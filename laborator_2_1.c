#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car {
    int ID;
    char marca[50];
    char model[50];
    int an_producere;
    char stare[20];
    struct car* next;
} Car;

typedef struct List {
    Car* head;
} List;

Car* readCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    if (car == NULL) {
        printf("Eroare alocare");
        exit(1);
    }
    printf("\nDati ID-ul masinii: ");
    scanf("%d", &car->ID);
    printf("\nDati marca masinii: ");
    getchar();
    gets(car->marca);
    printf("\nDati modelul masinii: ");
    gets(car->model);
    printf("\nDati anul de producere: ");
    scanf("%d", &car->an_producere);
    printf("\nDati starea masinii: ");
    getchar();
    gets(car->stare);
    car->next = NULL;
    return car;
}

void printList(Car* head) {
    Car* current = head;
    printf("Lista de masini:\n");
    while (current != NULL) {
        printf("ID: %d, Marca: %s, Modelul: %s, Anul: %d, Starea: %s\n", current->ID, current->marca, current->model, current->an_producere, current->stare);
        current = current->next;
    }
}

void clearList(List* list) {
    Car* current_node = list->head, *back_node = NULL;
    while (current_node) {
        back_node = current_node;
        current_node = current_node->next;
        free(back_node);
    }
    list->head = NULL;
}

int searchCar(Car* head, const char* val, int camp) {
    Car* current = head;
    int poz = 0;

    while (current != NULL) {
        switch (camp) {
        case 1:
            if (current->ID == atoi(val))
                return poz;
            break;

        case 2:
            if (strcmp(current->marca, val) == 0)
                return poz;
            break;

        case 3:
            if (strcmp(current->model, val) == 0)
                return poz;
            break;

        case 4:
            if (current->an_producere == atoi(val))
                return poz;
            break;

        case 5:
            if (strcmp(current->stare, val) == 0)
                return poz;
            break;

        default:
            printf("Eroare.\n");
            return -1;
        }
        current = current->next;
        poz++;
    }
    return -1;
}

void sortCar_Year(Car* head) {
    int swapped;
    Car* ptr1;
    Car* lptr = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->an_producere > ptr1->next->an_producere) {
                int tempID = ptr1->ID;
                ptr1->ID = ptr1->next->ID;
                ptr1->next->ID = tempID;

                char tempMarca[50];
                strcpy(tempMarca, ptr1->marca);
                strcpy(ptr1->marca, ptr1->next->marca);
                strcpy(ptr1->next->marca, tempMarca);

                char tempModel[50];
                strcpy(tempModel, ptr1->model);
                strcpy(ptr1->model, ptr1->next->model);
                strcpy(ptr1->next->model, tempModel);

                int tempAn = ptr1->an_producere;
                ptr1->an_producere = ptr1->next->an_producere;
                ptr1->next->an_producere = tempAn;

                char tempStare[20];
                strcpy(tempStare, ptr1->stare);
                strcpy(ptr1->stare, ptr1->next->stare);
                strcpy(ptr1->next->stare, tempStare);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void deleteList(List* list) {
   clearList(list);
   free(list);
}

int main() {
    List carList;
    carList.head = NULL;
    int alegere;
    char val[50];
    int camp;

    do {
        printf("\n1. Adauga masina\n2. Afiseaza masinile\n3. Cauta masina\n4. Sorteaza masinile dupa anul de productie\n5. Iesire\n");
        printf("Introduceti optiunea: ");
        scanf("%d", &alegere);

        switch (alegere) {
        case 1:
            if (carList.head == NULL) {
                carList.head = readCar();
            } else {
                Car* temp = carList.head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = readCar();
            }
            break;

        case 2:
            printList(carList.head);
            break;

        case 3:
            printf("\n1. ID\n2. Marca\n3. Model\n4. Anul de productie\n5. Stare\n");
            printf("Introduceti campul dupa care doriti sa cautati: ");
            scanf("%d", &camp);
            printf("Introduceti valoarea: ");
            scanf("%s", val);
            if (searchCar(carList.head, val, camp) == -1)
                printf("Masina nu a fost gasita.\n");
            else
                printf("Masina a fost gasita la pozitia: %d\n", searchCar(carList.head, val, camp));
            break;

        case 4:
            sortCar_Year(carList.head);
            printf("Masinile au fost sortate dupa anul de productie.\n");
            break;

        case 5:
            deleteList(&carList);
            printf("Program terminat.\n");
            break;

        default:
            printf("Optiune invalida.\n");
        }
    } while (alegere != 5);

    return 0;
}
//modificari ?