#include<bits/stdc++.h>
#include <windows.h>
#define Max 100
using namespace std;

struct Node{
		int data;
		int priority;
};

struct PriorityQueue{
    int Size;			//�����洢����Ԫ�صĸ�����Ҳ���ǶѵĴ�С
    Node Elements[Max];		//������Ŷѵ�����
};

void Swap(Node &a,Node &b)
{
    swap(a.data,b.data);
    swap(a.priority,b.priority);
}

void initRandomize (int arr[], int n, int min, int max)
{
    srand(time(0));  			/*��������,������α�������*/
    for(int j=1;j<=n;j++)
    {
    	arr[j]= rand() % (max - min + 1) + min;  /*�õ���[min, max]֮��������*/
	}
		cout<<endl;
}

//��㸳ֵ 
void assi(Node &a,Node &b)
{
	a.data=b.data;
	a.priority=b.priority;
}

//��ʼ�� 
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
    cout<<"�����ɹ���"<<endl; 
    return H;
}

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(PriorityQueue H)
{
	if(H.Size==0)
	return true;
	else return false;
}

//�ж϶����Ƿ�Ϊ�� 
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
		if (tmp >=H.Elements[i].priority) //���ý���
			break;
		Swap(H.Elements[k],H.Elements[i]);
		//cout<<"����"<<k<<"    "<<i<<endl;
		k = i; //��������
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
		siftup(H,i); //�����һ����㣬�����ϵ� 
	}
	return;
}

// ����Ԫ��
void Insert(PriorityQueue &H)
{
	cout<<"���������Ԫ�أ�"<<endl;
	Node x;
	cout<<"��ֵ�� "<<endl;
	cin>>x.data;
	cout<<"���ȼ���"<<endl;
	cin>>x.priority;
    if(IsFull(H))
    {
        cout<<"PriorityQueue Is Full"<<endl;
        return;
    }
    H.Size+=1;
}

//ɾ����Сֵ
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
    cout<<"������ȼ�Ԫ��Ϊ��"<<endl;
    cout<<x.data<<endl;
    cout<<"���ȼ�Ϊ��"<<endl; 
    cout<<x.priority <<endl;
    H.Size--;
    cout<<"���������" <<endl; 
}

//���ȶ��еĲ�ѯ
void search(PriorityQueue &H) 
{
	int x;
	cout<<"������Ҫ���ҵ�Ԫ��ֵ"<<endl;
	cin>>x;
	int n=H.Size,i=1;
	while(H.Elements[i].data!=x&&i<=n)
	{
		i++;
	}
	if(i>n)
	{
		cout<<"����ʧ�ܣ��������޸�Ԫ��"<<endl;
		return;
	}
	else
	{
		cout<<"Ԫ��"<<x<<"��λ���±꣺ "<<i<<"  ���ȼ��� "<<H.Elements[i].priority<<endl; 
	}
}

//����Ԫ�����ȼ�
void adjust(PriorityQueue &H)
{
	int x;
	cout<<"������Ҫ������Ԫ��ֵ"<<endl;
	cin>>x;
	int n=H.Size,i=1;
	while(H.Elements[i].data!=x&&i<=n)
	{
		i++;
	}
	if(i>n)
	{
		cout<<"����ʧ�ܣ��������޸�Ԫ��"<<endl;
		return;
	}
	else
	{
		int t;
		cout<<"�������µ����ȼ�"<<endl;
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
		cout<<"\t\t *     ��1.�������ȶ���       \n";
		cout<<"\t\t *     ��2.����Ԫ��       \n";
		cout<<"\t\t *     ��3.������ȼ�Ԫ�س�����       \n";
		cout<<"\t\t *     ��4.����Ԫ�����ȼ�   \n";
		cout<<"\t\t *     ��5.�����ȶ��еĳ���		\n";
		cout<<"\t\t *     ��6.���ȶ��еĲ�ѯ     \n";
		cout<<"\t\t *     ��7.�˳�       		\n";
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
				cout<<"���ȶ��г���Ϊ��"<<H.Size<<endl;
				system("pause");
				break;
			case 6:
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
    int i,num;
    PriorityQueue H;
    menu(H); 
  	/*for(int i=1;i<=num;i++)
  	{
  		printf("���ݣ�%d  ���ȼ���%d\n",H.Elements[i].data ,H.Elements[i].priority);
	}
	
	siftdown(H);
	DeleteMin(H);
	//printf("���ݣ�%d  ���ȼ���%d\n",x.data ,x.priority);
	//cout<<endl;
	
    for(int i=1;i<=H.Size;i++)
        printf("���ݣ�%d  ���ȼ���%d\n",H.Elements[i].data ,H.Elements[i].priority);*/
  
    return 0;
}








