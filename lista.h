//
// Created by rudri on 10/10/2019.
//

#ifndef CS1103_PC2_201902_HEAP_H
#define CS1103_PC2_201902_HEAP_H

#include "nodo.h"

using namespace std;

template <typename T>
class Lista {
private:
    int size;
    T* top;
public:

    Lista() {
        size = 0;
        top = nullptr;
    }

    ~Lista()= default;

    template<typename param>
    void insert(param nodo){
        auto *nuevoNodo = new T(nodo);
        nuevoNodo->next=this->top;
        this->top=nuevoNodo;
        size++;
    }

    //void push_back(T*);

    void clear(){
        auto aux = this->top;
        if(this->top!= nullptr)
        {
            this->top = top->next;
            size--;
        }
    }


    T* pop_front()
    {
        auto aux = this->top;
        if(this->top!= nullptr)
        {
            this->top = top->next;
            size--;
        }
        return aux;
    }

    T* pop_back()
    {
        auto aux = this->top;
        if(this->top!= nullptr)
        {
            this->top = top->next;
            size--;
        }
        return aux;
    }

    T* front() const
    {
        return top;
    }

    T* back() const
    {
        auto aux = top;
        while(aux->next != nullptr)
            aux = aux->next;
        return aux;
    }

    int Size() const
    {
        return this->size;
    }


    bool isEmpty()
    {
        return size==0;
    }

    T* operator[](int index)
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

};



/*template <typename T, typename ...param>
void Lista<T,param...>::insert_v(param&&... nodos)
{
    for(int i = 0; i<sizeof...(nodos); i++)
    auto *nuevoNodo = new T(nodo);
    nuevoNodo->next=this->top;
    this->top=nuevoNodo;
    size++;
}*/





#endif //CS1103_PC2_201902_HEAP_H
