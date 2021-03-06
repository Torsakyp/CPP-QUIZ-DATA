#include <iostream>
#include <string>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>
#include <algorithm> 
using namespace std;
class Node
{
	public:
	Node *next;
	int	id;
	Node()
	{
		id   = 0;	
		next = NULL;	
	}
	Node(int a)
	{
		id   = a;	
		next = NULL;
	}
};

class List_Link
{
	public:
	Node *head;
//--------------------------------------------------------------------------------------
	List_Link()
	{
		head = NULL;
	}
//--------------------------------------------------------------------------------------
	void PrintList()
	{
		for( Node *h = head ; h != NULL ; h = h->next )
		{
			cout<<h->id<<" ";
		}
		cout<<endl;
	}	
//--------------------------------------------------------------------------------------
	bool Search(int a)
	{
		for( Node *h = head ; h != NULL ; h = h->next )
		{
			if( h->id == a )
			{
				return true;
			}
		}
		return false;	
	}		
//--------------------------------------------------------------------------------------	
	void InsertNode(int a,int insert_id) 
	{
		Node *hh;
		if( !Search(a) )
		{
			bool can_insert = false;
			for( Node *h = head ; h != NULL ; h = h->next )
			{
				//Header
				if( h->id == insert_id && h == head ) 
				{
					Node *n 	= new Node(a);
					n->next 	= head;
					head 		= n;
					PrintList();
					can_insert 	= true;
					break;
				}
				//Normal
				else if( h->next != NULL && h->next->id == insert_id )
				{
					Node *n 	= new Node(a);
					n->next 	= h->next;
					h->next 	= n;		
					PrintList();
					can_insert 	= true;
					break;
				}
				hh = h; 
			}
			//Rear 
			if( !can_insert )
			{	
				if( head == NULL  )
				{
					head 			= new Node(a);
					PrintList();
					can_insert 		= true;		
				}
				else
				{
					hh->next 		= new Node(a);
					hh->next->next 	= NULL;
					PrintList();
					can_insert 		= true;	
				}
			}
		}
	}
//--------------------------------------------------------------------------------------
	void RemoveNode(int a)
	{		
		if (head != NULL)
		{
			for( Node *h = head ; h->next != NULL ; h = h->next )
			{
				//Header
				if(a == h->id)
				{
					head = head->next;				
					PrintList();
					break;
				}
				//Rear
				else if(a == h->next->id && h->next->next == NULL  )
				{
					h->next = NULL;
					PrintList();
					break;
				}
				//Normal
				else if( a == h->next->id )
				{
					h->next = h->next->next;
					PrintList();
					break;
				}
			}
		}
	}	
//--------------------------------------------------------------------------------------	
};
//--------------------------------------------------------------------------------------
int 	a;
int 	insert_id;
string	chioce = "";
int 	main() 
{
	List_Link *l = new List_Link();	
	while(true)
	{
		cin>>chioce;
		if(chioce == "I")
		{
			cin>>a>>insert_id;
			l->InsertNode(a,insert_id);		
		}
		else if(chioce == "D")
		{
			cin>>a;
			l->RemoveNode(a);			
		}
		else
		{
			break;
		}
	}
   	return 0;
}
