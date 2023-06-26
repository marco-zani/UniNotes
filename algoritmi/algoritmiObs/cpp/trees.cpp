#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* parent;
    Node* left;
    Node* right;
    Node(int val) {
        value = val;
        parent = NULL;
        right = NULL;
        left = NULL;
    }
    void insert(Node* n) {
        if ((*n).value <= value) {
            if (left != NULL) {
                (*left).insert(n);
            } else {
                left = n;
            }
        } else {
            if (right != NULL) {
                (*right).insert(n);
            } else {
                right = n;
            }
        }
    }
    void dfs_pre_order() {
        cout << value << " ";
        if (left != NULL) {
            (left)->dfs_pre_order();
        }
        if (right != NULL) {
            (right)->dfs_pre_order();
        }
    }
    void dfs_in_order() {
        if (left != NULL) {
            (left)->dfs_in_order();
        }
        cout << value << " ";
        if (right != NULL) {
            (right)->dfs_in_order();
        }
    }
    void dfs_post_order() {
        if (left != NULL) {
            (left)->dfs_post_order();
        }
        if (right != NULL) {
            (right)->dfs_post_order();
        }
        cout << value << " ";
    }
    void bfs() {
        vector<Node*> queue = vector<Node*>();
        queue.push_back(this);

        while (queue.size() > 0) {
            if ((*queue[0]).left != NULL) {
                queue.push_back((*queue[0]).left);
            }
            if ((*queue[0]).right != NULL) {
                queue.push_back((*queue[0]).right);
            }
            cout << (*queue[0]).value << " ";
            queue.erase(queue.begin());
        }

        cout << endl;
    }
};

struct Tree {
    Node* root;
    Tree() { root = NULL; }
    void insert(Node* n) {
        if (root != NULL) {
            (*root).insert(n);
        } else {
            root = n;
        }
    }
    void dfs_pre_order() {
        if (root != NULL) {
            (*root).dfs_pre_order();
            cout << endl;
        }
    }
    void dfs_in_order() {
        if (root != NULL) {
            (*root).dfs_in_order();
            cout << endl;
        }
    }
    void dfs_post_order() {
        if (root != NULL) {
            (*root).dfs_post_order();
            cout << endl;
        }
    }
    void bfs() { (*root).bfs(); }
};

int main(int argc, char const* argv[]) {
    Tree t = Tree();

    int arr[] = {5, 3, 2, 4, 7, 6, 8};

    //      5
    //  3       7
    // 2   4   6    8

    for (int el : arr) {
        Node* n = new Node(el);
        t.insert(n);
    }

    t.bfs();

    return 0;
}
