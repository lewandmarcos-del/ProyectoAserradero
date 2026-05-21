#include <iostream>
#include <cstring>
#include "ArchivoClientes.h"
using namespace std;

//----------CONSTRUCTOR REPO--------------------------

ArchivoClientes::ArchivoClientes(const char *n)
{
    strcpy(nombre, n);
}


//----------LEER--------------------------
Clientes ArchivoClientes::leerRegistro(int pos)
{
    Clientes obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) {
        obj.setIdCliente(-2);
        return obj;
    }
    fseek(p, pos * sizeof(obj), 0);
    size_t leidos = fread(&obj, sizeof(obj), 1, p);
    fclose(p);
    if(leidos != 1) {
        obj.setIdCliente(-1);
    }
    return obj;
}

//----------GRABAR--------------------------
bool ArchivoClientes::grabarRegistro(Clientes obj)
{
    if (verificarExistencia(obj.getNombreCliente())) {
        cout << endl;
        cout << "-------------------------------------------------------------" << endl << endl;
        cout << "ERROR, el Cliente con nombre <--" << obj.getNombreCliente() << "--> ya fue previamente registrado." << endl << endl;
        cout << "-------------------------------------------------------------" << endl;
        return false;
    }
    int nuevoId = obtenerUltimoID() + 1;
    obj.setIdCliente(nuevoId);

    FILE *p = fopen(nombre, "ab");
    if(p == nullptr) {
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(obj), 1, p);
    fclose(p);
    return escribio;
}

//----------MODIFICAR--------------------------

bool ArchivoClientes::modificarRegistro(Clientes obj, int pos)
{

    int cantReg = contarRegistros();
    if(pos < 0 || pos >= cantReg) {
        return false;
    }

    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr) {
        return false;
    }

    fseek(p, pos * sizeof(Clientes), 0);
    bool escribio = fwrite(&obj, sizeof(Clientes), 1, p);
    fclose(p);
    return escribio;
}

//----------CONTAR REGISTROS--------------------------
int ArchivoClientes::contarRegistros()
{
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) {
        return 0;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Clientes);
}


//----------BUSCAR REGISTROS POR ID--------------------------
int ArchivoClientes::buscarRegistro(int Id)
{
    Clientes obj;
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++) {
        obj = leerRegistro(i);
        if(obj.getIdCliente() == Id) {
            return i;
        }
    }
    return -1;
}

//----------VERIFICAR EXISTENCIA--------------------------

bool ArchivoClientes::verificarExistencia(const char* nombreBuscado)
{
    Clientes obj;
    int cantReg = contarRegistros();

    for (int i = 0; i < cantReg; i++) {
        obj = leerRegistro(i);

        // Si el nombre coincide (sin importar mayusculas/minusculas)
        if (_stricmp(obj.getNombreCliente(), nombreBuscado) == 0) {
            return true;
        }
    }

    return false;
}

//----------OBTENER ULTIMO ID--------------------------

int ArchivoClientes::obtenerUltimoID()
{
    int cantReg = contarRegistros();
    if (cantReg == 0) {
        return 0;
    }

    Clientes obj = leerRegistro(cantReg - 1);
    int ultimoID = obj.getIdCliente();
    if(ultimoID <= 0) {
        return 0; // Si el último ID es 0 o negativo, empezamos desde 1
    }
    return obj.getIdCliente();
}
