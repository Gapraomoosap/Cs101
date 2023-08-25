#include <iostream>
#include <list>

using namespace std;

class HashTable {
private:
    int size;
    list<int>* table;

    int hashFunction(int key) {
        // Mid-square hashing
        int squared = key * key;
        string keyStr = to_string(squared);
        int middleIndex = keyStr.length() / 2;
        int hashedValue = stoi(keyStr.substr(middleIndex - 1, 2));
        return hashedValue % size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table = new list<int>[size];
    }

    HashTable() {
        delete[] table;
    }

    void insert(int key) {
        int hashValue = hashFunction(key);
        table[hashValue].push_back(key);
    }

    bool search(int key) {
        int hashValue = hashFunction(key);
        for (const auto& storedKey : table[hashValue]) {
            if (storedKey == key) {
                return true;
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << "Slot " << i << ": ";
            for (const auto& storedKey : table[i]) {
                cout << storedKey << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable(10);

    hashTable.insert(10170);
    hashTable.insert(10013);
    hashTable.insert(10331);
    hashTable.insert(10200);
    hashTable.insert(30391);

    hashTable.display();


    return 0;
}