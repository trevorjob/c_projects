#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
        // A NODE IS BASICALLY A STRUCT WITH A POINTER POINTING TO ANOTHER STRUCT
        int data;
        struct node* next;
}node_t;
void display();
void insertAtBegining(node_t** head, int new_data);
void insertAtEnd(node_t** head, int new_data);
void insertPreviousNode(node_t* prevNode, int new_data);
void deleteFirstNode(node_t** head);
void deleteLastNode(node_t** head);
void deleteAtPosition(node_t** head, int data);
int main(void)
{
        // THE HEAD IS THE POINTER TO THE VERY FIRST NODE IN THE INKED LIST
        node_t* head;

        // STRUCT DECLARATIONS
        node_t* first;
        node_t* second;
        node_t* third;
        node_t* fourth;
        // ALLOCATION OF SPACES FOR EACH NODE
        first = (node_t*)malloc(sizeof(node_t));
        second = (node_t*)malloc(sizeof(node_t));
        third = (node_t*)malloc(sizeof(node_t));
        fourth = (node_t*)malloc(sizeof(node_t));
        
        // INITIALIZING EACH NODE
        first->data = 10;
        second->data = 50;
        third->data = 60;
        fourth->data = 90;

        // LINKING THE NODES TOGETHER
        head = first;
        first->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = NULL; 

        // PRINT OUT THE DATA FROM EACH NODE IN THE LINKED LIST
        display(head);

        // INSERT A NEW NODE TO THE BEGINING OF THE LIST
        insertAtBegining(&head, 20);
        insertAtBegining(&head, 100);
        insertAtBegining(&head, 2);
        // PRINT OUT THE DATA FROM EACH NODE IN THE LINKED LIST
        display(head);


        // INSERT A NEW NODE TO THE END OF THE LIST
        insertAtEnd(&head, 20);
        insertAtEnd(&head, 100);
        insertAtEnd(&head, 2);
        // PRINT OUT THE DATA FROM EACH NODE IN THE LINKED LIST
        display(head);


        // INSERT A NEW NODE AFTER A SPECIFIED NODE IN THE LIST
        insertPreviousNode(second, 20);
        insertPreviousNode(second, 100);
        insertPreviousNode(second, 2);
        // PRINT OUT THE DATA FROM EACH NODE IN THE LINKED LIST
        display(head);

        // DELETE THE FIRST NODE IN THE LIST
        deleteFirstNode(&head);
        deleteFirstNode(&head);
        deleteFirstNode(&head);
        // PRINT OUT THE DATA FROM EACH NODE IN THE LINKED LIST
        display(head);

        // DELETE THE LAST NODE IN THE LIST
        deleteLastNode(&head);
        deleteLastNode(&head);
        deleteLastNode(&head);
        // PRINT OUT THE DATA FROM EACH NODE IN THE LINKED LIST
        display(head);

        // DELETE A NODE AT A POSITION
        deleteAtPosition(&head, 2);
        deleteAtPosition(&head, 100);
        deleteAtPosition(&head, 20);
        display(head);
        return (0);
}
void display(node_t* ptr)
{
        // PRINTIG ALL NODE LIST DATA
        printf("linked list elements are: ");
        while (ptr != NULL)
        {
                printf("%d ",ptr->data);
                ptr = ptr->next;
        }
        printf("\n");
        
}

void insertAtBegining(node_t** head, int new_data)
{
        // ALLOCATE SPACE FOR TEMPORARY NODE
        node_t *temp = (node_t*)malloc(sizeof(node_t));
        if (*head == NULL)
        {
                return;
        }
        
        // TEMP->NEXT IS A POINTER POINTING TO THE SAME POINTER THE HEAD IS POINTING TO
        // IN THAT CASE TEMP->NEXT IS POINTING TO THE FIRST ELEMENT IN THE LINKED LIST BECAUSE THE HEAD ALWAYS POINTS TO THE FIST NODE
        temp->next = *head;
        temp->data = new_data;
        // NOW CHANGE THE HEAD TO POINT TO THE NEW NODE THAT IS CREATED MAKING IT THE FIRST NODE
        *head = temp;
        return;
}

void insertAtEnd(node_t** head, int new_data)
{
        // CREATE TEMPORARY NODE TO TRAVERSE THE WHOLE LIST
        // IT IS ADVISED THAT YOU DO NOT TRAVERSE THE LIST WITH THE HEAD POINTER
        // CREATE A TEMPORARY NODE AND SAVE THE VALUE OF THE HEAD NODE IN IT
        node_t *temp = *head;

        // LAST WILL BE THE LAST NODE THAT WILL BE ADDED 
        node_t *last = (node_t*)malloc(sizeof(node_t));
        last->data = new_data;
        // SINCE LAST WILL BE THE LAST NODE IN THE LIST IT HAS TO BE SET TO NULL
        last->next = NULL;
        if (*head == NULL)
        {
                *head = last;
                return;
        }

        // LOOP TO THE CURRENT END OF THE LIST
        while (temp->next != NULL)
        {
                temp = temp->next;
        }
        // CHANGE THE CURRENT LAST NODE POINTER (TEMP->NEXT) IN THE LIST TO POINT TO THE NEW NODE THAT WAS JUST CREATED (LAST)
        temp->next = last;
        return;
}
void insertPreviousNode(node_t* prevNode, int new_data)
{
        if (prevNode == NULL)
        {
                return;
        }
        // ALLOCATE SPACE FOR NEW NODE
        node_t *new = (node_t*)malloc(sizeof(node_t));

        // THE NEW NODE POINTER WIL POINT TO THE SAME POINTER PREVNODE POINTER POINTS TP
        new->next = prevNode->next;
        new->data = new_data;
        // WHILE PREVENODE POINTER WILL POINT TO THE NEW NODE
        prevNode->next = new;
        
} 

void deleteFirstNode(node_t** head)
{
        if (*head == NULL)
        {
                return;
        }
        // DELETING THE VERY FIRST NODE
        
        // CREATE TEMPORARY NODE
        node_t *temp;
        
        // TEMP POINTS TO THE FIRST ELEMENT
        temp = *head;
        // HEAD POINTS TO THE SAME POINTER THAT THE FIRST ELEMENT POINTS TO WICH IS THE SECOND NODE
        // MAKING THE SECOND NODE THE FIRST NODE AND REMOVING THE FIRST NODE FROM THE LIST
        *head = temp->next;

        // DELETE THE FIRST NODE
        free(temp);

}
void deleteLastNode(node_t** head)
{
        // DELETING THE LAST NODE
        if (*head == NULL)
        {
                return;
        }

        // CREATE 2 TEMPORARAY NODES
        node_t *temp;
        node_t *temp2;

        // FIRST TEMPORARY NODE POINTS TO THE SAME POINTER AS THE HEAD
        temp = *head;

        if (temp->next == NULL)
        {
                *head = NULL;
        }
        
        // LOOP TO THE CURRENT END OF THE LIST
        while (temp->next != NULL)
        {
                temp2 = temp;
                temp = temp->next;
                // BY PUTTING THESE 2 NODES LIKE THIS TEMP WILL CONTAIN THE LAST NODE
                // WHILE TEMP2 WILL CONTAIN THE SECOND TO LAST NODE
                // EG. IF THERE ARE 10 NODES IN THE LIST AT THE END OF THIS LOOP TEMP WILL EQUAL TO NODE NUMBER 10
                // WHILE TEMP2 WILL EQUAL TO NODE NUMBER 9
        }
        // DELETE THE LAST NODE
        free(temp);
        // AND MAKE THE SECOND TO LAST NODE POINT TO NULL MAKING IT THE NEW LAST NODE
        temp2->next = NULL;
}


void deleteAtPosition(node_t** head, int data)
{
        if (*head == NULL)
        {
                return;
        }

        // CREATE 2 TEMPORARAY NODES
        node_t *temp;
        node_t *temp2;

        // FIRST TEMPORARY NODE POINTS TO THE SAME POINTER AS THE HEAD
        temp = *head;        

        // LOOP TO THE CURRENT END OF THE LIST
        while (temp->next != NULL)
        {
                // CHECK IF THE DATA IN CURRENT NODE IS SAME AS THE DATA PARAMETER
                if (temp->data == data)
                {
                        break;
                }

                temp2 = temp;
                temp =  temp->next;
                // CURRENTY TEMP2 WILL EQUAL TO TEMP WHICH IS THE NODE TO BE DELETED 
                // TEMP WILL EQUAL TO THE NEXT NODE
                
        }
        // THE PREVIOUS NODE (TEMP2) WILL POINT TO THE NODE AFTER THE ONE TO BE DELETED (TEMP->NEXT)
        // NOTE TEMP IS THE CURRENT NODE TO BE DELETED
        temp2->next = temp->next;
        // DELETE THE NODE
        free(temp);
}