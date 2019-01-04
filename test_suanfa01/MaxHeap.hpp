//
//  MaxHeap.hpp
//  test_suanfa01
//
//  Created by 井利华 on 2018/12/28.
//  Copyright © 2018年 纠结伦. All rights reserved.
// 堆

/*
 堆化：从堆中最后一个非叶子节点开始往前遍历（从1开始存放是 n/2，从0开始是（n-1)/2），进行shiftDown操作即可
 索引堆：新增一个索引数组
 应用：
 1. 优先队列
 2. 在10000000个元素中选出前100名，最小堆，容量为100，依次往里添加元素，维持堆的性质
 3. 多路归并排序：将数据分成n组，每次从每个组中取出一个元素，组成一个最小堆，取出堆顶元素放入排序数据，再往堆中添加新元素，维持堆的特性
 */

#ifndef MaxHeap_hpp
#define MaxHeap_hpp

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
using namespace std;

template <typename Item>
class MaxHeap {
private:
    Item *data;
    int count; // 堆中元素个数
    int capacity; // 数组容量
    
    void _shiftUp(int i) {
        while (i>1 && data[i] > data[i/2]) {
            swap(data[i], data[i/2]);
            i = i/2;
        }
    }
    
    void _shiftDown(int i) {
        while (2*i <= count) {
            // 找到子节点中较大的
            int j = 2*i;
            if (2*i+1 <= count && data[j] < data[j+1]) {
                j = j+1;
            }
            
            // 找到了目标位置，直接break
            if (data[i] >= data[j]) {
                break;
            }
            
            // 交换
            swap(data[i], data[j]);
            i = j;
        }
    }
    
public:
    MaxHeap(int capacity) {
        data = new Item[capacity];
        this->capacity = capacity;
    }
    
    ~MaxHeap() {
        delete [] data;
    }
    
    int size() {
        return count;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    void insert(Item item) {
        assert(count + 1 < capacity);
        data[++count] = item;
        _shiftUp(count);
    }
    
    Item extractMax() {
        assert(count > 0);
        Item max = data[1];
        swap(data[1], data[count]);
        count--;
        _shiftDown(1);
        return max;
    }
    

private:
    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){
        
        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }
    
    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){
        
        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );
        
        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
    
public:
    
    // 以树状打印整个堆结构
    void testPrint(){
        
        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( size() >= 100 ){
            cout<<"This print function can only work for less than 100 int";
            return;
        }
        
        // 我们的testPrint只能处理整数信息
        if( typeid(Item) != typeid(int) ){
            cout <<"This print function can only work for int item";
            return;
        }
        
        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 1 ; i <= size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert( data[i] >= 0 && data[i] < 100 );
            cout<<data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;
        
        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }
        
        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');
            
            int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;
            
            if( level == max_level - 1 )
                break;
            
            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;
            
            cur_tree_max_level_number /= 2;
        }
    }

};

#endif /* MaxHeap_hpp */
