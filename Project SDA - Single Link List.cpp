#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Node
{
public:
    int info;
    Node* next;
};
class List:public Node
{
 
    Node *first,*last;
public:
    List()
    {
        first=NULL;
        last=NULL;
    }
    void buat();
    void tambah();
    void hapus();
    void tampilkan();
    void cari();
};
void List::buat()
{
    Node *temp;
    temp=new Node;
    int n;
    cout<<"\nMasukkan Data Pertama:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=first;
    }
 
    else
    {
        last->next=temp;
        last=temp;
    }
}
void List::tambah()
{
    Node *prev,*cur;
    prev=NULL;
    cur=first;
    int count=1,pos,pilih,n;
    Node *temp=new Node;
    cout<<"\nMasukkan data:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    cout<<"\nData disimpan sebagai\n1:Urutan Pertama\n2:Urutan Terakhir\n3:Antara Awal dan Akhir";
    cout<<"\nMasukkan pilihan anda:";
    cin>>pilih;
    switch(pilih)
    {
    case 1:
        temp->next=first;
        first=temp;
        break;
    case 2:
        last->next=temp;
        last=temp;
        break;
    case 3:
        cout<<"\nMasukkan posisi yang ingin dimasukkan:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            prev->next=temp;
            temp->next=cur;
        }
        else
            cout<<"\nData tidak dapat diinput";
        break;
 
    }
}
void List::hapus()
{
    Node *prev=NULL,*cur=first;
    int count=1,pos,ch;
    cout<<"\nHapus\n1:Urutan Pertama\n2:Urutan Terakhir\n3:Antara Awal dan Akhir";
    cout<<"\nMasukkan pilihan anda:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        if(first!=NULL)
        {
            cout<<"\nData yang dihapus adalah "<<first->info;
            first=first->next;
        }
        else
            cout<<"\nData tidak dapat dihapus";
        break;
    case 2:
        while(cur!=last)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==last)
        {
            cout<<"\nData yang dihapus adalah: "<<cur->info;
            prev->next=NULL;
            last=prev;
        }
        else
            cout<<"\nData tidak dapat dihapus";
        break;
    case 3:
        cout<<"\nMasukkan posisi yang ingin dihapus:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            cout<<"\nData yang dihapus adalah: "<<cur->info;
            prev->next=cur->next;
        }
        else
            cout<<"\nData tidak dapat dihapus";
        break;
    }
}
void List::tampilkan()
{
    Node *temp=first;
    if(temp==NULL)
    {
        cout<<"\nList kosong\n";
    }
    while(temp!=NULL)
    {
        cout<<temp->info;
        cout<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}
void List::cari()
{
    int value,pos=0;
    bool flag=false;
    if(first==NULL)
    {
        cout<<"\nList masih kosong\n";
        return;
    }
    cout<<"Masukkan Data yang ingin dicari:";
    cin>>value;
    Node *temp;
    temp=first;
    while(temp!=NULL)
    {
        pos++;
        if(temp->info==value)
        {
            flag=true;
            cout<<"\nData "<<value<<" terletak diposisi ke "<<pos;
            return;
        }
        temp=temp->next;
    }
    if(!flag)
    {
        cout<<"\nData "<<value<<" tidak ditemukan di list\n";
    }
}
int main()
{
    List l;
    int pilihan;
    while(1)
    {
        cout<<"\n**** Single Link List ****";
        cout<<"\n1:Buat List\n2:Tambahkan Data Baru\n3:Hapus Data\n4:Cari Data\n5:Tampilkan List\n6:Keluar\n";
        cout<<"Masukkan pilihan anda:";
        cin>>pilihan;
        switch(pilihan)
        {
        case 1:
            l.buat();
            break;
        case 2:
            l.tambah();
            break;
        case 3:
            l.hapus();
            break;
        case 4:
            l.cari();
            break;
        case 5:
        	l.tampilkan();
        	break;
        case 6:
            return 0;
        }
    }
    return 0;
}
