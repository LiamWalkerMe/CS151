/* project2.cpp - Inventory File Manager
    Name: Liam Walker
    Module: 9
    Project: 2
    Problem Statement:
    Create a menu-driven program that stores inventory records in a
    binary file. The user can add new items, view the available
    inventory, and choose a specific item number to display on the
    console.

    Algorithm / Plan:
    1. Include the headers needed for file input/output, formatting,
       character handling, strings, and vectors.
    2. Define an inventory structure to store the item description,
       quantity, wholesale price, and sale price.
    3. Write a helper function that normalizes item descriptions so
       duplicate names can be compared consistently.
    4. Start a loop that repeatedly shows the main menu until the user
       chooses to exit.
    5. If the user selects add, open the binary file in append mode and
       collect one inventory record from the user.
    6. Validate that quantity, wholesale price, and sale price are not
       negative before saving the record.
    7. If the user selects display, read every record from the binary
       file into a vector.
    8. Skip unavailable items and merge duplicate item names so only
       the latest available version of each item is shown.
    9. Display the available inventory as a numbered list and ask the
       user which item they want to view.
    10. Show the selected item's details in a clean formatted block or
        exit when the user chooses the quit option.

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

string normalizeDescription(const char description[]) {
    string normalized = description;

    // Convert the description to lowercase so matching ignores case.
    for (char& ch : normalized) {
        ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
    }

    return normalized;
}

int main() {
    // This struct matches the binary layout stored in inventory.txt.
    struct inventory
    {
        char item_description[100];
        int quantity;
        double wholesale_price;
        double sale_price;


    };

    // Main menu loop
    while (true) {
        cout << "\nInventory Menu\n";
        cout << "--------------\n";
        cout << "1. Add Item into File\n";
        cout << "2. Display Inventory from File\n";
        cout << "3. Exit\n";
        cout << "\nPlease select an option: ";

        // Validate menu input
        int option;
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid menu input. Please enter 1, 2, or 3.\n";
            continue;
        }

        if (option == 1) {
            // Open the file in append mode so new items are added to the end.
            ofstream outputFile("inventory.txt", ios::binary | ios::app);
            if (!outputFile.is_open()) {
                cerr << "Error opening file." << endl;
                return 1;
            }

            inventory item;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nEnter item description: ";
            cin.getline(item.item_description, sizeof(item.item_description));

            // Keep asking until a non-negative quantity is entered.
            cout << "Enter quantity: ";
            cin >> item.quantity;
            while (item.quantity < 0) {
                cout << "Quantity cannot be negative. Please enter again: ";
                cin >> item.quantity;
            }
            
            // Keep asking until a non-negative wholesale price is entered.
            cout << "Enter wholesale price: ";
            cin >> item.wholesale_price;
            while (item.wholesale_price < 0) {
                cout << "Wholesale price cannot be negative. Please enter again: ";
                cin >> item.wholesale_price;
            }
            
            // Keep asking until a non-negative sale price is entered.
            cout << "Enter sale price: ";
            cin >> item.sale_price;
            while (item.sale_price < 0) {
                cout << "Sale price cannot be negative. Please enter again: ";
                cin >> item.sale_price;
            }

            // Write one complete inventory record to the binary file.
            outputFile.write(reinterpret_cast<const char*>(&item), sizeof(item));
            outputFile.close();

            cout << "\nItem saved successfully.\n";
        } else if (option == 2) {
            ifstream inputFile("inventory.txt", ios::binary);
            if (!inputFile.is_open()) {
                cerr << "Error opening file." << endl;
                return 1;
            }

            inventory item;
            vector<inventory> items;

            // Read each saved record and keep only available inventory items.
            while (inputFile.read(reinterpret_cast<char*>(&item), sizeof(item))) {
                if (item.quantity <= 0) {
                    continue;
                }

                bool foundMatch = false;
                string currentDescription = normalizeDescription(item.item_description);

                // Replace duplicates with the latest version of the same item name.
                for (inventory& existingItem : items) {
                    if (normalizeDescription(existingItem.item_description) == currentDescription) {
                        existingItem = item;
                        foundMatch = true;
                        break;
                    }
                }

                if (!foundMatch) {
                    items.push_back(item);
                }
            }
            inputFile.close();

            if (items.empty()) {
                cout << "\nNo available inventory records found.\n";
                continue;
            }

            // Show the user a numbered list so they can choose one item.
            cout << "\nAvailable Inventory Items\n";
            cout << "-------------------------\n";
            for (size_t i = 0; i < items.size(); ++i) {
                cout << i + 1 << ". " << items[i].item_description
                     << " (Qty: " << items[i].quantity << ")\n";
            }

            int itemNumber;
            cout << "\nEnter the item number to display: ";
            // Validate that the selection is a real item number.
            while (!(cin >> itemNumber) || itemNumber < 1 || itemNumber > static_cast<int>(items.size())) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number between 1 and " << items.size() << ": ";
            }

            const inventory& selectedItem = items[itemNumber - 1];

            // Print the selected inventory record in a clean detail view.
            cout << "\nSelected Item\n";
            cout << "-------------\n";
            cout << left << setw(18) << "Description:" << selectedItem.item_description << '\n';
            cout << left << setw(18) << "Quantity:" << selectedItem.quantity << '\n';
            cout << left << setw(18) << "Wholesale Price:" << fixed << setprecision(2)
                 << selectedItem.wholesale_price << '\n';
            cout << left << setw(18) << "Sale Price:" << fixed << setprecision(2)
                 << selectedItem.sale_price << '\n';
        } else if (option == 3) {
            cout << "\nGoodbye.\n";
            break;
        } else {
            cout << "\nInvalid option. Please try again.\n";
        }
    }

    return 0;
}
