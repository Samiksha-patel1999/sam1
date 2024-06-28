#include <iostream>
using namespace std;

// Function to heapify a subtree with root at given index
void heapify(int array[], int n, int i) {
    int smallest = i;    // Initialize smallest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is smaller than root
    if (left < n && array[left] < array[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && array[right] < array[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(array[i], array[smallest]);

        // Recursively heapify the affected sub-tree
        heapify(array, n, smallest);
    }
}

// Function to build a Min-Heap from the array
void buildMinHeap(int arr[], int n) {
    // Index of last non-leaf node
    int startIndex = (n / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify each node
    for (int i = startIndex; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to perform Heap Sort
void heapSort(int array[], int n) {
    // Build the Min-Heap
    buildMinHeap(array, n);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(array[0], array[i]);

        // Call min heapify on the reduced heap
        heapify(array, i, 0);
    }
}

int main() {
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    heapSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
