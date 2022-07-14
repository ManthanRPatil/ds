#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
		int data;
		NODE *next;

};
class STACK
{
		private:
			NODE *top;
		public:
			STACK();
			void PUSH(int ele);
			int POP();
			void LIST_ALL();

};
void STACK::STACK()
{
		top=NULL;
}
void STACK::PUSH(int ele)
{
		//create a node
		NODE *NEW =new NODE();
		if(NEW==NULL)
		{
			cout<<"STACK is full";
			return;
		}
		//fill up the data
		NEW->data= ele;
		NEW->next=NULL;
		//set the link
		NEW->next=top;
		top=NEW;

}
int STACK::POP()
{
	if(top==NULL)
	{
		cout<<"stack is empty";
		return NULL;
	}
	else
	{
		int ele=top->data;
		NODE *TEMP=top;
		top=top->next;
		delete TEMP;
		return ele;
	}
}
void STACK:: LIST_ALL()
{
	if(top==NULL)
	{
		cout<<"LIST is empty";
	}
	NODE *ptr;
	ptr=top;
	while(ptr != NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
}
MENU()
{
		STACK obj;
		int opt,ele;
		do
		{
			cout<<"\n 1. ADD";
			cout<<"\n 2. DEL";
			cout<<"\n 3. LIST_ALL";
			cout<<"\n 4.EXIT";
			cout<<"Enter your option";
			cin>>opt;

			switch(opt)
			{
				case 1:
						cout<<"Enter your elemet";
						cin>>ele;
						obj.PUSH(ele);
						break;
				case 2:
					ele=obj.POP();
					if(ele != NULL)
					{
						cout<<ele<<"is deleted";
					}
					break;
				case 3:
					obj.LIST_ALL();
					break;
				case 4:
					return;
				default:
					cout<<"INVALID OPTION";
			}

		}while(1);

}
void main()
{
	clrscr();
	MENU();
	getch();
}
