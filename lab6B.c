/*

Dominic Taraska
Tug76525@temple.edu

Proper input:

1. operator(ex: '+', '-', '/', etc...)
2. space
3. number

if number is negative you put '-' immediately before the number after the space.

Examples of proper input:

+ 2

* 5

+ -654

% 65


res is automatically used as first input, so if you want to do 5 * 4, first you have to add 5 to res (res starts off at 0) and then multiple res by 4.



*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
int _add(int a, int b);
int add(int a, int b);
int sub(int a, int b);
int neg(int a);
int mul(int a, int b);
int div1(int a, int b);
int mod(int a, int b);
int pow1(int a, int b);
int convert(char *input);
void menu();


// Main
int main(int argc, char *argv[]){

    int res = 0;        // Cumulative result - running total
    int n = 0;          // For number conversion from input string
    char input[50];     // Input string
    input[0] = '\0';    // Put null in operator char so loop works

    // Write code here to test your functions
    // Uncomment code below when done

    // Loop until quit is selected
    while(input[0] != 'q' && input[0] != 'Q'){
        // Show menu choices
        menu();
        // Print prompt with running total
        printf("\nres = %d > ", res);
        // Get input string
        gets(input);

        // Clear screen
        //system("cls");

        // Switch on operator char input[0]
        switch (input[0]){
            case '+':
                res = add(res, convert(input));

                break;
            case '-':
                res = sub(res, convert(input));
                break;
            case '*':
                res = mul(res, convert(input));
                break;
            case '/':
                res = div1(res, convert(input));
                break;
            case '%':
                res = mod(res, convert(input));
                break;
            case '~':
                res = neg(res);
                break;
            case '^':
                res = pow1(res, convert(input));
                break;
            case 'c':
            case 'C':
                res = 0;
                break;
            case 'q':
            case 'Q':
                printf("Good-bye!\n");
                break;
            default:
                printf("Enter a valid operator and operand\n");

        }

    }


    return 0;
}


// Show menu choices
void menu(){
    printf("\nSafe Integer Calculator\n");
    printf("+ x to add\n");
    printf("- x to subtract\n");
    printf("* x to multiply\n");
    printf("/ x to divide\n");
    printf("%% x to modulus\n");
    printf("~ x to negate\n");
    printf("^ x to raise by power x\n");
    printf("c x to clear result\n");
    printf("q x to quit\n");
    return;
}


/*
    This function should only use bitwise operators and
    relational operators
*/
// Add operation using only bitwise operators
int _add(int a, int b){
    // Loop until b is zero



        // Find carry 1 bits - a AND b assign to carry

        // Find non carry 1 bits - a XOR b assign to a

        // Multiply carry by 2 by shift and assign to b




    // Call to _add() a and b and assign to result

    while( b != 0 ){
        int carry = a&b;

        a = a^b;

        b = carry << 1;
    }


    return a;
}


/*
    Safe add() should call _add() and check for both
    overflow and underflow errors.
*/
// Safe add operation
int add(int a, int b){
    // Declare int for result

    int res = 0;

    // Call to _add() a and b and assign to result




    res = _add(a, b);

    // Check for overflow - look at page 90 in book
    if(a >= 0 && b >= 0 && res < 0){
        printf("Overflow detected.");
    }

    // Check for underflow - look at page 90 in book
    else{
        if(a < 0 && b < 0 && res >= 0){
            printf("underflow detected.");
        }
        else{

        }

    }


    return res;
}


/*
    Negate a by using a bitwise operator and safe add().
    Look on page 95 in book.
    Replace the zero with an expression that solves this.
*/
// Define negation with ~ and safe add
int neg(int a){
    // Return negation of a and add 1

    return add((~a), 1);   // Replace 0 with code
}


/*
    Remember that subtraction is the same as addition
    if you negate one of the operands.
    Replace the zero with an expression that solves this.
*/
// Define safe subtract by safe add - negate b
int sub(int a, int b){
    return (a+neg(b));  // Replace 0 with code
}


/*
    Safe mul() uses an iterative call to safe add()
    to calculate a product. Remember that
        5 x 4 = 5 + 5 + 5 + 5 = 20
*/
// Define safe multiply by calling safe add b times
int mul(int a, int b){
    // Declare and initialize cumulative result
    int res = 0;


    // Declare sign of product - initially assume positive
    int sign = 1;





    // For efficiency - smaller number should be multiplier
    int multi = 0;
    int adder = 0;



    if (b<0){

        b = neg(b);
        sign = neg(sign);



    }
    if (a<0){



        a = neg(a);
        sign = neg(sign);
     }

     if(a <= b){
        multi = a;
        adder = b;
     }
     else{
        multi = b;
        adder = a;
     }





    for(; multi > 0; multi--){







    // Absolute value of a and flip sign



    // Absolute value of b and flip sign


    // Accumulate result

        res = add(res, adder);


    }

    // Set sign to output

    if(sign < 0){
        res = neg(res);
    }


    return res;
}


/*
    Safe div() repeatedly subtracts b from a, counting the
    number of subtractions until a < b, which it returns.
*/
// Define safe divide by calling safe subtract b times
int div1(int a, int b){
    // Declare int to count how many times can b be subtracted from a
    int cnt = 0;
    // Declare sign
    int sign = 1;



    if (b<0){
        b = neg(b);
        sign = neg(sign);


    }
    if (a<0){

        a = neg(a);
        sign = neg(sign);
     }

    // Absolute value of a and flip sign

    // Absolute value of b and flip sign

    // loop to calculate how many times can b be subtracted from a
    for(cnt; a >= b; cnt++){
        a = sub(a, b);
    }

    // Set sign to output

    if(sign < 0){
        cnt = neg(cnt);
    }


    return cnt;
}


/*
    Safe mod() repeatedly subtracts b from a until a < b, returning a.
*/
// Define safe modulus by calling safe subtract
int mod(int a, int b){
    // Absolute value of a
    if (a < 0){
        a = neg(a);
    }

    // Absolute value of b

    if (b < 0){
        b = neg(b);
    }

    // Find remainder by repeated subtraction a - b

    for( ; a >= b; a = sub(a, b)){

    }

    return a;
}


/*
    Safe pow() calculates as the math pow function but
    only uses the safe operations.
        res = n^exp
    Loop until exp is zero
        res = res * n
        exp = exp - 1
    Remember the special case for n^0

*/
// Define safe pow by calling safe multiply exp times
int pow1(int n, int exp){
    // Declare int for result of n^exp
    if(exp == 0){
        return 1;
    }
    int res = n;
    // Loop and multiply to calculate n^exp

    for(exp; exp > 1; exp--){
        res = mul(res, n);
    }

    return res;
}


/*
    This function extracts the integer value from the input string.
        If input = "+ -123", res = -123.
        If input = "* 987654", res = 987654.
    The best way to solve complicated problems is to work them out
    on paper first.
*/
// Extract the integer from the input string and convert to int
int convert(char *input){
    // Declare int for result extracted from input
    int res = 0;
    // Declare int for sign of result
    int sign = 1;

    // Declare two iterators
    int i = 2;
    int j;
    int multi = 1;

    // Declare a buffer for numeric chars
    char buffer[50];

    // Set error to zero - no error found yet
    int error = 0;

    // Check for space in element 1
    if(input[1] != ' '){
        error++;
        printf("Please include a space after operator \n");
        exit(1);

    }


    // Check for negative integer at element 2
    if(input[2] == '-'){
        sign *= -1;
        i = 3;
    }
    else{
        i = 2;
    }



    // Loop to copy all numeric chars to buffer
    // i is iterator for input string and should start at first numeric char
    // j is iterator for buffer where numeric chars are copied
    // This must test for chars between 0 and 9
    for(j = 0 ; i <= strlen(input)-1; j++, i++){
        if(input[i] < 48 || input[i] > 57){
            error++;
            printf("Please only use numeric characters\n");
            exit(1);
        }

        buffer[j] = input[i];

    }






    // i gets position of last numeric char in buffer

    // j is now used for pow function - start at zero
    j -= 1;

    // Construct integer from buffer using pow j increases and i decreases
    for(i = 0; j >= 0; j--){
        if(buffer[j] >= 48 && buffer[j] <= 57){
            res += (buffer[j] - '0')*multi;
        }
        else{
            printf("\n error  \n");

            error++;
        }
        multi *= 10;
    }

    // Set sign for output
    res *= sign;



    return res;
}
