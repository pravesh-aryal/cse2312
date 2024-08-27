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
int getFruitCount(struct Person *currentPerson, char *currentFruit);

//expecting at least there will be one person
int totalPersonCount = 0;

int comparePersons(const void *a, const void *b) {
    struct Person *personA = (struct Person *)a;
    struct Person *personB = (struct Person *)b;
    return strcmp(personA->name, personB->name);
}

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

        qsort(persons, totalPersonCount, sizeof(struct Person), comparePersons);

        for (int i = 0; i < totalPersonCount; i++) {

            printf("%-20.20s%8.8s = %2d\n", persons[i].name, "apples", getFruitCount(&persons[i], "apples"));
            printf("%-20.20s%8.8s = %2d\n", "", "bananas", getFruitCount(&persons[i], "bananas"));
            printf("%-20.20s%8.8s = %2d\n", "", "oranges", getFruitCount(&persons[i], "oranges"));
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
    //add all the fruits and initialize their count to 0 since we want to print the 0 count too.
    for (int i = 0; i < currentPerson->fruitCount; i++){
        if (strcmp(currentPerson->fruits[i].name, currentFruit) == 0){
            //if fruit exists update the count
            currentPerson->fruits[i].fruitCount += currentFruitCount;
            return;
        }
    }

    currentPerson->fruitCount++;//add a new fruit for that person
    strcpy(currentPerson->fruits[currentPerson->fruitCount].name, currentFruit);
    currentPerson->fruits[currentPerson->fruitCount].fruitCount = currentFruitCount;
    currentPerson->fruitCount++;

}


int getFruitCount(struct Person *currentPerson, char *currentFruit){
    //check for all fruits.
    for (int i = 0; i < currentPerson->fruitCount; i++) {
        if (strcmp(currentPerson->fruits[i].name, currentFruit) == 0) {
            // If the fruit matches, print the count and return it
            return currentPerson->fruits[i].fruitCount;
        }
    }
    
    // If no matching fruit is found, return 0
    return 0;
}