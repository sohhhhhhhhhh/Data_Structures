#pragma once

#include <vector>

class Heap_max {
    std:: vector<long long int> heap;

    void shift_up(long long int index);

    void shift_down(long long int index);

public:
    Heap_max(std::vector<long long int> args);

    void push(long long int el);

    long long get();

    long long del();

    long long len();
};


