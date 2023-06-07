#include<iostream>
#define max 10
#define true 1
#define false 0
using namespace std;
class bfsl
{
    typedef struct node1
    {
        int vertex;
        struct node1* next;
    }node;
    node *head[max];
    int queue[max],visited[max],front,rear;
    public:
        bfsl();
        void create();
        void bfs(int);
};
bfsl::bfsl()
{
    int v1;
    for(v1=0;v1<max;v1++)
        visited[v1]=false;
    front=rear=-1;
    for(v1=0;v1<max;v1++)
        head[v1]=NULL;
}
void bfsl::create()
{
    int v1,v2;
    node *news,*first;
    char ans;
    do
    {
        cout<<"\n Enter edges"<<endl;
        cin>>v1;
        cin>>v2;
        if(v1>=max || v2>=max)
            cout<<"Invalid edge"<<endl;
        else
        {
        news=new node;
        if(news==NULL)
            cout<<"\n insufficient memory"<<endl;
        news->vertex=v2;
        news->next=NULL;
        first=head[v1];
        if(first==NULL)
            head[v1]=news;
        else{
            while(first->next!=NULL)
                first=first->next;
            first->next=news;
        }
        
        news=new node;
        news->vertex=v1;
        news->next=NULL;
        first=head[v2];
        if(first==NULL)
            head[v2]=news;
        else
        {
            while(first->next!=NULL)
                first=first->next;
            first->next=news;
        }
        }
        cout<<"\n You want to insert more edges(enter y/n): ";
        cin>>ans;
        
    }while(ans=='y');
}
void bfsl::bfs(int v1)
{
    int i;
    node *first;
    queue[++rear]=v1;
    while(front!=rear)
    {
        i=queue[++front];
        if(visited[i]==false)
        {
            cout<<endl<<i<<" ";
            visited[i]=true;
        }
        first=head[i];
        while(first!=NULL)
        {
            if(visited[first->vertex]==false)
                queue[++rear]=first->vertex;
                first=first->next;
        }
    }
}
int main()
{
    int v;
    bfsl bs;
    bs.create();
    cout<<"\n Enter starting vertex; "<<endl;
    cin>>v;
    cout<<"\n\nBFS TRAVERSAL :\n";
    bs.bfs(v);
    return 0;
}

/*Enter edges
0 2
You want to insert more edges(enter y/n): y
Enter edges
0 1
You want to insert more edges(enter y/n): y
Enter edges
2 0
You want to insert more edges(enter y/n): y
Enter edges
1 2
You want to insert more edges(enter y/n): y
Enter edges
3 3
You want to insert more edges(enter y/n): y
Enter edges
2 3
You want to insert more edges(enter y/n): n
Enter starting vertex; 
2
BFS TRAVERSAL :

2 
0 
1 
3 */ 
