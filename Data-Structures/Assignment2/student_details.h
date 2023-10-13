/***************************************************************************************
    Write a program to store student details in a data structure. 
    Carry out transactions like insert, delete, and search an employee. 
    For every transaction conducted, store the log details like type_of_operation, 
    transaction_time, and transactions_date in a separate data structure. 
    Count the number of insert and delete transactions that took place. Deallocate all the memory allocated dynamically. 
    (Solve the above problem using a linked list)
*****************************************************************************************/
#define MAX_SIZE 25
typedef struct _stud_
{
    int student_id;
    char student_name[MAX_SIZE];
    char course[MAX_SIZE];
    
}Student;

struct _node
{
    Student data;
    struct _node *ptr;
};
typedef struct _node SNode;

typedef struct _list
{
    SNode * head, *tail; 
    int count;
}Slist;

typedef struct _trans
{
    int type_of_op; //1 if insert, 2 if delete
    char trans_time[5];
    char trans_date[11]; //ddmmyyyy
}Transaction;

struct _trans_node
{
    Transaction data;
    struct _trans_node *ptr;
};
typedef struct _trans_node TNode;

typedef struct _trans_list
{
    TNode *head, *tail;
    int count;
    int insert_count, delete_count;
}Tlist;

Slist * initialise_new_student_list();
Tlist * initialise_transaction_list();

int insert_student_details(Slist *, Student, Tlist *);
void insert_transaction(Tlist*, Transaction);
int delete_student_details(Slist *, Student, Tlist *);
int search_student(Slist *, int);
Slist* deallocate_Slist(Slist *);
Tlist* deallocate_Tlist(Tlist *);
