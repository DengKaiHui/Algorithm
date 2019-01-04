//
//  BST.hpp
//  test_suanfa01
//
//  Created by 井利华 on 2019/1/4.
//  Copyright © 2019年 纠结伦. All rights reserved.
//  二分搜索树

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include <iostream>


template <typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;
        
        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };
    
    Node *root;
    int count;
    
    // 向以node为根的二叉搜索树中，插入节点（key, value）
    // 返回插入新节点后的二叉搜索树的根
    Node * __insert(Node *node ,Key k, Value v) {
        
        if (node == NULL) {
            count ++;
            return new Node(k, v);
        }
        
        if (node->key == k) {
            node->value = v;
            return;
        }
        
        if (node->key > k) {
            node->left = __insert(node->left, k, v);
        } else {
            node->rigt = __insert(node->right, k, v);
        }
        
        return node;
    }
    
public:
    BST() {
        root = NULL;
        count = 0;
    }
    
    ~BST() {
    
    }
    
    int size() {
        return count;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    void insertNode(Key k, Value v) {
        root = __insert();
    }
};

#endif /* BST_hpp */
