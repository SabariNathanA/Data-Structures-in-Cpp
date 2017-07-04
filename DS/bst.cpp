#include <iostream>
#include "bst.h"

// class bst{
// 	public:
		// struct node* search (struct node *, int );
		// struct node *minimum_in_the_subtree_rooted_at(struct node *);
		// struct node *maximum_in_the_subtree_rooted_at(struct node *);
		// struct node* predecessor(struct node *, struct node *);
		// struct node* successor(struct node *, struct node *);
		// struct node* search_for_insert(struct node *,int );
		// bool parent_sibling_relation(struct node *,struct node* );
		// struct node* insert(struct node *, int );
		// struct node* node_delete(struct node *, int );

	void bst::preorder(struct node *head)
	{
		std::cout<<head->data<<" - ";
		if(head->left) preorder(head->left);
		if(head->right) preorder(head->right);
	}

	void bst::postorder(struct node *head)
	{
		if(head->left) preorder(head->left);
		if(head->right) preorder(head->right);
		std::cout<<head->data<<" - ";
	}

	void bst::inorder(struct node *head)
	{
		if(head->left) preorder(head->left);
		std::cout<<head->data<<" - ";
		if(head->right) preorder(head->right);
		
	}

	struct node* bst::search (struct node *head, int value)
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


	struct node * bst::  minimum_in_the_subtree_rooted_at(struct node *current)
	{
		struct node *temp = current;
		while(temp->left)
		{
			temp=temp->left;
		}
		return temp;
	}

	struct node * bst::maximum_in_the_subtree_rooted_at(struct node *current)
	{
		struct node *temp = current;
		while(temp->right)
		{
			temp=temp->right;
		}
		return temp;
	}

	struct node* bst::predecessor(struct node *head, struct node *current)
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

	struct node* bst::successor(struct node *head, struct node *current)
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

	struct node* bst::search_for_insert(struct node* head,int value)
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

	bool bst::parent_sibling_relation(struct node *parent,struct node* child)
	{
		// 0-> leftchild	1->rightchild
		if(parent->data > child->data)
			return false;
		else
			return true;
	}

	struct node* bst::insert(struct node *head, int value)
	{
		struct node *parent_of_to_be_inserted = NULL,*new_node,*temp = head;
		if(!temp)
		{
			temp = new node;
			temp->parent = NULL;
			temp->left = NULL;
			temp->right = NULL;
			temp->data = value;
			head = temp;
		}
		else
		{
			parent_of_to_be_inserted = search_for_insert(head,value);
			if(parent_of_to_be_inserted == NULL)
			{
				std::cout<<value<<" Already Exists!"<<std::endl;
				return head;
			}
		
			new_node = new node;
			new_node->data = value;
			new_node->right = NULL;
			new_node->left = NULL;
			new_node->parent = parent_of_to_be_inserted;
		
			if(parent_sibling_relation(parent_of_to_be_inserted,new_node)){
				parent_of_to_be_inserted->right = new_node;
			}
			else
				parent_of_to_be_inserted->left = new_node;
		}
		return head; 
	}

	struct node * bst::node_delete(struct node *head, int value)
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
// };
// int main()
// {
// 	struct node *head=NULL,*temp;
// 	bst b = bst();
// 	head = b.insert(head,5);
// 	std::cout<<head->data<<std::endl;
// 	head = b.insert(head,3);
// 	std::cout<<head->left->data<<std::endl;
// 	head = b.insert(head,10);
// 	std::cout<<head->right->data<<std::endl;
// 	head = b.insert(head,10);
// 	std::cout<<head->data;
// 	std::cout<<std::endl;

// b.preorder(head);
// b.postorder(head);b
// .inorder(head);
// 	temp = b.node_delete(head,3);
// 	std::cout<<temp->data;
// 	std::cout<<std::endl;

// 	temp = b.node_delete(head,10);	
// 	std::cout<<temp->data;
// 	std::cout<<std::endl;
// 	b.preorder(head);
// 	return 0;
// }