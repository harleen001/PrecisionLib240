#include <iostream>
#include <vector>
using namespace std;



void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;

}
// Function to initialize the RC4 key-scheduling algorithm (KSA)
void initialize(vector<unsigned char>& S, const vector<unsigned char>& key) {
    for (int i = 0; i < 256; ++i)
        S[i] = i;

    int j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + S[i] + key[i % key.size()]) % 256;
        swap(S[i], S[j]);
    }
}

// Function to generate a stream of pseudorandom bytes (PRGA)
vector<unsigned char> generateStream(const vector<unsigned char>& S, int length) {
    int i = 0, j = 0;
    vector<unsigned char> keystream;
    
    for (int k = 0; k < length; ++k) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        int t = (S[i] + S[j]) % 256;
        keystream.push_back(S[t]);
    }
    
    return keystream;
}

// Function to perform RC4 encryption
vector<unsigned char> RC4Encrypt(const vector<unsigned char>& plaintext, const vector<unsigned char>& key) {
    vector<unsigned char> S(256);
    initialize(S, key); // Initialize the state array (S) with the key using KSA
    
    vector<unsigned char> keystream = generateStream(S, plaintext.size()); // Generate keystream using PRGA
    
    vector<unsigned char> ciphertext;
    for (size_t i = 0; i < plaintext.size(); ++i) {
        // XOR each byte of plaintext with corresponding byte from keystream to get ciphertext
        ciphertext.push_back(plaintext[i] ^ keystream[i]);
    }
    
    return ciphertext;
}


// Function to perform RC4 decryption
vector<unsigned char> RC4Decrypt(const vector<unsigned char>& ciphertext, const vector<unsigned char>& key) {
    // Decryption in RC4 is the same as encryption
    return RC4Encrypt(ciphertext, key);
}

int main() {
    // Sample plaintext and key
    vector<unsigned char> plaintext = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!' };
    vector<unsigned char> key = { 'S', 'e', 'c', 'r', 'e', 't', 'K', 'e', 'y' };

    // Encrypt plaintext using RC4 algorithm
    vector<unsigned char> encryptedText = RC4Encrypt(plaintext, key);

    // Display encrypted text
    cout << "Encrypted Text: ";
    for (const auto& byte : encryptedText) {
        cout << hex << (int)byte << " "; // Display encrypted bytes in hexadecimal format
    }
    cout << endl;

   // Decrypt ciphertext using RC4 algorithm
    vector<unsigned char> decryptedText = RC4Decrypt(encryptedText, key);

    // Display decrypted text
    cout << "Decrypted Text: ";
    for (const auto& byte : decryptedText) {
        cout << byte; // Display decrypted bytes as characters
    }
    cout << endl;

    return 0;
}
