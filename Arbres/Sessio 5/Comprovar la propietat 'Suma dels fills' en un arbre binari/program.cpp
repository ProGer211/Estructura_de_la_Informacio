#include "arbreBin.hpp"
#include <iostream>

using namespace std;
// Pre: true 
// Post: retorna si compleix la propietat 'Suma de fills':
// Per tot node el seu valor és igual a la suma de valors dels nodes
//(arrels) del fill esquerre i del fill dret
bool compleix_suma_fill(const arbreBin<int> &a)
{
 bool asuma(true);
 //CD1. a es buit => true
 //CD2. a.fe() i a.fd() són buits => true
	if(not a.es_buit())   //if(not a.es_buit() and not(a.fe().es_buit() and a.fd.es_buit()))
	{
	if(not (a.fe().es_buit() and a.fd().es_buit()))
	{
	int afe(0),afd(0);
	afe = a.fe().es_buit() ? 0 : a.fe().arrel();// si es buit es 0 i sino es buit el el valor de a.fe().arrel()
	afd = a.fd().es_buit() ? 0 : a.fd().arrel();
	//if(not a.fe().es_buit()) afe = a.fe().arrel(); // puede pasar que el fd es buit y el fe no es buit.
	//if(not a.fd().es_buit()) afd = a.fd().arrel();
	asuma = a.arrel() == afe + afd and 
		compleix_suma_fill(a.fe()) and 
		compleix_suma_fill(a.fd());//Preordre es primer es veu l'arrel i després els fills , es millor preordre 
		
		// compleix_suma_fills(a.fd())) and 
		//compleix_suma_fills(a.fe()) and 
		// asuma = a.arrel() == afe + afd  // Postordre?
		
		//  compleix_suma_fills(a.fe())  and 
		// suma = a.arrel() == afe + afd  and 
		//compleix_suma_fills(a.fd())) // Inordre?
	 // per fer-ho iteratiu s'ha de fer amb una pila auxiliar stack<arbreBin<int> > p; amb l'espai > > sino no compila
	}	
	
	}	
return asuma;
}
int main()
{
arbreBin<int> ar;
cin >> ar;
cout << ar << endl;

if(compleix_suma_fill(ar))
	cout << "L'arbre compleix la propietat 'Suma dels fills'." << endl;
else
	cout << "L'arbre no compleix la propietat 'Suma dels fills'." << endl;
}
