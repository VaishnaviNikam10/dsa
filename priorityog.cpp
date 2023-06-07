#include<iostream>
#define max 10
using namespace std;
class priorityqueue
{
    string qu[max];
    int pr[max];
    int front,rear;
    public:
        priorityqueue()
        {
            front=-1;
            rear=-1;
        }
        bool is_empty()
        {
            return front==-1;
        }
        bool is_full()
        {
            return rear==max-1;
        }
        void enqueue(string,int);
        string dequeue();
        void display();
        int get_priority();
};
void priorityqueue::enqueue(string data,int p)
{
    if(is_full())
    {
        cout<<"\n Queue is full"<<endl;
        return;
    }
    if(is_empty())
    {
        front=0;
        rear=0;
        qu[rear]=data;
        pr[rear]=p;

    }
    else
    {
        int i;
        rear++;
        for(i=rear-1;i>=front;i--)
        {
            if(pr[i]<p)
            {
                qu[i+1]=qu[i];
                pr[i+1]=pr[i];
            }
            else
            {
                break;
            }
        }
        qu[i+1]=data;
        pr[i+1]=p;
    }
}
string priorityqueue::dequeue()
{
    if(is_empty())
    {
        cout<<"\n Queue is empty"<<endl;
        return "";
    }
    string data=qu[front];
        
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
    return data;
}
int priorityqueue::get_priority()
{
    if(is_empty())
    {
        cout<<"\n Queue is empty"<<endl;
        return -1;
    }
    return pr[front];
}
void priorityqueue::display()
{
    if(is_empty())
    {
        cout<<"\n Queue is empty"<<endl;
        return;
    }
    cout<<"\nQueu is:";
    cout<<"\n\tPRIORITY  NAME";
    for(int i=front;i<=rear;i++)
    {
        cout<<"\n\t"<<pr[i]<<"\t  "<<qu[i];
    }
    cout<<endl;
}
int main()
{
    priorityqueue pq;
    string name;
    int priority;
    int ch=0;
    do
    {
        cout<<"\n1]Add Patent\n2]Remove Patent\n3]Display\n4]Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\n Enter name: ";
            cin>>name;
            cout<<"\ntGeneral=0\tNon-serious=1\tSerious=2"<<"\nEnter your choice: ";
            cin>>priority;
            pq.enqueue(name,priority);
            break;
        case 2:
            priority=pq.get_priority();
            name=pq.dequeue();
            cout<<"patient "<<name<<" with priority "<<priority<<" is removed";
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout<<"Thank you"<<endl;
            break;
        default:
            cout<<"invalid choice"<<endl;
            break;
        }
    } while (ch!=4);
    
    return 0;
}

/* 1]Add Patent
2]Remove Patent
3]Display
4]Exit
Enter your choice: 1
Enter name: vv
tGeneral=0	Non-serious=1	Serious=2
Enter your choice: 2
1]Add Patent
2]Remove Patent
3]Display
4]Exit
Enter your choice: 1
Enter name: ss
tGeneral=0	Non-serious=1	Serious=2
Enter your choice: 0
1]Add Patent
2]Remove Patent
3]Display
4]Exit
Enter your choice: 3
Queu is:
	PRIORITY  NAME
	2	  vv
	0	  ss

1]Add Patent
2]Remove Patent
3]Display
4]Exit
Enter your choice: 1
Enter name: mm
tGeneral=0	Non-serious=1	Serious=2
Enter your choice: 1
1]Add Patent
2]Remove Patent
3]Display
4]Exit
Enter your choice: 3
Queu is:
	PRIORITY  NAME
	2	  vv
	1	  mm
	0	  ss*/
