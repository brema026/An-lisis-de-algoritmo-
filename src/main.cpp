#include <iostream>
#include <vector>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "BenchMark.h"
#include "BinarySearchTree.h"
#include "SortedLinkedList.h"
#include "benchmark_graph.h"

// Función para generar un array ordenado (mejor caso)
std::vector<int> generarMejorCaso(int N) {
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = i;
    }
    return arr;
}

// Función para generar un array invertido (peor caso)
std::vector<int> generarPeorCaso(int N) {
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = N - i;
    }
    return arr;
}

// Función para generar un array aleatorio (caso promedio)
std::vector<int> generarCasoPromedio(int N) {
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 10000;
    }
    return arr;
}

// Función para ejecutar pruebas con diferentes algoritmos y estructuras de datos
void ejecutarPruebas(int N) {
    std::vector<int> mejorCaso = generarMejorCaso(N);
    std::vector<int> peorCaso = generarPeorCaso(N);
    std::vector<int> casoPromedio = generarCasoPromedio(N);

    long long tiempoMejor, tiempoPeor, tiempoPromedio;

    // BubbleSort
    tiempoMejor = medirTiempo(BubbleSort::sort, mejorCaso);
    tiempoPeor = medirTiempo(BubbleSort::sort, peorCaso);
    tiempoPromedio = medirTiempo(BubbleSort::sort, casoPromedio);

    std::cout << "BubbleSort - N: " << N << "\n";
    std::cout << "Mejor caso: " << tiempoMejor << " ns\n";
    std::cout << "Peor caso: " << tiempoPeor << " ns\n";
    std::cout << "Caso promedio: " << tiempoPromedio << " ns\n";

    // SelectionSort
    tiempoMejor = medirTiempo(SelectionSort::sort, mejorCaso);
    tiempoPeor = medirTiempo(SelectionSort::sort, peorCaso);
    tiempoPromedio = medirTiempo(SelectionSort::sort, casoPromedio);

    std::cout << "SelectionSort - N: " << N << "\n";
    std::cout << "Mejor caso: " << tiempoMejor << " ns\n";
    std::cout << "Peor caso: " << tiempoPeor << " ns\n";
    std::cout << "Caso promedio: " << tiempoPromedio << " ns\n";

    // MergeSort
    tiempoMejor = medirTiempo(MergeSort::sort, mejorCaso);
    tiempoPeor = medirTiempo(MergeSort::sort, peorCaso);
    tiempoPromedio = medirTiempo(MergeSort::sort, casoPromedio);

    std::cout << "MergeSort - N: " << N << "\n";
    std::cout << "Mejor caso: " << tiempoMejor << " ns\n";
    std::cout << "Peor caso: " << tiempoPeor << " ns\n";
    std::cout << "Caso promedio: " << tiempoPromedio << " ns\n";

    // Búsqueda en LinkedList
    SortedLinkedList lista;
    for (int i = 0; i < N; ++i) {
        lista.insert(i);
    }
    tiempoMejor = medirTiempo([&]() { lista.search(0); }); // Mejor caso: buscar el primer elemento
    tiempoPeor = medirTiempo([&]() { lista.search(N - 1); }); // Peor caso: buscar el último
    tiempoPromedio = medirTiempo([&]() { lista.search(N / 2); }); // Caso promedio: buscar en el medio

    std::cout << "LinkedList Search - N: " << N << "\n";
    std::cout << "Mejor caso: " << tiempoMejor << " ns\n";
    std::cout << "Peor caso: " << tiempoPeor << " ns\n";
    std::cout << "Caso promedio: " << tiempoPromedio << " ns\n";

    // Inserción en Binary Search Tree
    BinarySearchTree bst;
    tiempoMejor = medirTiempo([&]() {
        for (int i = 0; i < N; ++i) {
            bst.insert(i); // Mejor caso: insertar ordenado
        }
    });

    tiempoPeor = medirTiempo([&]() {
        for (int i = N; i > 0; --i) {
            bst.insert(i); // Peor caso: insertar en orden inverso
        }
    });

    tiempoPromedio = medirTiempo([&]() {
        for (int i = 0; i < N; ++i) {
            bst.insert(rand() % 10000); // Caso promedio: insertar números aleatorios
        }
    });

    std::cout << "Binary Search Tree Insert - N: " << N << "\n";
    std::cout << "Mejor caso: " << tiempoMejor << " ns\n";
    std::cout << "Peor caso: " << tiempoPeor << " ns\n";
    std::cout << "Caso promedio: " << tiempoPromedio << " ns\n";
}

int main() {
    srand(time(NULL));

    std::vector<std::vector<long long>> tiemposAlgoritmos(3); // Mejor caso, Peor caso, Promedio
    std::vector<std::string> algoritmos = {"BubbleSort", "SelectionSort", "MergeSort", "LinkedList", "BST"};

    for (int N : {100, 1000, 5000}) {
        std::vector<long long> mejorCaso, peorCaso, casoPromedio;

        std::vector<int> mejorCasoArray = generarMejorCaso(N);
        std::vector<int> peorCasoArray = generarPeorCaso(N);
        std::vector<int> casoPromedioArray = generarCasoPromedio(N);

        // BubbleSort
        mejorCaso.push_back(medirTiempo(BubbleSort::sort, mejorCasoArray));
        peorCaso.push_back(medirTiempo(BubbleSort::sort, peorCasoArray));
        casoPromedio.push_back(medirTiempo(BubbleSort::sort, casoPromedioArray));

        // SelectionSort
        mejorCaso.push_back(medirTiempo(SelectionSort::sort, mejorCasoArray));
        peorCaso.push_back(medirTiempo(SelectionSort::sort, peorCasoArray));
        casoPromedio.push_back(medirTiempo(SelectionSort::sort, casoPromedioArray));

        // MergeSort
        mejorCaso.push_back(medirTiempo(MergeSort::sort, mejorCasoArray));
        peorCaso.push_back(medirTiempo(MergeSort::sort, peorCasoArray));
        casoPromedio.push_back(medirTiempo(MergeSort::sort, casoPromedioArray));

        // LinkedList Search
        SortedLinkedList lista;
        for (int i = 0; i < N; ++i) {
            lista.insert(i);
        }
        mejorCaso.push_back(medirTiempo([&]() { lista.search(0); }));
        peorCaso.push_back(medirTiempo([&]() { lista.search(N - 1); }));
        casoPromedio.push_back(medirTiempo([&]() { lista.search(N / 2); }));

        // BST Insert
        BinarySearchTree bst;
        mejorCaso.push_back(medirTiempo([&]() {
            for (int i = 0; i < N; ++i) {
                bst.insert(i);
            }
        }));
        peorCaso.push_back(medirTiempo([&]() {
            for (int i = N; i > 0; --i) {
                bst.insert(i);
            }
        }));
        casoPromedio.push_back(medirTiempo([&]() {
            for (int i = 0; i < N; ++i) {
                bst.insert(rand() % 10000);
            }
        }));

        // Guardar los resultados de este tamaño de N
        tiemposAlgoritmos[0] = mejorCaso;
        tiemposAlgoritmos[1] = peorCaso;
        tiemposAlgoritmos[2] = casoPromedio;
    }

    // Mostrar gráficas para cada caso
    BenchmarkGraph graph(tiemposAlgoritmos, algoritmos);
    graph.mostrarGrafica(0); // 0 = Mejor caso
    graph.mostrarGrafica(1); // 1 = Peor caso
    graph.mostrarGrafica(2); // 2 = Caso promedio

    return 0;
}
