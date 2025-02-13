#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;


typedef struct Cola {
    Nodo *inicio;   
    Nodo *ultimo;   
    int contador;   
} Cola;


void init_cola(Cola *c) {
    c->inicio = c->ultimo = NULL;
    c->contador = 0;
}


int isEmpty(Cola *c) {
    return c->inicio == NULL;
}


void enqueue(Cola *c, int dato) {
    Nodo *nuevo = malloc(sizeof(Nodo));
    if (!nuevo) {
        fprintf(stderr, "wrror de memoria\n");
        exit(EXIT_FAILURE);
    }
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    
    if (isEmpty(c))
        c->inicio = c->ultimo = nuevo;
    else {
        c->ultimo->siguiente = nuevo;
        c->ultimo = nuevo;
    }
    c->contador++;
}


int dequeue(Cola *c) {
    if (isEmpty(c)) {
        fprintf(stderr, "vacio\n");
        return -1;
    }
    Nodo *temp = c->inicio;
    int valor = temp->dato;
    c->inicio = temp->siguiente;
    if (c->inicio == NULL)
        c->ultimo = NULL;
    free(temp);
    c->contador--;
    return valor;
}


int front(Cola *c) {
    if (isEmpty(c)) {
        fprintf(stderr, "vacio\n");
        return -1;
    }
    return c->inicio->dato;
}


int size(Cola *c) {
    return c->contador;
}


void imprimirCola(Cola *c) {
    Nodo *actual = c->inicio;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("nadita\n");
}


int main(void) {
    Cola cola;
    init_cola(&cola);

    enqueue(&cola, 10);
    enqueue(&cola, 20);
    enqueue(&cola, 30);
    enqueue(&cola, 40);

    printf("Tamaño  %d\n", size(&cola));
    printf("Último elemento %d\n", front(&cola));

    int valor = dequeue(&cola);
    printf("%d", valor);

    printf("Cola:\n");
    imprimirCola(&cola);

    
    while (!isEmpty(&cola)) {
        dequeue(&cola);
    }

    return 0;
}
