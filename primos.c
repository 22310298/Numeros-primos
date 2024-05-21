#include <stdio.h>
#include <conio.h>

int menu();
int primos(int);
void imprimir_rango();
void clear();

int main(){

    int op;
    int n;

    do{
        clear();
        op=menu();
        
        switch (op)
        {
            case 1:
                clear();
                printf("\nIngresa un numero: ");
                scanf("%i", &n);
                if(primos(n) == 1){
                    printf("\n%i es primo.", n);
                } else printf("\n%i no es primo.", n);
                getch();
                break;
            case 2:
                clear();
                imprimir_rango();
                break;
            case 3:
                clear();
                printf("\nHasta la proxima.");
                getch();
                break;

            default:
                clear();
                printf("Opcion invalida");
                getch();
        }
    }while(op!=3);
    

    getchar();
    return 0;
}

int menu(){
    int opcion;
    printf("\n---- MENU ----\n");
    printf("1. Es primo?...\n");
    printf("2. Primo en rango (0 - 100)\n");
    printf("3. Salir\n");
    printf("Ingrese la opci%cn: ", 162);
    scanf("%d", &opcion);

    return opcion;
}

int primos(int n){
    int i;
	

    if (n <= 1){
        return 0;
    }
    for ( i = 2; i * i <= n; i++)
    {
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

void imprimir_rango(){
    int st, end=0;

    printf("Ingrese el inicio del rango: ");
    scanf("%i", &st);

    printf("\nIngrese el final del rango: ");
    scanf("%i", &end);
    while (end > 100) {
        clear();
        printf("El final del rango debe ser menor o igual a 100. Ingrese un nuevo valor: ");
        scanf("%i", &end);
    }

    clear();

    printf("Los numeros primos en el rango %i - %i son:\n", st, end);
    for(int i= st; i <= end; i++){
        if(primos(i)){
            printf("%i ",i);
        }
    }
    getch();
}

void clear(){
   printf("\033[2J"); // Código ANSI para limpiar la pantalla
    printf("\033[1;1H"); // Mover el cursor al inicio de la pantalla
}