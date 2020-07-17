#include<bits/stdc++.h>
#include <windows.h>
#define Max 100
using namespace std;

struct Node{
		int data;
		int priority;
};

struct PriorityQueue{
    int Size;			//用来存储堆中元素的个数，也就是堆的大小
    Node Elements[Max];		//用来存放堆的数组
};

void Swap(Node &a,Node &b)
{
    swap(a.data,b.data);
    swap(a.priority,b.priority);
}

void initRandomize (int arr[], int n, int min, int max)
{
    srand(time(0));  			/*设置种子,并生成伪随机序列*/
    for(int j=1;j<=n;j++)
    {
    	arr[j]= rand() % (max - min + 1) + min;  /*得到从[min, max]之间的随机数*/
	}
		cout<<endl;
}

//结点赋值 
void assi(Node &a,Node &b)
{
	a.data=b.data;
	a.priority=b.priority;
}

//初始化 
PriorityQueue Init_Queue(PriorityQueue &H)
{ 
    H.Size=0;
    H.Elements[0].data=-1;
    H.Elements[0].priority=-1;
    int arr[11];
    initRandomize(arr,10,1,10);
    for(int i=1;i<=10;i++)
    {
       H.Elements[i].data=i;
       H.Elements[i].priority=arr[i];
	}
    H.Size=10; 
    cout<<"创建成功！"<<endl; 
    return H;
}

//判断队列是否为空
bool IsEmpty(PriorityQueue H)
{
	if(H.Size==0)
	return true;
	else return false;
}

//判断队列是否为满 
bool IsFull(PriorityQueue H)
{
	if(H.Size==Max)
	return true;
	else return false;
}

void siftup(PriorityQueue &H, int k)
{
	int tmp = H.Elements[k].priority;
	int tmp2=H.Elements[k].data;
	int i=k/2;
	while (i>=1) 
	{
		//cout<<i<<"     " <<tmp<<endl;
		if (tmp >=H.Elements[i].priority) //不用交换
			break;
		Swap(H.Elements[k],H.Elements[i]);
		//cout<<"交换"<<k<<"    "<<i<<endl;
		k = i; //继续查找
		i = k/2;
	}
	H.Elements[k].priority = tmp;
	H.Elements[k].data =tmp2;
}

void HeapSort(PriorityQueue &H)
{
	if (H.Size <= 0)
	return;
	for (int i=H.Size;i>=1; --i) 
	{
		siftup(H,i); //从最后一个结点，依次上调 
	}
	return;
}

// 插入元素
void Insert(PriorityQueue &H)
{
	cout<<"输入待插入元素："<<endl;
	Node x;
	cout<<"数值： "<<endl;
	cin>>x.data;
	cout<<"优先级："<<endl;
	cin>>x.priority;
    if(IsFull(H))
    {
        cout<<"PriorityQueue Is Full"<<endl;
        return;
    }
    H.Size+=1;
}

//删除最小值
void DeleteMin(PriorityQueue &H)
{
    int i,Child;
    Node x;
    if(IsEmpty(H))
    {
        cout<<"PriorityQueue Is Empty"<<endl;
        x.data=-1;
        x.priority=-1;
        return;
    }
    assi(x,H.Elements[1]);
    assi(H.Elements[1],H.Elements[H.Size]);
    cout<<"最高优先级元素为："<<endl;
    cout<<x.data<<endl;
    cout<<"优先级为："<<endl; 
    cout<<x.priority <<endl;
    H.Size--;
    cout<<"出队列完成" <<endl; 
}

//优先队列的查询
void search(PriorityQueue &H) 
{
	int x;
	cout<<"请输入要查找的元素值"<<endl;
	cin>>x;
	int n=H.Size,i=1;
	while(H.Elements[i].data!=x&&i<=n)
	{
		i++;
	}
	if(i>n)
	{
		cout<<"查找失败，队列中无该元素"<<endl;
		return;
	}
	else
	{
		cout<<"元素"<<x<<"的位置下标： "<<i<<"  优先级： "<<H.Elements[i].priority<<endl; 
	}
}

//调整元素优先级
void adjust(PriorityQueue &H)
{
	int x;
	cout<<"请输入要调整的元素值"<<endl;
	cin>>x;
	int n=H.Size,i=1;
	while(H.Elements[i].data!=x&&i<=n)
	{
		i++;
	}
	if(i>n)
	{
		cout<<"查找失败，队列中无该元素"<<endl;
		return;
	}
	else
	{
		int t;
		cout<<"请输入新的优先级"<<endl;
		cin>>t;
		H.Elements[i].priority=t;
	}
} 



void menu(PriorityQueue &H) {
	int key;
	string n1,t1;
	int x;
	do {
		system("cls"); 
		cout<<"\t\t....................menu...........................\n";
		cout<<"\t\t***************************************************\n";
		cout<<"\t\t *     │1.创建优先队列       \n";
		cout<<"\t\t *     │2.插入元素       \n";
		cout<<"\t\t *     │3.最大优先级元素出队列       \n";
		cout<<"\t\t *     │4.调整元素优先级   \n";
		cout<<"\t\t *     │5.求优先队列的长度		\n";
		cout<<"\t\t *     │6.优先队列的查询     \n";
		cout<<"\t\t *     │7.退出       		\n";
		printf("\t\t\t***************************************************\n");
		cout << endl;
		cin >> key;
		switch (key) 
		{
			case 1:
				Init_Queue(H); 
				system("pause");
				break;
			case 2:	
				Insert(H);
				break;
			case 3: 
				HeapSort(H);
				DeleteMin(H);
				system("pause");
				break; 
			case 4:
				adjust(H);
				system("pause");
				break;
			case 5:
				cout<<"优先队列长度为："<<H.Size<<endl;
				system("pause");
				break;
			case 6:
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
    int i,num;
    PriorityQueue H;
    menu(H); 
  	/*for(int i=1;i<=num;i++)
  	{
  		printf("数据：%d  优先级：%d\n",H.Elements[i].data ,H.Elements[i].priority);
	}
	
	siftdown(H);
	DeleteMin(H);
	//printf("数据：%d  优先级：%d\n",x.data ,x.priority);
	//cout<<endl;
	
    for(int i=1;i<=H.Size;i++)
        printf("数据：%d  优先级：%d\n",H.Elements[i].data ,H.Elements[i].priority);*/
  
    return 0;
}








