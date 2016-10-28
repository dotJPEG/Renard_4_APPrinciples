
#include <stdio.h>
#include <string.h>
int encrypt();
	int decrypt();
	int decryptKnown();
	int decryptUnknown();
int main(void)
{
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
	char alph[] = "abcdefghijklmnopqrstuvwxyz";
	char str[100000]; 
	int shift;
	int index;
	printf("word to encrypt\n");
    	scanf("%s",str);
    	printf("shift\n");
    	scanf("%d", &shift);
    	shift = shift%26;
   int a;
   int strLength = strlen(str);
    for(a = 0; a < strLength;a++){
    char *ptr = strchr(alph, str[a]);
   index = ptr - alph;
	str[a]=alph[(index+shift)%26];
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
		//add to unkown method a way to check froma  key for the actual result
	}
	return 0;
}
int decryptKnown(){
	char alph[] = "abcdefghijklmnopqrstuvwxyz";
	char str[10000] =""; 
	int shift;
	int index;
   puts("Enter word to decrypt");
   scanf("%s", str);
   puts("Enter a shift");
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
int decryptUnknown(){	//put in a function to check outputs for words that match a key or something
		char alph[] = "abcdefghijklmnopqrstuvwxyz";
	char str[10000] =""; 
	char newStr[10000] ="";
	int shift;
	int index;
    puts("word to decrypt");
    scanf("%s", str);
    int w;
    for(w=0; w<=26; w++){
		shift = w;
   shift = shift%26;
   shift = 26 - shift;
   int a;
   int strLength = strlen(str);
   for(a = 0; a < strLength;a++){
   char *ptr = strchr(alph, str[a]);
   index = ptr - alph;
	newStr[a]=alph[(index+shift)%26];
}
    printf("decrypted: %s with shift: %d\n", newStr, w);
}
    return 0;

}	


