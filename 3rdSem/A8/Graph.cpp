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
        }
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
    g.addEdge(0, 4);
    g.printGraph();
    return 0;
}
