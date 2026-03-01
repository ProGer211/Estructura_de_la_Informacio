#include "llista.hpp"
#include <iostream>
void Llista::inverteix()
{
node *p(_prim->seg),*p1ant(nullptr);
while(p!=nullptr)
{

node *pcopia = p;
p = p->seg;
pcopia->seg = p1ant;
p1ant = pcopia;
}
_prim->seg = p1ant;


}



