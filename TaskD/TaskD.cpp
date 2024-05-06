#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define mod 2147483647LL
#define FIRST_LEVEL_SIZE  1000007
#define SECOND_LEVEL_SIZE 19

struct ListNode {
    unsigned int key;
    struct ListNode* next;
};

struct FirstLevelNode {
    struct ListNode* table[SECOND_LEVEL_SIZE];
};

struct PerfectHashTable {
    struct FirstLevelNode* table[FIRST_LEVEL_SIZE];
};

unsigned int firstLevelHash(unsigned int key) {
    return key % FIRST_LEVEL_SIZE;
}

unsigned int secondLevelHash(unsigned int key) {
    return key % SECOND_LEVEL_SIZE;
}

void insert(struct PerfectHashTable* pht, unsigned int key) {
    assert (pht);

    unsigned int firstIndex = firstLevelHash(key);
    unsigned int secondIndex = secondLevelHash(key);

    if (pht->table[firstIndex] == NULL) {
        pht->table[firstIndex] = (struct FirstLevelNode*)malloc(sizeof(struct FirstLevelNode));
        assert (pht->table);
        
        for (unsigned int i = 0; i < SECOND_LEVEL_SIZE; i++) {
            pht->table[firstIndex]->table[i] = NULL;
        }
    }

    if (pht->table[firstIndex]->table[secondIndex] == NULL) {
        pht->table[firstIndex]->table[secondIndex] = (struct ListNode*)malloc(sizeof(struct ListNode));
        pht->table[firstIndex]->table[secondIndex]->key = key;
        pht->table[firstIndex]->table[secondIndex]->next = NULL;
    }
}

bool search(struct PerfectHashTable* pht, unsigned int key) {
    assert (pht);
    assert (pht->table);

    unsigned int firstIndex = firstLevelHash(key);
    unsigned int secondIndex = secondLevelHash(key);

    if (pht->table[firstIndex] != NULL && pht->table[firstIndex]->table[secondIndex] != NULL)
        return true; 
    else 
        return false; 
}

void freeHashTable(struct PerfectHashTable* pht) {
    assert (pht);
    assert (pht->table);

    for (unsigned int i = 0; i < FIRST_LEVEL_SIZE; i++) {
        if (pht->table[i] != NULL) {
            for (unsigned int j = 0; j < SECOND_LEVEL_SIZE; j++) {
                struct ListNode* current = pht->table[i]->table[j];
            
                while (current != NULL) {
                    struct ListNode* temp = current;
                    current = current->next;
                    free(temp);
                }
            }
            free(pht->table[i]);
        }
    }
}

int main() {
    struct PerfectHashTable pht;

    for (unsigned int i = 0; i < FIRST_LEVEL_SIZE; i++) {
        pht.table[i] = NULL;
    }

    unsigned int n;
    assert (scanf("%u", &n) == 1);

    for (unsigned int i = 0; i < n; i++) {
        unsigned int x;
        assert (scanf("%u", &x) == 1);
        insert (&pht, x + mod);
    }

    while (true) {
        unsigned int x = 0;

        if (scanf("%u", &x) != 1) {
            break; 
        }
        
        if (search(&pht, x + mod))
            printf("YES\n");
        
        else
            printf("NO\n");
    }

    freeHashTable(&pht);

    return 0;
}
