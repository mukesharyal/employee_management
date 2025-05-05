int num_employees()
{
    FILE* fp = fopen("employees.csv", "r");

    int ct = 0;

    char ch;

    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '|')
        {
            ct++;
        }
    }

    fclose(fp);

    return ct;
}
