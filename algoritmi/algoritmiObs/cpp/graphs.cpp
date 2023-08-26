#include <iostream>
#include <vector>

using namespace std;

class Node {
   public:
    int name;
    vector<Node *> adjacent;
    Node(int id) { name = id; }
};

class Edge{
    public: 
     int capacity;
     Node * source;
     Node * destination;
     Edge(Node * src, Node * dst){
        source = src;
        destination = dst;
        capacity = 1;
     }
     Edge(Node * src, Node * dst, int w){
        source = src;
        destination = dst;
        capacity = w;
     }
};

class Graph {
   public:
    Graph() {}
    vector<Node *> v;
    int size = 0;
    vector<Node *> adj(Node *n) { return (*n).adjacent; }
    void insertNode(Node *n) {
        v.push_back(n);
        size++;
    }
    void insertEdge(Node *src, Node *dst) {
        insertOrientedEdge(src, dst);
        insertOrientedEdge(dst, src);
    }
    void insertOrientedEdge(Node *src, Node *dst) {
        (*src).adjacent.push_back(dst);
    }
    void deleteNode(Node *n) {
        for (int i = 0; i < v.size(); i++) {
            if (n == v[i]) {
                for (Node *adj : (*v[i]).adjacent) {
                    deleteOrientedEdge(adj, n);
                }
                v.erase(v.begin() + i);
            }
        }
    }
    void deleteEdge(Node *src, Node *dst) {
        deleteOrientedEdge(src, dst);
        deleteOrientedEdge(dst, src);
    }
    void deleteOrientedEdge(Node *src, Node *dst) {
        for (int i = 0; i < (*src).adjacent.size(); i++) {
            if ((*src).adjacent[i] == dst) {
                (*src).adjacent.erase((*src).adjacent.begin() + i);
            }
        }
    }
    void printGraph() {
        for (Node *n : v) {
            cout << (*n).name << endl;
            if ((*n).adjacent.size() > 0) {
                for (Node *adj : (*n).adjacent) {
                    cout << "  --> " << (*adj).name << endl;
                }
            }
        }
    }
    void bfs(Node *n) {
        int distance[size];
        for (int i = 0; i < size; i++) {
            distance[i] = -1;
        }
        distance[(*n).name] = 0;
        Node *curr;
        vector<Node *> queue;
        queue.push_back(n);

        while (queue.size() > 0) {
            curr = queue[0];
            queue.erase(queue.begin());

            for (Node *adj : (*curr).adjacent) {
                if (distance[(*adj).name] == -1) {
                    queue.push_back(adj);
                    distance[(*adj).name] = distance[(*curr).name] + 1;
                }
            }
        }

        for (int i = 0; i < size; i++) {
            cout << i << " - distance: " << distance[i] << " from " << (*n).name
                 << endl;
        }
    }
    void dfs(Node *n) {
        bool visited[size];
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }
        prvt_DFS(n, visited);
    }
    vector<int> cc() {
        vector<int> cid;
        int currID = 0;
        for (int i = 0; i < size; i++) {
            cid.push_back(0);
        }
        for (int i = 0; i < size; i++) {
            if (cid[i] == 0) {
                currID++;
                cid = prvt_CC(v[i], cid, currID);
            }
        }
        return cid;
    }
    bool hasCycle() {
        bool visited[size];
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                if (prvt_HasCycle(v[i], NULL, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<Edge> coverTree(Node * n){
        bool visited[size];
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }
        vector<Edge> out = vector<Edge>();
        prvt_CoverTree(n, NULL, visited, out);
        return out;
    }

   private:
    void prvt_DFS(Node *n, bool visited[]) {
        cout << "Node " << (*n).name << endl;
        visited[(*n).name] = true;
        for (Node *adj : (*n).adjacent) {
            if (!visited[(*adj).name]) {
                prvt_DFS(adj, visited);
            }
        }
    }
    vector<int> prvt_CC(Node *n, vector<int> cid, int currID) {
        cid[(*n).name] = currID;
        for (Node *adj : (*n).adjacent) {
            if (cid[(*adj).name] == 0) {
                cid = prvt_CC(adj, cid, currID);
            }
        }
        return cid;
    }
    bool prvt_HasCycle(Node *n, Node *p, bool visited[]) {
        visited[(*n).name] = true;
        for (Node *adj : (*n).adjacent) {
            if (p != adj) {
                if (visited[(*adj).name]) {
                    return true;
                } else if (prvt_HasCycle(adj, n, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    void prvt_CoverTree(Node * n, Node * p, bool visited[], vector<Edge> &out){
        visited[(*n).name] = true;
        out.push_back(Edge(p,n));
        for(Node * adj:(*n).adjacent){
            if(adj!=p && !visited[(*adj).name]){
                prvt_CoverTree(adj,n,visited,out);
            }
        }
    }
};

/* 
int main(int argc, char const *argv[]) {
    Graph g = Graph();

    Node *n0 = new Node(0);
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);

    g.insertNode(n0);
    g.insertNode(n1);
    g.insertNode(n2);
    g.insertNode(n3);
    g.insertNode(n4);
    g.insertNode(n5);
    g.insertNode(n6);

    g.insertEdge(n0, n2);
    g.insertEdge(n1, n2);
    g.insertEdge(n1, n2);
    g.insertEdge(n1, n3);
    g.insertEdge(n2, n4);
    g.insertEdge(n3, n4);
    g.insertEdge(n3, n5);
    g.insertEdge(n5, n6);

    for(Edge e :g.coverTree(n0)){
        if(e.source == NULL){
            cout << "nil";
        } else {
            cout << (*e.source).name;
        }
        cout << " ---- " << (*e.destination).name << endl;
    }

    return 0;
}
 */