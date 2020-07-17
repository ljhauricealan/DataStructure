#include<stdio.h>

#include<stdlib.h>
#include<string.h>
#include<malloc.h>


typedef char Status;
typedef char QElemType;


#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW 0

typedef struct{
	QElemType *base;
	int front ;
	int rear;
} SqQueue;

Status InitQueue(SqQueue &Q)
{
	//构造一个空队列
	Q.base=(QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if(!Q.base ) exit (OVERFLOW);
	Q.front =Q.rear =0;
	return OK; 
}

int QueueLength(SqQueue Q)
{
	//返回Q的元素个数，即队列的长度
	return (Q.rear -Q.front +MAXQSIZE)%MAXQSIZE; 
}

Status EnQueue(SqQueue &Q,QElemType e)
{
	//插入元素e为Q的新的队尾元素 
	if((Q.rear +1)%MAXQSIZE==Q.front )  return ERROR;//队列满
	Q.base [Q.rear]=e;
	Q.rear = (Q.rear +1)%MAXQSIZE;
	return OK; 
 } 

Status DeQueue(SqQueue &Q,QElemType &e)
{
	//若队列不空 ，则删除Q的队头元素 ，用e返回其值，并返回OK ，否则返回ERROR
	 if(Q.front==Q.rear) return ERROR;
	 e=Q.base [Q.front];
	 printf("%c  ",e);
	 Q.front =(Q.front +1) % MAXQSIZE;
	 return OK;
}

int Judge(SqQueue Q)
{
	if(Q.front==Q.rear)  
	{
		printf("队列为空\n");
		return 0;
	}
	else 
	{
		printf("队列非空\n");
		return 1;
	} 
}
int main()
{
	char el;
	SqQueue Q;
	InitQueue(Q);
	char a[6]={'a','b','c','d','e','f'};
	
	for(int i=0;i<3;i++)
	{
		EnQueue(Q,a[i]);
	}
	
	Judge(Q);
	//printf("队列长度：%d\n",QueueLength(Q));
	
	printf("出队列元素：\n");
	DeQueue(Q,el);
	printf("\n");
	
	for(int i=3;i<6;i++)
	{
		EnQueue(Q,a[i]);
	}
	//printf("队列长度：%d\n",QueueLength(Q));
	
	printf("出队列序列：\n");
	while(Q.front!=Q.rear)
	{
		DeQueue(Q,el); 	
	}
	//printf("队列长度：%d\n",QueueLength(Q));
	printf("\n"); 
	Judge(Q);
	
	
	
	return 0;
}
