#include "func.h"

void hangman(int n){ //функция выводящая на экран изображение виселицы
    switch (n) {
    case 9: printf("  ____ |\n |   | |\n |   O |\n |  /|\\|\n_|_ / \\|  "); break;    
    case 8: printf("  ____ |\n |   | |\n |   O |\n |  /|\\|\n_|_ /  |  "); break;
    case 7: printf("  ____ |\n |   | |\n |   O |\n |  /|\\|\n_|_    |  "); break;
    case 6: printf("  ____ |\n |   | |\n |   O |\n |  /| |\n_|_    |  "); break;
    case 5: printf("  ____ |\n |   | |\n |   O |\n |   | |\n_|_    |  "); break;
    case 4: printf("  ____ |\n |   | |\n |   O |\n |     |\n_|_    |  "); break;
    case 3: printf("  ____ |\n |     |\n |     |\n |     |\n_|_    |  "); break;
    case 2: printf("       |\n |     |\n |     |\n |     |\n_|_    |  "); break;
    case 1: printf("       |\n       |\n       |\n       |\n___    |  "); break;
    case 0: printf("       |\n       |\n       |\n       |\n       |  "); break;
    }
}

int getrand(int min, int max) //Функция генерации случайных чисел
{
    srand(time(NULL));
    return (int)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int length_string(char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++);
    return i;
}
