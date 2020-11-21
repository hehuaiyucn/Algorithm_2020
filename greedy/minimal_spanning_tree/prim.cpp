#include <stdio.h>
#define MAX_VERTEX_NUM 6
#define INFINITY 99999

// 最小代价生成树 Minimal spanning tree
struct Graph
{
    char vertexs[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vertexnum, edgenum;
} Graph;

typedef struct closedge
{
    char adjvex;
    int lowcost;
} closedge;

void MST_Prim(struct Graph graph)
{
    closedge cl[MAX_VERTEX_NUM];
    int k = 0;
    cl[k].adjvex = graph.vertexs[k];
    cl[k].lowcost = 0;

    for (int i = 0; i < graph.vertexnum; i++)
    {
        if (i != k)
        {
            cl[i].adjvex = graph.vertexs[k];
            cl[k].lowcost = graph.arcs[k][i];
        }
    }

    int min = INFINITY;
    for (int i = 0; i < graph.vertexnum; i++)
    {
        for (int j = 0; j < graph.vertexnum; j++)
        {
            if (cl[j].lowcost < min && cl[j].lowcost != 0)
            {
                min = cl[j].lowcost;
                k = j;
            }
        }

        printf("输出最小生成树的边:%d,%d", cl[k].adjvex, graph.vertexs[k]);
        cl[k].lowcost = 0;

        for (int j = 0; j < graph.vertexnum; j++)
        {
            if (graph.arcs[k][j] < cl[j].lowcost)
            {
                cl[j].adjvex = graph.vertexs[k];
                cl[j].lowcost = graph.arcs[k][j];
            }
        }
    }
}