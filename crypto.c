/**************************************************************
 * Description: Simple Vigenere Ciphering/Deciphering program
 * Licence : Public 
 * ************************************************************/
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
#define CRYPTO_LABEL " *******   ******  *   *   ***** *******   *******\n" \
                     "*          *    *  *   *   *   *    *      *     *\n" \
                     "*          ******  *****   *****    *      *     *\n" \
                     "*          **        *     *        *      *     *\n" \
                     "*******    * *       *     *        *      *******\n" \
                     
#define CREDITS             "*****************************************\n"\
			    "* Author: Kwstas Tsit                   *\n"\
			    "* Email: obvius1342@yahoo.gr            *\n"\
			    "* Date: 19/12/2014                      *\n"\
			    "* Type : Encryption/Decryption          *\n"\
			    "* Method: Vigenere Algorithm            *\n"\
			    "* More info: Google Vigenere Algorithm  *\n"\
			    "*****************************************\n"\

#define HELP "\nTo encrypt, a table of alphabets can be used, termed a tabula recta the table that you are seing , Vigenere square, or Vigenere table.\n"\
             "It consists of the alphabet written out 26 times in different rows, each alphabet shifted cyclically to the left compared to the previous alphabet\n"\
             "For example, suppose that the plaintext to be encrypted is: ATTACKATDAWN \n"\
             "The person sending the message chooses a keyword and repeats it until it matches the length of the plaintext, for example, the keyword LEMON: LEMONLEMONLE\n"\
             "Each row starts with a key letter. The remainder of the row holds the letters A to Z (in shifted order).\n"\
             "Although there are 26 key rows shown, you will only use as many keys (different alphabets) as there are unique letters in the key string, here just 5 keys, {L, E, M, O, N}.\n"\
             "For successive letters of the message, we are going to take successive letters of the key string, and encipher each message letter using its corresponding key row.\n"\
             "Choose the next letter of the key, go along that row to find the column heading that matches the message character; the letter at the intersection of [key-row, msg-col] is the enciphered letter.\n"\
             "Decryption is performed by going to the row in the table corresponding to the key, finding the position of the ciphertext letter in this row, and then using the column's label as the plaintext.\n"\
             "This program is used only the latin alphabet, does not work with other.\n"\
                                
char *vigenere_crypto( char *plain, char *key);
char *vigenere_decrypto( char *encrypted , char *key);
void tab_recta( char tabula_recta[MAX_ROWS][MAX_COLS] );
void print_tab_recta( char tabula_recta[MAX_ROWS][MAX_COLS] );
int read_line( char *str , int n);
void key_repeat( char *plain , char *key);

char tabula_recta[MAX_ROWS][MAX_COLS];

/*************************************************
 *  main function , call the subroutines 
 *  of tab_recta table , encryption - decryption.
 * ***********************************************/
 
int main(void)
{
	char plain[MAX_LEN_PLAINTEXT]={'\0'};
	char key[MAX_LEN_PLAINTEXT]={'\0'};
	int ch; 

	printf("%s" , CRYPTO_LABEL); 
	for(;;) {
		printf("\nOptions: \n");
		printf(" 1.Encryption/Decryption\n 2.Help \n 3.Credits\n4.Quit\n");
		scanf("%d" , &ch);
		switch(ch) {
		case 1 :	tab_recta( tabula_recta );
				printf("Give the plaintext(up to 50 characters) : ");
				read_line( plain , MAX_LEN_PLAINTEXT ); //read the message.
				printf("Give the key: ");
				read_line( key , MAX_LEN_PLAINTEXT );  // the actual length of user's key. 
				key_repeat( plain , key); 
				puts("Key is: "); puts(key);
				printf("\n Cipher: %s " , vigenere_crypto(plain, key) );
				printf("\n Plaintext: %s ", vigenere_decrypto( plain , key) );
				break;         
	        case 2 :	tab_recta( tabula_recta );
				print_tab_recta( tabula_recta );
				printf("%s" , HELP);
				break;          
	        case 3 :	printf("%s" , CREDITS);
			        break;
	        case 4 :	printf("Bye!");
				exit(EXIT_SUCCESS);
	        default:        printf("There is no such option. Try again!");
	    }
	 }
	
	return 0;
}
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
/**************************************
 * It reads the line from the user.
 * It converts all the letters into capitals
 * Throw away the first lettes if they aren't
 * valid letters (alphabetic)
 * *************************************/
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
         
    /* Copy to internal buf or memory buf if possible */
    if (!copy)
        return;
    strcpy(copy, key);
 
    for (size_t i = 0; *plain; ++plain, ++key) 
        *key = !isalpha(*plain) ? *plain : copy[i++ % len];
    *key = '\0';
	
    free(copy);
}
