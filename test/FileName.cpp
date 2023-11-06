#include <iostream>

int main() {
	std::cout << "test";
}

int key[] = { 8, 131, 214, 191, 186, 15, 133, 27, 56, 78, 231, 188 };
char password_enc[] = "5bf6a6dac85ce0784a7d93ec69f0a5c88a7de13a";

const encrypt = (bytes, key) = > {
	for (var i = 0; i < bytes.length; i++) {
		bytes[i] = bytes[i] ^ key[i % key.length];
	}
	return bytes;
};