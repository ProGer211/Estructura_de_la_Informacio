 #include <cstddef>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class deque {
   public:
     deque();
     // Pre: True
     // Post: El p.i. és una deque buida.
 
     deque(const deque &dq);
     // Pre: True
     // Post: El p.i. conté una còpia de dq.
 
     ~deque();
     // Post: Destrueix els elements del p.i.
 
     nat size() const;
     // Pre: True
     // Post: Retorna el nombre d’elements de la deque.
 
     bool empty() const;
     // Pre: True
     // Post: Retorna true si la deque és buida; false en cas contrari.
 
     T front() const;
     // Pre: La deque no és buida.
     // Post: Retorna el primer element de la deque.
 
     T rear() const;
     // Pre: La deque no és buida.
     // Post: Retorna l’últim element de la deque.
 
     void push(T e);
     // Pre: True
     // Post: Insereix un element al davant de la deque.
 
     void inject(T e);
     // Pre: True
     // Post: Insereix un element al darrera de la deque.
 
     void pop();
     // Pre: La deque no és buida.
     // Post: Elimina el primer element de la deque.
 
     void eject();
     // Pre: La deque no és buida.
     // Post: Elimina l’últim element de la deque.
 
   private:
   /* Double-ended queue implementada amb una llista doblement encadenada,
      sense fantasma i no circular. */
     struct node {
       T info;    // Informació del node
       node *seg; // Punter al següent element
       node *ant; // Punter a l’anterior element
     };
     node *_prim; // Punter al primer element
     node *_ult;  // Punter a l’últim element
     nat _long;   // Nombre d’elements
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Pre: True
 // Post: Insereix un element al davant de la deque.
 template <typename T>
 void deque<T>::push(T e){
 node *pnou = new node;
 pnou->info = e;
 pnou->seg =_prim;
 pnou->ant = nullptr;
 if(_prim == nullptr)_prim->ant = pnou;
 else _ult = pnou;
 _prim = pnou;
 _long++;
 }
 
 // Pre: True
 // Post: Insereix un element al darrera de la deque.
 template<typename T>
 void deque<T>::inject(T e){
  node *pnou = new node;
 pnou->info = e;
 if(_prim == nullptr)
 {
 _prim = pnou;
 _ult = pnou;
 pnou->seg = nullptr;
 }
 else
 {
  pnou->ant = _ult;
 _ult->seg = pnou;
 pnou->seg = nullptr;
 _ult = pnou;
 }
 _long++;
 }
 
 
 // Pre: La deque no és buida.
 // Post: Elimina el primer element de la deque.    
 template<typename T>
 void deque<T>::pop()
 {
 if(_prim != _ult) _prim->seg->ant = nullptr;
 else _ult = nullptr;
 node *pelim =_prim;
 _prim = _prim->seg;
 delete pelim; 
 _long--;

 
 
 }
     
     
     
     
 // Pre: La deque no és buida.
     // Post: Elimina l’últim element de la deque.
      template<typename T>
     void deque<T>::eject()
     {
     if(_long == 0) return;
     node *pelim(_ult);
     _ult = _ult->ant;
     delete pelim;     
     }

 
