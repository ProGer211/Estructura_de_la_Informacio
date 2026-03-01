 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class dicc {
   // Diccionari implementat en un BST on les claus poden estar repetides.
 
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     // Imprimeix el contingut del diccionari: Nombre d’elements i
     // totes les claus de més petita a més gran separades per un espai
     void print() const;
 
     void insereix(const Clau &k);
     // Pre: Cert
     // Post: Insereix la clau k en el diccionari.
 
     nat quantes(const Clau &k) const;
     // Pre: Cert
     // Post: Retorna el nombre de claus iguals a k
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
     };
     node *_arrel;
     nat _n;       // Nombre d’elements del diccionari
 
     // Elimina els nodes del subarbre apuntat per p
     static void esborra_nodes(node* p);
     // Imprimeix ordenades les claus del subarbre apuntat per p
     static void print(node* p);
     static node* insereix(const Clau &k,node *n);
     static nat quantes(const Clau &k,node *n);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació dels mètodes públics i dels mètodes privats addicionals
 template <typename Clau>
 void dicc<Clau>::insereix(const Clau &k)
 {
 _arrel = insereix(k,_arrel);
 _n = _n + 1;
 }
 template <typename Clau>
 typename dicc<Clau>::node* dicc<Clau>::insereix(const Clau &k,node *n)
 {
 if(n!= nullptr)
 {
 	if(n->_k > k) n->_esq = insereix(k,n->_esq);
 	else if(n->_k <= k) n->_dret = insereix(k,n->_dret);
 }
 else
 {
 node *nou = new node;
 nou->_k = k;
 nou->_esq = nullptr;
 nou->_dret = nullptr;
 return nou;
 }
 return n;
 }
 
 template <typename Clau>
 nat dicc<Clau>::quantes(const Clau &k) const
 {
 return quantes(k,_arrel);
 }
 template <typename Clau>
 nat dicc<Clau>::quantes(const Clau &k,node* n) 
 {
 nat total(0);
 if(n!=nullptr)
 {
 	if(n->_k > k) total = quantes(k,n->_esq);
 	else if(n->_k < k)total = quantes(k,n->_dret);
 	else if(n->_k == k)
 	{
 	total = quantes(k,n->_dret);
 	total = total + 1;
 	}
 }
 return total;
 }
 
 
 
#include <sstream>
using namespace std;


template <typename Clau>
dicc<Clau>::dicc() : _arrel(nullptr), _n(0) {}

template <typename Clau>
void dicc<Clau>::esborra_nodes(node* p) {
  if (p != nullptr) {
    esborra_nodes(p->_esq);
    esborra_nodes(p->_dret);
    delete p;
  }
}

template <typename Clau>
dicc<Clau>::~dicc() {
  esborra_nodes(_arrel);
}

template <typename Clau>
void dicc<Clau>::print() const {
  cout << _n << ":";
  print(_arrel);
  cout << endl;
}

template <typename Clau>
void dicc<Clau>::print(node* p) {
  if (p != nullptr) {
    print(p->_esq);
    cout << " " << p->_k;
    print(p->_dret);
  }
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
    d.print();

    // Processem comandes
    while (getline(cin, linea) and linea != "----------") {
      cout << linea << ": ";
      istringstream ss2(linea);
      ss2 >> comanda >> n;

      if (comanda == "quantes") {
        cout << d.quantes(n) << endl;
      }
    }
    if (linea == "----------")
      cout << linea << endl;
  }
  return 0;
}
