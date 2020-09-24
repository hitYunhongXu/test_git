//
// Created by xyh on 2020/9/22.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#include <iostream>
#include <stack>
#include <queue>

template<typename T>
class BinaryTree {
	friend int Isomorphic(BinaryTree<int> *, BinaryTree<int> *);
	friend BinaryTree<int>* Insert(BinaryTree<int>* ptr, int x);
	friend BinaryTree<int>* Delete(BinaryTree<int>* ptr, int x);
	friend BinaryTree<int>* findMin(BinaryTree<int>* ptr);
	friend int getHeight(BinaryTree<int> *ptr);
	friend BinaryTree<int>* singleLeftRotation (BinaryTree<int> * A);
	friend BinaryTree<int>* singleRightRotation (BinaryTree<int> *A);
	friend BinaryTree<int>* doubleRightLeftRotation(BinaryTree<int>* A);
	friend BinaryTree<int>* doubleLeftRightRotation(BinaryTree<int>* A);
	friend BinaryTree<int>* insertOfAVL(BinaryTree<int> *ptr, int x);
	friend int getNumberOfNodes(BinaryTree<int>* ptr);
	friend bool check(BinaryTree<int>* ptr, int val);

public:
	//创建二叉树的函数
	BinaryTree<T> *Create_BinaryTree();

	//递归实现遍历
	void preOrder(BinaryTree<T> *ptr);
	void inOrder(BinaryTree<T> *ptr);
	void postOrder(BinaryTree<T> *ptr);

	//利用堆栈实现的遍历（非递归）
	void stackPreOrder(BinaryTree<T> *ptr);
	void stackInOrder(BinaryTree<T> *ptr);
	void stackPostOrder(BinaryTree<T> *ptr);

	//利用pair实现先序 中序 后序三者写法的大致统一
	void easyPreOrder(BinaryTree<T> *ptr);
	void easyInOrder(BinaryTree<T> *ptr);
	void easyPostOrder(BinaryTree<T> *ptr);

	//层次遍历
	void levelTraversal(BinaryTree<T> *ptr);


private:
	T data = 0;
	BinaryTree<T> *lchild = nullptr;
	BinaryTree<T> *rchild = nullptr;
	bool isFirst = false;
	int height = 0;
};

int Isomorphic(BinaryTree<int> *ptr1, BinaryTree<int> *ptr2);
BinaryTree<int>* Insert(BinaryTree<int>* ptr, int x);
BinaryTree<int>* Delete(BinaryTree<int>* ptr, int x);
BinaryTree<int>* findMin(BinaryTree<int>* ptr);
void coutTraversal(BinaryTree<int> *ptr);
int getHeight(BinaryTree<int> *ptr);
BinaryTree<int>* singleLeftRotation (BinaryTree<int> * A);
BinaryTree<int>* singleRightRotation (BinaryTree<int> *A);
BinaryTree<int>* doubleRightLeftRotation(BinaryTree<int>* A);
BinaryTree<int>* doubleLeftRightRotation(BinaryTree<int>* A);
BinaryTree<int>* insertOfAVL(BinaryTree<int> *ptr, int x);
BinaryTree<int>* buildAVL();
BinaryTree<int>* makeSearchTree();
int getNumberOfNodes(BinaryTree<int>* ptr);
bool whetherTwoSearchTreeSame(BinaryTree<int>* tree1);
bool check(BinaryTree<int>* ptr, int val);


#endif //BINARYTREE_BINARYTREE_H
