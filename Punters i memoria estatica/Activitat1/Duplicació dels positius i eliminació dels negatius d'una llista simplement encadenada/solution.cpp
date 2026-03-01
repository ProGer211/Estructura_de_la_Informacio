#include "llista.hpp"


 void Llista::duplica_positius_elimina_negatius()
 {
 node *p(_prim),*p1ant(nullptr);
 while(p!=nullptr)
 {
 if(p->info > 0)
 {
 node *pnou = new node;
 pnou->info = p->info;
 pnou->seg =p->seg;
 p->seg = pnou;
 p = pnou->seg;
 p1ant = pnou;
 _long++;
 }
 else if(p->info < 0)
 {
 node *elim =p;
 p = p->seg;
 delete elim;
 if(p1ant !=nullptr) p1ant->seg = p;
 else _prim = p;
 _long--;
 }
 else
 { 
 p1ant = p;
 p = p->seg;
 }
 
 
 }
 
 }
