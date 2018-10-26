#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /*Input Routine*/
    int t=0;
    cin>>t;
    vector<int> P, k;
    do{
        int t_P, t_k;
        cin>>t_P>>t_k;
        P.push_back(t_P);
        k.push_back(t_k);
        t--;
    } while(t!=0);
        
    int cnt;
    /*Processing*/
    for(int i=0; i<P.size(); i++)
    {
        int fflag = 0;
        for (int j = 2; j < P[i]; ++j)
        {   
            cnt=0;
            int temp = j;

            for (int m = 2; m <= j; ++m)
            {
                
                if(temp%m==0)
                {
                    cnt++;
                    temp/=m;
                    m=1;  
                }
            }

            if (cnt==k[i])
            {
                fflag++;
                cout<<j<<" ";
            }
        } 
        if(fflag==0){
            cout<<"-1";
        }
        cout<<endl;
    }
    
    return 0;
}