#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <string>

class MotorStatus {
    private:
    uint8_t motorState; // Each bit represents the status of a motor (on/off)
    uint8_t overheatingMotors = 0; // Motors that are overheating
    int turnCount;

    // Function to randomly initialize motors (on/off) and overheat one motor
    void initialize() {
        std::srand(time(0));

        do {
            motorState = static_cast<uint8_t>(std::rand() % 256);
        } while (motorState == 0); // Ensure at least one motor is ON

        turnCount = 0;

        updateOverheating();
        displayStatus();
    }

    // Incrementally overheat motors with each turn
    void updateOverheating() {

        if ((motorState & static_cast<uint8_t>(~overheatingMotors)) == 0) {
            // All ON motors already overheating
            turnCount++;
            return;
        }

        int newMotor = 0;

        do {
            newMotor = std::rand() % 8;
        } while (((static_cast<uint8_t>(1u << newMotor) & motorState) == 0) || ((static_cast<uint8_t>(1u << newMotor) & overheatingMotors) != 0));

        overheatingMotors |= static_cast<uint8_t>(1u << newMotor);

        turnCount++;
    }

    void displayStatus() {
        std::cout << "Motor State (ON/OFF): " << std::bitset<8>(motorState) << std::endl;
        std::cout << "Overheating Motors: " << std::bitset<8>(overheatingMotors) << std::endl;
        std::cout << "Turn Count: " << turnCount << std::endl << std::endl;
    }

    public:
    MotorStatus() {
        initialize();
    }

    // =====================================
    // =========EDIT THIS FUNCTION==========
    // =====================================

    bool turnOff(uint8_t guess) {
        bool correct = (guess == overheatingMotors);
        
        uint8_t motorsToTurnOff = guess & overheatingMotors;
        
        motorState &= ~motorsToTurnOff;
        
        overheatingMotors &= ~motorsToTurnOff;

        if (correct) {
            std::cout << "Correct! You shut down the overheating motors!\n";
        }
        else {
            std::cout << "Wrong guess! More motors are overheating!\n";
            updateOverheating();
        }

        displayStatus();
        
        return correct;
    }
};

int checkInput(const std::string& s) {
    int value = 0;
    bool ok = true;

    // Parse binary
    if (s.size() == 8 && s.find_first_not_of("01") == std::string::npos) {
        for (char c : s) {
            value = (value << 1) | (c - '0');
        }

        return value;
    }

    // Parse hex (0x..)
    else if (s.size() >= 3 && (s.rfind("0x", 0) == 0 || s.rfind("0X", 0) == 0)) {
        try {
            value = std::stoul(s, nullptr, 16);

            if (value > 255) {
                ok = false;
            }
        } catch (...) {
            ok = false;
        }

        if (ok) {
            return value;
        }
    }

    std::cout << "Invalid input. Use 8-bit binary (00101000) or hex (0x28).\n\n";
    return -1;
}

// =====================================
// =========EDIT THIS FUNCTION==========
// =====================================

int main() {
    MotorStatus motorStatus;

    uint8_t guess = 0;
    
    std::cout << "Motor Meltdown\n";
    std::cout << "Enter your guess as:\n";
    std::cout << " - 8-bit binary (e.g., 00101000)\n";
    std::cout << " - hex (e.g., 0x28)\n";
    std::cout << "Type 'q' to quit.\n";

    std::string s;

    while (true) {
        std::cout << "Your guess: ";
        std::cin >> s;

        if (!std::cin) 
        break;

        int value = checkInput(s);

        if (value == -1) 
        continue;

        guess = static_cast<uint8_t>(value);

        bool correct = motorStatus.turnOff(guess);

        if (correct) {
            std::cout << "Game Over. Motors saved!\n";
            break;
        }
    }

    return 0;
}