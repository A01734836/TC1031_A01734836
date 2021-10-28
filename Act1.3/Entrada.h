struct Entrada{
        int fecha;
        int mes;
        string sMes;
        string sDia;
        string hora;
        string IP;
        string razon;
    //Constructores
        Entrada();
        Entrada(int,int,string,string,string);
    //Setters
        void setFecha(string m, int d);
    //Otros
        void imprimir();
};

Entrada :: Entrada(){
    fecha = 0;
    hora = "";
    IP = "";
    razon = "";
}

Entrada :: Entrada(int m,int d,string h,string i,string r){
    fecha = m * 100 + d;
    hora = h;
    IP = i;
    razon = r;
}

void Entrada :: setFecha(string m, int d){
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

void Entrada :: imprimir(){
    cout << sMes << " " << sDia << " " << hora << " " << IP << " " << razon << endl;
}