#include <iostream>
#include <cstring>
#include "ArchivoTipoMadera.h"
using namespace std;

//----------CONSTRUCTOR REPO--------------------------

ArchivoTipoMadera::ArchivoTipoMadera(const char *n)
{
    strcpy(nombre, n);
}

//----------LEER--------------------------
TipoMadera ArchivoTipoMadera::leerRegistro(int pos)
{
    TipoMadera obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) {
        obj.setIdDetalleTipoMadera(-2);
        return obj;
    }
    fseek(p, pos * sizeof(obj), 0);
    size_t leidos = fread(&obj, sizeof(obj), 1, p);
    fclose(p);
    if(leidos != 1) {
        obj.setIdTipoMadera(-1);
    }
    return obj;
}

//----------GRABAR--------------------------
bool ArchivoTipoMadera::grabarRegistro(TipoMadera obj)
{
    int nuevoId = obtenerUltimoID() + 1;
    obj.setIdTipoMadera(nuevoId);

    FILE *p = fopen(nombre, "ab");
    if(p == nullptr) {
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(obj), 1, p);
    fclose(p);
    return escribio;
}

//----------MODIFICAR--------------------------

bool ArchivoTipoMadera::modificarRegistro(TipoMadera obj, int pos)
{

    int cantReg = contarRegistros();
    if(pos < 0 || pos >= cantReg) {
        return false;
    }

    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr) {
        return false;
    }

    fseek(p, pos * sizeof(TipoMadera), 0);
    bool escribio = fwrite(&obj, sizeof(TipoMadera), 1, p);
    fclose(p);
    return escribio;
}

//----------CONTAR REGISTROS--------------------------
int ArchivoTipoMadera::contarRegistros()
{
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) {
        return 0;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (TipoMadera);
}


//----------BUSCAR REGISTROS POR ID--------------------------
int ArchivoTipoMadera::buscarRegistro(int Id)
{
    TipoMadera obj;
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++) {
        obj = leerRegistro(i);
        if(obj.getIdTipoMadera() == Id) {
            return i;
        }
    }
    return -1;
}

//----------OBTENER ULTIMO ID--------------------------

int ArchivoTipoMadera::obtenerUltimoID()
{
    int cantReg = contarRegistros();
    if (cantReg == 0) {
        return 0;
    }

    TipoMadera obj = leerRegistro(cantReg - 1);
    int ultimoID = obj.getIdTipoMadera();
    if(ultimoID <= 0) {
        return 0; // Si el ultimo ID es 0 o negativo, empezamos desde 1
    }
    return obj.getIdTipoMadera();
}
