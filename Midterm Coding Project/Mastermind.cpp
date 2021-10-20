#include "Mastermind.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;


Mastermind::Mastermind()
{
    srand (time(NULL));
    //The following command sizes the string and also gives you a known value for testing purposes.
    //Do not remove it even when you get the secret combination working
    colors = "ROGB";

    setRandomColors();
}

//1.  Use a switch statement to return a random letter to represent the colors red, orange, yellow, green, blue
//Generate a Random number and each case will return R, O, Y, G, B
char Mastermind::getRandomLetter()
{
    int x =  rand() % (6);
    switch (x) {
        case 0:
            return 'R';
        case 1:
            return 'O';
        case 2:
            return 'Y';
        case 3:
            return 'G';
        case 4:
            return 'B';
        case 5:
            return 'P';
        default:
            return ' ';
    }
    //return 'A';
}

//2.  Modify the secret combination of colors to be random by calling the getRandomLetter()
//for each position in the string "colors"
void Mastermind::setRandomColors(){
    for(int i = 0; i < colors.length(); i++){
        colors[i] += getRandomLetter();
    }
}


//3.  Return the number of colors that are in the Correct position
//Compare the guess to the "secret" to "colors"
//Example  secret of "RBYG", and colors = "YBGO" would only return 1 since only blue is in the correct position
int Mastermind::getPositionsCorrect(string guess)
{
    int numberCorrect = 0;
    
    for(int i = 0; i < guess.length(); i++){
            if(guess[i] == colors[i]){
                numberCorrect++;
        }
    }
    
    
    return numberCorrect;
}



/*4.  Returns the number of colors that are correct but not in the correct position
      You can assume that there are not any duplicate colors in the guess, or the colors.
      Example: guess = "ROYG" and colors = "RYOB" would return 1, 
         Red doesn't count as it's in the correct position, Green is not a correct color, so only Orange and Yellow count

    Challenge: Get the logic for the colors correct to work for duplicate values...
        For example
        guess = "ROGR" colors = "ORYO" should only be 2 correct for 1 red, and 1 orange. 

*/

int Mastermind::getColorsCorrect(string guess)
{
    int numberCorrect = 0;
    for(int i = 0; i < guess.length(); i++){
        for(int i1 = 0; i1 < colors.length(); i1++){
            if(guess[i] == colors[i]){
                break;
            }else if(guess[i] == colors[i1]){
                numberCorrect++;
            }
        }
    }
    return numberCorrect;
    
}

void Mastermind:: setSolution(string str){
    colors = str;
}

//This is an accessor method to allow you to display the solution
string Mastermind::getSolution()
{
    return colors;
}


