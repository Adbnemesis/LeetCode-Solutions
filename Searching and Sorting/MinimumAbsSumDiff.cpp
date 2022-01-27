class Solution
{
public:
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int str[n];
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            str[i] = abs(nums1[i] - nums2[i]);
            sum += str[i];
            sum %= (long long)1000000007;
        }
        sort(nums1.begin(), nums1.end());
        int bestdiff[n];

        for (int i = 0; i < n; i++)
        {
            int x, y;
            auto itr = upper_bound(nums1.begin(), nums1.end(), nums2[i]);
            auto ir = upper_bound(nums1.begin(), nums1.end(), nums2[i]);
            if (itr != nums1.end())
            {
                y = itr - nums1.begin();
                if (ir != nums1.begin())
                {
                    ir--;
                    x = ir - nums1.begin();
                    bestdiff[i] = min(abs(nums2[i] - nums1[x]), abs(nums2[i] - nums1[y]));
                }
                else
                {
                    bestdiff[i] = abs(nums2[i] - nums1[y]);
                }
            }
            else if (itr == nums1.end())
            {
                if (ir != nums1.begin())
                {
                    ir--;
                    x = ir - nums1.begin();
                    bestdiff[i] = abs(nums2[i] - nums1[x]);
                }
                else
                    bestdiff[i] = str[i];
            }
        }
        int saved = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            saved = max(saved, str[i] - bestdiff[i]);
        }
        sum -= saved;
        if (sum < 0)
            sum += (long long)(1E9 + 7);
        return (int)sum;
    }
};
