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
  
  
