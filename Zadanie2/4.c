#include <stdio.h>
#include <stdlib.h>

struct Student {
  char imie[15];
  float ocena;
};

void sortStudent(struct Student *student, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (student[j].ocena < student[j + 1].ocena) {
                struct Student temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            };
        };
    };
};

int main(){
   struct Student student[100];
     for (int i = 0; i < 100; i++) {
        sprintf(student[i].imie, "Student %d", i+1); // sprintf do generowania unikalnych imion
        student[i].ocena = 2.0 + (float)(rand() % 4); 
    };
    
     sortStudent(student, 100);

     for (int i = 0; i < 100; i++) {
        printf("Student %d: Ocena koncowa: %.2f\n", i+1, student[i].imie, student[i].ocena);
    };
    
    return 0;
};
