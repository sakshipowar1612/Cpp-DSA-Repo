#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>>adjList;
    void addEdge(int u, int v, int w, bool direction)
    {
        if (direction == 0)
        {
            adjList[u].push_back({v, w});//make_pair(v,w);
            adjList[v].push_back({u, w});//make_pair(v,w);
        }
        else{
            adjList[u].push_back(make_pair(v, w));
        }
        printGraph();
    }


    void printGraph(){
        for(auto i: adjList){
            cout << i.first << " -> { ";
            for (pair<int, int>p: i.second )
            {
                cout << "(" << p.first << ", " << p.second << ")" << ", ";
                 
            }
            cout << "}"<<endl;
            
        }
        cout << endl;
    }

};

int main(){
    Graph g;
    g.addEdge(0, 1, 10, 1);
    g.addEdge(0, 2, 20, 0);

}