 #include <cstdlib>
 #include <vector>
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
 
   // Col·loca l’Arbre donat com a darrer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
   void afegir_darrer_fill(Arbre<T> &a);
 
   static const int ArbreInvalid = 400;
 
   // Retorna un vector amb les sumes de tots els elements de cada nivell.
   vector<T> sumes_nivells() const;
 
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
   
 
   // Aquí va l’especificació dels mètodes privats addicionals
   static void sumes_nivells(node* p, vector<T> &v,int nivell); 
 };
 
 // Aquí va la implementació del mètode sumes_nivells
 template <typename T>
  void Arbre<T>::sumes_nivells(node *p, vector<T> &v,int nivell) 
  {
  if(p !=nullptr)
  {
  if(p->seggerm != nullptr)
  {
  sumes_nivells(p->seggerm, v,nivell); 
  v[nivell] += p->info;
  sumes_nivells(p->primf, v,nivell = nivell + 1); 
  }
  else
  {
  if(v.size() > nivell) v[nivell] += p->info;
  else v.push_back(p->info);
  sumes_nivells(p->primf, v,nivell = nivell + 1);
  } 
  
  }
  
  }
   template <typename T>
  vector<T> Arbre<T>::sumes_nivells() const
  {
   vector<T> v;
   sumes_nivells(_arrel,v,0);
   return v;
  }
