#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    //send the random number generator
    srand(static_cast<unsigned int>(time(0)));

    //generate a random number between 1 and 100
    int random_number = rand()%100 +1;
    int guess = 0;

    cout<< "I'mthinking of a number between 1 and 100." <<endl;
    while (true) {
        cout << "take a guess :";
        cin>>guess;

        if (guess < random_number) {
            cout<< "your guess is too low. try again." <<endl;
        } else if (guess > random_number) {
            cout << "your guess is too high. try again." << endl;
        } else {
            cout<< "congratulations ! you guessed the correct number." << whendl;
            break;
        }
        
    }
    return 0;
}