//Naive approach
#include <iostream>

class Solution {
public:
    bool isPrime(int n){
        for(int i = 2; i < n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        int numprimes = 0;
        for(int i = 2; i < n; i++){
            if(isPrime(i)){
                numprimes += 1; 
            }
        }
        return numprimes;
    }
};

int main() {
    Solution sol;
    int n = 20;  // Example: count prime numbers less than 20
    int result = sol.countPrimes(n);
    std::cout << "Number of prime numbers less than " << n << " is: " << result << std::endl;
    return 0;
}