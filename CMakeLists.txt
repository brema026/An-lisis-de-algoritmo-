cmake_minimum_required(VERSION 3.28)
project(AAlgoritmo)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-stack-protector")
# Buscar GTK y sus dependencias
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
pkg_check_modules(CAIRO REQUIRED cairo)

# Incluir los directorios de GTK
include_directories(${GTK_INCLUDE_DIRS})

# Agregar flags de compilación y enlace para GTK
link_directories(${GTK_LIBRARY_DIRS})
add_definitions(${GTK_CFLAGS_OTHER})

# Crear el ejecutable AAlgoritmo
add_executable(AAlgoritmo
        src/main.cpp
        src/BubbleSort.cpp
        src/BubbleSort.h
        src/BenchMark.h
        src/SelectionSort.cpp
        src/SelectionSort.h
        src/MergeSort.cpp
        src/MergeSort.h
        src/SortedLinkedList.cpp
        src/SortedLinkedList.h
        src/BinarySearchTree.cpp
        src/BinarySearchTree.h
        src/benchmark_graph.cpp
        src/benchmark_graph.h
)

# Enlazar GTK y Cairo con el ejecutable
target_link_libraries(AAlgoritmo ${GTK_LIBRARIES} ${CAIRO_LIBRARIES})

