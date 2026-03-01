#include "llista.hpp"
#include <iostream> 

void Llista::fusiona_suma(Llista &l2, nat n)
{
node *p1(_prim),*p2(l2._prim);
node *pant(nullptr);
int i = 0;
int j = 0;
int total = 0;
while(p2 !=nullptr or p1 !=nullptr)
{
	if(p1 == nullptr)
	{
	 node *pnou = new node;
	 pnou->info = p2->info;
	 total = total + p2->info;
	 pnou->ant =pant;
	 if(pant !=nullptr) pant->seg = pnou;
	 else if(p1 == nullptr and pant == nullptr) _prim= pnou;
	 if(p1 != nullptr) p1->ant = pnou;
	 pant = pnou;
	 pnou->seg = p1; 
	 _ult = pnou;
	 node *pelim = p2;
	 p2 = p2->seg;
	 l2._prim = p2;
	 _long++;
	 l2._long--;
	 delete pelim;
	}
	else if(p2 == nullptr)
	{	
	 pant = p1;
	 total = total + p1->info;
	 p1 = p1->seg;
	}
	else if(i < n)
	{
	 pant = p1;
	 total = total + p1->info;
	 p1 = p1->seg;
	 if(i<n) i++;
	 if(i == n) j=0;
	}
	else if(j < n)
	{
	 node *pnou = new node;
	 pnou->info = p2->info;
	 total = total + p2->info;
	 pnou->ant = pant;
	 pant->seg = pnou;
	 pnou->seg = p1; 
	 p1->ant = pnou;
	 pant = pnou;
	 node *pelim(p2);
	 p2 = p2->seg;
	 delete pelim;
	 l2._prim = p2;
	 _long++;
	 l2._long--;
	 if(j<n)j++; 
	 if(j == n) i = 0;
	}


}
l2._ult = nullptr;
node *pnou = new node;
pnou->info = total;
pnou->seg = _prim;
if(pant != nullptr)_prim->ant = pnou;
_prim = pnou;
_prim->ant = nullptr;
_long++;


}
