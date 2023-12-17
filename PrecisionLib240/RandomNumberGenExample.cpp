#include <iostream>
#include <ctime>
#include "RandomNumberGen.h"

int rollDice() {
    return generateRandomInt(1, 6); // Rolling a standard 6-sided die
}

int main() {
    unsigned int seedValue = static_cast<unsigned int>(time(0));
    seedRandomGenerator(seedValue);

    std::cout << "Let's play a dice game!\n";

    int playerScore = 0;
    int computerScore = 0;

    const int NUM_ROUNDS = 5;

    for (int round = 1; round <= NUM_ROUNDS; ++round) {
        std::cout << "\nRound " << round << ":\n";

        // Player's turn
        std::cout << "Rolling the dice for the player...\n";
        int playerRoll = rollDice();
        std::cout << "Player rolled: " << playerRoll << std::endl;
        playerScore += playerRoll;

        // Computer's turn
        std::cout << "Rolling the dice for the computer...\n";
        int computerRoll = rollDice();
        std::cout << "Computer rolled: " << computerRoll << std::endl;
        computerScore += computerRoll;
    }

    // Determine the winner
    std::cout << "\nGame Over!\n";
    std::cout << "Player's total score: " << playerScore << std::endl;
    std::cout << "Computer's total score: " << computerScore << std::endl;

    if (playerScore > computerScore) {
        std::cout << "Congratulations! You win!\n";
    } else if (playerScore < computerScore) {
        std::cout << "Computer wins! Better luck next time.\n";
    } else {
        std::cout << "It's a tie!\n";
    }

    return 0;
}
