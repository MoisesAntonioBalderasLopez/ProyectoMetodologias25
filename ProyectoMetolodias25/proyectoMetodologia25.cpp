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

void ordenarBurbuja(){
    int i,j;
    Producto aux;
    for(i=0;i<tamanoProducto;i++){
        for(j=0;j<tamanoProducto;j++){
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

void ordenarBurbujaOriginal(){
    int arreglo[] = {6,3,5};
    int i,j,aux;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(arreglo[j] > arreglo[j+1]){
                aux = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = aux;
            }
        }
        for(int x=0;x<3;x++){
            cout << arreglo[x];
        }
        cout<<"\n";
    }
}


int main()
{
    /*for(int i=0;i < 2;i++){
        registrarProductos();
    }
    mostrarProductos();*/
    /*ordenarBurbuja();*/
    /*ordenarSeleccion();*/
    //ordenarBurbuja();
    //ordenarSeleccion();
    //ordenarInsercion();
    ordenarBurbujaOriginal();
    return 0;
}