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
	//����һ���ն���
	Q.base=(QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if(!Q.base ) exit (OVERFLOW);
	Q.front =Q.rear =0;
	return OK; 
}

int QueueLength(SqQueue Q)
{
	//����Q��Ԫ�ظ����������еĳ���
	return (Q.rear -Q.front +MAXQSIZE)%MAXQSIZE; 
}

Status EnQueue(SqQueue &Q,QElemType e)
{
	//����Ԫ��eΪQ���µĶ�βԪ�� 
	if((Q.rear +1)%MAXQSIZE==Q.front )  return ERROR;//������
	Q.base [Q.rear]=e;
	Q.rear = (Q.rear +1)%MAXQSIZE;
	return OK; 
 } 

Status DeQueue(SqQueue &Q,QElemType &e)
{
	//�����в��� ����ɾ��Q�Ķ�ͷԪ�� ����e������ֵ��������OK �����򷵻�ERROR
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
		printf("����Ϊ��\n");
		return 0;
	}
	else 
	{
		printf("���зǿ�\n");
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
	//printf("���г��ȣ�%d\n",QueueLength(Q));
	
	printf("������Ԫ�أ�\n");
	DeQueue(Q,el);
	printf("\n");
	
	for(int i=3;i<6;i++)
	{
		EnQueue(Q,a[i]);
	}
	//printf("���г��ȣ�%d\n",QueueLength(Q));
	
	printf("���������У�\n");
	while(Q.front!=Q.rear)
	{
		DeQueue(Q,el); 	
	}
	//printf("���г��ȣ�%d\n",QueueLength(Q));
	printf("\n"); 
	Judge(Q);
	
	
	
	return 0;
}
