#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

/* newNode() allocates a new node with the given data and NULL left and
right pointers. */
struct node* newNode(int data)
{
	// Allocate memory for new node 
	struct node* node = (struct node*)malloc(sizeof(struct node));

	// Assign data to this node
	node->data = data;

	// Initialize left and right children as NULL
	node->left = NULL;
	node->right = NULL;
	return(node);
}

insert(int key, struct node **leaf)
{
	if (*leaf == 0)
	{
		*leaf = (struct node*) malloc(sizeof(struct node));
		(*leaf)->data = key;
		/* initialize the children to null */
		(*leaf)->left = 0;
		(*leaf)->right = 0;
	}
	else if (key <= (*leaf)->data)
	{
		insert(key, &(*leaf)->left);
	}
	else if (key >(*leaf)->data)
	{
		insert(key, &(*leaf)->right);
	}
}

float search(struct node* root, int sayi)
{
	int i=0;
	 clock_t k;
	 k = clock();			//süreyi baþlattý
	if (root != NULL)
	{
		search(root->left, sayi);
		if(root->data == sayi)
		{
			k = clock() - k; 		// sureyi bitirdi
  	
	  		printf("%d Bulundu!\n", root->data);
  	 		float time_taken = ((float)k);
			printf("%.10lf mikrosaniyede ulasildi.\n", time_taken);
				
			return time_taken;
		}
		search(root->right, sayi);
	}	

}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

int main()
{
	float sum;
	/*create root*/
	struct node *root = NULL;
	srand(time(NULL));
	int t=0, tree_size = 10000, new_leaf_value, x,count=0;
	
	
	root = newNode(1);		// Basta koke bir eklendi, sirali ekleme bu kokun ustune eklenecek sekilde yazildi.
	for (int i = 2; i <= tree_size; i++)
	{
		new_leaf_value = i;
		insert(new_leaf_value, &root);
	}
	
	
		
	for ( x = 0; x < 1000; x++ )  
	{
	sum += search (root, rand()%10000);
   	}
	
	printf("ortalama ulasim suresi: %.10lf mikrosaniye \n\n ", sum / 1000);
	getchar();
	return 0;
}
