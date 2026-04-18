/*Hash Table Using Quadratic Probing*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

typedef struct {
    int size;
    int *table;
} HashTable;

HashTable* createTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        ht->table[i] = EMPTY;
    }
    return ht;
}

void insert(HashTable* ht, int key) {
    int m = ht->size;
    int h_k = key % m;
    for (int i = 0; i < m; i++) {
        int index = (h_k + i * i) % m;
        if (ht->table[index] == EMPTY) {
            ht->table[index] = key;
            return;
        }
    }
}

void search(HashTable* ht, int key) {
    int m = ht->size;
    int h_k = key % m;
    for (int i = 0; i < m; i++) {
        int index = (h_k + i * i) % m;
        if (ht->table[index] == key) {
            printf("FOUND\n");
            return;
        }
        if (ht->table[index] == EMPTY) {
            break;
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    HashTable* ht = createTable(m);
    char command[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", command, &key);
        if (strcmp(command, "INSERT") == 0) {
            insert(ht, key);
        } else if (strcmp(command, "SEARCH") == 0) {
            search(ht, key);
        }
    }

    free(ht->table);
    free(ht);
    return 0;
}
