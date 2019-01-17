#include <iostream>
#include <vector>
#include <cmath>


// Exercise one

template <typename T>
T* init(const std::size_t length) {
    T* array{new T[length]{}};
    for (auto i=0u; i < length; ++i) {
         T input;
         std::cin >> input;
         array[i] = input;
    }
    return array;
}

template <typename  T>
void reverse_order(const T* array, const std::size_t length) {
    const T* const start{array};
    array += length - 1;
    for (; array != start; --array) {
        std::cout << *array << " ";
    }
    std::cout << *start;
    delete[] array;
}

void exercise_one() {
    std::size_t length;
    std::cin >> length;
    int* array = init<int>(length);
    reverse_order(array, length);
}


// Exercise two

void rough_prime_numbers() {
    int primes[100] = {2};
    int index{1};
    bool is_prime{true};
    for (unsigned int num=3; num <= 100; ++num) {
        is_prime = true;
        for (unsigned int i=2; i < num; ++i) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes[index] = num;
            ++index;
        }
    }
    for (unsigned int j=0; j < index; ++j) {
        std::cout << primes[j] << " ";
    }
}


// Exercise three

void sieve_of_eratosthenes() {
    unsigned int num;
    std::cout << "insert number:";
    std::cin >> num;
    bool numbers[num + 1];
    for (int j=0; j <= num; j++) {
        numbers[j] = true;
    }
    for (unsigned int i=2; i <= std::sqrt(num); i++) {
        if (numbers[i]) for (unsigned int k=i*i; k <= num; k+=i) numbers[k] = false;
    }
    for (unsigned int pos=2; pos <= num; pos++) {
        if (numbers[pos]) std::cout << pos << " ";
    }
}


// Exercise four

void rough_prime_numbers_with_vectors() {
    std::vector<int> primes{2};
    unsigned int index{1};
    bool is_prime{true};
    for (unsigned int num=3; num <= 100; num++) {
        is_prime = true;
        for (unsigned int i=2; i < num; i++) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(num);
        }
    }
    for (unsigned int j=0; j < primes.size(); j++) {
        std::cout << primes[j] << " ";
    }
}


void sieve_of_eratosthenes_with_vectors() {
    unsigned int num;
    std::cout << "insert number:";
    std::cin >> num;
    std::vector<bool> numbers(3);
    numbers[0] = false;
    numbers[1] = false;
    numbers[2] = false;
    for (unsigned int i=2; i <= std::sqrt(num); i++) {
        if (!numbers[i]) for (int k=i*i; k <= num; k+=i) numbers[k] = true;
    }
    for (unsigned int pos=2; pos <= num; pos++) {
        if (!numbers[pos]) std::cout << pos << " ";
    }
}


// Main function

int main(int argc, char* argv[]) {
    return 0;
}



