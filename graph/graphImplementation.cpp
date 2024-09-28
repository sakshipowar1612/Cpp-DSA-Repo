#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class Graph{

    public:
    unordered_map<int, list<int>>adjList;
    void addEdge(int u, int v, bool direction){
        //direction -> 0 -> undirected;
        //direction -> 1 -> directed;
        if (direction==0)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{
            adjList[u].push_back(v);
        }
        cout << "Printing Graph : " << endl;
        printAdjList();
        cout << endl;
    }

    void printAdjList(){
        for (auto i: adjList)
        {
            cout << i.first << " -> { ";
            for (auto neighbours: i.second)
            {
                cout << neighbours << ", ";
            }
            cout << "}" << endl;
        }
        
    }

};


int main(){
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 2, 1);
    return 0;
}