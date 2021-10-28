#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <bits.h>

struct Entrada{
        int fecha;
        int mes;
        string sMes;
        string sDia;
        string hora;
        string IP;
        long long decIP;
        int IP1;
        int IP2;
        int IP3;
        int IP4;
        int puerto;
        string razon;
    //Constructores
        Entrada();
        Entrada(int,int,string,string,string);
    //Setters
        void setFecha(string m, int d);
        void setIPports();
    //Otros
        void imprimir();
};

Entrada::Entrada(){
    fecha = 0;
    hora = "";
    IP = "";
    razon = "";
}
Entrada::Entrada(int m,int d,string h,string i,string r){
    fecha = m * 100 + d;
    hora = h;
    IP = i;
    razon = r;
}

void Entrada::imprimir(){
    cout << sMes << " " << sDia << " " << hora << " " << IP << " " << razon << endl;
}

void Entrada::setFecha(string m, int d){
    string meses[5] = {"Jun","Jul","Aug","Sep","Oct"};
    for(int i = 0; i < 5; i++){
        if(meses[i] == m){
            mes = i + 6;
        }
    }
    int pfecha = mes * 100 + d;
    stringstream sM,sD,sF;
    sM << m; sD << d;
    sMes = sM.str();
    sDia = sD.str();
    sF << pfecha << hora[0] << hora[1] << hora[3] << hora[4] << hora[6] << hora[7];
    fecha = stoi(sF.str());
}

void Entrada::setIPports(){
    stringstream ssIP, finalIP;
    string dato;
    int columna = 0;
    for(int i = 0; i < this->IP.size(); i++){
        if(this->IP[i] != ':'){
            ssIP << this->IP[i];
        }
        else{
            break;
        }
    }
    while(getline(ssIP, dato, '.')){
        //cout << dato << endl;
        switch(columna++){
            case 0:
                IP1 = stoi(dato);
                for(int i = 0; i < 3 - dato.size(); i++){
                    finalIP << "0";
                }
                finalIP << IP1;
                break;
            case 1:
                IP2 = stoi(dato);
                for(int i = 0; i < 2 - dato.size(); i++){
                    finalIP << "0";
                }
                finalIP << IP2;
                break;
            case 2:
                IP3 = stoi(dato);
                for(int i = 0; i < 3 - dato.size(); i++){
                    finalIP << "0";
                }
                finalIP << IP3;
                break;
            case 3:
                IP4 = stoi(dato);
                for(int i = 0; i < 3 - dato.size(); i++){
                    finalIP << "0";
                }
                finalIP << IP4;
                break;
        }
    }
    decIP = stoll(finalIP.str());
}