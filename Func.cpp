//
// Created by xyh on 2020/9/22.
//

#include "BinaryTree.h"

int Isomorphic(BinaryTree<int> *ptr1, BinaryTree<int> *ptr2)
{
	if ((ptr1 == nullptr) && (ptr2 == nullptr))
		return 1;

	if (((ptr1 == nullptr) &&(ptr2 != nullptr)) || ((ptr1 != nullptr) && (ptr2 == nullptr)))
		return 0;

	if (ptr1->data != ptr2->data)
		return 0;

	if ((ptr1->lchild == nullptr) && (ptr2->lchild == nullptr))
		return Isomorphic(ptr1->rchild, ptr2->rchild);

	if ((ptr1->rchild == nullptr) && (ptr2->rchild == nullptr))
		return Isomorphic(ptr1->lchild, ptr2->lchild);

	if ((ptr1->lchild != nullptr) && (ptr2->lchild != nullptr) && (ptr1->lchild->data == ptr2->lchild->data) )
		return (Isomorphic(ptr1->lchild,ptr2->lchild) && Isomorphic(ptr1->rchild,ptr2->rchild));

	else
		return (Isomorphic(ptr1->lchild, ptr2->rchild) && Isomorphic(ptr1->rchild, ptr2->lchild));
}
// 1 2 4 -1 -1 5 6 -1 -1 -1 3 7 8 -1 -1 -1 -1
// 1 3 7 -1 8 -1 -1 -1 2 5 6 -1 -1 -1 4 -1 -1

BinaryTree<int>* Insert(BinaryTree<int>* ptr, int x)
{
	if(!ptr)
	{
		ptr = new BinaryTree<int>;
		ptr->data = x;
		ptr->lchild = nullptr;
		ptr->rchild = nullptr;
	}
	else
	{
		if (x < ptr->data)
			ptr->lchild = Insert(ptr->lchild, x);
		else if (x > ptr->data)
			ptr->rchild = Insert(ptr->rchild,x);
	}
	return ptr;
}

BinaryTree<int> * Delete(BinaryTree<int>* ptr, int x)
{
	BinaryTree<int> *tmp;
	if (!ptr)
		std::cout << "fail to find the element";

	else
	{
		if (x < ptr->data)
			ptr->lchild = Delete(ptr->lchild, x);
		else if (x > ptr->data)
			ptr->rchild = Delete(ptr->rchild, x);
		else
		{
			if ((ptr->lchild != nullptr) && (ptr->rchild != nullptr))
			{
				tmp = findMin(ptr->rchild);
				ptr->data = tmp->data;
				ptr->rchild = Delete(ptr->rchild, tmp->data);
			}
			else
			{
				tmp = ptr;
				if (!ptr->lchild)
					ptr = ptr->rchild;
				else
					ptr = ptr->lchild;
				delete tmp;
			}
		}
	}
	return ptr;
}


BinaryTree<int>* findMin(BinaryTree<int> *ptr)
{
	std::stack<BinaryTree<int> *> s;
	BinaryTree<int> *min = new BinaryTree<int>;
	min->data = 999;
	//如果指针指向位置为nullptr或者栈为空，则遍历结束
	while (ptr || !s.empty()) {
		//一直往左探索，直到左子树为空
		while (ptr)
		{
			if (min->data > ptr->data)
				min = ptr;
			s.push(ptr);
			ptr = ptr->lchild;
		}
		if (!s.empty()) {
			ptr = s.top();
			s.pop();
			ptr = ptr->rchild;
		}
	}
	std::cout << min->data << std::endl;
	return min;
};
//4 3 -1 -1 2 -1 1 6 -1 -1 7 -1 -1

int Max(int a, int b)
{
	return a>b ? a:b;
}

int getHeight(BinaryTree<int> *ptr)
{
	int height = 0;
	if (ptr)
	{
		height = Max(getHeight(ptr->lchild), getHeight(ptr->rchild)) + 1;
	}
	return height;
}

BinaryTree<int>* singleLeftRotation (BinaryTree<int> * A)
{
	/* 注意：A必须有一个左子结点B */
	/* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */
	BinaryTree<int>* B = A->lchild;
	A->lchild = B->rchild;
	B->rchild = A;
	A->height = Max(getHeight(A->lchild), getHeight(A->rchild)) + 1;
	B->height = Max(getHeight(B->lchild), getHeight(B->rchild)) + 1;
	return B;
}

BinaryTree<int>* singleRightRotation (BinaryTree<int> *A)
{
	/* 注意：A必须有一个右子结点B */
	/* 将A与B做右单旋，更新A与B的高度，返回新的根结点B */
	BinaryTree<int> *B = A->rchild;
	A->rchild = B->lchild;
	B->lchild = A;
	A->height = Max(getHeight(A->lchild), getHeight(A->rchild)) + 1;
	B->height = Max(getHeight(B->lchild), getHeight(B->rchild)) + 1;
	return B;
}

BinaryTree<int>* doubleLeftRightRotation(BinaryTree<int>* A)
{
	/* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
	/* 将A、B与C做两次单旋，返回新的根结点C */

	/* 将B与C做右单旋，C被返回 */
	A->lchild = singleRightRotation(A->lchild);  //此时A的左孩子变成了C.大体是 A-left = C  C-left = B  注意，此时C不再是B的右孩子，C已经上提了
	/* 将A与C做左单旋，C被返回 */
	return singleLeftRotation(A);
}

BinaryTree<int>* doubleRightLeftRotation(BinaryTree<int>* A)
{
	A->rchild = singleLeftRotation(A->rchild);
	return singleRightRotation(A);
}

BinaryTree<int>* insertOfAVL(BinaryTree<int> *ptr, int x)
{
	/* 将X插入AVL树T中，并且返回调整后的AVL树 */
	if (!ptr)
	/* 若插入空树，则新建包含一个结点的树 */
	{
		ptr = new BinaryTree<int>;
		ptr->data = x;
		ptr->lchild = nullptr;
		ptr->rchild = nullptr;
	}
	else if ( x < ptr->data)
	{
		/* 插入T的左子树 */
		ptr->lchild = insertOfAVL(ptr->lchild, x);
		/* 如果需要左旋 */
		if (getHeight(ptr->lchild) - getHeight(ptr->rchild) == 2)
			if ( x < ptr->lchild->data)
				ptr = singleLeftRotation(ptr);  /* 左单旋 */
			else
				ptr = doubleLeftRightRotation(ptr); /* 左-右双旋 */
	}
	else if ( x > ptr->data)
	{
		/* 插入T的右子树 */
		ptr->rchild = insertOfAVL(ptr->rchild, x);
		/* 如果需要右旋 */
		if (getHeight(ptr->rchild) - getHeight(ptr->lchild) == 2)
			if (x > ptr->rchild->data)
				ptr = singleRightRotation(ptr); /* 右单旋 */
			else
				ptr = doubleRightLeftRotation(ptr); /* 右-左双旋 */
	}
	/* 更新树高 */
	ptr->height = Max(getHeight(ptr->lchild), getHeight(ptr->rchild)) + 1;
	return ptr;
}

BinaryTree<int>* buildAVL()
{
	BinaryTree<int>* ptr = nullptr;
	int input;

	while (std::cin >> input && input != -1)
	{
		ptr = insertOfAVL(ptr, input);
	}

	ptr->preOrder(ptr);
}


BinaryTree<int>* makeSearchTree()
{
	BinaryTree<int>* ptr = nullptr;
	int input;
	while (std::cin >> input && input != -1)
	{
		ptr = Insert(ptr, input);
	}
//	ptr->preOrder(ptr);
}

int getNumberOfNodes(BinaryTree<int>* ptr)
{
	static int num = 0;
	if (ptr)
	{
		num += 1;
		getNumberOfNodes(ptr->lchild);
		getNumberOfNodes(ptr->rchild);
	}
	return num;
}


bool whetherTwoSearchTreeSame(BinaryTree<int>* tree1)
{
	int num = getNumberOfNodes(tree1);
	int val;
	for (int i = 0; i < num; ++i)
	{
		std::cin >> val;
		if (!check(tree1, val))
			return false;
	}
	return true;
}

bool check(BinaryTree<int>* ptr, int val)
{
	if (ptr->isFirst)
	{
		if (ptr->data < val)
			return check(ptr->rchild, val);
		else if (ptr->data > val)
			return check(ptr->lchild, val);
		else
			return false;
	}
	else
	{
		if (ptr->data == val)
		{
			ptr->isFirst = true;
			return true;
		}
		return false;
	}
}


template class BinaryTree<int>;
