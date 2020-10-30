/*
The data structure I have used is an array of the structure "list" and a singly linked list.Each element of the array of 
strutures points to a linked list.Each linked list can be considered to be at a different level with respect to the array index it starts at.
In the find_Second_greatest() function we iterate through the array of numbers. A node is created for each element and it is inserted into its correct position
and at the correct position. Then the merge_lists() function is called to check whether a list needs to be pushed or if two lists are at the same level,
the max elements of each list are compared and they are merged accordingly. Any unwanted nodes are freed as to avoid wasting space.
After we iterate through the whole input array, we call the merge_lists() function again to make sure all remaining lists are compared and accordingly merged.
The above case occurs when the input size is not a power of 2. 
Also whwnever a comparison is made, the program prints it in the required format.
When we have the final list, we know that the head is the max element so we start checking from the head->next element.And we also know that the final list starts at the last index always.
Using a while loop we find the second largest element and after that display it.
*/


#include<stdlib.h>
#include<stdio.h>
#include "assignment_2.h"

typedef struct node //Node structure to create a node for each value for the array
{
    int data;
    struct node* next;    
}node;

typedef struct list //List struture with head and tail for the list
{
    node* head;
    node* tail;
}list;

node* create_node(int key) //Helps create a new node for every element
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = key;
    new_node->next = NULL;
    return new_node;
}

void print(list* list) //Prints the list from the given node
{
    node* temp = list->head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void merge_lists(list* l,int n, int cur_iteration, int len) //Checks whether two lists of the same level exist. If yes then the function compares the max elements in each and merges them.
{
    for(int i=0 ; i<n-1 ; i++)
    {
        if(l[i].head != NULL && l[i+1].head == NULL) //If no list of the same level exists then push it to the next level.
        {
            l[i+1] = l[i];
            l[i].head = l[i].tail = NULL;
            if(cur_iteration <= len) //To prevent current list to be be pushed to the last level
                break;
        }
        else if(l[i].head != NULL && l[i+1].head != NULL) //If two lists exist at the same level then compare the max elements in each and merge
        {
            print(&l[i+1]);
            printf("x ");
            print(&l[i]);

            if(l[i].head->data > l[i+1].head->data) //Merge max element of next list into current
            { 
                node* temp = l[i+1].head->next;
                while(temp) //Free unwanted nodes
                {   
                    node* temp_copy = temp;
                    temp = temp->next;
                    free(temp_copy);
                }
                l[i+1].tail = l[i+1].head;
                l[i+1].head->next = NULL;
                l[i+1].head->next = l[i].head->next;
                node* curr = l[i+1].head->next;
                while(curr)
                    curr = curr->next;
                l[i+1].tail = curr;
                l[i].head->next = l[i+1].head;
                l[i+1].head = l[i].head;
                l[i].head = l[i].tail = NULL;
            }
            else //Merge max element of current list into next
            {
                node* temp = l[i].head->next;
                while(temp) //Free unwanted nodes
                {   
                    node* temp_copy = temp;
                    temp = temp->next;
                    free(temp_copy);
                }
                l[i].head->next = l[i+1].head->next;
                l[i+1].head->next = l[i].head;
                l[i].head = l[i].tail = NULL;
            }
            printf("= ");
            print(&l[i+1]);
            printf("\n");
        }
    }
}

void find_second_greatest(int *numbers, int length)
{   
    int curr_iteration = 0; //Helps to prevent current list to be be pushed to the last level
    int n = length;
    int size; //Stores the depth/level of the list by finding log to the base 2 of the array size
    while(n>1)
    {
        ++size;
        n /= 2;
    }
    list l[++size];
    for(int i=0 ; i<size ; i++) //Inintially list is empty so set all the heads to NULL
        l[i].head = NULL;
    
    for(int i=0 ; i<length ; i++) //Iterate throught the array
    {  
        ++curr_iteration;
        node* new_node = create_node(numbers[i]); //Create node for element

        if(l[0].head == NULL) //If no numbers exist for comparison
            l[0].head = l[0].tail = new_node;
        else
        {
            printf("%d x %d ",l[0].head->data,numbers[i]);
            if(l[0].head->data < numbers[i]) //Inserting in front
            {
                node* temp = new_node;
                temp->next = l[0].head;
                l[0].head = temp;
                while(temp)
                    temp = temp->next;
                l[0].tail = temp;    
            }
            else //Inserting at the end
            {
                l[0].tail->next = new_node;
                l[0].tail = new_node;
            }   
                
            printf("= %d %d",l[0].head->data,l[0].head->next->data);
            printf("\n");
            merge_lists(l,size,curr_iteration,length); //Calls merge_list to check if any lists need to be merged or pushed ahead
        }
    }

    ++curr_iteration;
    merge_lists(l,size,curr_iteration,length); //For inputs which are not powers of two, multiple lists might exist after traversing through the whole array of numbers. This call compares and merges any such remaining lists
    node* temp = l[size-1].head->next; //As the first node is the max, we start from the next node
    int second_largest = temp->data;
    while(temp) //Finds the second largest element
    {
        if(temp->data > second_largest)
            second_largest = temp->data;
        temp = temp->next;
    }
    printf("\n%d",second_largest);
}