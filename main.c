#include "func.h"

int main(){
    system("clear");
    FILE *words;
    if ((words = fopen("words.txt", "r")) == NULL){
        printf("Ошибка открытия файла!\n");
        return 1;
    }
    int sizeFile = 0, sizeWord, stayed_char, i, k = 0, err = 0, count = 0;
    char buffer[40], word[40] = {0}, *keyword, symbols[20] = {0}, symbol;
    while (fscanf(words, "%s", buffer) != EOF)
        sizeFile++;
    fseek(words, 0, SEEK_SET);
    for(i = 0; i < getrand(0, sizeFile); i++)
        fscanf(words, "%s", word);
    fclose(words);

    sizeWord = length_string(word);
    stayed_char = sizeWord;
//    keyword = (char *)malloc(sizeWord);
    char *unknown_Word = calloc(sizeWord, sizeof(char));
    for (i = 0; i < sizeWord; i++){
        unknown_Word[i] = '_';
//        keyword[i] = word[i];
    }    
    
    while (stayed_char >= 0 && err <= 9){
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
        k = 1;
        for (i = 0; i < sizeWord; i++){
            if (word[i] == symbol){
                k = 0;
                stayed_char--;
                unknown_Word[i] = word[i];
            }
        }
        symbols[count++] = symbol;
        
    }
    
    



    return 0;
}




