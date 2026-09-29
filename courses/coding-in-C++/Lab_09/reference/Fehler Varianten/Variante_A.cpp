#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[4] = {5, 2, 8, 1};
    int n = 4;

    for (int i = 0; i < n - 1 - i; i++) {
        for (int j = 0; j < n - 1; j++) {   //<= war falsch
            if (arr[j] > arr[j + 1]) {      //Größer mit kleiner vertauscht
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printArray(arr, n);
    }

    return 0;
}