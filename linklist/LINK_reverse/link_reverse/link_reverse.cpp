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
	Node 	*next;
	int		id;
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
		Node *hh;
		if(!Search(a)){
			bool can_insert = false;
			for(Node*h=head ; h!=NULL ; h=h->next){
				if(h->id==insert_id && h==head){
					Node*n=new Node(a);
					n->next = head;
					head = n;
					PrintList();
					can_insert=true;
					break;
				}
				else if(h->next!=NULL && h->next->id==insert_id){
					Node*n=new Node(a);
					n->next=h->next;
					h->next = n;
					PrintList();
					can_insert = true;
					break;
				}
				hh=h;
			}
			if(!can_insert){
				if(head==NULL){
					head = new Node(a);
					PrintList();
					can_insert = true;
				}
				else{
					hh->next = new Node(a);
					hh->next->next = NULL;
					PrintList();
					can_insert = true;					
				}
			}				
		}
	}
	void RemoveNode(int a)
	{		
		if(head!=NULL){
			for(Node*h=head ; h->next!=NULL ; h=h->next){
				if(a==h->id){
					head = head->next;
					PrintList();
					break;
				}
				else if(a==h->next->id && h->next->next==NULL){
					h->next = NULL ;
					PrintList();
					break;
				}
				else if(a==h->next->id){
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
string	ch = "";

int main() 
{
	List_Link *l = new List_Link();	
	while(true)
	{
		cin >> ch;
		if(ch=="I"){
			cin >> a >> insert_id;
			l->InsertNode(a,insert_id);
		}
		else if(ch=="D"){
			cin >> a;
			l->RemoveNode(a);
		}
		else if(ch=="E"){
			break;
		}
	}
   	return 0;
}
