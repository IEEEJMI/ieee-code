#include <iostream>
#include <math.h>

using namespace std;



double Log2( double n )  
{  
    // log(n)/log(2) is log2.  
    return log( n ) / log( 2 );  
}  

int main() 
{

    float A,B;
    cin>>A>>B;
    
    cout<<( pow(2, B- (Log2(A))  ));
    
    
    





    return 0;
    
}