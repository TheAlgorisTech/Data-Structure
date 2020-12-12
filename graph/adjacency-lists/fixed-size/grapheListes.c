

#include <stdlib.h>
#include <stdio.h>
 
// Nombre Maximal des vertices dans un Graphe 
#define GRAPH_MAX_SIZE 6
 



struct Vertex {
    int value;
    struct Vertex *next;
};

struct Edge {
    int src, dst;
};

struct Graph {
    struct Vertex *AdjList[GRAPH_MAX_SIZE];
};




/*
 * @brief create new empty graph
 * 
 * @param[out] Graph
 * @return Empty graph
 *
 */

struct Graph *grnouv()
{
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));
    
    for (int idx =0; idx < GRAPH_MAX_SIZE; idx++)
    {
        graph->AdjList[idx] = NULL;
    }
    return graph;
}

/*  
 * @brief populate Directed graph from edges list 
 * 
 * @parm[in] Edge
 * @param[out] Graph
 * @return Graph populated from edges
 *
 */

struct Graph *populateFromEdgesD(struct Edge edges[], int num_edges)
{
    struct Graph *graph = grnouv();
    // Add edges to the directed graph one by one
    for(int edgIdx = 0; edgIdx < num_edges; edgIdx++)
    {
        int src = edges[edgIdx].src;
        int dest = edges[edgIdx].dst;
        // Create vertex node
        struct Vertex *newvertex = (struct Vertex *) malloc(sizeof(struct Vertex));
        newvertex->value = dest;
        newvertex->next = graph->AdjList[src];
        graph->AdjList[src] = newvertex;
    }
    return graph;
}

/*  
 * @brief populate directed graph from edges list 
 * @parm[in] Edge
 * @param[out] Graph
 * @return Graph populated from edges
 *
 */

struct Graph *populateFromEdgesU(struct Edge edges[], int num_edges)
{
    struct Graph *graph = grnouv();
    // Add edges to the directed graph one by one
    for(int edgIdx = 0; edgIdx < num_edges; edgIdx++)
    {
        int src = edges[edgIdx].src;
        int dest = edges[edgIdx].dst;
        // UnDirected graph
        // Point source -> destination
        struct Vertex *newvertex = (struct Vertex *) malloc(sizeof(struct Vertex));
        newvertex->value = dest;
        newvertex->next = graph->AdjList[src];
        graph->AdjList[src] = newvertex;


        // Point destination -> source
        struct Vertex *srcvertex = (struct Vertex *) malloc(sizeof(struct Vertex));
        srcvertex->value = src;
        srcvertex->next = graph->AdjList[dest];
        graph->AdjList[dest] = srcvertex;
    }
    return graph;
}



/* 
 * @brief add vertex into the graph
 * @details in fixed size graph we have to reallocate/or copy the adjacency list into bigger graph
 *          then add the vertex into the last index of the adjacency list
 *
 * @param[in] Vertex
 * @param[out] Graph
 * @return Graph with additional disconnected vertex
 *
 */

/*
 * 
struct Graph *adjs(struct Graph *graph, struct Vertex *v)
{
        * If Graph is of fixed size we have to add additional space 
         * in the adjacency list for the new vertex*
        // Sizeof graph
        int sizeofGraph = (int) (sizeof(graph->AdjList)/sizeof(struct Vertex));

        // Increase size of adjacency list
        graph->AdjList = (struct Vertex *) realloc(graph->AdjList, sizeof(struct Vertex)); 
        // new vertex idx in adjacecny list
        int vertexIdx = sizeofGraph + 1;
        graph->AdjList[vertexIdx] = v;
        return graph;
}
*/



/* 
 * @brief add directed edge between two vertex
 *
 * @param[in] Vertex src, Vertex dest
 * @param[out] Graph
 * @return Graph with additional edge between src and dest
 *
 */

struct Graph *addDirectedEdge(struct Graph *graph, int src,int dest)
{
    struct Vertex *dist = (struct Vertex *)malloc(sizeof(struct Vertex));
    dist->value = dest;
    dist->next = NULL;

    dist->next = graph->AdjList[src];
    graph->AdjList[src] = dist;

    return graph;
}


/* 
 * @brief add undirected edge between two node 
 *
 * @param[in] Vertex src, Vertex dest 
 * @param[out] Graph
 * @return Graph with additional edge between src and dest 
 *
 */

struct Graph *addUnDirectedEdge(struct Graph *graph, int src,int dest)
{
    // Direction from source -> destination
    struct Vertex *dist = (struct Vertex *)malloc(sizeof(struct Vertex));
    dist->value = dest;
    dist->next = graph->AdjList[src];
    graph->AdjList[src] = dist;

    // Direction from destinatin -> source
    struct Vertex *source = (struct Vertex *)malloc(sizeof(struct Vertex));
    source->value = src;
    source->next = graph->AdjList[dest];
    graph->AdjList[dest] = source;
    
    return graph;
}


/* 
 * @brief remove a vertex from graph
 * @detail remove a vertex, point vertex into NULL in the adjacency matrix
 *
 * @param[in] Vertex v 
 * @param[out] Graph
 * @return Graph without vertex v 
 *
 */

struct Graph *DeleteVertex(struct Graph *graph,int v1)
{
    for(int idx=0; idx < GRAPH_MAX_SIZE; idx++)
    {
        if (idx == v1)
        {
            printf("Now we are at node 2\n");
        }
        else
        {
            struct Vertex *header = graph->AdjList[idx];
            // While it's not the end of the adjacency list
            // or vertex
            while (header != NULL && header->value != v1) 
            {
                    header = header->next;
            }

            printf("found node %d\n", header->value);
            
        }
    }
    return graph;
}



/* 
 * @brief remove edge between two vertex from graph
 *
 * @param[in] Vertex v1, Vertex v2 
 * @param[out] Graph
 * @return Graph where v1 and v2 are disconnected
 *
 * Graph supa(Vertex v1, Vertex v2){}*/


/* 
 * @brief check if vertex exist in the graph 
 *
 * @param[in] Vertex v 
 * @param[out] bool
 * @return true if vertex exist in the graph otherwise false 
 *
 * Graph exs(Vertex v){}*/


/* 
 * @brief check if edge between two Vertex exist in the graph 
 *
 * @param[in] Vertex v1, Vertex v2 
 * @param[out] bool 
 * @return true if edge exist between v1 and v2 otherwise false
 *
 * Graph exa(Vertex v1, Vertex v2){}*/



/* 
 * @brief compute internal degree of a vertex 
 *
 * @param[in] Vertex v 
 * @param[out] int 
 * @return number of edges received by vertex v 
 *
 * Graph di(Vertex v){}*/




/* 
 * @brief compute external degree of a vertex 
 *
 * @param[in] Vertex v 
 * @param[out] int 
 * @return number of edges that goes out from vertex v 
 *
 * Graph de(Vertex v){}*/



/*
 * @brief print graph presentation
 *
 * @param[in] Graph
 * @param[out] void
 *
 */
void printGraph(struct Graph *graph)
{
    printf("Printing graph...\n");
    for(int idx=0; idx < GRAPH_MAX_SIZE; idx++)
    {
        struct Vertex *head = graph->AdjList[idx];
        while (head != NULL) {
            printf("(%d)-->(%d)\n",idx, head->value);
            head = head->next;
        } 
    }
    printf("\n");
}
 
int main(void)
{
    struct Edge edges[] =
    {
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
        { 3, 2 }, { 4, 5 }, { 5, 4 }
    };

    int num_edges = (int ) (sizeof(edges)/sizeof(edges[0]));
    struct Graph *graph = populateFromEdgesU(edges, num_edges);
    printGraph(graph);


    graph = addDirectedEdge(graph, 1,5);

    printf("Adding undirected edge from 2 to 5");
    graph = addUnDirectedEdge(graph, 2,5);
    printGraph(graph);


    return EXIT_SUCCESS;
}
