#include <iostream>

using namespace std;

const uint32_t
    MAX_POINTS = 100000;

//=============================================================================
// int compareX(const void *a,const void *b)
//   Compare points by x-coordinates, break ties by y-coordinates
//
// Parameters
//  a - pointer to a Point object
//  b - pointer to a Point object
//
// Returns
//  -1 if a < b
//  0 if a == b
//  1 if a > b
//

int compareX(const void *a,const void *b) {
    auto
        *pa = (Point *)a,
        *pb = (Point *)b;
    Fraction
        d = pa->getX() - pb->getX();	// difference in x-coordinates

    // if x-coordinates are different, return 1 or -1
    if (d < 0)
        return -1;
    if (d > 0)
        return 1;
        
    // if we get here, x-coordinates are the same, do the same testing
    // with the y-coordinates
    d = pa->getY() - pb->getY();
    if (d < 0)
        return -1;
    if (d > 0)
        return 1;
        
    // if we get here, the points are the same
    return 0;
}


//=============================================================================
// void sortPointsX(Point *pList,uint32_t nPoints)
//  sort an array of Point objects by x-coordinate
//
// Parameters
//  pList   - an array of Point objects
//  nPoints - the number of Point objects in the pList array
//
// Note:
// - this just uses the C library's qsort() function. This requires a callback
//   function to compare elements; that's the purpose of the compareX() function
//   above
//

void sortPointsX(Point *pList,uint32_t nPoints) {
    qsort(pList,nPoints,sizeof(Point),compareX);
}

//=============================================================================
// int main(int32_t argc,char *argv[])
//  the main function
//
// Parameters
//  argc - number of elements given on the command line. Should be 2.
//  argv - array of C strings holding the contents of the command line
//
// Returns
//  0 if the program runs successfully, 1 if not
//

int main(int32_t argc,char *argv[]) {
    Point
        pList[MAX_POINTS];
    uint32_t
        nPoints,
        p1,p2;
    Fraction
        minDistNaive,
        minDistFast;
    double
        d;

    // make sure there's an option (-n, -f or -b) given on the command line
    if (argc < 2 || argv[1][0] != '-') {
        cout << "Usage error" << endl;
        return 1;
    }

    // read the points
    cin >> nPoints;

    for (uint32_t i=0;i<nPoints;i++)
        cin >> pList[i];

    // -n = use the brute force / naive method
    if (argv[1][1] == 'n') {

        minDistNaive = naiveClosestPair(pList,nPoints,p1,p2);

        cout << "Minimum distance (squared): " << minDistNaive << endl;
        cout << "points: " << pList[p1] << ' ' << pList[p2] << endl;

        d = sqrt(minDistNaive.getNum()) / sqrt(minDistNaive.getDen());

        cout << "Distance: " << d << endl;

    // -f = use the fast / divide and conquer method
    } else if (argv[1][1] == 'f') {

        minDistFast = fastClosestPair(pList,nPoints,p1,p2);

        cout << "Minimum distance (squared): " << minDistFast << endl;
        cout << "points: " << pList[p1] << ' ' << pList[p2] << endl;

        d = sqrt(minDistFast.getNum()) / sqrt(minDistFast.getDen());

        cout << "Distance: " << d << endl;

    // -b = use both methods to compare answers
    } else if (argv[1][1] == 'b') {

        minDistNaive = naiveClosestPair(nPoints,p1,p2);

        cout << "Brute force:" << endl;
        cout << "Minimum distance (squared): " << minDistNaive << endl;
        cout << "points: " << pList[p1] << ' ' << pList[p2] << endl;

        d = sqrt(minDistNaive.getNum()) / sqrt(minDistNaive.getDen());

        cout << "Distance: " << d << endl;

        cout << "\nFast:" << endl;
        minDistFast = fastClosestPair(nPoints,p1,p2);

        cout << "Minimum distance (squared): " << minDistFast << endl;
        cout << "points: " << pList[p1] << ' ' << pList[p2] << endl;

        d = sqrt(minDistFast.getNum()) / sqrt(minDistFast.getDen());

        cout << "Distance: " << d << endl;

    } else {
        cout << "Usage error" << endl;
        return 1;
    }

    return 0;
}
