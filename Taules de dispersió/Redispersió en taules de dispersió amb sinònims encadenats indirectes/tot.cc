#include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 class dicc {
   // Taula de dispersió sinònims encadenats indirectes
   // Les llistes de sinònims estan ordenades per clau
   public:
     // Constructora per defecte. Crea un diccionari buit
     // en una taula de dispersió de mida m > 0
     dicc(nat m);
 
     // Destructora
     ~dicc();
 
     // Retorna quants elements (claus) té el diccionari.
     nat quants() const;
 
     // Impressió per cout de totes les claus del diccionari segons l’ordre
     // en que estan a cadascuna de les llistes encadenades indirectes
     void print() const;
 
     // Pre: Cert
     // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     // Redimensiona la taula de dispersió amb una mida el doble que 
     // l’anterior més un si el factor de càrrega és superior a 0.8
     void insereix(const int &k);
 
     // Pre: Cert
     // Post: Retorna el factor de càrrega de la taula de dispersió
     float factor_de_carrega() const;
 
     // Pre: Cert
     // Post: Redimensiona la taula de dispersió amb una mida el doble que 
     // l’anterior més un (_M => 2*_M+1)
     void redispersio();
 
   private:
     struct node_hash {
       int _k;           // Clau
       node_hash* _seg;
     };
     node_hash **_taula; // Taula amb punters a les llistes de sinònims
     nat _M;             // Mida de la taula
     nat _quants;        // Nº d’elements guardats al diccionari
 
     static long const MULT = 31415926;
 
     // Calcula un valor de dispersió entre 0 i LONG_MAX a partir de k
     static long h(int k);
 
     // Destrueix la llista de nodes apuntats per p
     static void esborra_nodes(node_hash *p);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 
 };
 
 // Aquí va la implementació dels mètodes públics factor_de_carrega, redispersio i
 // dels mètodes privats addicionals
 float dicc::factor_de_carrega() const
 {
 return float(_quants)/float(_M);
 }
 
 void dicc::redispersio()
 {
 node_hash** vieja_tabla = _taula;
 nat old_M = _M;
 _M = (2*_M)+1;
 _taula = new node_hash*[_M];
 _quants = 0;
 for (int i=0; i < _M; ++i) {
    _taula[i] = NULL;
  }
 for(int i = 0;i<old_M;i++)
 {
 	if(vieja_tabla[i] != nullptr)
 	{
 	node_hash *p = vieja_tabla[i];
 	while(p != nullptr)
 	{
 	insereix(p->_k);
 	p = p->_seg;
 	}
 }
 }
 delete[] vieja_tabla;
 }
 
 
 
#include <iostream>
#include <sstream>
using namespace std;

long dicc::h(int k) {
  long i = (((k+1) * k * MULT) << 47) >> 7;
  if (i < 0)
    i = -i;
  return i;
}

dicc::dicc(nat m) : _quants(0) {
  _M = m;
  _taula = new node_hash*[_M];
  for (int i=0; i < _M; ++i) {
    _taula[i] = NULL;
  }
}

void dicc::esborra_nodes(node_hash *p) {
  if (p != NULL) {
    esborra_nodes(p->_seg);
    delete p;
  }
};

dicc::~dicc() {
  for (int i=0; i < _M; ++i) {
    esborra_nodes(_taula[i]);
  }
  delete _taula;
};

nat dicc::quants() const {
  return _quants;
}

void dicc::print() const {
  for (int i=0; i < _M; ++i) {
    cout << i << ": ";
    node_hash *p = _taula[i];
    while (p != NULL) {
      cout << p->_k << " ";
      p = p->_seg;
    }
    cout << endl;
  }
  cout << "-----------\n";
}

void dicc::insereix(const int &k) {
  long i = h(k) % _M;
  node_hash *p = _taula[i], *ant = NULL;
  while (p != NULL and p->_k < k) {
    ant = p;
    p = p->_seg;
  }
  if (p == NULL or p->_k > k) {
    node_hash *n = new node_hash;
    n->_k = k;
    n->_seg = p;
    if (ant == NULL)
      _taula[i] = n;
    else
      ant->_seg = n;
    ++_quants;
    if (factor_de_carrega() > 0.8) {
      redispersio();
    }
  }
}

int main() {
  string linea;
  int n;
  cin >> n; getline(cin, linea);
  dicc d(n);

  // Inserim alguns elements al diccionari
  getline(cin, linea);
  istringstream ss1(linea);
  while (ss1 >> n){
    d.insereix(n);
  }
  cout << "Nº elem: " << d.quants() << endl;
  cout << "Factor de càrrega: " << d.factor_de_carrega() << endl;
  d.print();

  // Inserim alguns elements al diccionari
  getline(cin, linea);
  istringstream ss2(linea);
  while (ss2 >> n){
    d.insereix(n);
  }
  cout << "Nº elem: " << d.quants() << endl;
  cout << "Factor de càrrega: " << d.factor_de_carrega() << endl;
  d.print();

 
  return 0;
}
