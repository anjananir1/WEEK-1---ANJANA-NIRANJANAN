#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Created this class to store one stock entry
class StockEntry {
public:
    string date;
    string open;
    string high;
    string low;
    string close;

    StockEntry(string d, string o, string h, string l, string c) {
        date = d;
        open = o;
        high = h;
        low = l;
        close = c;
    }

    void display() {
        cout << "Date: " << date
             << "\tOpen: $" << open
             << "\tHigh: $" << high
             << "\tLow: $" << low
             << "\tClose: $" << close << endl;
    }
};

// I created this Function to extract a field from a CSV line
string extractField(string& line) {
    int pos = line.find(',');               
    string field = line.substr(0, pos);    
    line = line.substr(pos + 1);           
    return field;                          
}

int main() {
    const int SIZE = 10;
    StockEntry* entries[SIZE]; //Array to hold 10 entries
    ifstream file("Download Data - STOCK_US_XNAS_NFLX.csv");
    string line;

    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    getline(file, line); // Skip header

    int index = 0;
    while (getline(file, line) && index < SIZE) {
        string original = line;

        string date = extractField(original);   
        string open = extractField(original);  
        string high = extractField(original);  
        string low = extractField(original);    
        string close = extractField(original);  

        entries[index] = new StockEntry(date, open, high, low, close);
        index++;
    }

    cout << "\nNetflix Stock Data (First 10 Entries):\n" << endl;
    for (int i = 0; i < SIZE; i++) {
        entries[i]->display();
    }

    for (int i = 0; i < SIZE; i++) {
        delete entries[i];
    }

    file.close();
    return 0;
}
