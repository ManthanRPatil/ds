#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
		int data;
		NODE *next;
};
class LIST
{
		public:
			NODE *start,*next;
		public:
			LIST();
			void ADD_FIRST(int ele);
			int DEL_FIRST();
			void ADD_END(int ele);
			int DEL_END();
			void ADD_POS(int ele,int pos);
			int DEL_POS(int pos);
			void LIST_ALL();

};
void LIST::LIST()
{
		start=NULL;
}
void LIST::ADD_FIRST(int ele)
{
		//create a node
		NODE *NEW =new NODE();
		if(NEW==NULL)
		{
			cout<<"LIST is full";
			return;
		}
		//fill up the data
		NEW->data= ele;
		NEW->next=NULL;
		//set the link
		NEW->next=start;
		start=NEW;

}
int LIST::DEL_FIRST()
{
	if(start==NULL)
	{
		cout<<"LIST is empty";
		return NULL;
	}
	else
	{
		int ele=start->data;
		NODE *TEMP=start;
		start=start->next;
		delete TEMP;
		return ele;
	}
}
void LIST::ADD_END(int ele)
{
		//create a node
		NODE *NEW =new NODE();
		if(NEW==NULL)
		{
			cout<<"LIST is full";
			return;
		}
		//fill up the data
		NEW->data= ele;
		NEW->next=NULL;
		//set the link
		NODE *ptr;
		if(start==NULL)
		{
			start=NEW;
		}
		else
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=next;
			}
			ptr->next=NEW;

}
int LIST::DEL_END()
{
	if(start==NULL)
	{
		cout<<"LIST is empty";
		return NULL;
	}
	NODE *ptr1=start;
	NODE *ptr=NULL;
	while(ptr1->next!=NULL)
	{
		NODE *ptr2=ptr1;
		NODE *ptr1=ptr1->next;
	}
	int ele=ptr1->data;
	NODE *Temp=ptr1;
	NODE *ptr2;
	if(ptr2!=NULL)
		ptr->next=NULL;
	else
	{
		start=NULL;
	}
	delete Temp;
	return ele;
}
void LIST::ADD_POS(int ele,int pos)
{
		//create a node
		NODE *NEW =new NODE();
		if(NEW==NULL)
		{
			cout<<"LIST is full";
			return;
		}
		//fill up the data
		NEW->data= ele;
		NEW->next=NULL;
		//Assuming given 'pos' in valid
		int count;
		if(pos==1)
		{
			NEW ->next=start;
			start=NEW;
		}
		else
		{
			NODE *ptr1=start;
			NODE *ptr2=NULL;
			count=1;
			while(count<pos)
			{
				ptr2=ptr1;
				ptr1=ptr1->next;
				count=count+1;
			}
			NEW ->next=ptr1;
			ptr2->next=NEW;
		}
}
int LIST::DEL_POS(int pos)
{
	if(start==NULL)
	{
		cout<<"LIST is empty";
		return NULL;
	}
	//search a node
	if(pos==1)
	{
		int ele=start->data;
		NODE *Temp=start;
		start=start->next;
	}
	else
	{
		NODE *ptr1=start;
		NODE *ptr2=NULL;
		int count=1;
		while(count<pos)
		{
			ptr2=ptr1;
			ptr1=ptr1->next;
			count=count+1;
		}
		int ele=ptr1->data;
		NODE *Temp=ptr1;
		ptr2->next=ptr1->next;
	}
	delete Temp;
	return ele;
}

void LIST:: LIST_ALL()
{
	if(start==NULL)
	{
		cout<<"LIST is empty";
	}
	NODE *ptr;
	ptr=start;
	while(ptr != NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
}
void MENU()
{
		LIST obj;
		int opt,ele,pos;
		do
		{
			cout<<"\n 1. ADD_FIRST";
			cout<<"\n 2. DEL_FIRST";
			cout<<"\n 3. ADD_END";
			cout<<"\n 4. DEL_END";
			cout<<"\n 5. ADD_POS";
			cout<<"\n 6. DEL_POS";
			cout<<"\n 7. LIST_ALL";
			cout<<"\n 8.EXIT";
			cout<<"\n Enter your option: ";
			cin>>opt;

			switch(opt)
			{
				case 1:
					cout<<"Enter your elemet: ";
					cin>>ele;
					obj.ADD_FIRST(ele);
					break;
				case 2:
					ele=obj.DEL_FIRST();
					if(ele != NULL)
					{
						cout<<ele<<"is deleted";
					}
					break;
				case 3:
					cout<<"Enter your elemet: ";
					cin>>ele;
					obj.ADD_END(ele);
					break;
				case 4:
					ele=obj.DEL_END();
					if(ele != NULL)
					{
						cout<<ele<<"is deleted";
					}
					break;
				case 5:
					cout<<"Enter your elemet: ";
					cin>>ele;
					cout<<"Enter your elemet: ";
					cin>>pos;
					obj.ADD_POS(ele,pos);
					break;
				case 6:
					cout<<"Enter your elemet: ";
					cin>>pos;
					ele=obj.DEL_POS(pos);
					if(ele != NULL)
					{
						cout<<ele<<"is deleted";
					}
					break;
				case 7:
					obj.LIST_ALL();
					break;
				case 8:
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

