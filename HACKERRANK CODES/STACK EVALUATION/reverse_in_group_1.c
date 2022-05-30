#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*NODE;
NODE getNode(int m)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    if(n==NULL)
        exit(0);
    //printf("Enter a number : ");
    n->data = m;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

NODE insert_end(NODE head, int m)
{
    NODE temp = getNode(m);
    if(head==NULL)
        return temp;
    NODE cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

NODE reverse_in_groups(NODE head, int k)
{
    if(head==NULL)
        return head;
    int c = 0;
    NODE cur = head, nxt = NULL, p = NULL;
    while(cur!=NULL && c<k)             //Only next link is updated like a singly linked list
    {
        nxt  = cur->next;
        cur->next = p;
        p = cur;
        cur = nxt;
        c++;
    }
    if (nxt !=  NULL)
       head->next = reverse_in_groups(nxt, k);
    return p;
}

void display(NODE head)
{
    if(head==NULL)
        printf("Linked list is empty.\n");
    else
    {
        NODE cur = head;
        while(cur!=NULL)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
    }
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    NODE head = NULL;
    int n, k, m;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &m);
        head = insert_end(head, m);
    }
    head = reverse_in_groups(head, k);
    display(head);
    return 0;
}