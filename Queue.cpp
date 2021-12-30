#include<iostream>
using namespace std;
#define size 5
class queue
{
	public:
		int arr[size];
		int front;
		int rear;
		queue()
		{
			front = -1;
			rear = -1;
		}
		void enqueue(int num)
		{
			if(rear == size-1)
			{
				cout<<"Queue is Full.";
			}
			else
			{
				arr[++rear] = num;
				cout<<num<<" added in queue"<<endl;
			}
			if(front == -1)
			{
				front = 0;
			}
		}
		void dequeue()
		{
			if((rear == -1 && front == -1) || front > rear)
			{
				cout<<"Queue is Empty.";
				front = rear = -1;
			}
			else
			{
				cout<<arr[front++]<<" removed from queue"<<endl;
			}
		}
		void display()
		{
			for(int i = front ; i<= rear ; i++)
			{
				cout<<arr[i]<<endl;
			}
		}
};
int main()
{
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	cout<<"Before Dequeue."<<endl;
	q.display();
	q.dequeue();
	cout<<"After Dequeue."<<endl;
	q.display();
}
