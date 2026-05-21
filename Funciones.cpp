#include <iostream>
#include <cstdlib>
#include "funciones.h"

#include "ArchivoClientes.h"
#include "ArchivoDetallesPresupuesto.h"
#include "ArchivoMaderas.h"
#include "ArchivoPresupuestos.h"
#include "ArchivoTipoMadera.h"
#include "Fecha.h"
#include "Medidas.h"
#include "Direccion.h"
using namespace std;


// ============================================================
//                         MENÚ MARCAS
// ============================================================

// Menú principal de Marcas
void menuMarcas()
{
    int opcion;

    do
    {
        cout << "-------------------" << endl;
        cout << "Menu Marcas" << endl;
        cout << "-------------------" << endl;
        cout << "1 - Cargar Marcas" << endl;
        cout << "2 - Mostrar Marcas" << endl;
        cout << "3 - Modificar" << endl;
        cout << "4 - Marcas Activas (Desactivar)" << endl;
        cout << "5 - Marcas Inactivas (Activar)" << endl;
        cout << "0 - Volver" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            cargarMarca();
            system("pause");
            system("cls");
            break;
        case 2:
            mostrarMarcas();
            system("pause");
            system("cls");
            break;
        case 3:
            menuModificarMarca();
            system("pause");
            system("cls");
            break;
        case 4:
            desactivarMarca();
            system("pause");
            system("cls");
            break;
        case 5:
            activarMarca();
            system("pause");
            system("cls");
            break;
        case 0:
            break;

        default:
            cout << "!OPCION INCORRECTA!" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while (opcion != 0);
}

// Submenú de Modificar Marca
void menuModificarMarca()
{
    int opcion;

    do
    {
        cout << "-------------------" << endl;
        cout << "Modificar Marca" << endl;
        cout << "-------------------" << endl;
        cout << "1 - Nombre" << endl;
        cout << "0 - Volver" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            modificarNombreMarca();
            system("pause");
            system("cls");
            break;
        case 0:
            break;

        default:
            cout << "!OPCION INCORRECTA!" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while (opcion != 0);
}


// ---------------- FUNCIONES PUENTE (Marcas) ----------------

// Carga marcas en bucle hasta ingresar "0"
void cargarMarca()
{
    ArchivoMarca arch;
    arch.cargarMarcas();
}

// Lista todas las marcas
void mostrarMarcas()
{
    ArchivoMarca arch;
    arch.listarMarcas();
}

// Modifica el nombre de una marca por ID
void modificarNombreMarca()
{
    ArchivoMarca arch;

    arch.listarMarcas();
    cout << endl;

    int id;
    cout << "Ingrese ID de la marca a modificar (0 para volver): ";
    cin >> id;

    if (id == 0) return;

    if (arch.modificarNombrePorId(id))
        cout << "Nombre modificado correctamente." << endl;
    else
        cout << "No se encontro el ID o no se pudo modificar." << endl;
}

// Activa una marca mostrando primero las inactivas
void activarMarca()
{
    ArchivoMarca arch;

    cout << "=== MARCAS INACTIVAS ===" << endl;
    arch.listarInactivas();
    cout << endl;

    int id;

    while (true)
    {
        cout << "Ingrese ID de la marca a ACTIVAR (0 para volver): ";
        cin >> id;

        if (id == 0) return;

        if (arch.activarPorId(id))
        {
            cout << "Marca activada correctamente." << endl;
            break;
        }
        else
        {
            cout << "ID invalido o no se pudo activar. Intente nuevamente." << endl;
            cout << endl;
        }
    }
}

// Desactiva una marca mostrando primero las activas
void desactivarMarca()
{
    ArchivoMarca arch;

    cout << "=== MARCAS ACTIVAS ===" << endl;
    arch.listarActivas();
    cout << endl;

    int id;

    while (true)
    {
        cout << "Ingrese ID de la marca a DESACTIVAR (0 para volver): ";
        cin >> id;

        if (id == 0) return;

        if (arch.desactivarPorId(id))
        {
            cout << "Marca desactivada correctamente." << endl;
            break;
        }
        else
        {
            cout << "ID invalido o no se pudo desactivar. Intente nuevamente." << endl;
            cout << endl;
        }
    }
}


// ============================================================
//                        MENÚ PRODUCTOS
// ============================================================

// Menú principal de Productos
void menuProductos()
{
    int opcion;

    do
    {
        cout << "-------------------" << endl;
        cout << "Menu Productos" << endl;
        cout << "-------------------" << endl;
        cout << "1 - Cargar Productos" << endl;
        cout << "2 - Mostrar Productos" << endl;
        cout << "3 - Modificar" << endl;
        cout << "4 - Productos Activos (Desactivar)" << endl;
        cout << "5 - Productos Inactivos (Activar)" << endl;
        cout << "0 - Volver" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            cargarProducto();
            system("pause");
            system("cls");
            break;

        case 2:
            mostrarProductos();
            system("pause");
            system("cls");
            break;

        case 3:
            menuModificarProducto();
            system("pause");
            system("cls");
            break;

        case 4:
            desactivarProducto();
            system("pause");
            system("cls");
            break;

        case 5:
            activarProducto();
            system("pause");
            system("cls");
            break;

        case 0:
            break;

        default:
            cout << "!OPCION INCORRECTA!" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while (opcion != 0);
}

// Submenú de Modificar Producto
void menuModificarProducto()
{
    int opcion;

    do
    {
        cout << "-------------------" << endl;
        cout << "Modificar Producto" << endl;
        cout << "-------------------" << endl;
        cout << "1 - Nombre" << endl;
        cout << "2 - Descripcion" << endl;
        cout << "3 - Marca (ID Marca)" << endl;
        cout << "4 - Stock" << endl;
        cout << "5 - Precio de compra" << endl;
        cout << "6 - Precio de venta" << endl;
        cout << "0 - Volver" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            modificarNombreProducto();
            system("pause");
            system("cls");
            break;

        case 2:
            modificarDescripcionProducto();
            system("pause");
            system("cls");
            break;

        case 3:
            modificarMarcaProducto();
            system("pause");
            system("cls");
            break;

        case 4:
            modificarStockProducto();
            system("pause");
            system("cls");
            break;

        case 5:
            modificarPrecioCompraProducto();
            system("pause");
            system("cls");
            break;

        case 6:
            modificarPrecioVentaProducto();
            system("pause");
            system("cls");
            break;

        case 0:
            break;

        default:
            cout << "!OPCION INCORRECTA!" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while (opcion != 0);
}


// ---------------- FUNCIONES PUENTE (Productos) ----------------

// Alta de productos
void cargarProducto()
{
    ArchivoProducto arch;
    arch.cargarProductos();
}

// Listado general de productos
void mostrarProductos()
{
    ArchivoProducto arch;
    arch.listarProductos();
}

// Modificar nombre por ID
void modificarNombreProducto()
{
    ArchivoProducto arch;

    arch.listarProductos();
    cout << endl;

    int id;
    cout << "Ingrese ID del producto a modificar (0 para volver): ";
    cin >> id;

    if (id == 0) return;

    if (arch.modificarNombrePorId(id))
        cout << "Nombre modificado correctamente." << endl;
    else
        cout << "No se encontro el ID o no se pudo modificar." << endl;
}

// Modificar descripción por ID
void modificarDescripcionProducto()
{
    ArchivoProducto arch;

    arch.listarProductos();
    cout << endl;

    int id;
    cout << "Ingrese ID del producto a modificar (0 para volver): ";
    cin >> id;

    if (id == 0) return;

    if (arch.modificarDescripcionPorId(id))
        cout << "Descripcion modificada correctamente." << endl;
    else
        cout << "No se encontro el ID o no se pudo modificar." << endl;
}

// Modificar marca (ID Marca) por ID
void modificarMarcaProducto()
{
    ArchivoProducto arch;

    arch.listarProductos();
    cout << endl;

    int id;
    cout << "Ingrese ID del producto a modificar (0 para volver): ";
    cin >> id;

    if (id == 0) return;

    if (arch.modificarMarcaPorId(id))
        cout << "Marca modificada correctamente." << endl;
    else
        cout << "No se encontro el ID o no se pudo modificar." << endl;
}

// Modificar stock por ID
void modificarStockProducto()
{
    ArchivoProducto arch;

    arch.listarProductos();
    cout << endl;

    int id;
    cout << "Ingrese ID del producto a modificar (0 para volver): ";
    cin >> id;

    if (id == 0) return;

    if (arch.modificarStockPorId(id))
        cout << "Stock modificado correctamente." << endl;
    else
        cout << "No se encontro el ID o no se pudo modificar." << endl;
}

// Modificar precio compra por ID
void modificarPrecioCompraProducto()
{
    ArchivoProducto arch;

    arch.listarProductos();
    cout << endl;

    int id;
    cout << "Ingrese ID del producto a modificar (0 para volver): ";
    cin >> id;

    if (id == 0) return;

    if (arch.modificarPrecioCompraPorId(id))
        cout << "Precio de compra modificado correctamente." << endl;
    else
        cout << "No se encontro el ID o no se pudo modificar." << endl;
}

// Modificar precio venta por ID
void modificarPrecioVentaProducto()
{
    ArchivoProducto arch;

    arch.listarProductos();
    cout << endl;

    int id;
    cout << "Ingrese ID del producto a modificar (0 para volver): ";
    cin >> id;

    if (id == 0) return;

    if (arch.modificarPrecioVentaPorId(id))
        cout << "Precio de venta modificado correctamente." << endl;
    else
        cout << "No se encontro el ID o no se pudo modificar." << endl;
}

// Activa un producto mostrando primero los inactivos
void activarProducto()
{
    ArchivoProducto arch;

    cout << "=== PRODUCTOS INACTIVOS ===" << endl;
    arch.listarInactivos();
    cout << endl;

    int id;

    while (true)
    {
        cout << "Ingrese ID del producto a ACTIVAR (0 para volver): ";
        cin >> id;

        if (id == 0) return;

        if (arch.activarPorId(id))
        {
            cout << "Producto activado correctamente." << endl;
            break;
        }
        else
        {
            cout << "ID invalido o no se pudo activar. Intente nuevamente." << endl;
            cout << endl;
        }
    }
}

// Desactiva un producto mostrando primero los activos
void desactivarProducto()
{
    ArchivoProducto arch;

    cout << "=== PRODUCTOS ACTIVOS ===" << endl;
    arch.listarActivos();
    cout << endl;

    int id;

    while (true)
    {
        cout << "Ingrese ID del producto a DESACTIVAR (0 para volver): ";
        cin >> id;

        if (id == 0) return;

        if (arch.desactivarPorId(id))
        {
            cout << "Producto desactivado correctamente." << endl;
            break;
        }
        else
        {
            cout << "ID invalido o no se pudo desactivar. Intente nuevamente." << endl;
            cout << endl;
        }
    }
}
// ============================================================
//                         MENÚ CLIENTES
// ============================================================

// Menú principal de Clientes
void menuClientes()
{
    int opcion;

    do
    {
        cout << "-------------------" << endl;
        cout << "Menu Clientes" << endl;
        cout << "-------------------" << endl;
        cout << "1 - Cargar Clientes" << endl;
        cout << "2 - Mostrar Clientes" << endl;
        cout << "3 - Modificar" << endl;
        cout << "4 - Clientes Activos (Desactivar)" << endl;
        cout << "5 - Clientes Inactivos (Activar)" << endl;
        cout << "0 - Volver" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            cargarCliente();
            system("pause");
            system("cls");
            break;

        case 2:
            mostrarClientes();
            system("pause");
            system("cls");
            break;

        case 3:
            menuModificarCliente();
            system("pause");
            system("cls");
            break;

        case 4:
            desactivarCliente();
            system("pause");
            system("cls");
            break;

        case 5:
            activarCliente();
            system("pause");
            system("cls");
            break;

        case 0:
            break;

        default:
            cout << "!OPCION INCORRECTA!" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while (opcion != 0);
}

// Submenú de Modificar Cliente
void menuModificarCliente()
{
    int opcion;

    do
    {
        cout << "-------------------" << endl;
        cout << "Modificar Cliente" << endl;
        cout << "-------------------" << endl;
        cout << "1 - Nombre" << endl;
        cout << "2 - Telefono" << endl;
        cout << "0 - Volver" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            modificarNombreCliente();
            system("pause");
            system("cls");
            break;

        case 2:
            modificarTelefonoCliente();
            system("pause");
            system("cls");
            break;

        case 0:
            break;

        default:
            cout << "!OPCION INCORRECTA!" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while (opcion != 0);
}


// ---------------- FUNCIONES PUENTE (Clientes) ----------------

// Alta de clientes
void cargarCliente()
{
    ArchivoCliente arch;
    arch.cargarClientes();
}

// Listado general de clientes
void mostrarClientes()
{
    ArchivoCliente arch;
    arch.listarClientes();
}

// Modificar nombre por ID
void modificarNombreCliente()
{
    ArchivoCliente arch;

    arch.listarClientes();
    cout << endl;

    int id;
    cout << "Ingrese ID del cliente a modificar (0 para volver): ";
    cin >> id;

    if (id == 0) return;

    if (arch.modificarNombrePorId(id))
        cout << "Nombre modificado correctamente." << endl;
    else
        cout << "No se encontro el ID o no se pudo modificar." << endl;
}

// Modificar teléfono por ID
void modificarTelefonoCliente()
{
    ArchivoCliente arch;

    arch.listarClientes();
    cout << endl;

    int id;
    cout << "Ingrese ID del cliente a modificar (0 para volver): ";
    cin >> id;

    if (id == 0) return;

    if (arch.modificarTelefonoPorId(id))
        cout << "Telefono modificado correctamente." << endl;
    else
        cout << "No se encontro el ID o no se pudo modificar." << endl;
}

// Activa un cliente mostrando primero los inactivos
void activarCliente()
{
    ArchivoCliente arch;

    cout << "=== CLIENTES INACTIVOS ===" << endl;
    arch.listarInactivos();
    cout << endl;

    int id;

    while (true)
    {
        cout << "Ingrese ID del cliente a ACTIVAR (0 para volver): ";
        cin >> id;

        if (id == 0) return;

        if (arch.activarPorId(id))
        {
            cout << "Cliente activado correctamente." << endl;
            break;
        }
        else
        {
            cout << "ID invalido o no se pudo activar. Intente nuevamente." << endl;
            cout << endl;
        }
    }
}

// Desactiva un cliente mostrando primero los activos
void desactivarCliente()
{
    ArchivoCliente arch;

    cout << "=== CLIENTES ACTIVOS ===" << endl;
    arch.listarActivos();
    cout << endl;

    int id;

    while (true)
    {
        cout << "Ingrese ID del cliente a DESACTIVAR (0 para volver): ";
        cin >> id;

        if (id == 0) return;

        if (arch.desactivarPorId(id))
        {
            cout << "Cliente desactivado correctamente." << endl;
            break;
        }
        else
        {
            cout << "ID invalido o no se pudo desactivar. Intente nuevamente." << endl;
            cout << endl;
        }
    }
}

// ============================================================
//                    MENÚ FORMAS DE PAGO
// ============================================================

// Menú principal de Formas de Pago
void menuFormasPago()
{
    int opcion;

    do
    {
        cout << "-------------------" << endl;
        cout << "Menu Formas de Pago" << endl;
        cout << "-------------------" << endl;
        cout << "1 - Cargar Formas de Pago" << endl;
        cout << "2 - Listar Formas de Pago" << endl;
        cout << "3 - Modificar" << endl;
        cout << "4 - Formas Activas (Desactivar)" << endl;
        cout << "5 - Formas Inactivas (Activar)" << endl;
        cout << "0 - Volver" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            cargarFormaPago();
            system("pause");
            system("cls");
            break;

        case 2:
            mostrarFormasPago();
            system("pause");
            system("cls");
            break;

        case 3:
            menuModificarFormaPago();
            system("pause");
            system("cls");
            break;

        case 4:
            desactivarFormaPago();
            system("pause");
            system("cls");
            break;

        case 5:
            activarFormaPago();
            system("pause");
            system("cls");
            break;

        case 0:
            break;

        default:
            cout << "!OPCION INCORRECTA!" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while (opcion != 0);
}

// Submenú de Modificar Forma de Pago
void menuModificarFormaPago()
{
    int opcion;

    do
    {
        cout << "-------------------" << endl;
        cout << "Modificar Forma de Pago" << endl;
        cout << "-------------------" << endl;
        cout << "1 - Porcentaje (Descuento / Interes)" << endl;
        cout << "0 - Volver" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            modificarPorcentajeFormaPago();
            system("pause");
            system("cls");
            break;

        case 0:
            break;

        default:
            cout << "!OPCION INCORRECTA!" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while (opcion != 0);
}


// ---------------- FUNCIONES PUENTE (Formas de Pago) ----------------

// Alta de formas de pago
void cargarFormaPago()
{
    ArchivoFormaPago arch;
    arch.cargarFormasPago();
}

// Listado general
void mostrarFormasPago()
{
    ArchivoFormaPago arch;
    arch.listarFormasPago();
}

// Modificar porcentaje por ID
void modificarPorcentajeFormaPago()
{
    ArchivoFormaPago arch;

    arch.listarFormasPago();
    cout << endl;

    int id;
    cout << "Ingrese ID de la forma de pago a modificar (0 para volver): ";
    cin >> id;

    if (id == 0) return;

    if (arch.modificarPorcentajePorId(id))
        cout << "Porcentaje modificado correctamente." << endl;
    else
        cout << "No se encontro el ID o no se pudo modificar." << endl;
}

// Activar mostrando primero inactivas
void activarFormaPago()
{
    ArchivoFormaPago arch;

    cout << "=== FORMAS DE PAGO INACTIVAS ===" << endl;
    arch.listarInactivas();
    cout << endl;

    int id;

    while (true)
    {
        cout << "Ingrese ID de la forma de pago a ACTIVAR (0 para volver): ";
        cin >> id;

        if (id == 0) return;

        if (arch.activarPorId(id))
        {
            cout << "Forma de pago activada correctamente." << endl;
            break;
        }
        else
        {
            cout << "ID invalido o no se pudo activar. Intente nuevamente." << endl;
            cout << endl;
        }
    }
}

// Desactivar mostrando primero activas
void desactivarFormaPago()
{
    ArchivoFormaPago arch;

    cout << "=== FORMAS DE PAGO ACTIVAS ===" << endl;
    arch.listarActivas();
    cout << endl;

    int id;

    while (true)
    {
        cout << "Ingrese ID de la forma de pago a DESACTIVAR (0 para volver): ";
        cin >> id;

        if (id == 0) return;

        if (arch.desactivarPorId(id))
        {
            cout << "Forma de pago desactivada correctamente." << endl;
            break;
        }
        else
        {
            cout << "ID invalido o no se pudo desactivar. Intente nuevamente." << endl;
            cout << endl;
        }
    }
}


// ============================================================
//                         MENÚ VENTAS
// ============================================================

// Menú principal de Ventas
void menuVentas()
{
    int opcion;

    do
    {
        cout << "-------------------" << endl;
        cout << "Menu Ventas" << endl;
        cout << "-------------------" << endl;
        cout << "1 - Nueva Venta" << endl;
        cout << "2 - Confirmar Venta" << endl;
        cout << "3 - Cancelar Venta" << endl;
        cout << "4 - Listar Ventas" << endl;
        cout << "5 - Ver Venta con Detalle" << endl;
        cout << "0 - Volver" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            nuevaVenta();
            system("pause");
            system("cls");
            break;

        case 2:
            confirmarVenta();
            system("pause");
            system("cls");
            break;

        case 3:
            cancelarVenta();
            system("pause");
            system("cls");
            break;

        case 4:
            listarVentas();
            system("pause");
            system("cls");
            break;

        case 5:
            mostrarVentaDetalle();
            system("pause");
            system("cls");
            break;

        case 0:
            break;

        default:
            cout << "!OPCION INCORRECTA!" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while (opcion != 0);
}


// ---------------- FUNCIONES PUENTE (Ventas) ----------------

// Crea una venta en estado pendiente
void nuevaVenta()
{
    ArchivoVenta arch;
    arch.cargarVentaCompleta();
}

// Confirma una venta pendiente
void confirmarVenta()
{
    ArchivoVenta arch;

    int id;
    cout << "Ingrese ID de venta a confirmar: ";
    cin >> id;

    if (!arch.confirmarVenta(id))
        cout << "No se pudo confirmar la venta.\n";
}

// Cancela una venta
void cancelarVenta()
{
    ArchivoVenta arch;

    int id;
    cout << "Ingrese ID de venta a cancelar: ";
    cin >> id;

    if (!arch.cancelarVenta(id))
        cout << "No se pudo cancelar la venta.\n";
}

// Lista todas las ventas
void listarVentas()
{
    ArchivoVenta arch;
    arch.listarVentas();
}

// Muestra una venta específica junto con su detalle
void mostrarVentaDetalle()
{
    ArchivoVenta arch;

    int id;
    cout << "Ingrese ID de venta: ";
    cin >> id;

    arch.mostrarVentaConDetalle(id);
}

// ============================================================
//                         MENÚ REPORTES
// ============================================================

// Menú principal de Reportes
void menuReportes()
{
    int opcion;

    do
    {
        cout << "-------------------" << endl;
        cout << "Menu reportes" << endl;
        cout << "-------------------" << endl;
        cout << "1 - Listar Ventas Confirmadas" << endl;
        cout << "2 - Total recaudadio ventas confirmadas" << endl;
        cout << "3 - Ventas por Cliente" << endl;
        cout << "4 - Ventas por Fecha" << endl;
        cout << "5 - Ventas por Forma de Pago" << endl;
        cout << "6 - Mostrar Factura / Ticket" << endl;
        cout << "0 - Volver" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            listarVentasConfirmadas();
            system("pause");
            system("cls");
            break;

        case 2:
            mostrarTotalVentasConfirmadas();
            system("pause");
            system("cls");
            break;

        case 3:
            listarVentasPorCliente();
            system("pause");
            system("cls");
            break;

        case 4:
            listarVentasPorFecha();
            system("pause");
            system("cls");
            break;

        case 5:
            listarVentasPorFormaPago();
            system("pause");
            system("cls");
            break;

        case 6:
            mostrarFactura();
            system("pause");
            system("cls");
            break;

        case 0:
            break;

        default:
            cout << "!OPCION INCORRECTA!" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while (opcion != 0);
}


// ---------------- FUNCIONES PUENTE (Reportes) ----------------

// Lista solo las ventas confirmadas
void listarVentasConfirmadas()
{
    ArchivoVenta arch;
    arch.listarVentasConfirmadas();
}

// Muestra el total recaudado en ventas confirmadas
void mostrarTotalVentasConfirmadas()
{
    ArchivoVenta arch;

    float total = arch.calcularTotalVentasConfirmadas();

    cout << "Total recaudado por ventas confirmadas: $" << total << endl;
}

// Muestra las ventas confirmadas de un cliente
void listarVentasPorCliente()
{
    ArchivoCliente archCli;
    ArchivoVenta archVen;

    cout << "=== CLIENTES ACTIVOS ===" << endl;
    archCli.listarActivos();
    cout << endl;

    int id;
    cout << "Ingrese ID Cliente: ";
    cin >> id;

    archVen.listarVentasPorCliente(id);
}

// Muestra las ventas confirmadas de una fecha
void listarVentasPorFecha()
{
    ArchivoVenta arch;
    Fecha fecha;

    cout << "Ingrese la fecha a consultar:\n";
    fecha.cargarFecha();

    arch.listarVentasPorFecha(fecha);
}

// Muestra las ventas confirmadas de una forma de pago
void listarVentasPorFormaPago()
{
    ArchivoFormaPago archFP;
    ArchivoVenta archVen;

    cout << "=== FORMAS DE PAGO ACTIVAS ===" << endl;
    archFP.listarActivas();
    cout << endl;

    int id;
    cout << "Ingrese ID Forma de Pago: ";
    cin >> id;

    archVen.listarVentasPorFormaPago(id);
}

// Muestra ticket/factura de una venta confirmada
void mostrarFactura()
{
    ArchivoVenta arch;

    int id;
    cout << "Ingrese ID de venta: ";
    cin >> id;

    arch.mostrarFactura(id);
}
