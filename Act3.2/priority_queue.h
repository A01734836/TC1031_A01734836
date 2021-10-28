#include <iostream>
#include <vector>
#include <cfloat>
using namespace std;

class priority_queue{
	public:
		priority_queue();
		void push(int dato); 
		void pop(); 			
		int top(); 
		bool empty();
		int size();
		void print();
		int getParent(int pos);
		void aumentarDato(int i, int dato);
		void swap(int a, int b);
		int getLeft(int pos);
		int getRight(int pos);
		void maxHeapify(int i);
	private:
		vector<int> datos;
};

priority_queue::priority_queue(){
	
}

void priority_queue::push(int dato){
	if(datos.size()==0){
		datos.push_back(dato);
		return;
	}
	datos.push_back(-INT_MAX);
	aumentarDato(datos.size()-1,dato);
	
}

void priority_queue::pop(){
	if(datos.size()==0){
		cout<<"No se tienen datos"<<endl;
		return;
	}
	int max=datos[0];
	datos[0]=datos[datos.size()-1];
	datos.pop_back();
	maxHeapify(0);
}

int priority_queue::top(){
	if(datos.size()==0){
		return -1;
	}
	return datos[0];
}

bool priority_queue::empty(){
	return datos.size()==0;
}

int priority_queue::size(){
	return datos.size();
}

void priority_queue::print(){
	if(datos.size()==0){
		cout<<"La fila no tiene datos"<<endl;
		return;
	}
	for(int i=0;i<datos.size();i++){
		cout<<datos[i]<<" ";
	}
	cout<<endl;
}

int priority_queue::getParent(int pos){
	return ((pos+1)/2)-1;
}

void priority_queue::aumentarDato(int i, int dato){
	if(dato<datos[i]){
		cout<<"El dato es mas pequeno que el anterior"<<endl;
		return;
	}
	datos[i]=dato;
	while(i>0 && datos[getParent(i)]<datos[i]){
		swap(i, getParent(i));
		i=getParent(i);
	}
}

void priority_queue::swap(int a, int b){
	int temp=datos[a];
	datos[a]=datos[b];
	datos[b]=temp;
}

int priority_queue::getLeft(int pos){
	return ((pos+1)*2)-1;
}

int priority_queue::getRight(int pos){
	return (pos+1)*2;
}

void priority_queue::maxHeapify(int i){
	int l=getLeft(i), r=getRight(i), largest;
	if(l<=datos.size()-1 && datos[l]>datos[i]){
		largest=l;
	}else{
		largest=i;
	}
	if(r<=datos.size()-1 && datos[r]>datos[largest]){
		largest=r;
	}
	if(largest!=i){
		swap(i,largest);
		maxHeapify(largest);
	}
}