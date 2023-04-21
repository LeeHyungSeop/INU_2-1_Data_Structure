#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}B;

B* root=0;

void addNode(int _data)
{
	B* new_node=(B*)malloc(sizeof(B));
	new_node->data=_data;
	new_node->left=new_node->right=0;

	B* temp=root;

	if(root==0)
	{
		root=new_node;
		return;
	}
	while(1)
	{
		if(temp->data>_data)
		{
			if(temp->left==0)
			{
				temp->left=new_node;
				return;
			}
			temp=temp->left;
		}
		else
		{
			if(temp->right==0)
			{
				temp->right=new_node;
				return;
			}
			temp=temp->right;
		}
	}
}

void inorderTraversal(B* _r)
{
	if(_r==0)
	{
		return;
	}
	inorderTraversal(_r->left);
	printf("%d ",_r->data);
	inorderTraversal(_r->right);
}

void preorderTraversal(B* _r)
{
	if(_r==0)
	{
		return;
	}
	printf("%d ",_r->data);
	preorderTraversal(_r->left);
	preorderTraversal(_r->right);
}

void postorderTraversal(B* _r)
{
	if(_r==0)
	{
		return;
	}
	postorderTraversal(_r->left);
	postorderTraversal(_r->right);
	printf("%d ",_r->data);
}

int cntNodes(B* _r)
{
	if(_r==0)
		return 0;

	return 1+cntNodes(_r->left) + cntNodes(_r->right);
}

int height(B* _r)
{
	if(_r==0)
	return 0;

	int left_child=height(_r->left);
	int right_child=height(_r->right);

	return 1+(left_child>right_child?left_child:right_child);
}

int cntTerminal(B* _r)
{
	if(_r==0)
	return 0;

	if(_r->left==0 && _r->right==0)
	{
		return 1;
	}

	return cntTerminal(_r->left) + cntTerminal(_r->right);
}

void deleteNode(int _data,B* _r)
{
	B* target=_r;
	B* target_p=0;

	while(1)
	{
		if(target==0)
		{
			return;
		}
		else if(target->data==_data)
		{
			if(target->left==0 && target->right==0)   // terminal node 인 경우
			{
				if(target==_r)
				{
					free(_r);
					_r=0;
					return;
				}
				if(target_p->left==target)
				{
					target_p->left=0;
					free(target);
					return;
				}
				else if(target_p->right==target)
				{
					target_p->right=0;
					free(target);
					return;
				}
			}

			else if(target->left!=0 && target->right==0) // 자식 노드가 왼쪽에만
			{
				if(target==_r)
				{
					_r=_r->left;
					free(target);
					return;
				}
				if(target_p->left==target)
				{
					target_p->left=target->left;
					free(target);
					return;
				}
				else if(target_p->right==target)
				{
					target_p->right=target->left;
					free(target);
					return;
				}
			}
			else if(target->left==0 && target->right!=0) // 자식 노드가 오른쪽에만
			{
				if(target==_r)
				{
					_r=_r->right;
					free(target);
					return;
				}
				if(target_p->left==target)
				{
					target_p->left=target->right;
					free(target);
					return;
				}
				else if(target_p->right==target)
				{
					target_p->right=target->right;
					free(target);
					return;
				}
			}
			else // 쌍자식
			{
				B* temp=target->right;
				B* temp_p=target;
				while(temp->left!=0)
				{
					temp_p=temp;
					temp=temp->left;
				}
				target->data=temp->data;
				if(temp_p->right==temp) // 오른쪽 트리의 가장 작은 숫자가 바로 나온경우
				{
					temp_p->right=temp->right;
					free(temp);
					return;
				}
				else{
					temp_p->left=temp->right;
					free(temp);
					return;
				}
			}
		}
		else // 값을 찾지 못하고 내려가야 하는 경우
		{
			target_p=target;
			if(target->data>_data)
			{
				target=target->left;
			}
			else
			{
				target=target->right;
			}
		}
	}
}

int main(void)
{
	addNode(5);
	addNode(1);
	addNode(3);
	addNode(9);
	addNode(7);
	addNode(6);
	addNode(10);

	inorderTraversal(root); printf("\n");
	preorderTraversal(root); printf("\n"); 
	postorderTraversal(root); printf("\n"); 

	printf("총 노드의 개수 : %d\n",cntNodes(root));
	printf("height : %d\n", height(root));
	printf("terminal node 개수 : %d\n", cntTerminal(root));

	deleteNode(9, root);
	deleteNode(5, root); 
	deleteNode(1212,root);

	inorderTraversal(root); printf("\n");
	preorderTraversal(root); printf("\n"); 
	postorderTraversal(root); printf("\n");

	printf("총 노드의 개수 : %d\n", cntNodes(root));
	printf("height : %d\n", height(root));
	printf("terminal node 개수 : %d\n", cntTerminal(root));
	return 0;
}