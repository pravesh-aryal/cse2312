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
    char name[21];
    struct Fruit fruits[100];
    int fruitCount;
};

void addPerson(struct Person persons[], int *personCount, char *currentName, char *currentFruit, int currentFruitCount);
void addFruit(struct Person *currentPerson, char *currentFruit, int currentFruitCount);

//expecting at least there will be one person
int totalPersonCount = 0;


int main (void){

    struct Person persons[900] = {0};
    char line[1024];
    FILE *dataFile = fopen("data.csv", "r");
    printf("Hello world\n");
    if (dataFile == NULL){
        printf("Error: cannot open the file\n");
        exit(-1);
}
    char *token;
    // printf("%s \n", line);
     

    while (fgets(line, 1024, dataFile)){
        // printf("%s \n", line);
        char *name = strtok(line, ",");
        char *fruit = strtok(NULL, ",");
        char *fruitCountStr = strtok(NULL, ",");
        int fruitCount = atoi(fruitCountStr);
        
        // printf("Name:%s, Fruit %s, Count %d", name, fruit, fruitCount);
        addPerson(persons, &totalPersonCount, name, fruit, fruitCount);
        }
        fclose(dataFile);

        for (int i = 0; i < totalPersonCount; i++) {
        // Print person's name
        printf("Person: %s\n", persons[i].name);

        // Print each fruit and its count
        printf("Fruits:\n");
        for (int j = 0; j < persons[i].fruitCount; j++) {
            printf("  Fruit: %s, Count: %d\n", persons[i].fruits[j].name, persons[i].fruits[j].fruitCount);
        }
        printf("\n");  // Separate persons with a newline
    }
    return 0;

}

void addPerson(struct Person persons[], int *personCount, char *currentName, char *currentFruit, int currentFruitCount){
    //see if the person is on the persons array and only update the fruit count if exists
    for (int i = 0; i < *personCount; i++){
        if (strcmp(persons[i].name, currentName) == 0){
            addFruit(&persons[i], currentFruit, currentFruitCount);
            return;
        }
    }

    //if it is a new person
    strcpy(persons[*personCount].name, currentName);    
    persons[*personCount].fruitCount = 0; 
    addFruit(&persons[*personCount], currentFruit, currentFruitCount);
    (*personCount)++;
}

//function to add fruit name and update count for a particular person

void addFruit(struct Person *currentPerson, char *currentFruit, int currentFruitCount) {


    // Check if the fruit name already exists for the particular person and update its count
    for (int i = 0; i < currentPerson->fruitCount; i++){
        if (strcmp(currentPerson->fruits[i].name, currentFruit) == 0){
            //if fruit exists update the count
            currentPerson->fruits[i].fruitCount += currentFruitCount;
            return;
        }
    }

    //add a new fruit for that person
    strcpy(currentPerson->fruits[currentPerson->fruitCount].name, currentFruit);
    currentPerson->fruits[currentPerson->fruitCount].fruitCount = currentFruitCount;
    currentPerson->fruitCount++;

}
