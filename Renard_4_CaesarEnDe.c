#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int encrypt();
        int decrypt();
        int decryptKnown();
        int decryptUnknown();
int main(void)
{
        //OG CODE
        char ans[1000];
        puts("encrypt or decrypt");
        puts("1. Encrypt");
        puts("2. Decrypt\n");
        scanf("%s", ans);
        if (strcmp(ans, "encrypt") == 0 || strcmp(ans, "1") == 0){
         encrypt();
        }
        else {
         decrypt();
        }
        return 0;
}
int encrypt(){
        char filename;
        char alph[] = "abcdefghijklmnopqrstuvwxyz";
        int shift;
        int index;
        puts("file to encrypt");
        scanf("%s", &filename);
        FILE* file = fopen(&filename, "r");
fseek(file, 0, SEEK_END);
int fsize = ftell(file);
fseek(file, 0, SEEK_SET);
char* str = malloc(fsize);
fread(str, fsize, 1, file);
fclose(file);
int z;
for(z = 0; z < fsize; z++) {
printf("%c", str[z]);
}
    printf("enter a shift\n");
    scanf("%d", &shift);
    shift = shift%26;
    int a;
    int strLength = strlen(str);
    for(a = 0; a < strLength;a++){
    char *ptr = strchr(alph, str[a]);
    index = ptr - alph;
     if (isalpha(str[a])) {
      str[a]=alph[(index+shift)%26];
}
        else {
        }
}
    printf("encrypted: %s\n", str);
    return 0;
}
int decrypt(void){
        char str[10000] ="";
        puts("shift known?");
        puts("1. yes");
        puts("2. no");
        scanf("%s", str);
        if (strcmp(str, "yes") == 0 || strcmp(str, "1") == 0){
         decryptKnown();
         return 0;
        }
        else {
         decryptUnknown();
         return 0;
        }
        return 0;
}
int decryptKnown(){
        char alph[] = "abcdefghijklmnopqrstuvwxyz";
        char str[10000] ="";
        int shift;
        int index;
    puts("word to decrypt");
    scanf("%s", str);
    puts("enter a shift");
    scanf("%d", &shift);
    shift = shift%26;
    shift = 26 - shift;
    int a;
    int strLength = strlen(str);
    for(a = 0; a < strLength;a++){
    char *ptr = strchr(alph, str[a]);
    index = ptr - alph;
    str[a]=alph[(index+shift)%26];
}
    printf("decrypted: %s\n", str);
    return 0;
}
int decryptUnknown(){
        char filename;
        char alph[] = "abcdefghijklmnopqrstuvwxyz";
        int shift;
        int index;
        puts("file to decrypt");
        scanf("%s", &filename);
        FILE* file = fopen(&filename, "r");
fseek(file, 0, SEEK_END);
int fsize = ftell(file);
fseek(file, 0, SEEK_SET);
char* str = malloc(fsize);
fread(str, fsize, 1, file);
fclose(file);
int z;
for(z = 0; z < fsize; z++) {
 printf("%c", str[z]);
}
        int w;
        for(w=0; w < 26; w++){
         shift = w;
         shift = shift%26;
         shift = 26 - shift;
         int a;
         int strLength = strlen(str);
          for(a = 0; a < strLength;a++){
            char *ptr = strchr(alph, str[a]);
            index = ptr - alph;
            if (isalpha(str[a])) {
             str[a]=alph[(index+shift)%26];
            } else {
            }
          }
       printf("encrypted: %s With Shift of: %d\n", str, w);
     }
    return 0;
}
