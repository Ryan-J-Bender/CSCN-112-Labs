// Implementation file for the Message class header file

#include "Message.h" // Message Header file

Message::Message() {} // Does nothing, because vectors do not need to be initialized

Message::Message(std::vector<std::string> w) {	// One argument constructor

	w = words;
}

Message::~Message() {}	// Destructor

void Message::setWords(std::string word) {	// Pushes one string into the vector

		words.push_back(word);
}

std::vector<std::string> Message::getWords() const {	// Returns the vector of words

	return words;
}

void Message::setKey(std::string k) {	// Sets the key using the Vigenere setKey function

	vig.setKey(k);
}

std::string Message::getKey() const {	// Returns the key using the Vigenere getKey function

	return vig.getKey();
}

std::string Message::encryptWord(std::string w) const {	// Encrypts a single word using the Vigenere Encrypt function

	return vig.Encrypt(w);
}

std::string Message::decryptWord(std::string w) const {	// Decrypts a single word using the Vigenere Decrypt function

	return vig.Decrypt(w);
}

std::string Message::outputString() const { // Concatenates the words stored in the vector to one solid string

	std::string output = "";

	for (int i = 0; i < words.size(); i++) {
		output += words.at(i);
		if (i < words.size() - 1) {
			output += " ";
		}
	}
	return output;
}
