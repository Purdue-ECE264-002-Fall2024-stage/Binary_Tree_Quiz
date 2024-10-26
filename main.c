#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

// DO NOT MODIFY THIS FILE

// helper functions
static void push(Stack** stack, void* val)
{
    ListNode* node = malloc(sizeof *node);
    *node = (ListNode) { .val = val, .next = (*stack)->head };
    (*stack)->head = node;
    (*stack)->size++;
}

static void* pop(Stack** stack)
{
    if (!(*stack)->size) return NULL;
    ListNode* pop_node = (*stack)->head;
    (*stack)->head = (*stack)->head->next;
    void* ret_val = pop_node->val;
    free(pop_node);
    (*stack)->size--;
    return ret_val;
}

static TreeNode* build_tree(FILE* fptr)
{
    TreeNode* new_node = NULL;
    Stack* stack = malloc(sizeof *stack);
    *stack = (Stack) { .head = NULL, .size = 0 };
    int val;

    while (true)
    {
        int read_val = fscanf(fptr, "%d", &val);

        if (read_val == EOF) break;
        
        else if (read_val == 0)
        {
            // Insert Null node
            char c;
            fscanf(fptr, "%c", &c);
            new_node = NULL;
        }
        
        else
        {
            // Read leaf node
            new_node = malloc(sizeof *new_node);
            *new_node = (TreeNode) { .val = val, .left = NULL, .right = NULL };
        }


        if (new_node != NULL)
        {
            new_node->right = pop(&stack);
            new_node->left = pop(&stack);
        }

        push(&stack, new_node); // Push current node onto stack
    }

    TreeNode* root = pop(&stack);
    assert(stack->size == 0);
    free(stack);
    return root;
}

static void free_tree(TreeNode* root)
{
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root->left);
    free(root->right);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    
    TreeNode* root = build_tree(fptr);
    fclose(fptr);
    
    bin_tree_counter(root); // your function
    
    free_tree(root);
    free(root);
    return EXIT_SUCCESS;
}