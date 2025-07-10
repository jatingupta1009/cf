#define pp pair<int,int>
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& v) {
        int n= v.size(), m= v[0].size();

        deque<pp>dq;
        vector<vector<int>>distance(n, vector<int>(m, INT_MAX));
        dq.push_front({0,0});
        distance[0][0]=0;

        int dx[]={-1, 1, 0, 0};
        int dy[]={0, 0, -1, 1};

        while(dq.size())
        {
            pp curr= dq.front(); dq.pop_front();
            int i= curr.first;
            int j= curr.second;

            for(int d=0; d<4; d++)
            {
                int newi= i+ dx[d];
                int newj= j+ dy[d];

                if(newi>=0 && newj>=0 && newi<n && newj<m)
                {
                    int newCost= v[newi][newj]+ distance[i][j];
                    if(distance[newi][newj]>newCost)
                    {
                        distance[newi][newj]= newCost;

                        if(v[newi][newj]==0) dq.push_front({newi, newj});
                        else dq.push_back({newi, newj});
                    }
                }
            }
        }
        return distance[n-1][m-1];
    }
};
