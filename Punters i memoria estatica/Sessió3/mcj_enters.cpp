#include "mcj_enters.hpp"

   // Constructora per defecte. Crea un multiconjunt buit.
   mcj_enters::mcj_enters()
   { //: _prim(nullptr),_ult(nullptr),_mida(0)
   _mida = 0;
   _prim = nullptr;
   _ult = nullptr;
   }
 
   // Les tres grans: Constructora per còpia, destructora, operador d’assignació
   mcj_enters::mcj_enters(const mcj_enters &cj)
   {
   _mida = cj._mida;
   node *pcj(cj._prim);
   _prim = nullptr;
   node *pp1(_prim);
   while(pcj != nullptr)
   {
   node *pnou = new node;
   pnou->info = pcj->info;
   if(_prim == nullptr)
   {
    _prim = pnou;
    _ult = pnou;
    pp1 = pnou;
   }
   else
   {
   pp1->seg = pnou;
   _ult = pnou;
   pp1 = pnou;   
   }
   pcj = pcj->seg;   
   }
   }
   mcj_enters::~mcj_enters()
   {
   node *p(_prim);
   while(p != nullptr)
   {
    node *pelim=p;
    p = p->seg;
    delete pelim; //IMPORTANT avanzar primer i destruir despres.
   }
   
   }
   mcj_enters& mcj_enters::operator=(const mcj_enters &cj)
   {
  _mida = cj._mida;
   node *pcj(cj._prim);
   node *pp1(_prim);
   while(pcj != nullptr)
   {
   node *pnou = new node;
   pnou->info = pcj->info;
   if(_prim == nullptr)
   {
    _prim = pnou;
    _ult = pnou;
    pp1 = pnou;
   }
   else
   {
   pp1->seg = pnou;
   _ult = pnou;
   pp1 = pnou;   
   }
   pcj = pcj->seg;   
   }
   
   return *this;
   }
 
   // Insereix l’enter e en el multiconjunt.
   void mcj_enters::insereix(int e)
   {
   node *p(_prim), *pant(nullptr);
   while(p != nullptr and p->info <=e ){ //important el ordre ja que si p es null i posem abans p->info petaria while(p->info >=e and p!=nullptr) petaria si p es null porque mira primero el p->info que la segunda instruccion
   	pant = p;  	
   	p = p->seg;
      	}
      	node *pnou = new node;
      	pnou->info = e;
      	pnou->seg = p;
      	if(pant == nullptr) _prim = pnou;
      	else  pant->seg = pnou;
      	_mida++;
      	if(p == nullptr)_ult = pnou;
   }
 
   // Unió, intersecció i diferència de multiconjunts. Operen modificant el multiconjunt
   // sobre el que s’aplica el mètode, usant el segon multiconjunt com argument.
   // P.e.: a.restar(b)
   // fa que el nou valor d’a sigui A - B, on A i B són els valors originals dels objectes a i b.
   void mcj_enters::unir(const mcj_enters& B)
   {
   node *pp2(B._prim);
   node *pp1(_prim);
   node *pp1ant(nullptr);
   while(pp2 != nullptr)
  {
  	if(pp1 == nullptr)
  	{
  	node *pnou = new node;
    	 pnou->info = pp2->info;
    	 	if(pp1ant == nullptr)
    	 	{
    	 	pnou->seg = pp1;
    	 	pp1ant = pnou;
    	 	_prim = pnou;
    	 	}
    	 	else
    	 	{
    	 	pp1ant->seg = pnou;
    	 	pnou->seg = pp1;
    	 	pp1ant = pnou;
    	 	}
    	 pp2 = pp2->seg;
    	 _mida++;
  	
  	}
   	else if(pp2->info < pp1->info)
   	{
    	 node *pnou = new node;
    	 pnou->info = pp2->info;
    	 	if(pp1ant == nullptr)
    	 	{
    	 	pnou->seg = pp1;
    	 	pp1ant = pnou;
    	 	_prim = pnou;
    	 	}
    	 	else
    	 	{
    	 	pp1ant->seg = pnou;
    	 	pnou->seg = pp1;
    	 	pp1ant = pnou;
    	 	}
    	 pp2 = pp2->seg;
    	 _mida++;
   	}
   	else if(pp2->info > pp1->info)
   	{
   		if(pp1ant == nullptr) {
   		pp1ant = pp1;
   		pp1 = pp1->seg;
   		}
   		else
   		{
	   	pp1 = pp1->seg;
	   	pp1ant = pp1ant->seg; 
   		} 	
   	}
   	else
   	{
   		if(pp1ant == nullptr)
   		{
   		pp1ant = pp1;
   		pp2 = pp2->seg;
    		 pp1 = pp1->seg;
   		}
   		else
   		{
   		pp2 = pp2->seg;
    	 	pp1 = pp1->seg;
    	 	pp1ant = pp1ant->seg;     	
   		}  	 	  	
   	}
  }
  if(pp1 == nullptr) _ult = pp1ant;
   
   
   }
   void mcj_enters::intersectar(const mcj_enters& B)
   {
    node *pp2(B._prim);
   node *pp1(_prim);
   node *pp1ant(nullptr);
   while(pp1 != nullptr)
  {
  	if(pp2 == nullptr)
  	{
  	 node *pelim = pp1;
   	 pp1 = pp1->seg;
   	 delete pelim; 	
   	 _mida--;
   	if(pp1ant != nullptr)pp1ant->seg = pp1;
   	 if(pp1ant == nullptr) _prim = pp1;
  	}
   	else if(pp2->info < pp1->info)
   	{
    	 pp2 = pp2->seg;
   	}
   	else if(pp2->info > pp1->info)
   	{
   	 node *pelim = pp1;
   	 pp1 = pp1->seg;
   	 _mida--;
   	 delete pelim; 	
   	 if(pp1ant != nullptr)pp1ant->seg = pp1;
   	 if(pp1ant == nullptr) _prim = pp1;
   	}
   	else
   	{
        	if(pp1ant == nullptr)
        	{
        	pp1ant = pp1;
        	pp1 = pp1->seg;
        	pp2 = pp2->seg;
        	}
        	else
       	 	{
         	pp2 = pp2->seg;
    	 	pp1 = pp1->seg;
    	 	pp1ant = pp1ant->seg; 
        	}   	 	  	
   	}
  }
  if(pp1 == nullptr)_ult = pp1ant;
   }
   void mcj_enters::restar(const mcj_enters& B)
   {
         node *pp2(B._prim);
   node *pp1(_prim);
   node *pp1ant(nullptr);
   while(pp1 != nullptr and pp2 != nullptr)
  { 	
   	if(pp2->info < pp1->info)
   	{
    	 pp2 = pp2->seg;
   	}
   	else if(pp2->info > pp1->info)
   	{
   	if(pp1ant == nullptr) pp1ant = pp1;
   	else pp1ant = pp1ant->seg;
        pp1 = pp1->seg;
   	}
   	else
   	{
         node *pelim = pp1;
   	 pp1 = pp1->seg;
   	 pp2 = pp2->seg;
   	 delete pelim; 	
   	 _mida--;
   	 if(pp1ant != nullptr)pp1ant->seg = pp1;
   	 if(pp1ant == nullptr) _prim = pp1; 	  	
   	}
  }
  if(pp1 == nullptr)_ult = pp1ant;
   
   }
 
   // Unió, intersecció i diferència de multiconjunts. Operen creant un nou multiconjunt
   // sense modificar el multiconjunt sobre el que s’aplica el mètode. La suma de
   // multiconjunts correspon a la unió, la resta a la diferència i el producte a la intersecció.
   mcj_enters mcj_enters::operator+(const mcj_enters& B) const
   {
  mcj_enters aux = *this;
  aux.unir(B);
  return aux;   
   }
   mcj_enters mcj_enters::operator*(const mcj_enters& B) const
   {
   mcj_enters aux = *this;
  aux.intersectar(B);
  return  aux;
   
   }
   mcj_enters mcj_enters::operator-(const mcj_enters& B) const
   {
   mcj_enters aux = *this;
  aux.restar(B);
  return  aux;
   
   }
 
   // Retorna cert si i només si e pertany al multiconjunt.
   bool mcj_enters::conte(int e) const
   {
   node *pp1(_prim);
   for(int i = 0;i<_mida;i++)
   {
   if(pp1->info == e) return true;
   else pp1 = pp1->seg; 
   }
   return false;
   }
   // Retornen els elements màxim i mínim del multiconjunt, respectivament.
   // El seu comportament no està definit si el multiconjunt és buit.
   int mcj_enters::max() const
   {
   return _ult->info;
   
   }
   int mcj_enters::min() const
   {
   return _prim->info;
   
   }
 
   // Retorna el nombre d’elements (la cardinalitat) del multiconjunt.
   int mcj_enters::card() const
   {
   return _mida;
   
   }
 
   // Operadors relacionals. == retorna cert si i només si els dos multiconjunts
   // (el paràmetre implícit i B) contenen els mateixos elements;
   // != retorna cert si i només si els multiconjunts són diferents.
   bool mcj_enters::operator==(const mcj_enters& B) const
   {
   node *pp1(_prim),*pp2(B._prim);
   if(_mida !=B._mida) return false;
   while(pp2 !=nullptr)
   {
   if(pp2->info != pp1->info) return false;
   else
   {
   pp2 = pp2->seg;
   pp1 = pp1->seg;
   } 
   }
   return true;   
   }
   bool mcj_enters::operator!=(const mcj_enters& B) const
   {
   return !(*this == B);   
   }
 
   // Imprimeix el multiconjunt d’enters, ordenats en ordre ascendent, sobre
   // el canal de sortida os; el format és [e1 e2 ... en], és a dir, amb
   // espais entre els elements i tancant la seqüència amb corxets.
   void mcj_enters::print(ostream& os) const
   {
   if(_mida == 0) os << "[]";
   else
   {
   node* pp1(_prim);
   os <<"[";
   while(pp1->seg != nullptr)
   {
   os << pp1->info << " ";
   pp1 = pp1->seg;
   }
   os << pp1->info << "]";
   }
   
   }
