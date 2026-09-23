// https://leetcode.com/problems/house-robber-ii/

int f(int day, vector<vector<int>> &points, int last)
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
        return maxi;
    }
    int maxi=0;
    
    for(int task=0; task<3; task++)
    {
        if(task!=last)
        {
            int point = points[day][task] + f(day-1, points, task);
            maxi = max(maxi, point);
        }
    }
    return maxi;

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return f(n-1, points, 3);
}
