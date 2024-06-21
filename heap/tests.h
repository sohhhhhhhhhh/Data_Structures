#pragma once
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

}
