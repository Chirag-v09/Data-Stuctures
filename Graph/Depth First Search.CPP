#include<iostream>
#include<queue>

using namespace std;

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
    DFS(G, 1, 7);

    return 0;
}
