#include <iostream>
using namespace std;

int main()
{
	int t1,t2,x1,x2;
	float t0;
	cin>>t1>>t2>>x1>>x2>>t0;

	float min_diff = t0;
	int y1=0, y2=0;

	for (int i1 = 1; i1 <= x1 ; i1++)
	{
		for (int i2 = 1; i2 <= x2; i2++)
		{
			float t = (float)(((t1*i1)+(t2*i2))/(i1+i2));
			float diff = (t - t0);
			if(diff < 0) continue;
			if(diff < min_diff) {
				min_diff = diff;
				cout<<min_diff<<endl;
				if((i1+i2)>(y1+y2)) {
					y1 = i1;
					y2 = i2;
				}
			}
		}
	}
	cout<<y1<<" "<<y2<<endl;
	return 0;
}