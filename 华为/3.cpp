#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DijkstraPath(vector<vector<int> > &g,int &dist,int *path,int v0)   //v0表示源顶点
{
    int i,j,k;
    bool visited[7] = {false, false, false, false, false, false};
    for(i=1;i<=6;i++)     //初始化
    {
        if(g[v0][i]>0&&i!=v0){
            dist[i]=g.matrix[v0][i];
            path[i]=v0;     //path记录最短路径上从v0到i的前一个顶点
        }
        else
        {
            dist[i]=INT_MAX;    //若i不与v0直接相邻，则权值置为无穷大
            path[i]=-1;
        }
        visited[i]=false;
        path[v0]=v0;
        dist[v0]=0;
    }
    visited[v0]=true;
    for(i=1;i<g.n;i++)     //循环扩展n-1次
    {
        int min=INT_MAX;
        int u;
        for(j=0;j<g.n;j++)    //寻找未被扩展的权值最小的顶点
        {
            if(visited[j]==false&&dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }
        visited[u]=true;
        for(k=0;k<g.n;k++)   //更新dist数组的值和路径的值
        {
            if(visited[k]==false&&g.matrix[u][k]>0&&min+g.matrix[u][k]<dist[k])
            {
                dist[k]=min+g.matrix[u][k];
                path[k]=u;
            }
        }
    }
}

int main(){
    int to, fog;
    while(cin >> to >> fog){
        vector<vector<int> > graph = {
            {-1, -1, -1, -1, -1, -1, -1},
            {-1, 0, 2, 10, 5, 3, -1},
            {-1, -1,0, 12, -1, -1 ,10},
            {-1, -1, -1, 0, -1, 7, -1},
            {-1, 2, -1, -1, 1, 0, -1},
            {-1, 4, -1, -1, 1, 0, -1},
            {-1, 3, -1, 1, -1, 2, 0}
        };
        if(fog){
            for(int i = 1; i <= 6; i++){
                graph[fog][i] = -1;
                graph[i][fog] = -1;
            }
        }
        vector<int> result;


    }
    return 0;
}
