#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve_of_atkin(int limit) {
    vector<bool> primes(limit + 1, false);
 
    if (limit > 2)
        primes[2] = true;
    if (limit > 3)
        primes[3] = true;
 
    for (int x = 1; x * x < limit; x++) {
        for (int y = 1; y * y < limit; y++) {
            int n = 4 * x * x + y * y;
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                primes[n] = !primes[n];
 
            n = 3 * x * x + y * y;
            if (n <= limit && n % 12 == 7)
                primes[n] = !primes[n];
 
            if (x > y) {
                n = 3 * x * x - y * y;
                if (n <= limit && n % 12 == 11)
                    primes[n] = !primes[n];
            }
        }
    }
 
    for (int r = 5; r * r < limit; r++) {
        if (primes[r]) {
            for (int i = r * r; i < limit; i += r * r)
                primes[i] = false;
        }
    }
 
    vector<int> primeNumbers;
    for (int a = 2; a <= limit; a++) {
        if (primes[a])
            primeNumbers.push_back(a);
    }
 
    return primeNumbers;
}
 
int main() {
    int limit = 20;
    vector<int> primeNumbers = sieve_of_atkin(limit);
 
    for (int prime : primeNumbers)
        cout << prime << " ";
 
    return 0;
}