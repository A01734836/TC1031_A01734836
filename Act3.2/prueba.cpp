#include "priority_queue.h"

int main(){
    priority_queue fila;
    cout<<fila.empty()<<endl;
    fila.push(100);
    fila.push(110);
    fila.push(150);
    fila.push(20);
    fila.push(40);
    fila.push(1);
    fila.push(2);
    cout<<fila.empty()<<endl;
    cout<<fila.top()<<endl;
    fila.print();
    cout<<fila.size()<<endl;
    fila.pop();
    cout<<fila.size()<<endl;
    cout<<fila.top()<<endl;
    fila.print();
    return 0;
}