#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class studentclass
{
    typedef struct student
    {
        char name[10];
        int roll_no;
        char div;
        char address[50];
    }rec;
    rec records;
    public:
        void create();
        void display();
        void update();
        void delet();
        void append();
        int search();
};
void studentclass::create()
{
    char ch='y';
    ofstream seqfile;
    seqfile.open("student.dat",ios::out|ios::binary);
    do
    {
        
        cout<<"Enter student information"<<endl;
        cout<<"Name:"<<endl;
        cin>>records.name;
        cout<<"Roll no.:"<<endl;
        cin>>records.roll_no;
        cout<<"Division:"<<endl;
        cin>>records.div;
        cout<<"Address:"<<endl;
        cin>>records.address;
        seqfile.write((char *)&records,sizeof(records))<<flush;
        cout<<"You want to add more records"<<endl;
        cin>>ch;
    }while (ch=='y');
    seqfile.close();
}
void studentclass::display()
{
    ifstream seqfile;
    seqfile.open("student.dat",ios::in|ios::binary);
    seqfile.seekg(0,ios::beg);
    cout<<"contents are"<<endl;
    cout<<"\n\tName\tRoll_No.\tDiv\tAddress"<<endl;
    while(seqfile.read((char *)&records,sizeof(records)))
    {
        if(records.roll_no!=-1)
        {
            cout<<"\t"<<records.name<<"\t"<<records.roll_no<<"\t"<<records.div<<"\t"<<records.address<<endl;
        }
    }
    seqfile.close();
}

void studentclass::delet()
{
    cout<<"\n for deletion"<<endl;
    int pos,id;
    pos=search();
    fstream seqfile;
    seqfile.open("student.dat",ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    if(pos==-1)
    {
        cout<<"Data not found"<<endl;
        return;
    }
    int offset=pos*sizeof(rec);
    seqfile.seekp(offset);
    strcpy(records.name,"NULL");
    records.roll_no=-1;
    records.div=-1;
    strcpy(records.address,"NULL");
    seqfile.write((char *)&records,sizeof(records));
    seqfile.seekg(0);
    seqfile.close();
    cout<<"\n deletion is done"<<endl;
}
void studentclass::append()
{
    cout<<"\n For append"<<endl;
    fstream seqfile;
    seqfile.open("student.dat",ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    int i=0;
    while (seqfile.read((char*)&records,sizeof(records)))
    {
        i++;                                               // or simply use: seqfile.seekg(0,ios::end)
    }
    seqfile.clear();
    cout<<"enter the data"<<endl;
    cout<<"\n Name: "; cin>>records.name;
    cout<<"\n Roll no.: "; cin>>records.roll_no;
    cout<<"\n Division: "; cin>>records.div;
    cout<<"\n Address: "; cin>>records.address;
    cout<<endl;
    seqfile.write((char*)&records,sizeof(records));
    seqfile.seekg(0);
    seqfile.close();  
}
int studentclass::search()
{
    fstream seqfile;
    int id, pos;
    cout<<"\n Enter teh roll no. that you want to search"<<endl;
    cin>>id;
    seqfile.open("student.dat",ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    pos=-1;
    int i=0;
    while(seqfile.read((char*)&records,sizeof(records)))
    {
        if(id==records.roll_no)
        {
            pos=i;
            cout<<"\n Data is found"<<endl;
            break;
        }
        i++;
    }
    return pos;
}

int main()
{
    studentclass sc;
    sc.create();
    sc.display();
    sc.delet();
    sc.display();
    sc.append();
    sc.display();
    sc.search();
    return 0;
}