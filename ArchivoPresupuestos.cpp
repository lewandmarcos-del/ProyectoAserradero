#include <iostream>
#include <cstring>
#include "ArchivoPresupuestos.h"
using namespace std;

//----------CONSTRUCTOR REPO--------------------------

ArchivoPresupuestos::ArchivoPresupuestos(const char *n)
{
    strcpy(nombre, n);
}

//----------LEER--------------------------
Presupuesto ArchivoPresupuestos::leerRegistro(int pos)
{
    Presupuesto obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) {
        obj.setIdDetallePresupuesto(-2);
        return obj;
    }
    fseek(p, pos * sizeof(obj), 0);
    size_t leidos = fread(&obj, sizeof(obj), 1, p);
    fclose(p);
    if(leidos != 1) {
        obj.setIdPresupuesto(-1);
    }
    return obj;
}

//----------GRABAR--------------------------
bool ArchivoPresupuestos::grabarRegistro(Presupuesto obj)
{
    int nuevoId = obtenerUltimoID() + 1;
    obj.setIdPresupuesto(nuevoId);

    FILE *p = fopen(nombre, "ab");
    if(p == nullptr) {
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(obj), 1, p);
    fclose(p);
    return escribio;
}

//----------MODIFICAR--------------------------

bool ArchivoPresupuestos::modificarRegistro(Presupuesto obj, int pos)
{

    int cantReg = contarRegistros();
    if(pos < 0 || pos >= cantReg) {
        return false;
    }

    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr) {
        return false;
    }

    fseek(p, pos * sizeof(Presupuesto), 0);
    bool escribio = fwrite(&obj, sizeof(Presupuesto), 1, p);
    fclose(p);
    return escribio;
}

//----------CONTAR REGISTROS--------------------------
int ArchivoPresupuestos::contarRegistros()
{
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) {
        return 0;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Presupuesto);
}


//----------BUSCAR REGISTROS POR ID--------------------------
int ArchivoPresupuestos::buscarRegistro(int Id)
{
    Presupuesto obj;
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++) {
        obj = leerRegistro(i);
        if(obj.getIdPresupuesto() == Id) {
            return i;
        }
    }
    return -1;
}

//----------OBTENER ULTIMO ID--------------------------

int ArchivoPresupuestos::obtenerUltimoID()
{
    int cantReg = contarRegistros();
    if (cantReg == 0) {
        return 0;
    }

    Presupuesto obj = leerRegistro(cantReg - 1);
    int ultimoID = obj.getIdPresupuesto();
    if(ultimoID <= 0) {
        return 0; // Si el ultimo ID es 0 o negativo, empezamos desde 1
    }
    return obj.getIdPresupuesto();
}
