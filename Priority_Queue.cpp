#include<iostream>
using namespace std;
struct node
{
	char letter;
	int p;
	node *next;
};
class PQ
{
	private:
		node *front,*rear;
	public:
		PQ()
		{
			front = rear = NULL;
		}
		void enqueue(char letter,int p)
		{
			node *temp = new node;
			temp->letter = letter;
			temp->p = p;
			temp->next = NULL;
			if(front == NULL && rear == NULL)
			{
				front = rear = temp;
			}
			else if(temp->p < front->p)     // add to head
			{
				temp->next = front;
				front = temp;
			}
			else if(temp->p >= rear->p)    //add to end
			{
				rear->next = temp;
				rear = temp;
			}
			else
			{
				node *f = front , *r = front->next;
				while(r!=NULL)
				{
					if(temp->p > f->p && temp->p <= r->p)
					{
						f->next = temp;
						temp->next = r;
					}
					f = f->next;
					r = r->next;
				}
			}
		}
		void dequeue()
		{
			node *q = front;
			while(q->next!=NULL)
			{
				q = q->next;
			}
			q->next = NULL;
			rear = q;
		}
		void display()
		{
			node *dis = front;
			while(dis!=NULL)
			{
				cout<<"Letter : "<<dis->letter<<" having Priority : "<<dis->p<<endl;
				dis = dis->next;
			}
		}
};
int main()
{
	PQ p;
	p.enqueue('B',2);
	p.enqueue('A',1);
	p.enqueue('D',4);
	p.enqueue('C',3);
	p.display();
}
