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
 
     // Retorna la segona clau.
     // Pre: El diccionari té com a mínim 2 claus.
     Clau segona() const;
 
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
     static Clau segona(node *n,int i);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació dels mètodes públics i privats
 template <typename Clau>
 Clau dicc<Clau>::segona() const
 {
 return segona(_arrel,2);
 }
 
 template <typename Clau>
 Clau dicc<Clau>::segona(node *n,int i)
 {
 Clau k;
 	if(n!=nullptr)
 	{
 	if(n->_esq != nullptr) 
 	{
 	if(n->_esq->_n >= i)k = segona(n->_esq,i);
 	else return n->_k;
 	}
 	else if(i==1) return n->_k;
 	else if(n->_dret != nullptr) k = segona(n->_dret,i - 1);;
	}
return k;	
 }
 
 
 
