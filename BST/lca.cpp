#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t
{
    int key;
    struct bstnode_t
        *left,
        *right,
        *parent;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(BSTNode *root, int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->parent = root;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, BSTNode *node, int value)
{
    if (node == NULL)
        return __bst__createNode(root, value);
    root = node;
    if (value < node->key)
        node->left = __bst__insert(root, node->left, value);

    else if (value > node->key)
        node->right = __bst__insert(root, node->right, value);

    return node;
}

BSTNode *__bst__search(BSTNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

BSTNode *bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return NULL;

    if (temp->key == value)
        return temp;
    else
        return NULL;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, bst->_root, value);
        bst->_size++;
    }
}

int main()
{
    BST tri;
    bst_init(&tri);
    int tc;
    scanf("%d\n", &tc);
    while (tc--)
    {
        int opt;
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            int a;
            scanf("%d", &a);
            bst_insert(&tri, a);
            continue;
        case 2:
            int p1, p2;
            scanf("%d %d", &p1, &p2);
            if (!bst_find(&tri, p1) || !bst_find(&tri, p2))
                puts("Data tidak valid.");
            else
            {
                BSTNode *temp, *temp2;
                temp = bst_find(&tri, p1);
                while (temp->parent != NULL)
                {
                    temp2 = temp;
                    while (temp2 != NULL)
                    {
                        if (temp2->key < p2)
                        {
                            if (temp2->right && temp2->right->key != p1)
                                temp2 = temp2->right;
                            else break;
                        }
                        else if (temp2->key > p2)
                        {
                            if (temp2->left && temp2->left->key != p1)
                                temp2 = temp2->left;
                            else break;
                        }
                        else break;
                    }
                    if (temp2->key == p2)
                        break;
                    temp = temp->parent;
                }
                printf("%d\n", temp->key);
            }
            continue;
        default:
            printf("Input tidak valid.\n");
        }
    }
    return 0;
}