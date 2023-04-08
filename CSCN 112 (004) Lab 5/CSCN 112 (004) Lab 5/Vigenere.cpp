// Implementation file for the Vigenere class header file

#include "Vigenere.h" // Vigenere header file

Vigenere::Vigenere() { // Basic Constructor
	
	key = "";
}

Vigenere::Vigenere(std::string k) { // 1 Argument Constructor

	k = key;
}

Vigenere::~Vigenere() {} // Destructor

std::string Vigenere::Encrypt(std::string word) const { // Encrypts a word using the Vigenere Cypher

	
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {

		char c = word[i];

		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';

		else if (c < 'A' || c > 'Z')
			continue;

		output += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet[65 - 90 | A - Z]
			
		j = (j + 1) % key.length();
	}
	return output;
}

std::string Vigenere::Decrypt(std::string word) const { // Decrypts a word using the Vigenere Cypher

	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {

		char c = word[i];

		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';

		else if (c < 'A' || c > 'Z')
			continue;

		output += (c - key[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet[65 - 90 | A - Z]
			
		j = (j + 1) % key.length();
	}
	return output;
}

void Vigenere::setKey(std::string keyInput) { // Sets the Vigenere key to the uppercase version of the user input key

	char * ptrKey = &keyInput[0];
	std::string keyOutput = "";

	for (int i = 0; i < keyInput.length(); i++) {

		keyInput[i] = toupper(ptrKey[i]);
		keyOutput = keyOutput + keyInput[i];
	}

	key = keyOutput;
}

std::string Vigenere::getKey() const { // Returns the Key variable

	return key;
}