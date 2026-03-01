#include <vector>
#include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 class graf {
   // Graf dirigit i no etiquetat.
   // Les arestes es guarden en una matriu d’adjacència.
   public:
     // Constructora per defecte. Crea un graf buit.
     graf();
 
     // Destructora
     ~graf();
 
     // Llegeix les dades del graf del canal d’entrada
     void llegeix();
 
     vector<nat> quants_succ_succ() const;
     // Pre: Cert
     // Post: Retorna quants successors diferents tenen els successors de cada vèrtex
     // del graf
 
   private:
     nat n; // Nombre de vèrtexs
     nat m; // Nombre d’arestes
     vector<vector<bool> > a; // Matriu d’adjacència
 
     // Aquí va l’especificació dels mètodes privats addicionals
     void quants_succ_succ(vector<nat> &succ,nat compte,nat i) const;
 };
 
 // Aquí va la implementació del mètode públic quants_succ_succ i privats addicionals
 vector<nat> graf::quants_succ_succ() const
 {
 vector<nat> total;
 for(int i = 0;i<n;i++)
 {
 vector<nat> succ;
 quants_succ_succ(succ,1,i);
 total.push_back(succ.size());
 }
 return total;
 }
 void graf::quants_succ_succ(vector<nat> &succ,nat compte,nat i) const
 {
  bool mateix = false;
 for(int j = 0;j<n;j++)
 {
 	if(a[i][j] == true && compte == 2)
 	{
 	for(int z = 0;z<succ.size();z++) if(succ[z] == j) mateix = true;
 		if(mateix == false)
 		{
 		succ.push_back(j);
 		}
 		else mateix = false;
 	}
 	else if(a[i][j] == true) quants_succ_succ(succ,compte + 1,j);
 }

 
 }
#include <iostream>
using namespace std;

graf::graf() : n(0), m(0) {}

graf::~graf() {}

void graf::llegeix() {
  // Llegim el nombre de vèrtexs i arestes
  cin >> n >> m;

  // Creem la matriu d'adjacència
  a = vector<vector<bool> >(n, vector<bool>(n, false));

  // Llegim les m arestes
  nat u, v;
  for(nat i = 0; i < m; i++) {
    cin >> u >> v; // Aresta que connecta vèrtex u amb vèrtex v
    a[u][v] = true;
  }
}

int main() {
  graf g;
  g.llegeix();
  vector<nat> resultat = g.quants_succ_succ();
  for(nat i=0; i<resultat.size(); i++) {
    cout << resultat[i] << " ";
  }
  cout << endl;
  return 0;
}
