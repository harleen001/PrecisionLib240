#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

// Rotate right (circular right shift) operation
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

// Define SHA-256 constants
const uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// SHA-256 compression function
void sha256(const std::string& input, uint32_t hash[8]) {
    // Initialize hash values
    uint32_t H[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Pre-processing: Padding the input message
    std::string paddedInput = input;
    paddedInput += static_cast<char>(0x80); // Append a '1' bit

    // Calculate the length of the original message in bits
    uint64_t bitLength = input.length() * 8;
    paddedInput += std::string(64 - ((input.length() + 8) % 64), '\0'); // Zero-padding
    paddedInput += std::string(8, '\0') + std::string(reinterpret_cast<char*>(&bitLength), 8);

    // Process each 512-bit block
    for (size_t i = 0; i < paddedInput.length(); i += 64) {
        uint32_t W[64] = {0};

        // Prepare the message schedule
        for (int t = 0; t < 16; ++t) {
            W[t] = (static_cast<uint32_t>(paddedInput[i + t * 4]) << 24) |
                   (static_cast<uint32_t>(paddedInput[i + t * 4 + 1]) << 16) |
                   (static_cast<uint32_t>(paddedInput[i + t * 4 + 2]) << 8) |
                   (static_cast<uint32_t>(paddedInput[i + t * 4 + 3]));
        }

        for (int t = 16; t < 64; ++t) {
            uint32_t s0 = ROTR(W[t - 15], 7) ^ ROTR(W[t - 15], 18) ^ (W[t - 15] >> 3);
            uint32_t s1 = ROTR(W[t - 2], 17) ^ ROTR(W[t - 2], 19) ^ (W[t - 2] >> 10);
            W[t] = W[t - 16] + s0 + W[t - 7] + s1;
        }

        // Initialize working variables
        uint32_t a = H[0], b = H[1], c = H[2], d = H[3], e = H[4], f = H[5], g = H[6], h = H[7];

        // Main loop
        for (int t = 0; t < 64; ++t) {
            uint32_t S1 = ROTR(e, 6) ^ ROTR(e, 11) ^ ROTR(e, 25);
            uint32_t ch = (e & f) ^ ((~e) & g);
            uint32_t temp1 = h + S1 + ch + K[t] + W[t];
            uint32_t S0 = ROTR(a, 2) ^ ROTR(a, 13) ^ ROTR(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // Update hash values
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    // Final hash value
    for (int i = 0; i < 8; ++i) {
        hash[i] = H[i];
    }
}

int main() {
    std::string input;
    
    std::cout << "Enter a string to hash using SHA-256: ";
    std::getline(std::cin, input);

    uint32_t hash[8];
    sha256(input, hash);

    std::cout << "SHA-256 Hash: ";
    for (int i = 0; i < 8; ++i) {
        std::cout << std::hex << std::setw(8) << std::setfill('0') << hash[i];
    }
    std::cout << std::endl;

    return 0;
}
