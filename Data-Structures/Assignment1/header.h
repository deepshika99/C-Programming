/*Header File for structures and function prototypes */

#define ARRAY_FULL 0
#define SUCCESS 1
//structure to contain an array of ranks(integer values) current size and total size of the array
struct _quota 
{
	int* rank;
	int c_size, t_size;
};
typedef struct _quota Quota;
// structure to contain rank details of all students according to what quota they want to apply for
struct _student_
{
	Quota merit;
	Quota nri;
	Quota mgmt;
};
typedef struct _student_ Student;


Student* initialise_students(int, int, int); 
int insert_stud_details(Student*,int, int);
int sort_details(Student*);
void display_details(Student*);
