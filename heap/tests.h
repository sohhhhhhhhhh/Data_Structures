#pragma once
#include <random>
#include "heap.h"
#include <iostream>

void test_duplicate_elements() {
    Heap_max h;
    for (int i = 0; i < 100; ++i) {
        h.push(42);
    }
    while (h.len() > 0) {
        std::cout << h.del() << " ";
    }
    std::cout << std::endl;
}

void test_add_one_value_and_print() {
    Heap_max h;
    h.push(10);
    h.print_heap();
}

void test_descending_order_elements() {
    Heap_max h;
    for (int i = 100; i >= 0; --i) {
        h.push(i);
    }
    h.print_heap();
}

void test_push_pop_alternating() {
    Heap_max h;
    for (int i = 0; i < 50; ++i) {
        h.push(i);
        if (i % 2 == 0) {
            std::cout << h.del() << " ";
        }
    }
    int right_el = 49;

    std::cout << std::endl;
    h.print_heap();
    long long res = h.get();
    if(h.get() == right_el)
        std::cout << "you got it right" << std::endl;
    else std::cout << "error: expected " << right_el << " but got " << res << std::endl;
}


void test_large_random_numbers() {
    int size = 100;
    std::vector<long long> random_numbers;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long long> dis(-1000, 1000);

    for (int i = 0; i < size; ++i) {
        random_numbers.push_back(dis(gen));
    }

    Heap_max h(random_numbers);

    long long middle_element = random_numbers[size / 2];

    for (int i = 0; i < h.len(); ++i) {
        if (h.get() % 2 == 0) {
            h.del();
        }

    }
    if (h.get() == middle_element) {
        std::cout << "Middle element matches heap top: Good" << std::endl;
    } else {
        std::cout << "Middle element does not match heap top: Not Good" << std::endl;
    }
}
