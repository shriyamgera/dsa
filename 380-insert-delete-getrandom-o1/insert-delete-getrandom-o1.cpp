class RandomizedSet {
public:
unordered_map<int,int>mp;
vector<int>currentVals;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        bool isPresent  = mp.count(val);
        if(!isPresent){
            currentVals.push_back(val);
            mp[val] = currentVals.size()-1;
        }
        return !isPresent;
    }
    
    bool remove(int val) {
        bool isPresent  = mp.count(val);
        if(isPresent){
            int idx = mp[val];
            int lastVal = currentVals[currentVals.size()-1];

            currentVals[idx] = lastVal;
            mp[lastVal] = idx;
            currentVals.pop_back();
            mp.erase(val);
        };
        return isPresent;
    }
    
    int getRandom() {
        int randomVal = currentVals[rand() % currentVals.size()];
        return randomVal;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */