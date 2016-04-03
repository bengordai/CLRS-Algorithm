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
bool isPrime_determined(int num);//朴素的检查素数算法
bool isPrime_MillerRabin(int num);//MillerRabin算法，并且在64bit情况下保证正确

#endif //CLRS_UTILITY_H
