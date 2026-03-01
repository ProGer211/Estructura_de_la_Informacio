 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 class dicc {
   // Taula de dispersió sinònims encadenats indirectes
   // Les llistes de sinònims estan ordenades per clau
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     // Retorna quants elements (claus) té el diccionari.
     nat quants() const;
 
     // Impressió per cout de totes les claus del diccionari segons l’ordre
     // en que estan a cadascuna de les llistes encadenades indirectes
     void print() const;
 
     // Pre: Cert
     // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const int &k);
 
     // Pre: El diccionari res està buit
     // Post: Omple res amb la intersecció entre el p.i. i d2
     void interseccio(const dicc &d2, dicc &res) const;
 
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
     bool consulta(const int &k) const;
 };
 
 // Aquí va la implementació dels mètodes públics insereix, interseccio i
 // dels mètodes privats addicionals
 
 
void dicc::insereix(const int &k)
{
int i = h(k) % _M;
if(_taula[i] != nullptr)
{
node_hash* _pant = nullptr;
node_hash* p = _taula[i];
while(p != nullptr and p->_k < k)
{
_pant = p;
p = p->_seg;
}
node_hash* nou = new node_hash;
nou->_k = k;
if(_pant != nullptr)_pant->_seg = nou;
else _taula[i] = nou;
nou->_seg = p;
_quants++;
}
else
{
node_hash* p = new node_hash;
p->_k = k;
_taula[i] = p;
p->_seg = nullptr;
_quants++;
}
}

bool dicc::consulta(const int &k) const
{
long i = h(k) % _M;
node_hash *p =_taula[i];
while(p != nullptr and p->_k < k)
{
p = p->_seg;
}
bool trobat; 
if(p!= nullptr and p->_k == k) trobat = true;
else trobat = false;
return trobat;
}
void dicc::interseccio(const dicc &d2, dicc &res) const
{
for(int i=0;i < _M ; ++i)
{
node_hash *p= _taula[i];
while(p != nullptr)
{
if(d2.consulta(p->_k)) res.insereix(p->_k);
p = p->_seg;
}
}
}


