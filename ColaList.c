#include <glib.h>
#include <stdio.h>

typedef struct {
    GSList *inicio;
    GSList *final;
    guint contador;
} Cola;

/* Inicializa la cola */
void initCola(Cola *c) {
    c->inicio = NULL;
    c->final = NULL;
    c->contador = 0;
}

/* Verifica si la cola está vacía */
gboolean isEmpty(Cola *c) {
    return (c->inicio == NULL);
}

/* Encola un elemento (agrega al final) */
void enqueue(Cola *c, int dato) {
    GSList *nuevo = g_slist_append(NULL, GINT_TO_POINTER(dato));

    if (isEmpty(c)) {
        c->inicio = c->final = nuevo;
    } else {
        c->final->next = nuevo;
        c->final = nuevo;
    }
    c->contador++;
}

/* Desencola un elemento usando `g_slist_remove()` */
int dequeue(Cola *c) {
    if (isEmpty(c)) {
        printf("Cola vacía\n");
        return -1;
    }

    int valor = GPOINTER_TO_INT(c->inicio->data);
    GSList *temp = c->inicio;  

    c->inicio = g_slist_remove(c->inicio, temp->data);  

    if (c->inicio == NULL) {
        c->final = NULL;
    }

    g_slist_free_1(temp);  // Libera memoria del nodo eliminado
    c->contador--;

    return valor;
}

/* Obtiene el primer elemento sin eliminarlo */
int front(Cola *c) {
    if (isEmpty(c)) {
        printf("Cola vacía\n");
        return -1;
    }
    return GPOINTER_TO_INT(c->inicio->data);
}

/* Retorna el tamaño de la cola */
guint size(Cola *c) {
    return c->contador;
}

/* Imprime la cola */
void imprimirCola(Cola *c) {
    printf("Cola: ");
    for (GSList *nodo = c->inicio; nodo != NULL; nodo = nodo->next) {
        printf("%d -> ", GPOINTER_TO_INT(nodo->data));
    }
    printf("NULL\n");
}

int main() {
    Cola cola;
    initCola(&cola);

    enqueue(&cola, 10);
    enqueue(&cola, 20);
    enqueue(&cola, 30);
    enqueue(&cola, 40);

    printf("Tamaño: %u\n", size(&cola));
    printf("Frente: %d\n", front(&cola));

    printf("Elemento desencolado: %d\n", dequeue(&cola));
    printf("Nuevo frente: %d\n", front(&cola));

    imprimirCola(&cola);

    // Vaciar la cola
    while (!isEmpty(&cola)) {
        dequeue(&cola);
    }

    return 0;
}

