//
//  InsertSort.hpp
//  test_suanfa01
//
//  Created by jameskhdeng(邓凯辉) on 2018/12/2.
//  Copyright © 2018 纠结伦. All rights reserved.
//

#ifndef InsertSort_hpp
#define InsertSort_hpp

#include <stdio.h>

/*
 * 插入排序：把前面当做排序好的数组（开始只有第一个元素），每次遍历i，在排序好的数组中查找i合适的位置（在数据大致有序的数据中，效率很高，如果已经拍好序，那么插入排序的时间复杂度为O(n),一般为O(n2)）
 */
template <class T>
void insertSort(T *arr, int n) {
    for (int i=  1; i < n; i++) {
        // 选择元素arr[i]合适的插入位置
        
        //        for (int j = i; j >0; j--) {
        //            if (arr[j] < arr[j-1]) {
        //                swap(arr[j], arr[j-1]);
        //            } else {
        //                break;
        //            }
        //        }
        
        //        for (int j = i; j >0 && arr[j] < arr[j-1]; j--) {
        //            swap(arr[j], arr[j-1]);
        //        }
        
        // 优化：之前每次内层循环都会交换一次元素，现在把需要排序的当前元素记下，每次如果比较的元素比他大，就往后移，不交换
        T a = arr[i];
        for (int j = i; j >0; j--) {
            if (a < arr[j-1]) {
                arr[j] = arr[j-1];
            } else {
                arr[j] = a;
                break;
            }
        }
    }
}

// 插入排序2: 对arr数组中[l...r]的元素进行插入排序
template <class T>
void insertSort(T arr[], int l, int r) {
    for (int i = l+1; i <= r; i++) {
        T a = arr[i];
        for (int j = i; j > l; j--) {
            if (a < arr[j-1]) {
                arr[j] = arr[j-1];
            } else {
                arr[j] = a;
                break;
            }
        }
    }
}

#endif /* InsertSort_hpp */
