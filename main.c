#include "crypto.h"
#include "help.h"

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
						    puts("key is: "); puts(key);
						    printf("\n Cipher: %s " , vigenere_crypto(plain, key) );
						    printf("\n Plaintext: %s ", vigenere_decrypto( plain , key) );
						    break;         
	   case 2 :	 tab_recta( tabula_recta );
						   print_tab_recta( tabula_recta );
						   printf("%s" , HELP);
						   break;          
	   case 3 :	 printf("%s" , CREDITS);
						   break;
	   case 4 :	 printf("Bye!");
						   exit(EXIT_SUCCESS);
			default: printf("There is no such option. Try again!");
			
	    }
	 }
	
	return 0;
}
