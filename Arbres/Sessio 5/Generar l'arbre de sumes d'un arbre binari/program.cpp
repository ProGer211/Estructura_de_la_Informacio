#include "arbreBin.hpp"
#include <iostream>
#include <vector>
using namespace std;

int generararbre(const arbreBin<int> &a)
{
int suma(0);
if(not(a.es_buit()))
{
	if(not(a.fe().es_buit() and a.fd().es_buit()))
	{
	int afe(0),afd(0);
	afe = generararbre(a.fe());
	afd = generararbre(a.fd());
	 = suma;
	}

}
return suma;

}


int main()
{
arbreBin<int> v;
arbreBin<int> ar;
cin >> ar;
generararbre(ar);
cout << ar << endl;
}
