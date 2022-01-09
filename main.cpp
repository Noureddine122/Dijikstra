#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


class Graph
{
    int V;
    list< pair<int, int> > *adj;

public:
    explicit Graph(int V);


    void addEdge(int u, int v, int w);

    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}

void Graph::shortestPath(int src)
{

    set< pair<int, int> > setds;

    vector<int> dist(V, INF);

    setds.insert(make_pair(0, src));
    dist[src] = 0;


    while (!setds.empty())
    {

        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        int u = tmp.second;
        int v = tmp.first;

        list< pair<int, int> >::iterator i;
        cout << v << " " << setds.size() << " " <<u << endl;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int Vs = (*i).first;
            int weight = (*i).second;

            if (dist[Vs] > dist[u] + weight)
            {

                if (dist[Vs] != INF)
                    setds.erase(setds.find(make_pair(dist[Vs], Vs)));

                dist[Vs] = dist[u] + weight;
                setds.insert(make_pair(dist[Vs], Vs));
            }
        }
    }
    printf("Sommet Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

/*int main()
{
    int V = 5;
    Graph g(V);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 7);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 2);
    g.addEdge(1, 4, 1);
    g.addEdge(3, 4, 7);


    g.shortestPath(2);


    return 0;
}*/

int main()
{
    set < int > s;

    // inserting elements in random order .
    s.insert( 60 ) ;
    s.insert( 10 ) ;
    s.insert( 20 ) ;
    s.insert( 20 ) ;
    s.insert( 20 ) ;
    s.insert( 00 ) ;
    s.insert( 40 ) ;
    s.insert( 50 ) ;

    // printing set s
    //initialising the iterator, iterating to the beginning of the set.

    set<int >::iterator it ;
    cout << "The element of set s are : \n";
    for (it = s.begin() ; it != s.end() ; it++ )
    {
        cout << *it<<" ";
    }
    cout << endl;
    cout <<s.count(100)<< endl;
    cout<< "The size of set : \n " << s.size() <<endl ;
    return 0 ;
}

