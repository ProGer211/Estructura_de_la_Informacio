 #include <cstdlib>
 #include <string>
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
 
   // Col·loca l’Arbre donat com a darrer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
   void afegir_darrer_fill(Arbre<T> &a);
 
   // Imprimeix la informació dels nodes en preodre, cada element en una nova línia i precedit per espais segons el nivell on està situat.
   void preordre() const;
 
   static const int ArbreInvalid = 400;
 
   // Per cada fulla afegeix un nou fill que conté la suma de tots els elements del camí que va de l’arrel a la fulla.
   void crea_fills_sumes_camins();
 
 private:
   Arbre(): _arrel(NULL) {};
   struct node {
     T info;
     node* primf;
     node* seggerm;
   };
   node* _arrel;
   static node* copia_arbre(node* p);
   static void destrueix_arbre(node* p) throw();
   static void preordre(node *p, string pre);
   static void crea_fills_sumes_camins(node *p,T suma);
   // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode crea_fills_sumes_camins i dels privats addicionals

template <typename T>
void Arbre<T>::crea_fills_sumes_camins(node *p,T suma)
{
if(p != nullptr)
{
	if(p->primf == nullptr)
	{
	node *nou = new node;
	nou->info = suma + p->info;
	nou->primf = nou->seggerm = nullptr;
	p->primf = nou;
	
	
	}
	else
	{
	
	crea_fills_sumes_camins(p->primf,suma = suma + p->info);
	p = p->primf;
	while(p->seggerm !=nullptr)	
	{
		crea_fills_sumes_camins(p->seggerm,suma);
		if(p->seggerm != nullptr) p = p->seggerm;
	}
	}
}

}

template <typename T>
void Arbre<T>::crea_fills_sumes_camins()
{
crea_fills_sumes_camins(_arrel,0);

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
void Arbre<T>::afegir_darrer_fill(Arbre<T> &a) { 
  if (_arrel == NULL or a._arrel == NULL) {
    throw ArbreInvalid;
  }
  node *p = _arrel -> primf;
  if (p == NULL) {
    _arrel -> primf = a._arrel;
  } else {
    while (p -> seggerm != NULL) {
      p = p -> seggerm;
    }
    p -> seggerm = a._arrel;
  }
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
  while (nf>0) {
    Arbre<int> af = arbre();
    a.afegir_darrer_fill(af);
    nf--;
  }
  return a;
}

int main() {
  Arbre<int> a(arbre());
  a.crea_fills_sumes_camins();
  a.preordre();
  return 0;
}
