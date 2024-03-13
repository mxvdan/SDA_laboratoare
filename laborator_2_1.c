#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car { 
    int ID;
    char marca[50];
    char model[50];
    int an_producere;
    char stare[20];
    struct car *next;
}Car;

 Car *readCar(){
    Car *car = (Car*)malloc(sizeof(Car));
    if (car == NULL){
        printf("Eroare alocare");
        exit(1);
    }
    printf("\nDati ID-ul masinii: ");
    scanf("%d", &car->ID);
    printf("\nDati marca masinii: ");
    scanf("%s", car->marca);
    printf("\nDati modelul masinii: ");
    scanf("%s", car->model);
    printf("\nDati anul de producere: ");
    scanf("%d", &car->an_producere);
    printf("\nDati starea masinii: ");
    scanf("%s", car->stare);
    car->next = NULL;
    return car;
}

void printList(Car *head){
    Car *current = head;
    printf("Lista de masini:\n");
    while(current != NULL){
        printf("ID: %d, Marca: %s, Modelul: %s, Anul: %d, Starea: %s\n",current->ID, current->marca, current->model, current->an_producere, current->stare);
        current = current->next;
    }
}

void freeList(Car **head){
    Car *current = *head;
    Car *next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}





