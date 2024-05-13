#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define INF 1000000000

struct Node {
    int key;
    double priority;
    int size;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    assert(newNode != NULL);

    newNode->key = key;
    newNode->priority = rand() / (RAND_MAX + 1.0);
    newNode->size = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
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

    if (left->priority > right->priority) {
        swap(left, right);
    }

    left->right = merge(left->right, right);
    updateSize(left);
    return left;

}

void split(struct Node* node, int key, struct Node** left, struct Node** right) {
    assert(left != NULL);
    assert(right != NULL);

    if (!node) {
        *left = *right = NULL;
    } 
    
    else if (node->key <= key) {
        *left = node;
        split(node->right, key, &((*left)->right), right);
        updateSize(*left);
    } 
    
    else {
        *right = node;
        split(node->left, key, left, &((*right)->left));
        updateSize(*right);
    }
}

struct Node* insert(struct Node* root, int key) {
    struct Node *left, *right;
    assert(root != NULL);

    split(root, key, &left, &right);

    if (!right || right->key != key) {
        struct Node* newNode = createNode(key);
        
        if (!right || key < right->key) {
            newNode->right = right;
            newNode->left = left;
        } else {
            newNode->left = left;
            newNode->right = right->right;
        }
        
        updateSize(newNode);
        
        return newNode;
    }

    return root;
}


struct Node* erase(struct Node* root, int key) {
    assert(root != NULL);

    if (root->key == key) {
        root = merge(root->left, root->right);

        if (root != NULL) {
            root->size--;
        }
    } 
    
    else if (root->key < key) {
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

    updateSize(root);
    return root;
}

bool exists(struct Node* root, int key) {
    assert(root != NULL);

    while (root) {
        if (root->key == key) {
            return true;
        } 
        
        else if (root->key < key) {
            root = root->right;
        } 
        
        else {
            root = root->left;
        }
    }
    return false;
}

int next_value(struct Node* root, int key) {
    int res = -INF;
    while (root != NULL) {
        if (root->key > key) {
            res = root->key;
            root = root->left;
        } 
        
        else {
            root = root->right;
        }
    }
    return res;
}

int prev_value(struct Node* root, int key) {
    int res = -INF;
    while (root) {
        if (root->key < key) {
            res = root->key;
            root = root->right;
        } 
        
        else {
            root = root->left;
        }
    }
    return res;
}

int find_kth_order_statistic(struct Node* root, int k) {
    if (root == NULL || k >= size(root) || k < 0) {
        return -INF; 
    }

    while (root != NULL) {
        int leftSize = size(root->left);

        if (k == leftSize) {
            return root->key;
        } 
        
        else if (k < leftSize) {
            root = root->left;
        } 
        
        else {
            k -= leftSize + 1;
            root = root->right;
        }
    }
    return -INF; 
}


struct Node* del(struct Node* root, int key) {
    if (!root) return NULL;

    if (root->size <= 0)
        return root;

    root->size--;

    if (root->key == key) {
        return merge (root->left, root->right);
    }

    if (key < root->key) {
        root->left = del (root->left, key);
    } 
    
    else {    
        root->right = del (root->right, key);
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

            if (next_value (root, value) != -INF)
                printf ("%d\n", next_value (root, value));

            else
                printf ("none\n");
        } 
        
        else if (strcmp (operation, "prev") == 0) {
            assert (scanf("%d", &value) == 1);
            if (prev_value (root, value) != -INF)
                printf ("%d\n", prev_value (root, value));

            else
                printf ("none\n");
        } 
        
        else if (strcmp (operation, "delete") == 0) {
            assert (scanf ("%d", &value) == 1);
            root = erase (root, value);
        } 
        
        else if (strcmp(operation, "kth") == 0) {
            assert (scanf("%d", &value) == 1);
            if (find_kth_order_statistic (root, value) != -INF)
                printf ("%d\n", find_kth_order_statistic (root, value));

            else
                printf ("none\n");
        }
    }

    return 0;
}
