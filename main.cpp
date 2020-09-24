#include "BinaryTree.h"

int main()
{
//	BinaryTree<int>* iTree;
//	iTree = iTree->Create_BinaryTree();
//	std::cout << getHeight(iTree);

//	coutTraversal(iTree);
//	BinaryTree<int> *min = findMin(iTree);


//	BinaryTree<int>* ptr = nullptr;
//	int input;
//
//	while (std::cin >> input && input != -1)
//	{
//		ptr = insertOfAVL(ptr, input);
//	}
//
//	ptr->preOrder(ptr);
//	BinaryTree<int>* ptr = buildAVL();
	BinaryTree<int>* root = makeSearchTree();
	std:: cout << whetherTwoSearchTreeSame(root);
}

/*
input:1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
                1
               / \
              2   3
             / \ / \
            4  5 6  7

output:
先序遍历: 1  2  4  5  3  6  7
中序遍历: 4  2  5  1  6  3  7
后序遍历: 4  5  2  6  7  3  1
*/


