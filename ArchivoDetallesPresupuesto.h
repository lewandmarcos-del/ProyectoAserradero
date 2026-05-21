#ifndef ARCHIVODETALLESPRESUPUESTO_H_INCLUDED
#define ARCHIVODETALLESPRESUPUESTO_H_INCLUDED
#include "DetallesPresupuesto.h"

class ArchivoDetallesPresupuesto{
    private:
        char nombre[30];
    public:
        ArchivoDetallesPresupuesto(const char *n="DetallesPresupuesto.dat");
        DetallesPresupuesto leerRegistro(int);
        bool grabarRegistro(DetallesPresupuesto);
        bool modificarRegistro(DetallesPresupuesto, int);
        int contarRegistros();
        int buscarRegistro(int);
        bool verificarExistencia(const char*);
        int obtenerUltimoID();
};

#endif // ARCHIVODETALLESPRESUPUESTO_H_INCLUDED
