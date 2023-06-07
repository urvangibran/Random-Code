#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int found = 0;

typedef struct bstnode_t
{
    int key;
    struct bstnode_t
        *left,
        *right, *parents;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int value)
{
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
    {
        root->left = __bst__insert(root->left, value);
        root->left->parents = root;
    }

    else if (value > root->key)
    {
        root->right = __bst__insert(root->right, value);
        root->right->parents = root;
    }

    return root;
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

void _bst_hitungAcak(BSTNode *root, int guess)
{
    if (!found)
    {
        if (root && (root->right || root->left))
        {
            if (root->right && root->left)
            {
                if (guess == (root->key + root->right->key + root->left->key) || guess == (root->key + root->parents->key + root->left->key) || guess == (root->key + root->parents->key + root->right->key))
                    found = 1;
                else
                {
                    _bst_hitungAcak(root->right, guess);
                    _bst_hitungAcak(root->left, guess);
                }
            }
            else if(!root->right)
            {
                if(guess == (root->key + root->parents->key + root->left->key))
                    found = 1;
                else 
                    _bst_hitungAcak(root->left, guess);
            }
            else if(!root->left)
            {
                if(guess == (root->key + root->parents->key + root->right->key))
                    found = 1;
                else 
                    _bst_hitungAcak(root->right, guess);
            }

            // if ((guess == (root->key + root->right->key + root->left->key)) || (guess == (root->key + root->parents->key + root->left->key)) || (guess == (root->key + root->parents->key + root->right->key)))
            //     found = 1;
            // else
            // {
            //     if (root->right && root->left)
            //     {
            //         _bst_hitungAcak(root->right, guess);
            //         _bst_hitungAcak(root->left, guess);
            //     }
            //     else if (!root->right)
            //         _bst_hitungAcak(root->left, guess);
            //     else if (!root->left)
            //         _bst_hitungAcak(root->right, guess);
            // }
        }
    }
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

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_hitung(BST *bst, int guess)
{
    int grup = bst->_root->key + bst->_root->left->key + bst->_root->right->key;
    if (guess == (grup))
        found = 1;
    else if (guess > (grup))
        _bst_hitungAcak(bst->_root->right, guess);
    else
        _bst_hitungAcak(bst->_root->left, guess);
}

int main()
{
    BST tri;
    bst_init(&tri);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a;
        scanf("%d", &a);
        bst_insert(&tri, a);
    }
    int guess;
    scanf("%d", &guess);
    bst_hitung(&tri, guess);
    if (found)
        printf("ManTap");
    else
        printf("HAiiyyaAhh SalAhh");
    return 0;
}