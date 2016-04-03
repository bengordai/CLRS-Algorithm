//
// Created by ben on 16-4-2.
//

#ifndef CLRS_UTILITY_H
#define CLRS_UTILITY_H
<typename T>
void QuickSort(T array[], int low, int high);
<typename T>
void MergeSort(T array[], int length);
<typename T>
void MaxifyHeap(T array[], int i, int length);
<typename T>
void HeapSort(T array[], int length);
<typename T>
void BubbleSort(T array[], int length);
<typename T>
void ShellSort(T array[], int length);
<typename T>
void InsertionSort(T array[], int length);
void RadixSort(int array[], int length);
void CountingSort(int *A, int length);
bool isPrime(int num);
#endif //CLRS_UTILITY_H
