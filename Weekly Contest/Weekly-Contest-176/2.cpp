#include <vector>

using namespace std;

class ProductOfNumbers {
private:
    vector<int> v;

public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        const int size = v.size();
        int result = 1;
        for (int i = size - 1; i >= size - k; i--) {
            result *= v[i];
        }
        return result;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */