#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Node {
    char call_sign[600]; 
    char aircraft[600];  
    struct Node *left;
    struct Node *right;
};

struct Node* createNode (const char* call_sign, const char* aircraft) {
    assert(call_sign != NULL && aircraft != NULL);

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    assert(newNode != NULL);

    strcpy(newNode->call_sign, call_sign);
    strcpy(newNode->aircraft, aircraft);

    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* rotateRight (struct Node* node) {
    assert(node != NULL && node->left != NULL);

    struct Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    return newRoot;
}

struct Node* rotateLeft (struct Node* node) {
    assert(node != NULL && node->right != NULL);

    struct Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    return newRoot;
}

struct Node* splay (struct Node* root, const char* call_sign) {
    assert(call_sign != NULL);

    if (root == NULL || strcmp(root->call_sign, call_sign) == 0)
        return root;

    if (strcmp(call_sign, root->call_sign) < 0) {
        if (root->left == NULL) 
            return root;
        
        if (strcmp(call_sign, root->left->call_sign) < 0) {
            // Zig-Zig (Left Left)
            root->left->left = splay(root->left->left, call_sign);
            root = rotateRight(root);
        } 
        
        else if (strcmp(call_sign, root->left->call_sign) > 0) {
            // Zig-Zag (Left Right)
            root->left->right = splay(root->left->right, call_sign);
            
            if (root->left->right != NULL)
                root->left = rotateLeft(root->left);
        }

        return (root->left == NULL) ? root : rotateRight(root);
    } 
    
    else {
        if (root->right == NULL) return root;

        if (strcmp(call_sign, root->right->call_sign) > 0) {
            // Zig-Zig (Right Right)
            root->right->right = splay(root->right->right, call_sign);
            root = rotateLeft(root);
        } 
        
        else if (strcmp(call_sign, root->right->call_sign) < 0) {
            // Zig-Zag (Right Left)
            root->right->left = splay(root->right->left, call_sign);

            if (root->right->left != NULL)
                root->right = rotateRight(root->right);
        }

        return (root->right == NULL) ? root : rotateLeft(root);
    }
}

struct Node* insert(struct Node* root, const char* call_sign, const char* aircraft) {
    assert(call_sign != NULL && aircraft != NULL);

    if (root == NULL) 
        return createNode(call_sign, aircraft);

    root = splay(root, call_sign);

    if (strcmp(call_sign, root->call_sign) == 0) 
        return root;

    struct Node* newNode = createNode(call_sign, aircraft);

    if (strcmp(call_sign, root->call_sign) < 0) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    } 
    
    else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }
    return newNode;
}

const char* search(struct Node* root, const char* call_sign) {
    assert(call_sign != NULL);

    if (root == NULL) {
        return "none";
    }

    while (root != NULL) {
        if (strcmp(root->call_sign, call_sign) == 0) {
            root = splay(root, call_sign);
            return root->aircraft;
        }
        
        else if (strcmp(call_sign, root->call_sign) < 0) {
            root = root->left;
        }
        
        else {
            root = root->right;
        }
    }

    return "none";
}

void deleteTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
}

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf ("ERROR: scanf != 1");
        return 0;
    }

    struct Node* root = NULL;

    for (int i = 0; i < n; ++i) {
        char call_sign[600], aircraft[600];
        if (scanf ("%600s %600s", call_sign, aircraft) != 2) {
            printf ("ERROR: scanf != 2");
            return 0;
        }
        assert(strlen(call_sign) <= 599);
        assert(strlen(aircraft) <= 599);

        root = insert (root, call_sign, aircraft);
        root = insert (root, aircraft, call_sign);
    }

    int q;
    if (scanf("%d", &q) != 1) {
        printf ("ERROR: scanf != 1");
        return 0;
    }

    for (int i = 0; i < q; ++i) {
        char call_sign[600];
        if (scanf ("%600s", call_sign) != 1) {
            printf ("ERROR: scanf != 1");
            return 0;
        }

        assert(strlen(call_sign) <= 599);

        const char* result = search (root, call_sign);
        printf("%s\n", result);
    }
    
    deleteTree (root);

    return 0;
}
