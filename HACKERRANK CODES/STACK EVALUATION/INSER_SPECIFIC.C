SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) 
{
    SinglyLinkedListNode* temp = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    if(llist == NULL)
    {
        llist->data = data;
        llist->next = NULL;
        return llist;
    }
    else
    {
        if(position == 0)
        {
            temp->data = data;
            temp->next = llist;
            return temp;
        }
        else
        {   
            SinglyLinkedListNode* prev = llist;
            temp->data = data;
            for(int i =0;i<position-1;i++)
            {
            prev = prev->next;
            }
            temp->next= prev->next;
            prev->next = temp;
        }
    }
    return llist;
}