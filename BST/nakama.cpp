#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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

BSTNode *__bst__createNode(BSTNode *root, int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->parents = root;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, BSTNode *node, int value)
{
    if (node == NULL)
        return __bst__createNode(root, value);
    root = node;
    if (value < node->key)
    {
        node->left = __bst__insert(root, node->left, value);
        // root->left->parents = root;
    }

    else if (value > node->key)
    {
        node->right = __bst__insert(root, node->right, value);
        // root->right->parents = root;
    }

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

void _bst_hitungAcak(BSTNode *root, int guess, int *found)
{
    if (root)
    {
        // if (root && (root->left || root->right))
        // {
        //     if (root->left && root->right)
        //     {
        //         if (guess == (root->key + root->left->key + root->right->key) || guess == (root->key + root->parents->key + root->right->key) || guess == (root->key + root->left->key + root->parents->key) && !(*found))
        //         {
        //             printf("%d | | Pintu terbuka! Lanjut eksplorasi.\n", guess);
        //             *found = 1;
        //         }
        //         else
        //         {
        //             _bst_hitungAcak(root->left, guess, found);
        //             _bst_hitungAcak(root->right, guess, found);
        //         }
        //     }
        //     else if (!root->left)
        //     {
        //         if (guess == (root->key + root->parents->key + root->right->key) && !(*found))
        //         {
        //             printf("%d | | Pintu terbuka! Lanjut eksplorasi.\n", guess);
        //             *found = 1;
        //         }
        //         else
        //         {
        //             _bst_hitungAcak(root->right, guess, found);
        //         }
        //     }
        //     else if (!root->right)
        //     {
        //         if (guess == (root->key + root->parents->key + root->left->key) && !(*found))
        //         {
        //             printf("%d | | Pintu terbuka! Lanjut eksplorasi.\n", guess);
        //             *found = 1;
        //         }
        //         else
        //         {
        //             _bst_hitungAcak(root->left, guess, found);
        //         }
        //     }
        if (root->parents)
        {
            if (root->left)
            {
                if (guess == (root->key + root->parents->key + root->left->key) && !(*found))
                {
                    printf("%d | | Pintu terbuka! Lanjut eksplorasi.\n", guess);
                    *found = 1;
                }
            }
            else if (root->right)
            {
                if (guess == (root->key + root->parents->key + root->right->key) && !(*found))
                {
                    printf("%d | | Pintu terbuka! Lanjut eksplorasi.\n", guess);
                    *found = 1;
                }
            }
        }
        else if (root->right && root->left)
        {
            if (guess == (root->key + root->left->key + root->right->key) && !(*found))
            {
                printf("%d | | Pintu terbuka! Lanjut eksplorasi.\n", guess);
                *found = 1;
            }
        }
        _bst_hitungAcak(root->left, guess, found);
        _bst_hitungAcak(root->right, guess, found);

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
        bst->_root = __bst__insert(bst->_root, bst->_root, value);
        bst->_size++;
    }
}

void bst_hitung(BST *bst, int guess)
{
    int found = 0;
    _bst_hitungAcak(bst->_root, guess, &found);
    if (!found)
        printf("%d >< Tidak ditemukan kombinasi yang tepat! Retreat.\n", guess);
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
    // if (found)
    //     printf("%d | | Pintu terbuka! Lanjut eksplorasi.", guess);
    // else
    //     printf("%d >< Tidak ditemukan kombinasi yang tepat! Retreat.", guess);
    return 0;
}