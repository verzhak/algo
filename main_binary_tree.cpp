
#include <iostream>

#include "binary_tree.hpp"

using namespace std;

int main()
{
	CBinaryTree<int> tree(10);

	tree.insert(CBinaryTree<int>(17));
	tree.insert(CBinaryTree<int>(8));
	tree.insert(CBinaryTree<int>(1));
	tree.insert(CBinaryTree<int>(-2));
	tree.insert(CBinaryTree<int>(111));
	tree.insert(CBinaryTree<int>(102));
	tree.insert(CBinaryTree<int>(115));

	cout << tree << endl;
	cout << max_path_length(tree) << endl;

	return 0;
}

