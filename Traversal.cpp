//
// Created by xyh on 2020/9/22.
//

#include "BinaryTree.h"

template <typename T>
void BinaryTree<T>::preOrder(BinaryTree<T> *ptr)
{
	if (ptr)
	{
		std::cout << ptr->data << "  ";
		preOrder(ptr->lchild);
		preOrder(ptr->rchild);
	}
}

template <typename T>
void BinaryTree<T>::inOrder(BinaryTree<T> *ptr)
{
	if (ptr)
	{
		inOrder(ptr->lchild);
		std::cout << ptr->data << "  ";
		inOrder(ptr->rchild);
	}
}

template<typename T>
void BinaryTree<T>::postOrder(BinaryTree<T> *ptr)
{
	if (ptr)
	{
		postOrder(ptr->lchild);
		postOrder(ptr->rchild);
		std::cout << ptr->data << "  ";
	}
}

template <typename T>
void BinaryTree<T>::stackPreOrder(BinaryTree<T> *ptr)
{
	std::stack<BinaryTree<T>*> s;
	while (ptr || !s.empty())
	{
		while (ptr)
		{
			std::cout << ptr->data << "  ";
			s.push(ptr);
			ptr = ptr->lchild;
		}
		if (!s.empty())
		{
			ptr = s.top();
			s.pop();
			ptr = ptr->rchild;
		}
	}
}

template <typename T>
void BinaryTree<T>::stackInOrder(BinaryTree<T> *ptr)
{
	std::stack<BinaryTree<T>*> s;
	while (ptr || !s.empty())
	{
		while (ptr)
		{
			s.push(ptr);
			ptr = ptr->lchild;
		}
		if (!s.empty())
		{
			ptr = s.top();
			s.pop();
			std::cout << ptr->data << "  ";
			ptr = ptr->rchild;
		}
	}
}

template <typename T>
void BinaryTree<T>::stackPostOrder(BinaryTree<T> *ptr)
{
	std::stack<BinaryTree<T>*> s;
	while (ptr || !s.empty()) {
		while (ptr) {
			s.push(ptr);
			ptr = ptr->lchild;
		}
		if (!s.empty()) {
			ptr = s.top();
			s.pop();
			//如果是第一次到达栈顶，转向右子树
			if (ptr->isFirst == true) {
				ptr->isFirst = false;
				s.push(ptr);
				ptr = ptr->rchild;
			}
				//如果是第二次（左子树遍历完弹第一次，右子树遍历完弹第二次）到达栈顶，则输出该节点，将ptr置为nullptr，以便再弹出上一个节点。
			else {
				std::cout << ptr->data << "  ";
				ptr = nullptr;
			}
		}
	}
}

template <typename T>
void BinaryTree<T>::easyPreOrder(BinaryTree<T> *ptr)
{
	std::stack<std::pair<BinaryTree<T>*, bool>> s;
	s.push(std::make_pair(ptr, false));
	bool visited;
	while (!s.empty())
	{
		ptr = s.top().first;
		visited = s.top().second;
		s.pop();
		if (ptr == nullptr) continue;
		if (visited)
		{
			std::cout << ptr->data << "  ";
		}
		else
		{
			s.push(std::make_pair(ptr->rchild, false));
			s.push(std::make_pair(ptr->rchild, false));
			s.push(std::make_pair(ptr, true));
		}
	}
}

template <typename T>
void BinaryTree<T>::easyInOrder(BinaryTree<T> *ptr)
{
	std::stack<std::pair<BinaryTree<T>*, bool>> s;
	s.push(std::make_pair(ptr, false));
	bool visited;
	while (!s.empty())
	{
		ptr = s.top().first;
		visited = s.top().second;
		s.pop();
		if (ptr == nullptr) continue;
		if (visited)
		{
			std::cout << ptr->data << "  ";
		}
		else
		{
			s.push(std::make_pair(ptr->rchild, false));
			s.push(std::make_pair(ptr, true));
			s.push(std::make_pair(ptr->rchild, false));
		}
	}
}

template <typename T>
void BinaryTree<T>::easyPostOrder(BinaryTree<T> *ptr)
{
	std::stack<std::pair<BinaryTree<T>*, bool>> s;
	s.push(std::make_pair(ptr, false));
	bool visited;
	while (!s.empty())
	{
		ptr = s.top().first;
		visited = s.top().second;
		s.pop();
		if (ptr == nullptr) continue;
		if (visited)
		{
			std::cout << ptr->data << "  ";
		}
		else
		{
			s.push(std::make_pair(ptr->rchild, false));
			s.push(std::make_pair(ptr->rchild, false));
			s.push(std::make_pair(ptr, true));
		}
	}
}

template <typename T>
void BinaryTree<T>::levelTraversal(BinaryTree<T> *ptr)
{
	std::queue<BinaryTree<T>*> q;
	q.push(ptr);
	while (!q.empty())
	{
		ptr = q.front();
		std::cout << ptr->data << "  ";
		q.pop();
		if (ptr->lchild)
			q.push(ptr->lchild);
		if (ptr->rchild)
			q.push(ptr->rchild);
	}
}

void coutTraversal(BinaryTree<int> *ptr)
{
	std::cout <<std::endl<< "利用递归实现";
	std::cout << std::endl << "先序遍历: ";
	ptr->preOrder(ptr);
	std::cout << std::endl << "中序遍历: ";
	ptr->inOrder(ptr);
	std::cout << std::endl << "后序遍历: ";
	ptr->postOrder(ptr);

	std::cout <<std::endl<<std::endl<<"利用栈实现" ;
	std::cout << std::endl << "先序遍历: ";
	ptr->stackPreOrder(ptr);
	std::cout << std::endl << "中序遍历: ";
	ptr->stackInOrder(ptr);
	std::cout << std::endl << "后序遍历: ";
	ptr->stackPostOrder(ptr);

	std::cout << std::endl<<std::endl<<"利用pair的简易实现";
	std::cout << std::endl << "先序遍历: ";
	ptr->easyPreOrder(ptr);
	std::cout << std::endl << "中序遍历: ";
	ptr->easyInOrder(ptr);
	std::cout << std::endl << "后序遍历: ";
	ptr->easyPostOrder(ptr);

	std::cout << std::endl<<std::endl<<"利用队列实现的层次遍历" <<std::endl;
	ptr->levelTraversal(ptr);
}

template class BinaryTree<int>;
