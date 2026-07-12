// 14. Path Sum (Binary Tree)#include <stdio.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

int hasPathSum(struct Node *root, int sum)
{

    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return (sum == root->data);

    return hasPathSum(root->left, sum - root->data) ||
           hasPathSum(root->right, sum - root->data);
}

int main()
{
    printf("Function implemented successfully.\n");
    printf("Create a binary tree and call hasPathSum(root, sum).\n");
    return 0;
}