#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Node;

class Edge {
   public:
    Node *destNode;
    int capacity;
    bool visited;
    Edge(Node *node, int weight) {
        destNode = node;
        capacity = weight;
        visited = false;
    }
};

class Node {
    char name;

   public:
    vector<Edge *> adjacents;
    Node(char name) { this->name = name; }
    void addEdge(Node *n, int weight) {
        adjacents.push_back(new Edge(n, weight));
    }
    Edge *existEdge(Node *destination) {
        for (Edge *el : adjacents) {
            if (el->destNode == destination) {
                return el;
            }
        }
        return NULL;
    }
    void reduceEdge(Node *n, int weight) {
        for (Edge *edge : adjacents) {
            if (edge->destNode == n) {
                edge->capacity -= weight;
                Edge *opposite = edge->destNode->existEdge(this);
                if (opposite != NULL) {
                    opposite->capacity += weight;
                } else {
                    edge->destNode->addEdge(this, weight);
                }
                break;
            }
        }
    }
};

int searchPath(Node *current, Node *destination, int min) {
    for (Edge *adj : current->adjacents) {
        if (!adj->visited and adj->capacity != 0) {
            if (adj->capacity < min) {
                min = adj->capacity;
            }

            if (adj->destNode == destination) {
                current->reduceEdge(adj->destNode, min);

            } else {
                adj->visited = true;
                int out = searchPath(adj->destNode, destination, min);
                adj->visited = false;
                if (out != -1) {
                    min = out;
                    current->reduceEdge(adj->destNode, min);
                }
            }
            return min;
        }
    }
    return -1;
}

int maxFlux(Node *source, Node *pit) {
    int total = 0;
    int out = 0;
    do {
        out = searchPath(source, pit, __INT_MAX__);
        if (out != -1) {
            total += out;
        }
    } while (out != -1);
    return total;
}

int firstTest() {
    Node *nodeA = new Node('A');
    Node *nodeB = new Node('B');
    Node *nodeC = new Node('C');
    Node *nodeD = new Node('D');
    Node *nodeE = new Node('E');
    Node *nodeF = new Node('F');

    nodeA->addEdge(nodeB, 2);
    nodeA->addEdge(nodeC, 8);

    nodeB->addEdge(nodeD, 7);
    nodeB->addEdge(nodeC, 2);
    nodeB->addEdge(nodeE, 3);

    nodeC->addEdge(nodeE, 6);

    nodeD->addEdge(nodeF, 3);
    nodeD->addEdge(nodeE, 2);

    nodeE->addEdge(nodeF, 4);

    return maxFlux(nodeA, nodeF);
}

int secondTest() {
    Node *nodeA = new Node('A');
    Node *nodeB = new Node('B');
    Node *nodeC = new Node('C');
    Node *nodeD = new Node('D');
    Node *nodeE = new Node('E');
    Node *nodeF = new Node('F');
    Node *nodeG = new Node('G');
    Node *nodeH = new Node('H');
    Node *nodeI = new Node('I');
    Node *nodeJ = new Node('J');
    Node *nodeK = new Node('K');

    nodeA->addEdge(nodeB, 8);
    nodeA->addEdge(nodeC, 4);
    nodeA->addEdge(nodeD, 7);

    nodeB->addEdge(nodeF, 3);
    nodeB->addEdge(nodeG, 2);
    nodeB->addEdge(nodeE, 4);

    nodeC->addEdge(nodeD, 2);
    nodeC->addEdge(nodeE, 3);
    nodeC->addEdge(nodeH, 5);

    nodeD->addEdge(nodeC, 3);
    nodeD->addEdge(nodeH, 4);

    nodeE->addEdge(nodeC, 2);
    nodeE->addEdge(nodeG, 1);

    nodeF->addEdge(nodeG, 4);
    nodeF->addEdge(nodeI, 7);

    nodeG->addEdge(nodeF, 2);
    nodeG->addEdge(nodeJ, 5);

    nodeH->addEdge(nodeG, 5);
    nodeH->addEdge(nodeJ, 3);
    nodeH->addEdge(nodeK, 5);

    nodeI->addEdge(nodeK, 5);
    nodeI->addEdge(nodeJ, 2);

    nodeJ->addEdge(nodeG, 2);
    nodeJ->addEdge(nodeK, 9);

    return maxFlux(nodeA, nodeK);
}

int main(int argc, char const *argv[]) {
    cout << secondTest() << endl;
    return 0;
}
