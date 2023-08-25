#include <iostream>

using namespace std;

class ClosedMidSquareHash {
private:
    int tableSize;
    int* hashTable;

    int midSquare(int key) {
       int squared = key * key;
       string keyStr = to_string(squared);
       int middleIndex = keyStr.length() / 2;
       int hashedValue = stoi(keyStr.substr(middleIndex - 1,2));
    //    cout << "key = " << key << " middle = " << hashedValue << endl;
       return hashedValue ;
    }
public:
    ClosedMidSquareHash(int size) : tableSize(size) {
        hashTable = new int[size];
        for (int i = 0; i < size; ++i) {
            hashTable[i] = -1;
        }
    }

    ClosedMidSquareHash() {
        delete[] hashTable;
    }

    void insert(int key) {
        int index = midSquare(key);
        if (hashTable[index] == -1) {
            hashTable[index] = key;
        } else {
            int originalIndex = index;
            do {
                index = (index + 1) % tableSize;
            } while (hashTable[index] != -1 && index != originalIndex);
            if (index != originalIndex)
                hashTable[index] = key;
            else
                cout << "Hash table is full." << endl;
        }
    }

    bool search(int key) {
        int index = midSquare(key);
        int originalIndex = index;
        while (hashTable[index] != -1) {
            if (hashTable[index] == key)
                return true;
            index = (index + 1) % tableSize;
            if (index == originalIndex)
                break;
        }
        return false;
    }
    void remove(int key) {
        int index = midSquare(key);
        int originalIndex = index;
        while (hashTable[index] != -1) {
            if (hashTable[index] == key) {
                hashTable[index] = -2; 
                return;
            }
            index = (index + 1) % tableSize;
            if (index == originalIndex)
                break;
        }
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            cout << "[" << i << "]: ";
            if (hashTable[i] != -1) {
                cout << hashTable[i];
            }
            cout << endl;
        }
    }
};
int main() {
    ClosedMidSquareHash hashTable(100); 

    int keys[] = {42, 76, 32, 55, 94, 11, 39, 68, 87, 21};

    for (int key : keys) {
        hashTable.insert(key);
    }

    cout << "Hash Table:" << endl;

    int searchKey = 76;
    if (hashTable.search(searchKey)) {
        cout << searchKey << " found in the hash table." << endl;
    } else {
        cout << searchKey << " not found in the hash table." << endl;
    }

    int deleteKey = 32;
    hashTable.remove(deleteKey);
    hashTable.insert(55);

    
    hashTable.display();

    return 0;
}
