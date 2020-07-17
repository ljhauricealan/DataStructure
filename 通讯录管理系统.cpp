#include<bits/stdc++.h>
#include <windows.h>
using namespace std;

//system("pause");  ���������
//Sleep  ����һ��ʱ��
//	system("cls"); ���� 
typedef struct LNode{
		string name;
		string tel;	
		LNode *next;
}LNode, *LinkList;
bool InitList_L(LinkList &L)
{
	//��ʼ������ 
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
}

bool Node_Insert(LinkList &L,LNode *p1)
{
	//�����½�� 
	LinkList p,new_node,pre;
	string tel1=p1->tel ;
	string name1=p1->name;
	p=L;
	while(p)
	{
		if(tel1==p->tel)
		{
			cout<<"����ʧ��"<<endl; 
			return false;               //������������tel����������������tel�ظ��������ʧ�� 
		}
		p=p->next;
	}
	p=L;
	while(p&&name1>p->name)
	{							//pre����ָ��p��ǰһ����� 
		pre=p;                 //�������ֵ������У��ҵ���һ���ȴ�������������Ľ�㣬��ָ��pָ��ý�㣬����λ��ӦΪ�ý��ǰһ��λ�� 
		p=p->next;					
	}                  
	pre->next=p1;
	p1->next=p;
	return true;
}
//�����Ϣ
void CreateLinkList(LinkList & L)
{
	char ans = 'y';
	while (ans=='y'||ans=='Y') {
		system("cls");
		LNode *p = new LNode;
		cout << "������������" << endl;
		cin >> p->name;
		cout << "������绰���룺" << endl;
		cin >> p->tel;
		Node_Insert(L,p);
		cout<<"�Ƿ������(Y/N)"<<endl;
		getchar();
		ans=getchar();
	}
	system("pause");
}
bool Node_Delete1(LinkList &L,string tel1)
{
	//���绰����ɾ����ϵ�� 
	LinkList p,pre;
	pre=L;
	p=L->next ;
	while(p)
	{
		if(p->tel==tel1)
		{
			pre->next =p->next ;
			free(p);
			cout<<"..........ɾ���ɹ���.........."<<endl; 
			return true;
		} 
		pre=pre->next ;
		p=p->next;
	}
	cout<<"*********�޸���ϵ��**********"<<endl; 
	return false;
}
bool Node_Delete2(LinkList &L,string name1)
{
	//������ɾ����ϵ�� 
	LinkList p,pre;
	p=L->next;
	pre=L;
	while(p)
	{	
		if(p->name ==name1)
		{
			pre->next=p->next;
			free(p);
			cout<<"..........ɾ���ɹ���.........."<<endl;
			return true;
		} 
		p=p->next;
		pre=pre->next ;
	}
	cout<<"*********�޸���ϵ��**********"<<endl; 
	return false;
}
void Delete(LinkList &L)
{
	int x;	
	cout << "ѡ��ɾ����ʽ��\n1.������ɾ����ϵ��   2.������ɾ����ϵ��\n" << endl;
	cin >> x;
	if(x==2)
	{
		cout<<"������ϵ��������";
		string n1;
		cin>>n1;
		Node_Delete2(L,n1);
	}
	if(x==1)
	{
		cout<<"������ϵ�˺��룺";
		string t1;
		cin>>t1;
		Node_Delete1(L,t1);
	}
}
void search(LinkList &L)
{
	string name1;
	cout<<"������Ҫ���ҵ���ϵ��������"<<endl;
	cin>>name1;
	cout<<endl;
	LinkList p;
	p=L;
	int flag=0;
	while(p)
	{
		if(p->name ==name1)
		{
			flag=1;
			cout<<"          name��"<<p->name <<endl;
			cout<<"          tel��"<<p->tel<<endl;
			//return  true;
		}
		p=p->next ;
	}
	if(flag==0)
	cout<<"..........����ʧ�ܣ�.........."<<endl;
	
} 

bool modify1(LinkList &L)
{
	//ͨ�������޸���Ϣ
	string name1;
	cout<<"������Ҫ�޸ĵ���ϵ��������"<<endl;
	cin>>name1;
	LinkList p;
	p=L;
	int k;
	while(p)
	{
		if(p->name ==name1)
		{
			cout<<"�Ƿ��޸���ϵ��������   1.��    2.��"<<endl;
			cin>>k;
			if(k==1)
			{
				string nn;
				cin>>nn;
				p->name = nn;
				cout<<".....�޸ĳɹ���....."<<endl;
			}
			cout<<"�Ƿ��޸���ϵ�˺��룺   1.��    2.��"<<endl;
			cin>>k;
			if(k==1)
			{
				string nn;
				cin>>nn;
				p->tel  = nn;
				cout<<".....�޸ĳɹ���....."<<endl;
			}
			return  true;
		}
		p=p->next ;
	}
	cout<<"..........��ǰͨѶ¼���޸���ϵ�ˣ�.........."<<endl; 
	return false; 
}

bool show(LinkList &L)
{
	LinkList p;
	p=L->next ;
	while(p)
	{
		cout<<"������"<<p->name <<endl;
		cout<<"���룺"<<p->tel <<endl;
		cout<<"-----------------------------"<<endl; 
		p=p->next ;
	}
	return true;
}

void menu(LinkList &L) {
	int key;
	string n1,t1;
	do {
		system("cls"); 
		cout<<"\t\t\t....................menu...........................\n";
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t *     ��1.����ͨѶ¼       \n";
		cout<<"\t\t\t *     ��2.�½���ϵ��       \n";
		cout<<"\t\t\t *     ��3.������ϵ��       \n";
		cout<<"\t\t\t *     ��4.�޸���ϵ����Ϣ   \n";
		cout<<"\t\t\t *     ��5.ɾ����ϵ��		\n";
		cout<<"\t\t\t *     ��6.�鿴������ϵ��     \n";
		cout<<"\t\t\t *     ��7.�˳�       		\n";
		printf("\t\t\t***************************************************\n");
		cout << endl;
		cin >> key;
		switch (key) 
		{
			case 1:
				InitList_L(L);
				cout<<"�����ɹ���"<<endl; 
				system("pause");
				break;
			case 2:
				CreateLinkList(L);
				break;
			case 3: 
				search(L);
				system("pause");
				break; 
			case 4:
				modify1(L);
				system("pause");
				break;
			case 5:
				Delete(L);
				system("pause");
				break;
				 
			case 6:
				show(L);
				system("pause");
				break;
			case 7:
				cout<<"�����˳�"<<endl;
				Sleep(2000);
				exit(0); 
				break;
		}
	} while (key != 7);
}

int main()
{
	LinkList L;
	menu(L);
	return 0;
}









