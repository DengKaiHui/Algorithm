//
//  MaxHeap.hpp
//  test_suanfa01
//
//  Created by jameskhdeng(邓凯辉) on 2018/12/30.
//  Copyright © 2018 纠结伦. All rights reserved.
//

#ifndef MaxHeap_hpp
#define MaxHeap_hpp

#include <stdio.h>

template <typename Item>
class MaxHeap {
private:
    Item *datas;
    int count;
    int capacity;
    
    void _shiftUp(int i) {
        while (i>1 && datas[i] > datas[i/2]) {
            swap(datas[i], datas[i/2]);
            i = i/2;
        }
    }
    
    void _shiftDown(int i) {
        while (2*i <= count) {
            // 找到子节点中较大的
            int j = 2*i;
            if (2*i+1 <= count && datas[j] < datas[j+1]) {
                j = j+1;
            }
            
            // 找到了目标位置，直接break
            if (datas[i] >= datas[j]) {
                break;
            }
            
            // 交换
            swap(datas[i], datas[j]);
            i = j;
        }
    }
    
public:
    MaxHeap(int capacity) {
        datas = new Item[capacity];
        this->capacity = capacity;
    }

    ~MaxHeap() {
        delete [] datas;
    }
    
    int size() {
        return count;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    void insert(Item item) {
        assert(count + 1 < capacity);
        datas[++count] = item;
        _shiftUp(count);
    }
    
    Item extractMax() {
        assert(count > 0);
        Item max = datas[1];
        swap(datas[1], datas[count]);
        count--;
        _shiftDown(1);
        return max;
    }
    
};

#endif /* MaxHeap_hpp */
