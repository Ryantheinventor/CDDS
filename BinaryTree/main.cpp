#include "tBinaryTree.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
int main() 
{
	tBinaryTree<int> bTree = tBinaryTree<int>();

	
	bTree.insert(3);
	bTree.insert(2);
	bTree.insert(5);
	bTree.insert(4);
	bTree.insert(8);
	bTree.insert(9);
	bTree.insert(1);
	bTree.insert(6);
	bTree.insert(7);
	bTree.insert(10);
	tBinaryTree<int>::vertex *found;
	for (int i = 0; i < 11; i++) 
	{
		if (bTree.search(i, found))
		{
			std::cout << "Found:" << found->data << "\n";
		}
		else 
		{
			std::cout << "Failed to find:" << i << "\n";
		}
	}
	
	/*tBinaryTree<int> bTree2 = bTree;
	tBinaryTree<int> bTree3;
	bTree3 = bTree;*/

	bTree.printInOrder();
	bTree.printPostOrder();
	bTree.printPreOrder();

	tBinaryTree<int>::vertex *found2;
	bTree.search(8, found2);
	bTree.remove(found2);
	bTree.printInOrder();

	tBinaryTree<int> clearTree = tBinaryTree<int>();
	clearTree.clear();


	return 0;
}