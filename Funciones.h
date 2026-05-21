#pragma once

// ---------------- MEN√öS ----------------
void menuMarcas();               // Submen£ principal de Marcas
void menuModificarMarca();       // Submen£ de modificaci¢n (Marcas)

void menuProductos();            // Submen£ principal de Productos
void menuModificarProducto();    // Submen£ de modificaci¢n (Productos)

void menuClientes();             // Submen£ principal de Clientes
void menuModificarCliente();     // Submen£ de modificaci¢n (Clientes)

void menuFormasPago();           // Submen£ principal de Formas de Pago
void menuModificarFormaPago();   // Submen£ de modificaci¢n (Formas de Pago)

void menuVentas();               // Submen£ principal de Ventas

void menuReportes();             // Submen£ principal de Reportes

// ---------------- FUNCIONES PUENTE (Marcas) ----------------
void cargarMarca();              // Alta de marcas
void mostrarMarcas();            // Listado general
void modificarNombreMarca();     // Modificar nombre por ID
void activarMarca();             // Activar marca inactiva
void desactivarMarca();          // Desactivar marca activa


// ---------------- FUNCIONES PUENTE (Productos) ----------------
void cargarProducto();                 // Alta de productos
void mostrarProductos();               // Listado general
void modificarNombreProducto();        // Modificar nombre por ID
void modificarDescripcionProducto();   // Modificar descripci¢n por ID
void modificarMarcaProducto();         // Modificar ID marca por ID
void modificarStockProducto();         // Modificar stock por ID
void modificarPrecioCompraProducto();  // Modificar precio de compra por ID
void modificarPrecioVentaProducto();   // Modificar precio de venta por ID
void activarProducto();                // Activar producto inactivo
void desactivarProducto();             // Desactivar producto activo


// ---------------- FUNCIONES PUENTE (Clientes) ----------------
void cargarCliente();              // Alta de clientes
void mostrarClientes();            // Listado general
void modificarNombreCliente();     // Modificar nombre por ID
void modificarTelefonoCliente();   // Modificar tel√©fono por ID
void activarCliente();             // Activar cliente inactivo
void desactivarCliente();          // Desactivar cliente activo


// ---------------- FUNCIONES PUENTE (Formas de Pago) ----------------
void cargarFormaPago();                // Alta de formas de pago
void mostrarFormasPago();              // Listado general
void modificarPorcentajeFormaPago();   // Modificar porcentaje por ID
void activarFormaPago();               // Activar forma de pago inactiva
void desactivarFormaPago();            // Desactivar forma de pago activa


// ---------------- FUNCIONES PUENTE (Ventas) ----------------
void nuevaVenta();                     // Crea venta en estado pendiente
void confirmarVenta();                 // Confirma venta y aplica forma de pago
void cancelarVenta();                  // Cancela venta y devuelve stock
void listarVentas();                   // Listado general de ventas
void mostrarVentaDetalle();            // Muestra cabecera + detalle de una venta


// ---------------- FUNCIONES PUENTE (Reportes) ----------------
void listarVentasConfirmadas();        // Lista solo las ventas confirmadas
void mostrarTotalVentasConfirmadas();   // Muestra el total recaudado
void listarVentasPorCliente();   // Muestra ventas confirmadas seg£n ID cliente
void listarVentasPorFecha();   // Muestra ventas confirmadas seg£n fecha
void listarVentasPorFormaPago();   // Muestra ventas confirmadas seg£n forma de pago
void mostrarFactura();   // Muestra ticket/factura de una venta
