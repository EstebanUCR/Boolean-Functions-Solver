#include <iostream>
#include <sstream>
#include "FuncionBooleana.h"
using namespace std;

void FuncionBooleana :: seleccionarMinterminos() {
    string formula;
    stringstream ssFormula(formulaFuncion);
    while(getline(ssFormula, formula, '+')) {
        Mintermino *m = new Mintermino(formula, introducidos);
        listaMinterminos -> agregarObjeto(m);
    }
}

void FuncionBooleana :: evaluar() {
    int i = 0;
    setValorVerdad(false);
    seleccionarMinterminos();
    int longitud = getListaMinterminos() -> longitud();
    bool valoresVerdadMinterminos[longitud];
    llenarValoresVerdadMinterminos(valoresVerdadMinterminos);
    while(i < longitud) {
        if(valoresVerdadMinterminos[i])
            setValorVerdad(true);
        i++;
    }
}

void FuncionBooleana :: llenarValoresVerdadMinterminos(bool array[]) {
    int i = 0;
    string formula;
    stringstream ssFormula(formulaFuncion);
    while(getline(ssFormula, formula, '+')) {
        Mintermino *m =  new Mintermino(formula, introducidos);
        listaMinterminos -> getNodo(formula) -> getObjeto() -> setValorVerdad(m -> evaluar());
        array[i] = listaMinterminos -> getNodo(formula) -> getObjeto() -> getValorVerdad();
        i++;
        listaMinterminos -> eliminarObjeto(0);
    }
}
