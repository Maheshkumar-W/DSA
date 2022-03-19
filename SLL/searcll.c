#include<stdio.h>
#include<stdlib.h>
struct node
     {
         int data;
         struct node *next;
     } *head;

void list(int n)
     {
         struct node *new_Node, *temp;
         int data, i;
         head = malloc(sizeof(struct node));

         if (head == NULL)
         {
             printf("memory unable to allocate");
             exit(0);
         }

         printf("\n Enter data of node 1: ");
         scanf("%d", &data);

         head->data = data;
         head->next = NULL;
         temp = head;

         for(i=2;i<=n;i++)
         {
             new_Node = malloc(sizeof(struct node));
             if(new_Node == NULL)
             {
                 printf("memory unable to allocate");
                 exit(0);
             }
             printf("\n enter data of node %d : ",i);
             scanf("%d",&data);
             new_Node->data = data;
             new_Node->next = NULL;
             temp->next = new_Node;
             temp = temp->next;
         }
     }   

void print()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    temp = head;
    while(temp != NULL)
    {
        printf("%d" ,temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int found(int key)
{
    int index;
    struct node *cur_Node;
    index = 0;
    cur_Node = head;
    while(cur_Node != NULL && cur_Node->data != key)
    {
        index ++;
        cur_Node = cur_Node->next;
    }
    return(cur_Node != NULL) ? index : -1;
}
int main()
{
    int n,ele_search,index;
    printf("Enter the size of nodes : \n");  
    scanf("%d",&n);
    list(n);
    printf("\n Enter data in list:\n");
    print("\t");
    printf("Enter element to search : \n");
    scanf("%d", &ele_search);

    index = found(ele_search); 
    if(index >= 0)
       printf("Element found in the list at position = %d \n", index  + 1);
    else
       printf("Element not found in the list \n");
    return 0;
}