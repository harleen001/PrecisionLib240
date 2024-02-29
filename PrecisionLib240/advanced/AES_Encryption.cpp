#include <iostream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <algorithm> 
using namespace std;

// Key for encryption (128 bits)
const std::string key = "my_secret_key_16";

// Number of rounds in AES
const int rounds = 10;

// AES S-box substitution table
const unsigned char sbox[256] = {
    // ... (values omitted for brevity)
};

// AES round constant
const unsigned char Rcon[10] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36
};

// Multiply two numbers in the Galois field
unsigned char gmul(unsigned char a, unsigned char b) {
    unsigned char p = 0;
    unsigned char counter;
    unsigned char hi_bit_set;

    for (counter = 0; counter < 8; counter++) {
        if (b & 1)
            p ^= a;

        hi_bit_set = (a & 0x80) != 0;
        a <<= 1;
        if (hi_bit_set)
            a ^= 0x1B; // Irreducible polynomial in GF(2^8), used for AES
        b >>= 1;
    }

    return p;
}

// SubBytes transformation
void SubBytes(std::vector<std::vector<unsigned char>>& state) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] = sbox[state[i][j]];
        }
    }
}

// ShiftRows transformation
void ShiftRows(std::vector<std::vector<unsigned char>>& state) {
    for (int i = 1; i < 4; i++) {
        std::rotate(state[i].rbegin(), state[i].rbegin() + i, state[i].rend());  // Use rbegin and rend for right rotation
    }
}


// MixColumns transformation
void MixColumns(std::vector<std::vector<unsigned char>>& state) {
    for (int i = 0; i < 4; i++) {
        unsigned char a[4];
        unsigned char b[4];
        for (int j = 0; j < 4; j++) {
            a[j] = state[j][i];
            b[j] = state[j][i] << 1;
            if ((state[j][i] & 0x80) == 0x80) {
                b[j] ^= 0x1B; // XOR with irreducible polynomial
            }
        }

        state[0][i] = b[0] ^ a[1] ^ b[1] ^ a[2] ^ a[3];
        state[1][i] = a[0] ^ b[1] ^ a[2] ^ b[2] ^ a[3];
        state[2][i] = a[0] ^ a[1] ^ b[2] ^ a[3] ^ b[3];
        state[3][i] = a[0] ^ b[0] ^ a[1] ^ a[2] ^ b[3];
    }
}

// AddRoundKey transformation
void AddRoundKey(std::vector<std::vector<unsigned char>>& state, const std::vector<unsigned char>& roundKey) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[j][i] ^= roundKey[i * 4 + j];
        }
    }
}

// KeyExpansion function to generate round keys
vector<vector<unsigned char>> KeyExpansion() {
    vector<vector<unsigned char>> roundKeys(4, std::vector<unsigned char>(rounds * 4, 0));
    vector<unsigned char> temp(4, 0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            roundKeys[j][i] = key[i * 4 + j];
        }
    }

    for (int i = 4; i < rounds * 4; i++) {
        temp = roundKeys[i - 1];

        if (i % 4 == 0) {
            // RotWord
            rotate(temp.begin(), temp.begin() + 1, temp.end());

            // SubWord
            for (int j = 0; j < 4; j++) {
                temp[j] = sbox[temp[j]];
            }

            // XOR with Rcon
            temp[0] ^= Rcon[i / 4 - 1];
        }

        for (int j = 0; j < 4; j++) {
            roundKeys[j][i] = roundKeys[j][i - 4] ^ temp[j];
        }
    }

    return roundKeys;
}

// AES encryption function
vector<vector<unsigned char>> AESEncrypt(const vector<vector<unsigned char>>& input,
                                                   const vector<vector<unsigned char>>& roundKeys) {
    vector<vector<unsigned char>> state = input;

    AddRoundKey(state, roundKeys[0]);

    for (int round = 1; round < rounds; round++) {
        SubBytes(state);
        ShiftRows(state);
        MixColumns(state);
        AddRoundKey(state, roundKeys[round]);
    }

    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state, roundKeys[rounds]);

    return state;
}

int main() {
    std::vector<std::vector<unsigned char>> input = {
        {0x32, 0x88, 0x31, 0xe0},
        {0x43, 0x5a, 0x31, 0x37},
        {0xf6, 0x30, 0x98, 0x07},
        {0xa8, 0x8d, 0xa2, 0x34}
    };

    std::cout << "Original Input:\n";
    for (const auto& row : input) {
        for (const auto& byte : row) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
        }
        std::cout << "\n";
    }

    std::vector<std::vector<unsigned char>> roundKeys = KeyExpansion();

    std::vector<std::vector<unsigned char>> encrypted = AESEncrypt(input, roundKeys);

    std::cout << "\nEncrypted Output:\n";
    for (const auto& row : encrypted) {
        for (const auto& byte : row) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
