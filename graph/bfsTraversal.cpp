#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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

    void BFS(T src){
        unordered_map<T, bool>visited;
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T front = q.front();
            cout << front << " ";
            q.pop();

            for(auto i : adjList[front]){
                if(visited[i.first]!=true){
                    q.push(i.first);
                    visited[i.first] = true;
                }
            }

        }
    }
};

int main(){
    Graph <char>g;
    g.addEdge('a', 'b', 10, 0);
    g.addEdge('a', 'c', 20, 0);
    g.addEdge('b', 'c', 10, 0);
    g.addEdge('b', 'd', 20, 0);
    g.addEdge('c', 'e', 10, 0);
    g.addEdge('c', 'f', 20, 0);
    g.addEdge('e', 'f', 20, 0);
    g.BFS('a');
    


}