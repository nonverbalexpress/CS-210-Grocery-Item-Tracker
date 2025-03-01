#include "ItemTracker.h"
#include <iostream>
#include <limits>

int main() {
    // Initialize the item tracker with the specific input and output file names
    ItemTracker tracker("CS210_Project_Three_Input_File.txt", "output.txt");

    // Load items from the file
    tracker.loadItemsFromFile();

    int choice;
    do {
        std::cout << "\n1. Print all items\n";
        std::cout << "2. Find an item\n";
        std::cout << "3. Print histogram\n";
        std::cout << "4. Save and Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        // Handle input errors
        if (std::cin.fail()) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
            std::cout << "Invalid input, please enter a number.\n";
            continue;
        }

        // Process the user's menu choice
        switch (choice) {
        case 1:
            tracker.printItemFrequencies();
            break;
        case 2: {
            std::cout << "Enter item name: ";
            std::string item;
            std::cin >> item;
            tracker.findItemFrequency(item);
            break;
        }
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            tracker.saveItemsToFile();
            std::cout << "Data saved and exiting the program." << std::endl;
            return 0; // Clean exit
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
