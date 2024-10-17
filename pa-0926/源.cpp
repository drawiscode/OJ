#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>ans(n);
        ans[0] = 1;
        int max = 0;
        int maxcnt = 1;
        for (int i = 1; i < n; i++)
        {
            int temp = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && temp < ans[j])
                {
                    temp = ans[j];
                    if (temp + 1 == max)
                    {
                        maxcnt++;
                    }
                    else if (max < temp + 1)
                    {
                        max = temp + 1;
                        maxcnt = 1;
                    }
                }
            }
            ans[i] = temp + 1;

        }
        return maxcnt;
    }
};
int main()
{
    vector<int>ans(5);
    ans[0] = 1, ans[1] = 3, ans[2] = 5, ans[3] = 4, ans[4] = 7;
    Solution s;
    cout << s.findNumberOfLIS(ans);
    return 0;

}