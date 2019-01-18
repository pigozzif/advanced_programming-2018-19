#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <chrono>


//Exercise one

template <typename T, size_t N>
std::array<T, N> get_transpose(const std::array<T, N> &matrix, const size_t dim1, const size_t dim2) {
    std::array<T, N> transpose;
    for (auto i=0; i < dim1; ++i) {
        for (auto j=0; j < dim2; ++j) {
            transpose[j*dim1 + i] = matrix[i*dim2 + j];
        }
    }
    return transpose;
}


//Exercise two

void mean_and_median(const std::string path) {
    std::ifstream inFile{path};
    double line;
    std::vector<double> container;
    while (inFile >> line) {
        container.push_back(line);
    }
    double sum{0};
    auto size = container.size();
    for (auto j=0u; j < size; ++j) {
        sum += container[j];
    }
    std::cout << "The mean is: " << sum / size;
    std::sort(container.begin(), container.end());
    if (size % 2 == 0) {
        std::cout << "The median is: " << container[size / 2];
    }
    else {
        std::cout << "The median is: " << container[size / 2 - 1];
    }
}


//Exercise three

void avoid_repeated_words() {
    std::vector<std::string> container;
    for (std::string line; std::getline(std::cin, line);) {
        if (line.compare("q") == 0) {
            break;
        }
        else  {
            container.push_back(line);
        }
    }
    if (container.size() == 0) return;
    std::sort(container.begin(), container.end());
    std::string old_line = container[0];
    int count{0};
    for (auto j=0u; j < container.size(); ++j) {
        std::string line = container[j];
        if (old_line.compare(line) != 0) {
            std::cout << count << " " << old_line << "\n";
            count = 1;
            old_line = line;
        }
        else ++count;
    }
    std::cout << count << " " << old_line << "\n";
}


//Exercise four

void repeated_words_with_vectors(const std::string path) {
    std::ifstream inFile{path};
    std::string line;
    std::vector<std::string> container;
    while (inFile >> line) {
        container.push_back(line);
    }
    std::sort(container.begin(), container.end());
    std::string old_line = container[0];
    int count{0};
    for (auto j=0u; j < container.size(); j++) {
        std::string line = container[j];
        if (old_line.compare(line) != 0) {
            std::cout << count << " " << old_line << "\n";
            count = 1;
            old_line = line;
        }
        else ++count;
    }
    std::cout << count << " " << old_line << "\n";
}


void repeated_words_with_maps(const std::string path) {
    std::ifstream inFile{path};
    std::string line;
    std::map<std::string, int> container;
    while (inFile >> line) {
        if (container.count(line) == 0) {
            container[line] = 1;
        }
        else {
            ++container[line];
        }
    }
    for (auto couple=container.begin(); couple!=container.end(); ++couple) {
        std::cout << couple->first << " " << couple->second << "\n";
    }
}


void repeated_words_with_unordered_maps(const std::string path) {
    std::ifstream inFile{path};
    std::string line;
    std::unordered_map<std::string, int> container;
    while (inFile >> line) {
        if (container.count(line) == 0) {
            container[line] = 1;
        }
        else {
           ++ container[line];
        }
    }
    for (auto couple=container.begin(); couple!=container.end(); ++couple) {
        std::cout << couple->first << " " << couple->second << "\n";
    }
}


void exercise_four(const std::string path) {
    srand(11);
    auto t0 = std::chrono::high_resolution_clock::now();
    repeated_words_with_vectors(path);
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Counting with std::vector took " << std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() << " microseconds\n";
    t0 = std::chrono::high_resolution_clock::now();
    repeated_words_with_maps(path);
    t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Counting with std::map took " << std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() << " microseconds\n";
    t0 = std::chrono::high_resolution_clock::now();
    repeated_words_with_unordered_maps(path);
    t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Counting with std::unordered_map took " << std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() << " microseconds\n";
}


//Main function

int main() {
    return 0;
}
