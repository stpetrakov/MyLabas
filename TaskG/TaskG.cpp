#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define INF 1000000000

/// Enumeration for different operations on the treap.
enum Operations {
    INSERT = 1,  ///< Insert a key into the treap.
    EXISTS = 2,  ///< Check if a key exists in the treap.
    NEXT = 3,    ///< Find the next greater key in the treap.
    PREV = 4,    ///< Find the previous smaller key in the treap.
    DELETE = 5,  ///< Delete a key from the treap.
    KTH = 6      ///< Find the k-th order statistic in the treap.
};

/// Structure representing a node in the treap.
struct Node {
    int key;                ///< The key stored in the node.
    double priority;        ///< The priority of the node for maintaining heap property.
    int size;               ///< The size of the subtree rooted at this node.
    struct Node* left;      ///< Pointer to the left child.
    struct Node* right;     ///< Pointer to the right child.
};

/**
 * @brief Gets the operation code for a given operation string.
 *
 * @param operation The operation string.
 * @return The corresponding operation code.
 */
int get_operation_code(const char *operation) {
    if (strcmp(operation, "insert") == 0)
        return INSERT;

    if (strcmp(operation, "exists") == 0)
        return EXISTS;

    if (strcmp(operation, "next") == 0)
        return NEXT;

    if (strcmp(operation, "prev") == 0)
        return PREV;

    if (strcmp(operation, "delete") == 0)
        return DELETE;

    if (strcmp(operation, "kth") == 0)
        return KTH;

    return -1;
}

/**
 * @brief Creates a new node with a given key.
 *
 * @param key The key to be stored in the new node.
 * @return A pointer to the newly created node.
 */
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

/**
 * @brief Gets the size of a subtree rooted at a given node.
 *
 * @param node The root of the subtree.
 * @return The size of the subtree.
 */
int size(struct Node* node) {
    return node ? node->size : 0;
}

/**
 * @brief Updates the size of a given node based on its children.
 *
 * @param node The node whose size needs to be updated.
 */
void updateSize(struct Node* node) {
    if (node) {
        node->size = size(node->left) + size(node->right) + 1;
    }
}

/**
 * @brief Merges two subtrees into one while maintaining heap property.
 *
 * @param left The root of the left subtree.
 * @param right The root of the right subtree.
 * @return The root of the merged subtree.
 */
struct Node* merge(struct Node* left, struct Node* right) {
    if (!left || !right) {
        return left ? left : right;
    }

    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        updateSize(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        updateSize(right);
        return right;
    }
}

/**
 * @brief Splits a subtree into two subtrees based on a key.
 *
 * @param node The root of the subtree to be split.
 * @param key The key to split the subtree at.
 * @param left A pointer to the root of the left subtree.
 * @param right A pointer to the root of the right subtree.
 */
void split(struct Node* node, int key, struct Node** left, struct Node** right) {
    assert(left != NULL);
    assert(right != NULL);

    if (!node) {
        *left = *right = NULL;
    } else if (node->key <= key) {
        *left = node;
        split(node->right, key, &((*left)->right), right);
        updateSize(*left);
    } else {
        *right = node;
        split(node->left, key, left, &((*right)->left));
        updateSize(*right);
    }
}

/**
 * @brief Inserts a key into the treap.
 *
 * @param root The root of the treap.
 * @param key The key to be inserted.
 * @return The root of the updated treap.
 */
struct Node* insert(struct Node* root, int key) {
    struct Node *left = NULL, *right = NULL;
    split(root, key, &left, &right);

    if (!right || right->key != key) {
        struct Node* newNode = createNode(key);
        root = merge(merge(left, newNode), right);
    } else {
        root = merge(left, right); // if key already exists, just merge back
    }
    return root;
}

/**
 * @brief Deletes a key from the treap.
 *
 * @param root The root of the treap.
 * @param key The key to be deleted.
 * @return The root of the updated treap.
 */
struct Node* erase(struct Node* root, int key) {
    if (!root) return NULL;

    if (root->key == key) {
        struct Node* merged = merge(root->left, root->right);
        free(root);
        return merged;
    } else if (root->key < key) {
        root->right = erase(root->right, key);
    } else {
        root->left = erase(root->left, key);
    }
    updateSize(root);
    return root;
}

/**
 * @brief Checks if a key exists in the treap.
 *
 * @param root The root of the treap.
 * @param key The key to be checked.
 * @return True if the key exists, otherwise false.
 */
bool exists(struct Node* root, int key) {
    while (root) {
        if (root->key == key) {
            return true;
        } else if (root->key < key) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return false;
}

/**
 * @brief Finds the next greater key in the treap.
 *
 * @param root The root of the treap.
 * @param key The key to find the next greater key for.
 * @return The next greater key, or -INF if none exists.
 */
int next_value(struct Node* root, int key) {
    int res = -INF;
    while (root != NULL) {
        if (root->key > key) {
            res = root->key;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return res;
}

/**
 * @brief Finds the previous smaller key in the treap.
 *
 * @param root The root of the treap.
 * @param key The key to find the previous smaller key for.
 * @return The previous smaller key, or -INF if none exists.
 */
int prev_value(struct Node* root, int key) {
    int res = -INF;
    while (root) {
        if (root->key < key) {
            res = root->key;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return res;
}

/**
 * @brief Finds the k-th order statistic (0-indexed) in the treap.
 *
 * @param root The root of the treap.
 * @param k The k-th order statistic to find.
 * @return The k-th smallest key, or -INF if k is out of bounds.
 */
int find_kth_order_statistic(struct Node* root, int k) {
    if (root == NULL || k >= size(root) || k < 0) {
        return -INF;
    }

    while (root != NULL) {
        int leftSize = size(root->left);

        if (k == leftSize) {
            return root->key;
        } else if (k < leftSize) {
            root = root->left;
        } else {
            k -= leftSize + 1;
            root = root->right;
        }
    }
    return -INF;
}

/**
 * @brief The main function to read operations and perform them on the treap.
 */
void solve() {
    struct Node* root = NULL;
    char operation[100];
    int value;

    while (scanf("%s", operation) != EOF) {
        enum Operations code = get_operation_code(operation);
        assert(code != -1);

        switch (code) {
            case INSERT:
                assert(scanf("%d", &value) == 1);
                if (!exists(root, value)) {
                    root = insert(root, value);
                }
                break;

            case EXISTS:
                assert(scanf("%d", &value) == 1);
                printf("%s\n", exists(root, value) ? "true" : "false");
                break;

            case NEXT:
                assert(scanf("%d", &value) == 1);
                {
                    int next = next_value(root, value);
                    if (next != -INF)
                        printf("%d\n", next);
                    else
                        printf("none\n");
                }
                break;

            case PREV:
                assert(scanf("%d", &value) == 1);
                {
                    int prev = prev_value(root, value);
                    if (prev != -INF) {
                        printf("%d\n", prev);
                    } else {
                        printf("none\n");
                    }
                }
                break;

            case DELETE:
                assert(scanf("%d", &value) == 1);
                root = erase(root, value);
                break;

            case KTH:
                assert(scanf("%d", &value) == 1);
                {
                    int kth = find_kth_order_statistic(root, value);
                    if (kth != -INF) {
                        printf("%d\n", kth);
                    } else {
                        printf("none\n");
                    }
                }
                break;

            default:
                fprintf(stderr, "Unknown operation: %s\n", operation);
                exit(EXIT_FAILURE);
        }
    }
}

/**
 * @brief The main entry point of the program.
 *
 * @return Exit status of the program.
 */
int main() {
    solve();
    return 0;
}
