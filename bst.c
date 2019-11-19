#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node * NODE;

NODE getnode(int item) {
    NODE p = (NODE) malloc(sizeof(struct node));
    p -> data = item;
    p -> lchild = NULL;
    p -> rchild = NULL;
    return p;
}

void inorder(NODE root) {
    if (root == NULL) return;
    inorder(root -> lchild);
    printf("%d ", root -> data);
    inorder(root -> rchild);
}

void preorder(NODE root) {
    if (root == NULL) return;
    printf("%d ", root -> data);
    inorder(root -> rchild);
    preorder(root -> lchild);
}

void postorder(NODE root) {
    if (root == NULL) return;
    postorder(root -> lchild);
    postorder(root -> rchild);
    printf("%d ", root -> data);
}

NODE insert(NODE root, int item) {
    if (root == NULL) return getnode(item);
    if (item < root -> data) root -> lchild = insert(root -> lchild, item);
    else if (item >= root -> data) root -> rchild = insert(root -> rchild, item);
    return root;
}

void display(NODE root, int level) { 
	if (root == NULL) return; 
	if (level == 1) printf("%d ", root -> data); 
	else if (level > 1) { 
		display(root -> lchild, level - 1); 
		display(root -> rchild, level - 1); 
	} 
} 

int height(NODE root) { 
	int ldepth,rdepth;
	if (root == NULL) return 0; 
	else { 
		ldepth = height(root -> lchild); 
		rdepth = height(root -> rchild); 
		if(ldepth > rdepth) return (ldepth + 1); 
		else return (rdepth + 1); 
	} 
}

void levelorder(NODE root) { 
	int h = height(root), i; 
	for (i = 1; i <= h; i++) { 
		display(root, i); 
		printf("\n"); 
	} 
} 

int main() {
    int choice, pos, ele;
    NODE root = NULL;
    
    do {
        printf("1. Insert \n");
        printf("2. Traverse Inorder \n");
        printf("3. Traverse Preorder \n");
        printf("4. Traverse Postorder \n");
        printf("5. Display \n");
	printf("6. Exit \n");
        printf("Enter Choice \n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: printf("Enter Element \n");
                    scanf("%d", &ele);
                    root = insert(root, ele);
                    break;
            
            case 2: inorder(root);
                    break;
                    
            case 3: preorder(root);
                    break;
                    
            case 4: postorder(root);
                    break;
            case 5: levelorder(root);
                    break;

	    case 6: exit(0);
                    break;
            
            default: printf("Invalid Choice \n");
        }
        
        
    } while (choice != 6);

    return 0;
}
