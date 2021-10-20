#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Mastermind.h"

using namespace std;

void menu();
void playGame();
void testRandomColor(int &score);
void testRandomCombination(int &score);
void testGetPositionsCorrect(int &score);
void testGetColorsCorrect(int &score);

template<class Type>
void checkTest(string testName, Type expected, Type is, int &score);


int main()
{
    srand(time(NULL));
    int score = 0; 
    testRandomColor(score);
    testRandomCombination(score);
    testGetPositionsCorrect(score);
    testGetColorsCorrect(score);
    cout << endl << "Score: " << score << endl;
    playGame();

    return 0;
}


void testRandomColor(int &score){
  Mastermind game;
  int change = 0;
  char temp = 'A';
  
  for(int i = 0; i < 100; i++){
    char letter = game.getRandomLetter();
    if(letter != temp){
        change++;
    }
    temp = letter;
  }
      checkTest("1. Get Random Letter Test", change > 10, true, score);

}

void testRandomCombination(int &score){
    int change = 0;
    Mastermind game1;
    Mastermind game2;

    for(int i = 0; i < 100; i++){
      game1.setRandomColors();
      game2.setRandomColors();

      if(game1.getSolution() != game2.getSolution()){
        change ++;
      }   
    }
    checkTest("2. Check Secret Combination", change > 10, true, score); 
}

void testGetPositionsCorrect(int &score){
    Mastermind game;
    game.setSolution("ROBG");
    int cc = game.getPositionsCorrect("ROBY");
    checkTest("3. Check Positions Correct", cc, 3, score);

}

void testGetColorsCorrect(int &score){
  Mastermind game;
  game.setSolution("ROGB");
  int cc = game.getColorsCorrect("ROBY");
  checkTest("4. Check Colors Correct", cc, 1, score);
  game.setSolution("ROGR");
  cc = game.getColorsCorrect("ORYO");

  if(cc == 2){
    score += 1;
    cout << "Nice work on the Challenge" << endl;
  }
}

template<class Type>
void checkTest(string testName, Type expected, Type is, int &score){
  if(expected == is){
    score += 5;
    cout << testName << ": passed "<< endl;
  }
  else{
    cout << testName << ": failed" << endl;
  }
}

void playGame(){
        menu();
    //Declares an instance of the class
    Mastermind game;
    //The user's guess
    string guess;

    //Give 10 chances to guess
    int i;
    for(i = 10; i > 0; i--)
    {
        //Allow them to guess
        cout << "Guess " << i << ": ";
        cin >> guess;
        //Find the colors and positions correct
        int pc = game.getPositionsCorrect(guess);
        int colors = game.getColorsCorrect(guess);
        //Win if they get all positions correct
        if(pc==4)
        {
               break;
        }
        cout << "Positions Correct:  " << pc << endl;
        cout << "Colors Correct: " << colors << endl;
    }
    //Lose if i counts down to zero
    if(i == 0)
    {
        cout << "Sorry, the combination was: " << game.getSolution() << endl;
    }
    else
    {
        cout << "Great Job:  " << game.getSolution() << endl;
    }
    
}

void menu()
{
    cout << " __  __           _                      _           _ " << endl;
    cout << "|  \\/  | __ _ ___| |_ ___ _ __ _ __ ___ (_)_ __   __| |"<< endl;
    cout << "| |\\/| |/ _` / __| __/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` |"<< endl;
    cout << "| |  | | (_| \\__ \\ ||  __/ |  | | | | | | | | | | (_| |"<< endl;
    cout << "|_|  |_|\\__,_|___/\\__\\___|_|  |_| |_| |_|_|_| |_|\\__,_|"<< endl;
    cout << "\n\nEnter four letters to guess: (R)ed, (O)range, (Y)ellow, (G)reen, (B)lue, (P)urple\n\n";
    string str = "abcdefg";


}
