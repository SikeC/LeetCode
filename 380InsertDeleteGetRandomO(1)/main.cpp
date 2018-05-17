#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return myset.insert(val).second;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto tmp=myset.insert(val);
        myset.erase(tmp.first);
        return !(tmp.second);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        auto it=myset.begin();
        int count =rand()%myset.size();
        for(int i=0;i<count;i++)
        {
            it++;
        }
        return *it;
    }
    unordered_set<int> myset;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */