#include <iostream>
#include <random>
#include "disjointSet.h"

using namespace std;

int main() {
    DisjointSet
        ds(10);
    random_device
        rd;
    mt19937
        mt(rd());
    uniform_int_distribution<>
        dis(0,9);
    uint32_t
        a,b;

    for (uint32_t i=0;i<9;i++) {
        for (uint32_t j=0;j<10;j++)
            cout << j << "->" << ds.find(j) << ' ';
        cout << endl;

        do {
            a = dis(mt);
            b = dis(mt);
        } while (ds.find(a) == ds.find(b));

        cout << "Union: " << a << ' ' << b << endl;
        ds.join(a,b);
    }

    for (uint32_t j=0;j<10;j++)
        cout << j << "->" << ds.find(j) << ' ';
    cout << endl;

    return 0;
}
