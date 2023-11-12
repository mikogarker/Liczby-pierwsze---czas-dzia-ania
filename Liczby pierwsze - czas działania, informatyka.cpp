#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool isPrimeA(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0 && i != n) {
            return false;
        }
    }
    return true;
}

bool isPrimeB(int n) {
    if (n <= 1) return false;
    for (int i = 3; i <= n; i += 2) {
        if (n % i == 0 && i != n) {
            return false;
        }
    }
    return true;
}

bool isPrimeC(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0 && i != n) {
            return false;
        }
    }
    return true;
}

void sieveOfEratosthenes(int n) {
    bool *prime = new bool[n + 1];
    memset(prime, true, sizeof(bool) * (n + 1));

    for (int p = 2; p * p <= n; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Count and print primes
    int count = 0;
    for (int p = 2; p <= n; ++p) {
        if (prime[p]) {
            count++;
        }
    }
    cout << "Function D: " << count << " primes found using Sieve of Eratosthenes.\n";

    delete[] prime;
}

int main() {
    const int testCases[] = {1000, 10000, 100000, 1000000};

    for (int n : testCases) {
        auto start_time = high_resolution_clock::now();
        // Function A
        for (int i = 1; i <= n; ++i) {
            isPrimeA(i);
        }
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end_time - start_time);
        cout << "Function A: " << n << " Time: " << duration.count() << " ms\n";

        start_time = high_resolution_clock::now();
        // Function B
        for (int i = 1; i <= n; ++i) {
            isPrimeB(i);
        }
        end_time = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end_time - start_time);
        cout << "Function B: " << n << " Time: " << duration.count() << " ms\n";

        start_time = high_resolution_clock::now();
        // Function C
        for (int i = 1; i <= n; ++i) {
            isPrimeC(i);
        }
        end_time = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end_time - start_time);
        cout << "Function C: " << n << " Time: " << duration.count() << " ms\n";

        start_time = high_resolution_clock::now();
        // Function D (Sieve of Eratosthenes)
        sieveOfEratosthenes(n);
        end_time = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end_time - start_time);
        cout << "Sieve of Eratosthenes: " << n << " Time: " << duration.count() << " ms\n";

        cout << "-----------------------\n";
    }

    return 0;
}
