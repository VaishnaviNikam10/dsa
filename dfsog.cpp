#include<iostream>
#define max 20
#define true 1
#define false 0
using namespace std;
class stack
{
    int v1,v2,m[max][max],v[max];
    public:
        int n,e;
        int st[10];
        int top;
        stack();
        ~stack();
        void push(int);
        int pop();
        void create();
        void display();
        void dfs(int v1);
};
stack::stack()
{
    for(v1=0;v1<max;v1++)
        v[v1]=false;
    for(v1=0;v1<max;v1++)
        for(v2=0;v2<max;v2++)
            m[v1][v2]=false;
    for(v1=0;v1<max;v1++)
        st[v1]=false;
        top=-1;
}
stack::~stack()
{
    for(v1=0;v1<max;v1++)
        v[v1]=false;
    for(v1=0;v1<max;v1++)
    {
        for(v2=0;v2<max;v2++)
            m[v1][v2]=false;    
    }
}
void stack::push(int item)
{
    st[++top]=item;
}
int stack::pop()
{
    int item;
    item=st[top];
    top--;
    return item;
}
void stack::create()
{
    int v1,v2;
    cout<<"\n Enter total no. of nodes"<<endl;
    cin>>n;
    cout<<"Enter total no. of edges"<<endl;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cout<<"enter edge"<<endl;
        cin>>v1;
        cin>>v2;
        m[v1][v2]=true;
        m[v2][v1]=true;

    }
}
void stack::display()
{
    cout<<"\n Adjency matrix is:"<<endl;
    for(v1=0;v1<n;v1++)
    {
        for(v2=0;v2<n;v2++)
        {
            cout<<m[v1][v2]<<" ";
        }
        cout<<endl;
    }
}
void stack::dfs(int v1)
{
    int v2;
    push(v1);
    while(top!=-1)
    {
        v1=pop();
        if(v[v1]==false)
        {
            cout<<v1<<" ";
            v[ v1]=true;
        }
        for(v2=0;v2<n;v2++)
            if(m[v1][v2]==true && v[v2]==false)
                push(v2);
    }
}
int main()
{
    stack s;
    s.create();
    s.display();
    int v;
    cout<<"\nenter starting vertex"<<endl;
    cin>>v;
    s.dfs(v);
    return 0;
}