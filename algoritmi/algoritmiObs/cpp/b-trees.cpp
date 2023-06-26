#include <iostream>
#include <vector>

using namespace std;

class Node {
   public:
    Node *parent;
    Node *left;
    Node *right;
    int key;
    int value;

    Node(){};

    Node(int k, int val) {
        key = k;
        value = val;
    }

    Node *lookUp(int k) {
        Node *child;
        if (k == key) {
            return this;
        } else if (k < key) {
            child = left;
        } else {
            child = right;
        }
        if (child == NULL) {
            return NULL;
        } else {
            return (*child).lookUp(k);
        }
    }

    void insert(Node *n) {
        if ((*n).key == key) {
            value = (*n).value;
        } else if ((*n).key < key) {
            if (left != NULL) {
                (*left).insert(n);
            } else {
                (*n).parent = this;
                left = n;
            }
        } else {
            if (right != NULL) {
                (*right).insert(n);
            } else {
                (*n).parent = this;
                right = n;
            }
        }
    }

    Node *max() {
        if (right != NULL) {
            return (*right).max();
        } else {
            return this;
        }
    }
    Node *min() {
        if (left != NULL) {
            return (*left).max();
        } else {
            return this;
        }
    }
    Node *successor() {
        if (right != NULL) {
            return (*right).min();
        } else {
            Node *p = parent;
            Node *curr = this;

            while (curr == (*p).right && p != NULL) {
                curr = p;
                p = (*p).parent;
            }
            return p;
        }
    }
    Node *predecessor() {
        if (left != NULL) {
            return (*left).max();
        } else {
            Node *p = parent;
            Node *curr = this;

            while (curr == (*p).left && p != NULL) {
                curr = p;
                p = (*p).parent;
            }
            return p;
        }
    }

    void remove() {
        Node *p = parent;

        if (left != NULL && right != NULL) {
            Node *succ = successor();
            if ((*succ).right != NULL) {
                if ((*(*succ).parent).left == succ) {
                    (*(*succ).parent).left = (*succ).right;
                } else {
                    (*(*succ).parent).right = (*succ).right;
                }
            }
            if (this == (*parent).left) {
                (*parent).left = succ;
            } else {
                (*parent).right = succ;
            }

        } else {
            Node *child;
            if (left != NULL) {
                child = left;
            } else {
                child = right;
            }

            if ((*p).left == this) {
                (*p).left = child;
            } else {
                (*p).right = child;
            }
        }
    }
};

class RBNode : public Node {
   public:
    RBNode *parent;
    RBNode *left;
    RBNode *right;

    bool isRed = false;
    RBNode(int k, int val) : Node(k, val) {}

    void insert(RBNode *n) {
        if ((*n).key == key) {
            value = (*n).value;
        } else if ((*n).key < key) {
            if (left != NULL) {
                (*left).insert(n);
            } else {
                (*n).parent = this;
                left = n;
                balancedInsert(left);
            }
        } else {
            if (right != NULL) {
                (*right).insert(n);
            } else {
                (*n).parent = this;
                right = n;
                balancedInsert(right);
            }
        }
    }

    void balancedInsert(RBNode *n) {
        (*n).isRed = true;

        RBNode *p, *gp, *u;

        while (n != NULL) {
            p = (*n).parent;
            if (p != NULL) {
                gp = (*p).parent;
            } else {
                gp = NULL;
            }
            if (gp != NULL) {
                u = ((*gp).left = p) ? (*gp).right : (*gp).left;
            } else {
                u = NULL;
            }

            if (p == NULL) {
                (*n).isRed = false;
                n = NULL;
            } else if (!(*p).isRed) {
                n = NULL;
            } else if (u!= NULL && (*u).isRed) {
                (*p).isRed = false;
                (*u).isRed = false;
                (*gp).isRed = true;
                n = gp;
            } else {
                if (n == (*p).right && p == (*gp).left) {
                    (*p).rotateLeft();
                    n = p;
                } else if (n == (*p).left && p == (*gp).right) {
                    (*p).rotateRight();
                    n = p;
                } else {
                    if (n == (*p).left && p == (*gp).left) {
                        (*gp).rotateRight();
                    } else if (n == (*p).right && p == (*gp).right) {
                        (*gp).rotateLeft();
                    }

                    (*gp).isRed = true;
                    (*p).isRed = false;

                    n = NULL;
                }
            }
        }
    }

    bool rotateLeft() {
        if (right == NULL || parent == NULL) {
            return false;
        }

        RBNode *p = parent;
        RBNode *r = right;

        right = (*r).left;
        if ((*r).left != NULL) {
            (*(*r).left).parent = this;
        }
        (*r).left = this;
        parent = r;
        (*r).parent = p;
        if (p != NULL) {
            if (this == (*p).left) {
                (*p).left = r;
            } else {
                (*p).right = r;
            }
        }
        return true;
    }

    bool rotateRight() {
        if (left == NULL || parent == NULL) {
            return false;
        }

        RBNode *p = parent;
        RBNode *l = left;

        left = (*l).right;
        if ((*l).right != NULL) {
            (*(*l).right).parent = this;
        }
        (*l).right = this;
        parent = l;
        (*l).parent = p;
        if (p != NULL) {
            if (this == (*p).left) {
                (*p).left = l;
            } else {
                (*p).right = l;
            }
        }
        return true;
    }
};

class ABR {
   protected:
    ABR(){} 
   public:
    Node *root;

    ABR(Node *n) { root = n; }

    Node *lookUp(int key) { return (*root).lookUp(key); }
    void insert(Node *n) { (*root).insert(n); }
    Node *max() { return (*root).max(); }
    Node *min() { return (*root).min(); }
    Node *successor(Node *n) {
        if (n == NULL) {
            return n;
        } else {
            return (*n).successor();
        }
    }
    Node *predecessor(Node *n) {
        if (n == NULL) {
            return n;
        } else {
            return (*n).predecessor();
        }
    }
    void remove(Node *n) { (*n).remove(); }
};

class ABRB : public ABR {
   public:
    // black root
    // black leaves
    // red children are black
    // every path from root to leaves has the same number of black nodes
    RBNode *root;
    RBNode nil = RBNode(NULL, 0);

    ABRB(RBNode *n) {
        root = n;
    }

    void insert(RBNode *n) { (*root).insert(n); }
    void remove(RBNode *n) {}
};

int main(int argc, char const *argv[]) {
    int arr[] = {2, 1, 4, 3, 8, 12, 9, 15};
    ABRB tree = ABRB(new RBNode(6, -6));

    for (int i = 0; i < 9; i++) {
        tree.insert(new RBNode(arr[i], -1 * arr[i]));
    }

    // cout << (*(tree.lookUp(6))).value << endl;

    return 0;
}
