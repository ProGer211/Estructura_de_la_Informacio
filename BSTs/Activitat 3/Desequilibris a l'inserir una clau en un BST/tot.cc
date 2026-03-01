 #include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class dicc {
   public:
     dicc() : _arrel(NULL) {};
     // Pre: Cert
     // Post: El resultat és un dicc sense cap element
 
     ~dicc();
     // Pre: Cert
     // Post: El dicc ha estat destruït
 
     vector<Clau> insereix(const Clau &k);
     // Pre: Cert
     // Post: La clau k s’ha inserit en el diccionari si no hi era. Retorna un vector amb 
     // les claus dels nodes visitats on hi ha un desequilibri desprès de la inserció,
     // començant per la més propera a les fulles i acabant per la més propera a l’arrel.
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
       nat _h;       // Altura del subarbre
     };
     node *_arrel;
 
     static void esborra_nodes(node* m);
     static node* insereix(const Clau &k,node *n,vector<Clau> &result);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació dels mètodes públics i privats
 template <typename Clau>
 vector<Clau> dicc<Clau>::insereix(const Clau &k)
 {
 vector<Clau> result;
 _arrel = insereix(k,_arrel,result);
 return result;
 }
 template <typename Clau>
 typename dicc<Clau>::node* dicc<Clau>::insereix(const Clau &k,node *n,vector<Clau> &result)
 {
 int alturaesq(0),alturadret(0);
 if(n != nullptr)
 {
 	if(n->_k > k)
 	{
 	n->_esq = insereix(k,n->_esq,result);
 	if(n->_esq != nullptr) alturaesq = n->_esq->_h;
 	if(n->_dret != nullptr) alturadret = n->_dret->_h;
 	n->_h = 1 + max(alturaesq,alturadret);
 	}
 	else if(n->_k < k)
 	{
 	n->_dret = insereix(k,n->_dret,result);
 	if(n->_esq != nullptr) alturaesq = n->_esq->_h;
 	if(n->_dret != nullptr) alturadret = n->_dret->_h;
 	n->_h = 1 + max(alturaesq,alturadret);
 	}
 }
 else
 {
 node *nou = new node;
 nou->_k = k;
 nou->_esq = nullptr;
 nou->_dret = nullptr;
 nou->_h = 1;
 return nou;
 }
 int desequilibriesq(0),desequilibridret(0);
 if(n->_esq != nullptr) desequilibriesq = n->_esq->_h;
 if(n->_dret != nullptr) desequilibridret = n->_dret->_h;
 int factor;
 factor = desequilibriesq - desequilibridret;
 if(factor < 0) factor = -factor;
 if(factor>1)result.push_back(n->_k);
 return n;
 }
 
 

template <typename Clau>
void dicc<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
dicc<Clau>::~dicc() {
  esborra_nodes(_arrel);
}


int main() {
  int n;
  dicc<int> d;
  while (cin >> n) {
    vector<int> v;
    v = d.insereix(n);
    cout << "insereix " << n << ":";
    for (nat i = 0; i < v.size(); i++) {
      cout << " " << v[i];
    }
    cout << endl;
  }
  return 0;
}
