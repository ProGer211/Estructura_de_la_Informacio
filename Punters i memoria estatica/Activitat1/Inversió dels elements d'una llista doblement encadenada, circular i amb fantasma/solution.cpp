#include "llista.hpp"


void Llista::inverteix()
{
node *p(_prim->seg),*p1ant(_prim);

while(p != _prim)
{
if(p1ant == _prim) p1ant->ant = p;
node *pc =p;
p = p->seg;
pc->seg = p1ant;
pc->ant = p;
p1ant = pc;
}
_prim->seg =p1ant;

}
