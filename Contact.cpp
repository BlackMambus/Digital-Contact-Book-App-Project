#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

vector<Contact> contactBook;

void addContact() {
    Contact c;
    cout << "Enter name: ";
    getline(cin, c.name);
    cout << "Enter phone: ";
    getline(cin, c.phone);
    cout << "Enter email: ";
    getline(cin, c.email);
    contactBook.push_back(c);
    cout << "Contact added!\n";
}

void displayContacts() {
    if (contactBook.empty()) {
        cout << "No contacts to display.\n";
        return;
    }
    for (const auto& c : contactBook) {
        cout << "Name: " << c.name << ", Phone: " << c.phone << ", Email: " << c.email << "\n";
    }
}

void searchContact() {
    string query;
    cout << "Enter name to search: ";
    getline(cin, query);
    bool found = false;
    for (const auto& c : contactBook) {
        if (c.name == query) {
            cout << "Found! Phone: " << c.phone << ", Email: " << c.email << "\n";
            found = true;
        }
    }
    if (!found) cout << "Contact not found.\n";
}

void deleteContact() {
    string query;
    cout << "Enter name to delete: ";
    getline(cin, query);
    auto it = remove_if(contactBook.begin(), contactBook.end(),
                        [&query](Contact& c) { return c.name == query; });
    if (it != contactBook.end()) {
        contactBook.erase(it, contactBook.end());
        cout << "Contact deleted.\n";
    } else {
        cout << "Contact not found.\n";
    }
}

int main() {
    int choice;
    string dummy; // to capture newline after integer input

    while (true) {
        cout << "\n1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Delete Contact\n5. Exit\nChoose an option: ";
        cin >> choice;
        getline(cin, dummy); // to clear input buffer

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}

