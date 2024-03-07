#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct elem {
    int varsta_persoanei;
    char numele_persoanei[50];
    int numar_accidente;
};

void read(struct elem *array, int n){
    printf("Dati elementele tabloului:\n");
    for(int i = 0; i < n; i++){
        printf("Elementul %d:\n", i+1);
        printf("Numele persoanei: "); scanf("%s", &array[i].numele_persoanei);
        printf("Varsta persoanei: "); scanf("%d", &array[i].varsta_persoanei);
        printf("Numarul de accidente: "); scanf("%d", &array[i].numar_accidente);       
    }
}

void print(struct elem *array, int n) {
    printf("Elementele tabloului:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: Numele = %s, Varsta = %d, Nr. Accidente = %d\n", i + 1, array[i].numele_persoanei, array[i].varsta_persoanei, array[i].numar_accidente);
    }
}

int search(struct elem *array, int n, char nume[]){
    for(int i = 0;i<n;i++){
        if(strcmp(array[i].numele_persoanei, nume) == 0){
            return i;
        }
    }
    return -1;
}

void free_mem(struct elem *array){
    free(array);
}

int comparare_1(const void *a, const void *b) {
    return ((struct elem *)a)->varsta_persoanei - ((struct elem *)b)->varsta_persoanei;
}
int comparare_2(const void *a, const void *b) {
    return ((struct elem *)a)->numar_accidente - ((struct elem *)b)->numar_accidente;
}

void sort(struct elem *array, int n, int alegere){
    switch ((alegere))
    {
    case 1:
        qsort(array, n, sizeof(struct elem), comparare_1);
        break;
    case 2:
        qsort(array, n, sizeof(struct elem), comparare_2);
    default:
        printf("\nVarianta invalida!");
        break;
    }
}

void insert_end(struct elem **array, int *n){
    *n+=1;
    *array = realloc(*array, (*n) * sizeof(struct elem));
    printf("Dati datele noului element:\n");
    printf("Numele persoanei: "); scanf("%s", (*array)[*n-1].numele_persoanei);
    printf("Varsta persoanei: "); scanf("%d", &(*array)[*n-1].varsta_persoanei);
    printf("Numar accidente: "); scanf("%d", &(*array)[*n-1].numar_accidente);
}

void insert_beginning(struct elem **array, int *n){
    *n+=1;
    *array = realloc(*array, (*n) * sizeof(struct elem));
    memmove(*array + 1, *array, (*n-1)*sizeof(struct elem));
    printf("Dati datele noului element:\n");
    printf("Numele persoanei: "); scanf("%s", (*array)[0].numele_persoanei);
    printf("Varsta persoanei: "); scanf("%d", &(*array)[0].varsta_persoanei);
    printf("Numar accidente: "); scanf("%d", &(*array)[0].numar_accidente);
}

void insert_position(struct elem **array, int *n, int pozitie){
    if(pozitie< 0 || pozitie> *n){
        printf("Pozitie invalida\n");
        return;
    }
    *n+=1;
    *array = realloc(*array, (*n) * sizeof(struct elem));
    memmove(*array + 1 + pozitie, *array + pozitie, (*n-1-pozitie)*sizeof(struct elem));
    printf("Dati datele noului element:\n");
    printf("Numele persoanei: "); scanf("%s", (*array)[pozitie].numele_persoanei);
    printf("Varsta persoanei: "); scanf("%d", &(*array)[pozitie].varsta_persoanei);
    printf("Numar accidente: "); scanf("%d", &(*array)[pozitie].numar_accidente);
}

void delete_position(struct elem **array, int *n, int pozitie){
     if(pozitie< 0 || pozitie>= *n){
        printf("Pozitie invalida\n");
        return;
    }
    memmove(*array + pozitie, *array + pozitie +1, (*n - pozitie - 1) * sizeof(struct elem));
    *n-=1;
    *array = realloc(*array, (*n) * sizeof(struct elem));
}

int main(){
    struct elem *array = NULL;
    int n = 0;
    int optiune;
    int alegere;
    char nume[50];
    int pozitie;
    do {
        printf("\nMeniu:\n");
        printf("1) Citirea de la tastatura a elementelor tabloului\n");
        printf("2) Afisarea la consola a elementelor tabloului\n");
        printf("3) Cautarea unui element dupa valoarea unui camp din structura\n");
        printf("4) Eliberarea memoriei tabloului\n");
        printf("5) Sortarea elementelor\n");
        printf("6) Inserarea unui element nou la capatul tabloului\n");
        printf("7) Inserarea unui element nou la inceputul tabloului\n");
        printf("8) Inserarea unui element la o pozitie in tablou\n");
        printf("9) Stergerea unui element de pe o pozitie din tablou\n");
        printf("0) Iesire\n");
        printf("Alege optiunea: ");
        scanf("%d", &optiune);
        
        switch (optiune){
        case 1:
            printf("Dati nr de elemente: ");
            scanf("%d", &n);
            array = malloc(n*sizeof(struct elem));
            read(array, n);
        break;
        
        case 2:
            print(array,n);
        break;

        case 3:
            printf("Dati numele persoanei care o cautati: ");
            scanf("%s", &nume);
            pozitie = search(array, n, nume);
            if (pozitie != -1){
                printf("Persoana cu numele %s se afla la pozitia %d in tablou\n", nume, pozitie+1);
                printf("Datele persoanei: \nNume = %s\nVarsta = %d\nNumar accidente = %d\n", array[pozitie].numele_persoanei, array[pozitie].varsta_persoanei, array[pozitie].numar_accidente);
            } else { printf("Persoana data nu a fost gasita");}
        break;

        case 4:
            free(array);
            n = 0;
            printf("Memoria a fost eliberata!\n");
        break;

        case 5:
            printf("\nTastati 1 daca doriti sa sortati dupa varsta, tastati 2 daca doriti sa sortati dupa nr de accidente\n");
            scanf("%d", &alegere);
            sort(array, n, alegere);
            printf("Persoanele din tablou au fost sortate\n");
        break;

        case 6:
            insert_end(&array, &n);
        break;

        case 7:
            insert_beginning(&array, &n);
        break;

        case 8:
            printf("Dati pozitia dorita: ");
            scanf("%d", &pozitie);
            insert_position(&array, &n, pozitie);
        break;

        case 9:
            printf("Dati pozitia dorita: ");
            scanf("%d", &pozitie);
            delete_position(&array, &n, pozitie);
        break;
        case 0:
            printf("Va multumesc, programul se inchide\n");
        break;
        default:
            printf("Optiune invalida. Alegeti din nou\n");
        }   
    } while(optiune != 0);
    return 0;
}


