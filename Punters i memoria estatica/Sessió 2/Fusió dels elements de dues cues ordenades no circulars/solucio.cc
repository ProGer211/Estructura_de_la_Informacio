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
   
