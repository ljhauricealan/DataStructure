#include <stdio.h>
#include <malloc.h>
#include<cstring>

typedef char ElemType;
typedef char Status;

#define OK 1
#define ERROR 0
#define MAXSIZE		50

// ���Ա�Ķ�̬����˳��洢�ṹ
#define LIST_INIT_SIZE 100 						// ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT  10 						// ���Ա�洢�ռ�ķ�������

typedef struct {
    ElemType *elem; 								// �洢�ռ��ַ
    int 			length;		  					// ��ǰ���Ա�ĳ���(��ЧԪ�ظ���)
    int 			listsize; 						// ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
} SqList;

typedef struct {
    ElemType elem[MAXSIZE]; 				// �洢�ռ��ַ
    int 			length;		  					// ��ǰ���Ա�ĳ���(��ЧԪ�ظ���)
} SqList_Static;

Status InitList_Sq(SqList &L)
{
    // ����һ���յ����Ա�L��
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L.elem)
        return ERROR;       
    L.length = 0;                  
    L.listsize = LIST_INIT_SIZE;  
    return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    // ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
    // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
    ElemType *p, *q;
    if(i < 1 || i > L.length + 1) {
        return ERROR;  // iֵ���Ϸ�
    }

    if(L.length >= L.listsize) {   							// ��ǰ�洢�ռ���������������
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
	//������Ա� 
   if ( L.length == 0)  return ERROR;
   for(int i=0;i<L.length ;i++)
   printf("%c  ",L.elem[i]);
   printf("\n");
   return OK;	
}

int ListLength(SqList L)
{ 
   //���Ա��� 
	return L.length;
}

void ListJudge(SqList L)
{
	//�ж�˳����Ƿ�Ϊ�� 
	if(L.length)  
	printf("���Ա�ǿ�\n");
	else 
	printf("���Ա�Ϊ��\n");
}

Status GetElem(SqList L,int i,char &e)
{
	//��e����˳���ĵ�i��ֵ 
	if(L.length < i)  return ERROR;
	else 
	e = L.elem[i-1];
	return e;
}

Status LocatedElem_Sq(SqList L,ElemType e)
{
	//��˳�����Ա�L�в��ҵ�һ��ֵ��e����compare()��λ��
	 int i=1;
	 ElemType *p = L.elem;
	 while(i<=L.length&&*p++!=e)  ++i;
	 if(i<L.length)   return i;
	 else return 0;
}

Status ListDelete_Sq(SqList &L,int i, ElemType e)
{
	//��˳�����ɾ��λ��Ϊi��Ԫ�أ�����e������ֵ
	//i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L) 
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
	//�������� 
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

    InitList_Sq(List);  //��ʼ�����Ա�L 

    for(i = 1, j = 0; i <= 5; i++, j++)
    { 
        ListInsert_Sq(List, i, A[j]);      //���β���a,b,c,d,e 
    } 
    
    Output_List(List);       //���˳��� 
	 
	printf("%d\n",ListLength(List));     //���Ա��� 
	
	ListJudge(List); //�жϷǿ� 
	
	i=3;
	el=GetElem(List,i,el);
	printf("%c\n",el);    //˳��������Ԫ�� 
	
	int tip=LocatedElem_Sq(List , 'a' );
	printf("%d\n",tip);              //Ԫ��a��λ��
	
	
	i = 4;   //����Ԫ�� 
    ListInsert_Sq(List, 4, 'f');
    
    Output_List(List);
    
    i=3;
    ListDelete_Sq(List,i,el);//ɾ��������Ԫ��
	
	Output_List(List);
	
	DestroyList(List);
	
    
}
