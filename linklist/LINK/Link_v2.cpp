#include <iostream>
#include <string>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>
#include <vector> 
#include <algorithm> 
using namespace std;

class Node
{
	public:
	Node *next;
	int	id;
	
	Node()
	{
		id 		= 0;	
		next 	= NULL;	
	}
	Node(int a)
	{
		id 		= a;	
		next 	= NULL;
	}
};

class List_Link
{
	public:
	Node *head;

	List_Link()
	{
		head = NULL;
	}
	
	void PrintList()
	{
		for( Node *h = head ; h != NULL ; h = h->next )
		{
			cout<<h->id<<" ";
		}
		cout<<endl;
	}	
	
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
		
	void InsertNode(int a,int insert_id) 
	{
		if( !Search(a) )
		{
			bool can_insert = false;
			for( Node *h = head ; h != NULL ; h = h->next )
			{
				//Rear
				if( h->id == insert_id && h->next == NULL ) 
				{
					h->next = new Node(a);
					h->next->next = NULL;
					PrintList();
					can_insert = true;
					break;
				}
				//Normal
				else if( h->id == insert_id )
				{
					Node *n = new Node(a);
					n->next = h->next;
					h->next = n;		
					PrintList();
					can_insert = true;
					break;
				}
			}
			//Header
			if( !can_insert )
			{	
				Node *h = new Node(a);
				h->next = head;
				head = h;				
				can_insert = true;
			}
		}
	}

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
};

int 	a;
int 	insert_id;
int		chioce;
int main() 
{
	List_Link *l = new List_Link();	
	while(true)
	{
		cin>>chioce;
		if(chioce == 1){
			cin>>a>>insert_id;
			l->InsertNode(a,insert_id);		
		}
		else if(chioce == 0)
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
