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
    int fruitCount;
};

void addPerson(struct Person persons[], int personCount, char *currentName, char *currentFruit, int *currentFruitCountPtr);
void addFruit(struct Person currentPerson);

//expecting at least there will be one person
int totalPersonCount = 1;


int main (void){

    struct Person persons[totalPersonCount];
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
        char *fruitCountStr = strtok(NULL, ",");
        int fruitCount = atoi(fruitCountStr);
        int *fruitCountPtr = &fruitCount;
        printf("Name:%s, Fruit %s, Count %d", name, fruit, fruitCount);
        addPerson(persons, totalPersonCount, name, fruit, fruitCountPtr);
        totalPersonCount++;
        }

    return 0;

}

void addPerson(struct Person persons[], int personCount, char *currentName, char *currentFruit, int *currentFruitCountPtr){
    //see if the person is on the persons array
    for (int i = 0; i < personCount; i++){
        //if the person already exists in our array
        if (strcmp(persons[i].name, currentName) == 0){

        }
        //if the person is new
        else {
            strcpy(persons[i].name, currentName);
            addFruit(persons[i]);
        }
    }

}

//function to add fruit name and update count for a particular person

void addFruit(struct Person *currentPerson, char *currentFruit, int currentFruitCount) {
    // Check if the fruit name already exists for the particular person and update its count
    for (int i = 0; i < currentPerson->fruitCount; i++) {
        if (strcmp(currentPerson->fruits[i].name, currentFruit) == 0) {
            // Fruit exists, update the count
            currentPerson->fruits[i].fruitCount += currentFruitCount;
            return;
        }
    }

    // if the fruit DNE, add the fruit, update the count
    strcpy(currentPerson->fruits[currentPerson->fruitCount].name, currentFruit);
    currentPerson->fruits[currentPerson->fruitCount].fruitCount = currentFruitCount;
    currentPerson->fruitCount++;
}