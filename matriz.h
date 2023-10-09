#include <string>

class jogador {
    public:
        int posx = 0, velx = 2, points = 0;
        jogador();
        void moveJogador(int dir);  
};

class bola {
    public:
        int posx = 2, posy = 2, velx = 1, vely = 1;
        bola();
        void colidiu(jogador *jog);
        void moveBola();
};  

class matriz{
    private:
        char mat[25][110];
        void completaMatriz();
    public:
        matriz();
        void imprimeMatriz(bola bola, jogador jog);
};