#include <stdio.h>
#include <malloc.h>
#include<cstring>

typedef char ElemType;
typedef char Status;

#define OK 1
#define ERROR 0
#define MAXSIZE		50

// 线性表的动态分配顺序存储结构
#define LIST_INIT_SIZE 100 						// 线性表存储空间的初始分配量
#define LISTINCREMENT  10 						// 线性表存储空间的分配增量

typedef struct {
    ElemType *elem; 								// 存储空间基址
    int 			length;		  					// 当前线性表的长度(有效元素个数)
    int 			listsize; 						// 当前分配的存储容量(以sizeof(ElemType)为单位)
} SqList;

typedef struct {
    ElemType elem[MAXSIZE]; 				// 存储空间基址
    int 			length;		  					// 当前线性表的长度(有效元素个数)
} SqList_Static;

Status InitList_Sq(SqList &L)
{
    // 构造一个空的线性表L。
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L.elem)
        return ERROR;       
    L.length = 0;                  
    L.listsize = LIST_INIT_SIZE;  
    return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    // 在顺序线性表L的第i个元素之前插入新的元素e，
    // i的合法值为1≤i≤ListLength_Sq(L)+1
    ElemType *p, *q;
    if(i < 1 || i > L.length + 1) {
        return ERROR;  // i值不合法
    }

    if(L.length >= L.listsize) {   							// 当前存储空间已满，增加容量
        ElemType *newbase = (ElemType *)realloc(L.elem,
                                                (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase)
            return ERROR;   							
        L.elem = newbase;             					
        L.listsize += LISTINCREMENT;  						
    }

    q = &(L.elem[i - 1]);   								
    for(p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p + 1) = *p;										
    *q = e;      
    ++L.length;   
    return OK;
} // ListInsert_S

Status Output_List(SqList L)
{
	//输出线性表 
   if ( L.length == 0)  return ERROR;
   for(int i=0;i<L.length ;i++)
   printf("%c  ",L.elem[i]);
   printf("\n");
   return OK;	
}

int ListLength(SqList L)
{ 
   //线性表长度 
	return L.length;
}

void ListJudge(SqList L)
{
	//判断顺序表是否为空 
	if(L.length)  
	printf("线性表非空\n");
	else 
	printf("线性表为空\n");
}

Status GetElem(SqList L,int i,char &e)
{
	//用e返回顺序表的第i个值 
	if(L.length < i)  return ERROR;
	else 
	e = L.elem[i-1];
	return e;
}

Status LocatedElem_Sq(SqList L,ElemType e)
{
	//在顺序线性表L中查找第一个值与e满足compare()的位序
	 int i=1;
	 ElemType *p = L.elem;
	 while(i<=L.length&&*p++!=e)  ++i;
	 if(i<L.length)   return i;
	 else return 0;
}

Status ListDelete_Sq(SqList &L,int i, ElemType e)
{
	//在顺序表中删除位序为i的元素，并用e返回其值
	//i的合法值为1<=i<=ListLength_Sq(L) 
	if(i<1||i>L.length)  
	return ERROR;
	ElemType *p ,*q;
	p=&(L.elem[i-1]);
	e=*p;
	q=L.elem+L.length-1;
	for(++p;p<=q;++p)  
	*(p-1)=*p;
	--L.length;
	return OK;
}

Status DestroyList(SqList &L)
{
	//销毁链表 
	free(L.elem);
	L.elem=NULL;
	L.length=0;
	L.listsize=0;
	return OK;
}

int	main()
{
    
    int	i, j;
    char el;
    char A[5]={'a','b','c','d','e'};
    SqList	List;

    InitList_Sq(List);  //初始化线性表L 

    for(i = 1, j = 0; i <= 5; i++, j++)
    { 
        ListInsert_Sq(List, i, A[j]);      //依次插入a,b,c,d,e 
    } 
    
    Output_List(List);       //输出顺序表 
	 
	printf("%d\n",ListLength(List));     //线性表长度 
	
	ListJudge(List); //判断非空 
	
	i=3;
	el=GetElem(List,i,el);
	printf("%c\n",el);    //顺序表第三个元素 
	
	int tip=LocatedElem_Sq(List , 'a' );
	printf("%d\n",tip);              //元素a的位置
	
	
	i = 4;   //插入元素 
    ListInsert_Sq(List, 4, 'f');
    
    Output_List(List);
    
    i=3;
    ListDelete_Sq(List,i,el);//删除第三个元素
	
	Output_List(List);
	
	DestroyList(List);
	
    
}
