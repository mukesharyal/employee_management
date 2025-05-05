int authenticate(char *username, char *password) {
        if(strcmp("admin", username) == 0 && strcmp("admin@123", password) == 0)
        {
            return 0;
        }

        FILE* stream = fopen("employees.csv", "r");

        char line[1024];
        char us[20];
        char pass[20];
        char txt3[20];
        while (fgets(line, 1024, stream))
        {
            char* tmp = strdup(line);
            char* tmp1 = strdup(line);
            char* tmp2 = strdup(line);
            char* tmp3 = strdup(line);

            char* us = getfield(tmp, 5);
            char* pass = getfield(tmp1, 6);
            char* type = "";

            if(strcmp(us, username) == 0 && strcmp(pass, password) == 0)
            {
                type = getfield(tmp2, 7);
                myId = atoi(getfield(tmp3, 1));
                return atoi(type);
            }
        }

        printf("\n--- ERROR: Invalid username or password ---\n");
            return 4; // Authentication failed
    }

