
/*
Dominic Taraska

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//int input_to_decimal(char *input);
unsigned int bin_to_uint(char *input);
unsigned int oct_to_uint(char *input);
unsigned int hex_to_uint(char *input);
unsigned int dec_to_uint(char *input);
void uint_to_hex(unsigned int n, char *output);
void uint_to_oct(unsigned int n, char *output);
void uint_to_bin(unsigned int n, char *output);


int error = 0;


int main(){

    char input[50];
    unsigned int n = 0;
    char output[50];


    //Enter one of the base identifiers followed by the number
    printf("Enter a binary, octal, decimal or hexadecimal number\n");
    printf("convert > ");
    gets(input);

    // Detect input data type
    // Hexadecimal
    if(input[0] == '0' && input[1] == 'x'){
        n = hex_to_uint(input);
    }
    // Decimal
    else if(input[0] >= '0' && input[0] <= '9'){
        n = dec_to_uint(input);
    }
    // Octal
    else if(input[0] == 'o'){
        n = oct_to_uint(input);
    }
    // Binary
    else if(input[0] == 'b'){
        n = bin_to_uint(input);
    }
    // Unknown
    else{
        printf("ERROR: Unknown data type: %s\n", input);
    }

    // Print results
    printf("The decimal value of %s is %u\n", input, n);
    uint_to_hex(n, output);
    printf("The hexadecimal value of %s is %s\n", input, output);
    uint_to_oct(n, output);
    printf("The octal value of %s is %s\n", input, output);
    uint_to_bin(n, output);
    printf("The binary value of %s is %s\n", input, output);


    return 0;
}



// Convert a hexadecimal char array to uint
unsigned int hex_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    // Declare and set multiplier to 1
    int multi = 1;


    // Declare iterator

    int x;

    // Loop through value part of input string
    for(x = strlen(input)-1; x >= 2; x--){

        // If between 0 and 9 add 0 to 9 to res with multiplier

        if(input[x] >= 48 && input[x] <= 57){
            res += (input[x] - '0')*multi;
        }

        // If between A and F add 10 to 15 to res with multiplier
        if(input[x] >= 65 && input[x] <= 70){
            res += (input[x] - 55)*multi;
        }


        // Error - exit
        else{
            printf("Error: Unrecognized character");
            exit(0);
        }

        // Advance multiplier to next position value
        multi *= 16;
    }

    return res;
}



// Convert a unsigned integer char array to uint
unsigned int dec_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;

    int multi = 1;

    int x;

    // Loop through value part of input string
    for(x = strlen(input)-1; x >= 0; x--){

        // If between 0 and 9 add 0 to 9 to res

        if(input[x] >= 48 && input[x] <= 57){
            res += (input[x] - '0')*multi;
        }

        // Error - exit
        else{
            printf("Error: Unrecognized character");
            exit(1);
        }
        //advance multiplier
        multi *= 10;
    }

    return res;
}



// Convert a octal char array to uint
unsigned int oct_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    int x;
    int multi = 1;

    // Loop through value part of input string
    for(x = strlen(input)-1; x >= 1; x--){

        // If between 0 and 9 add 0 to 9 to res

        if(input[x] >= 48 && input[x] <= 55){
            res += (input[x] - '0')*multi;
        }

        // Error - exit
        else{
            printf("Error: Unrecognized character");
            exit(1);
        }
        //advance multiplier
        multi *= 8;
    }
    return res;
}


/*
    Copy oct_to_uint() and modify for binary input.
*/
// Convert a binary char array to unsigned int
unsigned int bin_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;

    int x;
    int multi = 1;

    for(x = strlen(input)-1; x >= 1; x--){

        // If between 0 and 9 add 0 to 9 to res

        if(input[x] >= 48 && input[x] <= 49){
            res += (input[x] - '0')*multi;
        }

        // Error - exit
        else{
            printf("Error: Unrecognized character");
            exit(1);
        }
        multi *= 2;
    }

    return res;
}


// Convert a unsigned integer char array to hexadecimal
void uint_to_hex(unsigned int n, char *output){
    // Declare a uint for remainder



    unsigned int rem = 0;

    // Declare an int for division
    unsigned int division = n;

    // Declare a char array buffer
    //REMEMBER TO CHECK FOR SUCCESS AND FREE MEM LATER
    char* buffer = (char*)malloc(8);
    if(buffer == NULL){
            printf("memory alloc unsuccessfull");
            exit(1);
        }


    // Use a loop to generate a hex string - string will be reverse
    int x = 0;
    while (division > 0){




        rem = (division%16);

        division = (division/16);

        if(rem > 9){
            buffer[x] = rem + 55;

        }
        else{
            buffer[x] = rem + '0';

        }

        x++;

        // Get last hex char


    }

    buffer[x+1] = '\0';
    // Put null at end of buffer
    output[0] = '0';
    output[1] = 'x';
    // Copy 0x to output string

    int y;
    int j = x-1;
    // Copy chars from buffer in reverse order to output string
    for(y = 2; y <= x+1; y++){
        output[y] = buffer[j];


        j--;

    }

    output[y+1] = '\0';

    free(buffer);

    return;
}




// Convert a unsigned integer char array to octal
void uint_to_oct(unsigned int n, char *output){
// Declare a uint for remainder
    unsigned int rem = 0;

    // Declare an int for division
    unsigned int division = n;

    // Declare a char array buffer
    //REMEMBER TO CHECK FOR SUCCESS AND FREE MEM LATER
    char* buffer = (char*)malloc(11);
        if(buffer == NULL){
            printf("memory alloc unsuccessfull");
            exit(1);
        }

    // Use a loop to generate a hex string - string will be reverse
    int x = 0;
    while (division > 0){


        rem = (division%8);
        division = (division/8);


        buffer[x] = rem + '0';



        x++;

    }

    buffer[x] = '\0';

    output[0] = 'o';
    int y;
    int j = x-1;
    for(y = 1; y <= x; y++){
        output[y] = buffer[j];
        j--;

    }
    output[y+1] = '\0';
    free(buffer);
    return;
}



// Convert a unsigned integer char array to binary
void uint_to_bin(unsigned int n, char *output){
unsigned int rem = 0;

    // Declare an int for division
    unsigned int division = n;

    // Declare a char array buffer
    //REMEMBER TO CHECK FOR SUCCESS AND FREE MEM LATER
    char* buffer = (char*)malloc(20*8);
    if(buffer == NULL){
            printf("memory alloc unsuccessfull");
            exit(1);
        }

    // Use a loop to generate a hex string - string will be reverse
    int x = 0;
    while (division > 0){


        rem = (division%2);
        division = (division/2);


        buffer[x] = rem + '0';



        x++;

    }

    buffer[x] = '\0';

    output[0] = 'b';
    int y;
    int j = x-1;
    for(y = 1; y <= x; y++){
        output[y] = buffer[j];
        j--;

    }
    output[y+1] = '\0';
    free(buffer);
    return;

}
