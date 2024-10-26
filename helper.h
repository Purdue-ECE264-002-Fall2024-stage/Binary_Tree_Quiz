#ifndef HELPER_H
#define HELPER_H

// DO NOT MODIFY THIS FILE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _ListNode {
    void* val;
    struct _ListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
    int size;
} Stack;

// Node structure for the linked list
typedef struct _TreeNode {
    int val;
    struct _TreeNode* left;
    struct _TreeNode* right;
} TreeNode;

// Your function
void bin_tree_counter(TreeNode* root);

#endif // HELPER_H
