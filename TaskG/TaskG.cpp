#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

struct Node {
    int x;
    double y;
    int size;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    assert(newNode != NULL);

    newNode->x = x;
    newNode->y = rand() / (RAND_MAX + 1.0);
    newNode->size = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int size(struct Node* node) {
    return node ? node->size : 0;
}

void updateSize(struct Node* node) {
    if (node) {
        node->size = size(node->left) + size(node->right) + 1;
    }
}

struct Node* merge(struct Node* left, struct Node* right) {
    if (!left || !right) {
        return left ? left : right;
    }

    if (left->y > right->y) {
        left->right = merge(left->right, right);
        updateSize(left);
        return left;
    } 
    
    else {
        right->left = merge(left, right->left);
        updateSize(right);
        return right;
    }
}

void split(struct Node* node, int x, struct Node** left, struct Node** right) {
    assert(left != NULL);
    assert(right != NULL);

    if (!node) {
        *left = *right = NULL;
    } 
    
    else if (node->x <= x) {
        *left = node;
        split(node->right, x, &((*left)->right), right);
        updateSize(*left);
    } 
    
    else {
        *right = node;
        split(node->left, x, left, &((*right)->left));
        updateSize(*right);
    }
}

struct Node* insert(struct Node* root, int x) {
    struct Node *left, *right;
    assert(root != NULL);

    split(root, x, &left, &right);

    if (!right || right->x != x) {
        struct Node* newNode = createNode(x);
        return merge(merge(left, newNode), right);
    }

    return root;
}

struct Node* erase(struct Node* root, int key) {
    assert(root != NULL);

    if (root->x == key) {
        root = merge(root->left, root->right);

        if (root != NULL) {
            root->size--;
        }
    } 
    
    else if (root->x < key) {
        root->right = erase(root->right, key);
        
        if (root->right != NULL) {
            root->size--; 
        }
    } 
    
    else {
        root->left = erase(root->left, key);

        if (root->left != NULL) {
            root->size--; 
        }
    }

    updateSize (root);
    return root;
}

bool exists(struct Node* root, int x) {
    assert(root != NULL);

    while (root) {
        if (root->x == x) {
            return true;
        } 
        
        else if (root->x < x) {
            root = root->right;
        } 
        
        else {
            root = root->left;
        }
    }
    return false;
}

int next_val(struct Node* root, int x) {
    int res = -1000000000;
    while (root != NULL) {
        if (root->x > x) {
            res = root->x;
            root = root->left;
        } 
        
        else {
            root = root->right;
        }
    }
    return res;
}

int prev_val(struct Node* root, int x) {
    int res = -1000000000;
    while (root) {
        if (root->x < x) {
            res = root->x;
            root = root->right;
        } 
        
        else {
            root = root->left;
        }
    }
    return res;
}

int kth(struct Node* root, int k) {
    if (root == NULL || k >= size(root) || k < 0) {
        return -1000000000; 
    }

    while (root != NULL) {
        int leftSize = size(root->left);

        if (k == leftSize) {
            return root->x;
        } 
        
        else if (k < leftSize) {
            root = root->left;
        } 
        
        else {
            k -= leftSize + 1;
            root = root->right;
        }
    }
    return -1000000000; 
}


struct Node* del(struct Node* root, int x) {
    if (!root) return NULL;
    root->size--;

    if (root->x == x) {
        return merge (root->left, root->right);
    }

    if (x < root->x) {
        root->left = del (root->left, x);
    } 
    
    else {    
        root->right = del (root->right, x);
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    char operation[_MAX_FNAME];
    int value;

    while (scanf("%s", operation) != EOF) {
        assert (scanf ("%s", operation) == 1);

        if (strcmp (operation, "insert") == 0) {
            assert (scanf ("%d", &value) == 1);
            if (!exists (root, value))
                root = insert (root, value);
        } 
        
        else if (strcmp(operation, "exists") == 0) {
            assert(scanf("%d", &value) == 1);
            printf("%s\n", exists(root, value) ? "true" : "false");
        } 
        
        else if (strcmp (operation, "next") == 0) {
            assert (scanf("%d", &value) == 1);

            if (next_val (root, value) != -1000000000)
                printf ("%d\n", next_val (root, value));

            else
                printf ("none\n");
        } 
        
        else if (strcmp (operation, "prev") == 0) {
            assert (scanf("%d", &value) == 1);
            if (prev_val (root, value) != -1000000000)
                printf ("%d\n", prev_val (root, value));

            else
                printf ("none\n");
        } 
        
        else if (strcmp (operation, "delete") == 0) {
            assert (scanf ("%d", &value) == 1);
            root = erase (root, value);
        } 
        
        else if (strcmp(operation, "kth") == 0) {
            assert (scanf("%d", &value) == 1);
            if (kth (root, value) != -1000000000)
                printf ("%d\n", kth(root, value));

            else
                printf ("none\n");
        }
    }

    return 0;
}
