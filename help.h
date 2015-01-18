#define CRYPTO_LABEL " *******   ******  *   *   ***** *******   *******\n" \
                     "*          *    *  *   *   *   *    *      *     *\n" \
                     "*          ******  *****   *****    *      *     *\n" \
                     "*          **        *     *        *      *     *\n" \
                     "*******    * *       *     *        *      *******\n" \
                     
#define CREDITS "*****************************************\n"\
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
                                
