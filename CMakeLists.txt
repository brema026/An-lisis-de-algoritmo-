cmake_minimum_required(VERSION 3.28)
project(AAlgoritmo)

set(CMAKE_CXX_STANDARD 26)

add_executable(AAlgoritmo src/main.cpp
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
        src/BinarySearchTree.h)
