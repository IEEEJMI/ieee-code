#include <iostream>

using namespace std;

int main()
{
	int t1,t2,x1,x2,y1,y2,t0;
	cin>>t1>>t2>>x1>>x2>>t0;

	int i1,i2;
	int t;

	int closest=t0;

	for (i1 = 1; i1 < x1 ; ++i1)
	{
		for (i2 = 1; i2 < x2; ++i2)
		{
			
			t=((t1*i1)+(t2*i2))/(i1+i2);
			

			if(t0==t)
			{
				cout<<i1<<" "<<i2<<endl;
				return 0;
			} 


			if (t0-closest>t0-t)
			{
				closest=t;

			}


		}
	}

	cout<<closest;





	return 0;
}