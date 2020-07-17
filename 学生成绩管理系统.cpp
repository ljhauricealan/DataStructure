#include<bits/stdc++.h>
#include <windows.h>
#define Max 100
using namespace std;
class student{
	//ѧ����� 
	public:
		string sname;
		string sno;
		double course[4];
		double sum;
		double average;
		student(){}
		student(string s1,string s2,double arr[])
		{
			sname=s1;
			sno=s2;
			int temp=0;
			for(int i=0;i<4;i++)
			{
				course[i]=arr[i];
				temp+=course[i];
			}
			sum=temp;
			average=sum/4;
		}
		student& operator=(student x)
	    {
	        sname=x.sname;
			sno=x.sno;
			for(int i=0;i<4;i++)
			{
				course[i]=x.course[i];
			}
			sum=x.sum;
			average=x.average;
			return *this;
	    }
};

void Swap(student s1,student s2)
{
	student temp;
	temp=s1;
	s1=s2;
	s2=temp;
}

struct stu_list
{   //ѧ�������� 
	student info[Max];
	int num;
};
bool list_init(stu_list &a)
{	//��ʼ�� 
	a.num=0;
}

void Insert(stu_list &L)
{   //����Ԫ�� 
    char s='y';
    while(s=='y'||s=='Y')
    {
    	system("cls");
    	string name1,no1;
    	double temp[4];
    	cout<<"������ѧ��������"<<endl;
    	cin>>name1;
    	cout<<"������ѧ��ѧ�ţ�"<<endl;
    	cin>>no1;
    	cout<<"�밴��˳������ѧ�������ſγɼ���"<<endl;
    	cout<<"(Ĭ��˳��Ϊ����ѧ��Ӣ����Դ�����������)"<<endl;
		for(int i=0;i<4;i++)
		{
			cin>>temp[i];
		}
		student x(name1,no1,temp);
		L.info[++L.num]=x;
		cout<<"�Ƿ������(Y/N)"<<endl;
		getchar();
		s=getchar();
	}
}
int Partition(stu_list &L, int left, int right)
{     
	student temp = L.info[left];
	while (left < right) 
	{
		while(left < right && L.info[right].average <= temp.average) 
		{
			right--;
		}  
		L.info[left] = L.info[right];
		while(left < right && L.info[left].average>=temp.average) 
		{
			left++;
		}  
		L.info[right] = L.info[left];
	}
	L.info[left] = temp;
	return left;
}

void QSort(stu_list &L, int left, int right)
{
	if (left < right)
	{
		int q = Partition(L, left, right);
		QSort(L, left, q - 1);
		QSort(L, q + 1, right);
	}
}

void Ranking(stu_list &L)
{   //��ʾ���� 
	if(L.num>0)
	{
		QSort(L,1,L.num);
		cout<<"Ranking:"<<endl;
		for(int i=1;i<=L.num;i++)
		{
			cout<<"ѧ�ţ�"<<L.info[i].sno <<"  ������"<<L.info[i].sname ; 
			cout<<"  �ܷ֣�"<<L.info[i].sum<<"  ƽ���֣�"<<L.info[i].average<<"  ����:"<<i<<endl; 
		}
	}
}
void search1(stu_list &L,string name)
{	//���������� 
	for(int i=1;i<=L.num;i++)
	{
		if(L.info[i].sname==name)
		{
			cout<<"ѧ�ţ�"<<L.info[i].sno <<"  ������"<<L.info[i].sname; 
			cout<<"  �ܷ֣�"<<L.info[i].sum<<"  ƽ���֣�"<<L.info[i].average<<endl; 
			return;
		}
		
	}
	
	cout<<"��ѯʧ�ܣ�"<<endl;
}

void search2(stu_list &L,string no)
{	//��ѧ�Ų��� 
	for(int i=1;i<=L.num;i++)
	{
		if(L.info[i].sno==no)
		{
			cout<<"ѧ�ţ�"<<L.info[i].sno <<"  ������"<<L.info[i].sname; 
			cout<<"  �ܷ֣�"<<L.info[i].sum<<"  ƽ���֣�"<<L.info[i].average<<endl; 
			return ;
		}
	}
	cout<<"��ѯʧ�ܣ�"<<endl;
}
void Search(stu_list &L)
{
	cout<<"��ȷ�ϲ��ҷ�ʽ��"<<endl;
	cout<<" 1.����������      2.��ѧ�Ų���"<<endl;
	char s;
	cin>>s;
	if(s=='1')
	{
		string name;
		cout<<"������������"<<endl;
		cin>>name;
		search1(L,name);
	}
	if(s=='2')
	{
		string no;
		cout<<"������ѧ�ţ�"<<endl;
		cin>>no;
		search2(L,no);
	}	
}
bool Is_empty(stu_list &L)
{
	if(L.num==0)
	{
		cout<<"ѧ����Ϣ��Ϊ�գ�"<<endl;
		return true;
	}
	else 
	{
		return false;
	}
}
void Modify(stu_list &L)
{
	cout<<"������Ҫ�޸ĵ�ѧ����ѧ�ţ�"<<endl;
	string s;
	cin>>s;
	for(int i=1;i<=L.num;i++)
	{
		if(L.info[i].sno==s)
		{
			cout<<"������Ҫ�޸ĵ���Ϣ��(ѧ�Ų����޸ģ�)"<<endl;
			cout<<"1.����  2.�ɼ�"<<endl;
			char c;
			cin>>c;
			if(c=='1')
			{
				string name1;
				cin>>name1;
				L.info[i].sname=name1;
				cout<<"�޸ĳɹ���"<<endl; 
				return ;
			}
			if(c=='2') 
			{
		    	cout<<"�밴��˳������ѧ�������ſγɼ���";
		    	cout<<"(Ĭ��˳��Ϊ����ѧ��Ӣ����Դ�����������)"<<endl;
				for(int j=0;j<4;j++)
				{
					cin>>L.info[i].course[j];
				}
				cout<<"�޸ĳɹ�!"<<endl;
				return;
			}
		}	
	} 
	cout<<"���޴��ˣ�"<<endl;
}

void menu(stu_list &L) 
{	 
	int key;
	do {
		system("cls"); 
		cout<<"\t\t\t....................menu...........................\n";
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t *     ��1.ѧ����Ϣ¼��       \n";
		cout<<"\t\t\t *     ��2.ѧ����Ϣ��ѯ       \n";
		cout<<"\t\t\t *     ��3.ѧ����Ϣ�޸�       \n";
		cout<<"\t\t\t *     ��4.ѧ���ɼ�����   \n";
		cout<<"\t\t\t *     ��5.ѧ���ɼ����		\n";
		cout<<"\t\t\t *     ��6.�˳�       		\n";
		printf("\t\t\t***************************************************\n");
		cout << endl;
		cin >> key;
		switch (key) 
		{
			case 1:
				Insert(L);
				break;
			case 2:
				Search(L);
				system("pause");
				break;
			case 3: 
				Modify(L);
				system("pause");
				break; 
			case 4:
				QSort(L,1,L.num);
				system("pause");
				break;
			case 5:
				Ranking(L);
				system("pause");
				break;
			case 6:
				cout<<"�����˳�"<<endl;
				Sleep(2000);
				exit(0); 
				break;
		}
	} while (key != 6&&key>0&&key<=5);
}

int main()
{
	stu_list L;
	list_init(L);
	menu(L);
	return 0;
} 


/*
xiaoming 123456 90 90 90 90 y
xiaohong 321654 92 80 80 80 y
xiaohua  111111 100 88 100 100 n*/













