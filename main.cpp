/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                             *
 *   Name: Reinier Garcia Ramos                                                                *
 *                                                                                             *
 *   Program Title: File Analyzer                                                              *
 *                                                                                             *
 *   Purpose:                                                                                  *
 *   Scans an existing file named words.txt, and then groups and counts the words on it.       *
 *                                                                                             *
 *   More Details:                                                                             *
 *   https://github.com/reymillenium/20240714_1407_chapter11_auto_graded_programming_project   *
 *                                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <filesystem>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;
using std::to_string;
using std::stringstream;
using std::vector;
using std::find;
using std::count_if;
using std::filesystem::exists;
using std::ifstream;


// STRUCTS DEFINITIONS


struct Word {
    string value;
    int frequency;
};


// UTILITY FUNCTIONS PROTOTYPES


// Detects if a given filename exist or not on the root of the executable file
bool fileExist(const string &);

// Gets all the non-empty lines of text inside a given file name
vector<string> getLinesFromFile(const string &);

// Converts a string to lowercase and returns it
string getLowerCase(string input);


// CUSTOM MADE FUNCTIONS PROTOTYPES


// Counts & properly groups the words on the scanned lines from the file
void countWords(vector<Word> &, const vector<string> &);

// Displays the results
void displayResults(const vector<Word> &words);


// Main Function
int main() {
    if (const string FILE_NAME = "words.txt"; fileExist(FILE_NAME)) {
        // We get all the non-empty lines of text from the file
        const vector<string> textLinesFromFile = getLinesFromFile(FILE_NAME);
        vector<Word> words;

        // Counts & properly groups the words on the scanned lines from the file
        countWords(words, textLinesFromFile);

        // Displays the analyzed words and its frequencies
        displayResults(words);
    }

    return 0;
}


// UTILITY FUNCTIONS DEFINITIONS


// Detects if a given filename exist or not on the root of the executable file
bool fileExist(const string &fileName) {
    bool theFileExist = false; // If the file with text was already saved in the root of the executable

    if (exists(fileName))
        theFileExist = true;

    return theFileExist;
}

// Gets all the non-empty lines of text inside a given file name
vector<string> getLinesFromFile(const string &fileName) {
    ifstream inputFile(fileName);
    vector<string> lines;

    if (inputFile.is_open()) {
        string line; // one single line at the time, to be read from the file

        while (getline(inputFile, line)) {
            if (!line.empty()) // If the line is empty then it's not interesting for us
                lines.push_back(line);
        }
    } else {
        cerr << "Error opening file\n";
    }

    // Closing the input file
    inputFile.close();

    return lines;
}

// Converts a string to lowercase and returns it
string getLowerCase(string input) {
    string destinationString = input;
    std::transform(input.begin(), input.end(), destinationString.begin(),
                   [](const unsigned char c) { return tolower(c); });
    return destinationString;
}


// CUSTOM MADE FUNCTIONS DEFINITIONS


// Counts & properly groups the words on the scanned lines from the file
void countWords(vector<Word> &words, const vector<string> &textLinesFromFile) {
    for (string textLine: textLinesFromFile) {
        // If the string is already inside the words vector
        bool wordExist = count_if(words.begin(), words.end(),
                                  [&](const Word &word) { return word.value == getLowerCase(textLine); }) > 0;
        if (wordExist) {
            for (Word &word: words) {
                if (word.value == getLowerCase(textLine)) {
                    word.frequency++;
                    break;
                }
            }
        } else {
            words.push_back(Word {.value = getLowerCase(textLine), .frequency = 1});
        }
    }
}

// Displays the results
void displayResults(const vector<Word> &words) {
    for (const auto &[value, frequency]: words) {
        cout << value << " " << frequency << endl;
    }
}
