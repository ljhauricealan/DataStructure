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
    //  按先序次序输入二叉树中结点的值
    //  构造二叉链表表示的二叉树T。
    ElemType	ch;

    static	int	i = 0;
    char	pch[] = "ABD$$EHJ$$KL$$M$N$$$CF$$G$I$$";						// 欲产生的先序序列
    //printf("\n静态变量i的值分别为：%d\n", i);
    //scanf("%c",&ch);
    ch = pch[i++];

    if(ch == '$') 										// 空树
        T = NULL;
    else {
        T = (BiTree)malloc(sizeof(BiTNode));
        if(!T)											// 检测是否申请结点成功
            exit(-1);
        T->data = ch; 									// 生成根结点
        CreateBiTree(T->lchild); 						// 构造左子树
        CreateBiTree(T->rchild); 						// 构造右子树
    }
}



void InOrderTraversal(BiTree BT)
{
	// 中序遍历
    if(BT) {
        InOrderTraversal(BT->lchild);
        printf("%c ", BT->data);
        InOrderTraversal(BT->rchild);
    }
}


void PreOrderTraversal(BiTree BT)
{
	//先序遍历
    if(BT) {
        printf("%c ", BT->data);
        PreOrderTraversal(BT->lchild);
        PreOrderTraversal(BT->rchild);
    }
}


void PostOrderTraversal(BiTree BT)
{
	// 后序遍历
    if(BT) {
        PostOrderTraversal(BT->lchild);
        PostOrderTraversal(BT->rchild);
        printf("%c ", BT->data);
    }
}

void DestroyBiTree(BiTree &T)
{
	//释放二叉树 
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
	//查找元素 
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
	//左右孩子 
	if(BT)
	{
		BiTNode *p;
		p=findElement(BT,a);
		if(p->lchild &&p->rchild)   
		printf("\n%c结点： 左孩子为%c,右孩子为%c",p->data ,p->lchild->data ,p->rchild->data );
		else if (p->lchild &&!p->rchild)
		printf("\n%c结点： 左孩子为%c,无右孩子",p->data ,p->lchild->data); 
		else if (p->rchild &&!p->lchild)
		printf("\n%c结点： 右孩子为%c,无左孩子",p->data ,p->rchild->data);
		else  printf("\n%c结点为叶子结点"); 
	}
}

int BiTree_Deepness(BiTNode *T)
{
	//树的高度 
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
	//元素在第几层 
	BiTNode *p=findElement(BT, a);
	int b=BiTree_Deepness(BT);
	int c=BiTree_Deepness(p);
	return b-c;
} 

void InOrderTraversal_NoRecursion(BiTNode *T)
{
	//非递归中序遍历 
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
	//以广义表形式输出二叉树 
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
{   //先序遍历方法输出每个叶子结点到根结点的路径序列 
    if(b!=NULL)
    {   if (b->lchild==NULL && b->rchild==NULL)    //b为叶子
        {   //输出栈中所有结点值
        	printf("%c到根结点的逆路径为：",b->data);
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
	//求二叉树的度为2的结点数算法 
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
	//交换二叉树中各结点的左右子树
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
	//求二叉树的叶子结点数算法 
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
	        printf("第一条最长路径长度：%d\n",depth);
	        printf("%c到根结点的逆路径为：",BT->data);
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
    printf("\n先序遍历序列：\n");
    PreOrderTraversal(T);
    printf("\n中序遍历序列：\n");
    InOrderTraversal(T);
    printf("\n中序遍历序列 - 中序遍历非递归算法：\n");
    InOrderTraversal_NoRecursion(T);
    printf("\n后序遍历序列：\n");
    PostOrderTraversal(T);

    printf("\n二叉树的深度为：\n");
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

