#include <iostream>
#include <cstring>
#include "ArchivoMaderas.h"
using namespace std;

//----------CONSTRUCTOR REPO--------------------------

ArchivoMaderas::ArchivoMaderas(const char *n)
{
    strcpy(nombre, n);
}

//----------LEER--------------------------
Madera ArchivoMaderas::leerRegistro(int pos)
{
    Madera obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) {
        obj.setIdDetallePresupuesto(-2);
        return obj;
    }
    fseek(p, pos * sizeof(obj), 0);
    size_t leidos = fread(&obj, sizeof(obj), 1, p);
    fclose(p);
    if(leidos != 1) {
        obj.setIdMadera(-1);
    }
    return obj;
}

//----------GRABAR--------------------------
bool ArchivoMaderas::grabarRegistro(Madera obj)
{
    int nuevoId = obtenerUltimoID() + 1;
    obj.setIdMadera(nuevoId);

    FILE *p = fopen(nombre, "ab");
    if(p == nullptr) {
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(obj), 1, p);
    fclose(p);
    return escribio;
}

//----------MODIFICAR--------------------------

bool ArchivoMaderas::modificarRegistro(Madera obj, int pos)
{

    int cantReg = contarRegistros();
    if(pos < 0 || pos >= cantReg) {
        return false;
    }

    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr) {
        return false;
    }

    fseek(p, pos * sizeof(Madera), 0);
    bool escribio = fwrite(&obj, sizeof(Madera), 1, p);
    fclose(p);
    return escribio;
}

//----------CONTAR REGISTROS--------------------------
int ArchivoMaderas::contarRegistros()
{
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) {
        return 0;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Madera);
}


//----------BUSCAR REGISTROS POR ID--------------------------
int ArchivoMaderas::buscarRegistro(int Id)
{
    Madera obj;
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++) {
        obj = leerRegistro(i);
        if(obj.getIdMadera() == Id) {
            return i;
        }
    }
    return -1;
}

//----------OBTENER ULTIMO ID--------------------------

int ArchivoMaderas::obtenerUltimoID()
{
    int cantReg = contarRegistros();
    if (cantReg == 0) {
        return 0;
    }

    Madera obj = leerRegistro(cantReg - 1);
    int ultimoID = obj.getIdMadera();
    if(ultimoID <= 0) {
        return 0; // Si el ultimo ID es 0 o negativo, empezamos desde 1
    }
    return obj.getIdMadera();
}
