#pragma once
#include <string>
using namespace std;


class Mastermind
{
    public:
        Mastermind();
        void setRandomColors();
        string colorToString(int);
        string getSolution();
        void setSolution(string);
        int getColorsCorrect(string guess);
        int getPositionsCorrect(string guess);
        char getRandomLetter();

    private:
        string colors;
};

