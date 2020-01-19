#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    string s = "TO BE OR NOT TO BE";

    vector<string> v;
    v.resize(205);

    int i = 0;
    int max = 0;
    for (char c : s) {
        if (c == ' ') {
            for (int j = i; j <= 200; j++)
                v[j].push_back(' ');
            i = 0;
            continue;
        }
        v[i].push_back(c);
        if (max < i)
            max = i;
        i++;
    }

    v.resize(max + 1);
    for (string s : v) {
        int tail = s.find_last_not_of(' ');
        s.erase(tail + 1);
        cout << s.size() << endl;
    }


    system("pause");
}