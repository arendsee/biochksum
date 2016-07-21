#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void print_chksum(unsigned char chksum[]){
    for(int i = 0; i < SIZE; i++){
        printf("%d ", chksum[i]);
    }
    printf("\n");
}

int main(int argc, char * argv[]){
    FILE * fasta = fopen("sample-data/a1.faa", "r");

    unsigned char chksum[] = {0, 0, 0, 0, 0, 0, 0, 0};

    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    size_t pos = 0;
    unsigned char c = 0;

    while((read = getline(&line, &len, fasta)) != EOF){
        
        if(line[0] == '>'){
            pos = 0;
            continue;
        }
        for(size_t i = 0; i < len; i++){
            c = line[i];
            if(c >= 'A' && c <= 'Z'){
                c += 32;
            }
            if(c >= 'a' && c <= 'z'){
                c = (c - 96) * (256.0 / 26);
                for(size_t j = 0; j < 8; j++){
                    chksum[(j + pos) % 8] += ((128 >> j) & c) | ((c+j) % 8);
                    chksum[(j + pos + 2) % 8] += ((128 >> j) & c) | (((c+j) % 4 << 3));
                    chksum[(j + pos + 4) % 8] += ((128 >> j) & c) | (((c+j) % 8 << 5));
                }
                pos++;
            }
        }
    }
    free(line);
    fclose(fasta);

    print_chksum(chksum);

    return EXIT_SUCCESS;
}
