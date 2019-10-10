//
// Created by lica-pc on 10/10/19.
//

#ifndef CS1103_PC2_201902_NODO_H
#define CS1103_PC2_201902_NODO_H

template <typename T>
struct Nodo {
    T dato;
    Nodo* next;
    Nodo()= default;
    Nodo(T dato);
};

template<typename T>
Nodo<T>::Nodo(T dato): dato(dato){
    next = nullptr;
}


#endif //CS1103_PC2_201902_NODO_H
