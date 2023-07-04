#ifndef _TREE_H__
#define _TREE_H__

#include "LinkQueue.h"				// 链队列
#include "TreeNode.h"			// 树结点类

// 树类
template <class ElemType>
class Tree
{
protected:
//  树的数据成员:
	TreeNode<ElemType> *root;
//	辅助函数:
	TreeNode<ElemType> *CopyTree(TreeNode<ElemType> *t);
// 复制树
	void Destroy(TreeNode<ElemType> * &r);	// 删除以r为根树
	void PreOrder(TreeNode<ElemType>*r,void(*Visit)(const ElemType&)) const;
		// 先序遍历以r为根的树
	void PostOrder(TreeNode<ElemType>*r,void (*Visit)(const ElemType &)) const;
		// 后序遍历以r为根的树
    int Height(const TreeNode<ElemType> *r) const;	
// 求以r为根的树的高
	int NodeCount(const TreeNode<ElemType> *r) const;
// 求以r为根的树的结点个数
    TreeNode<ElemType> *preSibling(TreeNode<ElemType>*r,const TreeNode<ElemType> *p) const;
// 求结点p的前一个兄弟 
    TreeNode<ElemType> *Parent(TreeNode<ElemType> *r, const TreeNode<ElemType>*p) const;//在以r为根的树中求p的双亲 
	int degreeCount(const TreeNode<ElemType> *r) const;//求以r为根的树的度
public:
//  树方法声明及重载编译系统默认方法声明:
	Tree();						// 无参数的构造函数
	Tree(const ElemType &e);		// 构造以e为根的树
	virtual ~Tree();				// 析构函数
	int	Height() const;							    // 求树的高
	Tree(const Tree<ElemType> &t);	// 复制构造函数
	Tree(TreeNode<ElemType> *r);			// 建立以r为根的树
	Tree<ElemType> &operator=(const Tree<ElemType>& t);
	// 赋值运算符重载
	TreeNode<ElemType> *GetRoot() const;	// 返回树的根
	bool IsEmpty() const;				// 判断树是否为空
	Status GetElem(const TreeNode<ElemType> *p, ElemType &e) const;
		// 用e返回结点p元素值
	Status SetElem(TreeNode<ElemType> *p,ElemType &e);
		// 将结点p的值置为e
	void PostOrder(void (*Visit)(const ElemType &)) const;// 树的后序遍历	
	void PreOrder(void (*Visit)(const ElemType &)) const;// 树的先序遍历
	int NodeCount() const;				// 求树的结点个数
	TreeNode<ElemType> *firstChild(const TreeNode<ElemType> *p) const;
		//  求结点p的第一个孩子
	TreeNode<ElemType> *nextSibling(const TreeNode<ElemType> *p) const;
		// 求结点p的下一个兄弟
	TreeNode<ElemType> *preSibling(const TreeNode<ElemType> *p) const;//求节点的前一个兄弟节点
	TreeNode<ElemType> *Parent(const TreeNode<ElemType> *p) const;
	// 求结点p的双亲
	TreeNode<ElemType> *Find(const ElemType &e) const;
		// 查找元素e，查找成功返回结点指针，否则返回NULL 
	Status InsertChild(TreeNode<ElemType> *p, const ElemType &e);
        // 插入一个结点e作为p的孩子
	void DeleteChild(TreeNode<ElemType> *p,int i);	// 删除以节点p的第i个孩子为根的子树
	void DeleteSubTree(TreeNode<ElemType> *p);// 删除以节点p为根的子树
	int degreeCount() const;//求树的度
};


template <class ElemType>
void DisplayTWithTreeShape(TreeNode<ElemType> *r, int level);
	//	按树状形式显示以r为根的树，level为层次数，可设根结点的层次数为1
template <class ElemType>
void DisplayTWithTreeShape(Tree<ElemType> &bt);
	//	树状形式显示树 
template <class ElemType>
void CreateTree(TreeNode<ElemType> *&r, ElemType pre[], ElemType post[], 
	int preLeft, int preRight, int postLeft, int postRight);	
	// 已知树的先序序列pre[preLeft..preRight]和中序序列in[inLeft..inRight]构造以r为根的
	// 树
template <class ElemType>
Tree<ElemType> &CreateTree(ElemType pre[], ElemType post[], int n);
	// 已知先序和中序序列构造树



// 树类的实现部分
template <class ElemType>
Tree<ElemType>::Tree()
// 操作结果：构造一个空树
{
	root = NULL;
}

template <class ElemType>
Tree<ElemType>::~Tree()
// 操作结果：删除树--析造函数
{
	Destroy(root);
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::GetRoot() const
// 操作结果：返回树的根
{
	return root;
}

template <class ElemType>
bool Tree<ElemType>::IsEmpty() const
// 操作结果：判断树是否为空
{
	return root == NULL;
}

template <class ElemType>
Status Tree<ElemType>::GetElem(const TreeNode<ElemType> *p, ElemType &e) const
// 操作结果：用e返回结点p元素值,如果不存在结点p,函数返回NOT_PRESENT,否则返回ENTRY_FOUND
{
	if (p == NULL)		// 不存在结点p
		return NOT_PRESENT;			// 返回NOT_PRESENT
	else	{	// 存在结点p
		e = p->data;				// 用e返回元素值
		return ENTRY_FOUND;			// 返回ENTRY_FOUND
	}
}

template <class ElemType>
Status Tree<ElemType>::SetElem(TreeNode<ElemType> *p,ElemType &e)
// 操作结果：如果不存在结点p,则返回FAIL,否则返回SUCCESS,并将结点p的值设置为e
{
	if (p == NULL)		// 不存在结点p
		return FAIL;				// 返回FAIL
	else	{	// 存在结点p
		p->data = e;				// 将结点p的值设置为e
		return SUCCESS;				// 返回SUCCESS
	}
}

template <class ElemType>
void Tree<ElemType>::PreOrder(TreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// 操作结果：先序遍历以r为根的树
{
	if (r != NULL)	{
		(*Visit)(r->data);				// 首先访问根结点r
		PreOrder(r->firstChild, Visit);	// 再遍历r的左子树
		PreOrder(r->nextSibling, Visit);	// 最后遍历r的右子树
	}
}

template <class ElemType>
void Tree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
// 操作结果：先序遍历树
{
	PreOrder(root, Visit);	
}	

template <class ElemType>
void Tree<ElemType>::PostOrder(TreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// 操作结果：后序遍历以r为根的树
{
	if (r != NULL) 	{
		PostOrder(r->firstChild, Visit);	// 首先遍历r的左子树
		(*Visit)(r->data);				// 再访问根结点r
		PostOrder(r->nextSibling, Visit);	// 最后遍历r的右子树
	}
}

template <class ElemType>
void Tree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
// 操作结果：后序遍历树
{
	PostOrder(root, Visit);	
}	

template <class ElemType>
int Tree<ElemType>::Height(const TreeNode<ElemType> *r) const
// 操作结果：返回以r为根的树的高
{
	if(r == NULL)	// 空树高为0
		return 0;
	else	{	// 非空树高为左右子树的高的最大值再加1
	int height;
	r=r->firstChild;
	height=Height(r);
	if(height!=0)
	while(r->nextSibling!=NULL) 
	{
		r=r->nextSibling;
		if(Height(r)>height) height=Height(r);
	}
	return height+1;
}
}
template <class ElemType>
int Tree<ElemType>::Height() const
// 操作结果：返回树的高
{
	return Height(root);
}

template <class ElemType>
Tree<ElemType>::Tree(const ElemType &e)
// 操作结果：建立以e为根的树
{
	root = new TreeNode<ElemType>(e);
}

template <class ElemType>
int Tree<ElemType>::NodeCount(const TreeNode<ElemType> *r) const
// 操作结果：返回以r为根的树的结点个数
{
	if (r ==NULL)
       return 0;			// 空树结点个数为0
	else
       return NodeCount(r->firstChild) + NodeCount(r->nextSibling) + 1;
		// 非空树结点个为左右子树的结点个数之和再加1
}

template <class ElemType>
int Tree<ElemType>::NodeCount() const
// 操作结果：返回树的结点个数
{
	return NodeCount(root);
}

template <class ElemType>
int Tree<ElemType>::degreeCount(const TreeNode<ElemType> *r) const
{
int degree=0;
if(r->firstChild!=NULL) 
{
r=r->firstChild;degree++;
while(r->nextSibling!=NULL) {r=r->nextSibling;degree++;}
}
return degree;
}

template <class ElemType>
int Tree<ElemType>::degreeCount() const
{
	LinkQueue<TreeNode<ElemType> *> q;	// 定义队列q
	TreeNode<ElemType> *p;
	int degree=0;
	if (root != NULL) q.EnQueue(root);		// 如果根非空,则入队
	while (!q.IsEmpty())	{	            // q非空,说明还有结点未访问
		q.DelQueue(p);                      // 队头元素出队，并访问之 
		if (degreeCount(p)>degree)
			degree=degreeCount(p);
		if (p->firstChild != NULL)			// 队头元素左孩子非空
			q.EnQueue(p->firstChild);		// 左孩子入队
		if (p->nextSibling != NULL)			// 队头元素右孩子非空
			q.EnQueue(p->nextSibling);		// 右孩子入队
	}
	return degree;
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::firstChild(const TreeNode<ElemType> *p) const
// 操作结果：返回树结点p的左孩子
{
	return p->firstChild;
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::nextSibling(const TreeNode<ElemType> *p) const
// 操作结果：返回树结点p的下一个兄弟
{
	return p->nextSibling;
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::preSibling(TreeNode<ElemType> *r,const TreeNode<ElemType> *p) const
// 操作结果：返回以r为根的树中结点p的前一个兄弟 
{
if(r==NULL||r==p||r->firstChild==p) return NULL;
else if(r->nextSibling==p) return r;
else 
{
TreeNode<ElemType> *tmp;
tmp=preSibling(r->firstChild,p);
if(tmp!=NULL) return tmp;
tmp=preSibling(r->nextSibling,p);
if(tmp!=NULL) return tmp;
else return NULL;
}
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::preSibling(const TreeNode<ElemType> *p) const
{
return preSibling(root,p);
}

template <class ElemType>
TreeNode<ElemType> * Tree<ElemType>::Parent(TreeNode<ElemType> *r, const TreeNode<ElemType> *p) const
// 操作结果：返回以r为根的树, 结点p的双亲
{
	if (r == NULL||r==p)
		return NULL;		// 空树
	else if (r->firstChild == p)
		return r; // r为p的双亲
	else if(r->nextSibling==p)
	{
	while(preSibling(r)!=NULL) r=preSibling(r);
	return Parent(root,r);
	}
		else	{	// 在子树上求双亲
		TreeNode<ElemType> *tmp;
		tmp = Parent(r->firstChild, p);	// 在左子树上求p的双亲	
		if (tmp != NULL)
			return tmp;			        // 双亲在左子树上
		
		tmp = Parent(r->nextSibling, p);	// 在右子树上求p的双亲	
		if (tmp != NULL)
			return tmp;			        // 双亲在右子树上
		else
			return NULL;				    // 表示p无双亲
	}
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::Parent(const TreeNode<ElemType> *p) const
// 操作结果：返回树结点p的双亲
{
	return Parent(root, p);
}


template <class ElemType>
Status Tree<ElemType>::InsertChild(TreeNode<ElemType> *p, const ElemType &e)
// 初始条件：p非空，
// 操作结果：插入元素值为e的结点为p的左孩子，如果p的左孩子非空，则p原有左子树成为e的右子树
{
	if (p == NULL)	// p空，返回
		return FAIL;
	else 	{	// 插入左孩子
		TreeNode<ElemType> *child =  new TreeNode<ElemType>(e);// 元素值为e结点
		if (p->firstChild != NULL)	// p的左孩子非空
			child->nextSibling = p->firstChild;	// p原有左子树成为e的右子树
		p->firstChild = child;					// e成为p的左孩子
		return SUCCESS;
	}
}

template <class ElemType>
void Tree<ElemType>::DeleteChild(TreeNode<ElemType> *p,int i)
// 初始条件：p非空
// 操作结果：删除以p的第i个孩子节点为根的子树
{
	if (p == NULL)	// p为空
		return;
	else	// p非空
	{
	int j=1;
	p=p->firstChild;
	while(j<i&&p!=NULL) {p=p->nextSibling;j++;}
	if(p==NULL) return;
	Destroy(p);
	return;
}
}

template <class ElemType>
void Tree<ElemType>::DeleteSubTree(TreeNode<ElemType> *p)
// 初始条件：p非空
// 操作结果：删除以p为根的子树
{
	if (p == NULL)	// p为空
		return;
	else	// p非空
		Destroy(p);	
}

template <class ElemType>
void Tree<ElemType>::Destroy(TreeNode<ElemType> *&r)
// 操作结果：删除以r的树
{
	if(r != NULL)	{	// r非空,实施删除
		if(r->nextSibling!=NULL)
		{
			if(preSibling(r)!=NULL) preSibling(r)->nextSibling=r->nextSibling;
			else if(preSibling(r)==NULL&&Parent(r)!=NULL) Parent(r)->firstChild=r->nextSibling;	
			r->nextSibling=NULL;
		}
		else
		{
			if(preSibling(r)!=NULL) preSibling(r)->nextSibling=NULL;
			else if(preSibling(r)==NULL&&Parent(r)!=NULL) Parent(r)->firstChild=NULL;	
		}
		Destroy(r->firstChild);
		delete r;					// 删除根结点
		r = NULL;
	}
	else return;
}

template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::Find(const ElemType &e) const
// 操作结果：返回节点数值为e的节点
{
	LinkQueue<TreeNode<ElemType> *> q;	// 定义队列q
	TreeNode<ElemType> *p;
	
	if (root != NULL) q.EnQueue(root);		// 如果根非空,则入队
	while (!q.IsEmpty())	{	            // q非空,说明还有结点未访问
		q.DelQueue(p);                      // 队头元素出队，并访问之 
		if (p->data == e)
			return p;
		if (p->firstChild != NULL)			// 队头元素左孩子非空
			q.EnQueue(p->firstChild);		// 左孩子入队
		if (p->nextSibling != NULL)			// 队头元素右孩子非空
			q.EnQueue(p->nextSibling);		// 右孩子入队
	}
	return NULL;
}


template <class ElemType>
TreeNode<ElemType> *Tree<ElemType>::CopyTree(TreeNode<ElemType> *t)
// 操作结果：将以t为根的树复制成新的树,返回新树的根
{
	if (t == NULL)	// 复制空树
		return NULL;					// 空树根为空	
	else	{	// 复制非空树
		TreeNode<ElemType> *lChild = CopyTree(t->firstChild);	// 复制左子树
		TreeNode<ElemType> *rSibling = CopyTree(t->nextSibling);	// 复制右子树
		TreeNode<ElemType> *r = new TreeNode<ElemType>(t->data, lChild, rSibling);
			// 复制根结点
		return r;
	}
}

template <class ElemType>
Tree<ElemType>::Tree(const Tree<ElemType> &t)
// 操作结果：由已知树构造新树——复制构造函数
{
	root = CopyTree(t.root);	// 复制树
}

template <class ElemType>
Tree<ElemType>::Tree(TreeNode<ElemType> *r)
// 操作结果：建立以r为根的树
{	
	root = r;	// 复制树
}

template <class ElemType>
Tree<ElemType> &Tree<ElemType>::operator=(const Tree<ElemType> &t)
// 操作结果：由已知树t复制到当前树--赋值运算符重载
{
	if (&t != this)	{
		Destroy(root);				// 释放原树所占用空间
		root = CopyTree(t.root);	// 复制树
	}
	return *this;
}

template <class ElemType>
void DisplayTWithTreeShape(TreeNode<ElemType> *r, int level)
// 操作结果：按树状形式显示以r为根的树，level为层次数，可设根结点的层次数为1
{
	if(r != NULL)	{	// 空树不显式，只显式非空树
		DisplayTWithTreeShape<ElemType>(r->nextSibling, level);//显示右子树
		cout << endl;					//显示新行	
		for(int i = 0; i < level - 1; i++)
			cout << "  ";				//确保在第level列显示结点
		cout << r->data;				//显示结点
		DisplayTWithTreeShape<ElemType>(r->firstChild, level + 1);//显示左子树
	}
}

template <class ElemType>
void DisplayTWithTreeShape(Tree<ElemType> &bt)
// 操作结果：树状形式显示树 
{
	DisplayTWithTreeShape<ElemType>(bt.GetRoot(), 1);	
		// 树状显示以bt.GetRoot()为根的树
	cout << endl;
}

template <class ElemType>
void CreateTree(TreeNode<ElemType> *&r, ElemType pre[], ElemType post[], 
							int preLeft, int preRight, int postLeft, int postRight)	
// 操作结果：已知树的先序序列pre[preLeft..preRight]和后序序列post[postLeft..postRight]构造
//	以r为根的树
{
	if (postLeft > postRight)	// 树无结点,空树
		r = NULL;			// 空树根为空
	else	{	// 树有结点,非空树
		r = new TreeNode<ElemType>(pre[preLeft]);// 生成根结点
		int mid = postLeft;
		while (post[mid] != pre[preLeft]) 	// 查找pre[preLeft]在in[]中的位置,也就是后序序列中根的位置
			mid++;
		CreateTree(r->firstChild, pre, post, preLeft+1, preLeft + mid - postLeft, postLeft, mid - 1);
			// 生成左子树
		CreateTree(r->nextSibling, pre, post, preLeft + mid - postLeft + 1, preRight, mid + 1, 
			postRight);								// 生成右子树
	}
} 

template <class ElemType>
Tree<ElemType> &CreateTree(ElemType pre[], ElemType post[], int n)
// 操作结果：已知先序和后序序列构造树
{
	TreeNode<ElemType> *r;						// 树的根
	CreateTree<ElemType>(r, pre,post, 0, n - 1, 0, n - 1);
		// 由先序和后序序列构造以r为根的树 
	Tree<ElemType> *bt = new Tree<ElemType>(r);	// 生成树
	return *bt;
}

#endif
