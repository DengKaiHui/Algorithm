//
//  MergeSort_new.hpp
//  test_suanfa01
//
//  Created by jameskhdeng(邓凯辉) on 2019/3/9.
//  Copyright © 2019 纠结伦. All rights reserved.
//

#ifndef MergeSort_new_hpp
#define MergeSort_new_hpp

#include <stdio.h>

/*
 * 归并排序：将数组分成左右两部分，在将左右两部分各自分成两部分...直到最后每个部分只剩一个元素（就是有序的了），再将这些部分两两归并排序，总数为n的数组分到最后只剩一个元素的情况需要分logn次，所以总共需要归并logn次，每次归并采用o(n)的算法，所以算法负责度为o(nlogn)
 */

#pragma mark - 自顶向下的归并排序

void __merge(int arr[], int l, int mid, int r) {
    int tempArr[r-l+1];
    for (int i = l; i<=r; i++) {
        tempArr[i-l] = arr[i];
    }
    
    int i = l, j = mid+1;
    for (int k = l; k<=r; k++) {
        if (i > mid) {
            arr[k] = tempArr[j-l];
            j++;
        } else if(j > r) {
            arr[k] = tempArr[i-l];
            i++;
        } else if(tempArr[i-l] < tempArr[j-l]) {
            arr[k] = tempArr[i-l];
            i++
        } else {
            arr[k] = tempArr[j-l];
            j++;
        }
    }
}

void __mergeSort(int arr[], int l, int r) {
    // 递归结束条件
    if(l>=r) return;
    
    int mid = l + (r-l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    
    if(arr[mid] > arr[mid+1]) {    
        __merge(arr, l, mid, r);
    }
}

void mergeSrot(int arr[], int n) {
    if(n <= 0) return;
    __mergeSort(arr, 0, n-1);
}

#endif /* MergeSort_new_hpp */
