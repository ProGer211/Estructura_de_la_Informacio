#include <vector>
#include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 class graf {
   // Graf dirigit i no etiquetat.
   // Les arestes es guarden en multillistes d’adjacència en memòria dinàmica.
   public:
     // Constructora per defecte. Crea un graf buit de n vèrtexs.
     graf(nat n);
 
     // Destructora
     ~graf();
 
     // Retorna un vector amb els successors del vèrtex v
     vector<nat> successors(nat v) const;
 
     // Retorna un vector amb els predecessors del vèrtex v
     vector<nat> predecessors(nat v) const;
 
     void insereix(nat orig, nat dest);
     // Pre: orig i dest són menors que el número de vèrtexs
     // Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
           // Si l’aresta ja existia no fa res.
 
   private:
     nat nv; // Nombre de vèrtexs
     struct node {
       nat orig; // Vèrtex origen 
       nat dest; // Vèrtex destí 
       node *seg_succ; // Punter al següent successor
       node *seg_pred; // Punter al següent predecessor
     };
     vector<node *> prim_succ; // Punters al primer successor de cada vèrtex.
                               // La llista de successors està ordenada.
     vector<node *> prim_pred; // Punters al primer predecessor de cada vèrtex.
                               // La llista de predecessors està ordenada.
 
     // Aquí va l’especificació dels mètodes privats addicionals
     void insereix(node* &p1,node* &p2,nat orig,nat dest);
     
 };
 
 // Aquí va la implementació del mètode públic insereix i privats addicionals
 void graf::insereix(nat orig, nat dest)
 {
 node* comp = prim_succ[orig];
 while(comp != nullptr)
 {
 if(comp->dest == dest) return;
 comp = comp->seg_succ;
 }
 insereix(prim_succ[orig],prim_pred[dest],orig,dest);
 }
 
 void graf::insereix(node* &p1,node* &p2,nat orig,nat dest)
 {
 node* prev1 = nullptr;
 node* prev2 = nullptr;
 
 node* current1 = p1;
 node* current2 = p2;
 while(current1 != nullptr && current1->dest < dest)
 {
 prev1 = current1;
 current1 = current1->seg_succ;
 }
 while(current2 != nullptr && current2->orig < orig)
 {
 prev2 = current2;
 current2 = current2->seg_pred;
 }
 node *nou = new node;
 nou->orig = orig;
 nou->dest = dest;
 if(prev1 == nullptr)
 {
 nou->seg_succ = p1;
 p1 = nou;
 }
 else
 {
 prev1->seg_succ = nou;
 nou->seg_succ = current1;
 }
 if(prev2 == nullptr)
 {
 nou->seg_pred = p2;
 p2 = nou;
 }
 else
 {
 prev2->seg_pred = nou;
 nou->seg_pred = current2;
 
 }
 }

 
 
 
