 #include <cstdlib>
 #include <utility>
 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class heap {
   public:
     heap(): _arrel(NULL), _nelems(0) {};
     // Pre: Cert
     // Post: El resultat és un heap sense cap element
 
     heap(heap<T> &he, const T &x, heap<T> &hd);
     // Pre: Cert
     // Post: El resultat és un heap amb x com arrel, he com a fill
     // esquerre i hd com a fill dret. No fa còpia dels heaps he i hd
 
     heap(const heap<T> &h);
     // Pre: Cert
     // Post: Crea un heap que és una còpia de h
 
     ~heap();
     // Pre: Cert
     // Post: El heap ha estat destruït
 
     bool empty() const;
     // Pre: Cert
     // Post: Retorna un booleà indicant si el heap està buit
 
     T min() const;
     // Pre: El heap no és buit
     // Post: Retorna l’element mínim del heap
 
     void elim_min();
     // Pre: El heap no és buit
     // Post: S’ha eliminat l’element mínim del heap o qualsevol d’ells si està repetit
 
   private:
     struct node {
       node* fesq;  // Punter al fill esquerre
       node* fdret; // Punter al fill dret
       node* pare;  // Punter al pare
       T info;
     };
     node* _arrel; // Arrel de l’arbre binari del heap
     int _nelems;  // Nombre d’elements del heap
 
     static node* copia_nodes(node* m, node *n_pare);
     static void esborra_nodes(node* m);
 
     void ultim(node* &ult, node* &pare_ult) const;
     // Pre: Cert
     // Post: ult conté el punter de l’últim element del heap (NULL si està buit)
     // pare_ult conté el punter del pare de l’últim element del heap (NULL si no en té)
 
     // Aquí va l’especificació dels mètodes privats addicionals
     static node* enfosar(node* n);
 };
 
 // Aquí va la implementació del mètode elim_min
 
 template <typename T>
 void heap<T>::elim_min()
 {
 node* _ult;
 node* pare_ult;
 ultim(_ult,pare_ult);
 if(pare_ult != nullptr)
 {
 _arrel->info = _ult->info;
 if(pare_ult->fesq == _ult) pare_ult->fesq = nullptr;
 else pare_ult->fdret = nullptr;
 }
 else
 {
 _arrel = nullptr;
 }
  delete(_ult);
 _nelems--;
 _arrel = enfosar(_arrel);
 }
 template <typename T>
 typename heap<T>::node* heap<T>::enfosar(node* n)
 {
 if(n!=nullptr)
 {
  if(n->fesq != nullptr and n->fdret != nullptr)
  {
  	if(n->fesq->info <= n->fdret->info and n->fesq->info < n->info)
  	{
  	swap(n->info,n->fesq->info);
  	n->fesq= enfosar(n->fesq);
  	}
  	else if(n->fesq->info >= n->fdret->info and n->fdret->info < n->info)
  	{
  	swap(n->info,n->fdret->info);
  	n->fdret = enfosar(n->fdret);
  	}
  
  }
  else if(n->fesq != nullptr and n->fesq->info < n->info)
  {
  swap(n->fesq->info,n->info);
  n->fesq = enfosar(n->fesq);
  }
  //no fa falta el dret ja que sempre son dos fills o 1 fill que es l'esquerre 100%
 }
 return n;
 }
 
 
