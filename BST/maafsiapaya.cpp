#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right, *parent;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(BSTNode *root, int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->parent = root;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, BSTNode *node, int value) {
    if (node == NULL)
        return __bst__createNode(root, value);
    root = node;
    if (value < node->key)
        node->left = __bst__insert(root, node->left, value);

    else if (value > node->key)
        node->right = __bst__insert(root, node->right, value);

    return node;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

BSTNode* bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return NULL;

    if (temp->key == value)
        return temp;
    else
        return NULL;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, bst->_root, value);
        bst->_size++;
    }
}

int main()
{
    BST set;
    bst_init(&set);
    int t, i;

    scanf("%d", &t);
    for(i = 0; i < t; i++) {
        int input;
        scanf("%d", &input);
        if(input == 1) {
            int x;
            scanf("%d", &x);
            bst_insert(&set, x);
        }
        else if(input == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (!bst_find(&set, x) || !bst_find(&set, y))
                printf("Data tidak valid.\n");
            else 
            {
                BSTNode *temp = bst_find(&set, x);
                BSTNode *temp2 = temp;
                while(temp->parent != NULL) 
                {
                    BSTNode *temp2 = temp;
                    while(temp2 != NULL) 
                    {
                        if(temp2->key < y) 
                        {
                            if(temp2->right != NULL && temp2->right->key != x)
                                temp2 = temp2->right;
                            else break;
                        }
                        else if(temp2->key > y)
                        {
                            if(temp2->left != NULL && temp2->left->key != x)
                            {
                                temp2 = temp2->left;
                            }
                            else break;
                        }
                        else break;

                    }
                    if(temp2->key == y)
                        break;
                    temp = temp->parent;
                }
                printf("%d\n", temp->key);
            }
        }
        else
            printf("Input tidak valid.\n");
    }
    return 0;
}