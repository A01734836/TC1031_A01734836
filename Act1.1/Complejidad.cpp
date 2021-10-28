/* 
Jorge Leonardo Garcia Reynoso - A01734836                                                                    27/08/2021
Este programa calcula la suma de todos los numeros enteros entre 1 y numero n, esto mediante 3 metodos: un metodo 
iterativo (por medio de la funcion for), un metodo recursivo (llamando la misma funcion dentro de la funcion) y un 
metodo directo (la formula matematica n*(n+1)/2).
*/

#include <iostream>
#include <fstream>

using namespace std;

// Metodo de suma iterativa
long long sumaIterativa(long long n){
    long long suma=0;
    for(long long i=1;i<=n;i++){
        suma=suma+i;
    }
    return suma;
}

// Metodo de suma recursiva
long long sumaRecursiva(long long n){
    if(n==1){
        return 1;
    }
    return n+sumaRecursiva(n-1);
}

// Metodo de suma directa
long long sumaDirecta(long long n){
    return n*(n+1)/2;
}

string caso;
int main(){
    do{
        // se pide el documento a utilizar
        cout<<"Que casos se utilizaran (solo escribir el numero)? ";
        cin>>caso;
        // se revisa que el nombre del documento sea valido
        while(!(caso=="1"||caso=="2"||caso=="3"||caso=="4")){
            cout<<"El documento es invalido, por favor intentelo de nuevo (solo escriba el numero de archivo): ";
            cin>>caso;
        }
        caso=caso+".in";
        // se adjunta el documento a una variable in
        ifstream in(caso);
        string s;
        // se obtiene el tamano del arreglo
        getline(in,s);
        int n=stoi(s);
        if(caso=="4.in"){
            //debido a que causa problemas, si se trata del documento 4 no realizara el metodo recursivo
            cout<<"n             Iterativa         Directa"<<endl;
            int *arreglo = new int[n];
            int i=0;
            //se llaman las funciones de suma para cada valor del arreglo y se imprimen
            while(getline(in,s)){
                arreglo[i]=stoi(s);
                cout<<arreglo[i]<<"         "<<sumaIterativa(arreglo[i])<<"         "<<sumaDirecta(arreglo[i])<<endl;
                i++;
            }
        }else{
            cout<<"n          Iterativa         Recursiva        Directa"<<endl;
            int *arreglo = new int[n];
            int i=0;
            //se llaman las funciones de suma para cada valor del arreglo y se imprimen
            while(getline(in,s)){
                arreglo[i]=stoi(s);
                cout<<arreglo[i]<<"        "<<sumaIterativa(arreglo[i])<<"         "<<sumaRecursiva(arreglo[i])<<"         "<<sumaDirecta(arreglo[i])<<endl;
                i++;
            }
        }
        cout<<"Deseas analizar otro caso? (si/no) ";
        cin>>caso;
    }while(caso=="si"||caso=="Si");

    return 0;
}