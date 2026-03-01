#include "llista.hpp"

Llista::Llista(const vector<int> &v)
{
_prim = new node;
_prim->seg = nullptr;
node *p1ant(_prim);
_long = v.size();
	for(int i=0;i<_long;i++)
	{
	node *pnou = new node;
	pnou->info = v[i];			
	p1ant->seg = pnou;			
	p1ant = pnou;
	}
p1ant->seg = nullptr;
 


}
