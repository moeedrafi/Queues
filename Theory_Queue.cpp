#include<iostream>
using namespace std;
class Queue_LL {
	private:
		struct Node 
		{
			int value;
			Node *next;
		} *front, *rear;
	public:
		Queue_LL() : front(NULL), rear(NULL) { }
		~Queue_LL() 
		{
			makeEmpty(); 
		}
		bool isEmpty() 
		{ 
			return (front == NULL); 
		}
		bool isFull();
		void makeEmpty();
		bool tryEnqueue(int);
		bool tryDequeue(int&);
		void display();
};
bool Queue_LL::isFull() 
{
	Node *temp = new (nothrow) Node;  //When Memory Full RAM , ROM
	if(temp != NULL) 
	{
		delete temp;
		return false;
	}
	else 
	{
		return true; 
	}
}
void Queue_LL::makeEmpty() 
{
	Node *temp;
	while(front != NULL) 
	{
		temp = front;
		front = front->next;
		delete temp;	
	}
	rear = NULL;
}
bool Queue_LL::tryEnqueue(int newValue) 
{
	if(isFull()) 
	{ 
		return false; 
	}
	Node *newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;
	if(rear == NULL) 
	{ 
		front = newNode; 
	}
	else 
	{ 
		rear->next = newNode; 
	}
	rear = newNode;
	return true;
}
bool Queue_LL::tryDequeue(int &removedValue) 
{
	if(isEmpty()) 
	{ 
		return false; 
	}
	Node *temp = front;
	removedValue = front->value;
	front = front->next;
	if(front == NULL) 
	{ 
		rear = NULL; 
	}
	delete temp;
	return true;
}
void Queue_LL::display() 
{
	if(isEmpty()) 
	{ 
		cout << "Queue is Empty!" << endl; 
	}
	else 
	{
		for(Node *ptr = front; ptr != NULL; ptr = ptr->next)
		{
			cout << ptr->value << ", ";
		}
		cout << "\b\b " << endl;
	}
}
int main() 
{
	Queue_LL queue;
	int choice, num;
	do 
	{
		cout << endl << "Menu" << endl;
		cout << "1. ENQUEUE" << endl;
		cout << "2. DEQUEUE" << endl;
		cout << "3. DISPLAY" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch(choice) 
		{
			case 1:
				cout << "Enter value to Enqueue: "; cin >> num;
				if(!queue.tryEnqueue(num)) 
				{
					cout << "Queue is Full!" << endl;
				} break;
			case 2: 
				if(queue.tryDequeue(num)) 
				{
					cout << num << " removed from Queue." << endl;
				}
				else 
				{
					cout << "Queue is Empty!" << endl;
				} 
				break;
			case 3: 
				queue.display(); 
				break;
			case 4: 
				return 0;
			default: 
				cout << "Invalid Choice!" << endl; break;
		}
	}while(choice != 4);
}

