int createaccount() {

    Employee newEmployee;
    newEmployee.id = numEmployees;

    printf("Enter employee name: ");
    while (scanf("%49s", newEmployee.name) != 1)
    {
        while (getchar() != '\n')
            ;
        printf("Invalid input. Please enter a valid employee name: ");
    }

    fflush(stdin);
    printf("Enter designation of Employee (1,2 or 3)\n");
    printf("1. Boss\n");
    printf("2. Administrative Head\n");
    printf("3. Officer\n");
    scanf("%d",&newEmployee.positionstatus);

    if(loggedInEmployeeId >= newEmployee.positionstatus)
    {
        printf("This user is not permitted to add that level of staff.\n");
    }
    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);

    printf("Enter employee age: ");
    scanf("%d", &newEmployee.age);
    printf("Create username for employee: ");
    scanf("%s",&newEmployee.username);
    printf("Create password: ");
    scanf("%s",&newEmployee.password);

    FILE* fp = fopen("employees.csv", "a");

    if(fp == NULL)
    {
        printf("The file is not opening!");
    }

    fprintf(fp, "%d,%s,%.1f,%d,%s,%s,%d|\n", newEmployee.id, newEmployee.name, newEmployee.salary, newEmployee.age, newEmployee.username, newEmployee.password, newEmployee.positionstatus);

    fclose(fp);

    numEmployees++;

    printf("Employee added successfully !\n");
}
