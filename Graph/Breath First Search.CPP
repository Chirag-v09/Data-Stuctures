#include<iostream>
#include<queue>

using namespace std;

void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    queue <int>q;
    int visited[n] = {0};

    cout << i;
    visited[i] = 1;
    q.push(i);

    while(!q.empty())
    {
        i = q.front();
        q.pop();
        for(j = 0; j < n; j++)
        {
            if(G[i][j] == 1 && visited[j] != 1)
            {
                cout << j;
                q.push(j);
                visited[j] = 1;
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};
    if(visited[start] == 0)
    {
        cout << start;
        visited[start] = 1;
        for(int i = 0; i < n; i++)
        {
            if(G[start][i] == 1 && visited[i] == 0)
                DFS(G, i, n);
        }
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    BFS(G, 4, 7);
    cout << endl;
    DFS(G, 1, 7);

    return 0;
}
