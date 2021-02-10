#pragma once
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
template<typename T>
class tBinaryTree 
{
public:
	struct vertex 
	{
		T data;

		vertex *left;
		vertex *right;

		bool hasLeft() 
		{
			return left != nullptr;
		}
		bool hasRight()
		{
			return right != nullptr;
		}

		vertex() 
		{
			left = nullptr;
			right = nullptr;
		}
	};

	tBinaryTree();
	tBinaryTree(const tBinaryTree &other);//copy-con
	tBinaryTree &operator=(const tBinaryTree &rhs);//copy-assign
	~tBinaryTree();

	void insert(const T &value);
	bool search(const T &value, vertex *&found);
	void clear();

	void printPreOrder();
	void printPostOrder();
	void printInOrder();

	void remove(vertex *target);

private:
	std::vector<vertex *> vertices;

	vertex *root;

	void rVertexDel(vertex &del);
	void rCopy(vertex &cur);

	void rPrintPreOrder(vertex &cur);
	void rPrintPostOrder(vertex &cur);
	void rPrintInOrder(vertex &cur);

};

#pragma region Constructors/Destructors
template<typename T>
tBinaryTree<T>::tBinaryTree()
{
	root = nullptr;
	vertices = std::vector<vertex *>();
}


template<typename T>
tBinaryTree<T>::tBinaryTree(const tBinaryTree &other)
{
	vertices = std::vector<vertex *>();
	rCopy(*other.root);
}

template <typename T>
tBinaryTree<T> &tBinaryTree<T>::operator=(const tBinaryTree &rhs)
{
	vertices = std::vector<vertex *>();
	rCopy(*rhs.root);
	return *this;
}

template<typename T>
tBinaryTree<T>::~tBinaryTree() 
{
	//remove all nodes
	if (root != nullptr) 
	{
		rVertexDel(*root);
		delete root;
	}
	
}
#pragma endregion

template<typename T>
void tBinaryTree<T>::clear() 
{
	if (root != nullptr)
	{
		rVertexDel(*root);
		delete root;
	}
	root = nullptr;
}

template<typename T>
void tBinaryTree<T>::rCopy(vertex &cur)
{
	insert(cur.data);
	if (cur.hasLeft())
	{
		rCopy(*cur.left);
	}
	if (cur.hasRight())
	{
		rCopy(*cur.right);
	}
}

template<typename T>
void tBinaryTree<T>::rVertexDel(vertex &del) 
{
	if (del.hasLeft())
	{
		rVertexDel(*del.left);
		delete del.left;
	}
	if (del.hasRight())
	{
		rVertexDel(*del.right);
		delete del.right;
	}
}

template<typename T>
void tBinaryTree<T>::insert(const T &value) 
{
	vertex *newVertex = new vertex();
	newVertex->data = value;
	if (root == nullptr)
	{
		root = newVertex;
		return;
	}

	vertex *cur = root;
	bool notSet = true;
	while (notSet) 
	{
		if (value < cur->data)
		{
			if (cur->hasLeft())
			{
				cur = cur->left;
			}
			else 
			{
				cur->left = newVertex;
				notSet = false;
			}
		}
		if (value > cur->data)
		{
			if (cur->hasRight())
			{
				cur = cur->right;
			}
			else
			{
				cur->right = newVertex;
				notSet = false;
			}
		}
		if(value == cur->data)
		{
			throw "Unsuported duplicate";
		}
	}
	vertices.push_back(newVertex);
}

template<typename T>
bool tBinaryTree<T>::search(const T &value, vertex *&found) 
{
	vertex *cur = root;
	while (cur->hasLeft() || cur->hasRight()) 
	{
		if (cur->data == value) 
		{
			found = cur;
			return true;
		}
		if (value < cur->data)
		{
			if (cur->hasLeft())
			{
				cur = cur->left;
			}
			else 
			{
				found = nullptr;
				return false;
			}
		}
		if (value > cur->data)
		{
			if (cur->hasRight())
			{
				cur = cur->right;
			}
			else
			{
				found = nullptr;
				return false;
			}
		}
	}
	if (cur->data == value)
	{
		found = cur;
		return true;
	}
	found = nullptr;
	return false;
}

template<typename T>
void tBinaryTree<T>::remove(vertex *target) 
{

	if (target == root) 
	{
		if (root->hasLeft() && root->hasRight()) 
		{
			root = target->right;
			rCopy(*target->left);
			rVertexDel(*target->left);
			delete target->left;
			delete target;
		}
		else if (root->hasLeft() && !root->hasRight()) 
		{
			root = root->left;
			delete target;
		}
		else if (!root->hasLeft() && root->hasRight()) 
		{
			root = root->right;
			delete target;
		}
		else 
		{
			root = nullptr;
			delete target;
		}
	}
	else 
	{
		vertex *preVert = root;
		while (true)
		{
			if (preVert->data < target->data && preVert->hasRight())
			{
				if (preVert->right == target)
				{
					preVert->right = nullptr;
					if (target->hasLeft())
					{
						rCopy(*target->left);
						rVertexDel(*target->left);
						delete target->left;
					}
					if (target->hasRight())
					{
						rCopy(*target->right);
						rVertexDel(*target->right);
						delete target->right;
					}
					delete target;
					break;
				}
				else
				{
					preVert = preVert->right;
				}
			}

			if (preVert->data > target->data && preVert->hasLeft())
			{
				if (preVert->left == target)
				{
					preVert->left = nullptr;
					if (target->hasLeft())
					{
						rCopy(*target->left);
						rVertexDel(*target->left);
						delete target->left;
					}
					if (target->hasRight())
					{
						rCopy(*target->right);
						rVertexDel(*target->right);
						delete target->right;
					}
					delete target;
					break;
				}
				else
				{
					preVert = preVert->left;
				}
			}
		}
	}
}

#pragma region Print Pre-order
template<typename T>
void tBinaryTree<T>::printPreOrder()
{
	rPrintPreOrder(*root);
	std::cout << "\n";
}

template<typename T>
void tBinaryTree<T>::rPrintPreOrder(vertex &cur)
{
	std::cout << cur.data << " ";
	if (cur.hasLeft())
	{
		rPrintPreOrder(*cur.left);
	}
	if (cur.hasRight())
	{
		rPrintPreOrder(*cur.right);
	}
}
#pragma endregion

#pragma region Print Post-order
template<typename T>
void tBinaryTree<T>::printPostOrder() 
{
	rPrintPostOrder(*root);
	std::cout << "\n";
}

template<typename T>
void tBinaryTree<T>::rPrintPostOrder(vertex &cur)
{
	if (cur.hasLeft())
	{
		rPrintPostOrder(*cur.left);
	}
	if (cur.hasRight())
	{
		rPrintPostOrder(*cur.right);
	}
	std::cout << cur.data << " ";
}
#pragma endregion

#pragma region Print In-order
template<typename T>
void tBinaryTree<T>::printInOrder() 
{
	rPrintInOrder(*root);
	std::cout << "\n";
}

template<typename T>
void tBinaryTree<T>::rPrintInOrder(vertex &cur)
{
	if (cur.hasLeft())
	{
		rPrintInOrder(*cur.left);
	}
	std::cout << cur.data << " ";
	if (cur.hasRight())
	{
		rPrintInOrder(*cur.right);
	}
}
#pragma endregion