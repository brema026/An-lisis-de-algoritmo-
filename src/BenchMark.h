#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
#include <utility>  // Para std::forward

// Función genérica para medir el tiempo de ejecución de un algoritmo
template <typename Func, typename... Args>
long long medirTiempo(Func&& f, Args... args) {
    auto start = std::chrono::high_resolution_clock::now();
    std::forward<Func>(f)(args...);  // Pasa los argumentos sin std::forward, que puede causar problemas con rvalues
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

#endif // BENCHMARK_H
