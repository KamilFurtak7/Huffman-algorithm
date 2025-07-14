# Huffman algorithm CLI Tool

This project implements a simple Huffman coding program for educational purposes.  
It allows you to input character-frequency or character-probability data, construct a Huffman tree, generate binary codes, and compute compression statistics.

## 🔧 Features

- Supports both **frequency** (count) and **probability** input modes.
- Generates Huffman codes and prints the tree structure.
- Calculates compression efficiency and entropy.
- Includes custom runtime exceptions.
- Input validation with clear error messages.

## 📁 Project Structure
```
main.cpp # Main logic
Huffman.h/.cpp # Huffman tree building and statistics computation
Node.h # Huffman node structure
Drzewo.h/.cpp # Tree visualization (pretty print)
Wyjatki.h/.cpp # Custom runtime exception definitions
dane.txt # Example input data
```

## 📌 Input Format
Each line in the input file should contain:
<char> <value>
### Examples:
  **For frequencies:**
```
  A 10
  B 15
  C 30
```
  
**For probabilities:**
```
  A 0.25
  B 0.50
  C 0.25
```

## Sample Output
<img width="733" height="689" alt="image" src="https://github.com/user-attachments/assets/80dec4b6-1164-4b98-bddd-bb264c161892" />

