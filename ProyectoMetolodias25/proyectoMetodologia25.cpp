#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int contadorProductos = 0;
int tamanoProducto = 100;
struct Producto{
    string nombre;
    float precio;
    int cantidad;
};
Producto productoLista[100] = {};
void registrarProductos(){
    int cantidadProductos = 0;
    int conteo = 1;
    cout << "¿Cuántos productos desea registrar?: "<<endl;
    cin >> cantidadProductos;
    int totalRegistro = contadorProductos + cantidadProductos;
    if(contadorProductos < tamanoProducto){
        for(int i=contadorProductos;i < totalRegistro;i++){
            if(contadorProductos >= 100){
                cout <<"Limite de productos alcanzado"<<endl;
                break;
            }
            cout << "Producto" << conteo <<endl;
            
            cout << "Nombre" <<endl;
            cin >> productoLista[i].nombre;
            cout << "Precio" <<endl;
            cin >> productoLista[i].precio;
            cout << "Cantidad" <<endl;
            cin >> productoLista[i].cantidad;
            cout << "\n"<<endl;
            contadorProductos+=1;
            conteo++;
        }
    }
    else
    {
        cout <<"Limite de productos alcanzado"<<endl;
    }
}

void mostrarProductos(){
    for(int i=0;i < tamanoProducto;i++){
        if(productoLista[i].nombre != "" && productoLista[i].precio != 0.0)
        if(productoLista[i].cantidad != 0){
            cout << "Nombre: "<< productoLista[i].nombre <<endl;
            cout << "Precio: "<< productoLista[i].precio <<endl;
            cout << "Cantidad: " <<productoLista[i].cantidad<<endl;
        }
    }
}

void ordenarBurbuja(){
    int i,j;
    Producto aux;
    for(i=0;i<tamanoProducto - 1;i++){
        for(j=0;j<tamanoProducto - 1 - i;j++){
            if(productoLista[j].precio > productoLista[j+1].precio){
                aux = productoLista[j];
                productoLista[j] = productoLista[j+1];
                productoLista[j+1] = aux;
            }
        }
    }
}

void ordenarSeleccion(){
    int i,j,min;
    Producto aux;
    for(i=0;i<tamanoProducto;i++){
        min = i;
        for(j=i+1;j<tamanoProducto;j++){
            if(productoLista[j].precio < productoLista[min].precio){
                min = j;
            }
        }
        aux = productoLista[i];
        productoLista[i] = productoLista[min];
        productoLista[min] = aux;
    }
}

void ordenarInsercion(){
    int i,pos;
    Producto aux;
    for(i=0;i<tamanoProducto;i++){
        pos = i;
        aux = productoLista[i];
        while((pos>0) && (productoLista[pos - 1].precio > aux.precio)){
            productoLista[pos] = productoLista[pos -1];
            pos--;
        }
        productoLista[pos] = aux;
    }
}

void buscarProductos(){
    string busqueda;
    cout << "Ingrese el nombre a buscar: "<<endl;
    cin >> busqueda;
    cout << "Producto encontrado:"<<endl;
    for(int i=0;i < tamanoProducto;i++){ 
        if(productoLista[i].nombre == busqueda){
            cout << "Nombre: " << productoLista[i].nombre <<endl;
            cout << "Precio: " << productoLista[i].precio <<endl;
            cout << "Cantidad: " << productoLista[i].cantidad <<endl;
        }
    }
}

void buscarProducto(){
    string busqueda;
    cout << "Ingrese el nombre a buscar: "<<endl;
    cin >> busqueda;
    cout << "Producto encontrado:"<<endl;
    for(int i=0;i < tamanoProducto;i++){ 
        if(productoLista[i].nombre == busqueda){
            cout << "Nombre: " << productoLista[i].nombre <<endl;
            cout << "Precio: " << productoLista[i].precio <<endl;
            cout << "Cantidad: " << productoLista[i].cantidad <<endl;
            break;
        }
    }
}

void actualizarProducto(){
    int i = 0;
    int opcion = 0;
    while(true){
        cout << "Ingrese el índice del producto a actualizar:" <<endl;
        cin >> i;
        if(i => tamanoProducto){
        cout << "No se encuentra esa posicion";
        }
        else{
            break;
        }
    }
    cout << "¿Qué desea actualizar?"<<endl;
    cout << "1. Precio"<<endl;
    cout << "2. Cantidad"<<endl;
    cout << "Opción:" <<endl;
    cin >> opcion;
    cout << "Nueva cantidad:"<<endl;
    switch(opcion){
        case 1:
            cin >> productoLista[i].precio;
            break;
        case 2:
            cin >> productoLista[i].cantidad;
            break;
        default:
            break;
    }
}


int main()
{
    registrarProductos();
    //ordenarBurbuja();
    //ordenarSeleccion();
    //ordenarInsercion();
    //mostrarProductos();
    //buscarProductos();
    //buscarProducto();
    actualizarProducto();
    mostrarProductos();
    return 0;
}