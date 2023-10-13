#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include"student_details.h"


Slist * initialise_new_student_list()
{
    Slist * new_list;
    new_list = (Slist *) malloc(sizeof(Slist));
    
    if(new_list == NULL) return NULL;
    
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->count = 0;
    return new_list;
}
Tlist * initialise_transaction_list()
{
    Tlist * new_list;
    new_list = (Tlist *) malloc(sizeof(Tlist));
    
    if(new_list == NULL) return NULL;
    
    new_list->head = new_list->tail = NULL;
    new_list->count = 0;
    new_list->insert_count =0;
    new_list ->delete_count = 0;
    return new_list;
}
SNode *get_snode(Student data)
{
    SNode *new_node;

    new_node = (SNode *)malloc(sizeof(SNode));
    if(new_node == NULL) return NULL;

    new_node->data = data;
    new_node->ptr = NULL;

    return new_node;
}
int insert_student_details(Slist * my_list, Student data, Tlist * my_tlist)
{
    SNode *new_node;
    Transaction new_trans;
    new_trans.type_of_op = 1;
    strcpy(new_trans.trans_date, "10-10-1999");
    strcpy(new_trans.trans_time, "9:45");
    new_node = get_snode(data); 
    if(new_node == NULL) return 0; 

    if(my_list->count == 0) 
        my_list->head = my_list->tail = new_node; 
    else{
        new_node->ptr = my_list->head; 
        my_list->head = new_node; 
    }
    my_list->count++; 
    insert_transaction(my_tlist, new_trans);
    
    return 1;
}
TNode *get_tnode(Transaction data)
{
    TNode *new_node;

    new_node = (TNode *)malloc(sizeof(TNode));
    if(new_node == NULL) return NULL;

    new_node->data = data;
    new_node->ptr = NULL;

    return new_node;
}
void insert_transaction(Tlist* my_trans_list, Transaction new_trans)
{
    TNode *new_node;

    new_node = get_tnode(new_trans); 

    if(my_trans_list->count == 0) 
        my_trans_list->head = my_trans_list->tail = new_node; 
    else{
        new_node->ptr = my_trans_list->head; 
        my_trans_list->head = new_node; 
    }
    my_trans_list->count++; 
    if(new_trans.type_of_op == 1) my_trans_list->insert_count++;
    if(new_trans.type_of_op == 2) my_trans_list->delete_count++;
}
int delete_student_details(Slist * my_list, Student data, Tlist * my_trans_list)
{
    SNode *curr_node;
	SNode *prev_node;
	Transaction new_trans={2, "10-40", "11-10-2000"};

	if(my_list == NULL)
		return 0;

	for(prev_node = NULL, curr_node = my_list->head; curr_node != NULL;\
	prev_node = curr_node, curr_node = curr_node->ptr)
	{
		if(curr_node->data.student_id   == data.student_id)
		{
			if(my_list->count == 1)
			{
				my_list->head = NULL;
				my_list->tail = NULL;
			}
			else if(curr_node == my_list->head)
			{

				my_list->head = my_list->head->ptr;
			}
			else if(curr_node == my_list->tail)
			{
				prev_node->ptr = NULL;
				my_list->tail = prev_node;
			}
			else
			{
				prev_node->ptr = curr_node->ptr;
			}

			free(curr_node);
			my_list->count --;

			
            insert_transaction(my_trans_list,new_trans);

			return 1;
		}

	}

	return 0;

}
int search_student(Slist * my_list, int stud_id)
{
	SNode *temp;

	if(my_list == NULL)
		return 0;

	for(temp = my_list->head; temp != NULL; temp = temp->ptr){
		if(temp->data.student_id == stud_id)
			return 1;
	}

	return 0;
}




Tlist* deallocate_Tlist(Tlist* my_trans_list)
{
    TNode *temp2;

        while(my_trans_list->head != NULL)
        {
            temp2 = my_trans_list->head;
            my_trans_list->head = my_trans_list->head->ptr;
            free(temp2);
        }
        free(my_trans_list);

        return NULL;
}

Slist * deallocate_Slist(Slist *my_list)
{
    SNode *temp;


        while(my_list->head != NULL)
        {
            temp = my_list->head;
            my_list->head = my_list->head->ptr;
            free(temp);
        }

        free(my_list);

        return NULL;
}
