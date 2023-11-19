#include <bits/stdc++.h>
using namespace std;

class Graph_Competitive
{
private:
    vector<vector<pair<int, int>>> adjList;
public:
    vector<int> distance;
    Graph_Competitive(int V)
    {
        adjList.resize(V);
        distance.resize(V);
        for(int i=0;i<V;i++){
            distance[i]=0;
        }
        for (int i = 0; i < V; i++)
        {
            while (1)
            {
                int x;
                cin >> x;
                if (x == -1)
                    break;
                int w;
                cin >> w;
                adjList[i].push_back(make_pair(x, w));
            }
        }
        cout << "Graph Created" << endl;
    }

    void Dijkstra(int s)
    {
        vector<int> dist(adjList.size(), __INT_MAX__);
        vector<bool> visited(adjList.size(), false);
        dist[s] = 0;
        for (int i = 0; i < adjList.size(); i++)
        {
            int u = minDistance(dist, visited);
            visited[u] = true;
            for (auto j = adjList[u].begin(); j != adjList[u].end(); j++)
            {
                if (!visited[j->first] && dist[u] != __INT_MAX__ && dist[u] + j->second < dist[j->first])
                {
                    dist[j->first] = dist[u] + j->second;
                }
            }
        }
        for (int i = 0; i < adjList.size(); i++)
        {
            cout << i << " " << dist[i] << endl;
        }
    }

    int minDistance(vector<int> dist, vector<bool> visited)
    {
        int min = __INT_MAX__;
        int min_index;
        for (int i = 0; i < adjList.size(); i++)
        {
            if (!visited[i] && dist[i] <= min)
            {
                min = dist[i];
                min_index = i;
            }
        }
        return min_index;
    }

    void DijkstraV2(int s)
    {
        vector<int> dist(adjList.size(), __INT_MAX__);
        vector<bool> visited(adjList.size(), false);
        dist[s] = 0;
        for (int i = 0; i < adjList.size(); i++)
        {
            int u = minDistance(dist, visited);
            visited[u] = true;
            for (auto j = adjList[u].begin(); j != adjList[u].end(); j++)
            {
                if (!visited[j->first] && dist[u] != __INT_MAX__ && dist[u] + j->second < dist[j->first])
                {
                    dist[j->first] = dist[u] + j->second;
                }
            }
        }
        for (int i = 0; i < adjList.size(); i++)
        {
            //cout << i << " " << dist[i] << endl;
            distance[i]=dist[i];
        }
    }
    void DijkstraV3(int s)
    {
        vector<int> dist(adjList.size(), __INT_MAX__);
        vector<bool> visited(adjList.size(), false);
        dist[s] = 0;
        for (int i = 0; i < adjList.size(); i++)
        {
            int u = minDistance(dist, visited);
            visited[u] = true;
            for (auto j = adjList[u].begin(); j != adjList[u].end(); j++)
            {
                if (!visited[j->first] && dist[u] != __INT_MAX__ && dist[u] + j->second < dist[j->first])
                {
                    dist[j->first] = dist[u] + j->second;
                }
            }
        }
        cout<<"The possible meeting point is: ";
        int min=-1;
        for (int i = 0; i < adjList.size(); i++)
        {
            if(dist[i]=distance[i]){
                if(min==-1)min=i;
                else{
                    if(dist[i]<dist[min]){
                        min=i;
                    }
                }
            }
        }
        cout<<min<<endl;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    Graph_Competitive g(n);
    cout<<"Enter the starting points"<<endl;
    int p,q;
    cin>>p>>q;
    g.DijkstraV2(p);
    g.DijkstraV3(q);
    return 0;
}
