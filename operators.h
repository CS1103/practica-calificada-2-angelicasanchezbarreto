//
// Created by lica-pc on 10/10/19.
//

#ifndef CS1103_PC2_201902_OPERATORS_H
#define CS1103_PC2_201902_OPERATORS_H


template<typename param>
void load_from(const string & file_name, Lista<Nodo<param>> & lista)
{
    if(lista.isEmpty())
    {
    fstream file_lista(file_name,ios::in);
    if(!file_lista.is_open()){
        cout << "ERROR"<<endl;
    }

    if(file_lista.is_open()){
        param num;
        while(file_lista>>num){
            //cout<<num<<endl;
            lista.insert(num);
        }
    }

    file_lista.close();
    }
    else{
        lista.clear();
        load_from(file_name,lista);
    }
}


template <typename param>
ostream& operator<< (ostream& out, Lista<Nodo<param>> lista)
{
    auto aux = lista.front();
    for(int i=0; i< lista.Size(); i++)
    {
        out << aux->dato <<endl;
        if(aux->next != nullptr)
            aux = aux->next;
    }
    return out;
}

template <typename T>
istream& operator>> (istream& in, Lista<Nodo<T>> lista)
{
    cout << "Ingresa un valor: ";
    T a;
    in >> a;
    //auto n1 = new Nodo<param>(a);

    //a = n1->dato;
    lista.insert(a);
    return in;
}


template<typename... param, typename params>
void insert(Lista<Nodo<params>> lista, params item, param&&...nodos) {
    //for (auto nodo:{nodos...})
        lista.insert(nodos...);

}



#endif //CS1103_PC2_201902_OPERATORS_H
