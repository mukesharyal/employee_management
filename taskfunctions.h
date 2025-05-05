void createTask() {
    Task newTask;
    newTask.taskId = numTasks;

    fflush(stdin);

    printf("Enter task description: ");
    gets(newTask.description);

    printf("Who is the task for? (1 or 2)\n");
    printf("1. Administrative Head\n");
    printf("2. Officer\n");
    scanf("%d", &newTask.taskFor);

    FILE* fp = fopen("tasks.csv", "a");

    if(fp == NULL)
    {
        printf("The file is not opening!");
    }

    fprintf(fp, "%d,%s,%d|\n",newTask.taskId, newTask.description, (newTask.taskFor+1));

    fclose(fp);

    printf("Task created successfully.\n");
    numTasks++;
  }


void displayEmployees() {

  FILE* stream = fopen("employees.csv", "r");

    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* token = strtok(line, ",|");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
        printf(" %s", token);
        token = strtok(NULL, ",|");
    }
    }
}

void displayTasks() {

  FILE* stream = fopen("tasks.csv", "r");

    char line[1024];
    while (fgets(line, 1024, stream))
    {
        // If the task is not meant for the user with a certain privilege, it shouldn't be shown to the user
        char* tmp = strdup(line);
        int taskFor = atoi(getfield(tmp, 3));
        if(taskFor != loggedInEmployeeId && loggedInEmployeeId != 0)
        {
            continue;
        }


        char* token = strtok(line, ",|");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
        printf(" %s", token);
        token = strtok(NULL, ",|");
    }
    }

    fclose(stream);
}


void submitTask()
{
    int task_id;
    displayTasks();

    printf("Select the id of the task to be submitted: ");
    scanf("%d", &task_id);

    FILE* fp = fopen("submitted_tasks.csv", "r");

    if(fp == NULL)
    {
        printf("The file is not opening!");
    }

    char line[1024];
    while (fgets(line, 1024, fp))
    {
        // If the task has already been submitted by the user, it shouldn't be able to be submitted again.
        char* tmp = strdup(line);
        char* tmp1 = strdup(line);

        int taskId = atoi(getfield(tmp, 1));
        int submitterId = atoi(getfield(tmp1, 2));

        if(taskId == task_id && submitterId == myId)
        {
            printf("The task has already been submitted by you!\n");
            fclose(fp);
            prompt();
        }
    }

    fclose(fp);

    FILE* filep = fopen("submitted_tasks.csv", "a");

    fprintf(fp, "%d,%d|\n",task_id, myId);

    fclose(fp);

    printf("Task submitted successfully.\n");
}


