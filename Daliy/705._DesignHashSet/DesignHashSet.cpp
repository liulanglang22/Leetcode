
//
// Created by Admin on 2021/3/13.
//
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class MyHashSet {
private:
    vector<list<int>> data;
    static const int base = 769;//一个质数
    static int hash(int key) {
        return key % base;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() : data(base){}

    void add(int key) {
        int h = hash(key);
        for (auto it : data[h]) {
            if (it == key) {
                return;
            }
        }
        data[h].push_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) {
                data[h].erase(it);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = hash(key);
        for (auto it : data[h]) {
            if (it == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    MyHashSet myHashSet;

    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(1); // 返回 True
    myHashSet.contains(3); // 返回 False ，（未找到）
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(2); // 返回 True
    myHashSet.remove(2);   // set = [1]
    myHashSet.contains(2);

}










