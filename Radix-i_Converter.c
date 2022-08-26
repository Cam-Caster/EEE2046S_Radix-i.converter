#include <stdio.h>
#include <math.h>

//Declare function that takes 2 integers and converts the first into a radix of base the second
void Dec2RadixI(int decValue, int radValue);

void Dec2RadixI(int decValue, int radValue)
{
    int digits,i,n;
    n = decValue;
    char hex[16] = "0123456789ABCDEF";      //given max base size of 16, thus at most hexadecimal

    digits = log10(decValue)/log10(radValue);    //calculates the amount of digits the new radix-n number will have
    char new[digits];             //declares string to which new digits will be written to

    for(i=digits; i>=0; i--) {             //for loop divides by the base, with each iteration the remainder is appended to the new[] string
                                           //division done as many times as there were digits calculated
        new[i]= hex[n%radValue];
        n = n/radValue;          
    }
    printf("The radix-%d value is %s\n",radValue,new);         //prints the now converted value
}






int main() {

    #define TITLE "DECIMAL TO RADIX-i converter"
    #define AUTHOR "THMCAM009"
    #define YEAR 2022

        //prints the title card above the functions
    printf("*****************************\n%s\nWritten by: %s\nDate: %d\n*****************************\n",TITLE,AUTHOR,YEAR);


    int conv,rad,result;
    conv = 0;
    while(conv>=0){
        printf("Enter a decimal number: ");                        //function prompts the user for a decimal value, recordss it then displays it back
        scanf("%d", &conv);
        if(conv>=0) {       //function checks if the given value is >=0, if not it won't terminate
            printf("The number you have entered is %d\n",conv);         
            printf("Enter a radix for the converter between 2 and 16: ");   //function prompts the user for a radix value, records it then displays it back
            scanf("%d", &rad);
            printf("The radix you have entered is %d\n",rad);

            printf("The log2 of the number is %0.2f\n",log2(conv));        //displays the log base2 of the given decimal value
            printf("The integer result of the number divided by %d is %d\n",rad,conv/rad);      //displays the decimal divided by the radix
            printf("The remainder is %d\n",conv%rad);                   //displays the remainder of the decimal divided by the radix

            Dec2RadixI(conv, rad);         //calls the conversion function, inputting the decimal and radix values
                                           //the function prints the decimal value converted into a base of radix


        }
        else {            //this exits the loop once a value less than zero is inputted when prompted for a decimal value
            printf("EXIT"); }
    }

    return 0;
}