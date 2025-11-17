#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool bigO_example1(double x) {
    double f = 2 * pow(x, 2) + 5;
    double g = pow(x, 2);
    double M = 7;
    return f <= M * g;
}

bool bigO_example2(double K, double c, double x) {
    double f = K * pow(x, c);
    double g = pow(x, c + 1);
    double M = K;
    return f <= M * g;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    double x = 10;
    cout << "2x^2 + 5 = O(x^2)? " << (bigO_example1(x) ? "True" : "False") << endl;

    double K = 3, c = 2;
    cout << "Kx^c = O(x^(c+1))? " << (bigO_example2(K, c, x) ? "True" : "False") << endl;

    int n = 29;
    cout << "Is " << n << " prime? " << (isPrime(n) ? "Yes" : "No") << endl;

    vector<int> arr = {5, 2, 4, 6, 1, 3};
    insertionSort(arr);
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
