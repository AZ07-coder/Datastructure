#include <iostream>
#include <vector>

using namespace std;

class MyHashSet {
public:
    vector<bool> v;
    MyHashSet() {
        v = vector<bool>(1000001, false);
    }

    // Add key to HashSet
    void add(int key) {
        v[key] = true;
    }

    // Remove key from HashSet
    void remove(int key) {
        v[key] = false;
    }

    // Check if key exists
    bool contains(int key) {
        return v[key];
    }
};

int main() {
    MyHashSet obj;

    obj.add(1);
    obj.add(2);

    cout << obj.contains(1) << endl;  
    cout << obj.contains(3) << endl;  


    obj.add(3);
    cout << obj.contains(3) << endl; 

 
    obj.remove(2);
    cout << obj.contains(2) << endl;  // 0 (false)

    return 0;
}