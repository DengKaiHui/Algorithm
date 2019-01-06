//
//  UnionFind.hpp
//  test_suanfa01
//
//  Created by jameskhdeng(邓凯辉) on 2019/1/6.
//  Copyright © 2019 纠结伦. All rights reserved.
//  并查集

#ifndef UnionFind_hpp
#define UnionFind_hpp

#include <stdio.h>
#include <iostream>
#include <cassert>

class UnionFind {
private:
    int *parent;
    int *rank; //rank[i] 表示以i为根的集合所表示的树的层数
    int count;
    
public:
    UnionFind(int count) {
        assert(count>0);
        parent = new int[count];
        rank = new int[count];
        for (int i = 0; i < count; i++) {
            // 初始化状态，每个节点的都指向自己，所以层数为1
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~UnionFind() {
        delete [] parent;
        delete [] rank;
    }
    
    int find(int p) { 
        assert(p >=0 && p<count);
        
//        // 路径压缩1
//        while (parent[p] != p) {
//            parent[p] = parent[parent[p]];
//            p = parent[p];
//        }
//        return p;
        // 路径压缩2
        if (p != parent[p]) {
            parent[p] = find(parent[p]);
        }
        return parent[p];
    }
    
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
    
    void unionElements(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootQ == rootP) {
            return;
        }
        
        if (rank[rootP] < rank[rootQ]) {
            parent[rootP] = rootQ;
        } else if (rank[rootP] > rank[rootQ]) {
            parent[rootQ] = rootP;
        } else { // rank[rootP] == rank[rootQ]，层数相等时
            parent[rootP] = rootQ;
            rank[rootP]++;
        }
    }
};

#endif /* UnionFind_hpp */
