#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

int main() {
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int guess = 0;

    std::cout << "I have generated a number between 1 and 100. Can you guess it?\n";

    // Loop until the correct guess
    while (guess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess > randomNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randomNumber << "\n";
        }
    }

    return 0;
}