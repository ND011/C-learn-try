#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 100

struct Person {
    char name[MAX_NAME_LENGTH];
    char gender[10];
    int teamNumber;
};

// Comparator function for qsort
int compareNames(const void *a, const void *b) {
    const struct Person *personA = (const struct Person *)a;
    const struct Person *personB = (const struct Person *)b;
    return strcmp(personA->name, personB->name);
}

int main() {
    int n, numTeams;

    // Input number of people
    printf("Enter the number of people: ");
    scanf("%d", &n);
    getchar(); // consume the newline character

    // Input number of teams
    printf("Enter the number of teams: ");
    scanf("%d", &numTeams);
    getchar(); // consume the newline character

    // Dynamically allocate memory for array of Person structures
    struct Person *people = malloc(n * sizeof(struct Person));
    if (people == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input names and genders
    for (int i = 0; i < n; ++i) {
        printf("Enter the name of person %d (in the format 'NAME SURNAME'): ", i + 1);
        fgets(people[i].name, MAX_NAME_LENGTH, stdin);
        // Remove newline character from input
        people[i].name[strcspn(people[i].name, "\n")] = '\0';

        printf("Enter the gender of person %s (male/female): ", people[i].name);
        scanf("%s", people[i].gender);
        getchar(); // consume the newline character
    }

    // Shuffle people array randomly
    srand(time(NULL));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        struct Person temp = people[i];
        people[i] = people[j];
        people[j] = temp;
    }

    // Sort names alphabetically
    qsort(people, n, sizeof(struct Person), compareNames);

    // Assign team numbers
    for (int i = 0; i < n; ++i) {
        people[i].teamNumber = (i % numTeams) + 1;
    }

    // Calculate the number of males and females
    int maleCount = 0, femaleCount = 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(people[i].gender, "male") == 0)
            maleCount++;
        else
            femaleCount++;
    }

    // Calculate the target number of males and females per team
    int targetMalePerTeam = maleCount / numTeams;
    int targetFemalePerTeam = femaleCount / numTeams;

    // Print teams
    printf("\nTeams:\n");
    for (int i = 1; i <= numTeams; ++i) {
        printf("Team %d:\n", i);
        int maleRemaining = targetMalePerTeam;
        int femaleRemaining = targetFemalePerTeam;
        for (int j = 0; j < n; ++j) {
            if (people[j].teamNumber == i) {
                if (strcmp(people[j].gender, "male") == 0 && maleRemaining > 0) {
                    printf("%s - %s\n", people[j].name, people[j].gender);
                    maleRemaining--;
                } else if (strcmp(people[j].gender, "female") == 0 && femaleRemaining > 0) {
                    printf("%s - %s\n", people[j].name, people[j].gender);
                    femaleRemaining--;
                } else {
                    printf("%s - %s\n", people[j].name, people[j].gender);
                }
            }
        }
    }

    // Free allocated memory
    free(people);

    return 0;
}
