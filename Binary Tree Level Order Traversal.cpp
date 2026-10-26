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

void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            Node* t = q.front();
            q.pop();

            cout << t->data << " ";

            if (t->left != NULL)
                q.push(t->left);

            if (t->right != NULL)
                q.push(t->right);
        }
        cout << endl;
    }
}

int main() {
    Node* root = build();

    cout << "\nLevel Order:\n";
    levelOrder(root);

    return 0;
}
