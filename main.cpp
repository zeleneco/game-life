#include "func.h"
#include <iostream>
#include <unistd.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int x, y, lc, life = 0, size = 9;
    bool end = false;
    printf("Использовать шаблон или новую конфигурацию? (0/1)\n");
    scanf("%i",&lc);
    if(lc) {
        printf("Введите количество живых клеток: ");
        scanf("%i",&lc);
        for(int i = 0; i<lc; i++) {
            printf("Введите координаты живых клеток от 0 до 9 (x y): \n");
            while(1) {
                scanf("%i %i", &x, &y);
                if(x>=0 && x<=9 && y>=0 && y<=9) {
                    generation[x][y] = true;
                    break;
                } else {
                    printf("Координаты клетки должны быть от 0 до 9!\n");
                    sleep(100);
                }
            }
            sleep(100);
        }
    } else {
        system("cls");
        while(!end) {
            printf("Выберите шаблон:\n\n1)Устойчивая фигура: \"Пасека\"\n2)Д");
            printf("олгожитель: \"R-пентамино\"\n3)Периодическая фигура: \"Г");
            printf("алактика Кока\"\n4)Двигающаяся фигура: \"Планер\"\n");
            scanf("%i", &lc);
            switch(lc) {
            case 1: {
                size = 15;
                generation[7][1] = true;
                generation[6][2] = true;
                generation[8][2] = true;
                generation[6][3] = true;
                generation[8][3] = true;
                generation[7][4] = true;
                generation[7][10] = true;
                generation[6][11] = true;
                generation[8][11] = true;
                generation[6][12] = true;
                generation[8][12] = true;
                generation[7][13] = true;
                generation[1][7] = true;
                generation[2][6] = true;
                generation[2][8] = true;
                generation[3][6] = true;
                generation[3][8] = true;
                generation[4][7] = true;
                generation[10][7] = true;
                generation[11][6] = true;
                generation[11][8] = true;
                generation[12][6] = true;
                generation[12][8] = true;
                generation[13][7] = true;
                end = true;
                break; 
            }
            case 2: {
                size = 21;
                generation[8][9] = true;
                generation[9][9] = true;
                generation[9][10] = true;
                generation[9][8] = true;
                generation[10][8] = true;
                end = true;
                break; 
            }
            case 3: {
                size = 15;
                generation[3][3] = true;
                generation[3][4] = true;
                generation[3][5] = true;
                generation[3][6] = true;
                generation[3][7] = true;
                generation[3][8] = true;
                generation[4][3] = true;
                generation[4][4] = true;
                generation[4][5] = true;
                generation[4][6] = true;
                generation[4][7] = true;
                generation[4][8] = true;
                generation[6][3] = true;
                generation[7][3] = true;
                generation[8][3] = true;
                generation[9][3] = true;
                generation[10][3] = true;
                generation[11][3] = true;
                generation[6][4] = true;
                generation[7][4] = true;
                generation[8][4] = true;
                generation[9][4] = true;
                generation[10][4] = true;
                generation[11][4] = true;
                generation[3][10] = true;
                generation[4][10] = true;
                generation[5][10] = true;
                generation[6][10] = true;
                generation[7][10] = true;
                generation[8][10] = true;
                generation[3][11] = true;
                generation[4][11] = true;
                generation[5][11] = true;
                generation[6][11] = true;
                generation[7][11] = true;
                generation[8][11] = true;
                generation[10][6] = true;
                generation[10][7] = true;
                generation[10][8] = true;
                generation[10][9] = true;
                generation[10][10] = true;
                generation[10][11] = true;
                generation[11][6] = true;
                generation[11][7] = true;
                generation[11][8] = true;
                generation[11][9] = true;
                generation[11][10] = true;
                generation[11][11] = true;
                end = true;
                break; 
            }
            case 4: {
                size = 9;
                generation[3][3] = true;
                generation[3][4] = true;
                generation[3][5] = true;
                generation[4][3] = true;
                generation[5][4] = true;
                end = true;
                break; 
            }
            }
            system("cls");
        }
    }
    end = false;
    for(int l = 0; l < size; l++) {
        for(int i = 0; i < size; i++) {
            if(!generation[i][l])
                printf(" .");
            else 
                printf(" X"); 
        }
        printf("\n");
    }
    sleep(1500);
    while(!end) {
        lc = 0;
        system("cls");
        for(int l = 0; l < size; l++)
            for(int i = 0; i < size; i++)
                generation_old[i][l] = generation[i][l];
                
        for(int l = 0; l < size; l++)
            for(int i = 0; i < size; i++)
                countgen[i][l] = check(i, l, size);
                
        for(int l = 0; l < size; l++) {
            for(int i = 0; i < size; i++) {
                if(!generation[i][l]) {
                    if(countgen[i][l] == 3) generation[i][l] = true;
                } else {
                    if(countgen[i][l] != 2 && countgen[i][l] != 3) generation[i][l] = false;
                }
                
                if(!generation[i][l]) {
                    printf("  ");
                } else {
                    printf(" X");
                    life++;
                }
            }
            printf("\n");
        }
        
        if(life == 0) {
            end = true;
            printf("\nВсе клетки погибли.");
        }
        else life = 0;
        
        for(int l = 0; l < size; l++)
            for(int i = 0; i < size; i++) {
                if(generation_old[i][l] != generation[i][l]) lc++;
            }
            
        if(lc == 0) {
            end = true;
            printf("\nСостояние клеток не изменяется.");
        }
        
        sleep(900);
    }
    return 0;
}
