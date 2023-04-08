#pragma once

#include <string> // Getline, etc.

class Vigenere {
public:

	Vigenere(); // Basic constructor
	Vigenere(std::string); // 1 Argument constructor
	~Vigenere(); // Destructor

	void setKey(std::string); // Sets key variable

	std::string getKey() const; // Returns key variable

	std::string Encrypt(std::string) const; // Uses the Vigenere Cypher to encrypt a word
	std::string Decrypt(std::string) const; // Uses the Vigenere Cypher to decrypt a word

private:
	
	std::string key; // Key to be used in Vigenere Cypher
};