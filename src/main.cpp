#include <iostream>
#include <vector>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "Timer.h"
#include "BinarySearchTree.h"
#include "SortedLinkedList.h"

int main() {
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    Timer timer;

    // BubbleSort
    std::vector<int> bubbleData = data;
    timer.start();
    BubbleSort::sort(bubbleData);
    long long bubbleTime = timer.stop();
    std::cout << "BubbleSort duration: " << bubbleTime << " ns\n";

    // SelectionSort
    std::vector<int> selectionData = data;
    timer.start();
    SelectionSort::sort(selectionData);
    long long selectionTime = timer.stop();
    std::cout << "SelectionSort duration: " << selectionTime << " ns\n";

    // MergeSort
    std::vector<int> mergeData = data;
    timer.start();
    MergeSort::sort(mergeData);
    long long mergeTime = timer.stop();
    std::cout << "MergeSort duration: " << mergeTime << " ns\n";

    // Pruebas con SortedLinkedList
    SortedLinkedList sll;
    sll.insert(10);
    sll.insert(30);
    sll.insert(20);
    sll.insert(40);

    std::cout << "Sorted LinkedList: ";
    sll.display();

    timer.start();
    bool found = sll.search(20);
    long long searchTime = timer.stop();
    std::cout << "Search 20 in SortedLinkedList: " << (found ? "Found" : "Not Found") << " (Time: " << searchTime << " ns)\n";

    // Pruebas con BinarySearchTree
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "InOrder Traversal of BST: ";
    bst.inOrderTraversal();
    std::cout << std::endl;

    return 0;
}
