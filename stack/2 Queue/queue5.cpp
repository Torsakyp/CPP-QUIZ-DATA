#include <iostream>
#include <string>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>
#include <vector> 
#include <algorithm> 
using namespace std;

class Queue
{
	public:
    vector<string> v;
    int size = 0;
    int t_size = 0;
//-------------------------------------------------------------
    void Enqueue(string data)
    {
    	if( t_size < size )
    	{
        	v.push_back(data);
        	t_size++;
        }
    }
//-------------------------------------------------------------
    string Dequeue() 
    {
    	string s = "";
    	if(!v.empty())
    	{
        	s = v.at(0); 
        	cout<<v.at(0)<<endl;
        	v.erase( v.begin() );	          
        }
        return s;
    }
//-------------------------------------------------------------
    void Print()
    {
		if(!v.empty())
    	{    	
			for (int i = 0; i < v.size(); i++)				
			{ 
	 			cout << v[i] << " ";
			}
			cout<<endl;
		}
    }
//-------------------------------------------------------------    
};

int main() 
{
	Queue s;
	string t;
	string t1;
	int size;
	cin>>size;
	s.size = size;
	while(true)
	{
		cin>>t;
		if(t=="e")
		{
			cin>>t1;
			s.Enqueue(t1); 
		}
		else if(t=="d")
		{
			s.Dequeue();
		}
		else if(t=="p")
		{
			s.Print();
		}
		else if(t=="n")
		{
			cout<<s.v.size()<<endl;
		}				
		else if(t=="x")
		{
			break;
		}
	}
  	return 0;
}
