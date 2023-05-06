// A simple hash table implementation
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

// A hash table entry.  Singly-linked list for chaining collision.
struct entry {
    string key;
    entry *next;
};

// Should be prime
const int TABLE_SIZE = 75011;
static entry *hashTable[TABLE_SIZE];

/*
// Simple modprime
unsigned int genHash(string key) {
    string newKey;
    // Put all the digits together
    for (int i = 0; i < key.size(); i++) {
        if (isdigit(key[i]))
            newKey += key[i];
    }
    unsigned long kInt = stol(newKey);
    // cout << newKey << endl;
    return (kInt % TABLE_SIZE);
}
*/

// The 'djb2' hash
unsigned int genHash(string key) {
    unsigned long hash = 5381;
    for (int i = 0; i < key.size(); i++)
        hash = ((hash << 5) + hash) + key[i];
    return (hash % TABLE_SIZE);
}

// Add a key to the hash
void addKey(string key) {
    // Get the index
    int hIndex = genHash(key);

    // Allocate a new one
    struct entry *newp = new struct entry;
    newp->key = key;
    newp->next = 0;

    // Go to the hash bucket
    struct entry *entp;
    entp = hashTable[hIndex];

    // It's empty, add the new one and we're done
    if (!entp) {
        hashTable[hIndex] = newp;
        return;
    }

    // OK, it's not empty.
    // Find the last entry.
    while (entp->next) {
        entp = entp->next;
    }
    // ...and make it point to the new one.
    entp->next = newp;
}

// Find a node in the hash
bool findNode(string key) {
    int hIndex;

    // Get the index of the hash bucket
    hIndex = genHash(key);

    // Go to the hash bucket
    struct entry *entp;
    entp = hashTable[hIndex];

    // Look through the entries
    while (entp) {
        // Found it
        if (entp->key == key)
            return (true);
        entp = entp->next;
    }

    // Not found
    return (false);
}

bool readKeys(string filename) {
    ifstream f;
    int nKeys = 0;
    string tmp;

    // Check our file
    f.open(filename.c_str());
    if (!f.good()) {
        cerr << "Invalid file." << endl;
        return false;
    }

    // Read the file and hash each key
    while (getline(f, tmp)) {
        if (f.eof())
            break;
        addKey(tmp);
        nKeys++;
    }
    f.close();

    // Consider it a win if we read at least 1 line
    if (nKeys > 0)
        return true;

    return false;
}

// Print some information on the hash table
void printStats() {

    int bSize = 0, bTotal = 0;
    int nEntries = 0;
    int smallest = -1;
    int largest = 0;
    int nEmpty = 0;
    int bucketsWithNodes = 0;

    // Compute average bucket size
    for (int i = 0; i < TABLE_SIZE; i++) {

        // Count the elements in this bucket
        struct entry *entp = hashTable[i];
        bSize = 0;
        if (entp != 0)
            bucketsWithNodes++;
        while (entp) {
            nEntries++;
            bSize++;
            entp = entp->next;
        }

        // Keep a running total
        bTotal += bSize;

        // Check if this is the largest
        if (bSize > largest)
            largest = bSize;

        // Or smallest
        if (smallest == -1 || bSize < smallest)
            smallest = bSize;

        // See if it's empty
        if (bSize == 0)
            nEmpty++;
    }
    cout << fixed << setprecision(4) << endl;

    // Deliver the goods
    cout << endl;
    cout << "Btotal: " << bTotal << endl;
    cout << "Hash table size:      " << TABLE_SIZE << endl;
    cout << "Number of entries:    " << nEntries << endl;
    cout << "Average non-empty bucket size:  " << (double) bTotal / bucketsWithNodes << endl;
    cout << "Largest bucket:       " << largest << endl;
    cout << "Smallest bucket:      " << smallest << endl;
    cout << "Empty buckets:        " << nEmpty << endl;
    cout << endl;
}

int main() {

    for (;;) {
        string tmp;
        string filename;
        int choice;

        cout << endl;
        cout << "Hashmaster 1000" << endl;
        cout << "---------------" << endl;
        cout << "1) Add string keys from a file" << endl;
        cout << "2) Check if a key exists" << endl;
        cout << "3) Print hash statistics" << endl;
        cout << "Enter your choice (-1 to quit): ";
        getline(cin, tmp);
        choice = atoi(tmp.c_str());
        switch (choice) {
        case 1:
            cout << "File to use? " << endl;
            getline(cin, filename);
            if (!readKeys(filename)) {
                cout << "File was not read, try again." << endl;
                continue;
            }
            cout << endl;
            cout << "OK, file reading complete." << endl;
            break;
        case 2:
            cout << "Key to find? " << endl;
            getline(cin, tmp);
            if (findNode(tmp))
                cout << "That key exists." << endl;
            else
                cout << "That key does not exist." << endl;
            cout << endl;
            break;
        case 3:
            printStats();
            break;
        case -1:
            cout << endl;
            cout << "Done." << endl;
            return (0);
            break;
        }
    }
}
