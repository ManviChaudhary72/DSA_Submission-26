
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char dest) {
    if (n == 0) {
        return;
    }

    towerOfHanoi(n - 1, source, dest, helper);

    cout << "Move disk " << n << " from "
         << source << " to " << dest << endl;

    towerOfHanoi(n - 1, helper, source, dest);
}

int main() {
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    if (n < 0) {
        cout << "Number of disks cannot be negative.";
        return 0;
    }

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
