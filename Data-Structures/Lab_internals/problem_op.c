#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"header.h"

/* This function creates a new list and initialises the head. tail and count */
Participant_list* initialise_participant_list()
{
	Participant_list *new_list;
	new_list = (Participant_list*)malloc(sizeof(Participant_list));
	if(new_list == NULL) return NULL;

	new_list->head = new_list->tail = NULL;
	new_list-> count = new_list->beginner_count = new_list->intermediate_count = new_list->expert_count = 0;
	return new_list;
}

/*to create a new participant node Pnode*/
PNode* get_PNode(Participant new_data)
{
	PNode * new_node;
	new_node = (PNode*) malloc(sizeof(PNode));
	if(new_node == NULL) return ALLOC_FAIL;
	new_node->data = new_data;
	new_node->ptr = NULL;
}

/*to insert a new participant into the list*/
int insert_participant(Participant_list *my_list, Participant new_reg)
{
	PNode *new_node,*temp;
	new_node = get_PNode(new_reg);
	
	if(my_list->count == 0)
	{
		my_list->head = my_list->tail = new_node;
	}
	else
	{	
		for(temp = my_list->head;temp !=NULL;temp= temp->ptr)
		{
			if(temp->data.participant_id == new_reg.participant_id)
				return FAIL;
		}
		my_list->tail->ptr = new_node;
		my_list->tail = new_node;
	}
	my_list->count++;
	if(new_reg.level == beginner)my_list->beginner_count++;
	if(new_reg.level == intermediate)my_list->intermediate_count++;
	if(new_reg.level == expert)my_list->expert_count++;
	return SUCCESS;
}

/*to display the number of participants in each level*/ 
void count_all_level_registrations(Participant_list* my_list)
{
		printf("Total participants:%d\nNumber of beginners:%d\nNumber of intermediates:%d\nNumber of experts:%d\n",my_list->count,my_list->beginner_count, my_list->intermediate_count, my_list->expert_count);

}

/* to deallocate the memory of the entire list*/
Participant_list* deallocate_participant_list(Participant_list* my_list)
{
	PNode *temp;

	while(my_list->head->ptr != NULL)
	{
		//printf("temp1->data %d, head->data = %d\n", temp->data.participant_id, my_list->head->data.participant_id);
		temp = my_list->head;
		my_list->head = my_list->head->ptr;
		free(temp);
	}
	free(my_list);
	//assert(my_list == NULL);
	return NULL;
}
