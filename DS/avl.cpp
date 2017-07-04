#include <iostream>
//#include "avl.h"
#include <algorithm>

struct node
{
	int data;
	int height;
	struct node *parent;
	struct node *left;
	struct node *right; 
};

 class avl{
 	public:
		 int getBalance(struct node *);
		 void checkHeights(struct node *);
		 struct node *leftleft(struct node *);
		 struct node *leftright(struct node *);
		 struct node *rightleft(struct node *);
		 struct node *rightright(struct node *);
		 struct node* search (struct node *, int );
		 struct node *minimum_in_the_subtree_rooted_at(struct node *);
		 struct node *maximum_in_the_subtree_rooted_at(struct node *);
		 struct node* predecessor(struct node *, struct node *);
		 struct node* successor(struct node *, struct node *);
		 struct node* search_for_insert(struct node *,int );
		 bool parent_sibling_relation(struct node *,struct node* );
		 struct node* insert(struct node *, int );
		 void preorder(struct node *);
		 void inorder(struct node *);
		 void postorder(struct node *);
		 struct node* node_delete(struct node *, int );
		 void create_height(struct node *);
};
	void avl::preorder(struct node *head)
	{
		std::cout<<head->data<<" - ";
		
		if(head->left) preorder(head->left);
		
		if(head->right) preorder(head->right);
		
	}

	void avl::postorder(struct node *head)
	{
		if(head->left) preorder(head->left);
		if(head->right) preorder(head->right);
		std::cout<<head->data<<" - ";
	}

	void avl::inorder(struct node *head)
	{
		if(head->left) preorder(head->left);
		std::cout<<head->data<<" - ";
		if(head->right) preorder(head->right);
		
	}

	struct node* avl::search (struct node *head, int value)
	{
		// returns node which has the data
		// if not present, it returns NULL
		struct node *temp = head,*to_return=NULL;
		while(temp!=NULL){
			if(temp->data > value)
				temp = temp->left;
			else if(temp->data < value)
				temp = temp->right;
			else
			{
				to_return = temp;
				break; 
			}
		}
		return to_return;
	}

	struct node * avl::  minimum_in_the_subtree_rooted_at(struct node *current)
	{
		struct node *temp = current;
		while(temp->left)
		{
			temp=temp->left;
		}
		return temp;
	}

	struct node * avl::maximum_in_the_subtree_rooted_at(struct node *current)
	{
		struct node *temp = current;
		while(temp->right)
		{
			temp=temp->right;
		}
		return temp;
	}

	struct node* avl::predecessor(struct node *head, struct node *current)
	{
		// Will return NULL if no predecessor and display no predecessor
		// WIll return node, it's upto you to decide what to do with it
		// if you have data, call SEARCH and pass the returned value as current
		struct node *to_return;
		if(!current)
		{
			std::cout<<"Predecessor of NULL node is undefined"<<std::endl;
			return NULL;
		}
		if(current->left)
		{
			to_return = maximum_in_the_subtree_rooted_at(current->left);
		}
		else
		{
			struct node *parent = current->parent;
			while((parent!=NULL) && (!parent_sibling_relation(parent,current))){
				current = parent;
				parent = parent->parent;
			}
			to_return = parent;
		}
		if(to_return == NULL)
		{
			std::cout<<"No predecessor for "<<current->data<<std::endl;	
			return NULL;
		}
		return to_return;
	}

	struct node* avl::successor(struct node *head, struct node *current)
	{
		// Will return NULL if no predecessor and display no predecessor
		// WIll return node, it's upto you to decide what to do with it
		// if you have data, call SEARCH and pass the returned value as current
		struct node *to_return;
		if(!current)
		{
			std::cout<<"Successor of NULL node is undefined"<<std::endl;
			return NULL;
		}
		if(current->right)
		{
			to_return = minimum_in_the_subtree_rooted_at(current->right);
		}
		else
		{
			struct node *parent = current->parent;
			while((parent!=NULL) && (parent_sibling_relation(parent,current))){
				current = parent;
				parent = parent->parent;
			}
			to_return = parent;
		}
		if(to_return == NULL)
		{
			std::cout<<"No Successor for "<<current->data<<std::endl;	
			return NULL;
		}
		return to_return;
	}

	struct node* avl::search_for_insert(struct node* head,int value)
	{
		// returns parent where to be inserted
		// if already present returns null
		struct node *temp = head,*to_return;
		while(temp!=NULL){
			to_return = temp;
			if(temp->data > value)
				temp = temp->left;
			else if(temp->data < value)
				temp = temp->right;
			else
			{
				temp = NULL;
				to_return = NULL; 
			}
		}
		return to_return;
	}

	bool avl::parent_sibling_relation(struct node *parent,struct node* child)
	{
		// 0-> leftchild	1->rightchild
		if(parent->data > child->data)
			return false;
		else
			return true;
	}

	void avl::create_height(struct node *a_node)
	{
		if(a_node)
		{
			int left_height,right_height;
			if(a_node->left) left_height = a_node->left->height;
			if(a_node->right) right_height = a_node->right->height;
			a_node->height = 1+std::max(left_height,right_height);
		}
	}
	int avl::getBalance(struct node *a)
	{
		int b=0,c=0;
		if(!a)
			return 0;
		else{
			if(a->left)
				b=a->left->height;
			if(a->right) 
				c= a->right->height;
			return b-c;
		}
	}
	struct node * avl::leftleft(struct node* a)
	{
		struct node *ggparent = a,*tparent = a->left;
		ggparent->left = tparent->right;
		if(ggparent->left)
		{			
			ggparent->left->parent = ggparent;
		}
		tparent->right = ggparent;
		tparent->parent = ggparent->parent;
		if(ggparent->parent)
		{
			if(ggparent->parent->left==ggparent)
				ggparent->parent->left = tparent;
			else
				ggparent->parent->right = tparent;
		}
		ggparent->parent = tparent;
		return tparent;
	}
	struct node * avl::rightright(struct node* a)
	{
		struct node *ggparent = a,*tparent = a->right;
		ggparent->right=tparent->left;
		if(ggparent->right) ggparent->right->parent = ggparent;
		tparent->left = ggparent;
		tparent->parent = ggparent->parent;
		if(ggparent->parent)
		{
			if(ggparent->parent->left==ggparent)
				ggparent->parent->left = tparent;
			else
				ggparent->parent->right = tparent;
		}
		ggparent->parent = tparent;
		return tparent;
	}
	struct node *avl::leftright(struct node *a)
	{
		struct node *ggp=a,*p=a->left,*son=a->left->right;
		p->parent=son;
		p->right=son->left;
		son->parent = ggp;
		ggp->left = son;
		if(p->right) p->right->parent = p;
		son->left = p;
		//one rotation over
		struct node* temp = son;
		son=p;
		p=temp;
		ggp->left=p->right;
		p->parent = ggp->parent;
		if(ggp->parent)
		{
			if(ggp->parent->left==ggp)
				ggp->parent->left = p;
			else
				ggp->parent->right = p;
		}
		ggp->parent = p;
		p->right = ggp;
		if(ggp->left) ggp->left->parent = ggp;
		return p;
	}
	struct node *avl::rightleft(struct node *a)
	{
		struct node *ggp=a,*p=a->right,*son=a->right->left;
		p->parent=son;
		p->left=son->right;
		son->parent = ggp;
		ggp->right = son;
		if(p->left) p->left->parent = p;
		son->right = p;
		//one rotation over
		struct node* temp = son;
		son=p;
		p=temp;
		ggp->right=p->left;
		p->parent = ggp->parent;
		if(ggp->parent)
		{
			if(ggp->parent->left==ggp)
				ggp->parent->left = p;
			else
				ggp->parent->right = p;
		}
		ggp->parent = p;
		p->left = ggp;
		if(ggp->right) ggp->right->parent = ggp;
		return p;
	}
	
	void avl::checkHeights(struct node *head)
	{
		if(head)
		{
			if(head->left) postorder(head->left);
			if(head->right) postorder(head->right);
			create_height(head);
		}
	}
	
	struct node* avl::insert(struct node *head, int value)
	{
		if(!head){
			struct node *newn = new node;
			newn->data = value;
			newn->right = NULL;
			newn->left = NULL;
			newn->height = 0;
			return newn;
		}
		else if(value > head->data){
			head->right = insert(head->right,value);
		} 
		else if(value < head->data){
			head->left = insert(head->left,value);
		}
		else{return head;}
		create_height(head);
		int balance = getBalance(head);
		if((balance > 1) &&(value > head->left->data))
			head = rightleft(head);
		else if ((balance > 1)&&(value < head->left->data))
			head = leftleft(head);
		else if ((balance < -1)&&(value<head->right->data))
			head = rightleft(head);
		else if ((balance < -1)&&(value > head->right->data))
			head = rightright(head);
		if(head) checkHeights(head);
		std::cout<<std::endl;
		return head;
	}

	struct node * avl::node_delete(struct node *head, int value)
	{	
		struct node *to_be_deleted = search(head,value);
		struct node *this_parent;
		if(!to_be_deleted){
			std::cout<<" Element "<<value<<" not found Exception";
			return head;
		}
		this_parent = to_be_deleted->parent;
		if (!to_be_deleted->left && !to_be_deleted->right)
		{
			if(this_parent == NULL)
				head = NULL;
			else
			{
				if(parent_sibling_relation(this_parent,to_be_deleted))
				{
					this_parent->right= NULL;
				}
				else
					this_parent->left = NULL;
			}
			delete(to_be_deleted);
		}
		else if(to_be_deleted->left && to_be_deleted->right)
		{
			struct node *predec = predecessor(head,to_be_deleted);
			to_be_deleted->data = predec->data;
			if(parent_sibling_relation(predec->parent,predec))
			{
				predec->parent->right= predec->left;
			}
			else
				predec->parent->left = predec->left;
			delete(predec);
		}
		else if(to_be_deleted->left && !to_be_deleted->right)
		{
			if(this_parent == NULL)
				head = to_be_deleted->left;
			else
			{
				if(parent_sibling_relation(this_parent,to_be_deleted))
				{
					this_parent->right= to_be_deleted->left;
				}
				else
					this_parent->left = to_be_deleted->left;
			}
			delete(to_be_deleted);

		}
		else if(!to_be_deleted->left && to_be_deleted->right)
		{
			if(this_parent == NULL)
				head = to_be_deleted->right;
			else
			{
				if(parent_sibling_relation(this_parent,to_be_deleted))
				{
					this_parent->right= to_be_deleted->right;
				}
				else
					this_parent->left = to_be_deleted->right;
			}
			delete(to_be_deleted);
		}
		return head;
	}
 int main()
 {
 	struct node *head=NULL;
 	avl b = avl();
 	head = b.insert(head,5);
//	std::cout<<head->data<<std::endl;
 	head = b.insert(head,3);
// 	std::cout<<head->left->data<<std::endl;
 	head = b.insert(head,10);
//	std::cout<<head->right->data<<std::endl;
 	head = b.insert(head,2);
 	head = b.insert(head,1);
 	head = b.insert(head,0);
// 	std::cout<<head->data;
 	std::cout<<std::endl<<std::endl<<std::endl<<'\t';
	b.preorder(head);
	std::cout<<std::endl<<std::endl<<std::endl<<'\t';
// b.postorder(head);
 b.inorder(head);
// 	temp = b.node_delete(head,3);
// 	std::cout<<temp->data;
// 	std::cout<<std::endl;

// 	temp = b.node_delete(head,10);	
// 	std::cout<<temp->data;
// 	std::cout<<std::endl;
// 	b.preorder(head);
 	return 0;
 }
