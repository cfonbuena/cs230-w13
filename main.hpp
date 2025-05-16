#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class heap {
    private:
        vector<int> arr;
        int size;
    public:
        heap() :  size(0) {};
        heap(int n) : size(n) {
            arr.resize(n);
            srand(time(0));
            for (int i = 0; i < n; i++)
                arr[i] = rand() % 50;
        };
        heap(const vector<int>& v) : arr(v), size(v.size()) {};
        void heapify(vector<int> &arr, int size, int idx);
        void buildMaxHeap();
        // void buildMinHeap(); // needs separate heapify function
        void printHeap();
        void heapSort();
};

void heap::heapify(vector<int> &arr, int size, int idx){
    int largest = idx;
    int left = ((2 * idx) + 1);
    int right = ((2 * idx) + 2);
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != idx) {
        swap(arr[idx], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heap::buildMaxHeap(){
    int N = ((arr.size() / 2) - 1);
    for (int i = N; i >= 0; i--)
        heapify(arr, size, i);
}

void heap::printHeap(){
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

void heap::heapSort(){
    int N = arr.size();
    for (int i = ((N / 2) - 1); i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
