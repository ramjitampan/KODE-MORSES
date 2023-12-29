#include <iostream>
#include <map>
#include <sstream>
#include <cctype>

// Struktur data untuk pasangan karakter dan kode Morse
struct MorseData {
    char character;
    std::string morseCode;
};

// Array untuk kode Morse
const MorseData morseCodes[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}, {' ', "/"} // spasi digunakan sebagai pemisah antar kata
};

// Map untuk menyimpan pasangan karakter dan kode Morse
std::map<char, std::string> morseMap;

// Inisialisasi map dengan pasangan karakter dan kode Morse
void initializeMap() {
    for (const auto& data : morseCodes) {
        morseMap[data.character] = data.morseCode;
    }
}

// Fungsi untuk menerjemahkan teks ke kode Morse
std::string textToMorse(const std::string& text) {
    std::stringstream morse;
    for (char ch : text) {
        ch = std::toupper(ch);
        if (morseMap.find(ch) != morseMap.end()) {
            morse << morseMap[ch] << " ";
        }
    }
    return morse.str();
}

// Fungsi untuk menerjemahkan kode Morse ke teks
std::string morseToText(const std::string& morse) {
    std::stringstream text;
    std::istringstream stream(morse);
    std::string code;
    while (stream >> code) {
        for (const auto& pair : morseMap) {
            if (pair.second == code) {
                text << pair.first;
                break;
            }
        }
    }
    return text.str();
}

int main() {
    initializeMap();

    std::string text;
    std::cout << "Masukkan teks untuk diterjemahkan ke kode Morse: ";
    std::getline(std::cin, text);

    std::string morse = textToMorse(text);
    std::cout << "Teks dalam kode Morse: " << morse << std::endl;

    std::string originalText = morseToText(morse);
    std::cout << "Kode Morse dalam teks asli: " << originalText << std::endl;

    return 0;
}
