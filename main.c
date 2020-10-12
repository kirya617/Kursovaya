#include "func.h"

int main(){
    system("clear");
    FILE *words;
    if ((words = fopen("words.txt", "r")) == NULL){
        printf("Ошибка открытия файла!\n");
        return 1;
    }
    int sizeFile = 0, sizeWord, i, k = 0, err = 0;
    char buffer[40], word[40] = {0}, *keyword, symbols[20] = {0}, symbol;
    while (fscanf(words, "%s", buffer) != EOF)
        sizeFile++;
    fseek(words, 0, SEEK_SET);
    for(i = 0; i < getrand(0, sizeFile); i++)
        fscanf(words, "%s", word);
    fclose(words);

    sizeWord = length_string(word);
//    keyword = (char *)malloc(sizeWord);
    char *unknown_Word = (char *)malloc(sizeWord);
    for (i = 0; i < sizeWord; i++){
        unknown_Word[i] = '_';
//        keyword[i] = word[i];
    }    
    
    while (sizeWord >= 0 && err <= 9){
//        system("clear");
        if (k == 1)
            err++;
        hangman(err);
        
        if (err == 9){
            printf("\nВы проиграли!");
            printf("\nЗагаданное слово: %s\n", word);
            free(unknown_Word);
            return 0;
        }

        printf("%s\n", unknown_Word);
        printf("Введенные буквы: %s\n", symbols);
        printf("Введите букву: ");
        scanf("%s", &symbol);
        if ((int)symbol >= -32 && (int)symbol <= -1) { 
            symbol = (char)((int)symbol - 32);
            printf ("%s\n", symbol);
        }


    }




    return 0;
}

