/*
 * Aiden McCormack
 * CS 124 Section A
 */
#include <iostream>
#include "QuickSort.h"
#include "bookData.h"
#include <vector>
#include <chrono> // Used for timer
using namespace std;
int main() {
    // Create a bookData vector and load books info
    vector<bookData> bookDataVec;
    loadFromFile("../books.csv", bookDataVec);

    bookDataVec.resize(15);
    // Start timer to record how long it takes to sort.
    auto BubbleSortTimeBegin = chrono::high_resolution_clock::now();
    // Put vector of bookData into bubble sort.
    bubbleSort(bookDataVec);
    // Stop timer and calculate total time.
    auto BubbleSortTimeEnd = chrono::high_resolution_clock::now();
    auto BubbleSortDuration = BubbleSortTimeEnd - BubbleSortTimeBegin;

    auto SelectionSortTimeBegin = chrono::high_resolution_clock::now();
    // Put vector of bookData into bubble sort.
    selectionSort(bookDataVec);
    auto SelectionSortTimeEnd = chrono::high_resolution_clock::now();
    auto SelectionSortDuration = SelectionSortTimeEnd - SelectionSortTimeBegin;

    auto QuickSortTimeBegin = chrono::high_resolution_clock::now();
    // Put vector of bookData into unstable quick sort.
    quickSortUnstable(bookDataVec);
    auto QuickSortTimeEnd = chrono::high_resolution_clock::now();
    auto QuickSortDuration = QuickSortTimeEnd - QuickSortTimeBegin;

    auto HeapSortTimeBegin = chrono::high_resolution_clock::now();
    // Put vector of bookData into heap sort.
    heapSort(bookDataVec);
    auto HeapSortTimeEnd = chrono::high_resolution_clock::now();
    auto HeapSortDuration = HeapSortTimeEnd - HeapSortTimeBegin;

    // TODO: Sort on a different field (bookTitle) using a stable selection sort algorithm.
        // TODO: Make a copy of the selection sort function and take out the template part
        // TODO: Create a getter for bookTitle to compare and return the comparable.



    // Print the time it took to sort each algorithm.
    // Bubble Sort time.
    auto i_millis = chrono::duration_cast<chrono::milliseconds>(BubbleSortDuration);
    auto f_secs = chrono::duration_cast<chrono::duration<float>>(BubbleSortDuration);
    cout << "Bubble Sort time elapsed: ", i_millis.count() << '/n';
    cout << f_secs.count() << endl;
    // Insertion Sort time.
    auto i_millis1 = chrono::duration_cast<chrono::milliseconds>(SelectionSortDuration);
    auto f_secs1 = chrono::duration_cast<chrono::duration<float>>(SelectionSortDuration);
    cout << "Selection Sort time elapsed: ", i_millis1.count() << '/n';
    cout << f_secs1.count() << endl;
    // Quick Sort time.
    auto i_millis2 = chrono::duration_cast<chrono::milliseconds>(QuickSortDuration);
    auto f_secs2 = chrono::duration_cast<chrono::duration<float>>(QuickSortDuration);
    cout << "Unstable Quick Sort time elapsed: ", i_millis2.count() << '/n';
    cout << f_secs2.count() << endl;
    // Heap Sort time.
    auto i_millis3 = chrono::duration_cast<chrono::milliseconds>(HeapSortDuration);
    auto f_secs3 = chrono::duration_cast<chrono::duration<float>>(HeapSortDuration);
    cout << "Heap Sort time elapsed: ", i_millis3.count() << '/n';
    cout << f_secs3.count() << endl;

    return 0;
}