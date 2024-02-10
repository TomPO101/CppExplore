struct Node
{
	int value;
	Node* left;
	Node* right;
	Node(int i = 0) : value(i), left(nullptr), right(nullptr) {}
};

auto left = &Node::left;
auto right = &Node::right;

template<typename T, typename... TP>
Node* traverse(T rootNode, TP... paths)
{
	// Because the type of paths is pointer-to-member of Node
	// We can use the ->* binary operator
	return (rootNode ->* ... ->* paths); // rootNode ->* paths1 ->* paths2 �
}

int main()
{
	Node* root = new Node{ 0 };
	root->left = new Node{ 1 };
	root->left->right = new Node{ 2 };

	Node* node = traverse(root, left, right);
}
