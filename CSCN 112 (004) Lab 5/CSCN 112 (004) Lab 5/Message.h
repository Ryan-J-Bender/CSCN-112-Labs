#pragma once

#include "Vigenere.h" // Vigenere header file
#include <iostream> // Cout, cin, etc.
#include <fstream> // File input & output
#include <vector> // Vector data type

class Message {
public:

	Message(); // Basic constructor
	Message(std::vector<std::string>); // One argument Constructor
	~Message();

	void setWords(std::string); // Pushes one string into the vector
	std::vector<std::string> getWords() const; // Returns the vector of words

	void setKey(std::string);	// Sets the key using the Vigenere setKey
	std::string getKey() const;		// Returns the key using the Vigenere getKey

	std::string encryptWord(std::string) const; // Returns one encrypted word
	std::string decryptWord(std::string) const; // Returns one decrypted word

	std::string outputString() const;	// Returns the words stored in the vector as one string

private:

	Vigenere vig; // Creates a Vigenere object to be used in message functions
	std::vector<std::string> words; // Vector that contains the words stored when encrypting or decrypting a message
};