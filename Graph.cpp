#include "Graph.h"
Graph::Graph()
{
    this->load();
    FileEngine engine;
    GraphTraversal traverse;
    GraphMutator Mutator;
    ShortestPath Path;
    ConsoleGraph consoleG;
    this->Traversal = traverse;
    this->DataStorage = engine;
    this->Mutator = Mutator;
    this->ShortPath = Path;
    this->ConsoleG = consoleG;
    /*
    vector<pair<string, double>>v = {{"Alex", 35.5}, {"Minia", 80}, {"Assuit", 60.30}};
    this->adjacencyList["Cairo"] = v;
    vector<pair<string, double>>vv = {{"Cairo", 60.14}, {"Minia", 20}, {"AInSHames", 29.7}};
    this->adjacencyList["Assuit"] = vv;
    */
}
bool Graph::save(){
    DataStorage.save(this->adjacencyList);
    return true;
}
bool Graph::load(){
    DataStorage.load(this->adjacencyList);
    return true;
}
vector<string> Graph::BFS(string start){

    return this->Traversal.BFS(start ,this->adjacencyList);
}
vector<string> Graph::DFS(string start){
    return this->Traversal.DFS(start ,this->adjacencyList);
}

bool Graph::AddVertex(string vertex) {
    return this->Mutator.AddVertex(vertex, this->adjacencyList);
}

bool Graph::AddEdge(string source, string destination) {
    return this->Mutator.AddEdge(source, destination, this->adjacencyList);
}

bool Graph::DelVertex(string vertex) {
    return this->Mutator.DelVertex(vertex, this->adjacencyList);
}

bool Graph::DelEdge(string source, string destination) {
    return this->Mutator.DelEdge(source, destination, this->adjacencyList);
}
bool Graph::DelGraph(){
    this->adjacencyList.clear();
}
pair<vector<string>, double> Graph::Dijkstra(){
    return this->ShortPath.Dijkstra(this->adjacencyList);
}
void Graph::Print(){
    ConsoleG.Print(this->adjacencyList);
}
Graph::~Graph()
{
    this->save();
    //cout<<"KillProcess"<<endl;
}
