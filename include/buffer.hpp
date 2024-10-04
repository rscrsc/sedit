#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <string>
#include <vector>

class Buffer {
public:
    Buffer();
    
    void insert(const std::string& text, size_t position);
    void remove(size_t position, size_t length);
    void display() const;
    const std::string& getContent() const;

private:
    std::vector<std::string> lines;
};

#endif // BUFFER_HPP