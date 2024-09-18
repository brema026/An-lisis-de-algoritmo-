#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>

// Función genérica para medir el tiempo de ejecución de un algoritmo
template <typename Func, typename... Args>
long long medirTiempo(Func f, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now(); // Inicio del tiempo
    f(std::forward<Args>(args)...);                         // Ejecuta la función
    auto end = std::chrono::high_resolution_clock::now();   // Fin del tiempo
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();  // Tiempo en nanosegundos
}

#endif // BENCHMARK_H
