/*1.3>Write a program to create a structure to store the information of n number of Employees. Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the information of employees with gross salary. Use array of structure.  
#include<stdio.h>
int main()
{
    int i,n;
    struct employee
    {
        int emp_id;
        char name[20];
        char designation[20];
        float basic_salary;
        float hra;
        float da;
    }e[100];
    printf("Enter the number of employees\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the details of employee %d\n",i+1);
        scanf("%d %s %s %f %f %f",&e[i].emp_id,e[i].name,e[i].designation,&e[i].basic_salary,&e[i].hra,&e[i].da);
        printf("\tEmployee ID : ");scanf("%d",&e[i].emp_id);
        printf("\tEmployee Name : ");scanf("%s",e[i].name);
        printf("\tEmployee Designation : ");scanf("%s",e[i].designation);
        printf("\tEmployee Basic Salary : ");scanf("%f",&e[i].basic_salary);
        printf("\tEmployee HRA : ");scanf("%f",&e[i].hra);
        printf("\tEmployee DA : ");scanf("%f",&e[i].da);
        printf("\n");
        }*/
    
 #include <stdio.h>
  struct Employee {
  int empId;
  char name[50];
  char designation[50];
  float basicSalary;
  float hraPercentage;
  float daPercentage;
};

int main() {
  int n;
  printf("Enter the number of employees: ");
  scanf("%d", &n);
    struct Employee employees[n];

  for (int i = 0; i < n; i++) {
    printf("\nEmployee %d\n", i + 1);
    printf("Enter Employee ID: ");
    scanf("%d", &employees[i].empId);
    printf("Enter Name: ");
    scanf("%s", employees[i].name);
    printf("Enter Designation: ");
    scanf("%s", employees[i].designation);
    printf("Enter Basic Salary: ");
    scanf("%f", &employees[i].basicSalary);
    printf("Enter HRA Percentage: ");
    scanf("%f", &employees[i].hraPercentage);
    printf("Enter DA Percentage: ");
    scanf("%f", &employees[i].daPercentage);
  }
  printf("\nEmployee Information\n");
  printf("--------------------\n");

  for (int i = 0; i < n; i++) {
    float hra = employees[i].basicSalary * (employees[i].hraPercentage / 100);
    float da = employees[i].basicSalary * (employees[i].daPercentage / 100);
    float grossSalary = employees[i].basicSalary + hra + da;

    printf("\nEmployee %d\n", i + 1);
    printf("Employee ID: %d\n", employees[i].empId);
    printf("Name: %s\n", employees[i].name);
    printf("Designation: %s\n", employees[i].designation);
    printf("Gross Salary: %.2f\n", grossSalary);
  }

  return 0;
}
