//
// Created by rudri on 10/10/2019.
//

#ifndef CS1103_PC2_201902_HEAP_H
#define CS1103_PC2_201902_HEAP_H

#include "nodo.h"

using namespace std;

template <typename T, typename param>
class Lista {
private:
    int size;
    T* top;
public:
    Lista();
    ~Lista()= default;

    void insert(param);
    //void insert_v(param&&...);
    //void push_back(T*);

    void clear();

    T* pop_front();
    T* pop_back();

    T *front() const;
    T *back() const;

    int Size() const ;
    bool isEmpty();
    T*operator[](int index);

};


template<typename T, typename param>
Lista<T, param>::Lista() {
    size = 0;
    top = nullptr;
}

template<typename T, typename param>
void Lista<T, param>::clear()
{
    auto aux = this->top;
    if(this->top!= nullptr)
    {
        this->top = top->next;
        size--;
    }
}


template <typename T, typename param>
void Lista<T, param>::insert(param nodo)
{
    auto *nuevoNodo = new T(nodo);
    nuevoNodo->next=this->top;
    this->top=nuevoNodo;
    size++;
}


/*template <typename T, typename ...param>
void Lista<T,param...>::insert_v(param&&... nodos)
{
    for(int i = 0; i<sizeof...(nodos); i++)
    auto *nuevoNodo = new T(nodo);
    nuevoNodo->next=this->top;
    this->top=nuevoNodo;
    size++;
}*/


template <typename T, typename param>
T*Lista<T, param>::pop_front()
{
    auto aux = this->top;
    if(this->top!= nullptr)
    {
        this->top = top->next;
        size--;
    }
    return aux;
}

template <typename T, typename param>
T*Lista<T,param>::pop_back()
{
    auto aux = this->top;
    if(this->top!= nullptr)
    {
        this->top = top->next;
        size--;
    }
    return aux;
}


template <typename T, typename param>
T*Lista<T,param>::front() const
{
    return top;
}

template <typename T, typename param>
T*Lista<T,param>::back() const
{
    auto aux = top;
    while(aux->next != nullptr)
        aux = aux->next;
    return aux;
}


template <typename T, typename param>
int Lista<T,param>::Size() const
{
    return this->size;
}

template <typename T, typename param>
bool Lista<T,param>::isEmpty()
{
    return size==0;
}

template <typename T, typename param>
T* Lista<T,param>::operator[](int index)
{
    if(index<size)
    {
        auto elemento_indexado=top;
        for(int i=0;i<index;i++)
        {
            elemento_indexado=elemento_indexado->next;
        }
        return elemento_indexado;
    }
    throw  out_of_range("El indice no existe");
}



#endif //CS1103_PC2_201902_HEAP_H
