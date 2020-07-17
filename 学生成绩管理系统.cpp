#include<bits/stdc++.h>
#include <windows.h>
#define Max 100
using namespace std;
class student{
	//学生结点 
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
{   //学生表类型 
	student info[Max];
	int num;
};
bool list_init(stu_list &a)
{	//初始化 
	a.num=0;
}

void Insert(stu_list &L)
{   //插入元素 
    char s='y';
    while(s=='y'||s=='Y')
    {
    	system("cls");
    	string name1,no1;
    	double temp[4];
    	cout<<"请输入学生姓名："<<endl;
    	cin>>name1;
    	cout<<"请输入学生学号："<<endl;
    	cin>>no1;
    	cout<<"请按照顺序输入学生的四门课成绩："<<endl;
    	cout<<"(默认顺序为：数学，英语，线性代数，概率论)"<<endl;
		for(int i=0;i<4;i++)
		{
			cin>>temp[i];
		}
		student x(name1,no1,temp);
		L.info[++L.num]=x;
		cout<<"是否继续？(Y/N)"<<endl;
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
{   //显示排名 
	if(L.num>0)
	{
		QSort(L,1,L.num);
		cout<<"Ranking:"<<endl;
		for(int i=1;i<=L.num;i++)
		{
			cout<<"学号："<<L.info[i].sno <<"  姓名："<<L.info[i].sname ; 
			cout<<"  总分："<<L.info[i].sum<<"  平均分："<<L.info[i].average<<"  排名:"<<i<<endl; 
		}
	}
}
void search1(stu_list &L,string name)
{	//按姓名查找 
	for(int i=1;i<=L.num;i++)
	{
		if(L.info[i].sname==name)
		{
			cout<<"学号："<<L.info[i].sno <<"  姓名："<<L.info[i].sname; 
			cout<<"  总分："<<L.info[i].sum<<"  平均分："<<L.info[i].average<<endl; 
			return;
		}
		
	}
	
	cout<<"查询失败！"<<endl;
}

void search2(stu_list &L,string no)
{	//按学号查找 
	for(int i=1;i<=L.num;i++)
	{
		if(L.info[i].sno==no)
		{
			cout<<"学号："<<L.info[i].sno <<"  姓名："<<L.info[i].sname; 
			cout<<"  总分："<<L.info[i].sum<<"  平均分："<<L.info[i].average<<endl; 
			return ;
		}
	}
	cout<<"查询失败！"<<endl;
}
void Search(stu_list &L)
{
	cout<<"请确认查找方式："<<endl;
	cout<<" 1.按姓名查找      2.按学号查找"<<endl;
	char s;
	cin>>s;
	if(s=='1')
	{
		string name;
		cout<<"请输入姓名："<<endl;
		cin>>name;
		search1(L,name);
	}
	if(s=='2')
	{
		string no;
		cout<<"请输入学号："<<endl;
		cin>>no;
		search2(L,no);
	}	
}
bool Is_empty(stu_list &L)
{
	if(L.num==0)
	{
		cout<<"学生信息表为空！"<<endl;
		return true;
	}
	else 
	{
		return false;
	}
}
void Modify(stu_list &L)
{
	cout<<"请输入要修改的学生的学号："<<endl;
	string s;
	cin>>s;
	for(int i=1;i<=L.num;i++)
	{
		if(L.info[i].sno==s)
		{
			cout<<"请输入要修改的信息：(学号不可修改！)"<<endl;
			cout<<"1.姓名  2.成绩"<<endl;
			char c;
			cin>>c;
			if(c=='1')
			{
				string name1;
				cin>>name1;
				L.info[i].sname=name1;
				cout<<"修改成功！"<<endl; 
				return ;
			}
			if(c=='2') 
			{
		    	cout<<"请按照顺序输入学生的四门课成绩：";
		    	cout<<"(默认顺序为：数学，英语，线性代数，概率论)"<<endl;
				for(int j=0;j<4;j++)
				{
					cin>>L.info[i].course[j];
				}
				cout<<"修改成功!"<<endl;
				return;
			}
		}	
	} 
	cout<<"查无此人！"<<endl;
}

void menu(stu_list &L) 
{	 
	int key;
	do {
		system("cls"); 
		cout<<"\t\t\t....................menu...........................\n";
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t *     │1.学生信息录入       \n";
		cout<<"\t\t\t *     │2.学生信息查询       \n";
		cout<<"\t\t\t *     │3.学生信息修改       \n";
		cout<<"\t\t\t *     │4.学生成绩排序   \n";
		cout<<"\t\t\t *     │5.学生成绩输出		\n";
		cout<<"\t\t\t *     │6.退出       		\n";
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
				cout<<"正在退出"<<endl;
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













