#ifndef DLLBITACORA_H
#define DLLBITACORA_H
#include "DLLBitacora_global.h"
using namespace std;

class DLLBITACORA_EXPORT DLLBitacora
{
public:
    DLLBitacora();
    void agregarBitacora(QString nombreArchivo, QString contenido);
};

#endif // DLLBITACORA_H
