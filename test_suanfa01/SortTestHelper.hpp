//
//  SortTestHelper.hpp
//  test_suanfa01
//
//  Created by 邓凯辉 on 2018/11/21.
//  Copyright © 2018年 纠结伦. All rights reserved.
//

#ifndef SortTestHelper_hpp
#define SortTestHelper_hpp
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;


namespace SortTestHelper {
    // 生成有n个元素的随机数组，每个元素的取值范围为[rangeL, rangeR]
    int * genRandomArray(int n, int rangeL, int rangeR) {
        
        assert(rangeL < rangeR);
        
        int *arr = new int[n];
        
        srand(time(NULL));
        
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        
        return arr;
        
    }
    
    int *gennearlyOrderdArray(int n, int swapTimes) {
        int * arr = new int[n];
        for (int i = 0; i<n; i++) {
            arr[i] = i;
        }
        
        srand(time(NULL));
        for (int i = 0; i<swapTimes; i++) {
            int index1 = rand()%n;
            int index2 = rand()%n;
            swap(arr[index1], arr[index2]);
        }
        return  arr;
    }
    
    
    template<class T>
    void printArray(T arr[], int n) {
        for (int i = 0; i< n ; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    template<class T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n-1; i++) {
            if (arr[i] > arr[i+1]) {
                return false;
            }
        }
        return true;
    }
    
    template<class T>
    void testSort(string  sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << ": " << (double)(endTime - startTime)/CLOCKS_PER_SEC << " s" << endl;
    }
    
    int * copyIntArray(int a[], int n) {
        int *arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }

}
#endif /* SortTestHelper_hpp */
