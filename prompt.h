int prompt()
{
    int choice;

    do {
        printf("--- Employee Portal ---\n");
        printf("1. Login\n");
        printf("2. Create account\n");
        printf("3. Display Employees\n");
        printf("4. Create Task\n");
        printf("5. Display Tasks\n");
        printf("6. Submit Completed Task\n");
        printf("7: Log Out\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (loggedInEmployeeId == 4) {
                    char username[50], password[50];
                    printf("Enter username: ");
                    scanf("%s", username);
                    printf("Enter password: ");
                    scanf("%s", password);

                loggedInEmployeeId = authenticate(username, password);

                }
                else {
                    printf("\n--- You are already logged in. ---\n\n");
                }
                break;
            }

            case 2: {
                if (loggedInEmployeeId <= 2) {
                    createaccount();
                }
                else {
                    printf("\n--- This user doesn't have enough privileges to create accounts. ---\n\n");
                }
                break;
            }

            case 3:
                if (loggedInEmployeeId == 0) {
                    displayEmployees();
                    break;
                } else {
                    printf("\n--- Only the admin is allowed to see this information. ---\n\n");
                }
                break;

            case 4:
                if (loggedInEmployeeId <= 2) {
                    createTask();
                    break;
                } else {
                    printf("\n--- This user doesn't have enough privileges to create tasks. ---\n\n");
                }
                break;

            case 5:
                if (loggedInEmployeeId <= 3)
                {
                    displayTasks();
                    break;

                }
                else{
                    printf("\n--- Only logged staff are authorized to view tasks. ---\n\n");
                    break;
                }

            case 6:
            if (loggedInEmployeeId >= 2){
                submitTask();
            }
            else{
                printf("\n--- Not applicable for this user! ---\n\n");
            }
            break;

            case 7:
                printf("\n--- Logging out... ---\n\n");
                loggedInEmployeeId =  4;
                prompt();

            case 8:
            printf("\n--- Exiting program... ---\n\n");
            exit(0);

            default:
                printf("\n--- Invalid choice. Please try again. ---\n\n");
                break;
        }
    } while (choice != 8);
}
