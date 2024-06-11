#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a > b) ? a : b)
#define BILLION 1000000000

/// Structure representing a node in the AVL tree.
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};


/**
 * @brief Finds the largest key in the AVL tree that is less than or equal to k.
 *
 * @param root The root of the AVL tree.
 * @param k The key to find the predecessor for.
 * @return The largest key less than or equal to k, or -1 if no such key exists.
 */
int find (struct Node* root, int k) {
    if (root != NULL) {
        if (root->left != NULL &&  root->left->key >= k)
            return find (root->left, k);

        else if (root->right != NULL && root->key < k)
            return find (root->right, k);

        else {
            return (root->key);
        }
    }

    return -1;
}

int main() {
    struct Node* root = NULL;

    int n, temp = 0;
    if (scanf("%d", &n) == 1) {
        printf ("ERROR: scanf != 1");
        return 0;
    }
    getchar();

    while (n--) {
        char q;
        int x;

        if (scanf("%c %d", &q, &x) != 2){
            printf ("ERROR: scanf != 2");
            return 0;
        }

        getchar();

        if (q == '+') {
            root = insert(root, (x + temp) % BILLION);
            temp = 0;
        } 
        
        else {
            temp = find(root, x);

            if (temp < x) {
                printf ("%d\n", -1);
                temp = BILLION - 1;
            }

            else
                printf("%d\n", temp);
        }
    }

    return 0;
}

struct Node* newNode (int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    assert (node);

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int height (struct Node* node) {
    if (node == NULL)
        return 0;

    return node->height;
}

struct Node* rightRotate (struct Node* x) {
    struct Node* y = x->left;
    struct Node* T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = max (height(x->left), height(x->right)) + 1;
    y->height = max (height(y->left), height(y->right)) + 1;

    return y;
}

struct Node* leftRotate (struct Node* y) {
    struct Node* x = y->right;
    struct Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = max (height(y->left), height(y->right)) + 1;
    x->height = max (height(x->left), height(x->right)) + 1;

    return x;
}

int getBalance (struct Node* node) {
    if (node == NULL)
        return 0;

    return height (node->left) - height (node->right);
}

struct Node* insert (struct Node* node, int key) {
    if (node == NULL)
        return newNode (key);

    if (key < node->key)
        node->left = insert (node->left, key);

    else if (key > node->key)
        node->right = insert (node->right, key);

    else
        return node;

    node->height = 1 + max (height(node->left), height(node->right));
    int balance = getBalance (node);

    // Левый поворот
    if (balance > 1 && key < node->left->key)
        return rightRotate (node);

    // Правый поворот
    if (balance < -1 && key > node->right->key)
        return leftRotate (node);

    // Левый поворот, а затем правый поворот
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate (node->left);
        return rightRotate (node);
    }

    // Правый поворот, а затем левый поворот
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate (node->right);
        return leftRotate (node);
    }

    return node;
}
