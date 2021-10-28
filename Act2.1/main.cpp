#include <iostream>
#include <fstream>
using namespace std;
#include "LinkedList.h"

int main(){
    //pedir el archivo
    LinkedList<int> lista;
    string archivo;
    cout<<"Escribe el numero de caso de pureba a probar: ";
    cin>>archivo;
    while(!(archivo=="1"|archivo=="2"|archivo=="3"|archivo=="4")){
        cout<<"Elige solamente el numero entre 1 y 4: ";
        cin>>archivo;
    }
    archivo=archivo+".in";

    //abrir archivo
	int n,val;
	ifstream in(archivo);
	in >> n;

	//llenar la lista
	for (int i = 0; i < n; i++) {
        in>>val;
		lista.addLast(val);
	}
    string inciso,decision;
    int valor,posicion;
    cout<<"Esta lista tiene un tamano de: "<<lista.getSize()<<endl;
    do{
        cout<<"Elige una opcion:"<<endl<<"a) Agregar un valor a la lista"<<endl;
        cout<<"b) Obtener uno de los valores de la lista"<<endl<<"c) Actualizar uno de los valores de la lista"<<endl;
        cout<<"d) Eliminar uno de los valores de la lista"<<endl<<"Escribe el inciso que corresponda ";
        cin>>inciso;
        while(!(inciso=="a"||inciso=="b"||inciso=="c"||inciso=="d")){
            cout<<"Por favor escoje un inciso valido ";
            cin>>inciso;
        }
        
        if(inciso=="a"){
            cout<<"Escribe el numero que deseas agregar: ";
            cin>>valor;
            cout<<"Y ahora la posicion: ";
            cin>>posicion;
            lista.create(valor,posicion);
        }else if(inciso=="b"){
            cout<<"Que posicion quieres obtener: ";
            cin>>posicion;
            cout<<"EL valor en la posicion "<<posicion<<" es "<<lista.read(posicion)<<endl;
        }else if(inciso=="c"){
            cout<<"En que posicion esta el valor a actualizar: ";
            cin>>posicion;
            cout<<"Cual sera el nuevo valor: ";
            cin>>valor;
            lista.update(valor,posicion);
        }else{
            cout<<"Cual es la posicion del valor a eliminar: ";
            cin>>posicion;
            lista.del(posicion);
        }
        cout<<"Ahora esta lista tiene un tamano de: "<<lista.getSize()<<endl;
        cout<<"Desea hacer algo mas (Y/n) ";
        cin>>decision;
    }while(decision=="Y"||decision=="y");
    
    return 0;
}