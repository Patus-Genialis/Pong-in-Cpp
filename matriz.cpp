#include "matriz.h"
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

bola::bola(){}

void bola::colidiu(jogador *jog) {
    if (this->posy == 2) {
        if (this->posx == jog->posx || this->posx == jog->posx + 1 || this->posx == jog->posx + 2 || this->posx == jog->posx + 3){
            this->vely *= -1;
            jog->points++;
        }
    }
    if (this->posx <= 0 || this->posx >= 24) {
        this->velx *= -1;
    }
    if (this->posy >= 108) {
        this->vely *= -1;
    }
    if (this->posy <= 0) {
        char c;
        cout << "GAME OVER" << endl;
        cout << "CONTINUE? (y/n)" << endl;
        while (c != 'y' && c != 'n'){
             c = getch();
            if (c == 'y') {
                system("cls");
                this->posx = 2;
                this->posy = 2;
                this->velx = 1;
                this->vely = 1;
                jog->points = 0;
            } else if (c == 'n'){
                exit(0);
            } else {
                cout << "Invalido" << endl;
            }
        }
    }
}

matriz::matriz() {
    completaMatriz();
}

void matriz::imprimeMatriz(bola bola, jogador jog) {
    this->mat[bola.posx][bola.posy] = 'O';
    this->mat[jog.posx][1] = '|';
    this->mat[jog.posx + 1][1] = '|';
    this->mat[jog.posx + 2][1] = '|';
    this->mat[jog.posx + 3][1] = '|';
    system("cls");
    cout << "|-------------------------------------------------------------------------------------------------------------|\n";
    for(int i = 0; i < 25; i++) {
        cout << "|" << this->mat[i] << "|\n";
    }
    cout << "|-------------------------------------------------------------------------------------------------------------|\n" << "Pontos: " << jog.points << endl;
    completaMatriz();
}

void matriz::completaMatriz() {
    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < 109; j++) {
            this->mat[i][j] = ' ';
        }
        this->mat[i][109] = '\0';
    }
}

jogador::jogador(){}

void jogador::moveJogador(int dir) {
    if (dir == 'w') {
        if (this->posx > 0){
            this->posx -= 3;
        }
    } else if (dir == 's') {
        if (this->posx + 3 < 24){
            this->posx += 3;
        }
    }
}

void bola::moveBola(){
    this->posx += this->velx;
    this->posy += this->vely;
}
