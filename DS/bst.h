#ifndef __BST_H_INCLUDED__
#define __BST_H_INCLUDED__

struct node
{
	int data;
	struct node *parent;
	struct node *left;
	struct node *right; 
};

class bst{
	public:
		struct node* search (struct node *, int );
		struct node *minimum_in_the_subtree_rooted_at(struct node *);
		struct node *maximum_in_the_subtree_rooted_at(struct node *);
		struct node* predecessor(struct node *, struct node *);
		struct node* successor(struct node *, struct node *);
		struct node* search_for_insert(struct node *,int );
		bool parent_sibling_relation(struct node *,struct node* );
		struct node* insert(struct node *, int );
		struct node* node_delete(struct node *, int );
		void preorder(struct node *);
		void inorder(struct node *);
		void postorder(struct node *);
};
#endif
