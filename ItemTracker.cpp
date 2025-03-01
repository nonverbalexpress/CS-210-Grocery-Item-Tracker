#include "ItemTracker.h"
#include <fstream>
#include <iostream>

// Constructor: Initializes file names for input and output
ItemTracker::ItemTracker(const std::string& input, const std::string& output)
    : inputFileName(input), outputFileName(output) {}

// Loads items from the file, normalizing to a consistent singular form
void ItemTracker::loadItemsFromFile() {
    std::ifstream file(inputFileName);
    if (!file) {
        std::cerr << "Error opening input file: " << inputFileName << std::endl;
        return;
    }
    std::string item;
    while (file >> item) {
        std::string normalizedItem = toLowerCase(item);
        // Normalize common plural forms to singular
        if (normalizedItem == "yams") normalizedItem = "yam";
        else if (normalizedItem == "apples") normalizedItem = "apple";
        // Add more conversions as necessary
        itemFrequencies[normalizedItem]++;
    }
    file.close();
}

// Displays all items and their frequencies
void ItemTracker::printItemFrequencies() const {
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

// Finds and displays the frequency of a specific item, checking both singular and plural forms
void ItemTracker::findItemFrequency(const std::string& item) const {
    std::string normalizedItem = toLowerCase(item);
    // Check both the singular and potential plural form
    std::string singular = (normalizedItem.back() == 's') ? normalizedItem.substr(0, normalizedItem.size() - 1) : normalizedItem;
    std::string plural = (normalizedItem.back() == 's') ? normalizedItem : normalizedItem + "s";

    auto singularIt = itemFrequencies.find(singular);
    auto pluralIt = itemFrequencies.find(plural);

    if (singularIt != itemFrequencies.end() || pluralIt != itemFrequencies.end()) {
        int total = (singularIt != itemFrequencies.end() ? singularIt->second : 0)
            + (pluralIt != itemFrequencies.end() ? pluralIt->second : 0);
        std::cout << item << " appears " << total << " times." << std::endl;
    }
    else {
        std::cout << item << " not found." << std::endl;
    }
}

// Displays a histogram of the items' frequencies
void ItemTracker::printHistogram() const {
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

// Saves the frequencies of items to an output file
void ItemTracker::saveItemsToFile() const {
    std::ofstream outFile(outputFileName);
    if (!outFile) {
        std::cerr << "Error opening output file: " << outputFileName << std::endl;
        return;
    }
    for (const auto& pair : itemFrequencies) {
        outFile << pair.first << ": " << pair.second << std::endl;
    }
    outFile.close();
}