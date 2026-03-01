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
 
     // Modifica el contingut de l’arbre per tal de guardar a cada node la suma dels
     // nodes del seu subarbre.
     void arbre_sumes();
 
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
     static int arbre_sumes(node *p);
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode arbre_sumes
  template <typename T>
 int Abin<T>::arbre_sumes(node *p)
 {
 int suma(0);
 if(p != nullptr)
 {
 	if(p->f_esq != nullptr or p->f_dret != nullptr)
 	{
 	int afe(0),afd(0);
 	if(p->f_esq != nullptr) afe = arbre_sumes(p->f_esq);
 	if(p->f_dret != nullptr) afd = arbre_sumes(p->f_dret);
 	suma = p->info + afe + afd;
 	p->info = suma;
 	}
 
 }
 if(p == nullptr) return suma;
 else if(p->f_esq == nullptr or p->f_dret == nullptr) return p->info;
 else return suma;
 
 }
 
  template <typename T>
 void Abin<T>::arbre_sumes()
 {
  arbre_sumes(_arrel);
 
 }
 
 
 
