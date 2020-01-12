#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    // class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> visited;
        visited.resize(n);
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        int scc = 0;
        int red = 0;

        while (true) {
            bool end = true;
            for (int i = 0; i < connections.size(); i++) {
                if (connections[i][0] != -1) {
                    visited[connections[i][0]] = true;
                    visited[connections[i][1]] = true;
                    connections[i][0] = -1;
                    end = false;
                    break;
                }
            }
            if (end)
                break;

            // find scc
            while (true) {
                bool end = true;
                for (int i = 0; i < connections.size(); i++) {
                    if (connections[i][0] == -1)
                        continue;
                    if (visited[connections[i][0]] && !visited[connections[i][1]]) {
                        visited[connections[i][1]] = true;
                        end = false;
                        connections[i][0] = -1;
                    }
                    else if (!visited[connections[i][0]] && visited[connections[i][1]]) {
                        visited[connections[i][0]] = true;
                        end = false;
                        connections[i][0] = -1;
                    }
                    else if (visited[connections[i][0]] && visited[connections[i][1]]) {
                        red++;
                        connections[i][0] = -1;
                    }
                }
                if (end)
                    break;
            }

            scc++;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                scc++;
        }
        if (red >= scc - 1)
            return scc - 1;
        return -1;
    }
};
};