//
// Created by lica-pc on 10/10/19.
//

#ifndef CS1103_PC2_201902_OPERATORS_H
#define CS1103_PC2_201902_OPERATORS_H


template<typename T,typename param>
void load_from(const string & file_name, Lista<T,param> & lista)
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
        lista.vaciar();
    }
}


template <typename param>
ostream& operator<< (ostream& out, Lista<Nodo<param>,param> lista) {
    auto aux = lista.front();
    for(int i=0; i< lista.Size(); i++)
    {
        out << aux->dato <<endl;
        if(aux->next != nullptr)
            aux = aux->next;
    }
    return out;
}

template <typename T, typename param>
istream& operator>> (ostream& out, Lista<T,param> lista);


#endif //CS1103_PC2_201902_OPERATORS_H
