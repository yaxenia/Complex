// Find minimum vertex cover for forest graph.
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int vertex_cover_size( vector<vector<int>> graph, int n)
{
    int k = 0, size = 0;
    while(k < n)
    {

        for(int i = 0; i < n; ++i)
        {

            if(graph[i].empty())
                k++;

            else if(graph[i].size() == 1)
            {
                int vr = *graph[i].begin();
                for(auto j = graph[vr].begin(); graph[vr].end() != j; ++j)
                {

                    auto it = find(graph[*j].begin(), graph[*j].end() , vr);
                    graph[*j].erase(it);
                }
                graph[vr].clear();
                size++;
            }
        }
    }
    return size;
}
int main()
{
    int n = 0;
    int b = 0;
    int c = 0;
    vector<vector<int>> graph;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        auto *t = new vector<int>;
        graph.push_back(*t);
        cin >> b;
        for(int j = 0; j < b; ++j)
        {
            cin >> c;
            graph[i].push_back(c);
        }
        delete t;
    }

    cout << vertex_cover_size(graph, n);
}
