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
#include "BST.hpp"
#include "UnionFind.hpp"
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

// 求数组的逆序对：归并排序，算法基本一样，归并操作的时候增加计数逻辑，后半部分数组中元素如果比前半部分中元素小（那么就是比它后面的数都小），那么就存在（前半部分数组结尾索引-前半部分比较元素索引）个逆序对

// 求数组中的第K大元素：快速排序，从大到小排序，标定点元素为v，如果v下标<k，就在前半部分继续查找，如果>k, 就在后半部分继续查找,(特殊情况:如果后半部分的第一个元素下标为k, 那么v就是第K大元素)

/**
 优先队列：队列的一种，出队的顺序不是FIFO，而是按队列中元素的优先级顺序（例子：CPU 处理任务，web server, 游戏中电脑从周围敌人中选择攻击对象）
 最大堆（heap）:1. 堆中某个节点的值总是不大于其父节点的值（只能说明堆顶元素为最大值）；2. 是一颗完全二叉树
 完全二叉树：除了最后一层，其他所有层的节点个数都必须为最大值，且最后一层如果只有一个子节点，则该子节点位于左边（利于用数组存储）
 */

// 二分查找
template <typename T>
int binarySort(int arr[], int n, T target) {
    int l = 0;
    int r = n-1;
    // 在arr[l...r]之中找target
    while (l<=r) {
//        T mid = (l+r)/2; l+r可能移除
        T mid = l + (r-l)/2;
        if (target == mid) {
            return mid;
        }
        
        if (target < mid) {
            r =  mid-1;
        } else {
            l = mid +1;
        }
        
    }
    return  -1;
}

// 二分搜索树
/*
 1. 对于树种每一个节点，大于其左孩子节点，小于其右孩子节点
 2. 不需要是完全二叉树
 */

int main(int argc, const char * argv[]) {
    
    
    /*二次搜索树*/
    
    
    
    // ** 堆
    MaxHeap<int> heap = MaxHeap<int>(100);
    cout << heap.size() <<endl;
    
    srand(time(NULL));
    for (int i = 0; i< 15; i++) {
        heap.insert(rand()%100);
    }
    heap.testPrint();
    
    return 0;
    
    // ** 排序
    
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
