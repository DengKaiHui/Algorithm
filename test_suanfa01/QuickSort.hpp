//
//  QuickSort.hpp
//  test_suanfa01
//
//  Created by jameskhdeng(邓凯辉) on 2019/3/9.
//  Copyright © 2019 纠结伦. All rights reserved.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>

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


//3路快排，针对数组中重复元素较多的情况，导致左右不平衡，计算过程中生成的树也不平衡，是算法退化
- (void)__quickSort3(int arr[], int l, int r) {
    if(l >= r) return;
    
    // pation
    // 使得arr[l+1...lt]<v, arr[gt...r]>v, arr[lt+1, i) == v
    swap(arr[l], rand()%(r-l+1)+l);
    int v = arr[l];
    int lt = l, gt = r+1, i = l+1;
    while(i<gt) {
        if(arr[i] < v) {
            swap(arr[i], arr[++lt]);
            i++;
        } else if(arr[i] > v) {
            swap(arr[i], arr[--gt]);
        } else {
            i++;
        }
    }
    swap(arr[l], arr[lt]);
    
    __quickSort3(arr, l, lt-1);
    __quickSort3(arr, gt, r);
    
}


- (void)quickSort3(int arr[], int n) {
    __quickSort3(arr, 0, n-1);
}

#endif /* QuickSort_hpp */
