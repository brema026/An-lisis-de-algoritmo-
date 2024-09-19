#ifndef BENCHMARK_GRAPH_H
#define BENCHMARK_GRAPH_H

#include <string>
#include <gtk/gtk.h>
#include <vector>

class BenchmarkGraph {
public:
    BenchmarkGraph(const std::vector<std::vector<long long>>& tiempos, const std::vector<std::string>& algoritmos);
    void mostrarGrafica(int tipoCaso);

private:
    GtkWidget *window;
    std::vector<std::vector<long long>> tiempos;  // Tiempos para cada algoritmo en mejor, peor y promedio
    std::vector<std::string> algoritmos;
    int tipoCaso; // 0: Mejor caso, 1: Peor caso, 2: Promedio

    static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data);
    void draw_chart(cairo_t *cr);
};

#endif // BENCHMARK_GRAPH_H
