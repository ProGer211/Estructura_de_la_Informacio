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
#include <sstream>

template <typename T>
pila<T>::pila() : _cim(NULL), _mida(0) {}

template <typename T>
pila<T>::~pila() {
  while (_cim != NULL) {
    node* aux = _cim;  
    _cim = _cim->seg;
    delete aux;
  }
}

template <typename T>
pila<T>::pila(const vector<int> &v) : _cim(NULL), _mida(v.size()) {
  node *p, *pant = NULL;
  for (nat i=0; i<v.size(); i++) {
    p = new node;
    try {
      p->info = v[i];
    } catch (const char* message) {
      cerr << message << endl;
      delete p;
      throw;
    }
    p->seg = NULL;
    if (pant == NULL)
      _cim = p;
    else
      pant->seg = p;
    pant = p;
  }
}

template <typename T>
nat pila<T>::longitud() const {
  return _mida;
}

template <typename T>
void pila<T>::mostra() const {
  node *p = _cim;
  cout << "[";
  if (p != NULL) {
    cout << p->info;
    p = p->seg;
    while (p != NULL) {
      cout << " " << p->info;
      p = p->seg;
    }
  }
  cout << "]" << endl;
}

int main() {
  int n;
  string linea;

  // Obtenim v1
  vector<int> v1;
  getline(cin, linea);
  istringstream ss1(linea);
  while (ss1 >> n) {
    v1.push_back(n);
  }

  pila<int> p(v1);
  cout << p.longitud() << " ";
  p.mostra();
  p.duplica_amb_sumes();
  cout << p.longitud() << " ";
  p.mostra();
  return 0;
}
