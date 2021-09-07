#include <iostream>

struct Node {
    char data;
    Node *left;
    Node *right;
};

void Prefix(Node *root) {
    if (root == NULL) return;
    std::cout << root->data << " ";
    Prefix(root->left);
    Prefix(root->right);
}

void Infix(Node *root) {
    if (root == NULL) return;
    Infix(root->left);
    std::cout << root->data << " ";
    Infix(root->right);
}

void Postfix(Node *root) {
    if (root == NULL) return;
    Postfix(root->left);
    Postfix(root->right);
    std::cout << root->data << " ";
}

Node *insertToTree(Node *root, char data) {
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    } else if (data <= root->data)
        root->left = insertToTree(root->left, data);
    else
        root->right = insertToTree(root->right, data);
    return root;
}

Node *searchKey(Node *root, char data) {
    if (root == NULL || root->data == data)
        return root;
    // Search value is greater than root
    if (root->data < data)
        return searchKey(root->right, data);
    // Search value is less than root
    return searchKey(root->left, data);
}

int main() {
    /*
                M
			   / \
			  B   Q
			 / \   \
			A   C   Z
      */


    Node *root = NULL;
    root = insertToTree(root, 'M');
    root = insertToTree(root, 'B');
    root = insertToTree(root, 'Q');
    root = insertToTree(root, 'Z');
    root = insertToTree(root, 'A');
    root = insertToTree(root, 'C');

    std::cout << "Prefix Traversal" << std::endl;
    Prefix(root);
    std::cout << "\n";
    std::cout << "Infix Traversal" << std::endl;
    Infix(root);
    std::cout << "\n";
    std::cout << "Postfix Traversal" << std::endl;
    Postfix(root);

    return 0;
}
