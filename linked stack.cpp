#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
/*  Bagli liste kullanilan yigin */

    /* Yigin kavrami olusturuluyor ve pop-push-node olusturma gibi islemler tanýmlanýyor*/ 

	struct StackNode
	{
			int data;
			struct StackNode* next;
		};
    
	 struct StackNode* newNode(int data)
	{
	struct StackNode* stackNode =
		(struct StackNode*) malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
	}

	void push(struct StackNode** root, int data)
	{
		struct StackNode* stackNode = newNode(data);
		stackNode->next = *root;
		*root = stackNode;
	}

	int isEmpty(struct StackNode *root)
	{
	return !root;
}

	int pop(struct StackNode** root)
	{
		if (isEmpty(*root))
			return INT_MIN;
		struct StackNode* temp = *root;
		*root = (*root)->next;
		int popped = temp->data;
		free(temp);
		return popped;
	}

	int peek(struct StackNode* root)
	{
		if (isEmpty(root))
			return INT_MIN;
		return root->data;
	}
	
	float stackarama (struct StackNode* ornek, int number)
	{
	 clock_t k;
	
	 k = clock();				//Arama islemi icin sure tutulmaya baslandi
	
    struct StackNode* current = ornek;  
    
	while (current != NULL)
    {
        if (current->data == number)
    		{
	   
			k = clock() - k; 					 // sureyi bitirdi
		
			printf("%d Bulundu!\n", current->data);
			printf("%.10lf mikrosaniyede ulasildi.\n", (float)k);
		
			return k;
		
			}
        
		current = current->next;
    }
	printf("Bulunamadi!");
}


int main()
{
	float sum=0;
	int sayi, i=1;
   	struct StackNode* liste = NULL;
   		
	int t=0;
	
	do
		{
		
		for(int i=1; i<=10000; i++)				//1-10000 ARASI DEGERLER ICIN STACK OLUSTURULDU
	
		{
			push(&liste, i);
	
		}
		
		sum += stackarama (liste, rand()%10000);
		
		t++;
			
		}
		while(t<1000);
	
printf("ortalama ulasim suresi: %.10lf mikrosaniye \n\n ", sum /(float)t);
		
		getchar();
		return 0;
	

}


