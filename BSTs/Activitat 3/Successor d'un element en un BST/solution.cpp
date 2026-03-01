 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class dicc {
 
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const Clau &k);
 
     // Retorna quants elements (claus) té el diccionari.
     nat quants() const;
 
     // Pre: La clau k existeix al diccionari i té successor.
     // Post: Retorna la clau successora de la clau k.
     Clau successor(const Clau &k) const;
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
       nat _n;       // Nombre de nodes del subarbre
       node(const Clau &k, node* esq = NULL, node* dret = NULL);
     };
     node *_arrel;
 
     static void esborra_nodes(node* m);
     static node* insereix_bst(node *n, const Clau &k, bool &ins);
     static Clau successor(const Clau &k,node *n,bool &trobat);
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació dels mètodes públics i privats
 template <typename Clau>
 Clau dicc<Clau>::successor(const Clau &k) const
 {
 bool trobat = false;
 return successor(k,_arrel,trobat);
 }
 template <typename Clau>
 Clau dicc<Clau>::successor(const Clau &k,node *n,bool &trobat)
 {
 Clau c;
 if(n != nullptr)
 {
 	if(n->_k > k)
 	{
 	c = successor(k,n->_esq,trobat);
 		if(trobat == false) 
 		{	
 		trobat = true;
 		return n->_k;
 		}
 	}
 	else if(n->_k < k)
 	{
 	c = successor(k,n->_dret,trobat);
 	}
 	else if( n->_k == k)
 	{
 		if(n->_dret != nullptr)
 		{
 		n = n->_dret;
 		while(n->_esq != nullptr) n = n->_esq;
 		trobat = true;
 		return n->_k;
 		}
 	}
 }
 else trobat = true;
 return c;
 
 }
