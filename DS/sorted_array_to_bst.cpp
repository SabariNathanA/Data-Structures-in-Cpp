#include "bst.h"
#include <iostream>

bst *o = new bst();
struct node *head =NULL;
struct node *build(int a[],int start,int end)
{
	if(start>end)
		return NULL;
	int mid = start+end;
	mid/=2;
	struct node *temp = new node;
	temp->data = a[mid];
	std::cout<<a[mid]<<std::endl;
	temp->left = build(a,start,mid-1);
	temp->right= build(a,mid+1,end);
	temp->parent = NULL;
	return temp;
}

int main()
{
	
	
	// temp = o->insert(temp,8);
	int b[5] = {5,6,7,8};
	head = build(b,0,3);
	// std::cout<<temp->data;
	o->inorder(head);

}