#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if ( !hash.count(key) ) return -1;
        auto it = hash[key];
        head.splice(head.begin(), head, it);
        return it->second;
    }
    
    void set(int key, int value) {
        if ( hash.count(key) ) {
            auto it = hash[key];
            it->second = value;
            head.splice(head.begin(), head, it);
            return;
        }

        if ( hash.size() >= capacity ) {
            hash.erase(head.back().first);
            head.pop_back();
        } 
        head.push_front({key,value});
        hash[key] = head.begin();
    }

private:
    int capacity;
    list<pair<int,int>> head;
    unordered_map<int,decltype(head)::iterator> hash;
};

int main(int argc, char *argv[]) {
    // Solution sol;
    {
        list<int> head{1,2,3,4};
        auto it = head.begin();
        head.erase(it);
        cout << *it <<endl;
        head.push_back(*it);
        for (auto i : head) cout << i << " ";
        cout <<endl;
    }

    {
        LRUCache lru(3);
        lru.set(1,1);
        lru.set(2,2);
        lru.set(3,3);
        lru.set(4,4);
        cout << lru.get(1) <<endl;
    }
    return 0;
}
