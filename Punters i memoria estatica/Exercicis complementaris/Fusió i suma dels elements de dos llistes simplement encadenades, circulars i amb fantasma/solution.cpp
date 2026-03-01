#include "llista.hpp"
#include <iostream> 

void Llista::fusiona_suma(Llista &l2, nat n)
{
node *p1(_prim->seg),*p2(l2._prim->seg);
node *pant(_prim);
int i = 0;
int j = 0;
int total = 0;
while(p2 != l2._prim or p1 != _prim)
{
	if(p1 == _prim)
	{
	 node *pnou = new node;
	 pnou->info = p2->info;
	 total = total + p2->info;
	 pant->seg = pnou;
	 pant= pnou;
	 pnou->seg = p1; 
	 node *pelim = p2;
	 p2 = p2->seg;
	 _long++;
	 l2._long--;
	 delete pelim;
	 l2._prim->seg =p2;
	}
	else if(p2 == l2._prim)
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
	 pant->seg = pnou;
	 pnou->seg = p1; 
	 pant = pnou;
	 node *pelim(p2);
	 p2 = p2->seg;
	 delete pelim;
	 l2._prim->seg =p2;
	 _long++;
	 l2._long--;
	 if(j<n)j++; 
	 if(j == n) i = 0;
	}


}
node *pposterior(_prim->seg);
node *pnou = new node;
pnou->info = total;
pnou->seg = pposterior;
_prim->seg = pnou;
_long++;



}
