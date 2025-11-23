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
    cout << "¿Cuántos productos desea registrar?: "<<endl;
    cin >> cantidadProductos;
    int totalRegistro = contadorProductos + cantidadProductos;
    if(contadorProductos < tamanoProducto){
        for(int i=contadorProductos;i < totalRegistro;i++){
            if(contadorProductos >= 100){
                cout <<"Limite de productos alcanzado"<<endl;
                break;
            }
            cout << "Nombre" <<endl;
            cin >> productoLista[i].nombre;
            cout << "Precio" <<endl;
            cin >> productoLista[i].precio;
            cout << "Cantidad" <<endl;
            cin >> productoLista[i].cantidad;
            cout << "\n"<<endl;
            contadorProductos+=1;
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
            cout << "Producto: " << i + 1 <<endl;
            cout << "Nombre: "<< productoLista[i].nombre <<endl;
            cout << "Precio: "<< productoLista[i].precio <<endl;
            cout << "Cantidad: " <<productoLista[i].cantidad<<endl;
        }
    }
}

int main()
{
    for(int i=0;i < 2;i++){
        registrarProductos();
    }
    mostrarProductos();
    return 0;
}