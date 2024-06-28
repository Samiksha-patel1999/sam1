#include <iostream>
using namespace std;

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        return;
    }
    // Move n-1 disks from source to auxiliary, using destination as auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    
    // Move n-1 disks from auxiliary to destination, using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;  // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;

    // Call the towerOfHanoi function with n disks, source rod 'A', destination rod 'C', and auxiliary rod 'B'
    towerOfHanoi(n, 'A', 'C', 'B');
    
    return 0;
}
