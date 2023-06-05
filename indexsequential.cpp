#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class emp_class
{
    typedef struct employee
    {
        int id;
        char name[10];
        int salary;
        char desg[20];

    }rec;
    typedef struct index
    {
        int id;
        int position;
    }ind_rec;
    rec records;
    ind_rec ind_records;
    public:
        emp_class();
        void create();
        void display();
        void search();
        void deleta();
        void update();
        void append();
};
emp_class::emp_class()
{
    strcpy(records.name,"NULL");
}
void emp_class::create()
{
    int i=0;
    char ch='y';
    ofstream seqfile;
    ofstream indfile;
    indfile.open("ind.dat",ios::out|ios::binary);
    seqfile.open("emp.dat",ios::out|ios::binary);
    do
    {
        cout<<"\n Enter employee details"<<endl;
        cout<<"\n ID: ";
        cin>>records.id;
        cout<<"\n Name: ";
        cin>>records.name;
        cout<<"\nSalary: ";
        cin>>records.salary;
        cout<<"\n desg;";
        cin>>records.desg;
        cout<<endl;
        seqfile.write((char *)&records,sizeof(records));
        ind_records.id=records.id;
        ind_records.position=i;
        indfile.write((char *)&ind_records,sizeof(ind_records));
        i++;
        cout<<"\n You want to add more records"<<endl;
        cin>>ch;
    } while (ch=='y');
    seqfile.close();
    indfile.close();

}
void emp_class::display()
{
    fstream seqfile;
    fstream indfile;
    int i;
    indfile.open("ind.dat",ios::in|ios::out|ios::binary);
    seqfile.open("emp.dat",ios::in|ios::out|ios::binary);
    indfile.seekg(0,ios::beg);
    seqfile.seekg(0,ios::beg);
    cout<<"\nContent are:"<<endl;
    cout<<"\n\tID\tName\tSalary\tDesg"<<endl;
    i=0;
    while(indfile.read((char *)&ind_records,sizeof(ind_records)))
    {
        i=ind_records.position*sizeof(rec);
        seqfile.seekg(i,ios::beg);
        seqfile.read((char *)&records,sizeof(records));
        if(records.id!=-1)
        {
            cout<<"\n\t"<<records.id<<"\t"<<records.name<<"\t"<<records.salary<<'\t'<<records.desg<<endl;
        }
    }
    seqfile.close();
    indfile.close();
}
void emp_class::append()
{
    cout<<"\n To add record"<<endl;
    fstream seqfile;
    fstream indfile;
    int pos;
    indfile.open("ind.dat",ios::in|ios::binary);
    indfile.seekg(0,ios::end);
    pos=indfile.tellg()/sizeof(ind_records);
    indfile.close();

    indfile.open("ind.dat",ios::app|ios::out|ios::binary);
    seqfile.open("emp.dat",ios::app|ios::out|ios::binary);
    //seqfile.seekg(0,ios::end);
    cout<<"\n Enter records"<<endl;
    cout<<"\n Id: "; cin>>records.id;
    cout<<"\n Nmae: "; cin>>records.name;
    cout<<"\n salary; "; cin>>records.salary;
    cout<<"\n desg: "; cin>>records.desg;
    seqfile.write((char *)&records,sizeof(records));
    ind_records.id=records.id;
    ind_records.position=pos;
    indfile.write((char *)&ind_records,sizeof(ind_records));
    seqfile.close();
    indfile.close();
}
void emp_class::deleta()
{
    cout<<"\nFor deletion";
    int id,pos;
    cout<<"\n Enter id to be deleted"<<endl;
    cin>>id;
    fstream seqfile;
    fstream indfile;
    indfile.open("ind.dat",ios::in|ios::out|ios::binary);
    seqfile.open("emp.dat",ios::in|ios::out|ios::binary);
    indfile.seekg(0,ios::beg);
    seqfile.seekg(0,ios::beg);
    pos=-1;
    while(indfile.read((char *)&ind_records,sizeof(ind_records)))
    {
        if(id==ind_records.id)
        {
            pos=ind_records.position;
            ind_records.id=-1;
            break;
        }
    }
    if(pos==-1)
    {
        cout<<"\n Record is not present in the file"<<endl;
        return;
    }
    int offset=pos*sizeof(rec);
    seqfile.seekp(offset);
    strcpy(records.name,"NULL");
    records.salary=-1;
    records.id=-1;
    strcpy(records.desg,"NULL");
    seqfile.write((char *)&records,sizeof(records))<<flush;
    int offset1=pos*sizeof(ind_rec);
    indfile.seekp(offset1);
    ind_records.id=-1;
    ind_records.position=pos;
    indfile.write((char *)&ind_records,sizeof(ind_records))<<flush;
    seqfile.seekg(0);
    seqfile.close();
    indfile.close();
    cout<<"\n Record is deleted";
}
void emp_class::search()
{
    fstream seqfile;
    fstream indfile;
    int id,pos,offset;
    cout<<"\n Enter id to be search; "<<endl;
    cin>>id;
    pos=-1;
    indfile.open("ind.dat",ios::in|ios::binary);
    while(indfile.read((char *)&ind_records,sizeof(ind_records)))
    {
        if(id==ind_records.id)
        {
            pos=ind_records.position;
            break;
        }
    }
    offset=pos*sizeof(records);
    seqfile.open("emp.dat",ios::in|ios::binary);
    seqfile.seekg(offset,ios::beg);
    seqfile.read((char *)&records,sizeof(records));
    if(records.id==-1)
    {
        cout<<"\n Data is not present in file"<<endl;
        return;
    }
    else{
        cout<<"\n Dta is present snd it is: "<<endl;
        cout<<"\n\tId\tName\tSalary\tdesg"<<endl;
        cout<<"\n\t"<<records.id<<"\t"<<records.name<<"\t"<<records.salary<<"\t"<<records.desg<<endl;
    }
    seqfile.close();
    indfile.close();
}
int main()
{
    emp_class emp;
    emp.create();
    emp.display();
    emp.append();
    emp.display();
    emp.deleta();
    emp.display();
    emp.search();
    return 0;
}
