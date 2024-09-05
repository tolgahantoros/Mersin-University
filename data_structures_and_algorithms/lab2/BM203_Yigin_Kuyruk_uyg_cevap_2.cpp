#include<iostream.h>
#include<conio.h>
#define size 4

class cqueue
{
      int data[size];
      int front,rear;
public:
      cqueue()
      {
            front=-1;rear=-1;
      }
      void insert();
      void remove(); 
};

void cqueue::insert()
{
      if(rear==size-1&&front==0 || front==rear+1)
      {
            cout<<"\nCircular queue is full";
            return;
      }
      else if(rear==-1)
      {
            rear++;
            front++;
      }
      else if(rear==size-1)
            rear=0;
      else
            rear++;

      cout<<"Enter Data : ";
      cin>>data[rear];
}

void cqueue::remove()
{
      if(front==-1)
      {
            cout<<"\n Circular Queue is empty";return;
      }

      cout<<data[front]<<" deleted"<<endl;

      if(front==rear)
      {
            front=-1;rear=-1;
      }
      else if(front==size-1)
            front=0;
      else
            front++;
}

int main()
{
      cqueue cq;
      int ch;
      do
      {
            cout<<"\n1. Insert\n2. Remove\n3. Quit\nEnter Choice(1-3) ";
            cin>>ch;
            switch(ch)
            {
                  case 1: cq.insert();break;
                  case 2: cq.remove();break;
            }
      }while(ch!=3);
   return 0;  
}
