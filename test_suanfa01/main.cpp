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


int main(int argc, const char * argv[]) {
    
    int n = 50000;
//    int *arr = gennearlyOrderdArray(n, 10);
    int *arr = genRandomArray(n, 0, n);
    int *arr2 = copyIntArray(arr, n);
    int *arr3 = copyIntArray(arr, n);
//    printArray(arr, n);
    testSort("Merge Sort", mergeSort, arr, n);
    testSort("Merge Sort BU", mergeSortBU, arr3, n);
    testSort("Insert Sort", insertSort, arr2, n);
    
    delete [] arr;
    delete [] arr2;
    
    return 0;
}
