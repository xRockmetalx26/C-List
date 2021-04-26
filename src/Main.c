#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <List.h>

typedef struct Student {
    char name[128];
    size_t id;
} Student;

Student* new_student(const char *name, const size_t id) {
    Student *student = (Student*) calloc(1, sizeof(Student));

    strncpy(student->name, name, 128);

    student->id = id;

    return student;
}

void print_students_list(List *students_list) {
    for(Node *it = students_list->first; it; it = it->next) {
        Student *student = (Student*) it->data;

        printf("Name: %s, ID: %llu\n", student->name, student->id);
    }

    printf("\n\n");
}

int main() {
    List *list = new_list();
    List *list2 = new_list();

    add_first_list(list, new_student("Ronald", 1));
    add_first_list(list, new_student("Jose", 2));
    add_first_list(list, new_student("Alan", 3));


    print_students_list(list2);

    delete_list(list);
    delete_list(list2);

    return EXIT_SUCCESS;
}