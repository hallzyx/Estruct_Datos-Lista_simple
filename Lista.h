#pragma once
#include "Nodo.h"
#include <functional>
#include <string>

typedef unsigned int uint;
template <class T>
class Lista {

private: 
    Nodo<T>* nodo;
    //typedef function<int(T, T)> Comp;
    Nodo<T>* ini;
    uint lon; // número de elementos en la lista

public:


    Lista() : ini(nullptr), lon(0) { nodo = new Nodo<T>(); }
    ~Lista();
    /*Lista() {
        nodo = new Nodo<T>();
    };*/
    Lista(Nodo<T>* pNodo) {
        nodo = pNodo;
    };
    uint longitud();
    bool esVacia();
    void agregaInicial(T elem);
    void agregaPos(T elem, uint pos);
    void agregaFinal(T elem);
    void modificarInicial(T elem);
    void modificarPos(T elem, uint pos);
    void modificarFinal(T elem);
    void eliminaInicial();
    void eliminaPos(uint pos);
    void eliminaFinal();
    T obtenerInicial();
    T obtenerPos(uint pos);
    T obtenerFinal();
    bool buscar(T elem);


    //~Lista(void);
    void agregar(T pNodo); //sumar nodos a la lista
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodo
    Lista* resto(void); //retorna el puntero al "resto" de la lista
    //resto= lo que queda de la lista sin la cabeza
    string toPrint(string p);
    T suma(T i);
    int size();
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    void addOrdenado(T d);// suma nodos ordenados de menor a mayor
    bool esta(T d); //retorna true cuando d est� en la lista
    void borrarDato(T d);// borra el nodo que contiene a d

};
template <class T>
uint Lista<T>::longitud() {
    return lon;
}
template <class T>
bool Lista<T>::esVacia() {
    return lon == 0;
}


//COMPLETADO!
template <class T>
void Lista<T>::agregaInicial(T elem) {

    /*
    Nodo<T>* nuevo = new Nodo<T>(elem);
    if (nuevo != nullptr) {
        ini = nuevo;
        lon++;
    }
    */
    Nodo<T>* nuevo = new Nodo<T>(elem);
    if (lon == 0) {
        this->ini = nuevo;
        lon++;
    }
    else {
        nuevo->sgte = this->ini;
        this->ini = nuevo;
        lon++;
    }
}
template <class T>

//COMPLETADO!
bool Lista<T>::buscar(T elem) {
    Nodo<T>* aux = ini;
    for (int i = 0; i < lon; i++) {
        if (aux->elem == elem) {
            return true;
        }
        aux = aux->sgte;
    }
    return false;
}

//COMPLEATADO!
template <class T>
void Lista<T>::agregaPos(T elem, uint pos) {

    Nodo<T>* nuevo = new Nodo<T>(elem);
    if (pos >= 0 && pos <= lon) {
        if (pos == 0) {
            agregaInicial(elem);
        }
        else if (pos == lon) {
            agregaFinal(elem);
        }
        else {
            Nodo<T>* aux = this->ini;

            for (int i = 0; i < pos-1; i++) {
                aux = aux->sgte;
            }
            Nodo<T>* aux2 = aux->sgte;
            aux->sgte = nuevo;
            nuevo->sgte = aux2;
            lon++;
        }
    }


    


    /*
     if (pos > lon) return;
    if (pos == 0) {
        agregaInicial(elem);
    }
    else {
        Nodo<T>* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        Nodo<T>* nuevo = new Nodo<T>(elem);
        nuevo->set_Sgte(aux->get_Sgte());
        if (nuevo != nullptr) {

            aux->set_Sgte(nuevo);
            lon++;
        }
    }
    */
   
}

//COMPLETADO!
template <class T>
void Lista<T>::agregaFinal(T elem) {
    Nodo<T>* nuevo = new Nodo<T>(elem);
   
    if (lon == 0) {
        this->ini = nuevo;
        lon++;
    }
    else {
        Nodo<T>* aux = this->ini;
        for (int i = 0; i < lon-1; i++) {
            aux = aux->sgte;
        };
        aux->sgte = nuevo;
        lon++;
    }
    
   
}

//COMPLETADO!
template <class T>
void Lista<T>::eliminaInicial() {
    
    /*
    if (lon > 0) {
        Nodo<T>* aux = ini;
        ini = ini->sgte;
        delete aux;
        lon--;
    }
    */

    if (lon > 0) {
        Nodo <T>* aux = this->ini;
        this->ini = this->ini->sgte;
        delete aux;
        lon--;
    }
    
    
}

//COMPLETADO!
template <class T>
void Lista<T>::eliminaPos(uint pos) {

    /*
    //if (pos <= lon && lon > 0) {
    Nodo<T>* aux = ini;
    Nodo<T>* aux2;
    for (int i = 0; i < pos; i++) {
        aux = aux->get_Sgte;
    }
    aux2 = aux->sgte;
    aux->get_Sgte = aux2->get_Sgte;
    delete aux2;
    lon--;
    //}
    */

    if (lon > 0 && pos < lon && pos>=0) {
        if (pos == 0) {
            eliminaInicial();
        }
        else if (pos == lon - 1) {
            eliminaFinal();
        }
        else {
            Nodo<T>* aux = this->ini;
            for (int i = 0; i < pos - 1; i++) {
                aux = aux->sgte;
            }
            Nodo<T>* aux2 = aux->sgte;
            aux->sgte = aux2->sgte;
            delete aux2;
            lon--;
        }
    }




    
}

//COMPLETADO!
template <class T>
void Lista<T>::eliminaFinal() {

    if (lon > 0) {
        Nodo<T>* aux = this->ini;
        for (int i = 0; i < lon - 2; i++) {
            aux = aux->sgte;
        }
        Nodo<T>* aux2 = aux->sgte;
        aux->sgte = nullptr;
        delete aux2;
        lon--;
    }
    

}

//COMPLETADO!
template <class T>
void Lista<T>::modificarInicial(T elem) {
    /*
    if (lon > 0) {
            ini->elem = elem;
    }
    */
    if (lon > 0) {
        this->ini->elem = elem;
    }
    
}
//COMPLETADO!
template <class T>
void Lista<T>::modificarPos(T elem, uint pos) {

    /*
    if (pos >= 0 && pos < lon) {
        Nodo<T>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sgte;
        }
        aux->elem = elem;
    }
    */
    if (pos >= 0 && pos < lon && lon > 0) {
        if (pos == 0) {
            modificarInicial(elem);
        }
        else if (pos == lon - 1) {
            modificarFinal(elem);
        }
        else {
            Nodo<T>* aux = this->ini;
            for (int i = 0; i < pos; i++) {
                aux = aux->sgte;
            }
            aux->elem = elem;
        }
    }
 
}

//COMPLETADO!
template <class T>
void Lista<T>::modificarFinal(T elem) {

    if (lon > 0) {
        Nodo<T>* aux = this->ini;
        for (int i = 0; i < lon - 1; i++) {
            aux = aux->sgte;
        }
        aux->elem = elem;
    }
}

//COMPLETADO!
template <class T>
T Lista<T>::obtenerInicial() {
    /*
    return obtenerPos(0);
    */
    if (lon > 0) {
        return this->ini->elem;
    }
    
}

//COMPLETADO!
template <class T>
T Lista<T>::obtenerPos(uint pos) {

    /*
     if (pos >= 0 && pos < lon) {
        Nodo<T>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        return aux->get_Elem();
    }
    else {
        return NULL;
    }
    */
   
    if (pos >= 0 && pos < lon && lon > 0) {
        if (pos == 0) {
            obtenerInicial();
        }
        else if (pos == lon - 1) {
            obtenerFinal();
        }
        else {
            Nodo<T>* aux = this->ini;
            for (int i = 0; i < pos; i++) {
                aux = aux->sgte;
            }
            return aux->elem;
        }
    }


}

//COMPLETADO!
template <class T>
T Lista<T>::obtenerFinal() {

    /*
    return obtenerPos(lon - 1);
    */
    if (lon > 0) {
        Nodo<T>* aux = this->ini;
        for (int i = 0; i < lon - 1; i++) {
            aux = aux->sgte;
        }
        return aux->elem;
    }
    
}

//COMPLETADO!
template <class T>
void Lista<T>::agregar(T d) //100
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->set_Sgte(nodo);
    nodo = nuevo;
}




