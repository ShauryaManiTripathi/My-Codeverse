#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<map>
#include<stack>
using namespace std;

class Graph_adjList
{
    private:
    vector<list<int>> adjList;
    vector<list<int>> layerList;
    vector<list<int>> BFStree;
    vector<list<int>> DFStree;
    public:
        ////////////////////////////////////////////////////////////////////////////////Constructor
        Graph_adjList(int V){
            adjList.resize(V);
            for (int i = 0; i < V; i++)
            {
                while(1){
                    int x;
                    cin>>x;
                    if(x==-1) break;
                    adjList[i].push_back(x);
                }
            }
        cout<<"Graph Created"<<endl;
        }
        /***
         *      _   _           _                     
         *     | \ | |         | |                    
         *     |  \| |   ___   | |_     ___    ___    
         *     | . ` |  / _ \  | __|   / __|  / _ \   
         *     | |\  | | (_) | | |_    \__ \ | (_) |  
         *     |_| \_|  \___/   \__|   |___/  \___/   
         *                                            
         *                                            
         *      _____                   _         _   
         *     |  __ \                 (_)       | |  
         *     | |__) |   __ _    ___   _   ___  | |_ 
         *     |  _  /   / _` |  / __| | | / __| | __|
         *     | | \ \  | (_| | | (__  | | \__ \ | |_ 
         *     |_|  \_\  \__,_|  \___| |_| |___/  \__|
         *                                            
         *                                            
         *       _____               _                
         *      / ____|             | |               
         *     | |        ___     __| |   ___   ___   
         *     | |       / _ \   / _` |  / _ \ / __|  
         *     | |____  | (_) | | (_| | |  __/ \__ \  
         *      \_____|  \___/   \__,_|  \___| |___/  
         *                                            
         *                                            
         */
        // i.e. most of them work on directed and undirected graphs
        ////////////////////////////////////////////////////////////////////////////////basicBFS
        void BFS(int s){
            bool *visited = new bool[adjList.size()];
            for (int i = 0; i < adjList.size(); i++)
            {
                visited[i] = false;
            }
            queue<int> q;
            q.push(s);
            visited[s] = true;
            while(!q.empty()){
                int u = q.front();
                cout<<u<<" ";
                q.pop();
                for(auto i = adjList[u].begin(); i!=adjList[u].end(); i++){
                    if(!visited[*i]){
                        visited[*i] = true;
                        q.push(*i);
                    }
                }
            }
            free(visited);
        }    vector<list<int>> adjList;

        ////////////////////////////////////////////////////////////////////////////////LayerListMaker
        vector<list<int>> BFSLayerList(int s){
            bool *visited = new bool[adjList.size()];
            for (int i = 0; i < adjList.size(); i++)
            {
                visited[i] = false;
            }
            layerList[0].push_back(s);
            visited[s] = true;
            for(int i=0; !layerList[i].empty();i++){
                for(auto j = layerList[i].begin(); j!=layerList[i].end(); j++){
                    for(auto k = adjList[*j].begin(); k!=adjList[*j].end(); k++){
                        if(!visited[*k]){
                            visited[*k] = true;
                            layerList[i+1].push_back(*k);
                        }
                    }
                }
            }
            free(visited);
            return layerList;
        }
        ////////////////////////////////////////////////////////////////////////////////
        void DFSrecursive(int s){
            bool *visited = new bool[adjList.size()];
            for (int i = 0; i < adjList.size(); i++)
            {
                visited[i] = false;
            }
            DFSUtil(s, visited);
        }
        // This is utility for DFS
        void DFSUtil(int s, bool visited[]){
            visited[s] = true;
            cout<<s<<" ";
            for(auto i = adjList[s].begin(); i!=adjList[s].end(); i++){
                if(!visited[*i]){
                    DFSUtil(*i, visited);
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////////
        void DFSiterative(int s){
            bool *visited = new bool[adjList.size()];
            for (int i = 0; i < adjList.size(); i++)
            {
                visited[i] = false;
            }
            stack<int> st;
            st.push(s);
            visited[s] = true;
            while(!st.empty()){
                int u = st.top();
                cout<<u<<" ";
                st.pop();
                for(auto i = adjList[u].begin(); i!=adjList[u].end(); i++){
                    if(!visited[*i]){
                        visited[*i] = true;
                        st.push(*i);
                    }
                }
            }
            free(visited);
        }
        ////////////////////////////////////////////////////////////////////////////////
        void printGraph(){
            for (int i = 0; i < adjList.size(); i++)
            {
                cout<<i<<"->";
                for(auto j = adjList[i].begin(); j!=adjList[i].end(); j++){
                    cout<<*j<<" ";
                }
                cout<<endl;
            }
        }
        ////////////////////////////////////////////////////////////////////////////////
        void addEdge(int u, int v){
            adjList[u].push_back(v);
        }
        void removeEdge(int u, int v){
            adjList[u].remove(v);
        }
        void removeVertex(int u){
            for (int i = 0; i < adjList.size(); i++)
            {
                adjList[i].remove(u);
            }
            adjList[u].clear();
        }
        void addVertex(){
            adjList.resize(adjList.size()+1);
        }
        ////////////////////////////////////////////////////////////////////////////////
        ///This is also utility for checkBipartiteViaColoring
        bool checkBipartiteOneComponent(int i,int *color){
            color[i] = 1;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto j = adjList[u].begin(); j!=adjList[u].end(); j++){
                    if(color[*j]==-1){
                        color[*j] = 1 - color[u];
                        q.push(*j);
                    }
                    else if(color[*j]==color[u]){
                        return false;
                    }
                }
            }
            return true;
        }
        void checkBipartiteViaColoring(){
            int *color = new int[adjList.size()];
            for (int i = 0; i < adjList.size(); i++)
            {
                color[i] = -1;
            }
            bool ans = true;
            for (int i = 0; i < adjList.size(); i++)
            {
                if(color[i]==-1){
                    ans = ans && checkBipartiteOneComponent(i, color);
                }
            }
            if(ans){
                cout<<"Graph is Bipartite"<<endl;
            }
            else{
                cout<<"Graph is not Bipartite"<<endl;
            }
        }
    ////////////////////////////////////////////////////////////////////////////////TaTaTa
        void checkBipartiteWithoutColoring(int s){
            bool isBipartite = true;
            int *layernum= new int[adjList.size()];
            bool *visited = new bool[adjList.size()];
            for (int i = 0; i < adjList.size(); i++)
            {  layernum[i] = -1;   visited[i] = false; }
            queue<int> q;
            q.push(s);
            visited[s] = true;
            layernum[s]=0;
            while(!q.empty()){
                int u = q.front();
                cout<<u<<" ";
                q.pop();
                for(auto i = adjList[u].begin(); i!=adjList[u].end(); i++){
                    if(!visited[*i]){
                        visited[*i] = true;
                        layernum[*i] = layernum[u]+1;
                        q.push(*i);
                    }
                    else {
                        if(layernum[*i]==layernum[u]){
                            isBipartite = false;
                        }
                    }
                }
            }
            if(isBipartite){
                cout<<"Graph is Bipartite"<<endl;
            }
            else{
                cout<<"Graph is not Bipartite"<<endl;
            }
            free(visited);
        }
    ////////////////////////////////////////////////////////////////////////////////TaTaTa
    //Given a connected undirected graph. Find the diameter of this graph.
    //The diameter of a graph is the maximum of minimum distance between any two nodes.
    //the obv and only way is run bfs on each node get the max of all the bfs 
    ////////////////////////////////////////////////////////////////////////////////TaTaTa

    /***
     *      _____    _                        _                _      _____               _              
     *     |  __ \  (_)                      | |              | |    / ____|             | |             
     *     | |  | |  _   _ __    ___    ___  | |_    ___    __| |   | |        ___     __| |   ___   ___ 
     *     | |  | | | | | '__|  / _ \  / __| | __|  / _ \  / _` |   | |       / _ \   / _` |  / _ \ / __|
     *     | |__| | | | | |    |  __/ | (__  | |_  |  __/ | (_| |   | |____  | (_) | | (_| | |  __/ \__ \
     *     |_____/  |_| |_|     \___|  \___|  \__|  \___|  \__,_|    \_____|  \___/   \__,_|  \___| |___/
     *                                                                                                   
     *                                                                                                   
     * directed codes for only outward edge adjacencylist data structures
     * will add a theory or probabily code for inward / outward edge adjacency list data structures
     *        __  __     ____   _         ____                  __                              __
     *       / / / /__  / / /  (_)____   / __/___  _____   ____/ /__  ____ ___  ____  ___  ____/ /
     *      / /_/ / _ \/ / /  / / ___/  / /_/ __ \/ ___/  / __  / _ \/ __ `__ \/ __ \/ _ \/ __  / 
     *     / __  /  __/ / /  / (__  )  / __/ /_/ / /     / /_/ /  __/ / / / / / / / /  __/ /_/ /  
     *    /_/ /_/\___/_/_/  /_/____/  /_/  \____/_/      \__,_/\___/_/ /_/ /_/_/ /_/\___/\__,_/                                                                                                                   /____/   /____/                                                            
     */
    //LETS START CODING
    ////////////////////////////////////////////////////////////////////////////////ta ta ta...
    
};
class Graph_Competitive{
    private:
        vector<vector<pair<int,int>>> adjList;
    public:
        Graph_Competitive(int V){
            adjList.resize(V);
            for (int i = 0; i < V; i++)
            {
                while(1){
                    int x;
                    cin>>x;
                    if(x==-1) break;
                    int w;
                    cin>>w;
                    adjList[i].push_back(make_pair(x,w));
                }
            }
        cout<<"Graph Created"<<endl;
        }
        void printGraph(){
            for (int i = 0; i < adjList.size(); i++)
            {
                cout<<i<<"->";
                for(auto j = adjList[i].begin(); j!=adjList[i].end(); j++){
                    cout<<"("<<j->first<<","<<j->second<<") ";
                }
                cout<<endl;
            }
        }
        void addEdge(int u, int v, int w){
            adjList[u].push_back(make_pair(v,w));
        }
        void removeEdge(int u, int v){
            for (int i = 0; i < adjList[u].size(); i++)
            {
                if(adjList[u][i].first==v){
                    adjList[u].erase(adjList[u].begin()+i);
                }
            }
        }
        void removeVertex(int u){
            for (int i = 0; i < adjList.size(); i++)
            {
                for (int j = 0; j < adjList[i].size(); j++)
                {
                    if(adjList[i][j].first==u){
                        adjList[i].erase(adjList[i].begin()+j);
                    }
                }
            }
            adjList[u].clear();
        }
        void addVertex(){
            adjList.resize(adjList.size()+1);
        }
        

        void Dijkstra(int s){
            vector<int> dist(adjList.size(),__INT_MAX__);
            vector<bool> visited(adjList.size(),false);
            dist[s] = 0;
            for (int i = 0; i < adjList.size(); i++)
            {
                int u = minDistance(dist,visited);
                visited[u] = true; 
                for(auto j = adjList[u].begin(); j!=adjList[u].end(); j++){
                    if(!visited[j->first] && dist[u]!=__INT_MAX__ && dist[u]+j->second<dist[j->first]){
                        dist[j->first] = dist[u]+j->second;
            ba        }
                }
            }
            for (int i = 0; i < adjList.size(); i++)
            {
                cout<<i<<" "<<dist[i]<<endl;
            }
        }

        int minDistance(vector<int> dist, vector<bool> visited){
            int min = __INT_MAX__;
            int min_index;
            for (int i = 0; i < adjList.size(); i++)
            {
                if(!visited[i] && dist[i]<=min){
                    min = dist[i];
                    min_index = i;
                }
            }
            return min_index;
        }


        
};

class Union_find_Array_Tree{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        Union_find_Array_Tree(int V){
            parent.resize(V);
            rank.resize(V);
            for (int i = 0; i < V; i++)
            {
                parent[i] = i;
                rank[i] = 0;
            }
        }
        int find(int u){
            if(parent[u]==u){
                return u;
            }
            return parent[u] = find(parent[u]);
        }

        int Union(int u,int v){
            int u_rep = find(u);
            int v_rep = find(v);
            if(u_rep==v_rep){
                return 0;
            }
            if(rank[u_rep]>rank[v_rep]){
                parent[v_rep] = u_rep;
            }
            else if(rank[u_rep]<rank[v_rep]){
                parent[u_rep] = v_rep;
            }
            else{
                parent[u_rep] = v_rep;
                rank[v_rep]++;
            }
            return 1;
        }      
};

class Union_Find_DoublyLinkedList{
    struct Node{
        int data;
        Node *left;
        Node *right;
    };
    private:
        vector<struct Node*> addr;
    public:
        Union_Find_DoublyLinkedList(int V){
            addr.resize(V);
            for (int i = 0; i < V; i++)
            {
                addr[i] = new Node;
                addr[i]->data = i;
                addr[i]->left = NULL;
                addr[i]->right = NULL;
            }
        }
        Node* find(int u){
            Node *temp = addr[u];
            while(temp->right!=NULL){
                temp = temp->right;
            }
            return temp;
        }
        int Union(int u,int v){
            Node *u_rep = find(u);
            Node *v_rep = find(v);
            if(u_rep==v_rep){
                return 0;
            }
            addr[u]->right=addr[v];
            addr[v]->left=addr[u];
            return 1;
        } 
};

int main(int argc, char const *argv[])
{
    Graph_adjList g(5);
    g.printGraph();
    g.BFS(0);
    cout<<endl;
    g.DFSrecursive(0);
    cout<<endl;
    g.checkBipartiteViaColoring();
    g.checkBipartiteWithoutColoring(0);
    g.addEdge(0, 4);
    g.printGraph();
    return 0;
}
