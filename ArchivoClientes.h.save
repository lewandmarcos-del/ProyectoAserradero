#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED

#include "Clientes.h"

class ArchivoClientes{
    private:
        char nombre[30];
    public:
        ArchivoClientes(const char *n="Clientes.dat");
        Clientes leerRegistro(int);
        bool grabarRegistro(Clientes);
        bool modificarRegistro(Clientes, int);
        int contarRegistros();
        int buscarRegistro(int);
        bool verificarExistencia(const char*);
        int obtenerUltimoID();
};

#endif // ARCHIVOCLIENTES_H_INCLUDED
