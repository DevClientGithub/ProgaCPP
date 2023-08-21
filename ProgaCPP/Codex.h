#pragma once

#include <string>
#include <cstdint>
#include <sstream>
#include <iomanip>

class Codex {
public:
    static std::string sha256(const std::string& input) {
        uint32_t words[64];
        uint32_t hash[8];

        hash[0] = 0x6a09e667;
        hash[1] = 0xbb67ae85;
        hash[2] = 0x3c6ef372;
        hash[3] = 0xa54ff53a;
        hash[4] = 0x510e527f;
        hash[5] = 0x9b05688c;
        hash[6] = 0x1f83d9ab;
        hash[7] = 0x5be0cd19;

        std::string paddedInput = input;
        paddedInput += '\x80';
        while ((paddedInput.size() * 8) % 512 != 448) {
            paddedInput += '\x00';
        }
        uint64_t bitLength = input.size() * 8;
        paddedInput.append(reinterpret_cast<const char*>(&bitLength), sizeof(bitLength));

        for (size_t chunkStart = 0; chunkStart < paddedInput.size(); chunkStart += 64) {
            for (size_t i = 0; i < 16; ++i) {
                words[i] = (paddedInput[chunkStart + i * 4] << 24) |
                    (paddedInput[chunkStart + i * 4 + 1] << 16) |
                    (paddedInput[chunkStart + i * 4 + 2] << 8) |
                    (paddedInput[chunkStart + i * 4 + 3]);
            }
            for (size_t i = 16; i < 64; ++i) {
                words[i] = sigma1(words[i - 2]) + words[i - 7] + sigma0(words[i - 15]) + words[i - 16];
            }

            uint32_t a = hash[0];
            uint32_t b = hash[1];
            uint32_t c = hash[2];
            uint32_t d = hash[3];
            uint32_t e = hash[4];
            uint32_t f = hash[5];
            uint32_t g = hash[6];
            uint32_t h = hash[7];

            for (size_t i = 0; i < 64; ++i) {
                uint32_t temp1 = h + Sigma1(e) + choose(e, f, g) + k[i] + words[i];
                uint32_t temp2 = Sigma0(a) + majority(a, b, c);
                h = g;
                g = f;
                f = e;
                e = d + temp1;
                d = c;
                c = b;
                b = a;
                a = temp1 + temp2;
            }

            hash[0] += a;
            hash[1] += b;
            hash[2] += c;
            hash[3] += d;
            hash[4] += e;
            hash[5] += f;
            hash[6] += g;
            hash[7] += h;
        }

        std::ostringstream resultStream;
        for (size_t i = 0; i < 8; ++i) {
            resultStream << std::hex << std::setfill('0') << std::setw(8) << hash[i];
        }

        return resultStream.str();
    }

private:
    static uint32_t rightRotate(uint32_t value, int count) {
        return (value >> count) | (value << (32 - count));
    }

    static uint32_t choose(uint32_t x, uint32_t y, uint32_t z) {
        return (x & y) ^ (~x & z);
    }

    static uint32_t majority(uint32_t x, uint32_t y, uint32_t z) {
        return (x & y) ^ (x & z) ^ (y & z);
    }

    static uint32_t sigma0(uint32_t x) {
        return rightRotate(x, 7) ^ rightRotate(x, 18) ^ (x >> 3);
    }

    static uint32_t sigma1(uint32_t x) {
        return rightRotate(x, 17) ^ rightRotate(x, 19) ^ (x >> 10);
    }

    static uint32_t Sigma0(uint32_t x) {
        return rightRotate(x, 2) ^ rightRotate(x, 13) ^ rightRotate(x, 22);
    }

    static uint32_t Sigma1(uint32_t x) {
        return rightRotate(x, 6) ^ rightRotate(x, 11) ^ rightRotate(x, 25);
    }

    static const uint32_t k[];
    static const uint32_t h[];
};

const uint32_t Codex::k[64] = {
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

const uint32_t Codex::h[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};
