#define ALLOC_FAIL NULL
#define FAIL 0
#define SUCCESS 1
#define MAX_SIZE 25

typedef enum 
{
	beginner =1, intermediate, expert
}levels;

/*structure to define the participants' details */
typedef struct _participant 
{
	char name[MAX_SIZE];
	int participant_id;
	levels level; //1 for beginner, 2 for intermediate, 3 for expert
}Participant;

/*struct to define the nodes containing data and pointer to next node*/
struct node 
{
	Participant data;
	struct node *ptr;
};
typedef struct node PNode;

/*Linked list of all the participants*/
typedef struct _list
{
	PNode *head, *tail;
	int count, beginner_count, intermediate_count, expert_count;
}Participant_list;


Participant_list* initialise_participant_list();
int insert_participant(Participant_list*, Participant);
void count_all_level_registrations(Participant_list*);
Participant_list* deallocate_participant_list(Participant_list*);
