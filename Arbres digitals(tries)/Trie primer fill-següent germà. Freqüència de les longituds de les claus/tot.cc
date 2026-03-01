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
       char _c;   // Símbol posició i-èssima de la clau
       node* _pf; // Primer fill, apunta a símbols de la següent posició
       node* _sg; // Següent germà, apunta a símbols de la mateixa posició
       node(const char &c, node* pf = NULL, node* sg = NULL);
     };
     node* _arrel;
 
     static void esborra_nodes(node* t);
     static node* insereix(node *t, nat i, const string &k);
 
     // Aquí va l’especificació dels mètodes privats addicionals
     void freq_longituds(node* n,vector<nat> &result,int i) const;
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
if(n != nullptr)
{
	if(n->_c == '#')
	{
		
		for(int j = result.size();j<=i;j++)result.push_back(0);
		result[i] = result[i] + 1;
	}
	freq_longituds(n->_pf,result,i + 1);
	freq_longituds(n->_sg,result,i);	
}
}

dicc::dicc() : _arrel(NULL) {}

dicc::~dicc() {
  esborra_nodes(_arrel);
}

void dicc::esborra_nodes(node* t) {
  if (t != NULL) {
    esborra_nodes(t->_pf);
    esborra_nodes(t->_sg);
    delete t;
  }
}

dicc::node::node(const char &c, node* pf, node* sg) :
  _c(c), _pf(pf), _sg(sg) {
}

typename dicc::node* dicc::insereix(node *t, nat i, const string &k) {
  if (t == NULL) {
    t = new node(k[i]);
    try {
      if (i < k.length()-1) {
        t->_pf = insereix(t->_pf, i+1, k);
      }
    }
    catch (...) {
      delete t;
      throw;
    }
  } else {
    if (t->_c > k[i]) {
      t = new node(k[i], NULL, t);
      try {
        if (i < k.length()-1) {
          t->_pf = insereix(t->_pf, i+1, k);
        }
      }
      catch (...) {
        delete t;
        throw;
      }
    }
    else if (t->_c < k[i]) {
      t->_sg = insereix(t->_sg, i, k);
    }
    else { // (t->_c == k[i])
      t->_pf = insereix(t->_pf, i+1, k);
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
