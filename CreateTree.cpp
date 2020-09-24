//
// Created by xyh on 2020/9/22.
//

#include "BinaryTree.h"

template<typename T>
BinaryTree<T>* BinaryTree<T>::Create_BinaryTree() {
	BinaryTree *p = new BinaryTree;
	T val;
	p->isFirst = true;
	std::cin >> val;
	if (val == '#' or val == -1) {                                   //“#”和"-1"是结束标志
		p = nullptr;
	} else {
		p->data = val;                                               //对当前结点初始化
		p->lchild = Create_BinaryTree();                            //递归构造左子树
		p->rchild = Create_BinaryTree();                            //递归构造右子树
	}
	return p;
}

template class BinaryTree<int>;


