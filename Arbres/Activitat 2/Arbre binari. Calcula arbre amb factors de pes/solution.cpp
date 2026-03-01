 #include <cstdlib>
 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class Abin {
   public:
     Abin(): _arrel(NULL) {};
     // Pre: cert
     // Post: el resultat és un arbre sense cap element
     Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
     // Pre: cert
     // Post: el resultat és un arbre amb un element i dos subarbres
 
     // Les tres grans
     Abin(const Abin<T> &a);
     ~Abin();
     Abin<T>& operator=(const Abin<T>& a);
 
     // operador << d’escriptura
     template <class U> friend std::ostream& operator<<(std::ostream&, const Abin<U> &a);
 
     // operador >> de lectura
     template <class U> friend std::istream& operator>>(std::istream&, Abin<U> &a);
 
     // Modifica el contingut de l’arbre per tal de guardar a cada node el factor
     // de pes (diferència entre quantitat nodes fill esquerra i quantitat nodes fill dret).
     void arbre_factors_pes();
 
   private:
     struct node {
       node* f_esq;
       node* f_dret;
       T info;
     };
     node* _arrel;
     static node* copia_nodes(node* m);
     static void esborra_nodes(node* m);
     static void print_nodes(node* m, ostream &os, string d1);
     static int arbre_factors_pes(node* p);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode arbre_factors_pes
 
 template <typename T>
 int Abin<T>::arbre_factors_pes(node* p)
 {
 int fe(0),fd(0);
 if(p != nullptr)
 {
  if(p->f_esq != nullptr and p->f_dret != nullptr)
  {
  fe = arbre_factors_pes(p->f_esq);
  fd = arbre_factors_pes(p->f_dret);
  p->info = fe- fd;
  return fe + fd + 1;
  
  }
  else if(p->f_esq != nullptr and p->f_dret == nullptr)
  {
   fe = arbre_factors_pes(p->f_esq);
   p->info = fe- fd;
   fe++;
   return fe;
  
  }
  else if(p->f_esq == nullptr and p->f_dret != nullptr)
  {
   fd = arbre_factors_pes(p->f_dret);
   p->info = fe- fd;
   fd++;
   return fd;
  }
  else
  {
  p->info = fe;
  fe++;
  return fe;
  }
 }
 return fe;
 }
 template <typename T>
 void Abin<T>::arbre_factors_pes()
 {
 arbre_factors_pes(_arrel);
 }
 
 
 
