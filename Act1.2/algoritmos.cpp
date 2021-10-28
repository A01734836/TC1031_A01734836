/*
Jorge Leonardo Garcia Reynoso - A01734836
TC1031.4
Este codigo ordena secuencias por 3 diferentes metodos (intercambio, buble, merge), y luego pide un numero a buscar y por medio de 2 diferentes metodos (secuencial binaria) encuentra la posicion
y la imprime. Ademas, el programa puede leer los 4 casos de prueba para asi poder analizar el deseado
*/
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void imprimirSecuencia(int a[],int n){
    for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
void swap(int a[], int i, int j){    
    int aux;    
    aux = a[i];    
    a[i] = a[j];    
    a[j] = aux;
    }
void ordIntercambio(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = i+1; j <= n - 1; j++) {
			if (a[i] > a[j]) {
				swap(a,i,j);
			}
		}
	}
	imprimirSecuencia(a, n);
}
void bubleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a,j,j+1);
			}
		}
	}
	imprimirSecuencia(a, n);
}
void unir(int a[],int inicio, int mitad, int fin){
    int i,j,k;
    i = inicio;
    j = mitad + 1;
    k = 0;
    int aux[fin - inicio + 1];

    while(i <= mitad && j <= fin){
        if(a[i] < a[j]){
            aux[k] = a[i];
            i++;
        } else {
            aux[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= mitad){
        aux[k] = a[i];
        i++;
        k++;
    }
    
    while(j <= fin){
        aux[k] = a[j];
        j++;
        k++;
    }
    
    for(int i = inicio; i <= fin; i++){
        a[i] = aux[i - inicio];
    }
}
void mergeSort(int a[], int inicio, int fin){
    int mitad;
    if(inicio < fin){
        mitad = (inicio + fin) / 2;
        mergeSort(a,inicio,mitad);
        mergeSort(a,mitad + 1,fin);
        unir(a,inicio,mitad,fin);
    }
}
int busquedaSecuencial(int a[],int n,int busqueda){
    for(int i=0;i<n;i++){
        if(a[i]==busqueda){
            return i;
        }
    }
    return -1;
}
int busquedaBinaria(int a[],int n,int busqueda){
    int ultimo=n-1,primero=0,centro;
    while(primero<=ultimo){
        centro=(primero+ultimo)/2;
        if(a[centro]==busqueda){
            return centro;
        }
        if(busqueda<a[centro]){
            ultimo=centro-1;
        }else{
            primero=centro+1;
        }
    }
    return -1;
}

int main(){
    //elegir el archivo
    string archivo;
    cout<<"Escribe el numero de caso de pureba a probar: ";
    cin>>archivo;
    while(!(archivo=="1"|archivo=="2"|archivo=="3"|archivo=="4")){
        cout<<"Elige solamente el numero entre 1 y 4: ";
        cin>>archivo;
    }
    archivo="0"+archivo+".in";
    //abrir archivo
	int n;
	string s;
	ifstream in(archivo);
	in >> n;

	//llenar arreglo
	int* arreglo = new int [n];
	for (int i = 0; i < n; i++) {
		in >> arreglo[i];
	}

	//ordenar
    cout<<"Merge Sort:"<<endl;
	mergeSort(arreglo,0, n);
    imprimirSecuencia(arreglo,n);
    cout<<endl;
    cout<<"Buble Sort:"<<endl;
	bubleSort(arreglo, n);
    cout<<endl;
    cout<<"Intercambio:"<<endl;
	ordIntercambio(arreglo, n);
    cout<<endl;

    //busqueda
    int elemento;
    cout<<"Que numero deseas buscar? ";
    cin>>elemento;
    int pos=busquedaSecuencial(arreglo,n,elemento);
    cout<<"Busqueda secuencial"<<endl;
    if(pos==-1){
        cout<<"Ese numero no se encuentra en el arreglo"<<endl;
    }else{
        cout<<"Ese numero se encuentra en la posicion "<<pos<<endl;
    }
    pos=busquedaBinaria(arreglo,n,elemento);
    cout<<"Busqueda binaria"<<endl;
    if(pos==-1){
        cout<<"Ese numero no se encuentra en el arreglo"<<endl;
    }else{
        cout<<"Ese numero se encuentra en la posicion "<<pos<<endl;
    }

	//cerrar archivo
	in.close();
    
    return 0;
}