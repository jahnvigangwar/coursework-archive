int f(int day, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
{
    if (day==0)
    {
        int maxi=0;
        for(int task=0; task<3; task++)
        {
            if(task!=last)
            {
                maxi = max(maxi, points[day][task]);
            }
        }
        return dp[day][last] =  maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maxi=0;
    
    for(int task=0; task<3; task++)
    {
        if(task!=last)
        {
            int point = points[day][task] + f(day-1, points, task, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] =  maxi;

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return f(n-1, points, 3, dp);
}