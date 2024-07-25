#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, int>>>adjList;
    void addEdge(T u, T v, int w, bool direction)
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
            for (pair<T, int>p: i.second )
            {
                cout << "(" << p.first << ", " << p.second << ")" << ", ";
                 
            }
            cout << "}"<<endl;
            
        }
        cout << endl;
    }
};

int main(){
    Graph <char>g;
    g.addEdge('a', 'b', 10, 1);
    g.addEdge('a', 'c', 20, 0);

}