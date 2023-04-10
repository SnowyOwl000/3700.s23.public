#include <iostream>
#include <random>
#include "bstree.h"

using namespace std;

const int DATA_SIZE = 1000000;
int
    mydata[DATA_SIZE],
    original[DATA_SIZE],
    work[DATA_SIZE],
    counter;

void trav(int &d) {

    mydata[counter] = d;
    counter++;
}

int main() {
    random_device
        rd;
    mt19937
        mt(rd());
    uniform_int_distribution<int>
        dis(0,DATA_SIZE-1);
    SortedLinearList<int>
        bsTree;

    for (int i=0;i<DATA_SIZE;i++)
        original[i] = work[i] = 2 * i;

    for (int i=0;i<DATA_SIZE;i++) {
        int j = dis(mt) % (DATA_SIZE-i);
        bsTree.insert(work[j]);
        mydata[i] = work[j];
        work[j] = work[DATA_SIZE-i-1];
    }

    cout << "Data inserted." << endl;
    cout << "Node count: " << bsTree.size() << endl;
    cout << "Tree height: " << bsTree.height() << endl;

    bool okay = true;
    for (int i : work) {
        try {
            int j = bsTree.search(i);
            if (j != i / 2) {
                cout << "Error: Bad position " << j << " for " << i << endl;
                okay = false;
            }
        } catch (domain_error &e) {
            cout << e.what() << endl;
            okay = false;
        }
    }

    if (okay)
        cout << "Search passes" << endl;
    else
        cout << "Search failed" << endl;

    okay = true;
    for (int i=0;i<DATA_SIZE;i++) {
        int j = bsTree[i];
        if (j != 2 * i) {
            cout << "[] error, tree[" << i << "] == " << j << endl;
            okay = false;
        }
    }

    if (okay)
        cout << "[] passes" << endl;
    else
        cout << "[] failed" << endl;

    counter = 0;
    bsTree.traverse(trav);

    okay = true;
    for (int i=0;i<DATA_SIZE;i++)
        if (mydata[i] != 2 * i) {
            cout << "Error: traversal not in order" << endl;
            okay = false;
        }

    if (okay)
        cout << "Traverse passes" << endl;
    else
        cout << "Traverse failed" << endl;

    for (int i=0;i<DATA_SIZE/2;i++)
        bsTree.remove(4*i);

    counter = 0;
    bsTree.traverse(trav);

    okay = true;
    for (int i=0;i<DATA_SIZE/2;i++)
        if (mydata[i] != 4 * i + 2) {
            cout << "Error in delete" << endl;
            okay = false;
        }

    if (okay)
        cout << "Remove passes" << endl;
    else
        cout << "Remove failed" << endl;

    if (bsTree.isEmpty())
        cout << "Error: tree is empty" << endl;
    else
        cout << "isEmpty() passes part 1" << endl;

    bsTree.clear();
    if (bsTree.isEmpty())
        cout << "clear and isEmpty pass" << endl;
    else
        cout << "clear failed" << endl;

    return 0;
}