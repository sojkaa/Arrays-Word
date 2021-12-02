#include <stdio.h>
#include <ctype.h>

#define MAX 1024

int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./word file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("Archivo no encontrado\n");
        return 1;
    }

    // TODO

    int cdt;
    char s;
    cdt=0;
    s=text [cdt];
    int palabras=0, oraciones=0;

    while (s!='\0'){
        s=text [cdt];
        if (s==' '){
            palabras++;
        }
        if (s=='.'){
            oraciones++;
        }
        if (s=='?'){
            oraciones++;
        }
        if (s=='!'){
            oraciones++;
        }
        if (s=='\0'){
            oraciones++;
        }
        cdt++;
    }
    printf ("La cantidad de oraciones es %d", oraciones);
    printf ("La cantidad de palabras es %d", palabras++);

    return 0;
}

int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "frases/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    while ((c = getc(fp)) != EOF) {
        *text = c;
        text++;
    }
    return 0;
}
