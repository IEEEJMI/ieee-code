#include <iostream>
#include <string>
#include <vector>
using namespace std;






bool checkbraces(string s)
{
	int cnt1=0,cnt2=0;



	for (int i = 0; i < s.size() ; ++i)
	{
		
		if (s[i]=='(')
		{
			cnt1++;
		}
		else if (s[i]==')')
		{
			cnt1--;
		}
		else if (s[i]=='[')
		{
			cnt2++;
		}
		else if (s[i]==']')
		{
			cnt2--;
		}

		if (cnt1<0|| cnt2<0)
		{
			return false;
		}


	}

	if (cnt1==cnt2)
		return true ;
	else return false ;



}





int main() 
{
    string s;
    vector<char> s1,s2;
    cin>>s;

   	int len=s.size();

    bool flag;

    flag=checkbraces(s);

    if(!flag)
    {
    	cout<<"impossible";
    	return 0;
    }


    char type1,type2;
    int cnt1,cnt2;






    for (int i = 0; i < s.size(); i++)	
    {
    	if(s[i]=='(' )
    	{
    		s1.push_back(s[i]);
    		cnt1++;
    		cout<<1<<" ";	
    	}
    	else if ( s[i]=='[')
    	{
    		s1.push_back(s[i]);
    		cnt1++;
    		cout<<1<<" ";	
    	}

    	if(s[i-1]=='[' && s[i]==']')
    	{
    		s1.push_back(s[i]);
    		cnt1++;
    		cout<<1<<" ";
    	}	

    	if(s[i-1]=='(' && s[i]==')')
    	{
    		s1.push_back(s[i]);
    		cnt1++;
    		cout<<1<<" ";
    	}



    	if(s[i-1]=='(' && s[i]==']')
    	{
    		int k;	
    		for (k = i-2; s[k] != '['; k--)
    		{
    			cout<<"\b\b \b";
    		}

    		for ( k = i-1; s[k] != '['; k--)
    		{
    			s2.push_back(s1[k]);
    			s1.pop_back();
    			cnt2++;
    			cout<<2<<" ";
    		}


    		s1.push_back(s[i]);
    		cnt1=cnt1 - (i-k);
    		cout<<1<<" " ;

       	}		

       	if(s[i-2]=='[' && s[i]==')')
    	{
    		int k;
    		for (k = i-2; s[k] != '('; k--)
    		{
    			cout<<"\b\b \b" ;
    		}

    		for (k = i-1; s[k] != '('; k--)
    		{
    			s2.push_back(s1[k]);
    			s1.pop_back();
    			cnt2++;
    			cout<<2<<" ";
    		}


    		s1.push_back(s[i]);
    		cnt1=cnt1 - (i-k);
    		cout<<1<<" " ;
       	}		





    }





    // if (cnt1!=cnt2)
    // {
    // 	cout<<"impossible";
    // }









































    return 0;
}