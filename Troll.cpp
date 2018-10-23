#include <iostream>
#include <vector>


void changebits(std::vector<int> &v, int flag)
{
	static int i=0;

	if (flag==1)
	{
		v[i]=1;
		i++;
	}
	else
	{
		
		if (!i==0)
			v[i-1]=0;

		v[i]=1;
		i++;

	}





}



int check()
{}




int main(int argc, char const *argv[])
{
	int n;

	std::cin>>n;

	int correctbits=0;

	std::vector<int> bits,last;

	for (int i = 0; i < n; ++i)
	{
		bits.push_back(0);
	}

	int j,k,temp,flag=0;









	for ( ;  ; )
	{
		
		std::cout<<"Q";

		for (j = 0; j < n ; ++j)
		{
			std::cout<<" "<<bits[j];
		}
		std::cout<<"\n";




		temp=correctbits;
		std::cin>>correctbits;




		if (correctbits>=temp)
		{
			flag=1;		
		}
		else
		{
			flag=0;
		}


		if (correctbits==n)
		{
			std::cout<<"A";

			for (j = 0; j < n ; ++j)
			{
				std::cout<<" "<<bits[j];
			}



			break;	
		}


		changebits(bits,flag);

		std::cout.flush();





	}


	return 0;
}