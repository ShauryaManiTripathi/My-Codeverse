#include <bits/stdc++.h>
using namespace std;

class Graph_adjList
{
private:
    vector<list<int>> adjList;
    vector<list<int>> gRev;
    vector<list<int>> layerList;
    vector<list<int>> BFStree;
    vector<list<int>> DFStree;
    vector<pair<int, int>> timeStamp;

public:
    ////////////////////////////////////////////////////////////////////////////////Constructor
    Graph_adjList(int V)
    {
        adjList.resize(V);
        for (int i = 0; i < V; i++)
        {
            while (1)
            {   
                
                int x;
                cin >> x;
                if (x == -1)
                    break;
                adjList[i].push_back(x);
            }
        }
        cout << "Graph Created" << endl;
    }

    // i.e. most of them work on directed and undirected graphs
    ////////////////////////////////////////////////////////////////////////////////basicBFS
    void BFS(int s)
    {
        bool *visited = new bool[adjList.size()];
        for (int i = 0; i < adjList.size(); i++)
        {
            visited[i] = false;
        }
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty())
        {
            int u = q.front();
            cout << u << " ";
            q.pop();
            for (auto i = adjList[u].begin(); i != adjList[u].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
        free(visited);
    }
    ////////////////////////////////////////////////////////////////////////////////LayerListMaker
    vector<list<int>> BFSLayerList(int s)
    {
        bool *visited = new bool[adjList.size()];
        for (int i = 0; i < adjList.size(); i++)
        {
            visited[i] = false;
        }
        layerList[0].push_back(s);
        visited[s] = true;
        for (int i = 0; !layerList[i].empty(); i++)
        {
            for (auto j = layerList[i].begin(); j != layerList[i].end(); j++)
            {
                for (auto k = adjList[*j].begin(); k != adjList[*j].end(); k++)
                {
                    if (!visited[*k])
                    {
                        visited[*k] = true;
                        layerList[i + 1].push_back(*k);
                    }
                }
            }
        }
        free(visited);
        return layerList;
    }
    ////////////////////////////////////////////////////////////////////////////////
    void DFSrecursive(int s)
    {
        bool *visited = new bool[adjList.size()];
        for (int i = 0; i < adjList.size(); i++)
        {
            visited[i] = false;
        }
        DFSUtil(s, visited);
    }
    // This is utility for DFS
    void DFSUtil(int s, bool visited[])
    {
        visited[s] = true;
        cout << s << " ";
        for (auto i = adjList[s].begin(); i != adjList[s].end(); i++)
        {
            if (!visited[*i])
            {
                DFSUtil(*i, visited);
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////
    void DFSiterative(int s)
    {
        bool *visited = new bool[adjList.size()];
        for (int i = 0; i < adjList.size(); i++)
        {
            visited[i] = false;
        }
        stack<int> st;
        st.push(s);
        visited[s] = true;
        while (!st.empty())
        {
            int u = st.top();
            cout << u << " ";
            st.pop();
            for (auto i = adjList[u].begin(); i != adjList[u].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    st.push(*i);
                }
            }
        }
        free(visited);
    }
    ////////////////////////////////////////////////////////////////////////////////
    void printGraph()
    {
        for (int i = 0; i < adjList.size(); i++)
        {
            cout << i << "->";
            for (auto j = adjList[i].begin(); j != adjList[i].end(); j++)
            {
                cout << *j << " ";
            }
            cout << endl;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }
    void removeEdge(int u, int v)
    {
        adjList[u].remove(v);
    }
    void removeVertex(int u)
    {
        for (int i = 0; i < adjList.size(); i++)
        {
            adjList[i].remove(u);
        }
        adjList[u].clear();
    }
    void addVertex()
    {
        adjList.resize(adjList.size() + 1);
    }
    ////////////////////////////////////////////////////////////////////////////////
    /// This is also utility for checkBipartiteViaColoring
    bool checkBipartiteOneComponent(int i, int *color)
    {
        color[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto j = adjList[u].begin(); j != adjList[u].end(); j++)
            {
                if (color[*j] == -1)
                {
                    color[*j] = 1 - color[u];
                    q.push(*j);
                }
                else if (color[*j] == color[u])
                {
                    return false;
                }
            }
        }
        return true;
    }
    void checkBipartiteViaColoring()
    {
        int *color = new int[adjList.size()];
        for (int i = 0; i < adjList.size(); i++)
        {
            color[i] = -1;
        }
        bool ans = true;
        for (int i = 0; i < adjList.size(); i++)
        {
            if (color[i] == -1)
            {
                ans = ans && checkBipartiteOneComponent(i, color);
            }
        }
        if (ans)
        {
            cout << "Graph is Bipartite" << endl;
        }
        else
        {
            cout << "Graph is not Bipartite" << endl;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////TaTaTa
    void checkBipartiteWithoutColoring(int s)
    {
        bool isBipartite = true;
        int *layernum = new int[adjList.size()];
        bool *visited = new bool[adjList.size()];
        for (int i = 0; i < adjList.size(); i++)
        {
            layernum[i] = -1;
            visited[i] = false;
        }
        queue<int> q;
        q.push(s);
        visited[s] = true;
        layernum[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            cout << u << " ";
            q.pop();
            for (auto i = adjList[u].begin(); i != adjList[u].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    layernum[*i] = layernum[u] + 1;
                    q.push(*i);
                }
                else
                {
                    if (layernum[*i] == layernum[u])
                    {
                        isBipartite = false;
                    }
                }
            }
        }
        if (isBipartite)
        {
            cout << "Graph is Bipartite" << endl;
        }
        else
        {
            cout << "Graph is not Bipartite" << endl;
        }
        free(visited);
    }
    ////////////////////////////////////////////////////////////////////////////////TaTaTa
    /* directed codes for only outward edge adjacencylist data structures
     * will add a theory or probabily code for inward / outward edge adjacency list data structures
     *        __  __     ____   _         ____                  __                              __
     *       / / / /__  / / /  (_)____   / __/___  _____   ____/ /__  ____ ___  ____  ___  ____/ /
     *      / /_/ / _ \/ / /  / / ___/  / /_/ __ \/ ___/  / __  / _ \/ __ `__ \/ __ \/ _ \/ __  /
     *     / __  /  __/ / /  / (__  )  / __/ /_/ / /     / /_/ /  __/ / / / / / / / /  __/ /_/ /
     *    /_/ /_/\___/_/_/  /_/____/  /_/  \____/_/      \__,_/\___/_/ /_/ /_/_/ /_/\___/\__,_/                                                                                                                   /____/   /____/
     */
    // LETS START CODING
    ////////////////////////////////////////////////////////////////////////////////ta ta ta...
    void dijkstra(int s)
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
                if (!visited[*j] && dist[u] != __INT_MAX__ && dist[u] + 1 < dist[*j])
                {
                    dist[*j] = dist[u] + 1;
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

    void Greversal()
    {
        gRev.resize(adjList.size());
        for (int i = 0; i < adjList.size(); i++)
        {
            for (auto j = adjList[i].begin(); j != adjList[i].end(); i++)
            {
                gRev[*j].push_front(i);
            }
        }
    }
    vector<bool> MinSet;
    vector<bool> visitedd;
    void FindSet_Algo1(){
        MinSet.resize(adjList.size());
        visitedd.resize(adjList.size());
        for(int i=0;i<visitedd.size();i++){
            visitedd[i]=false;
            MinSet[i]=false;
        }
        for(int i=0;i<visitedd.size();i++){
            if(!visitedd[i])
            FindSetUtil(i);
        }
    }
    void FindSetUtil(int s){
        queue<int> q;
        q.push(s);
        visitedd[s] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            bool test=true;
            for (auto i = adjList[u].begin(); i != adjList[u].end(); i++)
            {
                if (!visitedd[*i])
                {
                    test=false;

                    visitedd[*i] = true;
                    q.push(*i);
                }
                else{
                    
                }
            }
            if(test)MinSet[u]=true;

        }
    }
};
class Graph_Competitive
{
private:
    vector<vector<pair<int, int>>> adjList;

public:
    Graph_Competitive(int V)
    {
        adjList.resize(V);
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
    void printGraph()
    {
        for (int i = 0; i < adjList.size(); i++)
        {
            cout << i << "->";
            for (auto j = adjList[i].begin(); j != adjList[i].end(); j++)
            {
                cout << "(" << j->first << "," << j->second << ") ";
            }
            cout << endl;
        }
    }
    void addEdge(int u, int v, int w)
    {
        adjList[u].push_back(make_pair(v, w));
    }
    void removeEdge(int u, int v)
    {
        for (int i = 0; i < adjList[u].size(); i++)
        {
            if (adjList[u][i].first == v)
            {
                adjList[u].erase(adjList[u].begin() + i);
            }
        }
    }
    void removeVertex(int u)
    {
        for (int i = 0; i < adjList.size(); i++)
        {
            for (int j = 0; j < adjList[i].size(); j++)
            {
                if (adjList[i][j].first == u)
                {
                    adjList[i].erase(adjList[i].begin() + j);
                }
            }
        }
        adjList[u].clear();
    }
    void addVertex()
    {
        adjList.resize(adjList.size() + 1);
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

    // implement kruskal code
    // void kruskal()
    // {
    //     vector<pair<int, pair<int, int>>> edges;
    //     for (int i = 0; i < adjList.size(); i++)
    //     {
    //         for (auto j = adjList[i].begin(); j != adjList[i].end(); j++)
    //         {
    //             edges.push_back(make_pair(j->second, make_pair(i, j->first)));
    //         }
    //     }
    //     sort(edges.begin(), edges.end());
    //     Union_find_Array_Tree uf(adjList.size());
    //     for (int i = 0; i < edges.size(); i++)
    //     {
    //         if (uf.Union(edges[i].second.first, edges[i].second.second))
    //         {
    //             cout << edges[i].second.first << " " << edges[i].second.second << endl;
    //         }
    //     }
    // }

    void prim()
    {
        vector<int> parent(adjList.size(), -1);
        vector<int> key(adjList.size(), __INT_MAX__);
        vector<bool> visited(adjList.size(), false);
        key[0] = 0;
        for (int i = 0; i < adjList.size(); i++)
        {
            int u = minKey(key, visited);
            visited[u] = true;
            for (auto j = adjList[u].begin(); j != adjList[u].end(); j++)
            {
                if (!visited[j->first] && key[j->first] > j->second)
                {
                    key[j->first] = j->second;
                    parent[j->first] = u;
                }
            }
        }
        for (int i = 1; i < adjList.size(); i++)
        {
            cout << parent[i] << " " << i << endl;
        }
    }
    int minKey(vector<int> key, vector<bool> visited)
    {
        int min = __INT_MAX__;
        int min_index;
        for (int i = 0; i < adjList.size(); i++)
        {
            if (!visited[i] && key[i] <= min)
            {
                min = key[i];
                min_index = i;
            }
        }
        return min_index;
    }
};

class Union_find_Array_Tree
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    Union_find_Array_Tree(int V)
    {
        parent.resize(V);
        rank.resize(V);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    int Union(int u, int v)
    {
        int u_rep = find(u);
        int v_rep = find(v);
        if (u_rep == v_rep)
        {
            return 0;
        }
        if (rank[u_rep] > rank[v_rep])
        {
            parent[v_rep] = u_rep;
        }
        else if (rank[u_rep] < rank[v_rep])
        {
            parent[u_rep] = v_rep;
        }
        else
        {
            parent[u_rep] = v_rep;
            rank[v_rep]++;
        }
        return 1;
    }
};

class Union_Find_DoublyLinkedList
{
    struct Node
    {
        int data;
        Node *left;
        Node *right;
    };

private:
    vector<struct Node *> addr;

public:
    Union_Find_DoublyLinkedList(int V)
    {
        addr.resize(V);
        for (int i = 0; i < V; i++)
        {
            addr[i] = new Node;
            addr[i]->data = i;
            addr[i]->left = NULL;
            addr[i]->right = NULL;
        }
    }
    Node *find(int u)
    {
        Node *temp = addr[u];
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }
    int Union(int u, int v)
    {
        Node *u_rep = find(u);
        Node *v_rep = find(v);
        if (u_rep == v_rep)
        {
            return 0;
        }
        addr[u]->right = addr[v];
        addr[v]->left = addr[u];
        return 1;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    Graph_adjList g(n);
    g.FindSet_Algo1();
    cout<<"The set is"<<endl;
    for(int i=0;i<g.MinSet.size();i++){
        if(g.MinSet[i]==false){
            cout<<i<<" ";
        }
    }
    
    return 0;
}
