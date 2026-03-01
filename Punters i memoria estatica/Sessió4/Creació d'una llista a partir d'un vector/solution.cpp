#include "llista.hpp"


// Pre: True
// Post: El p.i. conté els elements de v amb el mateix ordre.
Llista::Llista(const vector<int> &v)
{
node *p1ant(nullptr);
_long = v.size();
	for(int i=0;i<_long;i++)
	{
	node *pnou = new node;
	pnou->info = v[i];
		if(p1ant == nullptr)_prim = pnou;	
		else p1ant->seg = pnou;			
		p1ant = pnou;
	}
if(_long == 0) _prim = nullptr;
else p1ant->seg = nullptr;
 
}
