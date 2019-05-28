#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int partition(int a[], int from, int to)
{
    int pivot = a[from];
    int i = from - 1;    int j = to + 1;
    while (i < j)
    {
        i++; while (a[i] < pivot) { i++; }
        j--; while (a[j] > pivot) { j--; }
        if (i < j) { std::swap(a[i], a[j]); }
    }
    return j;
}


void quicksort(int a[], int from, int to)
{
    if (from >= to) { return; }
    int p = partition(a, from, to);
    quicksort(a, from, p);
    quicksort(a, p + 1, to);
}
