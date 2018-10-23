#include<iostream>
#include <vector>
#include<algorithm>
#include <iterator>


class star
{
	int S,F,D;
	int next;

public:
	
	star()
	: S(0),F(0),D(0),next(0) {}	

	star(int a, int b, int c)
	: S(a),F(b),D(c), next(0) {}


	int getS()
	{
		return S;
	} 
	int getF()
	{
		return F;
	} 
	int getD()
	{
		return D;
	} 
	int getnext()
	{
		return next;
	}	
	void addnext()
	{
		next++;
	}
	


};


bool operator<(star L, star R) 
{ 
   	return (L.getS() < R.getS());
}




void showstar(std::vector<star> v)
{

	for (int i = 0; i<v.size(); ++i)
	{
		std::cout<<"S "<<v[i].getS()<<" F "<<v[i].getF()<<" D "<<v[i].getD()<<" Next - "<<v[i].getnext()<<std::endl;
	}

}


int getmaxd(std::vector<star> v)
{
	int max;
	int temp,pos;
	pos=0;
	max=v[0].getD();
	int sumall=0;
	
	//showstar(v);


	for (int i = 0; i < v.size(); ++i)
	{
		temp=v[i].getD();
		sumall+=temp;
		
		if (temp>max)
		{
			max=temp;
			pos=i;
		}	

	}

	if (max>(sumall-max))
	{
		//std::cout<<"if return MAX -"<<max;
		return max;
	}

	int newmax=0;

	for (int i = 0; i < v.size()-1; ++i)
	{
		if(i==pos)
			continue ;
		newmax+=v[i].getD();
		for (int j = i; j< v.size(); ++j)
		{
			if(j==pos)
				continue ;

			if (v[i].getF()<v[j].getS())
				newmax+=v[j].getD();



		}

	}


	//std::cout<<"if return NEWMAX -"<<newmax;

	if(newmax>max)
		return newmax;
	else return max;





}


int main()
{
	int n,i;
	std::cin>>n;
	int s,f,d;
	

	std::vector<star> arr;

	for ( i = 0; i < n; ++i)
	{
		std::cin>>s>>f>>d;
		star temp(s,f,d);
		arr.push_back(temp);
	}

	std::sort(arr.begin(),arr.end());
	//std::reverse(arr.begin(),arr.end());


	int sum=0,cnt=0;
	bool flag1;

    int p,q;

	for ( p = 0; p < arr.size()-1; p=q )
	{	
		for (q = p+1;(arr[p].getF()>=arr[q].getS() ) && q<arr.size(); q++)
		{	
			arr[p].addnext();
		}	


	}


	//showstar(arr);

	int maxD,temp;

	bool flag;


	std::vector<star> soln;


	int j,pos;

	for (i = 0; i < arr.size() ; i++)
	{
		std::vector<star> temp1;
		

		if(arr[i].getnext()==0)
		{
			sum+=arr[i].getD();	
		}		
		else
		{
			for (j = 0; j < arr[i].getnext()+1; ++j)
			{
				temp1.push_back(arr[i+j]);	
			}

			sum+=getmaxd(temp1);
			i+=arr[i].getnext();
		}




	}

	std::cout<<sum;




















	return 0;
}