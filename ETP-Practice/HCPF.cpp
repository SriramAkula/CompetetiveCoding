#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Recursive function to compute GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find the largest prime factor of a number
int largestPrimeFactor(int num) {
    int largest = 1;
    // Check for factors of 2
    while (num % 2 == 0) {
        largest = 2;
        num /= 2;
    }
    // Check for factors of odd numbers
    for (int i = 3; i <= sqrt(num); i += 2) {
        while (num % i == 0) {
            largest = i;
            num /= i;
        }
    }
    // If num is a prime number greater than 2
    if (num > 2) {
        largest = num;
    }
    return largest;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // Reading input numbers
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate GCD of the entire array
    int overallGCD = arr[0];
    for (int i = 1; i < n; i++) {
        overallGCD = gcd(overallGCD, arr[i]);
        // If GCD becomes 1, no common prime factor exists
        if (overallGCD == 1) {
            cout << 1;
            return 0;
        }
    }

    // Find and print the largest prime factor of the overall GCD
    cout << largestPrimeFactor(overallGCD) << endl;

    return 0;
}
