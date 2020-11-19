

#include <stdlib.h>
#include <stdio.h>



struct AdjListNode {
	int value;
	struct AdjListNode *edge;
};



struct AdjList {
	struct AdjListNode  *head;
};

struct LinkedGraph {
	struct AdjList *array;
	int size; // Linked Graph size
};




struct AdjListNode *newNode(int value){
	
	struct AdjListNode *adj = (struct AdjListNode *) malloc(sizeof(struct AdjListNode));
	adj->value = value;
	adj->edge = NULL;
	return adj;
}


struct LinkedGraph *newGraph(int max_size){
	struct LinkedGraph *graph = (struct LinkedGraph *) malloc(sizeof(struct LinkedGraph));
	graph->size = max_size;
	graph->array = (struct AdjList *) malloc( max_size * sizeof(struct AdjList));
	int idx;
	for (idx=0; idx < max_size; ++idx) graph->array[idx].head = NULL; 
	return graph;

}


void *addEdge(struct LinkedGraph *g, int src_value, int dest_value){
	/*
	 * Return adjacency linked graph with added edge from source vertex to destination vertex
	 *
	 */
	 
	 struct AdjListNode *newnode = newNode(dest_value);
	 newnode->edge = g->array[src_value].head;
	 g->array[src_value].head = newnode->edge;

	 // Because it's undirected Graph
	 newnode = newNode(src_value);
	 newnode->edge = g->array[dest_value].head;
	 g->array[dest_value].head = newnode->edge;
}



void printGraph(struct LinkedGraph *g){

	for (int v =0; v < g->size; ++v){
		struct AdjListNode *gcrawl = g->array[v].head;
		printf("Vertex %d\n", v);

		while (gcrawl){
			printf("Hello");
			printf("%d->", gcrawl->value);
			gcrawl = gcrawl->edge;
		}
		printf("\n");
	}
}


int main()
{
	struct LinkedGraph *graph;

	graph = newGraph(5);
	 addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 

	printGraph(graph);



	return EXIT_SUCCESS;
}

