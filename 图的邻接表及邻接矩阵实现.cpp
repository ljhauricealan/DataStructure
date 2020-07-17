#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//ͼ�����ִ洢�ṹ
#define INFINITY 32767			// ֵ��
#define MAX_VERTEX_NUM 8 		// ��󶥵����
typedef char InfoType;			// ������Ϣ

typedef struct {
    int no;									//������
 //   InfoType *info;							//����������Ϣ
} VertexType;								//��������

// ͼ������(�ڽӾ���)�洢��ʾ
typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; 				// ��������
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];		// �ڽӾ�������
    int n,e; 										// ͼ�ĵ�ǰ�������ͻ���
} MGraph;

// ͼ���ڽӱ�洢��ʾ
typedef struct ArcNode {	// ������
    int adjvex; 			// �û���ָ��Ķ����λ��
   // int weight; 			// ����Ȩֵָ��
    ArcNode *nextarc; 		// ָ����һ������ָ��
} ArcNode;

typedef struct {
    int data;		// ������Ϣ
    ArcNode *firstarc; 		// ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ��
} VNode;

typedef struct  {
    VNode adjlist[MAX_VERTEX_NUM];    	//adjacency List
    int n, e; // ͼ�ĵ�ǰ�������ͻ���
} ALGraph;

void CreateAdj(ALGraph *&G, int A[][MAX_VERTEX_NUM], int n, int e)
{
	//����ͼ���ڽӱ�
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

void CreateMat(MGraph &g, int A[][MAX_VERTEX_NUM], int n1, int e1)   
{
	//����ͼ���ڽӾ���
	g.n=n1;
	g.e=e1;
	for(int i=0;i<MAX_VERTEX_NUM;i++)
	for(int j=0;j<MAX_VERTEX_NUM;j++)
	{
		g.arcs[i][j]=A[i][j];
	}
}

void MatrixToList(MGraph g, ALGraph *&G)  //���ڽӾ���gת�����ڽӱ�G 
{
	ArcNode *p,*cur;	
	for(int i=0;i<MAX_VERTEX_NUM;i++)
	{
		G->adjlist[i].data=i+1;
		int flag=0;
		cur=G->adjlist[i].firstarc;
		for(int j=0;j<MAX_VERTEX_NUM;j++)
		{
			if(g.arcs[i][j]) 
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

void ListToMatrix(ALGraph *G, MGraph &g)  	//���ڽӱ�Gת�����ڽӾ���g 
{
	for(int i=0;i<MAX_VERTEX_NUM;i++)
	for(int j=0;j<MAX_VERTEX_NUM;j++)
	{
		g.arcs[i][j]=0;
	}
	ArcNode *p;
	for(int i=0;i<MAX_VERTEX_NUM;i++)
	{
		p=G->adjlist[i].firstarc;
		while(p)
		{
			int j=p->adjvex;
			g.arcs[i][j]=1;
			p=p->nextarc;
		}
	}
}

void DispMatrix(MGraph g)  	 	 	 	//����ڽӾ���g 
{
	printf("����ڽӾ���\n");
	for(int i=0;i<MAX_VERTEX_NUM;i++)
	{
		for(int j=0;j<MAX_VERTEX_NUM;j++)
		{
			printf("%d  ",g.arcs[i][j]);
		}
		printf("\n");
	} 
	 
}

void DispAdjList(ALGraph *G)  	 	 	//����ڽӱ�G 
{
	printf("����ڽӱ�\n");
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

void DestroyAdj(ALGraph *&G)  //�����ڽӱ� 
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
	 	 
int book[MAX_VERTEX_NUM];
void DFS(ALGraph *G,int v)
{
	//	v=v-1;
//	if(book[v]==0)
//	{
		book[v]=1;
		ArcNode *p;
		p=G->adjlist[v].firstarc;
		printf("%d  ",G->adjlist[v].data);
		int w;
		while(p)
		{
			//printf("  %d  ",p->adjvex );
	        if(!book[p->adjvex])
			{
	            DFS(G,p->adjvex);
	        }
        	p = p->nextarc;
    	}
	//}
 //	else return;
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
	ALGraph *G,*K;
	ALGraph G1,K1;
	G=&G1;
	K=&K1;
	MGraph g,g1;
	CreateAdj(G,A,8,9);
	CreateMat(g,A, 8, 9);
	DispMatrix(g);
	DispAdjList(G);
	printf("�ڽӱ���ڽӾ����ת����\n"); 
	MatrixToList(g, K);
	DispAdjList(K);
	ListToMatrix(G, g1);
	DispMatrix(g1);
	
	DispAdjList(G);
	DFS(G,4);
	
	DestroyAdj(G);
	DestroyAdj(K);
	return 0;
}
