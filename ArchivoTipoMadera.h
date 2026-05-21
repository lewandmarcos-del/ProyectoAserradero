#ifndef ARCHIVOTIPOMADERA_H_INCLUDED
#define ARCHIVOTIPOMADERA_H_INCLUDED
#include "TipoMadera.h"

class ArchivoTipoMadera{
    private:
        char nombre[30];
    public:
        ArchivoTipoMadera(const char *n="TipoMadera.dat");
        TipoMadera leerRegistro(int);
        bool grabarRegistro(TipoMadera);
        bool modificarRegistro(TipoMadera, int);
        int contarRegistros();
        int buscarRegistro(int);
        bool verificarExistencia(const char*);
        int obtenerUltimoID();
};

#endif // ARCHIVOTIPOMADERA_H_INCLUDED
