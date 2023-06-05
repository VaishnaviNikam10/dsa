#include<iostream>
#define infi 9999
#define max 10
using namespace std;
class prims
{
    int graph[max][max],nodes;
    public:
        void creategraph();
        void primsalgo();
};
void prims::creategraph()
{
    int i,j;
    cout<<"\nEnter total no. of offices"<<endl;
    cin>>nodes;
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            cout<<"\n Enter distance between"<<i<<" and "<<j<<": ";
            cin>>graph[i][j];

        }
    }
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            if(graph[i][j]==0)
                graph[i][j]=infi;
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
void prims::primsalgo()
{
    int selected[max],i,j,ne=0;
    int zero=0,one=1,min=0,x,y;
    int cost=0;
    for(i=0;i<nodes;i++)
        selected[i]=zero;
    selected[0]=one;
    while(ne<nodes-1)
    {
        min=infi;
        for(i=0;i<nodes;i++)
        {
            if(selected[i]==one)
            {
                for(j=0;j<nodes;j++)
                {
                    if(selected[j]==zero)
                    {
                        if(min>graph[i][j])
                        {
                            min=graph[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        selected[y]=one;
        cout<<"\n"<<x<<"-->"<<y<<"\n";
        cost+=graph[x][y];
        ne++;

    }
    cout<<"\n Total cost: "<<cost;
}
int main()
{
    prims pm;
    pm.creategraph();
    pm.primsalgo();
    return 0;
}
