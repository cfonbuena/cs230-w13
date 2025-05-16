#include "main.hpp"

int main(){
    // Create heap using default constructor
    cout << "** Create heap using given size **" << endl;
    heap a(5);
    a.printHeap();

    // Build max heap
    cout << "Build Max Heap" << endl;
    a.buildMaxHeap();
    a.printHeap();

    // Sort default heap
    cout << "Heap Sort" << endl;
    a.heapSort();
    a.printHeap();

    // --- Providing a vector --- //
    cout << "\t" << endl;
    // Create heap from vector array
    vector<int> array = {9, 1, 5, 3, 7};
    cout << "** Create heap using given array **" << endl;
    heap b(array);
    b.printHeap();

    // Build max heap
    cout << "Build Max Heap" << endl;
    b.buildMaxHeap();
    b.printHeap();
    
    // Heap Sort
    cout << "Heap Sort" << endl;
    b.heapSort();
    b.printHeap();

}
