#include "abin.hpp"
#include <iostream>

template <typename T>
 list<T> Abin<T>::preordre(node *p)  //sense utilitzar recursivitat i estructures de dades adiccionals.
 {
 list<T> l;
 while(p != nullptr)
 {
 l.push_back(p->info);
 if(p->f_esq !=nullptr) p=p->f_esq;
 else if(p->f_dret != nullptr)p=p->f_dret;
 else if(p->thread_dret == true && p->f_dret != nullptr) p = p->f_dret;
 } 
 return l;
 }
 template <typename T>
 list<T> Abin<T>::preordre() const
 {
 return preordre(_arrel);
 
 }
