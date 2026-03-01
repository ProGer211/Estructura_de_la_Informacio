 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 class dicc {
   public:
     dicc();  // Constructora per defecte. Crea un diccionari buit.
 
     ~dicc(); // Destructora
 
     // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const string &k);
 
     nat quantes_comencen(string inicials) const;
     // Pre: inicials no conté el char ’#’
     // Post: Retorna el nº de claus que comencen per algun dels caràcters que conté inicials
 
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
 	
     // Aquí va l’especificació dels mètodes privats addicionals
      static void quantes_comencen(char ini,node* n,nat &total);
      static void contar(node* n,nat &total);
 };
 
 // Aquí va la implementació del mètode públic quantes_comencen i privats addicionals
 nat dicc::quantes_comencen(string inicials) const
 {
 nat total = 0;
 for(int i = 0;i<inicials.size();i++)
 {
 char ini = inicials[i];
 quantes_comencen(ini,_arrel,total);
 }
 return total;
 }
 void dicc::quantes_comencen(char ini,node* n,nat &total) 
 {
 if(n != nullptr)
 {
 	if(n->_c < ini)
 	{
 	quantes_comencen(ini,n->_dre,total);
 
 	}
 	else if(n->_c > ini)
	 {
	 quantes_comencen(ini,n->_esq,total);
 
 	}
 	else
 	{
	 contar(n->_cen,total);
 	}
 }
 }
 
 
 void dicc::contar(node* n,nat &total) 
 {
 if(n != nullptr)
 {
 if( n->_c == '#')
 {
 total++;
 }
 contar(n->_esq,total);
 contar(n->_cen,total);
 contar(n->_dre,total);
 
 }
 
 }
#include <sstream>
using namespace std;

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
  cin >> input;
  while (input != "----------") {
    d.insereix(input);
    cin >> input;
  }

  while (cin >> input) {
    cout << d.quantes_comencen(input) << " comencen per " << input << endl;
  }
  return 0;
}
