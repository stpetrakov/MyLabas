#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MOD1 1000007
#define MAX_M2 100

struct ListNode {
    unsigned int key;
    struct ListNode* next;
};


struct FirstLevelNode {
    struct ListNode* table[MAX_M2];
};


struct PerfectHashTable {
    struct FirstLevelNode* table[MOD1];
};


unsigned int random(unsigned int a, unsigned int b) {
    return rand() % (b - a + 1) + a;
}


unsigned int firstLevelHash(unsigned int key) {
    return key % MOD1;
}


unsigned int secondLevelHash(unsigned int key, unsigned int m2) {
    return key % m2;
}


void insert(struct PerfectHashTable* pht, unsigned int key) {
    assert(pht);

    unsigned int firstIndex = firstLevelHash(key);
    unsigned int secondIndex = secondLevelHash(key, MAX_M2);

    if (pht->table[firstIndex] == NULL) {
        pht->table[firstIndex] = (struct FirstLevelNode*)malloc(sizeof(struct FirstLevelNode));
        assert(pht->table[firstIndex]);
        
        for (unsigned int i = 0; i < MAX_M2; i++) {
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
    assert(pht);

    unsigned int firstIndex = firstLevelHash(key);
    unsigned int secondIndex = secondLevelHash(key, MAX_M2);

    if (pht->table[firstIndex] != NULL && pht->table[firstIndex]->table[secondIndex] != NULL)
        return true; 
    else 
        return false; 
}

void freeHashTable(struct PerfectHashTable* pht) {
    assert(pht);

    for (unsigned int i = 0; i < MOD1; i++) {
        if (pht->table[i] != NULL) {
            for (unsigned int j = 0; j < MAX_M2; j++) {
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

bool checkCollisions(struct PerfectHashTable* pht, unsigned int n) {
    unsigned int collisionsSum = 0;

    for (unsigned int i = 0; i < MOD1; i++) {
        if (pht->table[i] != NULL) {
            unsigned int collisionCount = 0;

            for (unsigned int j = 0; j < MAX_M2; j++) {
                struct ListNode* current = pht->table[i]->table[j];

                if (current != NULL) {
                    collisionCount++;
                }
            }

            collisionsSum += collisionCount * collisionCount;
        }
    }
    return collisionsSum <= 4 * n;
}

int main() {
    struct PerfectHashTable pht;
    for (unsigned int i = 0; i < MOD1; i++) {
        pht.table[i] = NULL;
    }

    unsigned int hash1 = random(1, MOD1 - 1);
    unsigned int hash2 = random(1, MOD1 - 1);

    while (true) {
        if (checkCollisions(&pht, MOD1)) {
            break;
        }

        hash1 = random(1, MOD1 - 1);
        hash2 = random(1, MOD1 - 1);
    }

    unsigned int n;

    if (scanf("%u", &n) != 1) {
        return 0; 
    }

    for (unsigned int i = 0; i < n; i++) {
        unsigned int x;

        if (scanf("%u", &x) != 1) {
            break; 
        }

        unsigned int hash = (hash1 * x + hash2) % MOD1;
        insert(&pht, hash);
    }

    while (true) {
        unsigned int x;

        if (scanf("%u", &x) != 1) {
            break; 
        }

        unsigned int hash = (hash1 * x + hash2) % MOD1;
        if (search(&pht, hash)) {
            printf("YES\n");
        } 
        
        else {
            printf("NO\n");
        }
    }

    freeHashTable(&pht);

    return 0;
}
