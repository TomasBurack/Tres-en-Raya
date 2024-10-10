#include <stdio.h>

int cambioTurnos(int turno){
    if (turno ==1) return 2;
    return 1;
}

int main(){
    int tablero[3][3]={0}, fila, columna, ganador, turno = 1, continuar = 0, contador1 = 0, contador2 = 0, contadorGen = 0;

    do{
        printf("\n  1 2 3\n1 %d %d %d\n2 %d %d %d\n3 %d %d %d", tablero[0][0], tablero[0][1], tablero[0][2], tablero[1][0], tablero[1][1], tablero[1][2], tablero[2][0], tablero[2][1], tablero[2][2]);
        
        printf("\n---1 VS 2---\n");
        printf("Juega el %d\n", turno);
        printf("Ingrece su fila: ");
        scanf(" %d", &fila);
        fila = fila-1;
        printf("\nIngrece su columna: ");
        scanf(" %d", &columna);
        columna = columna - 1;
        if(turno == 1){
            if (tablero[fila][columna] == 0){
                tablero[fila][columna] = 1;
                continuar = 0;
            }else{
                continuar = 1;
                while(continuar == 1 ){
                    printf("\nLa posicion elegida ya esta en uso");
                    printf("\nIngrece su fila: ");
                    scanf(" %d", &fila);
                    fila = fila-1;
                    printf("\nIngrece su columna: ");
                    scanf(" %d", &columna);
                    columna = columna - 1;
                    if (tablero[fila][columna] == 0){
                        tablero[fila][columna] = 1;
                        continuar = 0;
                    }
                }
            }
        } else {
            if (tablero[fila][columna] == 0){
                tablero[fila][columna] = 2;
            }else{
                continuar = 1;
                while(continuar == 1 ){
                    printf("\nLa posicion elegida ya esta en uso");
                    printf("\nIngrece su fila: ");
                    scanf(" %d", &fila);
                    fila = fila-1;
                    printf("\nIngrece su columna: ");
                    scanf(" %d", &columna);
                    columna = columna - 1;
                    if (tablero[fila][columna] == 0){
                        tablero[fila][columna] = 2;
                        continuar = 0;
                    }
                }
            }
        }

        for (int i= 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (tablero[i][j] == 1){
                    contador1++;
                }else if (tablero[i][j] == 2){
                    contador2++;
                }
            }
            if (contador1 == 3){
                i = 3;
                ganador = 1;
            } else if (contador2 == 3){
                i = 3;
                ganador = 2;
            }
            contador1 = 0;
            contador2 = 0;
        }

        for (int i= 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (tablero[j][i] == 1){
                    contador1++;
                }else if (tablero[j][i] == 2){
                    contador2++;
                }
            }
            if (contador1 == 3){
                i = 3;
                ganador = 1;
            } else if (contador2 == 3){
                i = 3;
                ganador = 2;
            }
            contador1 = 0;
            contador2 = 0;
        }

        if ((tablero[0][0] == 1 && tablero[1][1] == 1 && tablero[2][2] == 1) || (tablero[0][2] == 1 && tablero[1][1] == 1 && tablero[2][0] == 1)){
            ganador = 1;
        } else if ((tablero[0][0] == 2 && tablero[1][1] == 2 && tablero[2][2] == 2) || (tablero[0][2] == 2 && tablero[1][1] == 2 && tablero[2][0] == 2)){
            ganador = 2;
        }
        
        turno=cambioTurnos(turno);
        contadorGen++;
    }while(ganador != 1 && ganador != 2 && contadorGen != 9);
    
    
    if (ganador == 1){
        printf("\n  1 2 3\n1 %d %d %d\n2 %d %d %d\n3 %d %d %d", tablero[0][0], tablero[0][1], tablero[0][2], tablero[1][0], tablero[1][1], tablero[1][2], tablero[2][0], tablero[2][1], tablero[2][2]);
        printf("\nEl ganador es el 1");
    }else if(ganador == 2){
        printf("\n  1 2 3\n1 %d %d %d\n2 %d %d %d\n3 %d %d %d", tablero[0][0], tablero[0][1], tablero[0][2], tablero[1][0], tablero[1][1], tablero[1][2], tablero[2][0], tablero[2][1], tablero[2][2]);
        printf("\nEl ganador es el 2");
    }

    if(contadorGen == 9){
        printf("\n  1 2 3\n1 %d %d %d\n2 %d %d %d\n3 %d %d %d", tablero[0][0], tablero[0][1], tablero[0][2], tablero[1][0], tablero[1][1], tablero[1][2], tablero[2][0], tablero[2][1], tablero[2][2]);
        printf("\nHubo un empate");
    }
    printf("Saliendo del programa...");
    return 0;
}