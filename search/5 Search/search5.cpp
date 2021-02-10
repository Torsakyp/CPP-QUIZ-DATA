#include<iostream>
#include<string>
#include<stdlib.h> 
#include<stdio.h> 
#include<math.h>
#include<vector> 
#include<algorithm> 
using namespace std;
vector <int>v;

void sort()
{
    for(int i=0 ; i < v.size() ; i++)
    {
        for (int j = i ; j < v.size()  ; j++)
        {       
            if( v[i] > v[j] )
            {
                int t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
        }
    }	
}

int meet_value = 0;
void binary_search(int value,int left,int right)
{
	int mid = (right + left) / 2;
	
	if( v[mid] == value )
	{
		cout<<mid<<" ";
		meet_value = 1;
		return;
	}		
	else  if( (right - left) == 1 )  
	{
		if( v[left] ==  value)
		{
			cout<<left<<" ";
			meet_value = 1;
		}	
		if( v[right] ==  value )
		{
			cout<<right<<" ";
			meet_value = 1;
		}
		return;
	}
	else if( v[mid] < value )
	{
		cout<<mid<<" ";
		binary_search(value,mid,right);
	}
	else if( v[mid] > value )
	{
		cout<<mid<<" ";
		binary_search(value,left,mid);
	}
}

void bs(int value)
{
	if( !v.empty() )
	{
		sort();
		meet_value = 0;
		int min = 0;
		int max = v.size()-1;
		binary_search( value, min, max );	
		if(meet_value == 1)
		{
			cout<<"Y"<<endl;
		}
		else
		{
			cout<<"N"<<endl;		
		}
	}
}

int main() 
{
	string s;
	int    n;
	while(true)
	{
		cin>>s;
		if(s == "e")
		{
			break;
		}
		else if(s == "s")
		{
			cin>>n;		
			bs(n);			
		}
		/*else if(s == "a"){
			cout << v.size();
		}*/
		else
		{
			const char * c = s.c_str();
			int t = atoi(c);
			v.push_back(t);
		}
	}
  	return 0;
}

