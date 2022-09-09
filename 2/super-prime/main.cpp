#include <array>
#include <iostream>
#include <vector>

const uint64_t MAX_PRIME = 100'000;

std::array<bool, MAX_PRIME + 1> findPrimes() {
    std::array<bool, MAX_PRIME + 1> isPrime;
    isPrime.fill(true);
    if (isPrime.size() > 0) {
        isPrime[0] = false;
    }
    if (isPrime.size() > 1) {
        isPrime[1] = false;
    }
    for (size_t number = 2; number < isPrime.size(); ++number) {
        if (isPrime[number]) {
            for (size_t notPrimeIdx = number * 2; notPrimeIdx <= MAX_PRIME; notPrimeIdx += number) {
                isPrime[notPrimeIdx] = false;
            }
        }
    }
    return isPrime;
}

std::vector<uint64_t> filterPrimes(const std::array<bool, MAX_PRIME + 1>& isPrime) {
    std::vector<uint64_t> primes;
    for (size_t number = 2; number < isPrime.size(); ++number) {
        if (isPrime[number]) {
            primes.push_back(number);
        }
    }
    return primes;
}

size_t findPrimeIdx(const std::vector<uint64_t>& primes, uint64_t prime) {
    size_t left = 0, right = primes.size();
    while (left + 1 < right) {
        size_t middle = (left + right) / 2;
        if (primes[middle] <= prime) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return left;
}

int main()
{
    using namespace std;

    const auto isPrime = findPrimes();
    const auto primes = filterPrimes(isPrime);
    cout << "Number to check = ";
    uint64_t number;
    cin >> number;
    size_t idx = findPrimeIdx(primes, number);
    if (primes[idx] == number && isPrime[idx + 1]) {
        cout << "Super prime!!!\n";
    } else {
        cout << "Not super prime.\n";
    }

    return 0;
}