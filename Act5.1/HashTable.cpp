#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int n){
	for (int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
//Manejo de desbordamiento por dirección abierta
void open(vector <int> &hashTable, int n){
	int dato, idx, tam;
	while(!isPrime(n)){
		n++;
	}
	tam = n;
	
	for (int i = 0; i < tam; i++){
			hashTable.push_back(-1);
	}
	
	for (int i = 0; i < n; i++){
		cout << "Introduce the " << i << "-th element: " << endl;
		cin >> dato;
		idx = dato % tam;
		while(hashTable[idx] != -1){
			idx = (idx+1) % tam;
		}
		hashTable[idx] = dato;
		
	}
}
//Desplegar la hashtable para comprobar 
void print(vector <int> &hashTable){
	for (int i = 0; i < hashTable.size(); i++){
		cout << "[" << i << "]" << "[" << hashTable[i] << "]" << endl;
	}
}



/*
5
100
200
543
123
4
*/
int main(){
	int n;
	vector <int> hashTable;
	cout << "Introduce the size of the hash table: " << endl;
	cin >> n;
	open(hashTable, n);
	print(hashTable);
}


