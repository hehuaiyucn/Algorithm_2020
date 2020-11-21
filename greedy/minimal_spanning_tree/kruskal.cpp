#include <stdio.h>
#define MAX_VERTEX_NUM 6

struct Graph
{
    char vertexs[MAX_VERTEX_NUM];
    Edge edges[MAX_VERTEX_NUM];
    int vertexnum, edgenum;
} Graph;

//边集数组
typedef struct Edge
{
    int begin;
    int end;
    int weight;
} Edge;

int parent[] = {};

//初始化 每个节点为一棵独立的树 其父节点为其本身
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
}

int findroot(int k)
{
    while (k != parent[k])
    {
        k = parent[k];
    }
    return k;
}

void MST_Kruskal(struct Graph G)
{
    sort(G.edges);
    init(G.vertexnum);
    int m, n;
    for (int i = 0; i < G.edgenum; i++)
    {
        n = findroot(G.edges[i].begin);
        m = findroot(G.edges[i].end);

        if (n != m)
        {
            parent[n] = m;
            printf("输出最小生成树的一条边:%d", G.edges[i]);
        }
    }
}

//TODO 对边集数组按权值由小到大排序
void sort(Edge edge[]){
}