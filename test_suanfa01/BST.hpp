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
#include <queue>

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
        
        Node(Node *node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
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
    
    // 向以node为根的二叉搜索树中，查看是否包含键值为k的节点
    bool __contain(Node *node, Key k) {
        
        if (node == NULL) {
            return false;
        }
        
        if (node->key == k) {
            return true;
        }
        
        if (node->key > k) {
            return __contain(node->left, k);
        } else {
            return __contain(node->right, k);
        }
    }
    
    // 在以node为根的二叉搜索树中，查找k对应的value值
    Value* __search(Node *node, Key k) {
        
        if (node == NULL) {
            return NULL;
        }
        
        if (node->key == k) {
            return &(node->value);
        }
        
        if (node->key > k) {
            return __search(node->left, k);
        } else {
            return __search(node->right, k);
        }
    }
    
    // ******二叉树遍历******
    /*
        深度优先遍历：分为前序，中序，后续遍历
        广度优先遍历：
     
        * 二叉搜索树的中序遍历结果为一个由小到大的有序序列
     */
    // 对以node为根的二叉搜索树进行前序遍历
    void __preOrder(Node *node) {
        if (node != NULL) {
            cout << node->key << endl;
            __preOrder(node->left);
            __preOrder(node->right);
        }
    }
    
    // 对以node为根的二叉搜索树进行中序遍历
    void __inOrder(Node *node) {
        if (node != NULL) {
            __inOrder(node->left);
            cout << node->key << endl;
            __inOrder(node->right);
        }
    }
    
    // 对以node为根的二叉搜索树进行前序遍历
    void __postOrder(Node *node) {
        if (node != NULL) {
            __postOrder(node->left);
            __postOrder(node->right);
            cout << node->key << endl;
        }
    }
    
    // 广度优先遍历（层序遍历），借助队列
    void __levelOrder(Node *root) {
        queue<Node *> q;
        q.push(root);
        
        while (!q.empty()) {
            // 取出队首元素
            Node *node = q.front();
            // pop掉队首元素
            q.pop();
            // 处理队首元素
            cout << node->key << endl;
            
            // 将当前元素的左右孩子节点入队
            if (node->left) {
                q.push(node->left);
            }
            
            if (node->right) {
                q.push(node->right);
            }
        }
    }
    
    
    // 寻找最小值
    Node *minimun(Node *node) {
        if (node->left == NULL) {
            return node;
        }
        
        return minimun(node->left);
    }
    
    // 删除掉以node为根的二叉搜索树的最小节点
    // 返回删除节点后的新的二分搜索树的根
    Node* removeMin(Node *node) {
        if (node->left == NULL) {
            Node *rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        
        node->left = removeMin(node->left);
        return node;
    }
    
    // 寻找最小值
    Node *maximun(Node *node) {
        if (node->right == NULL) {
            return node;
        }
        
        return maximun(node->right);
    }
    
    // 删除掉以node为根的二叉搜索树的最大节点
    // 返回删除节点后的新的二分搜索树的根
    Node* removeMax(Node *node) {
        if (node->right == NULL) {
            Node *leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }
        
        node->right = removeMin(node->right);
        return node;
    }
    
    // 删除掉以node为根的二叉搜索树中键为k的节点
    // 返回删除节点后的新的二分搜索树的根
    Node* remove(Node *node, Key k) {
        if (node == NULL) {
            return NULL;
        }
        
        if (node->key > k) {
            node->left = remove(node->left, k);
            return node;
        } else if (node->key < k) {
            node->right = remove(node->right, k);
            return node;
        } else { // 相等,还要分没有左子节点，和没有右子节点，和左右子节点都有的情况
            
            if (node->left == NULL) {
                Node rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            
            if (node->right == NULL) {
                Node *leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            
            // 左右子字节都存在
            Node *delNode = node;
            // 新的根节点为左子树中最大节点（或者右子树中最小节点）
            Node *newRoot = maximun(new Node(delNode->left));
            count++;
            // 这里要注意删除最小元素后, newRoot就指向空了，所以这里需要copy
            newRoot->left = removeMin(delNode->left);
            newRoot->right = delNode->right;
            delete delNode;
            count--;
            return newRoot;
        }
    }
    
    void __destroy(Node *node) {
        if (node != NULL) {
            __destroy(node->left);
            __destroy(node->right);
            
            delete node;
            count--;
        }
    }
    
public:
    BST() {
        root = NULL;
        count = 0;
    }
    
    ~BST() {
        // 析构函数要用后续遍历
        __destroy(root);
    }
    
    int size() {
        return count;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    // 插入
    void insertNode(Key k, Value v) {
        root = __insert();
    }
    
    // 包含
    bool contain(Key k) {
        return __contain(root, k);
    }
    
    // 查找
    Value* search(Key k) {
        return __search(root, k);
    }
    
    // 前序遍历
    void preOrder() {
        __preOrder(root);
    }
    
    

};

#endif /* BST_hpp */
