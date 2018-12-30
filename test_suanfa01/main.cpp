//
//  main.cpp
//  test_suanfa01
//
//  Created by 邓凯辉 on 2018/11/21.
//  Copyright © 2018年 纠结伦. All rights reserved.
//

#include <iostream>
#include "SortTestHelper.hpp"
#include "InsertSort.hpp"
#include "MergeSort.hpp"
#include "MaxHeap.hpp"
using namespace std;
using namespace SortTestHelper;

#pragma mark - O(n2)

/*
 * 选择排序：每次从剩下的数据中找出最小（大）的和当前的minIndex交换I
 */
template<class T>
void selectionSort(T *arr, int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
//        temp = arr[i];
//        arr[i] = arr[minIndex];
//        arr[minIndex] = temp;
    }
}
/*
 * 快速排序：选定元素v，让其找到合适的位置，使得arr[l...j-1] < v , arr[j+1...r] > v
 */

// 对arr[l...r]部分进行partition操作
// 返回j, 使得arr[l...j-1] < arr[j] , arr[j+1...r] > arr[j]
template <class T>
int __partition(T arr[], int l, int r) {
    int v = arr[l];
    
    // arr [l+1...j] < v, arr[j+1...i) > v （包括初始情况）
    int j = l;
    for (int i = l+1; i<=r; i++) {
        if (arr[i] < v) {
            swap(arr[i], arr[j+1]);
            j++;
        }
    }
    swap(arr[j], arr[l]);
    return j;
}

// 对arr[l...r]部分进行快速排序
template <class T>
void __quickSort(T arr[], int l, int r) {
    if (l>=r) {
        return;
    }
    
    int v = __partition(arr, l, r);
    __quickSort(arr, l, v-1);
    __quickSort(arr, v+1, r);
}

template <class T>
void quickSort(T arr[], int n) {
    __quickSort(arr, 0, n-1);
}

int main(int argc, const char * argv[]) {
    
    int n = 50000;
//    int *arr = gennearlyOrderdArray(n, 10);
    int *arr = genRandomArray(n, 0, n);
    int *arr2 = copyIntArray(arr, n);
    int *arr3 = copyIntArray(arr, n);
//    printArray(arr, n);
    testSort("Merge Sort", mergeSort, arr, n);
    testSort("Quick Sort", quickSort, arr2, n);
//    testSort("Merge Sort BU", mergeSortBU, arr3, n);
//    testSort("Insert Sort", insertSort, arr2, n);
    
    delete [] arr;
    delete [] arr2;
    
    return 0;
}
