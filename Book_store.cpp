#include<iostream>
#include<cstdlib>
using namespace std;
class Book_node
{
    string NameOfBook;
    string author;
    unsigned int NumOfCopies;
    unsigned int cost;
    Book_node* next;
    Book_node():NameOfBook(NULL),NumOfCopies(0),cost(0),next(NULL){}
    Book_node(string a,string d,unsigned int b,unsigned int c):NameOfBook(a),author(d),NumOfCopies(b),cost(c),next(NULL){}
    Book_node(string a,unsigned int b,unsigned int c,Book_node* d):NameOfBook(a),NumOfCopies(b),cost(c),next(d){}
    friend class Book;
};
class Book
{
    public:
    Book(){head=NULL;}
    ~Book();
    void add_book(string name,string author,unsigned int copies,unsigned int cost);
    void printlist();
    bool search_book(string name);
    bool check_copies_requested(unsigned int size,string name);
    unsigned int return_copies(string name);
    unsigned int amount_to_be_process(string name,unsigned int size);
    bool check_empty();
    private:
    Book_node* head;
    void remove();
    
};
void Book::add_book(string name,string author,unsigned int a,unsigned int b)
{
    Book_node* new_book=new Book_node(name,author,a,b);
    new_book->next=head;
    head=new_book;
}
void Book::printlist()
{
    Book_node* n=head;
    cout<<"Name of Book |  Author  |  Copies  |  cost per each"<<endl;
    cout<<"_____________|__________|_______________"<<endl;
    while(n!=NULL)
    {
        cout<<n->NameOfBook<<"  |  "<<n->author<<"  |  "<<n->NumOfCopies<<"  |  "<<n->cost<<endl;
        n=n->next;
    }
}
bool Book::search_book(string name)
{
    Book_node* n=head;
    while(n!=NULL)
    {
        if(n->NameOfBook==name)
        {
            return true;
        }
    }
    return false;
}
bool Book::check_copies_requested(unsigned int size,string name)
{
    Book_node* n=head;
    while(n!=NULL)
    {
        if(n->NameOfBook==name)
        {
            if(n->NumOfCopies<size){return false;}
            else
            {
                n->NumOfCopies=n->NumOfCopies-size;
                return true;
            }
        }
        n=n->next;
    }
    return false;//just a glitch//compiler  ws not accepting
}
unsigned int Book::return_copies(string name)
{
    Book_node* n=head;
    while(n!=NULL)
    {
        if(n->NameOfBook==name)
        {
            return n->NumOfCopies;
        }
        n=n->next;
    }
    return 0;
}
unsigned int Book::amount_to_be_process(string name,unsigned int size)
{
    Book_node* n=head;
    while(n!=NULL)
    {
        if(n->NameOfBook==name)
        {
            unsigned int amt=(n->cost)*size;
            return amt;
        }
    }
    return 0;
}
void Book::remove()
{
    Book_node* n=head;
    head=head->next;
    delete n;
    n=NULL;
}
bool Book::check_empty()
{
    if(head==NULL)
    {
        return true;
    }
    return false;
}
Book::~Book()
{
    while(!check_empty())
    {
        remove();
    }
}
int main()
{
    Book b1;
    cout<<"choose from menu:"<<endl;
    cout<<"1.) To add a book, no.of copies, cost of each book."<<endl;
    cout<<"2.) Search for book and copies."<<endl;
    cout<<"3.) Choose to print all books"<<endl;
    cout<<"4.) exit"<<endl;
    cout<<"\n\n\n";
    string nameofBOOk;
    string author;
    unsigned int copies;
    unsigned int cost;
    int ch;
    cout<<"Enter Choice:";cin>>ch;
    cin.ignore();
    system("cls");
    while(ch==1 || ch==2 || ch==3 )
    {
        int i=0;
        unsigned int size;
        if(ch==1)
        {
            i++;
            cout<<"Adding Book "<<i<<endl;
            cout<<"Enter name of Book: ";getline(cin,nameofBOOk);
            cout<<"Enter name of author of the book: ";getline(cin,author);
            cout<<"Enter no. of copies: ";cin>>copies;
            cout<<"Enter cost of each book: ";cin>>cost;
            b1.add_book(nameofBOOk,author,copies,cost);
            cout<<"Book Added!!"<<endl;
        }
        if(ch==2)
        {
            string name;
            cout<<"Search name of the book:";
            getline(cin,name);
            if(b1.search_book(name)==true)
            {
                cout<<"\nBook existed and now enter copies: ";
                cin>>size;
                if(b1.check_copies_requested(size,name)==true)
                {
                    cout<<"copies existed printing payment."<<endl;
                    ch=6;
                }
                else
                {
                    cout<<"Number of copies is less than you require, No. of copies left: "<<b1.return_copies(name)<<endl;
                }
            }
            else
            {
                cout<<"Book name not registered and go for menu or search a registered book"<<endl;
            }
        }
        if(ch==6)
        {
            cout<<"copies requested are "<<size;
            unsigned int amount=b1.amount_to_be_process(nameofBOOk,size);
            cout<<"Amount to be paid is Rs."<<amount;
        }
        if(ch==3)
        {
            if(b1.check_empty()==true)
            {
                cout<<"No books added"<<endl;
            }
            else
            {
                b1.printlist();
            }
        }
        cout<<"\n\n\n";
        cout<<"choose from menu:"<<endl;
        cout<<"1.) To add a book, no.of copies, cost of each book."<<endl;
        cout<<"2.) Search for book and copies."<<endl;
        cout<<"3.) Choose to print all books"<<endl;
        cout<<"4.)exit"<<endl;
        cout<<"\n\n\n";
        cout<<"Enter choice: ";
        cin>>ch;
        system("cls");
        cin.ignore();
    }
    return 0;
}