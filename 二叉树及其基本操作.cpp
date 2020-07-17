#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MaxSize 	50
typedef char ElemType;

typedef struct BiTNode {
    ElemType    data;
    struct BiTNode	*lchild, *rchild; 			
} BiTNode, *BiTree;

void InitBiTree(BiTree &T)
{
	T=NULL;
}


void CreateBiTree(BiTree &T)
{
    //  �������������������н���ֵ
    //  ������������ʾ�Ķ�����T��
    ElemType	ch;

    static	int	i = 0;
    char	pch[] = "ABD$$EHJ$$KL$$M$N$$$CF$$G$I$$";						// ����������������
    //printf("\n��̬����i��ֵ�ֱ�Ϊ��%d\n", i);
    //scanf("%c",&ch);
    ch = pch[i++];

    if(ch == '$') 										// ����
        T = NULL;
    else {
        T = (BiTree)malloc(sizeof(BiTNode));
        if(!T)											// ����Ƿ�������ɹ�
            exit(-1);
        T->data = ch; 									// ���ɸ����
        CreateBiTree(T->lchild); 						// ����������
        CreateBiTree(T->rchild); 						// ����������
    }
}



void InOrderTraversal(BiTree BT)
{
	// �������
    if(BT) {
        InOrderTraversal(BT->lchild);
        printf("%c ", BT->data);
        InOrderTraversal(BT->rchild);
    }
}


void PreOrderTraversal(BiTree BT)
{
	//�������
    if(BT) {
        printf("%c ", BT->data);
        PreOrderTraversal(BT->lchild);
        PreOrderTraversal(BT->rchild);
    }
}


void PostOrderTraversal(BiTree BT)
{
	// �������
    if(BT) {
        PostOrderTraversal(BT->lchild);
        PostOrderTraversal(BT->rchild);
        printf("%c ", BT->data);
    }
}

void DestroyBiTree(BiTree &T)
{
	//�ͷŶ����� 
	if(T)
	{
		if(T->lchild)  DestroyBiTree(T->lchild);
		if(T->rchild)  DestroyBiTree(T->rchild);
		free(T);
		T=NULL;
	}
}


BiTNode *findElement(BiTree T, char element)
{
	//����Ԫ�� 
	if(T == NULL)
		return NULL;
 
	if(element == T->data)
		return T;
 
	BiTNode *p = findElement(T->lchild, element);
	if(p != NULL)
		return p;
 
	return  findElement(T->rchild, element);
}

void Child_of_BiTree(BiTree BT,char a)
{
	//���Һ��� 
	if(BT)
	{
		BiTNode *p;
		p=findElement(BT,a);
		if(p->lchild &&p->rchild)   
		printf("\n%c��㣺 ����Ϊ%c,�Һ���Ϊ%c",p->data ,p->lchild->data ,p->rchild->data );
		else if (p->lchild &&!p->rchild)
		printf("\n%c��㣺 ����Ϊ%c,���Һ���",p->data ,p->lchild->data); 
		else if (p->rchild &&!p->lchild)
		printf("\n%c��㣺 �Һ���Ϊ%c,������",p->data ,p->rchild->data);
		else  printf("\n%c���ΪҶ�ӽ��"); 
	}
}

int BiTree_Deepness(BiTNode *T)
{
	//���ĸ߶� 
    if(T == NULL)
        return 0;
    else
        if(T->lchild == NULL && T->rchild == NULL)
            return 1;
        else
            return 1 + max(BiTree_Deepness(T->lchild), BiTree_Deepness(T->rchild));
}

int aspect_of_Element(BiTree BT,char a)
{
	//Ԫ���ڵڼ��� 
	BiTNode *p=findElement(BT, a);
	int b=BiTree_Deepness(BT);
	int c=BiTree_Deepness(p);
	return b-c;
} 

void InOrderTraversal_NoRecursion(BiTNode *T)
{
	//�ǵݹ�������� 
    BiTNode	*Stack[MaxSize];
    int	top = -1;

    while(T || (top != -1)) {
        while(T) {											
            Stack[++top] = T;
            T = T->lchild;
        }

        if(top != -1) {
            T = Stack[top--]; 					
            printf("%c ", T->data); 				
            T = T->rchild; 						
        }
    }
}

void Preorder_Output(BiTree BT)
{
	//�Թ������ʽ��������� 
	if(BT)
	{
		printf("%c",BT->data);
		if(BT->lchild||BT->rchild)
		{
			printf("(");
			Preorder_Output(BT->lchild);
		//	if((BT->lchild&&BT->rchild)||(!BT->lchild&&BT->rchild))
			printf(",");
			Preorder_Output(BT->rchild);
			printf(")");
		}
	}
}

void allpath(BiTNode *b,char path[],int pathlen)
{   //��������������ÿ��Ҷ�ӽ�㵽������·������ 
    if(b!=NULL)
    {   if (b->lchild==NULL && b->rchild==NULL)    //bΪҶ��
        {   //���ջ�����н��ֵ
        	printf("%c����������·��Ϊ��",b->data);
            printf("%c->",b->data);
            for (int i=pathlen-1;i>0;i--)
                printf("%c->",path[i]);
            printf("%c\n",path[0]);
        }
        else
        {   
			path[pathlen++]=b->data;
            allpath(b->lchild, path, pathlen);
            allpath(b->rchild, path, pathlen);
        }
    }
}

int	BTree_Count2Node(BiTNode *T)
{
	//��������Ķ�Ϊ2�Ľ�����㷨 
	int	  n1, n2;
	if(T == NULL)
		return	0;
	else {
		n1 = BTree_Count2Node(T->lchild);
		n2 = BTree_Count2Node(T->rchild);
		if(T->lchild != NULL && T->rchild != NULL)
			return	1+n1+n2;
		else
			return	n1+n2;
	}
}
void BTLink_Exchange(BiTNode *T)
{
	//�����������и�������������
	BiTNode	*p;
	if(T != NULL){
		p = T->lchild;
		T->lchild = T->rchild;
		T->rchild = p;
		BTLink_Exchange(T->lchild);
		BTLink_Exchange(T->rchild);		
	}
}

int	BTree_Count0Node(BiTNode *T)
{
	//���������Ҷ�ӽ�����㷨 
	if(T != NULL)
	{
		if(T->lchild==NULL&&T->rchild==NULL)
		return 1;
		else return BTree_Count0Node(T->lchild)+BTree_Count0Node(T->rchild);
	}
	else return 0;
}
/* 
void longest_path(BiTree BT,char path[],int len,int MAX,char MAXnode)
{
    if(BT)
    {
        if(BT->lchild==NULL&&BT->rchild==NULL)
        {
            if(len>MAX)
            {
                MAX=len;
                MAXnode=BT->data;
            }

        }
        else
        {
            path[len]=BT->data;
            len++;
            inverse_path(BT->lchild ,path,len);
            inverse_path(BT->rchild ,path,len);
        }
    }
}
*/
void longest_path(BiTree BT,char path[],int len,int depth)
{
    if(BT)
    {
	    if(len==depth-1)
	    {
	        printf("��һ���·�����ȣ�%d\n",depth);
	        printf("%c����������·��Ϊ��",BT->data);
            printf("%c->",BT->data);
	        for(int i=len-1;i>0;i--)
	        {
	            printf("%c->",path[i]);
	        }
	        printf("%c",path[0]);
	    }
	    else 
	    {
	        path[len++]=BT->data;
	        longest_path( BT->lchild ,path, len,depth);
	        longest_path( BT->rchild ,path, len,depth);
	    }
	}

}
int main()
{
	BiTree	T;
    CreateBiTree(T);
    
    Preorder_Output(T);
    printf("\n����������У�\n");
    PreOrderTraversal(T);
    printf("\n����������У�\n");
    InOrderTraversal(T);
    printf("\n����������� - ��������ǵݹ��㷨��\n");
    InOrderTraversal_NoRecursion(T);
    printf("\n����������У�\n");
    PostOrderTraversal(T);

    printf("\n�����������Ϊ��\n");
    printf("%d", BiTree_Deepness(T));
   
	Child_of_BiTree(T,'H');
	printf("\n");
	char path[MaxSize];
	int pathlen;
	allpath(T,path,0);
	char path2[MaxSize];
	longest_path(T,path2,0,BiTree_Deepness(T));
	
	
	printf("\n%d\n",BTree_Count0Node(T));
}
//A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))

