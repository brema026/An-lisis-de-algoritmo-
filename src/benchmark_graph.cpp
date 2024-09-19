#include "benchmark_graph.h"
#include <cairo.h>
#include <iostream>
#include <algorithm>

BenchmarkGraph::BenchmarkGraph(const std::vector<std::vector<long long>>& tiempos, const std::vector<std::string>& algoritmos)
    : tiempos(tiempos), algoritmos(algoritmos) {}

void BenchmarkGraph::mostrarGrafica(int tipoCaso) {
    this->tipoCaso = tipoCaso;

    gtk_init(0, nullptr);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600); // Aumentar tamaño para más detalle
    gtk_window_set_title(GTK_WINDOW(window), "Benchmark");

    GtkWidget *darea = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), darea);

    g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(on_draw_event), this);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();
}

gboolean BenchmarkGraph::on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    BenchmarkGraph *graph = static_cast<BenchmarkGraph*>(user_data);
    graph->draw_chart(cr);
    return FALSE;
}

void BenchmarkGraph::draw_chart(cairo_t *cr) {
    int width = 600;
    int height = 400;

    cairo_set_source_rgb(cr, 1, 1, 1); // Fondo blanco
    cairo_paint(cr);

    // Definir márgenes y espacio entre barras
    int margin = 50;
    int bar_width = 40;
    int spacing = 30;

    // Títulos
    cairo_set_source_rgb(cr, 0, 0, 0); // Color negro para el texto
    cairo_set_font_size(cr, 12);
    cairo_move_to(cr, width / 2 - 50, margin / 2 + 20); // Aumentar espacio superior

    // Etiqueta para el tipo de caso
    std::string tipoCasoTexto;
    switch (tipoCaso) {
        case 0: tipoCasoTexto = "Mejor Caso"; break;
        case 1: tipoCasoTexto = "Peor Caso"; break;
        case 2: tipoCasoTexto = "Caso Promedio"; break;
    }

    cairo_move_to(cr, width / 2 - 50, margin + 20); // Añadir espacio entre títulos
    cairo_show_text(cr, tipoCasoTexto.c_str());

    // Dibujar el gráfico de barras
    int x = margin;
    int max_height = height - 2 * margin;

    std::vector<long long> tiemposCaso = tiempos[tipoCaso];
    long long maxTime = *std::max_element(tiemposCaso.begin(), tiemposCaso.end());

    for (size_t i = 0; i < tiemposCaso.size(); ++i) {
        double bar_height = (double)tiemposCaso[i] / maxTime * max_height;

        cairo_set_source_rgb(cr, 0.2, 0.5, 0.8);
        cairo_rectangle(cr, x, height - margin - bar_height, bar_width, bar_height);
        cairo_fill(cr);

        cairo_move_to(cr, x, height - margin + 20);
        cairo_set_source_rgb(cr, 0, 0, 0);
        cairo_set_font_size(cr, 10);
        cairo_show_text(cr, algoritmos[i].c_str());

        x += bar_width + spacing;
    }

    // Ejes
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_move_to(cr, margin, height - margin);
    cairo_line_to(cr, width - margin, height - margin);
    cairo_line_to(cr, width - margin, margin);
    cairo_stroke(cr);

    // Etiquetas de los ejes
    cairo_move_to(cr, width / 2, height - 10);
    cairo_show_text(cr, "Algoritmos");

    cairo_move_to(cr, 5, height / 2); // Mover título del eje Y a la izquierda
    cairo_show_text(cr, "Tiempo (ns)");

    // Etiquetas en el eje Y
    cairo_set_font_size(cr, 10);
    int y_line_spacing = 40;
    int y_label_count = max_height / y_line_spacing;

    for (int i = 0; i <= y_label_count; ++i) {
        int y_position = height - margin - i * y_line_spacing;
        long long y_value = i * (maxTime / y_label_count);
        cairo_move_to(cr, margin - 40, y_position + 5);
        cairo_show_text(cr, std::to_string(y_value).c_str());
    }
}
