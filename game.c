#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char mas[10][21];
    int x = 10, y = 5;
    char move;
    char eda = '*';
    int x0, y0;
    int edaY = 5, edaX = 5;
    int score = 1;

    srand(time(NULL));

    do {
        sprintf(mas[0], "####################");
        for (int i = 1; i < 9; i++) {
            sprintf(mas[i], "#                  #");
        }
        sprintf(mas[9], "####################");

        mas[y][x] = '@';
        mas[edaY][edaX] = eda;

        system("clear");

        for (int i = 0; i < 10; i++) {
            printf("%s\n", mas[i]);
        }

        printf("SCORE: %d\n", score);
        printf("Press \"q\" for exit!\n");
        move = getchar();

        x0 = x;
        y0 = y;

        if (move == 'w') y--;
        if (move == 's') y++;
        if (move == 'a') x--;
        if (move == 'd') x++;

        if (mas[y][x] == '#') {
            x = x0;
            y = y0;
        }

        if (y == edaY && x == edaX ) {
            edaX = rand() * 1.0 / RAND_MAX * 18 + 1;
            edaY = rand() * 1.0 / RAND_MAX * 8 + 1;
            score++;
        }

        if (score == 10) {
            printf("YOU WIN!\n");
            break;
        }

    } while (move != 'q');
    
    return 0;
}