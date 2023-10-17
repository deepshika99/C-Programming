/* File that has all the function definitions */
#include <stdio.h>
#include<stdlib.h>
#include"header.h"
/* initialise_students function allocates and initialises list of students who want to apply.
It needs the number of students who are applying for merit,nri and management each*/
Student* initialise_students(int merit_size, int nri_size, int mgmt_size)
{
	Student* list;
	
	list = (Student*)malloc(sizeof(Student));
	if (list == NULL) return NULL;
	
	list->merit.rank = (int*)malloc(sizeof(int) * merit_size);
	list->merit.c_size = 0;
	list->merit.t_size = merit_size;
	
	list->nri.rank = (int*)malloc(sizeof(int) * nri_size);
	list->nri.c_size = 0;
	list->nri.t_size = nri_size;
	
	list->mgmt.rank = (int*)malloc(sizeof(int) * mgmt_size);
	list->mgmt.c_size = 0;
	list->mgmt.t_size = mgmt_size;

	return list;

}
/* insert_stud_details function takes in rank and quota of the students applying. 
For merit, quota is 0. For NRI, quota is 1. For Management, quota is 2.*/ 
int insert_stud_details(Student* l1, int rank, int quota)
{
    if(quota == 0) // merit
    {
        if(l1->merit.c_size == l1->merit.t_size) return ARRAY_FULL;
        *(l1->merit.rank + l1->merit.c_size) = rank;
        l1->merit.c_size++;
    }
    
    if(quota == 1) //nri
    {
        if(l1->nri.c_size == l1->nri.t_size) return ARRAY_FULL;
        *(l1->nri.rank + l1->nri.c_size) = rank;
        l1->nri.c_size++;
    }
    
    if(quota == 2) //mgmt
    {
        if(l1->mgmt.c_size == l1->mgmt.t_size) return ARRAY_FULL;
        *(l1->mgmt.rank + l1->mgmt.c_size) = rank;
        l1->mgmt.c_size++;
    }
    
    return SUCCESS;
}
/* sort_details function is to sort only first 6 merit quota students in ascending order using bubble sort*/
int sort_details(Student* s)
{
    for(int i = 0 ;i < 5 ; i++)
    {
        for(int j = 0 ;j < 5-i ; j++)
        {
            if(*(s->merit.rank + j) > *(s->merit.rank + j + 1))
            {
                int temp = *(s->merit.rank + j + 1);
                *(s->merit.rank + j + 1) = *(s->merit.rank + j);
                *(s->merit.rank + j) = temp;
                
            }
        }
        
    }
    return SUCCESS;
}
/* display_details function displays the students who are admitted with their rank number under the quota they applied for */
void display_details(Student * s)
{
    printf("Merit:\n\n");
    for(int i=0; i<6;i++)
    printf("Rank:%d\n", *(s->merit.rank +i));
    printf("\nNRI:\n\n");
    for(int i=0; i<2;i++)
    printf("Rank:%d\n", *(s->nri.rank +i)); 
    printf("\nManagement:\n\n");
    for(int i=0; i<2;i++)
    printf("Rank:%d\n", *(s->mgmt.rank +i)); 
    
}
