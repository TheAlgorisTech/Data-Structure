/*
 * =====================================================================================
 *
 *       Filename:  bfs.c
 *    Description:  breadth first search traversal
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAX_SIZE 5


/* 
 * Queue Operations
 *
 */
int queue[MAX_SIZE];
int rear = -1;
int front = 0;
int queueItemCount = 0;

void insert(int data) {
   queue[++rear] = data;
   queueItemCount++;
}

int removeData() {
   queueItemCount--;
   return queue[front++]; 
}

int isQueueEmpty() {
   return queueItemCount == 0;
}


/*
 * Graph Operations
 *
 */

struct Vertex {
		int value;
		int visit;
		struct Vertex *next;
};


struct AdjVertex {
		struct Vertex *head;
};

struct Graph {
		int size;
		struct AdjVertex *AdjList;
};

/*
 * @brief create new empty vertex
 * 
 * @param[out] vertex 
 * @return vertex node
 *
 */

struct Vertex *newVertex(int value)
{
	 struct Vertex *newV = (struct Vertex *) malloc(sizeof(struct Vertex));
	 newV->value = value;
	 newV->visit = FALSE;
	 newV->next = NULL;
	 return newV;
}

/*
 * @brief create empty graph
 * 
 * @param[out] vertex 
 * @return vertex node
 *
 */

struct Graph *createGraph(int gsize)
{
		struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
		graph->AdjList = (struct AdjVertex *)malloc(gsize*sizeof(struct Vertex));
		graph->size = gsize;

		for(int idx=0; idx < gsize; idx ++) graph->AdjList[idx].head = NULL;

		return graph;
}


/*
 * @brief Add directed edge
 * 
 * @param[out] Graph
 * @return Return graph with additional directed edge 
 *
 */

struct Graph *addDEdge(struct Graph *graph, int src, int dest)
{

		struct Vertex *newNode = newVertex(dest);
		newNode->next=graph->AdjList[src].head;
		graph->AdjList[src].head = newNode;
		return graph;
}


/*
 * @brief Add undirected edge
 * 
 * @param[out] Graph
 * @return Return graph with additional undirected edge 
 *
 */

struct Graph *addUEdge(struct Graph *graph, int src, int dest)
{
				graph = addDEdge(graph, src, dest);
				return addDEdge(graph, dest, src);
}



/*
 * @brief get unvisited Vertex
 * 
 * @param[out] Vertex 
 * @return Return unvisited vertex 
 *
 */


int exploreVertex(struct Graph *graph, int src)
{

	struct Vertex *pcrawl = graph->AdjList[src].head;

	while (pcrawl != NULL)
	{
		if (!pcrawl->visit)
		{
				return  pcrawl->value;
		}
		pcrawl = pcrawl->next;
	}

	return -1;
}



void breath_first_search(struct Graph *graph, int src)
{

	struct Vertex *pcrawl = graph->AdjList[src].head;
	pcrawl->visit = TRUE;

	insert(pcrawl->value);
	printf("Display vertex %d\n", pcrawl->value);

	int unvisitedVertex;
	while (!isQueueEmpty())
	{

		int temp = removeData();

		while ( (unvisitedVertex= exploreVertex(graph, temp)) != -1)
		{
			graph->AdjList[unvisitedVertex].head->visit = TRUE;
			printf("Display vertex %d\n", graph->AdjList[unvisitedVertex].head->value);
			insert(graph->AdjList[unvisitedVertex].head->value);
			
		}

	}

	// mark Vertex as unvisited again
	for (int idx=0; idx < graph->size; idx++)
	{
		graph->AdjList[idx].head->visit = FALSE;
	}
}



/*
 * @brief Print graph presentation
 * 
 * @param[out] Graph
 * @return Return graph with additional undirected edge 
 *
 */

void printGraph(struct Graph *graph)
{
		for(int idx=0; idx < MAX_SIZE; idx++)
		{
			struct Vertex *header = graph->AdjList[idx].head;

			while (header != NULL)
			{
				printf("(%d-->%d)", idx, header->value);
				header = header->next;
			}
		}
		printf("\n");
}



int main()
{

	struct Graph *graph = createGraph(MAX_SIZE);
	addUEdge(graph, 0, 1); 
	addUEdge(graph, 0, 4); 
	addUEdge(graph, 1, 2); 
	addUEdge(graph, 1, 3); 
	addUEdge(graph, 1, 4); 
	addUEdge(graph, 2, 3); 
	addUEdge(graph, 3, 4); 

	printGraph(graph);

	breath_first_search(graph,0);


	return EXIT_SUCCESS;
}
