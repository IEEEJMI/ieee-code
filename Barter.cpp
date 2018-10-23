#include <iostream>


struct pairs
{
	std::string A,B;
	int rate;
};


int main(int argc, char const *argv[])
{


	int n;
	std::cin>>n;

	pairs data[20000];


	for (int i = 0; i < n; ++i)
	{
		std::cin>> data[i].A >> data[i].B >> data[i].rate;
	}
	
	int q;
	pairs query[20000];
	std::cin>>q;

	for ( i = 0; i < q; ++i)
	{
		std::cin>> query[i].A >> query[i].B ;	
	}


	

















	}



	return 0;
}