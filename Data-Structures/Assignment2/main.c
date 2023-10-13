#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"student_details.h"
int main()
{
    Slist * test_list;
    Tlist * test_trans_list;
    
    Student test_stud1,test_stud2,test_stud3,test_stud4,test_stud5;
    
    test_stud1.student_id = 1;
    strcpy(test_stud1.student_name, "Radhika" );
    strcpy(test_stud1.course, "VLSI");
    
    test_stud2.student_id = 2;
    strcpy(test_stud2.student_name, "Vroon" );
    strcpy(test_stud2.course, "ES");
    
    test_stud3.student_id = 3;
    strcpy(test_stud3.student_name, "Takataka" );
    strcpy(test_stud3.course, "AIML");
    
    test_stud4.student_id = 4;
    strcpy(test_stud4.student_name, "Furfur" );
    strcpy(test_stud4.course, "BDA");
    
    test_stud5.student_id = 5;
    strcpy(test_stud5.student_name, "Dishoom" );
    strcpy(test_stud5.course, "DSA");
    
    test_list = initialise_new_student_list();
    test_trans_list = initialise_transaction_list();

    assert(test_list->tail == NULL && test_list->head == NULL && test_list->count == 0 );
    assert(test_trans_list->head == NULL);
    assert(test_trans_list->tail == NULL) ;
    assert(test_trans_list->count ==0 );
    
    assert(insert_student_details(test_list,test_stud1, test_trans_list));
    assert(test_trans_list->count==1 && test_trans_list->insert_count ==1);
    assert(insert_student_details(test_list,test_stud2, test_trans_list));
    assert(test_trans_list->count==2 && test_trans_list->insert_count ==2);
    assert(search_student(test_list,1));
    assert(delete_student_details(test_list,test_stud1, test_trans_list));
    assert(test_trans_list->count==3 && test_trans_list->insert_count ==2 && test_trans_list->delete_count == 1);
    test_list = deallocate_Slist(test_list);
    test_trans_list = deallocate_Tlist(test_trans_list);

    assert(test_list==NULL & test_trans_list == NULL);
    return 0;
    
}
