#include <iostream>
#include <termios.h>
#include <unistd.h>

// Function to configure terminal for single character input
void configureTerminal(termios &oldt) {
    termios newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

// Function to restore terminal settings
void restoreTerminal(termios &oldt) {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int main() {
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    configureTerminal(oldt);

    while (true) {
        std::cout << "Press an arrow key (q to quit)...\n";
        
        char c;
        read(STDIN_FILENO, &c, 1);

        if (c == 'q') {
            break;
        }

        if (c == '\033') { // ESC character
            read(STDIN_FILENO, &c, 1); // skip '['
            if (c == '[') {
                read(STDIN_FILENO, &c, 1); // get actual arrow key
                switch(c) {
                    case 'A':
                        std::cout << "Up arrow pressed!\n";
                        break;
                    case 'B':
                        std::cout << "Down arrow pressed!\n";
                        break;
                    case 'C':
                        std::cout << "Right arrow pressed!\n";
                        break;
                    case 'D':
                        std::cout << "Left arrow pressed!\n";
                        break;
                }
            }
        }
    }

    restoreTerminal(oldt);
    return 0;
}