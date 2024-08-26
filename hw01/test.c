#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONS 20
#define MAX_FRUITS 100

struct Fruit {
    char name[20];
    int fruitCount; 
};

struct Person {
    char name[21]; // Changed from int to char to store names
    struct Fruit fruits[MAX_FRUITS];
    int fruit_count; // Number of fruits for this person
};

// Function prototypes
void checkForDuplicate(struct Person persons[], int *person_count, char *current_name, char *current_fruit, int current_count);
void printPersons(struct Person persons[], int person_count);

int main(void) {
    struct Person persons[MAX_PERSONS] = {0};
    int person_count = 0;
    char line[1024];
    FILE *dataFile = fopen("data.csv", "r");

    if (dataFile == NULL) {
        printf("Error: cannot open the file\n");
        return -1;
    }

    while (fgets(line, 1024, dataFile)) {
        char *name = strtok(line, ",");
        char *fruit = strtok(NULL, ",");
        char *count_str = strtok(NULL, ",");
        int count = atoi(count_str);

        checkForDuplicate(persons, &person_count, name, fruit, count);
    }

    fclose(dataFile);

    // Print the array of persons
    printPersons(persons, person_count);

    return 0;
}

void checkForDuplicate(struct Person persons[], int *person_count, char *current_name, char *current_fruit, int current_count) {
    int person_index = -1;
    // Check if the person exists
    for (int i = 0; i < *person_count; i++) {
        if (strcmp(persons[i].name, current_name) == 0) {
            person_index = i;
            break;
        }
    }

    // If person does not exist, add new person
    if (person_index == -1) {
        person_index = *person_count;
        strcpy(persons[person_index].name, current_name);
        persons[person_index].fruit_count = 0; // Initialize fruit count
        (*person_count)++;
    }

    // Check if the fruit exists for the person
    int fruit_index = -1;
    for (int i = 0; i < persons[person_index].fruit_count; i++) {
        if (strcmp(persons[person_index].fruits[i].name, current_fruit) == 0) {
            fruit_index = i;
            break;
        }
    }

    // If fruit does not exist, add new fruit
    if (fruit_index == -1) {
        fruit_index = persons[person_index].fruit_count;
        strcpy(persons[person_index].fruits[fruit_index].name, current_fruit);
        persons[person_index].fruits[fruit_index].fruitCount = 0; // Initialize fruit count
        persons[person_index].fruit_count++;
    }

    // Update the fruit count
    persons[person_index].fruits[fruit_index].fruitCount += current_count;
}

void printPersons(struct Person persons[], int person_count) {
    for (int i = 0; i < person_count; i++) {
        printf("Person: %s\n", persons[i].name);
        for (int j = 0; j < persons[i].fruit_count; j++) {
            printf("  Fruit: %s, Count: %d\n", persons[i].fruits[j].name, persons[i].fruits[j].fruitCount);
        }
        printf("\n");
    }
}

