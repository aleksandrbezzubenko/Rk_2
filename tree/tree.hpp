#include <queue>
#include <stack>
using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

template<class T> class Tree;

template<class T>
class Node {
public:
	Node() { left=right=NULL; }
	Node(const T& el, Node *l=0, Node *r=0) {
		key=el; left=l; right=r;
	}
	T key;
	Node *left, *right;
};

template<class T>
class Tree {
public:
	Tree() { root = 0; }
	~Tree() { clear(); }
	void DeleteTree(Node* treeRoot)
	void clear() { clear(root); root = 0; }
	bool isEmpty() { return root == 0; }
	void inorder() { inorder(root); }
	void insert(const T& el);
	void deleteNode(Node<T> *& node);
	Node<T> *TreeMax(Node<T> *node);
	Node<T> *TreeMin(Node<T> *node);

protected:
	Node<T> *root;


};

template<class T>
void Tree<T>::DeleteTree(Node* treeRoot)
    {
        if (treeRoot != nullptr)
        {
            DeleteTree(treeRoot->left);
            DeleteTree(treeRoot->right);
            delete treeRoot;
        }
    }

template<class T>
void Tree<T>::clear() {
        if (root != nullptr)
            DeleteTree(root);
        if (TNULL != nullptr)
            delete TNULL;
        root = nullptr;
        TNULL = nullptr;
        size_ = 0;
}

template<class T>
void Tree<T>::insert(const T &el) {
	Node<T> *p = root, *prev = 0;
	while(p != 0) {
		prev = p;
		if(p->key < el)
			p=p->right;
		else
			p=p->left;
	}
	if(root == 0)
		root = new Node<T>(el);
	else if(prev->key<el)
		prev->right = new Node<T>(el);
	else
		prev->left = new Node<T>(el);
}

template<class T>
void Tree<T>::deleteNode(Node<T> *&node) {
	Node<T> *prev, *tmp=node;
	if(node->right == 0)
		node = node->left;
	else if(node->left == 0)
		node = node->right;
	else {
		tmp = node->left;
		prev = node;
		while(tmp->right != 0) {
			prev = tmp;
			tmp=tmp->right;
		}
		node->key = tmp->key;
		if(prev == node)
			prev->left = tmp->left;
		else prev->right = tmp->left;
	}
	delete tmp;
}
template<class T>
Node Tree<T>::*TreeMin(Node<T> *node) {
    Node<T>* it = node;
    while (it->Left->Left != nullptr) {
        it = it->Left;
    }
    return it;
}
template<class T>
Node Tree<T>::*TreeMax(Node<T> *node) {
    Node<T>* it = node;
    while (it->Right->Right != nullptr) {
         it = it->Right;
    }
    return it;
}

#endif // Binary_Search_Tree
