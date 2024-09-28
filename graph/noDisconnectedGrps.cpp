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

    void BFS(T src, unordered_map<T,bool>&visited){
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


    void DFS(T src, unordered_map<T, bool>&visited){
        visited[src]=true;
        for(auto i: adjList[src]){
            if (!visited[i.first])
            {
                BFS(i.first, visited);

            }
            
        }
    }
};

int main(){
    Graph <char>g;
    g.addEdge('a', 'b', 10, 1);
    g.addEdge('a', 'c', 20, 1);
    g.addEdge('e', 'f', 10, 1);
    //In ths case rather than calling for only one source we should give call for every node
    unordered_map<char, bool>visited;
    int noDisconnects = 0;
    for(char node='a'; node<='f'; node++){
        if (!visited[node])
        {
            g.DFS(node, visited);
            noDisconnects++;
        }
        
    }
    cout << "no. of disconnected graphs: " << noDisconnects << endl;


}