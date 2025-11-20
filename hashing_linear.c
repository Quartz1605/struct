#include <stdio.h>

#define SIZE 10        
int hashTable[SIZE];   
int EMPTY = -1;        


int hash(int key) {
    return key % SIZE;
}


void insert(int key) {
    
    int index = hash(key);

    
    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (hashTable[newIndex] == EMPTY) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
    }

    printf("Hash Table is full! Cannot insert %d\n", key);
}


void search(int key) {
    
    int index = hash(key);

    
    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (hashTable[newIndex] == key) {
            printf("Key %d found at index %d\n", key, newIndex);
            return;
        }

        if (hashTable[newIndex] == EMPTY) {
            printf("Key %d NOT found!\n", key);
            return;
        }
    }

    printf("Key %d NOT found!\n", key);
    
}

int main() {

    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }

    insert(12);
    insert(22);
    insert(42);
    insert(52);

    search(22);
    search(52);
    search(7);

    return 0;
}
