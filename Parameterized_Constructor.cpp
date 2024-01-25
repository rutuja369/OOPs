/*
Parameterized Constructor->
- It takes parameters to initialize the data/properties of an object
*/

#include <bits/stdc++.h>
using namespace std;

class Point
{
    int x, y;

public:
    // parameterized constructor-> constructor that takes parameters as arguments
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    void printData()
    {
        cout << "The point is (" << x << " , " << y << ")" << endl;
    }
    friend double dist(Point p, Point q);
};

// Function to cal-> distance between two points
double dist(Point p, Point q)
{
    double dist = sqrt(((q.x - p.x) * (q.x - p.x)) + ((q.y - p.y) * (q.y - p.y)));
    return dist;
}

int main()
{
    // Implicit Call
    Point p1(1, 2);
    p1.printData();

    // Explicit Call
    Point p2 = Point(3, 5);
    p2.printData();

    cout << "Distance between p1 and p2 is " << dist(p1, p2) << endl;
    return 0;
}