#include <cstdlib>
 #include <string>
 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class Arbre {
 
 public:
   // Construeix un Arbre format per un únic node que conté a x.
   Arbre(const T &x);
 
   // Tres grans.
   Arbre(const Arbre<T> &a);
   Arbre& operator=(const Arbre<T> &a);
   ~Arbre() throw();
 
   // Col·loca l’Arbre donat com a primer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
   void afegir_fill(Arbre<T> &a);
 
   // Imprimeix la informació dels nodes en preordre, cada element en una nova línia i precedit per espais segons el nivell on està situat.
   void preordre() const;
 
   static const int ArbreInvalid = 400;
 
   void arbre_simetric();
   // Pre: cert
   // Post: Modifica l’arbre amb el simètric de l’arbre original
 
 private:
   Arbre(): _arrel(NULL) {};
   struct node {
     T info;        // Informació del node
     node* primf;   // Punter al primer fill
     node* seggerm; // Punter al següent germà
   };
   node* _arrel; // Punter a l’arrel de l’arbre
   static node* copia_arbre(node* p);
   static void destrueix_arbre(node* p) throw();
   static void preordre(node *p, string pre);
   static void arbre_simetric(node *p);
 
   // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode arbre_simetric i privats addicionals
 
 template <typename T>
 void Arbre<T>::arbre_simetric(node *p)
  {
  if(p != nullptr)
  {
  node* fill = p->primf;
  node* prev_hermano = nullptr;
  while(p->primf != nullptr)
  {
  arbre_simetric(p->primf);
  node *next_hermano = p->primf->seggerm;
  p->primf->seggerm = prev_hermano;
  prev_hermano = p->primf;
  p->primf = next_hermano;
  
  }
  p->primf = prev_hermano;
  
  }
 
  }
  template <typename T>
  void Arbre<T>::arbre_simetric()
  {
   arbre_simetric(_arrel);
  }
  
  
#include <iostream>
#include <stack>

template <typename T>       
typename Arbre<T>::node* Arbre<T>::copia_arbre(node* p) { 
  node* aux = NULL;
  if (p != NULL) {
    aux = new node;
    try {
      aux -> info = p -> info;
      aux -> primf = aux -> seggerm = NULL;
      aux -> primf = copia_arbre(p -> primf);
      aux -> seggerm = copia_arbre(p -> seggerm);
    }
    catch (...) {
      destrueix_arbre(aux);
    }
  }
  return aux;
}

template <typename T> 
void Arbre<T>::destrueix_arbre(node* p) throw() { 
  if (p != NULL) {
    destrueix_arbre(p -> primf);
    destrueix_arbre(p -> seggerm);
    delete p;
  }
}

template <typename T> 
Arbre<T>::Arbre(const T &x) {
  _arrel = new node; 
  try {
    _arrel -> info = x;
    _arrel -> seggerm = NULL;
    _arrel -> primf = NULL;
  } 
  catch (...) {
    delete _arrel;
    throw;
  }
}

template <typename T> 
Arbre<T>::Arbre(const Arbre<T> &a) { 
  _arrel = copia_arbre(a._arrel);
}

template <typename T> 
Arbre<T>&  Arbre<T>::operator=(const Arbre<T> &a) { 
  Arbre<T> tmp(a);
  node* aux = _arrel;
  _arrel = tmp._arrel;
  tmp._arrel = aux;
  return *this;
}

template <typename T> 
Arbre<T>::~Arbre() throw() { 
  destrueix_arbre(_arrel);
}

template <typename T> 
void Arbre<T>::afegir_fill(Arbre<T> &a) { 
  if (_arrel == NULL or a._arrel == NULL or 
    a._arrel -> seggerm != NULL) {
    throw ArbreInvalid;
  }
  a._arrel -> seggerm = _arrel -> primf;
  _arrel -> primf = a._arrel;
  a._arrel = NULL;
}

template <typename T>
void Arbre<T>::preordre(node *p, string pre) {
  if (p != NULL) {
    cout << pre << p->info << endl;
    preordre(p->primf, pre + "  ");
    preordre(p->seggerm, pre);
  }
}

template <typename T>
void Arbre<T>::preordre() const {
  preordre(_arrel, "");
}

// Llegeix un arbre general des de cin i el retorna.
Arbre<int> arbre() {
  int valor, nf;
  cin >> valor >> nf;
  Arbre<int> a(valor);
  stack<Arbre<int> > pa;
  while (nf>0) {
    pa.push(arbre());
    nf--;
  }
  while (not pa.empty()) {
    a.afegir_fill(pa.top());
    pa.pop();
  }
  return a;
}

int main() {
  Arbre<int> a(arbre());
  a.arbre_simetric();
  a.preordre();
  return 0;
}
