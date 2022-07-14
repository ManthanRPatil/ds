#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
		NODE *next;
		int data;
};
class LIST_70
{
	private:
		NODE *start;
		NODE *end;
	public:
		LIST_70();
		void ADD_FIRST(int);
		void ADD_LAST(int);
		void LIST_ALL();
};
LIST_70::LIST_70()
{
	start=NULL;
}
void LIST_70::ADD_FIRST(int ele)
{
	NODE *NEW=new NODE();
	if(NEW==NULL)
	{
		cout<<"LIST is full";
	}
	else{
		NEW ->data=ele;
		NEW ->next=NULL;
		NEW ->next=start;
		start=NEW;
	}
	if(start==NULL)
	{
		start=NEW;
		NEW->next=NEW;
	}
	else{
		NEW->next=start;
		start=NEW;
		end->next=start;
	}
}
void LIST_70::ADD_LAST(int ele)
{
	NODE *NEW=new NODE();
	if(NEW==NULL)
	{
		cout<<"LIST is full";
	}
	else{
		NEW ->data=ele;
		NEW ->next=NULL;
		NEW ->next=start;
		start=NEW;
	}
	if(start==NULL)
	{
		start=NEW;
		NEW->next=start;
	}
	end ->next=NEW;
	NEW ->next=start;
}
void LIST_70::LIST_ALL()
{
	if(start==NULL)
	{
		cout<<"LIST is empty";
	}
	NODE *ptr;
	ptr=start;
	do{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
	  }
	  while(ptr!=start);
}
void MENU()
{
	int ele,opt;
	LIST_70 obj;
	do
	{
		cout<<"1.ADD_FIRST \n";
		cout<<"2.ADD_LAST \n";
		cout<<"3.LIST_ALL \n";
		cout<<"4.EXIT \n";
		cout<<"Enter your option: ";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"Enter element add to be First: ";
				cin>>ele;
				obj.ADD_FIRST(ele);
				break;
			case 2:
				cout<<"Enter element add to be Last: ";
				cin>>ele;
				obj.ADD_LAST(ele);
				break;
			case 3:
				obj.LIST_ALL();
			case 4:
				return;
			default:
				cout<<"INVALID OPTION"<<endl;
		}
	}while(1);
}
void main()
{
	clrscr();
	MENU();
	getch();
}
