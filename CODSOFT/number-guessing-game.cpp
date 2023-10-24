//Number guessing game

/*Creating a program that generates a random number and asks the 
user to guess it. Provide feedback on whether the guess is too 
high or too low until the user guesses the correct number*/

#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Linux and macOS
#endif
}

int main() {
    srand(time(0));
    char playAgain;

    do {
        clearScreen();
        cout << "\033[1;36m==============================================================================================================================================\n";
        cout << "\t\t\t\t\t\tWelcome to the Number Guessing Game\n";
        cout << "==============================================================================================================================================\033[0m\n\n";
         cout << "\x1B[1;35m";// Set text color to cyan (ANSI escape code)
        cout << "Instructions:\n";
       
        cout << "1. The computer will generate a random number between 1 and 100.\n";
        cout << "2. You need to guess the correct number.\n";
        cout << "3. After each guess, you will receive feedback on whether the number is too high or too low.\n";
        cout << "4. Keep guessing until you find the correct number.\n";
        cout << "5. Have fun and enjoy the game!\n\n";
         cout << "\x1B[0m";  

        int randomNumber = rand() % 100 + 1; // Generates a random number between 1 and 100
        int userGuess;
        int attempts = 0;

        do {
            if (attempts > 0) {
                cout << "Give another try:";
            } else {
                cout << "Guess a number between 1 and 100: ";
            }
            cin >> userGuess;
            attempts++;
            cout << "\n";
            if (userGuess == randomNumber) {
                cout << "\033[1;32mCongratulations!\033[0m You guessed the correct number in " << attempts << " attempts.\n";
            } else if (userGuess > randomNumber) {
                cout << "\033[1;33mToo High!\033[0m \n " ;
            } else {
                cout << "\033[1;33mToo Low!\033[0m\n ";
            }
        } while (userGuess != randomNumber);

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        cout << "\n";
    } while (playAgain == 'y' || playAgain == 'Y');

     cout << "\033[1;31mThank you for playing the Number Guessing Game!\033[0m" <<"\n"<<endl;
    return 0;
}