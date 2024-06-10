#include<iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

class Heap_max {
private:
    vector<long long int> heap;

    void shift_up(long long int index) {
        if (index == 0) return;
        long long int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) return;
        swap(heap[parent], heap[index]);
        shift_up(parent);
    }

    void shift_down(long long int index) {
        if (index * 2 + 1 > heap.size() - 1) return;
        long long arr[3] = {index, index * 2 + 1, index * 2 + 2};
        int n;
        if (index * 2 + 2 > heap.size() - 1) n = 2;
        else n = 3;
        long long max_el = max_in(arr, n);
        if (index == max_el) return;
        swap(heap[index], heap[max_el]);
        shift_down(max_el);
        return;
    }

    long long max_in(long long arr[], int n) {
        long long int max_ind;
        max_ind = arr[0];
        for (int i = 1; i < n; i++)
            if (heap[arr[i]] > heap[max_ind]) max_ind = arr[i];
        return max_ind;
    };
public:
    Heap_max()
    {
    }
    Heap_max(long long int arg)
    {
        heap.push_back(arg);
    }
    Heap_max(vector<long long int> args)
    {
        for (long long int i=0; i < args.size(); i++)
        {
            push(args[i]);
        }
    }

    void push(long long int el)
    {
        heap.push_back(el);
        shift_up(heap.size() - 1);
    }

    long long get()
    {
        return heap[0];
    }

    long long del()
    {
        long long el = heap[0];
        swap(heap[0], heap.back());
        heap.pop_back();
        shift_down(0);
        return el;
    }

    long long len()
    {
        return heap.size();
    }
};
