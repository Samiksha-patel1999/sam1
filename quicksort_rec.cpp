#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int down, int up) {
    int start = a[down];  // start is Pivot element
    int left = down + 1;
    int right = up;

    while (left <= right) {
        // Move left while elements are less than or equal to pivot
        while (left <= right && a[left] <= start) {
            left++;
        }
        // Move right while elements are greater than pivot
        while (left <= right && a[right] > start) {
            right--;
        }
        // Swap elements if left is still less than or equal to right
        if (left <= right) {
            swap(a[left], a[right]);
        }
    }
    // Swap pivot with the element at the 'right' index
    swap(a[down], a[right]);

    // Return the partition index
    return right;
}

void quicksort(int a[], int down, int up) {
    if (down < up) {
        int j = partition(a, down, up);
        quicksort(a, down, j - 1);
        quicksort(a, j + 1, up);
    }
}

int main() {
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int a[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    quicksort(a, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
