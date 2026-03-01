#include <cstdlib>
 #include <string>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class Arbre {
 
 public:
   // Construeix un Arbre format per un únic node que conté a x.
   Arbre(const T &x);
 
   // Tres grans.
   Arbre(const Arbre<T> &a);
   Arbre& operator=(const Arbre<T> &a);
   ~Arbre() throw();
 
   // Col·loca l’Arbre donat com a primer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
   void afegir_fill(Arbre<T> &a);
 
   // Imprimeix la informació dels nodes en preordre, cada element en una nova línia i
   // precedit per espais segons el nivell on està situat.
   void preordre() const;
 
   static const int ArbreInvalid = 400;
 
   // Modifica el contingut dels nodes per tal de guardar a cada node l’altura
   // del seu subarbre
   void arbre_altures();
 
 private:
   Arbre(): _arrel(NULL) {};
   struct node {
     T info;        // Informació del node
     node* primf;   // Punter al primer fill
     node* seggerm; // Punter al següent germà
   };
   node* _arrel; // Punter a l’arrel de l’arbre
   static node* copia_arbre(node* p);
   static void destrueix_arbre(node* p) throw();
   static void preordre(node *p, string pre);
 
   // Aquí va l’especificació dels mètodes privats addicionals
   // Aquí va l’especificació dels mètodes privats addicionals
   //Pre: p apunta a un subarbre del parametre implicit o apunta a nullptr
   //Post: Modifica el contingut dels nodes del subarbre apuntat per p per tal de guardar a cada node la suma dels
         //nodes dels seus fills. Els nodes fulla (els de grau 0) no es modifiquen.
   static void arbre_altures(node *p);
 };
 
 // Aquí va la implementació del mètode arbre_altures i privats addicionals
 
 
 
 // Modifica el contingut dels nodes per tal de guardar a cada node l’altura
   // del seu subarbre
   template <typename T>
 void Arbre<T>::arbre_altures(node *p)
 {
 if(p != nullptr){
       //arbre_altures(p->primf);
       //arbre_altures(p->seggerm);
       int alt(0);   //T suma = T.element_neutre();
       node *fill = p->primf;
       while(fill != nullptr){ //SOLUCIO HIBRIDA MITJA RECURSIVA Y MITJA ITERATIVA
       arbre_altures(fill);
       if(fill->info > alt) alt = fill->info;
       //alt = max(alt,fill->info);
       fill = fill->seggerm;
       }
       if(p->primf != nullptr) p->info = alt + 1;
       else p->info = 1;
     }
 
 }
 template <typename T>
  void Arbre<T>::arbre_altures() 
  {
       arbre_altures(_arrel);
  }
  
