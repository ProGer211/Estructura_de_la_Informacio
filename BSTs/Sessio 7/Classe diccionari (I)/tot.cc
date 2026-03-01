 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class dicc {
 
 public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Les tres grans: Constructora per còpia, destructora, operador d’assignació
     dicc(const dicc &d);
     ~dicc();
     dicc& operator=(const dicc &d);
 
     // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const Clau &k);
 
     // Elimina la clau k del diccionari. Si no hi era, no fa res.
     void elimina(const Clau &k);
 
     // Consulta si la clau k està en el diccionari.
     bool consulta(const Clau &k) const;
 
     // Retorna quants elements (claus) té el diccionari.
     nat quants() const;
 
     // Impressió per cout de claus del diccionari en ordre ascendent, separades per
     // un espai, començant per ’[’ i acabant per ’]’, en dues versions:
     // Imprimeix totes les claus
     void print() const;
     // Imprimeix les claus entre k1 i k2 ambdós incloses. Pre: k1 <= k2
     void print_interval(const Clau &k1, const Clau &k2) const;
 
     // Retorna la clau més petita i la més gran respectivament.
     // Pre: El diccionari no està buit
     Clau min() const;
     Clau max() const;
 
     // Retorna la clau de la posició i-èssima (comptant-les en ordre ascendent).
     // Pre: El diccionari no està buit. 1 <= i <= quants()
     Clau iessim(nat i) const;
 
 private:
   // Aquí van els atributs i mètodes privats
   struct node {
   node* f_esq;
   node* f_dret;
   Clau info;
   int grandaria;
   };
   node* _arrel;
   static node* insereix(node* n,const Clau &k,bool &trobat);
   static bool consulta(node* n,const Clau &k);
   static Clau min(node* n);
   static Clau max(node* n);
   static node* elimina(node* n,const Clau &k,bool &trobat);
   static node* elimina_maxim(node* p);
   static node* ajuntar(node* t1,node* t2);
   static void print(node* n,int k);
   static void print_interval(node* n,const Clau &k1,const Clau &k2);
   static Clau iessim(node* n,nat i);
   
 };
 
 // Aquí va la implementació dels mètodes públics i privats
template <typename Clau>
dicc<Clau>::dicc()
{
_arrel = nullptr;
}
 
template <typename Clau>
dicc<Clau>::dicc(const dicc &d)
{
_arrel = d._arrel;

}
template <typename Clau>
dicc<Clau>::~dicc()
{
delete(_arrel);
}
template <typename Clau>
typename dicc<Clau>::dicc& dicc<Clau>::operator=(const dicc &d)
{

_arrel = d._arrel;
return *this;
}
 
 
 
 
template <typename Clau> 
void dicc<Clau>::elimina(const Clau &k)
{
bool trobat = false;
_arrel = elimina(_arrel,k,trobat);
}
 
template <typename Clau> 
typename dicc<Clau>::node* dicc<Clau>::elimina(node* n,const Clau &k,bool &trobat)
{
 if(n != nullptr)
 {
 	if(n->info > k) n->f_esq = elimina(n->f_esq,k,trobat);
 	else if(n->info < k) n->f_dret = elimina(n->f_dret,k,trobat);
 	else
 	{
 		if(n->f_esq == nullptr and n->f_dret == nullptr) 
 		{
 		delete(n);
 		return nullptr; //sino devuelvo nullptr da volcat de memoria
 		}
 		else if(n->f_esq != nullptr and n->f_dret == nullptr) 
 		{
 		node* nou = n->f_esq;
 		delete(n);
 		return nou;
 		}
 		else if(n->f_esq == nullptr and n->f_dret != nullptr)
 		{
 		node* nou = n->f_dret;
 		delete(n);
 		return nou;
 		}
 		else
 		{
 		int i = 0;
 		node* p = n->f_dret;
 		node* p_ant = n;
 		node* fill = nullptr;
 		if(p->f_esq == nullptr) i = 1;
 		while(p->f_esq != nullptr)
 		{
 		p_ant = p;
 		p->grandaria = p->grandaria - 1;
 		p = p->f_esq;
 		}
 		n->info = p->info;
 		if(p->f_dret != nullptr) fill = p->f_dret;
 		if(i == 0)p_ant->f_esq = fill;
 		else p_ant->f_dret = fill;
 		delete(p);
 		}
 
 	}
 	if(n!=nullptr and trobat != true )n->grandaria = n->grandaria - 1;
 }
 else if(n == nullptr) trobat = true;
 return n;
 }
 /*if( n!= nullptr)
 {
 node *p = n;
 if(k < n->info) n->f_esq = elimina(n->f_esq,k,trobat);
 else if(k > n->info) n->f_dret = elimina(n->f_dret,k,trobat);
 else
 {
 n = ajuntar(n->f_esq,n->f_dret);
 delete(p);
 }
 }
 else if(n == nullptr) trobat = true;
 if(n!=nullptr and trobat != true )n->grandaria = n->grandaria - 1;
 return n;
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::ajuntar(node* t1,node* t2)
{
if(t1 == nullptr) return t2;
if(t2 == nullptr) return t1;
node* p = elimina_maxim(t1);
p->f_dret = t2;
return p;
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::elimina_maxim(node* p)
{
node *p_orig = p;
node *pare = nullptr;
while(p->f_dret != nullptr)
{
pare = p;
p = p->f_dret;
}
if(pare != nullptr)
{
pare->f_dret = p->f_esq;
p->f_esq = p_orig;
}
return p;

}*/

template <typename Clau>
nat dicc<Clau>::quants() const
{
if(_arrel!= nullptr) return _arrel->grandaria;
else return 0;

} 

template <typename Clau> 
void dicc<Clau>::print() const
{
int k;
if(_arrel != nullptr) k = max();
else  k = 0;
cout << "[";
print(_arrel,k);
cout << "]";
}
template <typename Clau> 
void dicc<Clau>::print(node* n,int k)
{
if(n!= nullptr)
{
print(n->f_esq,k);
if(k == n->info) cout << n->info;
else cout << n->info << " ";
print(n->f_dret,k);
}

}
template <typename Clau> 
void dicc<Clau>::print_interval(const Clau &k1, const Clau &k2) const
{
cout << "[";
if(min() == max() and max()>= k1 and max()<=k2) cout << max();
else print_interval(_arrel,k1,k2);
cout << "]";
}

template <typename Clau> 
void dicc<Clau>::print_interval(node* n,const Clau &k1, const Clau &k2) 
{
if(n!= nullptr)
{
print_interval(n->f_esq,k1,k2);
if(n->info == k2) cout << n->info;
else if(n->info >= k1 and n->info <= k2)cout << n->info << " ";
print_interval(n->f_dret,k1,k2);
}

}      

template <typename Clau>      
Clau dicc<Clau>::iessim(nat i) const
{
return iessim(_arrel,i);
}
template <typename Clau>      
Clau dicc<Clau>::iessim(node* n,nat i) 
{
Clau k;
if(n != nullptr)
{
	if(n->f_esq != nullptr)
	{
		if(n->f_esq->grandaria >= i )
		{
		k = iessim(n->f_esq,i);
		}
		else 
		{
		i = i - n->f_esq->grandaria;
		if(i == 1) return n->info;
		else k = iessim(n->f_dret,i - 1);
		
		}
	}
	else if(i == 1) return n->info;
	else if (n->f_dret != nullptr)k = iessim(n->f_dret,i - 1);
	else return n->info;
}
return k;
}
 
template <typename Clau>
typename dicc<Clau>::node*  dicc<Clau>::insereix(node* n,const Clau &k,bool &trobat)
{
if(n!= nullptr)
{
if(n->info > k)  n->f_esq = insereix(n->f_esq,k,trobat);
else if(n->info < k) n->f_dret = insereix(n->f_dret,k,trobat);
else if(n->info == k) trobat = true;
if(trobat == true) return n;
n->grandaria = n->grandaria + 1;
return n;
}
else
{
n = new node;
n->info = k;
n->f_esq = nullptr;
n->f_dret = nullptr;
n->grandaria = 1;
return n;
}
}

template <typename Clau>
void dicc<Clau>::insereix(const Clau &k)
{
  bool trobat = false;
  _arrel = insereix(_arrel,k,trobat);

}


template <typename Clau>
bool dicc<Clau>::consulta(node* n ,const Clau &k) 
{
bool trobat = false;
if(n!= nullptr)
{
 if(n->info == k) trobat = true;
 else 
 {
  trobat = consulta(n->f_esq,k);
  if(trobat == true) return trobat;
  trobat = consulta(n->f_dret,k);
 }
}
return trobat;

}

template <typename Clau>
bool dicc<Clau>::consulta(const Clau &k) const
{
bool trobat = false;
trobat = consulta(_arrel,k);
return trobat;
}

template <typename Clau>
Clau dicc<Clau>::min() const
{
return min(_arrel);
}

template <typename Clau>
Clau dicc<Clau>::min(node* n)
{
Clau k;
if(n->f_esq != nullptr)
{
k = min(n->f_esq);
return k;
}
return n->info;
}
template <typename Clau>
Clau dicc<Clau>::max() const
{
return max(_arrel);
}
template <typename Clau>
Clau dicc<Clau>::max(node* n)
{
Clau k;
if(n->f_dret != nullptr)
{
k = max(n->f_dret);
return k;
}
return n->info;
}
 
 
 
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  string linea, comanda;;
  int n, n1, n2;
  while (getline(cin, linea)) {
    dicc<int> d;

    // Obtenim elements 1er diccionari
    istringstream ss1(linea);
    while (ss1 >> n){
      d.insereix(n);
    }
    d.print(); cout << endl;

    // Processem comandes
    while (getline(cin, linea) and linea != "----------") {
      cout << linea << ": ";
      istringstream ss2(linea);
      ss2 >> comanda;

      if (comanda == "insereix") {
        ss2 >> n;
        d.insereix(n);
        cout << d.quants();

      } else if (comanda == "elimina") {
        ss2 >> n;
        d.elimina(n);
        cout << d.quants();

      } else if (comanda == "consulta") {
        ss2 >> n;
        cout << d.consulta(n);

      } else if (comanda == "quants") {
        cout << d.quants();

      } else if (comanda == "print") {
        d.print();

      } else if (comanda == "print_interval") {
        ss2 >> n1 >> n2;
        d.print_interval(n1, n2);

      } else if (comanda == "min") {
        cout << d.min();

      } else if (comanda == "max") {
        cout << d.max();

      } else if (comanda == "iessim") {
        ss2 >> n;
        cout << d.iessim(n);
      }
      cout<<endl;
    }
    if (linea == "----------")
      cout << linea << endl;
  }
}
