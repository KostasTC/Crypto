#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX_ROWS 26
#define MAX_COLS 26
#define MAX_LEN_PLAINTEXT 50
#define S_CHAR 'A'  // Starting char of latin alphabet
#define E_CHAR 'Z'  // Ending char of latin alphabet
#define MOD 26
char *vigenere_crypto( char *plain, char *key);
char *vigenere_decrypto( char *encrypted , char *key);
void tab_recta( char tabula_recta[MAX_ROWS][MAX_COLS] );
void print_tab_recta( char tabula_recta[MAX_ROWS][MAX_COLS] );
int read_line( char *str , int n);
void key_repeat( char *plain , char *key);
char tabula_recta[MAX_ROWS][MAX_COLS];
