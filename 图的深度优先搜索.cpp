#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//图的两种存储结构
#define INFINITY 32767			// 值∞
#define MAX_VERTEX_NUM 8 		// 最大顶点个数
typedef char InfoType;			// 其他信息

typedef struct {
    int no;									//顶点编号
 //   InfoType *info;							//顶点其他信息
} VertexType;								//顶点类型

// 图的数组(邻接矩阵)存储表示
typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; 				// 顶点向量
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];		// 邻接矩阵数组
    int n,e; 										// 图的当前顶点数和弧数
} MGraph;

// 图的邻接表存储表示
typedef struct ArcNode {	// 链表结点
    int adjvex; 			// 该弧所指向的顶点的位置
   // int weight; 			// 网的权值指针
    ArcNode *nextarc; 		// 指向下一条弧的指针
} ArcNode;

typedef struct {
    int data;		// 顶点信息
    ArcNode *firstarc; 		// 第一个表结点的地址,指向第一条依附该顶点的弧的指针
} VNode;

typedef struct  {
    VNode adjlist[MAX_VERTEX_NUM];    	//adjacency List
    int n, e; // 图的当前顶点数和弧数
} ALGraph;

void CreateAdj(ALGraph *&G, int A[][MAX_VERTEX_NUM], int n, int e)
{
	//创建图的邻接表
	ArcNode *p,*cur;	
	for(int i=0;i<n;i++)
	{
		G->adjlist[i].data=i+1;
		int flag=0;
		cur=G->adjlist[i].firstarc;
		
		for(int j=0;j<MAX_VERTEX_NUM;j++)
		{
			if(A[i][j]) 
			{
			 	if(flag==0)
			 	{
			 		p=(ArcNode *)malloc(sizeof(ArcNode));
			 		G->adjlist[i].firstarc=p;
			 		p->adjvex =j;
			 		p->nextarc =NULL;
			 		cur=p;
			 		flag=1;
				}
				else
				{
					p=(ArcNode *)malloc(sizeof(ArcNode));
			 		p->adjvex =j;
			 		p->nextarc ==NULL;
			 		cur->nextarc = p;
			 		cur=p;
				} 
				cur->nextarc =NULL;
			}
		}
	}
}  


void DispMatrix(MGraph g)  	 	 	 	//输出邻接矩阵g 
{
	printf("输出邻接矩阵：\n");
	for(int i=0;i<MAX_VERTEX_NUM;i++)
	{
		for(int j=0;j<MAX_VERTEX_NUM;j++)
		{
			printf("%d  ",g.arcs[i][j]);
		}
		printf("\n");
	} 
	 
}

void DispAdjList(ALGraph *G)  	 	 	//输出邻接表G 
{
	printf("输出邻接表：\n");
	ArcNode *p;
	for(int i=0;i<MAX_VERTEX_NUM;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%d: ",i);
		while(p)
		{
			printf("%d",p->adjvex);
			p=p->nextarc;
			if(p)
			printf("->");
			else printf("\n");
		}
	}
}

void DestroyAdj(ALGraph *&G)  //销毁邻接表 
{
	ArcNode *p,*q;
	
	for(int i=0;i<MAX_VERTEX_NUM;i++)
	{
		p=G->adjlist[i].firstarc;
		while(p)
		{
			q=p;
			p=p->nextarc;
			free(q);
		}
	}
}

//从某点v开始深度搜索遍历图，输出图中所有的点 
int book[MAX_VERTEX_NUM];
void DFS(ALGraph *G,int v)
{
		book[v]=1;
		ArcNode *p;
		p=G->adjlist[v].firstarc;
		printf("%d  ",G->adjlist[v].data);
		int w;
		while(p)
		{
	        if(!book[p->adjvex])
			{
	            DFS(G,p->adjvex);
	        }
        	p = p->nextarc;
    	}

}

int main()
{
	int A[MAX_VERTEX_NUM][MAX_VERTEX_NUM]=
	{
		{0,1,1,0,0,0,0,0},
		{1,0,0,1,1,0,0,0},
	    {1,0,0,0,0,1,1,0},
	    {0,1,0,0,0,0,0,1},
	    {0,1,0,0,0,0,0,1},
	    {0,0,1,0,0,0,1,0},
	    {0,0,1,0,0,1,0,0},
	    {0,0,0,1,1,0,0,0}
	};
	ALGraph *G;      //G为指向图G1的指针 
	ALGraph G1;
	G=&G1;
	
	CreateAdj(G,A,8,9);
	DispAdjList(G);

	printf("\n深度优先搜索序列(递归): ");
	DFS(G,4);
	printf("\n");
	
	DestroyAdj(G);
	return 0;
}
