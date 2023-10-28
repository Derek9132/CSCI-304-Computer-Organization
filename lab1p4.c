#include <string.h>
#include <stdio.h>
#include <stdlib.h>



struct Node
{
  char *data;
  struct Node *next;
};

typedef struct Node node;


struct Linked_List
{
  node *header;
};



void insertAtBeginning(struct Linked_List *LL, char ele[])
{
    if (findNode(LL, ele) == 1 && LL->header != NULL)
    {
      deleteNode(LL, ele);
    }
    else
    {
      struct Node *new_node = malloc(sizeof(node));
      int len = strlen(ele);
      char *to_add;
      to_add = (char*) malloc((len+1)*sizeof(char));
      strcpy(to_add, ele);
      new_node->data = to_add;
      new_node->next = LL->header;
      LL->header = new_node;
    }
}

void insertAtTheEnd(struct Linked_List *LL, char ele[])
{
    if (LL->header == NULL)
    {
        insertAtBeginning(LL, ele);
    }
    else
    {
      if (findNode(LL, ele) == 1 && LL->header != NULL)
      {
          deleteNode(LL, ele);
      }
      else
      {
        struct Node *new_node = malloc(sizeof(node));
        int len = strlen(ele);
        char *to_add;
        to_add = (char*) malloc((len+1)*sizeof(char));
        strcpy(to_add, ele);
        new_node->data = to_add;
        new_node->next = NULL;
        node *traverse_ptr = LL->header;
        while (traverse_ptr->next != NULL)
        {
          traverse_ptr = traverse_ptr->next;
        }
        traverse_ptr->next = new_node;
      }
    }
}


void displayLinkedList(struct Linked_List *LL)
{
    printf("The list:- ");
    node *traverse_ptr = LL->header;
    while (traverse_ptr->next != NULL)
    {
      printf("%s, ", traverse_ptr->data);
      traverse_ptr = traverse_ptr->next;
    }
    printf("%s", traverse_ptr->data);
    printf("\n");
}

void deleteNode(struct Linked_List* LL, char ele[])
{
    node *traverse_ptr = LL->header;
    if (strcmp(ele, traverse_ptr->data) == 0)
    {
        LL->header = LL->header->next;
    }
    else
    {
      while (traverse_ptr != NULL)
      {
          if (strcmp(ele, traverse_ptr->next->data) == 0)
          {
              traverse_ptr->next = traverse_ptr->next->next;
              break;
          }
          else
          {
              traverse_ptr = traverse_ptr->next;
          }
      }
    }
}


int findNode(struct Linked_List *LL, char ele[])
{
    node *traverse_ptr = LL->header;
    while (traverse_ptr != NULL)
    {
        if (strcmp(ele, traverse_ptr->data) == 0)
        {
            return 1;
            break;
        }
        else
        {
            traverse_ptr = traverse_ptr->next;
        }
    }
    return 0;
}


int main(int argc, char *argv[])
{
    struct Linked_List LL;
    LL.header = NULL;
    int i = 0;
    for (i = 1; i < argc; i++)
    {
        char *first = argv[i];
        if (isupper(*first) == 1)
        {
            insertAtBeginning(&LL, argv[i]);
        }
        if (isupper(*first) == 0)
        {
            insertAtTheEnd(&LL, argv[i]);
        }
    }
    displayLinkedList(&LL);
    return 0;
}






