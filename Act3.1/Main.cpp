#include <fstream>
#include "BST.h"


int main(){
    string archivo;
    cout<<"Escribe el numero de caso de pureba a probar: ";
    cin>>archivo;
    while(!(archivo=="1"|archivo=="2"|archivo=="3"|archivo=="4")){
        cout<<"Elige solamente el numero entre 1 y 4: ";
        cin>>archivo;
    }
    archivo="0"+archivo+".in";
    //abrir archivo
	string s;
    int n;
	ifstream in(archivo);
    BST tree;
    while(!in.eof()){
        in >> n;
        tree.insert(n);
    }
    int valor, flag = 1,inciso;
    while(flag){
        cout<<"Que desea hacer? "<<endl<<"1) visit"<<endl<<"2) height"<<endl<<"3) ancestors"<<endl<<"4) whatLevelAmI"<<endl;
        cout<<"Escribe el numero del inciso: ";
        cin>>inciso;
        while(inciso<1||inciso>4){
            cout<<"Escribe el numero del inciso: ";
            cin>>inciso;
        }
        if(inciso==1){
            cout<<"1) Preorder"<<endl<<"2) Inorder"<<endl<<"3) Postorder"<<endl<<"4) Level by Level"<<endl<<"Escriba el numero de inciso: ";
            cin>> valor;
            while(valor<1||valor>4){
                cout<<"Escriba un inciso valido: ";
                cin>>valor;
            }
            tree.visit(valor);
        }else if(inciso==2){
            cout<<"Altura: "<<tree.height()<<endl;
        }else if(inciso==3){
            cout<<"De que dato se busca el ancestro? ";
            cin>>valor;
            tree.ancestors(valor);
        }else{
            cout<<"De que dato se busca el nivel? ";
            cin>>valor;
            cout<<"El dato "<<valor<<" esta en el nivel "<<tree.whatLevelAmI(valor)<<endl;
        }
        cout<<"Desea continuar? (0=no/1=si) ";
        cin>>flag;
    }


    return 0;
}