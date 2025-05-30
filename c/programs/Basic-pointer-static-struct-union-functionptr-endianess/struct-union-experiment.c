#include <stdio.h>
#include <string.h>

typedef enum job_type
{
    EMPLOYEE_FULL_TIME,
    EMPLOYEE_PART_TIME,
    EMPLOYEE_INTERN
} JOB_TYPE;

union salary_type
{
    int full_time_salary;
    int part_time_salary;
    int intern_salary;
};

struct employee
{
    char name[25];
    int id;
    JOB_TYPE job_type;
    union salary_type pay;
};

int main()
{
    struct employee e;

    strcpy(e.name, "aaaa");
    e.id = 101;
    e.job_type = EMPLOYEE_PART_TIME;
    e.pay.part_time_salary = 300;

    printf("\n emp.name is: %s", e.name);
    printf("\n emp.id is: %d", e.id);
    printf("\n emp.job_type is: %d", e.job_type);
    printf("\n emp.pay: %d", e.pay.part_time_salary);

    printf("\n sizeof() struct is : %d\n", sizeof(e));
    printf("\n sizeof() union is : %d\n", sizeof(e.pay));
}