#include <iostream>
 #include <sstream>
 #include <vector>
 #include <cstddef>
 using namespace std;
 typedef unsigned int nat;
 
 class Llista {
   // Llista simplement encadenada, sense fantasma i circular.
 
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
 
     void duplica_capicua();
     // Pre: True
     // Post: Es dupliquen tots els elements del p.i. obtenint una llista capicua
     // Exemple: [2 5 3 8 4] => [2 5 3 8 4 4 8 3 5 2]
 
   private:
     struct node {
       int info;  // Informació del node
       node *seg; // Punter al següent element
     };
     node *_prim; // Punter al primer element
     nat _long;   // Nombre d’elements
 
     // Aquí va l’especificació dels mètodes privats addicionals
 
 };



void Llista::duplica_capicua()
{
node *p(_prim),*p1ant(nullptr);
int i = 0;
while(i< _long)
{
node *nou = new node;
nou->info = p->info;
if(p1ant != nullptr) nou->seg = p1ant;
else nou->seg =p;
p1ant = nou;
i++;
if(p->seg != _prim) p = p->seg;
}
if(_prim != nullptr) p->seg = p1ant;
_long = _long*2;
}




