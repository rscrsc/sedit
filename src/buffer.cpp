#include "Buffer.hpp"
#include <iostream>
#include <stdexcept>

// Constructor to initialize the buffer with an empty line
Buffer::Buffer() {
    lines.emplace_back("");  // Start with one empty line
}

// Insert text at a specific position
void Buffer::insert(const std::string& text, size_t position) {
    size_t line_num = 0;
    size_t char_position = position;

    // Determine the line number and character position
    while (line_num < lines.size() && char_position > lines[line_num].size()) {
        char_position -= lines[line_num].size() + 1; // +1 for newline
        line_num++;
    }

    if (line_num >= lines.size()) {
        lines.emplace_back(""); // Add new line if needed
    }

    // Insert the text at the specific position in the determined line
    lines[line_num].insert(char_position, text);
}

// Remove text starting from a specific position
void Buffer::remove(size_t position, size_t length) {
    size_t line_num = 0;
    size_t char_position = position;

    // Determine the line number and character position
    while (line_num < lines.size() && char_position > lines[line_num].size()) {
        char_position -= lines[line_num].size() + 1; // +1 for newline
        line_num++;
    }

    if (line_num >= lines.size()) {
        throw std::out_of_range("Position out of range");
    }

    // Remove the text from the specific position in the determined line
    lines[line_num].erase(char_position, length);
}

// Display the buffer content
void Buffer::display() const {
    for (const auto& line : lines) {
        std::cout << line << "\n";
    }
}

// Get the complete buffer content as a string
const std::string& Buffer::getContent() const {
    static std::string content;
    content.clear();
    for (const auto& line : lines) {
        content += line + "\n";
    }
    return content;
}