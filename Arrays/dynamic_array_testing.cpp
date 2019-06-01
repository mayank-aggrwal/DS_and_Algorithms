 
#include <iostream>
#include "dynamic_array.cpp"

using namespace std;

int main() {

    dArray<int> v;
    cout << "v.capacity : " << v.capcity() << endl;
    cout << "v.size : " << v.size() << endl << endl;

    v.push_back(1);
    cout << "After pushhing 1\nv.capacity : " << v.capcity() << endl;
    cout << "v.size : " << v.size() << endl << endl;

    v.push_back(2);
    cout << "After pushhing 2\nv.capacity : " << v.capcity() << endl;
    cout << "v.size : " << v.size() << endl << endl;

    v.push_back(3);
    cout << "After pushhing 3\nv.capacity : " << v.capcity() << endl;
    cout << "v.size : " << v.size() << endl << endl;

    v.push_back(4);
    cout << "After pushhing 4\nv.capacity : " << v.capcity() << endl;
    cout << "v.size : " << v.size() << endl << endl;

    v.push_back(5);
    cout << "After pushhing 5\nv.capacity : " << v.capcity() << endl;
    cout << "v.size : " << v.size() << endl << endl;

    v.push_back(6);
    cout << "After pushhing 6\nv.capacity : " << v.capcity() << endl;
    cout << "v.size : " << v.size() << endl << endl;

    v.clear();
    cout << "After clearing\nv.capacity : " << v.capcity() << endl;
    cout << "v.size : " << v.size() << endl << endl;
    
    int first = v.front();
    cout << "first: " << first << endl;
    cout << "v[0]: " << v.at(0) << endl;
    first = 99;
    cout << "After changing first , v[0]: " << v.at(0) << endl;

    dArray<int> vv(6, 99);
    cout << "vv.capacity : " << vv.capcity() << endl;
    cout << "vv.size : " << vv.size() << endl << endl;


    dArray<int> vvv(vv);
    cout << "vvv.capacity : " << vvv.capcity() << endl;
    cout << "vvv.size : " << vvv.size() << endl << endl;

    dArray<char> c;
    c.push_back('a');
    c.push_back('a');
    c.push_back('a');
    cout << "c.capacity : " << c.capcity() << endl;
    cout << "c.size : " << c.size() << endl << endl;

}