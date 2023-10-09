// o intuito desse codigo eh basicamente fazer um pong sem nenhuma biblioteca grafica
// Autor: Vinicius Biazi Bastos
// Data: 06/10/2023

#include <iostream>
#include "matriz.h"
#include <conio.h>
#include <windows.h>

using namespace std;

int main(){
    int c;
    system("cls");

    bola b;
    matriz m;
    jogador j;

    while (true){
        b.moveBola();
        m.imprimeMatriz(b, j);
        b.colidiu(&j);
        if (kbhit()){
            c = getch();
            j.moveJogador(c);
        }
        Sleep(40);
    }

    return 0;
}