#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct Employee {
    int id;
    char name[20];
    float salary;
};

int main() {

    int fd;
    struct Employee emp;
    
    // Create and open file
    fd = open("employees.dat", O_CREAT | O_RDWR, 0644);

    if(fd < 0) {
        printf("File opening failed\n");
        return 1;
    }

    // Write employee records
    struct Employee employees[3] = {
        {1, "Alice", 50000},
        {2, "Bob", 60000},
        {3, "Charlie", 70000}
    };

    write(fd, employees, sizeof(employees));

    printf("Employee records written successfully\n");


    // Update second employee record
    lseek(fd, sizeof(struct Employee), SEEK_SET);

    emp.id = 2;
    strcpy(emp.name, "Bob");
    emp.salary = 65000;

    write(fd, &emp, sizeof(emp));

    printf("Employee record updated successfully\n");


    // Retrieve second employee record
    lseek(fd, sizeof(struct Employee), SEEK_SET);

    read(fd, &emp, sizeof(emp));

    printf("\nRetrieved Employee Record:\n");
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);


    close(fd);

    printf("\nFile closed successfully\n");

    return 0;
}
