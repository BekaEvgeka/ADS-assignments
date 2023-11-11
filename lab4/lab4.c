#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
int swap_elements(node *head1, node *head2, char *element_to_swap1, char *element_to_swap2);
int find_change_value(node *head, char *str_to_change, char *change_element);
int swap_random_players(node *head1, node *head2, int n, int m);

int main()
{
    srand(time(NULL));
    node *head_of_list1;
    node *head_of_list2;
    int n;
    printf("How many elements in list 1?\n");
    scanf("%d", &n);
    head_of_list1 = create_list(n);
    display(head_of_list1);
    printf("How many elements in list 2?\n");
    int j;
    scanf("%d", &j);
    head_of_list2 = create_list(j);
    display(head_of_list2);
    // printf("Testing swap elements:\n--------------------------------------\n");


    // swap_elements(head_of_list1, head_of_list2, player, rear_player);
    int k = rand() % 5;
    char player_one[20];
    char player_two[20];
    int m;
    // n = rand() % n;
    // m = rand() % j;
    printf("Make %d change(s)\n", k);
    while(k != 0){
        scanf("%s", &player_one);
        scanf("%s", &player_two);
        swap_elements(head_of_list1, head_of_list2, player_one, player_two);
        display(head_of_list1);
        display(head_of_list2);
        k = k - 1;
        if (k!=0){

        printf("Swap another 2 players:\n");
        }
    }
    // while (k != 0){
    //     swap_random_players(head_of_list1, head_of_list2, n, m);
    //     k = k - 1;
    // }
    display(head_of_list1);
    display(head_of_list2);

}
node *create_list(int n)
{
    node *head, *prev, *p;
    int i;
    // printf("Enter number of elements in a list:");
    // scanf("%d", &n);
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
            // printf("Found element! %s", head->data);
            return 1;
        }
        else
        {
            find(head->next, to_find);
        }
    }
}
int swap_elements(node *head1, node *head2, char *element_to_swap1, char *element_to_swap2)
{

    if (((head1 == NULL) || (head2 == NULL)) || ((head1 == NULL) && (head2 == NULL)))
    {
        printf("One or two lists are empty");
    }
    else
    {   
        if ((find(head1, element_to_swap1) == 1) && ( find(head2, element_to_swap2) == 1)){
            find_change_value(head1, element_to_swap1, element_to_swap2);
            find_change_value(head2, element_to_swap2, element_to_swap1);
        }
        else{
            printf("Did not find one or two of the elements!\n");
        }
    }
}
int find_change_value(node *head, char *str_to_change, char *change_element)
{
    int compresult;
    if (head == NULL)
    {
        printf("Did not find specified player(s)!\n");
        return 0;
    }
    else
    {   
        compresult = strcmp(head->data, str_to_change);
        if (compresult == 0){
            // printf("Element found! Swapping...\n");

            strcpy(head->data, change_element);
        }
           else{
            find_change_value(head->next, str_to_change, change_element);
           }
        return 1; 
    }

}
int swap_random_players(node *head1, node *head2, int n, int m){
    char *player_to_swap;
    char *rear_player_to_swap;
    node *temp;
    temp = head1;
    if (head1 == NULL){
        printf("List 1 empty");
    }
    else{
        while(n != 0){
            temp = temp->next;
            n = n - 1;
        player_to_swap = temp->data;
        }
        printf("%s", player_to_swap);
    }
    temp = head2;
    if (head2 == NULL){
        printf("List 2 empty!");
    }
    else{
        while(m != 0){
            temp = temp->next;
            m = m - 1;
            rear_player_to_swap = temp->data;
        }
            printf("%s", rear_player_to_swap);
    }
    // printf("Swapping elements....\n");
    if( strcmp(player_to_swap, rear_player_to_swap) == 0){
        // printf("Stopped the swap beacause elements are identical");
        return 0;        
    }
    else
    {
        swap_elements(head2,head1, rear_player_to_swap, player_to_swap);
        // printf("Swapped %s for %s\n", player_to_swap, rear_player_to_swap);
        // swap_elements(head2, rear_player_to_swap, player_to_swap)
    }
    
}
