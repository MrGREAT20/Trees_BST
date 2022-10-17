bool vis[51][51];
int n, m;
class Solution {
    bool valid(int x, int y, vector<vector<int>>& image, int prev){
        if(x >= n or y >= m) return false;
        if(x < 0 or y < 0) return false;
        if(image[x][y] != prev) return false;
        return true;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        memset(vis, false, sizeof(vis));
        queue<pair<int, int>>q;
        q.push({sr, sc});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1,-1};
        while(!q.empty()){
            int currx = q.front().first;
            int curry = q.front().second;
            int prev = image[currx][curry];
            image[currx][curry] = color;
            q.pop();
            for(int i = 0; i<4; i++){
                if(valid(currx + dx[i], curry + dy[i],image, prev) and !vis[currx + dx[i]][curry + dy[i]])
                {
                    vis[currx + dx[i]][curry + dy[i]] = true;
                    q.push({currx + dx[i], curry + dy[i]});
                }
            }
            
        }
        return image;
    }
};