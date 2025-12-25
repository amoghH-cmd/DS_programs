#include <stdio.h>
#define MAX 20
int hashTable[MAX];
void initHashTable(int m) {
    for (int i = 0; i < m; i++) {
        hashTable[i] = -1; // -1 means empty slot
    }
}
int insertKey(int key, int m) {
    int index = key % m;
    int start = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % m;
        if (index == start) {
            printf("Hash Table Overflow! Cannot insert key %d\n", key);
            return -1;
        }
    }
    hashTable[index] = key;
    return index;
}
void displayHashTable(int m) {
    printf("\nHash Table contents:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("Address %d -> Key %d\n", i, hashTable[i]);
        else
            printf("Address %d -> Empty\n", i);
    }
}
int main() {
    int n, m, key;
    printf("Enter size of hash table (m): ");
    scanf("%d", &m);
    initHashTable(m);
    printf("Enter number of employee records (N): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter 4-digit key for employee %d: ", i + 1);
        scanf("%d", &key);
        int addr = insertKey(key, m);
        if (addr != -1)
            printf("Key %d mapped to address %d\n", key, addr);
    }
    displayHashTable(m);
    return 0;
}
