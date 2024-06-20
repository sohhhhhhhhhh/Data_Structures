#include "heap.h"
#include <iostream>

Heap_max::Heap_max() = default;

Heap_max::Heap_max(long long int arg) {
    heap.push_back(arg);
}

Heap_max::Heap_max(const std::vector<long long int>& args) {
    for (long long int i : args) {
        push(i);
    }
}

void Heap_max::push(long long int el) {
    heap.push_back(el);
    shift_up(heap.size() - 1);
}

long long Heap_max::get() {
    return heap[0];
}

long long Heap_max::del() {
    long long el = heap[0];
    std::swap(heap[0], heap.back());
    heap.pop_back();
    shift_down(0);
    return el;
}

long long Heap_max::len() {
    return heap.size();
}

void Heap_max::print_heap() {
    for (auto& el : heap) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

void Heap_max::shift_up(long long int index) {
    if (index == 0) return;
    long long int parent = (index - 1) / 2;
    if (heap[parent] >= heap[index]) return;
    std::swap(heap[parent], heap[index]);
    shift_up(parent);
}

void Heap_max:: shift_down(long long int index) {
    long long int l = 2 * index + 1;
    long long int r = 2 * index + 2;
    long long int largest = index;

    if (l < heap.size() && heap[l] > heap[largest]) {
        largest = l;
    }
    if (r < heap.size() && heap[r] > heap[largest]) {
        largest = r;
    }
    if (largest != index) {
        std::swap(heap[index], heap[largest]);
        shift_down(largest);
    }
}

