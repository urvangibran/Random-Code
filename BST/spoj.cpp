/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C
 */

//#include <stdlib.h>
//#include <stdbool.h>
//#include <stdio.h>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    ll key;
    ll member;
    struct bstnode_t 
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned ll _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(ll value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->member = 1ll;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, ll value) {
    if (root == NULL) 
        return __bst__createNode(value);

    root->member++;
    if (value < root->key){
        root->left = __bst__insert(root->left, value);
    }
    else if (value > root->key){
        root->right = __bst__insert(root->right, value);
    }
    return root;
}

ll indexing;
BSTNode* __bst__search(BSTNode *root, ll value) {
    while (root != NULL) {
        /*
        if(indexing == 0){
            if(root->left != NULL){
                indexing = root->member - root->left->member;
            }
            else{
                indexing = root->member;
            }
        }
        */
        if (value < root->key){
            root = root->left;
            /*
            if(root->left != NULL){
                indexing = indexing + (root->member - root->left->member);
            }
            else{
                indexing = indexing + root->member;
            }
            */
        }
        else if (value > root->key){
            root = root->right;
            /*
            if(root->right != NULL){
                indexing = indexing - (root->member - root->right->member);
            }
            else{
                indexing = indexing - root->member;
            }
            */
        }
        else{
            return root;
        }
            
    }
    return root;
}

ll __bst__searchIndex(BSTNode *root, ll value) {
    while (root != NULL) {
        if(indexing == 0){
            if(root->left != NULL){
                indexing = root->member - root->left->member;
            }
            else{
                indexing = root->member;
            }
        }

        if (value < root->key){
            root = root->left;
            if(root->left != NULL){
                indexing = indexing + (root->member - root->left->member);
            }
            else{
                indexing = indexing + root->member;
            }
        }
        else if (value > root->key){
            root = root->right;
            if(root->right != NULL){
                indexing = indexing - (root->member - root->right->member);
            }
            else{
                indexing = indexing - root->member;
            }
        }
        else{
            return indexing;
        }
            
    }
    return indexing;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, ll value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->member);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

/*
ll ind;
ll bendera;
void __indexTraversal(BSTNode *root, ll value){
    if (bendera)
        return;
    if (root) {
        __indexTraversal(root->right, value);
        if (!bendera){
            ind++;
            //cout << ind << " " << value << " " << root->key << endl;
            if(value == root->key){
                bendera = 1ll;
                return;
        }
        }
        __indexTraversal(root->left, value);
    }
}
*/

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0ull;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, ll value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

ll bst_findIndex(BST *bst, ll value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return 0ll;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, ll value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, ll value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

/*
void indexTraversal(BST *bst, ll value){
    __indexTraversal(bst->_root, value);
}
*/
 
int main()
{
    BST set;
    bst_init(&set);
    ll q, kode, nilai;
    
    cin >> q;
    while(q--){
        cin >> kode >> nilai;
        switch (kode)
        {
        case 1ll:
            bst_insert(&set, nilai);
            //bst_inorder(&set);
            break;
        case 2ll:
            //ind = 0ll;
            //bendera = 0ll;
            indexing = 0ll;
            if(bst_find(&set, nilai)){
                //indexTraversal(&set, nilai);
                //cout << ind << endl;
                cout << __bst__searchIndex(set._root, nilai) << endl;
            }
            else
                cout << "Data tidak ada" << endl;
            break;
        }
    }
    
    return 0;
}