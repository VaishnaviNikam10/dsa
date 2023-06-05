#include<iostream>
using namespace std;
struct node
{
    char label[10];
    int chcount;
    node *child[10];
};
node *root;
class tree
{
    public:
        tree()
        {
            root=NULL;
        }
        void create();
        void display(node*);
};
void tree::create()
{
    int i,j,k,tch;
    cout<<"enter the name of book"<<endl;
    root=new node;
    cin>>root->label;
    cout<<"enter no of chapter in book"<<endl;
    cin>>tch;
    root->chcount=tch;
    for(i=0;i<tch;i++)
    {
        root->child[i]=new node;
        cout<<"enter name of chapter:"<<i+1<<endl;
        cin>>root->child[i]->label;
        cout<<"enter the no section of chapter "<<i+1<<" :"<<endl;
        cin>>root->child[i]->chcount;
        for(j=0;j<root->child[i]->chcount;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"enter the name of section:"<<endl;
            cin>>root->child[i]->child[j]->label;
            cout<<"enter the no of sub-section of section "<<j+1<<":"<<endl;
            cin>>root->child[i]->child[j]->chcount;
            for(k=0;k<root->child[i]->child[j]->chcount;k++)
            {
                cout<<"enter subsection "<<j+1<<"."<<k+1<<" title"<<endl;
                root->child[i]->child[j]->child[k]=new node;
                cin>>root->child[i]->child[j]->child[k]->label;

            }


        }
    }
}
void tree::display(node *root)
{
    int tch,i,j,k;
    if(root!=NULL)
    {
        cout<<"BOOk TREE hierarchy"<<endl;
        tch=root->chcount;
        for(i=0;i<tch;i++)
        {
            cout<<"chapter "<<i+1<<": ";
            cout<<root->child[i]->label<<endl;
            for(j=0;j<root->child[i]->chcount;j++)
            {
                cout<<"Section "<<j+1<<": ";
                cout<<root->child[i]->child[j]->label<<endl;
                for(k=0;k<root->child[i]->child[j]->chcount;k++)
                {
                    cout<<"Sub-section "<<j+1<<"."<<k+1<<": ";
                    cout<<root->child[i]->child[j]->child[k]->label<<endl;
                }
            }
        }
    }
}
int main()
{
    tree tr;
    tr.create();
    tr.display(root);
    return 0;
}
