#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<iostream> 

using namespace std;

typedef char ElemType;
typedef char Status;

#define OK 	1
#define ERROR 0

typedef struct node {
	char	data;
	struct node	 *next;
} LNode, *LinkList;


Status InitList_L(LinkList &L)
{
	// ����һ���յ����Ա�L��
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}


bool ListInsert_L(LinkList &L, int i, ElemType e)
{
	// �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
	LinkList p, s;
	p = L;
	int j = 0;
	while(p && j < i - 1) {     // Ѱ�ҵ�i-1�����
		p = p->next;
		++j;
	}
	if(!p || j > i - 1)  {
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

void ShowAddress(LinkList L)
{
	int	i;
	LinkList p = L;
	if(L != NULL) {
		printf("\n\nͷ���ĵ�ַΪ��%p\n", L);
		for(i = 1; L->next != NULL; i++) {
			printf("\n��%d�����ĵ�ַΪ��%p \n", i, L->next);
			L = L->next;
		}
	}
}

void OutputList(LinkList L)
{
	//��˳����������е�����Ԫ��
	LinkList p;
	p=L->next ;
	while(p) {	
		printf("%c  ",p->data  );
		//cout<<L->data ;
		p=p->next ;
	}
	printf("\n");
}

int Listlength(LinkList L)
{
	//���ص�����ĳ���
	int i=0;
	LinkList p;
	p=L->next ;
	while (p) {
		i++;
		p=p->next;
	}
	return i;
}

void JudgeList(LinkList L)
{
	//�ж����Ա��Ƿ�Ϊ��
	if (L->next)
		printf("������ǿ�\n");
	else 
	    printf("������Ϊ��\n");
}

Status GetElem_L(LinkList L,int i, ElemType &e)
{
	//LΪ��ͷ���ĵ������ͷָ��
	// ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
	LinkList p;
	int j=1;
	p=L->next ;
	while ( p&& j<i) {
		p=p->next ;
		j++;
	}
	if(!p||j>i)
		return ERROR ;
	e=p->data ;
	return OK;
}

void LocatedElem_L(LinkList L,ElemType e)
{
	//�������в�������ֵΪe��Ԫ�ص�λ�����ҵ�����������е�λ��
	LinkList p;
	p=L->next ;
	int i=1;
	while (p) {
		if(p->data==e) {
			printf("%d\n",i);
		}
		i++;
		p=p->next ;
	}
}

Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
	//�ڴ�ͷ���ĵ������У�ɾ����i��Ԫ�أ�����e������ֵ
	LinkList p=L;
	LinkList q;
	int j =0;
	while(p->next && j<i-1) {
		p=p->next ;
		++j;
	}
	if(!(p->next )||j>i-1)
		return ERROR;
	q=p->next ;
	p->next =q->next ;
	e=q->data ;
	free(q);
	return OK;
}

Status DestroyList(LinkList &L)
{
	//��������
	LinkList q;
	while (L) {
		q=L->next;
		free(L);
		L=q;
	}
	return OK;
}


int	main()
{
	char A[5]= {'a','b','c','d','e'};
	int	i, j;
	char el;
	LinkList  Head, p;

	InitList_L(Head);   //��ʼ�������� 

	for(i = 1, j = 0; i <= 5; i++, j++)
		ListInsert_L(Head, i, A[j]);  //���β��� 

    OutputList(Head);
    
    printf("%d\n",Listlength(Head));
    
    JudgeList(Head);
    
    GetElem_L(Head,3, el);
	cout<<el<<endl;            
	
	LocatedElem_L(Head,'a');
	
	ListInsert_L(Head, 4, 'f');
	OutputList(Head);
	
	ListDelete_L(Head,3,el);
	OutputList(Head);
	
	DestroyList(Head);
	

}


