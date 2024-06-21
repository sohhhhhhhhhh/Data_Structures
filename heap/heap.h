#pragma once

#include <vector>

class Heap_max {
private:
    std::vector<long long int> heap;

    void shift_up(long long int index);
    void shift_down(long long int index);
    long long max_in(long long arr[], int n);

public:
    Heap_max();
    Heap_max(long long int arg);
    Heap_max(const std::vector<long long int>& args);

    void push(long long int el);
    long long get();
    long long del();
    long long len();
    void print_heap();
};
