#include "llista.hpp"

// Pre: l2 és buida
     // Post: S’han separat els elements del p.i., quedant al p.i. els elements
     // de les posicions senars i a l2 els de les posicions parells.
     // Exemple: [2 5 3 8 1] quedaria [2 3 1] i l2 = [5 8]
void Llista::separa(Llista &l2)
{
node *p(_prim), *p2ant(nullptr); //p2ant es p2;
while(p!=nullptr)
{
	node *pseg(p->seg);
	if(pseg !=nullptr)
	{
		p->seg = pseg->seg;
		if(p2ant ==nullptr) l2._prim = pseg;
		else p2ant->seg = pseg;
		p2ant = pseg;
		//_long--;
		//l2._long++;
	}
	p = p->seg;
}
if(p2ant !=nullptr) p2ant->seg = nullptr; // (_long !=nullptr) //posar NULL es la constant 0
l2._long = _long/2;
_long = _long -l2._long;
}
