#include "crypto.h"

/********************************************************
 *  tab_recta table filling function , uses an 2D array
 *  in order to make the tab_recta square table.
 * ******************************************************/
void tab_recta( char tabula_recta[MAX_ROWS][MAX_COLS] )
{
	int pos , row , col;

	for( row=0; row < MAX_ROWS; row++){
		pos = 0;
		for( col=0; col < MAX_COLS; col++){
			if( S_CHAR+row+col > E_CHAR && row > 0){
				tabula_recta[row][col] = S_CHAR + pos;
				pos++;
			}
		    else 
			tabula_recta[row][col] = S_CHAR+row+col;
		}
	}
	
	return;
}
/***********************************************
 *  Function that prints the contents of
 *  tabula_recta square if you want it.
 * *********************************************/
#if 1
void print_tab_recta( char tabula_recta[MAX_ROWS][MAX_COLS])
{
	int row , col;
	printf(" ******** VIGENERE TABLE ********** ");
	for( row=0; row<MAX_ROWS; row++) {
		printf("\n"); printf("\t");
		for( col=0; col<MAX_COLS; col++){
				printf("%c" , tabula_recta[row][col]);
		}
	} 	

	return;
}
#endif 
/********************************************
 *  vigenere_crypto makes the encryption 
 *  The contents come from tabula_recta square
 *  it takes the plaintext as argument and the
 *  key in order to do the encryption procedure
 *  returns the encrypted string of your msg.
 * ******************************************/
char *vigenere_crypto(char *plain , char *key)
{
	int row_tab_rec , col_tab_rec , i=0;
	char *encrypted = plain; 
	
	while( encrypted[i] ){
		if( !isalpha(encrypted[i])) {
			i++;
			continue;
		}
		row_tab_rec = (key[i] - S_CHAR )%MOD;  // For the apropriate row.
		col_tab_rec = (plain[i] - S_CHAR )%MOD; // For the apropriate column.
		encrypted[i] = tabula_recta[row_tab_rec][col_tab_rec]; // The element of the tabula recta square.
		i++;
	}
	
	return encrypted;
}
/****************************************************
 *  vigenere_decrypto function makes the decryption
 *  in order to gve you the plaintext. It takes 
 *  the encrypted msg and the key. It produces the
 *  decrypted message.
 *  It returns the decrypted string which is the 
 *  previous plaintext.
 * *************************************************/
char *vigenere_decrypto(char *encrypted , char *key)
{
	int i=0;
	
	char *decrypted = encrypted;
	
	while( encrypted[i] ) {
		if( !isalpha(encrypted[i])) {
			i++;
			continue;
		}
		else if( encrypted[i] >= key[i] ) 
			decrypted[i] = encrypted[i] - (key[i]- S_CHAR)%MOD; 
		
		else if ( encrypted[i] < key[i] )  
			decrypted[i] = E_CHAR + 1 - (key[i] - encrypted[i]) ;	
		i++;
	}

	return decrypted;
}
int read_line( char *str , int n)
{
	int ch , i=0;
	while( !isalpha( ch = toupper(getchar() )))
			;
	while( ch!= '\n' && ch != EOF) {
			if( i < n)
				str[i++] = ch;
				ch = toupper(getchar());
	}
	str[i] ='\0';
	
	return i;
}
/****************************************
 * key_repeat function makes the key for
 * the encryption and decryption procedure.
 * When the key is lower than plaintext 
 * the function repeat it in order to be
 * the same in length.
 * **************************************/
void key_repeat(char * plain, char * key) 
{
    size_t len = strlen(key);
    char * copy = malloc(len + 1); 
    size_t i;
         
    /* Copy to internal buf or memory buf if possible */
    if (!copy)
        return;
    strcpy(copy, key);
 
    for (i = 0; *plain; ++plain, ++key) 
        *key = !isalpha(*plain) ? *plain : copy[i++ % len];
    *key = '\0';
	
    free(copy);
}
