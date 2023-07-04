#ifndef _TREE_NODE_H__
#define _TREE_NODE_H__

// 二叉链表结点类
template <class ElemType>
struct TreeNode
{
// 数据成员:
	ElemType data;						// 数据域
	TreeNode<ElemType>  *firstChild;	// 第一个孩子指针域
	TreeNode<ElemType>  *nextSibling;	// 下一个兄弟指针域

//	构造函数:
	TreeNode();		// 无参数的构造函数 
	TreeNode(const ElemType &d,// 已知数据元素值,指向左右节点的指针构造一个结点
		TreeNode<ElemType> *lChild = NULL, 
		TreeNode<ElemType> *rSibling = NULL);
};

// 树结点类的实现部分
template <class ElemType>
TreeNode<ElemType>::TreeNode()
// 操作结果：构造一个叶结点
{
	firstChild = nextSibling = NULL;	// 叶结点左右节点为空
}

template <class ElemType>
TreeNode<ElemType>::TreeNode(const ElemType &d, 
	TreeNode<ElemType> *lChild, TreeNode<ElemType> *rSibling)
// 操作结果：构造一个数据域为d,第一个孩子为lChild,下一个兄弟为rChild的结点
{	
	data = d;					// 数据元素值
	firstChild = lChild;			// 第一个孩子
	nextSibling = rSibling;		// 下一个兄弟
}

#endif

