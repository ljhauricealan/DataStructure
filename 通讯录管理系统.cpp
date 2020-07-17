#include<bits/stdc++.h>
#include <windows.h>
using namespace std;

//system("pause");  任意键返回
//Sleep  挂起一段时间
//	system("cls"); 清屏 
typedef struct LNode{
		string name;
		string tel;	
		LNode *next;
}LNode, *LinkList;
bool InitList_L(LinkList &L)
{
	//初始化链表 
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
}

bool Node_Insert(LinkList &L,LNode *p1)
{
	//插入新结点 
	LinkList p,new_node,pre;
	string tel1=p1->tel ;
	string name1=p1->name;
	p=L;
	while(p)
	{
		if(tel1==p->tel)
		{
			cout<<"插入失败"<<endl; 
			return false;               //如果待插入结点的tel和链表中其他结点的tel重复，则插入失败 
		}
		p=p->next;
	}
	p=L;
	while(p&&name1>p->name)
	{							//pre用来指向p的前一个结点 
		pre=p;                 //按姓名字典序排列，找到第一个比待插入结点姓名大的结点，用指针p指向该结点，插入位置应为该结点前一个位置 
		p=p->next;					
	}                  
	pre->next=p1;
	p1->next=p;
	return true;
}
//添加信息
void CreateLinkList(LinkList & L)
{
	char ans = 'y';
	while (ans=='y'||ans=='Y') {
		system("cls");
		LNode *p = new LNode;
		cout << "请输入姓名：" << endl;
		cin >> p->name;
		cout << "请输入电话号码：" << endl;
		cin >> p->tel;
		Node_Insert(L,p);
		cout<<"是否继续？(Y/N)"<<endl;
		getchar();
		ans=getchar();
	}
	system("pause");
}
bool Node_Delete1(LinkList &L,string tel1)
{
	//按电话号码删除联系人 
	LinkList p,pre;
	pre=L;
	p=L->next ;
	while(p)
	{
		if(p->tel==tel1)
		{
			pre->next =p->next ;
			free(p);
			cout<<"..........删除成功！.........."<<endl; 
			return true;
		} 
		pre=pre->next ;
		p=p->next;
	}
	cout<<"*********无该联系人**********"<<endl; 
	return false;
}
bool Node_Delete2(LinkList &L,string name1)
{
	//按姓名删除联系人 
	LinkList p,pre;
	p=L->next;
	pre=L;
	while(p)
	{	
		if(p->name ==name1)
		{
			pre->next=p->next;
			free(p);
			cout<<"..........删除成功！.........."<<endl;
			return true;
		} 
		p=p->next;
		pre=pre->next ;
	}
	cout<<"*********无该联系人**********"<<endl; 
	return false;
}
void Delete(LinkList &L)
{
	int x;	
	cout << "选择删除方式：\n1.按号码删除联系人   2.按姓名删除联系人\n" << endl;
	cin >> x;
	if(x==2)
	{
		cout<<"输入联系人姓名：";
		string n1;
		cin>>n1;
		Node_Delete2(L,n1);
	}
	if(x==1)
	{
		cout<<"输入联系人号码：";
		string t1;
		cin>>t1;
		Node_Delete1(L,t1);
	}
}
void search(LinkList &L)
{
	string name1;
	cout<<"请输入要查找的联系人姓名："<<endl;
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
			cout<<"          name："<<p->name <<endl;
			cout<<"          tel："<<p->tel<<endl;
			//return  true;
		}
		p=p->next ;
	}
	if(flag==0)
	cout<<"..........查找失败！.........."<<endl;
	
} 

bool modify1(LinkList &L)
{
	//通过姓名修改信息
	string name1;
	cout<<"请输入要修改的联系人姓名："<<endl;
	cin>>name1;
	LinkList p;
	p=L;
	int k;
	while(p)
	{
		if(p->name ==name1)
		{
			cout<<"是否修改联系人姓名：   1.是    2.否"<<endl;
			cin>>k;
			if(k==1)
			{
				string nn;
				cin>>nn;
				p->name = nn;
				cout<<".....修改成功！....."<<endl;
			}
			cout<<"是否修改联系人号码：   1.是    2.否"<<endl;
			cin>>k;
			if(k==1)
			{
				string nn;
				cin>>nn;
				p->tel  = nn;
				cout<<".....修改成功！....."<<endl;
			}
			return  true;
		}
		p=p->next ;
	}
	cout<<"..........当前通讯录中无该联系人！.........."<<endl; 
	return false; 
}

bool show(LinkList &L)
{
	LinkList p;
	p=L->next ;
	while(p)
	{
		cout<<"姓名："<<p->name <<endl;
		cout<<"号码："<<p->tel <<endl;
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
		cout<<"\t\t\t *     │1.创建通讯录       \n";
		cout<<"\t\t\t *     │2.新建联系人       \n";
		cout<<"\t\t\t *     │3.查找联系人       \n";
		cout<<"\t\t\t *     │4.修改联系人信息   \n";
		cout<<"\t\t\t *     │5.删除联系人		\n";
		cout<<"\t\t\t *     │6.查看所有联系人     \n";
		cout<<"\t\t\t *     │7.退出       		\n";
		printf("\t\t\t***************************************************\n");
		cout << endl;
		cin >> key;
		switch (key) 
		{
			case 1:
				InitList_L(L);
				cout<<"创建成功！"<<endl; 
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
				cout<<"正在退出"<<endl;
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









