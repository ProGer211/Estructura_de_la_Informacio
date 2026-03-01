#include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class dicc {
   public:
     dicc() : _arrel(NULL) {};
     // Pre: Cert
     // Post: El resultat és un dicc sense cap element
 
     ~dicc();
     // Pre: Cert
     // Post: El dicc ha estat destruït
 
     pair<Clau, char> insereix(const Clau &k);
     // Pre: Cert
     // Post: La clau k s’ha inserit en el diccionari si no hi era. Retorna la clau dels nodes
     // visitats a on hi ha el desequilibri més proper a les fulles i un caràcter amb el seu
     // tipus de desequilibri: ’E’: Esquerre, ’D’: Dret, ’ ’: No s’ha trobat cap desequilibri
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
       nat _h;       // Altura del subarbre
     };
     node *_arrel;
 
     static void esborra_nodes(node* m);
     static node* insereix(node* n,pair<Clau,char> &result, const Clau &k);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació dels mètodes públics i privats

template <typename Clau> 
pair<Clau, char> dicc<Clau>::insereix(const Clau &k)
{
pair<Clau,char> result;
_arrel = insereix(_arrel,result,k);
return result;
}

template <typename Clau> 
typename dicc<Clau>::node* dicc<Clau>::insereix(node* n,pair<Clau,char> &result,const Clau &k)
{
int altura_esq(0),altura_dret(0);
if(n != nullptr)
{
 	if(k < n->_k)
 	{
 	n->_esq = insereix(n->_esq,result,k);
 	if(n->_esq != nullptr) altura_esq = n->_esq->_h;
 	if(n->_dret != nullptr) altura_dret = n->_dret->_h;
 	n->_h = 1 + max(altura_esq,altura_dret);
 	}
 	else if(k > n->_k) 
 	{
 	n->_dret =insereix(n->_dret,result,k);
 	if(n->_esq != nullptr) altura_esq = n->_esq->_h;
 	if(n->_dret != nullptr) altura_dret = n->_dret->_h;
 	n->_h = 1 + max(altura_esq,altura_dret);
 	}
 	
}
else
{
	node* p = new node;
	p->_k = k;
	p->_esq = nullptr;
	p->_dret = nullptr;
	p->_h = 1;
	result = pair<Clau,char>(NULL,' ');
	return p; 

}
if(result.second == 'D' or result.second == 'E') return n;
int desequilibri_esq(0),desequilibri_dret(0);
if(n->_esq != nullptr) desequilibri_esq = n->_esq->_h;
if(n->_dret != nullptr) desequilibri_dret = n->_dret->_h;
int factor = desequilibri_esq - desequilibri_dret;
if(factor<0) factor = -factor;
if(factor > 1 ) 
{
if(desequilibri_esq > desequilibri_dret) result = pair<Clau,char>(n->_k,'E');
else result = pair<Clau,char>(n->_k,'D');
}
return n;
}


