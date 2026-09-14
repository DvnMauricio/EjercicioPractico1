#include <iostream>
#include <string>

struct Elemento{
    std::string Codigo;
    std::string Nombre;
    float Longitud;
    float cargas[3];
    float Capacidad;
    float Factor;
    std::string Seguridad;

};

void registrarElemento(Elemento &elemento){
    std:: cout << "\n---REGISTRO DE ELEMENTO---\n" << std::endl;

    std::cout << "Codigo: " << std::endl;
    
    std::cin >> elemento.Codigo;
    
    std::cin.ignore();

    std::cout << "Nombre: " << std::endl;

    getline(std::cin, elemento.Nombre);

    std::cout << "Longitud (m): " << std::endl;

    std::cin >> elemento.Longitud;

    std::cout << "Cargas(N): " << std::endl;

    std::cin >> elemento.cargas[1];

    std::cin >> elemento.cargas[2];

    std::cin >> elemento.cargas[3];

    std::cout << "Capacidad maxima: " << std::endl;

    std::cin >> elemento.Capacidad;
}
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

    for(int i = 0; i < cantidad ; i++){
        std::cout << "\n Elemento #" << i + 1 << std::endl;
        
        registrarElemento(elementos[i]);
    }
    return 0;
}



