/*
References :
- https://www.youtube.com/watch?v=H1cK1QXw6Zs
- https://www.youtube.com/watch?v=Mhj-JkEHQ4E
- https://www.youtube.com/watch?v=fk-AtA2vC9s
*/

#include <iostream>
#include <vector>
using namespace std;

// Vector is a Dynamic array

void main()
{
    vector<int> myVector;
    myVector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : myVector) // for i in myVector
        cout << i << "  ";

    vector<int> myVector1(5); // max elements is 5
}
// OUTPUT: 1  2  3  4  5  6  7  8  9