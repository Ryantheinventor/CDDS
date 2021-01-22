#pragma once
#include <vector>
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
			return left != NULL;
		}
		bool hasRight()
		{
			return right != NULL;
		}

		vertex() 
		{
			left = NULL;
			right = NULL;
		}
	};

	tBinaryTree();
	tBinaryTree(const tBinaryTree &other);//copy-con
	tBinaryTree &operator=(const tBinaryTree &rhs);//copy-assign
	~tBinaryTree();

	void insert(const T &value);
	bool search(const T &value, vertex &found);
	void clear();

private:
	std::vector<vertex *> vertices;

	vertex *root;

	void rVertexDel(vertex &del);
	void rCopy(vertex &cur);

};


template<typename T>
tBinaryTree<T>::tBinaryTree()
{
	root = NULL;
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
	rVertexDel(*root);
	delete root;
}

template<typename T>
void tBinaryTree<T>::clear() 
{
	rVertexDel(*root);
	root = NULL;
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
	if (root == NULL) 
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
bool tBinaryTree<T>::search(const T &value, vertex &found) 
{
	vertex *cur = root;
	while (cur->hasLeft() || cur->hasRight()) 
	{

		if (cur->data == value) 
		{
			found = *cur;
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
				return false;
			}
		}
	}
	if (cur->data == value)
	{
		found = *cur;
		return true;
	}
	return false;
}