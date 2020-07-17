#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>


typedef char SElemType;
typedef char Status;

#define OK 1
#define ERROR 0
#define OVERFLOW 0
#define MAXSIZE	50

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct 
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack (SqStack &S)
{
	//����һ����ջ
	S.base= (SElemType *) malloc (STACK_INIT_SIZE * sizeof(SElemType)) ;
	if(!S.base) 
	exit (OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}//InitStack

Status GetTop(SqStack S,SElemType &e)
{
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if (S.top == S.base )
	return ERROR;
	e= *(S.top -1);
	return OK; 
}//GetTop

Status push (SqStack &S,SElemType &e)
{
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S.top -S.base >=S.stacksize )
	{
		//ջ����׷�Ӵ洢�ռ�
		S.base =(SElemType *) realloc (S.base ,(S.stacksize +STACKINCREMENT)*sizeof(SElemType)) ;
		if(S.base ) exit (OVERFLOW);
		S.top =S.base+S.stacksize ;
		S.stacksize +=STACKINCREMENT;
	 } 
	 *S.top ++ = e;
	 return OK;
	
} //Push

Status pop(SqStack &S,SElemType &e)
{
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(S.top == S.base ) 
	return ERROR;
	e=*--S.top ;
	return OK;
}//Pop

void Judge(SqStack &S)
{
	if(S.top ==S.base )
	printf("ջΪ��\n");
	else printf("ջ�ǿ�\n"); 
}

Status DestroyStack(SqStack &S)
{
	free(S.base );
	S.base =NULL;
	S.top =NULL;
	S.stacksize =0;
	return OK; 
}

Status ClearStack(SqStack &S)
{
	S.top=S.base ;
	return OK;
}

int main()
{
	SqStack S;
	InitStack(S);
	char el;
	
	Judge(S);
	
	char a[5]={'a','b','c','d','e'};
	
	for(int i=0;i<5;i++)
	push(S,a[i]);
	
	Judge(S);
	printf("��ջ���� ��\n") ;
	for(int i=0;i<5;i++)
	{
		pop(S,el);
		printf("%c  ",el);
	}
	printf("\n"); 
	Judge(S);
	
	DestroyStack(S);
	
	
	return 0;
}
