
#if 1

// From : https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

// #include <bits/stdc++.h>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <my.hpp>

#define INF 0x3f3f3f3f
using namespace  std;


// typedef pair<int, int> iPair;
using iPair = pair<int,int>;

class Graph {
    int V;

    list<iPair> *adj;

    public:
    Graph(int V);

    void addEdge(int u, int v, int w);
    void addEdge(tuple<int,int,int>);
    void shortestPath(int s);
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}


void Graph::addEdge(tuple<int,int,int> e) {
    adj[get<0>(e)].push_back({get<1>(e), get<2>(e)});
    adj[get<1>(e)].push_back({get<0>(e), get<2>(e)});
}

void Graph::shortestPath(int src) {

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    vector<int> dist(V,INF);

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        list<pair<int, int>>::iterator i;
        for(i = adj[cur].begin();i != adj[cur].end();++i) {
            int adjNode = (*i).first;
            int weight = (*i).second;

            if(dist[adjNode] > dist[cur] + weight) {
                dist[adjNode] = dist[cur] + weight;

                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << my::ts() << "Vertex Distance from source \n";
    for(int i = 0;i<V;++i) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main(int argc, char* argv[]) {
    string fileName;
    unordered_map<string, string> pMap;
    for (size_t i = 1; i < argc; i++)
    {
        if('-' == argv[i][0] 
            && strlen(argv[i]) > 1
            && i+1 < argc) {
                // string name(argv[i]+1);
                // string value(argv[i+1]);
                // pMap[name] = value;
                // pMap.emplace(name, value));
                pMap.emplace(argv[i]+1, argv[i+1]);
                i++;
        }
    }

    if(pMap.find("f") == pMap.end()) 
        fileName  =  "input.txt";
    else 
        fileName = pMap["f"];

    fstream fs(fileName, fs.binary|fs.in);
    
    int i;
    string line;
    stringstream ss;
    vector<tuple<int,int,int>> tl;
    while(getline(fs,line)) {
        int s,d,w;
        ss.str(line);
        cout << my::ts() << (i++) << " : " << line << '\n';
        ss >> s >> d >> w;
        tl.push_back({s,d,w});
    }

    Graph g(tl.size());

    auto tli = tl.begin();
    while(tli != tl.end()) {
        g.addEdge(*tli);
        ++tli;
    }
    
    g.shortestPath(0);

    getline(cin, line);
}

#endif