/* Main.c:
Question: X institute is offering a course in M.S. in EmbeddedSystems. Course has total of 15 seats. 
Of the  15 seats,  10  seats  are  allotted  based  on the merit  list (rank  wise),  
3  seats  areunder management quotaand 2 seats under NRI quota (Theses are allotted by first come first serve basis). 
Students will apply for this course under the different quota. 
X institute will generate the list of students who have been admitted to the course.

Solution: Modifying question(to reduce number of inputs) by considering that there are 10 seats- 6 Merit, 2 NRI, 2 management. */

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"header.h"

int main()
{
	Student* s;
	s = initialise_students(9, 3, 3); // Assuming 9 students will apply for merit, 3 for NRI and 3 for Management
	assert(s->merit.t_size ==  9);
	assert(insert_stud_details(s,5,0)); //1merit
	assert(insert_stud_details(s,1,0)); //2merit
	assert(insert_stud_details(s,50,1)); //1nri
	assert(insert_stud_details(s,4,0)); //3merit
	assert(insert_stud_details(s,3,0)); //4merit
	assert(insert_stud_details(s,100,2)); //1mgmt
	assert(insert_stud_details(s,56,1)); //2nri
	assert(insert_stud_details(s,10,0)); //5merit
	assert(insert_stud_details(s,76,1)); //2nri
	assert(insert_stud_details(s,2,0)); //6merit
	assert(insert_stud_details(s,81,2)); //2mgt
	assert(insert_stud_details(s,8,0)); //7merit
	assert(insert_stud_details(s,90,2)); //3mgt
	assert(insert_stud_details(s,9,0)); //8merit
	assert(insert_stud_details(s,13,0)); //9merit
  
	assert(*(s->merit.rank) == 5);
  
	printf("Before sorting merit list:\n\n");
	display_details(s); 
  
	assert(sort_details(s));
	printf("\nAfter sorting merit list:\n\n");
  
	display_details(s);
  
	return 0;
}
