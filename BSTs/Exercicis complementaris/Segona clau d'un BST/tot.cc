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
     static Clau segona(node* n,nat i);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació dels mètodes públics i privats
 template <typename Clau>
 Clau dicc<Clau>::segona() const
 {
 return segona(_arrel,2);
 }
 template <typename Clau>
 Clau dicc<Clau>::segona(node* n,nat i) 
 {
 Clau k;
 if(n!= nullptr)
 {	
 	 if(n->_esq != nullptr)
 	{
 	if(n->_esq->_n >= i) k = segona(n->_esq,i);
 	else return n->_k;
 	
 	}
 	else if(n->_dret != nullptr) 
 	{
 	if(i == 1) return n->_k;
 	k = segona(n->_dret,i - 1);
 	}
 	else return n->_k;
 }
 return k;
 }
 
#include <sstream>
using namespace std;


template <typename Clau>
dicc<Clau>::dicc() : _arrel(NULL) {}

template <typename Clau>
void dicc<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
dicc<Clau>::~dicc() {
  esborra_nodes(_arrel);
}

template <typename Clau>
dicc<Clau>::node::node (const Clau &k, node* esq, node* dret) :
	_k(k), _esq(esq), _dret(dret), _n(1) {
}

template <typename Clau>
void dicc<Clau>::insereix(const Clau &k) {
  bool ins = false;
  _arrel = insereix_bst(_arrel, k, ins);
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::insereix_bst (node *n, const Clau &k, bool &ins) {
  if (n == NULL) {
    ins = true;
    return new node(k);
  }
  else {
    if (k < n->_k) {
      n->_esq = insereix_bst(n->_esq, k, ins);
    }
    else if (k > n->_k) {
      n->_dret = insereix_bst(n->_dret, k, ins);
    }
    if (ins)
      n->_n++;
    return n;
  }
}

template <typename Clau>
nat dicc<Clau>::quants() const {
  nat n = 0;
  if (_arrel != NULL)
    n = _arrel->_n;
  return n;
}


int main() {
  string linea, comanda;
  int n;
  while (getline(cin, linea)) {
    dicc<int> d;

    // Obtenim elements 1er diccionari
    istringstream ss1(linea);
    while (ss1 >> n) {
      d.insereix(n);
    }
    cout << d.quants() << endl;

    // Processem comandes
    while (getline(cin, linea) and linea != "----------") {
      cout << linea << ": ";
      istringstream ss2(linea);
      ss2 >> comanda;

      if (comanda == "segona") {
        cout << d.segona() << endl;
      }
    }
    if (linea == "----------")
      cout << linea << endl;
  }
  return 0;
}
