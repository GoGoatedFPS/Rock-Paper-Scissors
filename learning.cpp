#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

void displayHeader() {
    std::cout << "\n=========================================\n";
    std::cout << "        🎮 Rock-Paper-Scissors 🎮      \n";
    std::cout << "=========================================\n";
}

void displayChoices() {
    std::cout << "\nChoose your move:\n";
    std::cout << "  1. ✊ Rock\n";
    std::cout << "  2. 📄 Paper\n";
    std::cout << "  3. ✌️ Scissors\n";
    std::cout << "  0. 🚪 Exit Game\n";
}

std::string choiceToString(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid";
    }
}

void announceResult(int playerChoice, int computerChoice, int& playerScore, int& computerScore, int& draws) {
    std::cout << "\nYou picked: " << choiceToString(playerChoice) << "\n";
    std::cout << "Computer picked: " << choiceToString(computerChoice) << "\n";
    if (playerChoice == computerChoice) {
        std::cout << "🤝 It's a draw!\n";
        draws++;
    } else if ((playerChoice == 1 && computerChoice == 3) || 
               (playerChoice == 2 && computerChoice == 1) ||
               (playerChoice == 3 && computerChoice == 2)) {
        std::cout << "🎉 You win!\n";
        playerScore++;
    } else {
        std::cout << "💻 Computer wins!\n";
        computerScore++;
    }
}

void playGame(int rounds) {
    int playerScore = 0;
    int computerScore = 0;
    int draws = 0;
    int choice;

    for (int round = 1; round <= rounds; ++round) {
        std::cout << "\n🔄 Round " << round << ":\n";
        displayChoices();
        std::cout << "Enter your choice (1-3 or 0 to exit): ";
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "\n👋 Thanks for playing! Final scores: You = " << playerScore << ", Computer = " << computerScore << ", Draws = " << draws << "\n";
            return;
        }

        if (choice < 1 || choice > 3) {
            std::cout << "🚫 Invalid choice. Please select a number between 1 and 3.\n";
            --round;
            continue;
        }

        int computerChoice = std::rand() % 3 + 1;
        announceResult(choice, computerChoice, playerScore, computerScore, draws);
        
        std::cout << "✨ Current scores: You = " << playerScore << ", Computer = " << computerScore << ", Draws = " << draws << "\n";
    }

    std::cout << "\n🎊 Final scores after " << rounds << " rounds: You = " << playerScore << ", Computer = " << computerScore << ", Draws = " << draws << "\n";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    while (true) {
        displayHeader();
        int rounds;
        std::cout << "How many rounds would you like to play? ";
        std::cin >> rounds;

        while (rounds <= 0) {
            std::cout << "⚠️ Please enter a valid number of rounds (greater than 0): ";
            std::cin >> rounds;
        }

        playGame(rounds);

        char playAgain;
        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            std::cout << "👋 Thanks for playing! Goodbye!\n";
            break;
        }
    }

    return 0;
}
