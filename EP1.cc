#include <iostream>

struct Elemento{
    std::string Codigo;
    std::string Nombre;
    float Longitud;
    float cargas[3];
    float Capacidad;
    float Factor;
    std::string Seguridad;

};
int main (){

    Elemento elementos[10];

    int cantidad;

    do{
        std::cout << "Cuantos elementos desea registrar?" << std::endl;
        std::cin >> cantidad;

        if (cantidad < 1 || cantidad > 10){
            std::cout << "Cantidad de elementos invalida, deben de ser entre 1 a 10 elementos" << std::endl;
        }

    } while (cantidad < 1 || cantidad > 10);

    return 0;
}


