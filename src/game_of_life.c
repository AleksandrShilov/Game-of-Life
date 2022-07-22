#include <stdio.h>
#include <stdlib.h>
#define ROWS 25
#define COLS 80

void createPlayingField(int array[][COLS], int row, int column);
void output(int array[][COLS]);
void generationAgeOne(int array[][COLS], int row, int column);
int checkCell(int array[][COLS], int row, int column);
void readLifeCell(int arr[][2], int row, int column);
int countLiveCell(int array[][COLS], int row, int column);
void newLife(int array[][COLS], int new_Array[][COLS]);
void copyLife(int array[][COLS], int new_Array[][COLS]);
void fastInput(int array[][COLS], int row, int column);
void readFile(int matrix[][COLS]);

int main() {
    int game_array[ROWS][COLS], flag = 1;
    char space = ' ';
    int new_game_array[ROWS][COLS];

    createPlayingField(game_array, ROWS, COLS);
    createPlayingField(new_game_array, ROWS, COLS);
    // generationAgeOne(game_array, ROWS, COLS);
    readFile(game_array);

    while (flag == 1) {
        int flag_1 = 1;

        // очистка поля
        output(game_array);  // печать старого
        newLife(game_array, new_game_array);  // старое и новое поле
        while (flag_1 == 1) {
            scanf("%c", &space);
            if (space == ' ') {
                flag_1 = 0;
            }
            if (space == 'q') {
                flag_1 = 0;
                flag = 0;
            }
            // printf("\033C\n");
        }
        // копирование массива
        copyLife(game_array, new_game_array);
    }
    return 0;
}
void createPlayingField(int array[][COLS], int row, int column) {  // заполненение поля нулями
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            array[i][j] = 0;
        }
    }
}
void output(int array[][COLS]) {  // печать игрового поля
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
// void generationAgeOne(int array[][COLS], int row, int column) {  // генерация первого поколения
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < column; j++) {
//             array[i][j] = rand() % 2;
//         }
//     }
// }
void copyLife(int array[][COLS], int new_Array[][COLS]) {  // копирование старого массива
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = new_Array[i][j];
        }
    }
}
void newLife(int array[][COLS], int new_Array[][COLS]) {  // изменение игрового поля
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] == 1 && ((checkCell(array, i, j) - 1) != 2
            && (checkCell(array, i, j) - 1) != 3)) {
                new_Array[i][j] = 0;
            } else if (array[i][j] == 0 && checkCell(array, i, j) == 3) {
                new_Array[i][j] = 1;
            } else {
                new_Array[i][j] = array[i][j];
            }
        }
    }
}
int checkCell(int array[][COLS], int row, int column) {  // проверка на живых соседей
    int count_cell_life = 0;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (array[(row + i + ROWS) % ROWS][(column + j + COLS) % COLS] == 1) {
                count_cell_life++;
            }
        }
    }
    return count_cell_life;
}
void readFile(int matrix[][COLS]) {  // чтение из файла
    int ch;

    printf("1 - Неизвестность № 1\n");
    printf("2 - Неизвестность № 2\n");
    printf("3 - Неизвестность № 3\n");
    printf("4 - Неизвестность № 4\n");
    printf("5 - Неизвестность № 5\n");
    scanf("%d", &ch);
    FILE *file;

    if (ch == 1) {
        file = fopen("one.txt", "r");
    } else if (ch == 2) {
        file = fopen("two.txt", "r");
    } else if (ch == 3) {
        file = fopen("two.txt", "r");
    } else if (ch == 4) {
        file = fopen("two.txt", "r");
    } else if (ch == 5) {
        file = fopen("two.txt", "r");
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            ch = fgetc(file);
            if (ch == 10) {
                ch = fgetc(file);
            }
            if (ch == 48) {
                matrix[i][j] = 0;
            } else if (ch == 49) {
                matrix[i][j] = 1;
            }
        }
    }
    fclose(file);
}
