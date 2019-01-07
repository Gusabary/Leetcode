class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode *> Q;
        Q.push(root);
        int num=1;
        //int tmp_num=0;
        int maxlen=0;
        int k=0;
        while (!Q.empty())
        {
            bool isFindLeft=false;
            int left;
            int right;
            bool flag=false;
            for (int i=1;i<=num;i++)
            {
                TreeNode *cnt;
                cnt=Q.front();
                if (!isFindLeft&&cnt!=NULL)
                {
                    isFindLeft=true;
                    left=i;
                }
                if (isFindLeft&&cnt!=NULL)
                    right=i;
                if (cnt!=NULL)
                {
                    flag=true;
                    Q.push(cnt->left);
                    Q.push(cnt->right);
                }
                if (isFindLeft&&cnt==NULL)
                {
                    Q.push(NULL);
                    Q.push(NULL);
                }
                if (!isFindLeft&&cnt==NULL)
                    k++;
                //tmp_num+=2;
                Q.pop();
            }
            if (!flag)
                break;
            num=(num-k)*2;
            //tmp_num=0;
            k=0;
            int length=right-left+1;
            if (length>maxlen)
                maxlen=length;
        }
        return maxlen;
    }
};