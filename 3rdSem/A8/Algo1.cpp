#include <bits/stdc++.h>
using namespace std;

class Graph_adjList
{
private:
    vector<list<int>> adjList;
    vector<int> root;
public:
    ////////////////////////////////////////////////////////////////////////////////Constructor
    Graph_adjList(int V)
    {
        root.resize(V);
        adjList.resize(V);
        for (int i = 0; i < V; i++){
            root[i]=0;
        }
        for (int i = 0; i < V; i++)
        {
            while (1)
            {
                int x;
                cin >> x;
                if (x == -1)
                    break;
                adjList[i].push_back(x);
                root[x]=1;
            }
        }
        cout << "Graph Created" << endl;
    }

    void print(){
        for(int i=0;i<root.size();i++){
            if(root[i]==0){
                cout<<i<<" ";
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    Graph_adjList g(n);
    g.print();
    
    
    return 0;
}
