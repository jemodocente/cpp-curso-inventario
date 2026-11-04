#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTOS = 50;
const int MESES = 12;

void agregarProducto(int ids[], string nombres[], float precios[],
                     int cantidades[], int &totalProductos) {
    if (totalProductos >= MAX_PRODUCTOS) {
        cout << "Error: inventario lleno (maximo " << MAX_PRODUCTOS << ").\n";
        return;
    }

    ids[totalProductos] = totalProductos + 1;   // ID automatico: 1, 2, 3...

    cout << "Nombre: ";
    getline(cin, nombres[totalProductos]);

    cout << "Precio: ";
    cin >> precios[totalProductos];

    cout << "Cantidad en stock: ";
    cin >> cantidades[totalProductos];

    totalProductos++;
    cout << "Producto agregado con ID " << ids[totalProductos - 1] << ".\n";
}

void mostrarInventario(const int ids[], const string nombres[],
                       const float precios[], const int cantidades[],
                       int totalProductos) {
    if (totalProductos == 0) {
        cout << "No hay productos registrados.\n";
        return;
    }

    cout << fixed;
    cout.precision(2);

    for (int i = 0; i < totalProductos; i++) {
        cout << "\nProducto #" << i + 1 << "\n";
        cout << "  ID     : " << ids[i] << "\n";
        cout << "  Nombre : " << nombres[i] << "\n";
        cout << "  Precio : $" << precios[i] << "\n";
        cout << "  Stock  : " << cantidades[i] << "\n";
    }
}

int main() {
    int ids[MAX_PRODUCTOS] = {};
    string nombres[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS] = {};
    int cantidades[MAX_PRODUCTOS] = {};
    int ventasMensuales[MESES][MAX_PRODUCTOS] = {};
    int totalProductos = 0;

    int opcion;

    do {
        cout << "\n===== SISTEMA DE INVENTARIO =====\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Registrar venta\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarProducto(ids, nombres, precios, cantidades, totalProductos);
                break;
            case 2:
                mostrarInventario(ids, nombres, precios, cantidades, totalProductos);
                break;
            case 3:
                cout << "[Aqui iria Registrar venta]\n";
                break;
            case 4:
                cout << "Hasta luego!\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);

    return 0;
}