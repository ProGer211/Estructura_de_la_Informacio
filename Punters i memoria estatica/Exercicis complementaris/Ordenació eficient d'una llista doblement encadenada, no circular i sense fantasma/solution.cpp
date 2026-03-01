 #include <cstddef>
 #include <vector>
 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 class Llista {
   // Llista doblement encadenada, no circular i sense fantasma.
 
   public:
     Llista();
     // Pre: True
     // Post: El p.i. és una llista buida.
 
     Llista(const vector<int> &v);
     // Pre: True
     // Post: El p.i. conté els elements de v amb el mateix ordre.
 
     ~Llista();
     // Post: Destrueix els elements del p.i.
 
     nat longitud() const;
     // Pre: True
     // Post: Retorna el nombre d’elements del p.i.
 
     void mostra() const;
     // Pre: True
     // Post: Mostra el p.i. pel canal estàndard de sortida.
 
     void mostra_invertida() const;
     // Pre: True
     // Post: Mostra el p.i. en ordre invers pel canal estàndard de sortida.
 
     void ordena();
     // Pre: True
     // Post: S’han ordenat eficientment els elements del p.i. de major a menor
 
   private:
     struct node {
       int info;  // Informació del node
       node *seg; // Punter al següent element
       node *ant; // Punter a l’anterior element
     };
     node *_prim; // Punter al primer element
     node *_ult;  // Punter a l’últim element
     nat _long;   // Nombre d’elements
 
     // Aquí va l’especificació dels mètodes privats addicionals
     void mergeSort(int n);
     void partir(Llista &L2,int m);
     void fusionar(node* &n1,node* &n2);
 };
 
 // Aquí va la implementació del mètode ordena i privats addicionals
 
 void Llista::mergeSort(int n)
 {
 Llista L2;
 if(n > 1)
 {
 nat m = n/2;
 partir(L2,m);
 mergeSort(m);
 L2.mergeSort(n-m);
 fusionar(_prim,L2._prim);
 
 
 }
 }
  void Llista::partir(Llista &L2,int m)
  {
  node* p = _prim;
  while(m>1)
  {
  p = p->seg;
  --m;
  }
  L2._prim = p->seg;
  p->seg = nullptr;
  }
 
 
  void Llista::fusionar(node* &n1,node* &n2)
  {
  if(n1 == nullptr){
  n1 = n2;
  n2 = nullptr;
  }
  if(n1!= nullptr and n2 != nullptr){
  if(n1->info < n2->info){
  node* aux = n1;
  n1 = n2;
  n2 = aux;
  }
  node* aux = n1->seg;
  fusionar(aux,n2);
  n1->seg = aux;
  }
  
  }
 
 void Llista::ordena()
 {
  mergeSort(_long);
  
  node* p(_prim),*p1ant(nullptr);
  while(p != nullptr)
  {
  p->ant = p1ant;
  p1ant = p;
  p = p->seg;
  }
   if(p1ant != nullptr) _ult = p1ant; 
 }
 
 
 
 
