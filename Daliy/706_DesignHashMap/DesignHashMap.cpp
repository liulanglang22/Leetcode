//
// Created by Admin on 2021/3/13.
//
#include <utility>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

class MyHashMap {
private:
    vector<list<pair<int, int>>> data;
    static const int N = 769;
    static int hashKey(int key) {
        return key % N;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() : data(N){}

    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hashKey(key);
        for (auto & it : data[h]) {
            if (it.first == key) {
                it.second = value;
                return ;
            }

        }
        data[h].push_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hashKey(key);
        for(auto it : data[h]) {
            if (it.first == key) {
                return it.second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hashKey(key);
        for (auto it = data[h].begin(); it != data[h].end(); it ++) {
            if ((*it).first == key) {
                data[h].erase(it);
                return ;
            }
        }
    }

    void print() {
        for (int i = 0; i < 5; i++) {
            for (auto it : data[i]) {
                cout << "<" << it.first << "," << it.second << ">" << endl;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
 int main() {
    auto* myHashMap = new MyHashMap();
    myHashMap->put(1, 1); // myHashMap 现在为 [[1,1]]
    myHashMap->print();
    myHashMap->put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
    myHashMap->print();
    myHashMap->get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
    myHashMap->print();
    myHashMap->get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
    myHashMap->print();
    myHashMap->put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
    myHashMap->print();
    myHashMap->get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
    myHashMap->print();
    myHashMap->remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
    myHashMap->print();
    myHashMap->get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
 }