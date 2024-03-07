#include<stdio.h>
#include<string.h>

struct elem {
    int varsta;
    char nume[50];
};

void scan(struct elem array[],int n){
    printf("Dati elementele tabloului:\n");
    for(int i = 0;i<n;i++){
        printf("Elementul %d:\n", i+1);
        printf("Varsta: ");
        scanf("%d", &array[i].varsta);
        printf("Nume: ");
        scanf("%s", &array[i].nume);
    }
}

void print(struct elem array[], int n){
    printf("Elementele tabloului;\n");
    for(int i = 0;i<n;i++){
        printf("Elementul %d:\nID: %d, Nume: %s\n", i, array[i].varsta, array[i].nume);
    }
}

int search(struct elem array[], int n, int value){
    for(int i = 0;i < n ;i++){
        if(array[i].varsta == value) return i;
    }
    return -1;
}

int main(){
    struct elem array[100];
    int n;
    repetare:
    printf("Dati nr de elemente al tabloului (< 100): ");
    scanf("%d", &n);
    if(n<=0 || n > 100){
        printf("Numarul de elemente este in afara limitelor!\n");
       goto repetare;
    }
    scan(array, n);
    int value;
    printf("Dati valoarea cautata\n");
    scanf("%d", &value);
    int pozitie = search(array, n, value);
    if(pozitie != -1){
        printf("Valoarea cautata se afla la pozitia %d\n", pozitie+1);
    } else {
        printf("Valoarea cautata nu este in tablou\n");
    }
    repetare2:
    printf("Pentru a continua, tastati 1, pentru a opri programul, tastati 0\n");
    int check;
    scanf("%d", &check);
    if(check==1)goto continuare;
    else if(check==0) return 0;
    else {printf("Nu ati introdus o alegere valida!\n");
    goto repetare2;}
    continuare:
    print(array,n);
    return 0;
}

