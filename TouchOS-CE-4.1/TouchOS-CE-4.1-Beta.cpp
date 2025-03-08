#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <time.h>
#include <stdio.h>

int backgroundColor = BLUE;

void setColors() {
    textcolor(WHITE);
    textbackground(backgroundColor);
}

void resetColor() {
    textcolor(WHITE);
    textbackground(backgroundColor);
}

void displayMenu() {
    clrscr();
    setColors();
    cout << "===| TouchOS CE 4.1 Beta |===\n";
    cout << "1 - Calculator\n";
    cout << "2 - Clock\n";
    cout << "3 - Text\n";
    cout << "4 - Getting Started\n";
    cout << "5 - Settings\n";
    cout << "6 - About\n";
    cout << "7 - Exit\n";
    cout << "Enter an option: ";
    resetColor();
}

void displayClock() {
    clrscr();
    time_t now = time(0);
    tm* ltm = localtime(&now);

    cout << "Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\n";
    cout << "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "\n";
    getch();
}

void displayTextMenu() {
    clrscr();
    setColors();
    cout << "***| Text |***\n";
    cout << "1 - Open Document\n";
    cout << "2 - Edit Document\n";
    cout << "3 - Back to Home\n";
    cout << "Enter an option: ";
    resetColor();
}

void openDocument() {
    clrscr();
    ifstream inputFile("TEXT.TXT");

    if (inputFile) {
        cout << "Opening document...\n";
        char data[100];
        while (inputFile.getline(data, 100)) {
            cout << "Document contents: " << data << "\n";
        }
        inputFile.close();
    } else {
        cout << "ERROR 3\n";
    }

    getch();
}

void editDocument() {
    clrscr();
    ofstream outputFile("TEXT.TXT", ios::app);

    if (outputFile) {
        char userData[100];
        cin.ignore();
        cout << "Enter document contents: ";
        cin.getline(userData, 100);
        outputFile << userData << "\n";
        cout << "Saved to document\n";
        outputFile.close();
    } else {
        cout << "ERROR 4\n";
    }

    getch();
}

void displayGettingStarted() {
    clrscr();
    cout << "***| Getting Started |***\n";
    cout << "Welcome to TouchOS CE 4.1\n";
    cout << "- New features: About and Settings\n";
    cout << "To start, go to Home\n";
    cout << "Select appss with the numbers\n";
    cout << "For more info, visit\n";
    cout << "https://www.touchos.macbines.com/touchos\n";
    cout << "TouchOS CE 4.1 Beta Build\n";
    getch();
}

void displaySettings() {
    clrscr();
    cout << "***| Settings |***\n";
    cout << "1 - Change Background Color\n";
    cout << "2 - Back to Home\n";
    cout << "Enter an option: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "Choose a color (1 - BLUE, 2 - GREEN, 3 - RED): ";
        cin >> choice;
        switch (choice) {
            case 1: backgroundColor = BLUE; break;
            case 2: backgroundColor = GREEN; break;
            case 3: backgroundColor = RED; break;
            default: cout << "ERROR 2\n";
        }
    }
    getch();
}

void displayAbout() {
    clrscr();
    cout << "***| About |***\n";
    cout << "TouchOS CE 4.1 Beta\n";
    cout << "Build: 4.1.2503.04\n";
    cout << "(C) 1997-2025 NeTT Systems\n";
    getch();
}

void displayCalculatorMenu() {
    clrscr();
    setColors();
    cout << "***| Calculator |***\n";
    cout << "1 - Add\n";
    cout << "2 - Subtract\n";
    cout << "3 - Multiply\n";
    cout << "4 - Back to Home\n";
    cout << "Enter an option: ";
    resetColor();
}

void performAddition() {
    clrscr();
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Result: " << num1 + num2 << "\n";
    getch();
}

void performSubtraction() {
    clrscr();
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Result: " << num1 - num2 << "\n";
    getch();
}

void performMultiplication() {
    clrscr();
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Result: " << num1 * num2 << "\n";
    getch();
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: displayCalculatorMenu(); break;
            case 2: displayClock(); break;
            case 3: displayTextMenu(); break;
            case 4: displayGettingStarted(); break;
            case 5: displaySettings(); break;
            case 6: displayAbout(); break;
            case 7: cout << "Exiting TouchOS 4.1...\n"; break;
            default: cout << "ERROR 1\n";
        }
    } while (choice != 7);
    return 0;
}