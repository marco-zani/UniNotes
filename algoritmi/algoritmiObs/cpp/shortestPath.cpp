#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Node {
   public:
    int name;
    vector<tuple<Node *, int>> adjacent;
    Node(int id) { name = id; }
};

class PrQueue {
   public:
    PrQueue() {
        elements = vector<Node *>();
        priority = vector<int>();
    }

    void addEl(Node *n, int pr) {
        int i = 0;
        while (i < priority.size() and pr > priority[i]) {
            i++;
        }
        if (i == priority.size()) {
            elements.push_back(n);
            priority.push_back(pr);
        } else {
            elements.insert(elements.begin() + i, n);
            priority.insert(priority.begin() + i, pr);
        }
    }

    Node *pop() {
        priority.erase(priority.begin());
        Node *out = elements[0];
        elements.erase(elements.begin());
        return out;
    }

    bool empty() { return elements.empty(); }

    void reduce(int index, int newPriority) {
        for (int i = 0; i < elements.size() - 1; i++) {
            if (elements[i]->name == index) {
                priority.erase(priority.begin() + index);
                Node *temp = elements[index];
                elements.erase(elements.begin() + index);

                addEl(temp, newPriority);
                break;
            }

            i++;
        }
    }

   private:
    vector<Node *> elements;
    vector<int> priority;
};

vector<int> dijkstra(Node *root, int graphSize) {
    vector<int> distance = vector<int>();
    vector<int> coverTree = vector<int>();
    vector<bool> v = vector<bool>();
    for (int i = 0; i < graphSize; i++) {
        coverTree.push_back(-1);
        distance.push_back(__INT_MAX__);
        v.push_back(false);
    }
    distance[root->name] = 0;
    v[root->name] = true;

    PrQueue next = PrQueue();
    next.addEl(root, 0);

    while (!next.empty()) {
        Node *curr = next.pop();
        v[curr->name] = false;

        for (tuple<Node *, int> adj : curr->adjacent) {
            int adjIndex = get<0>(adj)->name;
            int adjDistance = get<1>(adj);
            int newDistance = distance[curr->name] + adjDistance;
            if (distance[adjIndex] > newDistance) {
                if (!v[adjIndex]) {
                    next.addEl(get<0>(adj), newDistance);
                    v[adjIndex] = true;
                } else {
                    next.reduce(adjIndex, newDistance);
                }
                coverTree[adjIndex] = curr->name;
                distance[adjIndex] = newDistance;
            }
        }
    }

    return distance;
}

vector<int> bellman(Node *root, int graphSize) {
    vector<Node *> queue = vector<Node *>();
    vector<int> distances = vector<int>();
    vector<bool> alreadyProcessing = vector<bool>();
    vector<int> extractCount = vector<int>();

    for (int i = 0; i < graphSize; i++) {
        distances.push_back(__INT_MAX__);
        alreadyProcessing.push_back(false);
        extractCount.push_back(0);
    }

    distances[root->name] = 0;

    queue.push_back(root);
    alreadyProcessing[root->name] = true;
    Node *curr;

    while(!queue.empty()) {
        curr = queue[0];
        extractCount[curr->name]++;
        if(extractCount[curr->name]==graphSize){
            break;
        }
        alreadyProcessing[curr->name] = false;
        queue.erase(queue.begin());

        for (tuple<Node *, int> adj : curr->adjacent) {
            Node *el = get<0>(adj);
            int distance = get<1>(adj);
            int newDistance = distances[curr->name] + distance;
            if (distances[el->name] > newDistance) {
                if (!alreadyProcessing[el->name]) {
                    queue.push_back(el);
                    alreadyProcessing[el->name] = true;
                }
                distances[el->name] = newDistance;
            }
        }
    }

    if (!queue.empty()) {
        cout << "negative cycle present" << endl;
    }

    return distances;
}

int main(int argc, char const *argv[]) {
    Node *nodeA = new Node(0); 
    Node *nodeB = new Node(1); 
    Node *nodeC = new Node(2); 
    Node *nodeD = new Node(3); 
    Node *nodeE = new Node(4); 
    Node *nodeF = new Node(5); 

    nodeA->adjacent.push_back(make_tuple(nodeB, 1));
    nodeA->adjacent.push_back(make_tuple(nodeC, 2));

    nodeB->adjacent.push_back(make_tuple(nodeD, 5));
    nodeB->adjacent.push_back(make_tuple(nodeE, 2));

    nodeC->adjacent.push_back(make_tuple(nodeB, 1));
    nodeC->adjacent.push_back(make_tuple(nodeD, 3));

    nodeD->adjacent.push_back(make_tuple(nodeF, 1));

    nodeE->adjacent.push_back(make_tuple(nodeD, 1));
    nodeE->adjacent.push_back(make_tuple(nodeF, 3));


    vector<int> out = dijkstra(nodeA, 6);

    for (int el : out) {
        cout << el << " ";
    }
    cout << endl;

    nodeA = new Node(0);
    nodeB = new Node(1);
    nodeC = new Node(2);
    nodeD = new Node(3);
    nodeE = new Node(4);
    nodeF = new Node(5);

    nodeA->adjacent.push_back(make_tuple(nodeB, -1));
    nodeA->adjacent.push_back(make_tuple(nodeC, 2));

    nodeB->adjacent.push_back(make_tuple(nodeC, -1));
    nodeB->adjacent.push_back(make_tuple(nodeE, 2));

    nodeC->adjacent.push_back(make_tuple(nodeA, -1));
    nodeC->adjacent.push_back(make_tuple(nodeD, 3));

    nodeD->adjacent.push_back(make_tuple(nodeF, 1));

    nodeE->adjacent.push_back(make_tuple(nodeD, 1));
    nodeE->adjacent.push_back(make_tuple(nodeF, 3));

    out = bellman(nodeA, 6);

    for (int el : out) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}
