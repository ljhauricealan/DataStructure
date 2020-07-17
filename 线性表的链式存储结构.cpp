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
	// 构造一个空的线性表L。
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}


bool ListInsert_L(LinkList &L, int i, ElemType e)
{
	// 在带头结点的单链线性表L的第i个元素之前插入元素e
	LinkList p, s;
	p = L;
	int j = 0;
	while(p && j < i - 1) {     // 寻找第i-1个结点
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
		printf("\n\n头结点的地址为：%p\n", L);
		for(i = 1; L->next != NULL; i++) {
			printf("\n第%d个结点的地址为：%p \n", i, L->next);
			L = L->next;
		}
	}
}

void OutputList(LinkList L)
{
	//按顺序输出链表中的所有元素
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
	//返回单链表的长度
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
	//判断线性表是否为空
	if (L->next)
		printf("单链表非空\n");
	else 
	    printf("单链表为空\n");
}

Status GetElem_L(LinkList L,int i, ElemType &e)
{
	//L为带头结点的单链表的头指针
	// 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
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
	//在链表中查找所有值为e的元素的位序，若找到，则输出所有的位序
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
	//在带头结点的单链表中，删除第i个元素，并用e返回其值
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
	//销毁链表
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

	InitList_L(Head);   //初始化单链表 

	for(i = 1, j = 0; i <= 5; i++, j++)
		ListInsert_L(Head, i, A[j]);  //依次插入 

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


