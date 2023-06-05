#include<iostream>
#define size 10
using namespace std;
class obst
{
    int n, p[size],q[size],a[size],w[size][size],c[size][size],r[size][size];
    public:
        void getdata();
        int minvalue(int i, int j);
        void build_obst();
        void build_tree();
};
void obst::getdata()
{
    cout<<"\n OBST TREE"<<endl;
    int i;
    cout<<"Enter total no of nodes"<<endl;
    cin>>n;
    cout<<"enter identifiers<<endl"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"a["<<i<<"]: ";
        cin>>a[i];
    }
    cout<<"enter success probability"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"p["<<i<<"]: ";
        cin>>p[i];
    }
    cout<<"Failure probability"<<endl;
    for(i=0;i<=n;i++)
    {
        cout<<"q["<<i<<"]; ";
        cin>>q[i];
    }
}
int obst::minvalue(int i, int j)
{
    int m,k;
    int minimum=32000;
    for(m=r[i][j-1];m<=r[i+1][j];m++)
    {
        if((c[i][m-1]+c[m][j])<minimum)
        {
            minimum=c[i][m-1]+c[m][j];
            k=m;
        }
    }
    return k;
}
void obst::build_obst()
{
    int i,j,k,m;
    for(i=0;i<n;i++)
    {
    w[i][i]=q[i];
    c[i][i]=r[i][i]=0;

    w[i][i+1]=q[i]+p[i+1]+q[i+1];
    c[i][i+1]=q[i]+p[i+1]+q[i+1];
    r[i][i+1]=i+1;
    }
    w[n][n]=q[n];
    c[n][n]=r[n][n]=0;
    
    for(m=2;m<=n;m++)
    {
        for(i=0;i<=n-m;i++)
        {
            j=i+m;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            k=minvalue(i,j);
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            r[i][j]=k;
        }
    }
}
void obst::build_tree()
{
    int i,j,k;
    int queue[20],front=-1,rear=-1;
    cout<<"\nOBST TREE"<<endl;
    cout<<"ROOT is: "<<r[0][n];
    cout<<"Cost of obst is: "<<c[0][n];
    cout<<"\n\tnode\tleftchild\trightchild"<<endl;
    queue[++rear]=0;
    queue[++rear]=n;
    while(front!=rear)
    {
        i=queue[++front];
        j=queue[++front];
        k=r[i][j];
        cout<<"\n\t"<<k;
        if(r[i][k-1]!=0)
        {
            cout<<"\n\t\t"<<r[i][k-1];
            queue[++rear]=i;
            queue[++rear]=k-1;
        }
        else
        cout<<"\t\t";
        if(r[k][j]!=0)
        {
            cout<<"\t"<<r[k][j];
            queue[++rear]=k;
            queue[++rear]=j;
        }
        else
        cout<<"\t";
    }
    cout<<"\n";
}
int main()
{
    obst tr;
    tr.getdata();
    tr.build_obst();
    tr.build_tree();
    return 0;
}