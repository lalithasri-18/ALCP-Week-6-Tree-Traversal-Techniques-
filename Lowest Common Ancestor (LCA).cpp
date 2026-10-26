#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* create(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node* build() {
    int x;
    cout << "Enter root: ";
    cin >> x;

    if (x == -1) return NULL;

    Node* root = create(x);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* t = q.front();
        q.pop();

        cout << "Left of " << t->data << ": ";
        cin >> x;
        if (x != -1) {
            t->left = create(x);
            q.push(t->left);
        }

        cout << "Right of " << t->data << ": ";
        cin >> x;
        if (x != -1) {
            t->right = create(x);
            q.push(t->right);
        }
    }
    return root;
}

Node* lca(Node* root, int a, int b) {
    if (root == NULL)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    Node* left = lca(root->left, a, b);
    Node* right = lca(root->right, a, b);

    if (left != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;

    return right;
}

bool exists(Node* root, int x) {
    if (root == NULL) return false;

    if (root->data == x) return true;

    return exists(root->left, x) ||
           exists(root->right, x);
}

int main() {
    Node* root = build();
    int a, b;

    cout << "Enter two nodes: ";
    cin >> a >> b;

    if (!exists(root, a) || !exists(root, b)) {
        cout << "Node not found";
        return 0;
    }

    Node* ans = lca(root, a, b);

    cout << "LCA: " << ans->data;

    return 0;
}
