//
//  MergeSort.hpp
//  test_suanfa01
//
//  Created by jameskhdeng(邓凯辉) on 2018/12/2.
//  Copyright © 2018 纠结伦. All rights reserved.
//  归并排序-O(nlogn)

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>

/*
 * 归并排序：将数组分成左右两部分，在将左右两部分各自分成两部分...直到最后每个部分只剩一个元素（就是有序的了），再将这些部分两两归并排序，总数为n的数组分到最后只剩一个元素的情况需要分logn次，所以总共需要归并logn次，每次归并采用o(n)的算法，所以算法负责度为o(nlogn)
 */

#pragma mark - 自顶向下的归并排序
// 归并函数，将arr[l...mid]和arr[mid+1...r]两部分进行归并
template <class T>
void __merge(T arr[], int l, int mid, int r) {
    T tempArr[r-l+1];
    // 先把arr中的元素都拷贝到tempArr中
    for (int i = l; i <= r; i++) {
        tempArr[i-l] = arr[i];
    }
    
    // 归并
    int i = l, j = mid+1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = tempArr[j-l];
            j++;
        } else if (j > r) {
            arr[k] = tempArr[i-l];
            i++;
        } else if (tempArr[i-l] <= tempArr[j-l]) {
            arr[k] = tempArr[i-l];
            i++;
        } else {
            arr[k] = tempArr[j-l];
            j++;
        }
    }
    
    
    
}

// 递归调用，对arr[l...r](前闭后闭，注意边界值是否包含)的范围进行排序
template <class T>
void __mergeSort(T arr[], int l, int r) {
    // 递归方法，先考虑出口条件
        if (l >= r) {
            return;
        }
    
    // 【优化】当元素个数较少时，使用插入排序排序后直接返回
//    if (r-l <= 15) {
//        insertSort(arr, l, r);
//        return;
//    }
    
    // 计算中点
    int mid = (l + r)/2;
    __mergeSort(arr, l, mid);      // 递归左边
    __mergeSort(arr, mid+1, r);    // 递归右边
    if (arr[mid] > arr[mid+1]) {            // 【优化】左边最大元素小于等于右边最小元素的时候不用归并
        __merge(arr, l, mid, r);       // 归并
    }
    
}

// 归并排序函数
template <class T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n-1);
}


#pragma mark - 自底向上的归并排序
template <class T>
void mergeSortBU(T arr[], int n) {
    for (int sz = 1; sz < n; sz = sz*2) {
        // 对arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
        for (int i = 0; i+sz <n ; i += 2*sz) {
            if (arr[i+sz-1] > arr[i+sz]) {
                __merge(arr, i, i+sz-1, min(i+2*sz-1, n-1));
            }
        }
    }
}

#endif /* MergeSort_hpp */
