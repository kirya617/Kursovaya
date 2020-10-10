#include "func.h"

int main(){
    system("clear");
    FILE *words;
    if ((words = fopen("words.txt", "r")) == NULL){
        printf("Ошибка открытия файла!\n");
        return 1;
    }
    int sizeFile = 0, i;
    char buffer[40], word[40] = {0};
    while (fscanf(words, "%s", buffer) != EOF)
        sizeFile++;
    fseek(words, 0, SEEK_SET);
    for(i = 0; i < getrand(0, sizeFile); i++)
        fscanf(words, "%s", word);
    fclose(words);
    




    return 0;
}

