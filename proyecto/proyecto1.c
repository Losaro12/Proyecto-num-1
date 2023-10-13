#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Carta {
    char nombre[50];
    char tipo[20];
    int puntos_vida;
    int puntos_ataque;
    int puntos_defensa;
};

struct Jugador {
    char nombre[50];
    int puntos_vida;
};


void cargarCartasDesdeArchivo(struct Carta cartas[], int *num_cartas) {
    FILE *archivo;
    archivo = fopen("cartas.txt", "r");

    if (archivo == NULL) {
        return;
    }

    *num_cartas = 0;

    while (fscanf(archivo, "%49[^,],%19[^,],%d,%d,%d\n",
                  cartas[*num_cartas].nombre,
                  cartas[*num_cartas].tipo,
                  &cartas[*num_cartas].puntos_vida,
                  &cartas[*num_cartas].puntos_ataque,
                  &cartas[*num_cartas].puntos_defensa) == 5) {
        (*num_cartas)++;
    }

    fclose(archivo);
}

// Función para revolver las cartas
void revolverCartas(struct Carta cartas[], int num_cartas) {
    for (int i = num_cartas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Carta temp = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = temp;
    }
}

void mostrarMazo(struct Carta jugador[], int num_cartas) {
    printf("Mazo del Jugador:\n");
    for (int i = 0; i < num_cartas; i++) {
        printf("Carta %d:\n", i + 1);
        printf("Nombre: %s\n", jugador[i].nombre);
        printf("Tipo: %s\n", jugador[i].tipo);
        printf("Puntos de Vida: %d\n", jugador[i].puntos_vida);
        printf("Puntos de Defensa: %d\n", jugador[i].puntos_defensa);
        printf("Puntos de Ataque: %d\n", jugador[i].puntos_ataque);
        printf("\n");
    }
}

void comenzarPartida() {
printf("Comenzando la partida...\n");
struct Carta cartas[10000];
int num_cartas = 0;
 cargarCartasDesdeArchivo(cartas, &num_cartas);
srand(time(NULL));
revolverCartas(cartas, num_cartas);
   
struct Carta jugador1[15];
struct Carta jugador2[15];

for (int i = 0; i < 15; i++) {
jugador1[i] = cartas[i];
jugador2[i] = cartas[i + 15];
}


   
}

void crearCarta() {
    printf("Creando una nueva carta...\n");

    struct Carta nuevaCarta;
    char continuar;
    FILE *archivo;

    printf("Bienvenido al creador de cartas!\n");

    do {
        printf("\nIngrese los atributos de la carta:\n");

        printf("Nombre: ");
        scanf("%s", nuevaCarta.nombre);

        printf("Tipo: ");
        scanf("%s", nuevaCarta.tipo);

        printf("Puntos de vida: ");
        scanf("%d", &nuevaCarta.puntos_vida);

        printf("Puntos de ataque: ");
        scanf("%d", &nuevaCarta.puntos_ataque);

        printf("Puntos de defensa: ");
        scanf("%d", &nuevaCarta.puntos_defensa);

        
        archivo = fopen("cartas.txt", "a");

        if (archivo == NULL) {
            printf("Error al abrir el archivo 'cartas.txt'\n");
           
        }

        // Escribir la nueva carta en el archivo
        fprintf(archivo, "%s,%s,%d,%d,%d\n", nuevaCarta.nombre, nuevaCarta.tipo, nuevaCarta.puntos_vida, nuevaCarta.puntos_ataque, nuevaCarta.puntos_defensa);

        fclose(archivo);

        printf("Carta creada y guardada en 'cartas.txt'!\n");

        printf("Desea crear otra carta? (si o no): ");
        scanf(" %c", &continuar);
    } while (continuar == 'si' || continuar == 'S');
}

void historialPartida() {
    printf("Mostrando historial de la partida...\n");
    // Aqui puedes agregar la logica para mostrar el historial de la partida
}

int main() {
    int opcion;

    do {
        printf("************ Menu ************\n");
        printf("1. Comenzar partida\n");
        printf("2. Crear una carta\n");
        printf("3. Historial de partida\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                comenzarPartida();
                break;
            case 2:
                crearCarta();
                break;
            case 3:
                historialPartida();
                break;
            case 4:
                printf("Saliendo del juego. Hasta luego!\n");
                break;
            default:
                printf("Opcion no valida. seleccione por favor las opciones dadas.\n");
        }
    } while (opcion != 4);

    return 0;
}

