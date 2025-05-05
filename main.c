#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "num_tasks.h"
#include "definitions.h"
#include "extract_employees.h"
#include "authenticate.h"
#include "create_account.h"
#include "prompt.h"
#include"taskfunctions.h"


int main() {

    numEmployees = num_employees();
    numTasks = num_tasks();

    prompt();
}
