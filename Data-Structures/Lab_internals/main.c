#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"header.h"

int main()
{
	Participant_list *test_list;
	Participant p1 = {"Meera",1,beginner};
	Participant p2 = {"Jaya",2,intermediate};
	Participant p3 = {"Cookie",3,expert};
	Participant p4 = {"Rekssha",4,beginner};
	Participant p5 = {"Sushma", 4,2};

	test_list = initialise_participant_list();
	assert(test_list->head == NULL && test_list->tail == NULL);
	assert(test_list->count == 0 && test_list->beginner_count == 0 && test_list->intermediate_count == 0 && test_list->expert_count == 0);

	assert(insert_participant(test_list,p1));
	assert(insert_participant(test_list,p2));
	assert(insert_participant(test_list,p3));
	assert(insert_participant(test_list,p4));
	assert(!insert_participant(test_list,p5));
	count_all_level_registrations(test_list);
	assert(test_list->head->data.participant_id == 1 && test_list->tail->data.participant_id == 4);
	assert(test_list->count == 4 && test_list->beginner_count == 2);

	count_all_level_registrations(test_list);
	test_list = deallocate_participant_list(test_list);
	//assert(test_list->head == NULL);
	assert(test_list == NULL);

	return 0;
}
