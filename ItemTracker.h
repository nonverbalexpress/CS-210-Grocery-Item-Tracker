#pragma once
#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <map>
#include <algorithm>
#include <cctype>

// Converts a string to lowercase to standardize it for comparison.
// This helps in managing case insensitivity across the application.
inline std::string toLowerCase(const std::string& str) {
    std::string lowerCaseStr = str;
    std::transform(lowerCaseStr.begin(), lowerCaseStr.end(), lowerCaseStr.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return lowerCaseStr;
}

class ItemTracker {
private:
    std::map<std::string, int> itemFrequencies; // Map to store item names and their corresponding frequencies.
    std::string inputFileName;                  // File name for input data.
    std::string outputFileName;                 // File name for output data.

public:
    // Constructor: Initializes file names for input and output.
    ItemTracker(const std::string& input, const std::string& output);

    // Loads items from the file, normalizing them to ensure case insensitivity.
    void loadItemsFromFile();

    // Prints all items and their frequencies to the standard output.
    void printItemFrequencies() const;

    // Finds and displays the frequency of a specific item, handling both singular and plural forms.
    void findItemFrequency(const std::string& item) const;

    // Generates a histogram of the items' frequencies.
    void printHistogram() const;

    // Saves the frequencies of items to an output file.
    void saveItemsToFile() const;
};

#endif // ITEM_TRACKER_H
