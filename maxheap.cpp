#include <iostream>
using namespace std;

// Function to heapify a subtree rooted with node i which is an index in array[].
// n is the size of the heap.
void heapify(int array[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && array[left] > array[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && array[right] > array[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(array[i], array[largest]);

        // Recursively heapify the affected sub-tree
        heapify(array, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int array[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(array[0], array[i]);

        // Call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

int main() {
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int array[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    heapSort(array, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
