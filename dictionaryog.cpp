#include<iostream>
#include<string.h>
using namespace std;
typedef struct node
{
    char k[20];
    char m[20];
    class node *left;
    class node *right;
}node;
class dict
{
    public:
        node *root;
        void create();
        void insert(node*,node*);
        void display(node*);
        int search(node*,char[]);
        node* delet(node*,char[]);
        int update(node*,char[]);
        node* min(node*);
};
void dict::create()
{
    class node *temp;
    int ch;
    do
    {
        temp=new node;
        cout<<"\n Enter the key point:"<<endl;
        cin>>temp->k;
        cout<<"\n Enter the meaning"<<endl;
        cin>>temp->m;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            insert(root,temp);
        }
        cout<<"\nyou want to insert more (yes=1 & no=0):"<<endl;
        cin>>ch;
    } while (ch==1);
    
}
void dict::insert(node *root,node *temp)
{
    if (strcmp(temp->k,root->k)<0)
    {
        if(root->left==NULL)
            root->left=temp;
        else
            insert(root->left,temp);
    }
    else{
        if(root->right==NULL)
            root->right=temp;
        else
            insert(root->right,temp);
    }
}
void dict::display(node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        cout<<"\n Key word: "<<root->k;
        cout<<"\t Meaning:  "<<root->m;
        display(root->right);
    }
}
int  dict::search(node *root,char k[20])
{
    int c=0;
    while (root!=NULL)
    {
        c++;
        if(strcmp(k,root->k)==0)
        {
            cout<<"total no. of comparisons: "<<c<<endl;
            return 1;
        }
        if(strcmp(k,root->k)<0)
            root=root->left;
        if(strcmp(k,root->k)>0)
            root=root->right;
    }
    return -1;
    
}
int dict::update(node *root,char k[20])
{
    while(root!=NULL)
    {
        if(strcmp(k,root->k)==0)
        {
            cout<<"enter the meaning of keyword["<<root->k<<"]: ";
            cin>>root->m;
            return 1;
        }
        if(strcmp(k,root->k)<0)
            root=root->left;
        else
            root=root->right;

    }
    return -1;
}
node* dict::delet(node *root,char k[20])
{
    node *temp;
    if(root==NULL)
    {
        cout<<"key point not found "<<endl;
        return root;
    }
    if(strcmp(k,root->k)<0)
    {
        root->left=delet(root->left,k);
        return root;
    }
    if(strcmp(k,root->k)>0)
    {
        root->right=delet(root->right,k);
        return root;
    }
    if(root->right==NULL && root->left==NULL)
    {
        temp=root;
        delete temp;
        return NULL;
    }
    if(root->right==NULL)
    {
        temp=root;
        root=root->left;
        delete temp;
        return root;
    }
    if(root->left==NULL)
    {
        temp=root;
        root=root->right;
        delete temp;
        return root;
    }
    temp=min(root->right);
    strcpy(root->k,temp->k);
    root->right=delet(root->right,temp->k);
    return root;
}
node* dict::min(node *q)
{
    while(q->left!=NULL)
    {
        q=q->left;
    }
    return q;
}

int main()
{
    dict dt;
    dt.root=NULL;
    int ch;
    do
    {
        cout<<"\n1]create\n2]display\n3]search\n4]update\n5]delete\n6]exit"<<endl;
        cout<<"enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                dt.create();
                break;
            case 2:
            if(dt.root==NULL)
            {
                cout<<"dictionary is empty"<<endl;
                break;
            }
            else
            {
                dt.display(dt.root);
            }
            break;
            case 3:
            if(dt.root==NULL)
            {
                cout<<"dictionary is empty"<<endl;
            }
            else{
                cout<<"enter key point to be search: "<<endl;
                char k[20];
                cin>>k;
                if(dt.search(dt.root,k)==1)
                    cout<<"key point is present"<<endl;
                else
                    cout<<"key point is not present"<<endl;
            }
            break;
            case 4:
            if(dt.root==NULL)
            {
                cout<<"dictionary is empty"<<endl;
            }
            else
            {
                cout<<"\n enter the key word you want to search: ";
                char k[20];
                cin>>k;
                if(dt.update(dt.root,k)==1)
                    cout<<"meaning is updated"<<endl;
                else
                    cout<<"meaning is not updated"<<endl;
            }
            break;
            case 5:
            if(dt.root==NULL)
            {
                cout<<"dictionary is empty"<<endl;
            }
            else
            {
                cout<<"enter key that you want to delete"<<endl;
                char k[20];
                cin>>k;
                if(dt.root==NULL)
                {
                    cout<<"no any keyword"<<endl;
                }
                else
                {
                    dt.root=dt.delet(dt.root,k);
                }
            }
            
        }

    } while (ch<=5);
    
    
    return 0;
}
