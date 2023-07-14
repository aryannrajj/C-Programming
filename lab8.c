#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* new_node(int x) {
  struct node *temp;
  temp = malloc(sizeof(struct node));
  temp -> data = x;
  temp -> left = NULL;
  temp -> right = NULL;
  return temp;
}
struct node* insert(struct node * root, int x) {
  if (root == NULL)
    return new_node(x);
  else if (x > root -> data) 
    root -> right = insert(root -> right, x);
  else 
    root -> left = insert(root -> left, x);
  return root;
}
struct node* find_minimum(struct node * root) {		//finiding min to help in deletion
  if (root == NULL)
    return NULL;
  else if (root -> left != NULL) // min node does not have left leaf but other node may have it so we should check
    return find_minimum(root -> left); // keep going left till min is found
  return root;
}
struct node* delete(struct node * root, int x) {
  //searching for the item to be deleted
  if (root == NULL)
    return NULL;
  if (x > root -> data)
    root -> right = delete(root -> right, x);
  else if (x < root -> data)
    root -> left = delete(root -> left, x);
  else {
    //no children
    if (root -> left == NULL && root -> right == NULL) {
      free(root);
      return NULL;
    }
    //one child
    else if (root -> left == NULL || root -> right == NULL) {
      struct node *temp;
      if (root -> left == NULL)
        temp = root -> right;
      else
        temp = root -> left;
      free(root);
      return temp;
    }
    //two children
    else {
      struct node *temp = find_minimum(root -> right);
      root -> data = temp -> data;
      root -> right = delete(root -> right, temp -> data);
    }
  }
  return root;
}
void inorder(struct node *root) {	//we will do only inorder traversal for this for now
  if (root != NULL) 
  {
    inorder(root -> left); // traversing left first 
    printf(" %d ", root -> data); // printing data 
    inorder(root -> right); // traversing right (in order is left->root->right)
  }
}
int exists(struct node* root, int x) {
    if (root == NULL) {
        return 0;
    }
    else if (root->data == x) {
        return 1;
    }
    else if (x <= root->data) {	//if less then search the left tree
        return exists(root->left, x);
    }
    else {	//if greater search the right tree
        return exists(root->right, x);
    }
}
int main(){
	struct node* toproot = malloc(sizeof(struct node));
	toproot->data=NULL;
	toproot->left=NULL;
	toproot->right=NULL;
	int x,o=1;
	printf("\n\nBINARY SEARCH TREE OPERATIONS\nNote the default first value is being set as 0\n");
	while(o!=0){
		printf("\n1.Insert a node\n2. View the nodes InOrder only\n3. Delete a node\n4. Search if value exists\n0.Exit\n Enter your choice: ");
		scanf("%d",&o);
		switch(o){
			case 1:
				printf("Enter the data:");
				scanf("%d",&x);
				if(toproot==NULL)toproot = new_node(x);
				else insert(toproot,x);
				break;
			case 2:
				printf("\nInorder traversal of the BST:\n");
				inorder(toproot); break;
			case 3:
				printf("Enter the node to delete:");
				scanf("%d",&x);
				if(exists(toproot,x)){delete(toproot,x);printf("Deleted successfully!\n");}
				else printf("Does not exist!\n");
				break;
			case 4:
				printf("Enter the node to search:");
				scanf("%d",&x);
				if(exists(toproot,x))printf("Node Exists in BST!\n");
				else printf("Node does not exist in BST\n");
				break;
			case 0: printf("\nE X I T I N G !!\n"); break;
			default: printf("\nINVALID CHOICE!!");
		}
	}
    return 0;
}
