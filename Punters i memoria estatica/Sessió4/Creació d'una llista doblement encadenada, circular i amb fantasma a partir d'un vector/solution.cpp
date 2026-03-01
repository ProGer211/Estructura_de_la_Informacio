 #include "llista.hpp"


Llista::Llista(const vector<int> &v)
{
  _prim = new node;
  _prim->seg = _prim;
  _prim->ant = _prim;
  _long = v.size();
  node *pp1(_prim);
  for(int i = 0;i<_long;i++)
  {  
  node *pnou = new node;
  pnou->info = v[i];
  pnou->ant = pp1;
  pnou->seg = _prim;
  _prim->ant = pnou;
  pp1->seg = pnou;
  pp1 = pnou;   
  }

}

/*Llista::Llista(const vector<int> &v) : _long(v.size()){
_prim = new node;
  _prim->seg = _prim;
  _prim->ant = _prim;
   node *pp1(_prim);
  for(int i = 0;i<v.size();i++)
  {  
  node *pnou = new node;
  pnou->info = v[i];
  pp1->seg = pnou;
  pnou->ant = pp1;
  pnou->seg = _prim;
  _prim->ant = pnou;
  pp1 = pnou;   
  }
 //es pot fer el circular fora del bucle
 //pnou->seg = _prim;
  //_prim->ant = pnou;
}

*/

