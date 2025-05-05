// Definitions and structs...
typedef struct {
    int id;
    char name[50];
    float salary;
    int age;
    int nTasks;
    char username[50];
    char password[50];
    int positionstatus;
}Employee;

typedef struct
{
    int taskId;
    char description[100];
    int taskFor;
}Task;

int numEmployees = 0;
int numTasks = 0;
int loggedInEmployeeId = 4; // To keep track of the currently logged-in employee ID
int myId;

//Employee employees[MAX_EMPLOYEES];
//Task tasks[MAX_TASKS];
