#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]) {

    //looks for two command-line arguments
     if (argc != 2){
        printf("Usage: ./substitution key\n");
        exit(1);
     }

    string key = argv[1];
	int keylength = strlen(key);
    int cond = 0;
	int repeatcount = 0;


	while (cond == 0) {
    // Check for duplicate letters
        for (int j = 0; j < keylength-1; j++)
        {
            for (int k = j+1; k < keylength; k++)
            {
                if ((int)key[j] == (int)key[k])
                {

                    printf("Key must not contain repeated characters.");
                    cond = 1;
                    exit(1);
                }
            }
        }

        // validate alphabetical
        for (int i = 0; i < keylength; i++)
        {
            if ((key[i] > 90 && key[i] < 97) || key[i] > 122 || key[i] < 65)
            {
                printf("Key must only contain alphabetic characters.");
                cond = 1;
                exit(1);
            }

        }

        // validate length
        if (keylength != 26)
            {
                printf("Key must contain 26 characters");
                //key = get_string("\n");
                exit(1);
    	    }
    	    else{
    	       	cond = 1;
    		    //exit(1);
    	    }

	}
		string plaintext = get_string("plaintext: ");
		int length2 = strlen(plaintext);

    	for(int i=0; i < length2; i++){
            char id = plaintext[i];
            switch(id) {
                case 'a':
                	plaintext[i] = tolower(key[0]);
                	break;
                case 'b':
                    plaintext[i] = tolower(key[1]);
                    break;
                case 'c':
                    plaintext[i] = tolower(key[2]);
                    break;
                case 'd':
                    plaintext[i] = tolower(key[3]);
                    break;
                case 'e':
                    plaintext[i] = tolower(key[4]);
                    break;
                case 'f':
                    plaintext[i] = tolower(key[5]);
                    break;
                case 'g':
                    plaintext[i] = tolower(key[6]);
                    break;
                case 'h':
                	plaintext[i] = tolower(key[7]);
                	break;
                case 'i':
                    plaintext[i] = tolower(key[8]);
                    break;
                case 'j':
                    plaintext[i] = tolower(key[9]);
                    break;
                case 'k':
                    plaintext[i] = tolower(key[10]);
                    break;
                case 'l':
                    plaintext[i] = tolower(key[11]);
                    break;
                case 'm':
                    plaintext[i] = tolower(key[12]);
                    break;
                case 'n':
                    plaintext[i] = tolower(key[13]);
                    break;
                case 'o':
                	plaintext[i] = tolower(key[14]);
                	break;
                case 'p':
                    plaintext[i] = tolower(key[15]);
                    break;
                case 'q':
                    plaintext[i] = tolower(key[16]);
                    break;
                case 'r':
                    plaintext[i] = tolower(key[17]);
                    break;
                case 's':
                    plaintext[i] = tolower(key[18]);
                    break;
                case 't':
                    plaintext[i] = tolower(key[19]);
                    break;
                case 'u':
                    plaintext[i] = tolower(key[20]);
                    break;
                case 'v':
                	plaintext[i] = tolower(key[21]);
                	break;
                case 'w':
                    plaintext[i] = tolower(key[22]);
                    break;
                case 'x':
                    plaintext[i] = tolower(key[23]);
                    break;
                case 'y':
                    plaintext[i] = tolower(key[24]);
                    break;
                case 'z':
                    plaintext[i] = tolower(key[25]);
                    break;
                case 'A':                               //UPPERCASE
                    plaintext[i] = toupper(key[0]);
                    break;
                case 'B':
                    plaintext[i] = toupper(key[1]);
                    break;
                case 'C':
                    plaintext[i] = toupper(key[2]);
                    break;
                case 'D':
                    plaintext[i] = toupper(key[3]);
                    break;
                case 'E':
                    plaintext[i] = toupper(key[4]);
                    break;
                case 'F':
                    plaintext[i] = toupper(key[5]);
                    break;
                case 'G':
                    plaintext[i] = toupper(key[6]);
                    break;
                case 'H':
                    plaintext[i] = toupper(key[7]);
                    break;
                case 'I':
                    plaintext[i] = toupper(key[8]);
                    break;
                case 'J':
                    plaintext[i] = toupper(key[9]);
                    break;
                case 'K':
                    plaintext[i] = toupper(key[10]);
                    break;
                case 'L':
                    plaintext[i] = toupper(key[11]);
                    break;
                case 'M':
                    plaintext[i] = toupper(key[12]);
                    break;
                case 'N':
                    plaintext[i] = toupper(key[13]);
                    break;
                case 'O':
                    plaintext[i] = toupper(key[14]);
                    break;
                case 'P':
                    plaintext[i] = toupper(key[15]);
                    break;
                case 'Q':
                    plaintext[i] = toupper(key[16]);
                    break;
                case 'R':
                    plaintext[i] = toupper(key[17]);
                    break;
                case 'S':
                    plaintext[i] = toupper(key[18]);
                    break;
                case 'T':
                    plaintext[i] = toupper(key[19]);
                    break;
                case 'U':
                    plaintext[i] = toupper(key[20]);
                    break;
                case 'V':
                    plaintext[i] = toupper(key[21]);
                    break;
                case 'W':
                    plaintext[i] = toupper(key[22]);
                    break;
                case 'X':
                    plaintext[i] = toupper(key[23]);
                    break;
                case 'Y':
                    plaintext[i] = toupper(key[24]);
                    break;
                case 'Z':
                    plaintext[i] = toupper(key[25]);
                    break;

            }
                    cond = 2;
        }
        if (cond ==2) {
        printf("ciphertext: %s\n", plaintext);
        exit(0);
        }
        exit(0);
}