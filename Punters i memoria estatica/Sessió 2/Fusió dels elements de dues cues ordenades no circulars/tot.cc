 #include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class cua { // Cua no circular en memòria dinàmica
   public:
     cua();
     // Construeix una cua buida.
 
     ~cua();
     // Destrueix el p.i.
 
     cua(const vector<int> &v);
     // Crea cua amb els elements de v amb el mateix ordre.
 
     nat longitud() const;
     // Retorna el nombre d’elements del p.i.
 
     void mostra() const;
     // Mostra el p.i. pel canal estàndard de sortida.
 
     void fusiona(const cua<T> &c2);
     // Pre: Les cues del p.i. i c2 estan ordenades de menor a major
     // Post: Al p.i. se li han afegit els elements de c2 ordenadament. c2 no es modifica
 
   private:
     struct node {
       T info;
       node* seg;
     };
     node* _pri; // Apunta al primer element de la cua
     node* _ult; // Apunta al darrer element de la cua
     nat _mida;
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode públic fusiona i privats addicionals
template <typename T>
void cua<T>::fusiona(const cua<T> &c2)
{
node *pp1(_pri),*pp1ant(nullptr),*pp2(c2._pri);
while(pp2 != nullptr)
{
	if(pp1 == nullptr or pp1->info > pp2->info)
	{
	node *pnou = new node;
	pnou->info = pp2->info;
	pnou->seg = pp1;
	if(pp1ant == nullptr)
	{
	pp1ant = pnou;
	_pri = pnou;
	} 
	else if(pp1 == nullptr)
	{
	_ult = pnou;
	pp1ant->seg = pnou;
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
   
#include <sstream>

template <typename T>
cua<T>::cua() : _pri(NULL), _ult(NULL), _mida(0) {}

template <typename T>
cua<T>::~cua() {
  while (_pri != NULL) {
    node* aux = _pri;  
    _pri = _pri->seg;
    delete aux;
  }
}

template <typename T>
cua<T>::cua(const vector<int> &v) : _pri(NULL), _ult(NULL), _mida(v.size()) {
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
    if (pant == NULL)
      _pri = p;
    else
      pant->seg = p;
    pant = p;
  }
  if (v.size() > 0) { // Arreglem darrer element
    p->seg = NULL;
    _ult = p;
  }
}

template <typename T>
nat cua<T>::longitud() const {
  return _mida;
}

template <typename T>
void cua<T>::mostra() const {
  node *p = _pri;
  cout << "[";
  if (p != NULL) {
    while (p != _ult) {
      cout << p->info << " ";
      p = p->seg;
    }
    cout << p->info;
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

  // Obtenim v2
  vector<int> v2;
  getline(cin, linea);
  istringstream ss2(linea);
  while (ss2 >> n) {
    v2.push_back(n);
  }

  cua<int> c1(v1);
  cua<int> c2(v2);
  c1.fusiona(c2);
  cout << c1.longitud() << " ";
  c1.mostra();
  cout << c2.longitud() << " ";
  c2.mostra();
  return 0;
}
