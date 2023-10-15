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
    free;
}
void Menuturno() {
    printf("\n************ Turno de Jugador 1 ************\n");
    printf("1. Atacar\n");
    printf("2. Colocar una carta\n");
    printf("Seleccione una opcion: ");
}

void atacar() {
	
    printf("Jugador 1 ha seleccionado 'Atacar'.\n");
    
}

void realizarAtaque(struct Carta *atacante, struct Carta *defensor) {
    int danio = atacante->puntos_ataque - defensor->puntos_defensa;

    if (danio > 0) {
        defensor->puntos_vida -= danio;
        if (defensor->puntos_vida <= 0) {
            printf("%s ha derrotado a %s.\n", atacante->nombre, defensor->nombre);
        } else {
            printf("%s inflige %d puntos de daño a %s. %s tiene %d puntos de vida restantes.\n",
                   atacante->nombre, danio, defensor->nombre, defensor->nombre, defensor->puntos_vida);
        }
    } else {
        printf("%s no pudo infligir daño a %s debido a su alta defensa.\n", atacante->nombre, defensor->nombre);
    }
}

void colocarCarta() {
    printf("Jugador 1 ha seleccionado 'Colocar una carta'.\n");
    // Lógica para colocar una carta
    printf("hola mundo");
}

void AgregarVidasJugador(struct Jugador *jugador) {
    jugador->puntos_vida = 5; 
    // Entrega los puntos de vida al jugador
}

// Funcion para revolver las cartas
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
int perdervida = 1;
   
struct Carta jugador1[15];
struct Carta jugador2[15];
struct Jugador jugador1a;
struct Jugador jugador2a;

AgregarVidasJugador(&jugador1a);
AgregarVidasJugador(&jugador2a);

for (int i = 0; i < 15; i++) {
jugador1[i] = cartas[i];
jugador2[i] = cartas[i + 15];
}

 printf("El jugador1 tiene %d puntos de vida.\n", jugador1a.puntos_vida);
printf("El jugador2 tiene %d puntos de vida.\n", jugador2a.puntos_vida);

while(jugador1a.puntos_vida > 0 && jugador2a.puntos_vida > 0){
printf("ronda siguiente");
 int opcion;

    do {
        Menuturno();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                atacar();
                break;
            case 2:
                colocarCarta();
                break;
            default:
      
	            printf("Opcion no válida. Intente de nuevo.\n");
        }
    } while (opcion != 1 && opcion != 2);
	
	jugador2a.puntos_vida -= perdervida;
	printf("\nEl jugador2 tiene %d puntos de vida.\n", jugador2a.puntos_vida);
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
		free;
			
        printf("Carta creada y guardada en 'cartas.txt'!\n");

        printf("Desea crear otra carta? (s para si o n para no): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
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

