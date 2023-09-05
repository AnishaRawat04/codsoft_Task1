//***********************************NUMBER GUESSING GAME*********************************************
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int level = 1;
    int maxRange = 10;
    int maxTries = 3;
    int userGuess, secretNumber;

    cout << "\n***************Welcome to the Number Guessing Game!!***************" << endl<<"\n\n";
    cout << "You are currently on Level " << level << endl;
    cout << "You have " << maxTries << " tries to guess the number between 1 and " << maxRange << endl;

    srand(static_cast<unsigned int>(time(nullptr)));

    while (true) {
        secretNumber = rand() % maxRange + 1;

        for (int tries = 1; tries <= maxTries; tries++) {
            cout << "Enter your guess (Attempt " << tries << "): ";
            cin >> userGuess;

            if (userGuess == secretNumber) {
                cout << "Congratulations! You guessed the correct number: " << secretNumber << endl;
                level++;
                maxRange += 50;
                maxTries++;
                cout << "\nYou are now on Level " << level << endl;
                cout << "You have " << maxTries << " tries to guess the number between 1 and " << maxRange << endl;
                break;
            } else if (userGuess < secretNumber) {
                cout << "Too low! Try again." << endl;
            } else {
                cout << "Too high! Try again." << endl;
            }

            if (tries == maxTries) {
                cout << "You've run out of attempts. The secret number was: " << secretNumber << endl;
                cout << "\n----------Game Over!!----------" << endl;
                return 0;
            }
        }
    }

    return 0;
}
