#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

// Fibonacci Heap implementation for efficient priority queue operations
struct FibNode {
    int key, value;
    int degree;
    FibNode* parent;
    FibNode* child;
    FibNode* left, * right;

    FibNode(int k, int v) : key(k), value(v), degree(0), parent(nullptr), child(nullptr), left(this), right(this) {}
};

struct FibHeap {
    FibNode* minNode;
    int size;
    int maxDegree;

    FibHeap(int n) : minNode(nullptr), size(0), maxDegree(static_cast<int>(log2(n)) + 1) {}

    void insert(int key, int value) {
        FibNode* newNode = new FibNode(key, value);
        if (!minNode) {
            minNode = newNode;
        } else {
            FibNode* start = minNode->right;
            minNode->right = newNode;
            newNode->right = start;
            start->left = newNode;
            newNode->left = minNode;
            if (key < minNode->key)
                minNode = newNode;
        }
        size++;
    }

    FibNode* extractMin() {
        FibNode* z = minNode;
        if (z) {
            FibNode* x = z->child;
            if (x) {
                FibNode* p = x;
                do {
                    p->parent = nullptr;
                    p = p->right;
                } while (p != x);
            }
            FibNode* start = minNode->right;
            minNode->right->left = minNode->left;
            minNode->left->right = start;
            minNode = start == start->right ? nullptr : start;
            size--;
        }
        return z;
    }

    void consolidate() {
        vector<FibNode*> roots(maxDegree, nullptr);
        FibNode* start = minNode;
        FibNode* p = start;
        do {
            FibNode* x = p;
            int d = x->degree;
            while (roots[d]) {
                FibNode* y = roots[d];
                if (x->key > y->key) {
                    x->left->right = x->right;
                    x->right->left = x->left;
                    y->child->right = y->child->right->left = y->child;
                    x->right = x->left = x;
                    y->child->right = y->child->left = x;
                    x->parent = y;
                    y->child = x;
                    y->degree++;
                    x = y;
                } else {
                    y->left->right = y->right;
                    y->right->left = y->left;
                    x->child->right = x->child->right->left = x->child;
                    y->right = y->left = y;
                    x->child->right = x->child->left = y;
                    y->parent = x;
                    x->child = y;
                    x->degree++;
                }
                roots[d] = nullptr;
                d++;
            }
            roots[d] = x;
            p = p->right;
        } while (p != start);
        minNode = nullptr;
        for (FibNode* x : roots) { 
            if (x) {
                if (!minNode)
                    minNode = x;
                else if (x->key < minNode->key)
                    minNode = x;
            }
        }
    }

    bool empty() const {
        return size == 0;
    }
};

int spfa(const vector<vector<pair<int, int>>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, __INT_MAX__);
    vector<bool> inQueue(n, false);
    FibHeap pq(n);

    dist[start] = 0;
    pq.insert(0, start);
    inQueue[start] = true;

    while (!pq.empty()) {
        FibNode* node = pq.extractMin();
        int u = node->value;         
        delete node;
        inQueue[u] = false;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                if (!inQueue[v]) {
                    pq.insert(dist[v], v);
                    inQueue[v] = true;
                } else {
                    // Decrease key operation
                    pq.consolidate();
                }
            }
        }
    }

    return dist[end];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        vector<vector<pair<int, int>>> graph(N);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int weight = abs(j - i) * max(A[i], A[j]);
                graph[i].push_back(make_pair(j, weight));
                graph[j].push_back(make_pair(i, weight));
            }
        }

        int distance = spfa(graph, 0, N - 1);
        cout << distance << endl;
    }

    return 0;
}