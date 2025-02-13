#include <glib.h>
#include <stdio.h>

int main(void) {
    GQueue *cola = g_queue_new(); // Crea una nueva cola

    // Encola elementos
    g_queue_push_tail(cola, GINT_TO_POINTER(10)); 
    g_queue_push_tail(cola, GINT_TO_POINTER(20));
    g_queue_push_tail(cola, GINT_TO_POINTER(30));
    g_queue_push_tail(cola, GINT_TO_POINTER(40));

    // Muestra el tamaño de la cola
    printf("Tamaño: %u\n", g_queue_get_length(cola));
    
    // Muestra el primer elemento
    printf("Primer elemento: %d\n", GPOINTER_TO_INT(g_queue_peek_head(cola)));

    // Desencola un elemento y lo muestra
    int valor = GPOINTER_TO_INT(g_queue_pop_head(cola));
    printf("Elemento desencolado: %d\n", valor);

    // Muestra el nuevo primer elemento después de desencolar el anterior
    if (!g_queue_is_empty(cola)) {
        printf("Nuevo primer elemento: %d\n", GPOINTER_TO_INT(g_queue_peek_head(cola)));
    } else {
        printf("La cola está vacía después de desencolar.\n");
    }

    // Muestra el contenido actual de la cola
    printf("Contenido de la cola:\n");
    for (GList *iter = cola->head; iter != NULL; iter = iter->next) {
        printf("%d -> ", GPOINTER_TO_INT(iter->data));
    }
    printf("nadita\n");

    // Libera la cola
    g_queue_free(cola);

    return 0;
}
