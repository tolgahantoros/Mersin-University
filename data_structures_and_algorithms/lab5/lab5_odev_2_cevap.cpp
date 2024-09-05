#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int data;
    double freq;
    string code;
    node *left, *right;
    node(int data, double freq) : data(data), freq(freq), left(NULL), right(NULL) {}
};

bool compare(node* a, node* b) {
    return a->freq > b->freq;
}

void assign_code(node* n, string code) {
    if (n != NULL) {
        n->code = code;
        assign_code(n->left, code + "0");
        assign_code(n->right, code + "1");
    }
}

void print_code(node* n) {
    if (n != NULL) {
        cout << n->data << " - " << n->code << endl;
        print_code(n->left);
        print_code(n->right);
    }
}

void shannon_fano(vector<node*>& nodes, int left, int right) {
    if (left < right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += nodes[i]->freq;
        }
        int mid = left;
        int abs_diff = sum - 2 * nodes[left]->freq;
        while (abs_diff >= 0 && mid < right) {
            mid++;
            abs_diff -= 2 * nodes[mid]->freq;
        }
        abs_diff = abs(abs_diff);
        if (mid > left + 1 && right > mid - 1) {
            if (abs_diff >= sum - 2 * (nodes[mid - 1]->freq + nodes[mid]->freq)) {
                mid--;
            }
        }
        for (int i = left; i <= right; i++) {
            if (i < mid) {
                nodes[i]->code += "0";
            } else {
                nodes[i]->code += "1";
            }
        }
        shannon_fano(nodes, left, mid - 1);
        shannon_fano(nodes, mid, right);
    }
}

int main() {
    vector<node*> nodes;
    nodes.push_back(new node(0, 0.05));
    nodes.push_back(new node(1, 0.15));
    nodes.push_back(new node(2, 0.10));
    nodes.push_back(new node(3, 0.20));
    nodes.push_back(new node(4, 0.30));
    nodes.push_back(new node(5, 0.05));
    nodes.push_back(new node(6, 0.15));
    sort(nodes.begin(), nodes.end(), compare);
    shannon_fano(nodes, 0, nodes.size() - 1);
    assign_code(nodes[0], "");
    print_code(nodes[0]);
    return 0;
}

