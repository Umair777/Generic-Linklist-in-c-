#include<iostream>
using namespace std;
const int len = 80;
class employee
{
	private : 
		char name[len];
		unsigned long number;
	public:
		friend istream& operator >>(istream& s,employee& e);
		friend ostream& operator <<(ostream& s,employee& e);
};
istream& operator >> (istream& s,employee& e)
{
	cout<<"\n Enter last name :";cin>>e.name;
	cout<<"Enter number :";cin>>e.number;
	return s;
}
ostream& operator << (ostream& s, employee& e)
{
	cout<<"\nName :" <<e.name;
	cout<<"\nNumber :" <<e.number;
	return s;
}
//-----------------------------------------------------
template<class type>
struct link
{
	type data;	//data item
	link* next;	//pointer to next link
};
//-------------------------------------------------------------
template<class type>
class linklist
{
	private:
		link<type>* first;//poiter to first link
	public:
		linklist()
		{first = NULL;}//no argument constructor
		void additem(type d);
		void display();
};
//--------------------------------------------------------------
template<class type>
void linklist<type>::additem(type d)
{
	link<type>* newlink=new link<type>;//new node of any data type 
	newlink->data = d;
	newlink->next=first;	//it point to next link to where it is going to add
	first=newlink;

}
//----------------------------------------------------------------
template<class type>
void linklist<type>::display()
{
	link<type>* current = first;
	while(current !=NULL)
	{
		cout<<endl<<current->data;
		current=current->next;
	}
}
//----------------------------------------------------------------
int main()
{
	linklist<employee> lemp;
	employee emp;
	char resp;
	do
	{
		cin >>emp;
		lemp.additem(emp);
		cout<<"\nadd another( y/n) ? ";
		cin >>resp;
	}while(resp != 'n');
	lemp.display();
	cout<<endl;
	return 0;

}
