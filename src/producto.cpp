#include "../include/producto.h"

struct rep_producto {
    int id;
    char nombre[MAX_NOMBRE_PRODUCTO];
    int precio;
    TFecha fechaIngreso;
};

TProducto crearTProducto(int id, const char nombre[MAX_NOMBRE_PRODUCTO], int precio, TFecha fechaIngreso){
    TProducto producto = new rep_producto;
    producto->id = id;
    strcpy(producto->nombre, nombre);
    producto->precio = precio;
    producto->fechaIngreso = fechaIngreso;
    return producto;
}

int idTProducto(TProducto producto){
    return producto->id;
}


int precioTProducto(TProducto producto){
    return producto->precio;
}     

void imprimirTProducto(TProducto producto){
    printf("Producto: %d\n", producto->id);
    printf("%s\n", producto->nombre);
    printf("Precio: %d\n", producto->precio);
    printf("Ingresado el: ");
    imprimirTFecha(producto->fechaIngreso);
}

void liberarTProducto(TProducto &producto){
    liberarTFecha(producto->fechaIngreso);
    delete producto;
    producto = NULL;
}