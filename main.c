#include "func.h"

int main(){
    system("clear");
    FILE *words;
    if ((words = fopen("words.txt", "r")) == NULL){
        printf("Ошибка открытия файла!\n");
        return 1;
    }
    int sizeFile = 0, sizeWord, stayed_char, i, k = 0, err = 0, count = 0;
    char word[20] = {0}, symbols[27] = {0}, symbol;
    while (fscanf(words, "%s", word) != EOF)
        sizeFile++;
    fseek(words, 0, SEEK_SET);
    sizeFile = getrand(0, sizeFile);
    for(i = 0; i < sizeFile; i++)
        fscanf(words, "%s", word);
    fclose(words);

    sizeWord = length_string(word);
    stayed_char = sizeWord;

    char *unknown_Word = calloc(sizeWord, sizeof(char));
    for (i = 0; i < sizeWord; i++)
        unknown_Word[i] = '_';
    
    while (stayed_char >= 0 && err <= 9){
        system("clear");
        if (k == 1)
            err++;
        hangman(err);
        
        if (err == 9){
            printf("\nВы проиграли!");
            printf("\nЗагаданное слово: %s\n", word);
            free(unknown_Word);
            return 0;
        }
        if (stayed_char == 0){
            printf("%s", word);
            printf("\nВы победили!\n");
            free(unknown_Word);
            return 0;
        }

        printf(" %s\n", unknown_Word);
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
        for (i = 0; i < count;){
            if (symbols[i] == symbol){
                k = 0;
                break;
            }
            else
                i++;
        }
        if ( i == count)
            symbols[count++] = symbol;
    }
    return 0;
}




