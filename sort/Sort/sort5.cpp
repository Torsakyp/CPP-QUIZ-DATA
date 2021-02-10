#include<iostream>
#include<string>
#include<stdlib.h> 
#include<stdio.h> 
#include<math.h>
#include<vector> 
#include<algorithm> 
using namespace std;

int main() 
{	
	vector<int> v;
	string s;
	while(true)
	{
		cin>>s;
		if(s == "e")
		{
		    for (int i = 0 ; i < v.size()  ; i++)
		    {
		        for (int j = 0 ; j < (v.size() - i) - 1 ; j++)
		        {       
		            if(v[j] < v[j+1])
		            {
		                int t = v[j+1];
		                v[j+1] = v[j];
		                v[j] = t;
		            }
		        }
				for(int i = 0 ; i < v.size() ; i++) 
				{
					cout<<v[i]<<" ";
				}	    
				cout<<endl;
		    }        
			break;
		}	
		else 
		{
			const char * c = s.c_str();
			int t = atoi(c);
			v.push_back(t);
		}
	}
  	return 0;
}
