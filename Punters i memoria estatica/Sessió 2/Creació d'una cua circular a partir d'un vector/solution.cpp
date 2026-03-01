#include "cua.hpp"
// Pre: True
// Post: El p.i. conté els elements de v amb el mateix ordre.

   cua::cua(const vector<int> &v):_long(v.size()){
    node *pant(nullptr),*pprimer;
    for(unsigned int i = 0;i<_long;i++){
    node *pnou = new  node;
    pnou->info = v[i];
    if(pant == nullptr)
    	pprimer = pnou;
    else
    	pant->seg = pnou;
    pant = pnou;    
    }
    if(pant !=nullptr)
    	pant->seg = pprimer;
    _ult = pant;
    
    }

   
