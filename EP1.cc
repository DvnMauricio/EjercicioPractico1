#include <iostream>
#include <string>

using namespace std;

// ==========================================
// PARTE 1 - MODELADO DEL ELEMENTO
// ==========================================

struct Elemento {
    string Codigo;
    string Nombre;
    float Longitud;
    float cargas[3];
    float Capacidad;
    float Factor;
    string Seguridad;
};


// ==========================================
// PARTE 2 - REGISTRO DE ELEMENTOS
// ==========================================

void registrarElemento(Elemento &elemento) {

    cout << "\n--- REGISTRO DE ELEMENTO ---\n" << endl;

    cout << "Codigo: ";
    cin >> elemento.Codigo;

    cin.ignore();

    cout << "Nombre: ";
    getline(cin, elemento.Nombre);

    cout << "Longitud (m): ";
    cin >> elemento.Longitud;

    cout << "Carga 1 (N): ";
    cin >> elemento.cargas[0];

    cout << "Carga 2 (N): ";
    cin >> elemento.cargas[1];

    cout << "Carga 3 (N): ";
    cin >> elemento.cargas[2];

    cout << "Capacidad maxima (N): ";
    cin >> elemento.Capacidad;
}


// ==========================================
// PARTE 3 - CALCULO DEL FACTOR
// ==========================================

float calcularFactor(Elemento *elemento) {

    float promedio;

    promedio = (elemento->cargas[0] +
                elemento->cargas[1] +
                elemento->cargas[2]) / 3;

    elemento->Factor = promedio / elemento->Capacidad;

    return elemento->Factor;
}


// ==========================================
// PARTE 4 - DETERMINAR SEGURIDAD
// ==========================================

void determinarSeguridad(Elemento &elemento) {

    if (elemento.Factor >= 0.00 && elemento.Factor <= 0.50) {
        elemento.Seguridad = "SEGURO";
    }
    else if (elemento.Factor > 0.50 && elemento.Factor <= 0.80) {
        elemento.Seguridad = "PRECAUCION";
    }
    else if (elemento.Factor > 0.80 && elemento.Factor <= 1.00) {
        elemento.Seguridad = "RIESGO";
    }
    else if (elemento.Factor > 1.00) {
        elemento.Seguridad = "SOBRECARGA";
    }
}


// ==========================================
// PARTE 5 - ELEMENTO MAS COMPROMETIDO
// ==========================================

Elemento* obtenerElementoCritico(Elemento elementos[], int cantidad) {

    Elemento *critico = &elementos[0];

    for (Elemento *ptr = elementos + 1;
         ptr < elementos + cantidad;
         ptr++) {

        if (ptr->Factor > critico->Factor) {
            critico = ptr;
        }
    }

    return critico;
}


// ==========================================
// PARTE 6 - AUMENTAR CARGAS
// ==========================================

void aumentarCargas(Elemento &elemento, float porcentaje) {

    elemento.cargas[0] =
        elemento.cargas[0] * (1 + porcentaje / 100);

    elemento.cargas[1] =
        elemento.cargas[1] * (1 + porcentaje / 100);

    elemento.cargas[2] =
        elemento.cargas[2] * (1 + porcentaje / 100);

    // Volvemos a calcular el factor
    calcularFactor(&elemento);

    // Volvemos a determinar la seguridad
    determinarSeguridad(elemento);
}


// ==========================================
// PARTE 7 - GENERAR INFORME
// ==========================================

void generarInforme(Elemento elementos[], int cantidad) {

    int seguros = 0;
    int precaucion = 0;
    int riesgo = 0;
    int sobrecarga = 0;

    float sumaFactores = 0;

    cout << "\n";
    cout << "=============================================\n";
    cout << "              INFORME GENERAL\n";
    cout << "=============================================\n";

    for (int i = 0; i < cantidad; i++) {

        float promedio =
            (elementos[i].cargas[0] +
             elementos[i].cargas[1] +
             elementos[i].cargas[2]) / 3;

        cout << "\nElemento #" << i + 1 << endl;
        cout << "Codigo: " << elementos[i].Codigo << endl;
        cout << "Nombre: " << elementos[i].Nombre << endl;
        cout << "Carga promedio: " << promedio << " N" << endl;
        cout << "Factor de utilizacion: "
             << elementos[i].Factor << endl;
        cout << "Estado: " << elementos[i].Seguridad << endl;

        sumaFactores += elementos[i].Factor;

        if (elementos[i].Seguridad == "SEGURO") {
            seguros++;
        }
        else if (elementos[i].Seguridad == "PRECAUCION") {
            precaucion++;
        }
        else if (elementos[i].Seguridad == "RIESGO") {
            riesgo++;
        }
        else if (elementos[i].Seguridad == "SOBRECARGA") {
            sobrecarga++;
        }
    }

    float factorPromedio = sumaFactores / cantidad;

    cout << "\n";
    cout << "=============================================\n";
    cout << "          RESUMEN DE LA ESTRUCTURA\n";
    cout << "=============================================\n";

    cout << "Elementos SEGUROS: " << seguros << endl;
    cout << "Elementos en PRECAUCION: " << precaucion << endl;
    cout << "Elementos en RIESGO: " << riesgo << endl;
    cout << "Elementos en SOBRECARGA: " << sobrecarga << endl;

    cout << "Factor de utilizacion promedio: "
         << factorPromedio << endl;
}


// ==========================================
// MAIN
// ==========================================

int main() {

    Elemento elementos[10];

    int cantidad;

    // ------------------------------------------
    // Solicitar cantidad de elementos
    // ------------------------------------------

    do {

        cout << "Cuantos elementos desea registrar? ";
        cin >> cantidad;

        if (cantidad < 1 || cantidad > 10) {
            cout << "Cantidad de elementos invalida."
                 << " Debe ser entre 1 y 10.\n";
        }

    } while (cantidad < 1 || cantidad > 10);


    // ------------------------------------------
    // Registrar los elementos
    // ------------------------------------------

    for (int i = 0; i < cantidad; i++) {

        cout << "\n=============================================\n";
        cout << "Elemento #" << i + 1 << endl;
        cout << "=============================================\n";

        registrarElemento(elementos[i]);
    }


    // ------------------------------------------
    // Calcular factor y seguridad
    // ------------------------------------------

    for (Elemento *ptr = elementos;
         ptr < elementos + cantidad;
         ptr++) {

        calcularFactor(ptr);
        determinarSeguridad(*ptr);
    }


    // ------------------------------------------
    // Mostrar elemento critico
    // ------------------------------------------

    Elemento *critico =
        obtenerElementoCritico(elementos, cantidad);

    cout << "\n";
    cout << "=============================================\n";
    cout << "          ELEMENTO MAS COMPROMETIDO\n";
    cout << "=============================================\n";

    cout << "Codigo: " << critico->Codigo << endl;
    cout << "Nombre: " << critico->Nombre << endl;
    cout << "Longitud: " << critico->Longitud << " m" << endl;

    cout << "Carga 1: "
         << critico->cargas[0] << " N" << endl;

    cout << "Carga 2: "
         << critico->cargas[1] << " N" << endl;

    cout << "Carga 3: "
         << critico->cargas[2] << " N" << endl;

    cout << "Capacidad maxima: "
         << critico->Capacidad << " N" << endl;

    cout << "Factor de utilizacion: "
         << critico->Factor << endl;

    cout << "Estado de seguridad: "
         << critico->Seguridad << endl;


    // ------------------------------------------
    // Simulacion de incremento de carga
    // ------------------------------------------

    float porcentaje;

    cout << "\n";
    cout << "=============================================\n";
    cout << "       SIMULACION DE INCREMENTO DE CARGA\n";
    cout << "=============================================\n";

    cout << "Ingrese el porcentaje de incremento: ";
    cin >> porcentaje;

    aumentarCargas(*critico, porcentaje);


    // ------------------------------------------
    // Mostrar resultados despues del incremento
    // ------------------------------------------

    cout << "\n";
    cout << "=============================================\n";
    cout << "       RESULTADO DESPUES DEL INCREMENTO\n";
    cout << "=============================================\n";

    cout << "Codigo: " << critico->Codigo << endl;
    cout << "Nombre: " << critico->Nombre << endl;

    cout << "Carga 1: "
         << critico->cargas[0] << " N" << endl;

    cout << "Carga 2: "
         << critico->cargas[1] << " N" << endl;

    cout << "Carga 3: "
         << critico->cargas[2] << " N" << endl;

    cout << "Factor de utilizacion: "
         << critico->Factor << endl;

    cout << "Estado de seguridad: "
         << critico->Seguridad << endl;


    // ------------------------------------------
    // Generar informe final
    // ------------------------------------------

    generarInforme(elementos, cantidad);


    return 0;
}