#include <iostream>
#include <string>
using namespace std;


struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c) : val(c), left(NULL), right(NULL) {}

};

void insert(TreeNode*& root, char c) {
    if (root == NULL) {
        root = new TreeNode(c);
    }
    else if (c < root->val) {
        insert(root->left, c);
    }
    else {
        insert(root->right, c);
    }
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->val;
        inorder(root->right);
    }
}

int main() {
    string sentence;
    cout << "Cumle giriniz: ";
    getline(cin, sentence);

   TreeNode* root = NULL;
for (int i = 0; i < sentence.length(); i++) {
    char c = sentence[i];
        if (isalpha(c)) {
            insert(root, tolower(c));
        }
    }

    cout << "Sirali harfler: ";
    inorder(root);
    cout << endl;

    return 0;
}

