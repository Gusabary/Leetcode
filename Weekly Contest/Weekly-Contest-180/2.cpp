#include <vector>

using namespace std;

class CustomStack {
private:
    vector<int> v;
    int maxSize;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (v.size() == maxSize) {
            return;
        }
        v.push_back(x);
    }
    
    int pop() {
        if (v.empty()) {
            return -1;
        }
        const int rv = v.back();
        v.pop_back();
        return rv;
    }
    
    void increment(int k, int val) {
        if (v.size() < k) {
            for (auto it = v.begin(); it != v.end(); it++) {
                *it += val;
            }
            return;
        }
        for (int i = 0; i < k; i++) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */