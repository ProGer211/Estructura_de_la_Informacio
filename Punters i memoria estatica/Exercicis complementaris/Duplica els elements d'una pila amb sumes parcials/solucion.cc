 #include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class pila { // pila en memòria dinàmica
   public:
     pila();
     // Crea pila buida
 
     ~pila();
     // Destrueix el p.i.
 
     pila(const vector<int> &v);
     // Crea pila amb els elements de v amb el mateix ordre.
 
     nat longitud() const;
     // Retorna el nombre d’elements del p.i.
 
     void mostra() const;
     // Mostra el p.i. pel canal estàndard de sortida.
 
     void duplica_amb_sumes();
     // Pre: true
     // Post: S’han duplicat els elements de la pila, a sobre de cada element hi ha un
     // nou element que conté la suma dels elements restants de la pila original
 
   private:
     struct node {
       T info;
       node* seg;
     };
     node* _cim; // Apunta al cim de la pila
     nat _mida;  // Nombre d’elements de la pila
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode duplica_amb_sumes i dels privats addicionals
 
  template <typename T>
  void pila<T>::duplica_amb_sumes()
  {
  node *p1(_cim),*pant(nullptr);
  node *p(_cim);
  int total = 0;
  while(p !=nullptr)
  {
  if(p1 !=nullptr)
  {
  total = total + p1->info;
  p1 = p1->seg;
  }
  else if(p1 == nullptr)
  {
  node *pnou = new node;
  pnou->info = total;
  pnou->seg = p;
  if(pant == nullptr) _cim = pnou;
  else pant->seg = pnou;
  pant = p;
  p = p->seg;
  p1 = p;
  total = 0;
  _mida++;
  }
  }
 if(pant !=nullptr)pant->seg = nullptr;
  }
