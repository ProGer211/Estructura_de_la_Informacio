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
 
     bool compleix_suma_fills() const;
     // Pre: true
     // Post: retorna si compleix la propietat ’Suma dels fills’:
     // Per tot node el seu valor és igual a la suma dels valors
     // dels nodes (arrels) del fill esquerre i del fill dret.
 
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
     static bool compleix_suma_fills(node *p);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 template <typename T>
  bool Abin<T>::compleix_suma_fills(node *p)
  {
  bool asuma(true);
  if(p !=nullptr)
  {
  	if(p->f_esq != nullptr or p->f_dret != nullptr)
  	{
  	int afe(0),afd(0);
  	if(p->f_esq != nullptr)afe = p->f_esq->info;
  	if(p->f_dret != nullptr)afd = p->f_dret->info;
  	asuma = p->info == afe + afd and compleix_suma_fills(p->f_esq) and compleix_suma_fills(p->f_dret);
  	}
  
  }
  return asuma;
  
  
  }
  template <typename T>
  bool Abin<T>::compleix_suma_fills() const
  {
  return compleix_suma_fills(_arrel);
  
  
  }
  
  
  
  
  
  
