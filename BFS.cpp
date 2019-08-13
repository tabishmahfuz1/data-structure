#include <iostream>
#include <list>
#include <memory>
   
class Graph
{
    int _V;    
    bool _directed;
    std::unique_ptr< std::list<int> > adj;  
      
public:
    Graph(int V, bool directed);
    void AddEdge(int v, int w); 
    void BreadthFirstSearch(int s); 
};
   
Graph::Graph(int V, bool directed) : adj(new std::list<int>[V])
{
    _V = V;
    _directed = directed;       
}   
   
void Graph::AddEdge(int v, int w)
{
    std::list<int>* adjacency = adj.get();
    adjacency[v].push_back(w);
   
    if (!_directed)
    {
        adjacency[w].push_back(v);
    }
}
   
void Graph::BreadthFirstSearch(int s)
{
    bool *visited = new bool[_V];
    for(int i = 0; i < _V; i++){
		// std::cout<<i<<std::endl;
        visited[i] = false;
	}
    // Create a queue for BFS
    std::list<int> queue;
   
    visited[s] = true;
    queue.push_back(s);
	
   
    // 'i' will be used to get all adjacent vertices of a vertex
    std::list<int>::iterator i;
   
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
		s = queue.front();
		std::cout << s << "->";
		queue.pop_front();
        
   
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = (adj.get())[s].begin(); i != (adj.get())[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
   
int main()
{
    Graph g(7, false);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(0, 3);
    g.AddEdge(1, 0);
    g.AddEdge(1, 5);
    g.AddEdge(2, 5);
    g.AddEdge(3, 0);
    g.AddEdge(3, 4);
    g.AddEdge(4, 6);
    g.AddEdge(5, 1);
    g.AddEdge(6, 5);
   
    std::cout << "Breadth First Traversal from vertex 2:\n";
    g.BreadthFirstSearch(2);
	std::cout<<std::endl<<67<<"hahah";
    return 0;
}