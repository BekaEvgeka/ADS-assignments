#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define name_len 20

typedef struct node
{
    char data[name_len];
    int id;
    struct node *next;
} node;


int display(node *head);
node *create_list();
int find(node *head, char *to_find);
int swap_elements(node *head1, node *head2, int element_to_swap1, int element_to_swap2);
int find_change_value(node *head, int id_to_change, int change_to);


int main()
{
    node *head_of_list1;
    node *head_of_list2;
    head_of_list1 = create_list();
    display(head_of_list1);
    head_of_list2 = create_list();
    display(head_of_list2);
    printf("Testing swap elements:\n--------------------------------------\n");

    char player[name_len] = "kurenov";
    char rear_player[name_len] = "keshishev";
    swap_elements(head_of_list1, head_of_list2, 0, 1);
    display(head_of_list1);
    display(head_of_list2);

}
node *create_list()
{
    node *head, *prev, *p;
    int i, n;
    printf("Enter number of elements in a list:");
    scanf("%d", &n);
    head = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(node));
        scanf("%s", &p->data);
        p->id = i;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            prev->next = p;
        }
        prev = p;
    }
    return head;
}
int display(node *head)
{
    if (head == NULL)
    {
        printf("List iterated\n");
        return 0;
    }
    else
    {
        printf("element: %s, ID: %d\n", head->data, head->id);

        display(head->next);
        return 0;
    }
}
int find(node *head, char *to_find)
{
    int compresult;
    if (head == NULL)
    {
        printf("Didn`t find anyhting\n");
        return 0;
    }
    else
    {
        compresult = strcmp(head->data, to_find);
        if (compresult == 0)
        {
            printf("Found element! %s", head->data);
            return 0;
        }
        else
        {
            find(head->next, to_find);
        }

        return 0;
    }
}
int swap_elements(node *head1, node *head2, int element_to_swap1, int element_to_swap2)
{

    if (((head1 == NULL) || (head2 == NULL)) || ((head1 == NULL) && (head2 == NULL)))
    {
        printf("One or two lists are empty");
    }
    else
    {
        find_change_value(head1, element_to_swap1, element_to_swap2);
        find_change_value(head2, element_to_swap2, element_to_swap1);
    }
}
int find_change_value(node *head, int id_to_change, int change_to)
{

    if (head == NULL)
    {
        printf("Did not find specified player(s)!\n");
        return 0;
    }
    else
    {   
        if (id_to_change - change_to == 0){
            printf("Element found! Swapping...\n");

            head->id = change_to;
        }
           else{
            find_change_value(head->next, id_to_change, change_to);
           } 
    }

}