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
 
     void fusiona(const pila<T> &p2);
     // Pre: Les piles del p.i. i p2 estan ordenades de menor a major
     // Post: Al p.i. se li han afegit els elements de p2 ordenadament. p2 no es modifica
 
   private:
     struct node {
       T info;
       node* seg;
     };
     node* _cim; // Apunta al cim de la pila
     nat _mida;  // Nombre d’elements de la pila
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode públic fusiona i privats addicionals
 template <typename T>
 void pila<T>::fusiona(const pila<T> &p2)
 {
 node *pp1(_cim), *pp1ant(nullptr),*pp2(p2._cim);
 
 while(pp2 != nullptr)
  {
  	if(pp1 == nullptr or pp1->info > pp2->info) //
  	{
  	
  	node *pnou = new node;
  	pnou->info = pp2->info;
  	pnou->seg = pp1;
  	if(pp1ant == nullptr)
  	{
  	 _cim = pnou;
  	 pp1ant = pnou;
  	}
  	else 
  	{
  	pp1ant->seg = pnou;
  	pp1ant = pnou;
  	}  	 
  	 _mida++;
  	 pp2 = pp2->seg;
  	
  	}
  	else if(pp1->info <= pp2->info)
  	{
  	
  	if(pp1ant == nullptr) pp1ant = pp1;
  	else pp1ant = pp1ant->seg;
  	pp1 = pp1->seg;    	 	
  	}
  }
 }
 
