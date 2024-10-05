#include <ncurses.h>
#include "Buffer.hpp"

int main() {
    initscr();            // Initialize NCurses
    cbreak();             // Enable line buffering
    noecho();             // Do not echo input characters

    Buffer myBuffer;  // Create a buffer instance
    myBuffer.insert("Hello, World!", 0); // Insert text at the start
    myBuffer.insert("This is a Vim-like buffer.", 14); // Insert text after first line

    // Display the buffer content
    myBuffer.display(); 

    // Wait for user input
    getch();

    endwin(); // End NCurses mode
    return 0;
}