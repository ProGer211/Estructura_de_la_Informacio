#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class bst {

  public:
    // Constructora per defecte. Crea un BST buit.
    bst();

    // Destructora
    ~bst();

    // Aquí va l’especificació dels mètodes públics addicionals
    template <typename T>
    void ordena(vector<T>& v);
    
    void insereix(const Clau &k);

  private:
    struct node {
      Clau _k;      // Clau
      node* _esq;   // fill esquerre
      node* _dret;  // fill dret
    };
    node *_arrel;

    static void esborra_nodes(node* m);

    // Aquí va l’especificació dels mètodes privats addicionals
    static void inordena(vector<Clau>& resultat, node* n);
    static node* insereix(node* n,const Clau &k);
};

// Aquí va la implementació dels mètodes públics i privats de bst

// Aquí va la implementació del procediment ordena
template <typename Clau>
template <typename T>
void bst<Clau>::ordena(vector<T>& v)
{
for (const T& element : v) insereix(element);
int i = 0;
vector<T> resultat;
ordena(resultat,_arrel);
}
template <typename Clau>
void bst<Clau>::inordena(vector<Clau>& resultat,node* n)
{
 if(n != nullptr)
 {
 if(n->_esq != nullptr)inordena(resultat,n->_esq);
 resultat.push_back(n->_k);
 if(n->_dret != nullptr)inordena(resultat,n->_dret);
 }
}

template <typename Clau>
void bst<Clau>::insereix(const Clau &k)
{
insereix(_arrel,k);
}
template <typename Clau>
typename bst<Clau>::node* bst<Clau>::insereix(node* n,const Clau &k)
{
if(n != nullptr)
{
	if(n->_k > k) n->_esq = insereix(n->_esq,k);
	else if(n->_k <= k) n->_dret = insereix(n->_dret,k);
}
else
{
node *nou = new node;
nou->_k = k;
nou->_esq = nullptr;
nou->_dret = nullptr;
return nou;
}
}



template <typename Clau>
bst<Clau>::bst() : _arrel(NULL) {}

template <typename Clau>
void bst<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
bst<Clau>::~bst() {
  esborra_nodes(_arrel);
}

template <typename T>
void ordena(vector<T>& v);

template <typename T>
void mostra(vector<T> v) {
  for (nat i=0; i < v.size(); ++i) {
    cout << v[i] << ' ';
  }
  cout << endl;
}

int main() {
  nat n;
  while (cin >> n) {
    vector<double> v(n);
    for (nat i=0; i < n; ++i) {
      cin >> v[i];
    }

    ordena<double>(v);

    mostra<double>(v);
  }
  return 0;
}
