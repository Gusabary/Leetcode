class Solution {
public:
    struct node {
        int id;
        vector<node *> unders;
        node(int id) : id(id) {}
    };

    int inform(vector<node *> &alls, vector<int>& informTime, int cur) {
        // cout << cur << endl;
        int time = 0;
        if (!alls[cur]->unders.empty())
        for (node *n : alls[cur]->unders) {
            time = max(time, inform(alls, informTime, n->id));            
        }
        return time + informTime[cur];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<node *> alls(n);
        for (int i = 0; i <n;i++) {
            // cout <<  "i: " << i << endl;
            alls[i] = new node(i);
        }
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] < 0)
                continue;
            alls[manager[i]]->unders.push_back(alls[i]);
        }
        
        

        int ans = inform(alls, informTime, headID);
        return ans;
    }
};