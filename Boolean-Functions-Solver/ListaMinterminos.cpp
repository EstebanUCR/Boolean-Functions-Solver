#include <iostream>
#include "ListaMinterminos.h"
using namespace std;

void ListaMinterminos :: agregarMintermino(Mintermino *m) {
    NodoMinterminos *temp = cabeza;
    NodoMinterminos *nuevo = new NodoMinterminos(m);
    if(temp == nullptr)
        cabeza = nuevo;
    else {
        while(temp -> getSiguiente() != nullptr)
            temp = temp -> getSiguiente();
        temp -> setSiguiente(nuevo);
    }
}

int ListaMinterminos :: longitud() {
    int cont = 0;
    NodoMinterminos *temp = cabeza;
    while(temp != nullptr) {
        cont++;
        temp = temp -> getSiguiente();
    }
        return cont;
}

void ListaMinterminos :: getValoresVerdad(bool arrayVerdades[]) {
    int i = 0;
    NodoMinterminos *temp = cabeza;
    while(temp != nullptr) {
        arrayVerdades[i] = temp -> getMintermino() -> getValorVerdad();
        temp = temp -> getSiguiente();
        i++;
    }
}