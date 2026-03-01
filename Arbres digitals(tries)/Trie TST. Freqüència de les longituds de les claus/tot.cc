#include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 class dicc {
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const string &k);
 
     vector<nat> freq_longituds() const;
     // Pre: True
     // Post: Retorna un vector amb les freqüències de les longituds de les claus.
     // La mida del vector és igual a la longitud de la clau més llarga més un. 
 
   private:
     struct node {
       char _c;    // Símbol posició i-èssima de la clau
       node* _esq; // Fill esquerra, apunta a símbols mateixa posició formant un BST
       node* _cen; // Fill central, apunta a símbols següent posició
       node* _dre; // Fill dret, apunta a símbols mateixa posició formant un BST
       node(const char &c, node* esq = NULL, node* cen = NULL, node* dre = NULL);
     };
     node* _arrel;
 
     static void esborra_nodes(node* t);
     static node* insereix(node *t, nat i, const string &k);
     void freq_longituds(node* n,vector<nat> &result,int i) const;
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode públic freq_longituds i privats addicionals
 vector<nat> dicc::freq_longituds() const
 {
 vector<nat> result;
 freq_longituds(_arrel,result,0);
 return result;

 }
 void dicc::freq_longituds(node* n,vector<nat> &result,int i) const
 {
  if(n!=nullptr)
  {
  	if(n->_c == '#')
  	{
  	for(int j = result.size();j<=i;j++)result.push_back(0);
  	result[i]++;
  	
  	}	
  	cout << n->_c << "Y";
  	freq_longituds(n->_esq,result,i);
  	cout << n->_c << "c";
  	freq_longituds(n->_cen,result,i + 1);
  	cout << n->_c <<"a";
  	freq_longituds(n->_dre,result,i);
  	cout << n->_c <<"d ";
  	
  }
 }

dicc::dicc() : _arrel(NULL) {}

dicc::~dicc() {
  esborra_nodes(_arrel);
}

void dicc::esborra_nodes(node* t) {
  if (t != NULL) {
    esborra_nodes(t->_esq);
    esborra_nodes(t->_cen);
    esborra_nodes(t->_dre);
    delete t;
  }
}

dicc::node::node(const char &c, node* esq, node* cen, node* dre) :
	_c(c), _esq(esq), _cen(cen), _dre(dre) {
}

typename dicc::node* dicc::insereix(node *t, nat i, const string &k) {
  if (t == NULL) {
    t = new node(k[i]);
    try {
      if (i < k.length()-1) {
        t->_cen = insereix(t->_cen, i+1, k);
      }
    }
    catch (...) {
      delete t;
      throw;
    }
  } else {
    if (t->_c > k[i]) {
      t->_esq = insereix(t->_esq, i, k);
    }
    else if (t->_c < k[i]) {
      t->_dre = insereix(t->_dre, i, k);
    }
    else { // (t->_c == k[i])
      t->_cen = insereix(t->_cen, i+1, k);
    }
  }
  return t;
}

void dicc::insereix (const string &k) {
  _arrel = insereix(_arrel, 0, k + '#'); // Símbol # és la marca de fi de clau
}

int main() {
  string input;
  dicc d;
  while (getline(cin, input)) {
    d.insereix(input);
  }

  vector<nat> freq = d.freq_longituds();
  for (nat i = 0; i < freq.size(); i++) {
    cout << freq[i] << " ";
  }
  cout << endl;
  return 0;
}
