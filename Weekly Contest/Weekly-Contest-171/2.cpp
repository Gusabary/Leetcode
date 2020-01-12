#include <iostream>
#include <math.h>
#include <vector>

std::vector<bool> dec2bin(int x) {
    std::vector<bool> ans;
    while (x > 0) {
        if (x % 2 == 0) {
            ans.push_back(false);
        }
        else {
            ans.push_back(true);
        }
        x = x / 2;
    }
    return ans;
}

int main(int argc, char *argv[]) {
	int a,b,c;
	std::cin >> a >>b>>c;

    std::vector<bool> va = dec2bin(a);
    std::vector<bool> vb = dec2bin(b);
    std::vector<bool> vc = dec2bin(c);

    va.resize(40);
    vb.resize(40);
    vc.resize(40);

    std::cout << va[0] << va[1] << va[2] << va[3] << std::endl;
    std::cout << vb[0] << vb[1] << vb[2] << vb[3] << std::endl;
    std::cout << vc[0] << vc[1] << vc[2] << vc[3] << std::endl;

    int count = 0;
    for (int i = 0; i < vc.size(); i++) {
        if (vc[i]) {
            if (!va[i] && !vb[i])
                count++;
        }
        if (!vc[i]) {
            if (va[i] && vb[i])
                count += 2;
            else if (va[i] || vb[i])
                count++;
        }
    }
    
    std::cout << count << std::endl;
	system("pause");
}