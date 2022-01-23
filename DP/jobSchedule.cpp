class Solution {
public:
    struct Job {
        int start, end, profit;
    };
    static int jobsComp(Job m, Job n) {
        return m.end < n.end;
    }
    int binarySearchLastJob(vector<Job> &jobs, int index) {
        int low = 0, high = index-1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(jobs[mid].end <= jobs[index].start) {
                if(jobs[mid + 1].end <= jobs[index].start) {
                    //this is an extra if just to check if the current mids next number is also not the answer
                    low = mid + 1;
                }else {
                    return mid;
                }
            }else {
                high = mid - 1;
            }
            
        }
        return -1;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<Job> jobs(n); //Combining all the three given vector in one
        vector<int> dp(n, 0); //dp[i] tells us the maximum profit till this index
        for(int i = 0; i < n; i++) {
            jobs[i].start = startTime[i];                                   
            jobs[i].end = endTime[i];  
            jobs[i].profit = profit[i];
        }
        sort(jobs.begin(), jobs.end(), jobsComp); //sort according to endTimes
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                //for first index profit is just equal top profit of that job.
                dp[i] = jobs[i].profit;
                continue;
            }
            //we have to find the last non overlapping job
            int profitIncl = jobs[i].profit;
            int LastProfit = binarySearchLastJob(jobs, i);
            if(LastProfit != -1) {
                profitIncl += dp[LastProfit];
            }
            //Checking if its better to to consider this job or take the profit from the last job
            dp[i] = max(dp[i-1], profitIncl);
        }
        
        return dp[n-1]; //total profit given he have n job options
    }
};
