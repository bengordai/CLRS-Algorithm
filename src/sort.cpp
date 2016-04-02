//快排

<typename T>
int QPartition(T array[], int low, int high) {
    T pivot = array[high], temp;
    int i, j;
    for (i = low - 1, j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}


<typename T>
void QuickSort(T array[], int low, int high) {
    int pivot;
    if (low < high) {
        pivot = Qpartition<T>(array, low, high);
        Quicksort<T>(array, low, high);
        Quicksort < T > 3(array, pivot + 1, high);
    }
}


//归并排序

//array[0,...,length_a-1,...,length_a+length+b-1]
//array_a=array[0,...,length_a-1]
//array_b=array[length_a,...,length_a+length_b-1]
<typename T>
void Merge(T array[], int length_a, int length_b) {
    T *array_a = array;
    T *array_b = array + length_a;
    int i, j, k;
    T *array_sorted = new T[length_a + length_b];
    for (i = j = k = 0; i < length_a && j < length_b; k++) {
        if (array_a[i] < array_b[j]) {
            array_sorted[k] = array_a[i];
            i++;
        } else {
            array_sorted[k] = array_b[j];
            j++;
        }
    }
    if (i == length_a) {
        for (; j < length_b; j++, k++)
            array_sorted[k] = array_b[j];
    } else {
        for (; i < length_a; i++, k++)
            array_sorted[k] = array_a[i];
    }
    for (i = 0; i < length_a + length_b; i++)
        array[i] = array_sorted[i];
    delete[] array_sorted;
}

<typename T>
void MergeSort(T array[], int length) {
    if (length <= 1) {
        return;
    } else if (length == 2) {
        if (array[0] > array[1]) {
            T temp = array[0];
            array[0] = array[1];
            array[1] = temp;
        }
    } else if (length % 2 == 0) {
        Mergesort<T>(array, length / 2);
        Mergesort<T>(&(array[length / 2]), length / 2);
        Merge < T > (array, length / 2, length / 2);
    } else {
        Mergesort<T>(array, length / 2);
        Mergesort<T>(&(array[length / 2 + 1]), length / 2 + 1);
        Merge < T > (array, &(A[length / 2 + 1]), length / 2, length / 2 + 1);
    }
}

//堆排序
<typename T>
void MaxifyHeap(T array[], int i, int length) {
    int left, right, largest;
    while (true) {
        left = 2 * i + 1;
        right = left + 1;
        if (left >= length || right >= length) {
            break;
        } else if (array[left] > array[i]) {
            largest = left;
        } else {
            largest = i;
        }
        if (array[right] > array[largest]) {
            largest = right;
        }
        if (largest != i) {
            T temp = array[i];
            array[i] = array[largest];
            array[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
}

<typename T>
void HeapSort(T array[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        MaxifyHeap < T > (array, i, length);
    }
    for (int i = length - 1; i >= 1; i--) {
        T temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        length--;
        MaxifyHeap < T > (array, 0, length);
    }
}

//冒泡排序
<typename T>
void BubbleSort(T array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }//j-for
    }//i-for
}

//希尔排序
<typename T>
void ShellSort(T array[], int length) {
    int increments[] = {19, 13, 7, 3, 1};
    for (int i = 0; i < 5; i++) {
        int increment = increments[i];
        for (int j = 0; j < length - increment; j++) {
            int k = j + increment;
            if (array[j] > array[k]) {
                T temp = array[k];
                A[k] = array[j];
                for (int l = k - increment; l >= 0 && array[l] > temp; l = l - increment) {
                    array[l + increment] = A[l];
                }
                array[l + increment] = temp;
            }
        }//j-for
    }//i-for
}

//插入排序
<typename T>
void InsertionSort(T array[], int length) {
    for (int i = 1; i < length; i++) {
        if (array[i] < array[i - 1]) {
            T temp = array[i];
            array[i] = array[i - 1];
            for (int j = i - 2; j >= 0 && array[j] > temp; j--) {
                array[j + 1] = array[j];
            }
            array[j + 1] = temp;
        }
    }//i-for
}

//基数排序
void RadixSort(int array[], int length) {//采用了counting sort的方式来对每一位的不同可能进行装载
    int i, j;
    int assist[6] = {1, 8, 64, 512, 4096, 32768};
    int count[8];
    int *digit = new int[length];
    int *bucket = new int[length];
    for (i = 0; i < 6; i++) {//65536一共6个八进制位，i为第i位
        for (j = 0; j < 8; j++) {//count用来记录这个位的数有几位
            count[j] = 0;
        }
        for (j = 0; j < length; j++) {//digit用来记录第j个数的第i位
            digit[j] = array[j] / assist[i] % 8;
            count[digit[j]]++;
        }
        for (j = 1; j < 8; j++) {//count[j]表示第j个桶的右边界
            count[j] = count[j] + count[j - 1];
        }
        for (j = length - 1; j >= 0; j--) {//倒着装桶，倒着放
            bucket[count[digit[j]] - 1] = A[j];
            count[digit[j]]--;
        }
        for (j = 0; j < length; j++) {//从桶里取出
            array[j] = bucket[j];
        }
    }
    delete[]digit;
    delete[]bucket;
}

//计数排序

void CountingSort(int *A, int length) {
    int *B = new int[length];
    int C[65536], i;
    for (i = 0; i < 65536; i++)C[i] = 0;
    for (i = 0; i < length; i++) {
        C[A[i]]++;
    }
    for (i = 1; i < 65536; i++) {
        C[i] = C[i] + C[i - 1];
    }
    for (i = length - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    for (i = 0; i < length; i++) {
        A[i] = B[i];
    }
    delete[] B;
}