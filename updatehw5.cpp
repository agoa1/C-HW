#include <iostream>

using namespace std;

struct Node {
	int value;
	Node *left;
	Node *right;

	Node(int val) {
		this->value = val;
	}

	Node(int val, Node *left, Node *right) {
		this->value = val;
		this->left = left;
		this->right = right;
	}
};

void DFS_PreOrder_traversal_recursive(const Node *entry) {
  if (entry == nullptr) return;
  
  cout << entry->value << " ";
  
  DFS_PreOrder_traversal_recursive(entry->left);
  DFS_PreOrder_traversal_recursive(entry->right);
}

Node *generateBinaryTree() {
	Node *root = new Node(2);
	
	root->right = new Node(5, nullptr, new Node(9,  new Node(4), nullptr));
	root->left = new Node(7, new Node(2), new Node(6, new Node(5), new Node(11)));
	
	return root;
}

int main() {
  Node *root = generateBinaryTree();
  cout << "These are the steps in my tree: ";
  DFS_PreOrder_traversal_recursive(root);
  cout << endl;
}