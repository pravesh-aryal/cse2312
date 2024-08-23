/*
    name:  Pravesh Aryal

    instructor for Introduction to Programming:  Nadra Guizani
    instructor for Intermediate Programming   :  Marika Apostolova
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fruit {
    char name[20];
    int fruitCount; 
};
struct Person{
    int name[21];
    struct Fruit fruits[100];
};


int main (void){
    struct Person persons[20];
    char line[1024];
    FILE *dataFile = fopen("data.csv", "r");
    printf("Hello world\n");
    if (dataFile == NULL){
        printf("Error: cannot open the file\n");
        exit(-1);
}
    char *token;
    printf("%s \n", line);
     

    while (fgets(line, 1024, dataFile)){
        printf("%s \n", line);
        char *name = strtok(line, ",");
        char *fruit = strtok(NULL, ",");
        char *count = strtok(NULL, ",");
        printf("Name:%s, Fruit %s, Count %s", name, fruit, count);
        }

    return 0;

}


