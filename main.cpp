
//Airplane Seating Arrangement

#include <iostream>
#include <vector>

using namespace std;

// Show current seating arrangement
void showSeatingArrangement(const vector<vector<char>>& seating) {
    cout << "\nCurrent Seating Arrangement:\n";
    for (int i = 0; i < seating.size(); ++i) {
        cout << "Row " << (i + 1) << ": ";
        for (char seat : seating[i]) {
            cout << seat << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    int totalRows, seatsInRow;

    // User input for rows and seats
    cout << "Please enter the number of rows in the airplane: ";
    cin >> totalRows;
    cout << "Please enter the number of seats in each row: ";
    cin >> seatsInRow;

    // Initialize seating chart with '0' for available
    vector<vector<char>> seatingChart(totalRows, vector<char>(seatsInRow, '0'));
    vector<pair<int, int>> bookedSeats;  // Track booked seats
    int remainingSeats = totalRows * seatsInRow; // Total available seats
    char continueBooking; // User choice to continue

    showSeatingArrangement(seatingChart); // Display initial chart

    // Booking loop
    while (remainingSeats > 0) {
        int rowNumber, seatNumber;

        cout << "\nEnter the row you wish to book: ";
        cin >> rowNumber;
        cout << "Enter the seat number you wish to book: ";
        cin >> seatNumber;

        // Validate input
        if (rowNumber < 1 || rowNumber > totalRows || seatNumber < 1 || seatNumber > seatsInRow) {
            cout << "Invalid row or seat number. Try again.\n";
            continue;
        }

        // Check if seat is booked (using 1-based index)
        if (seatingChart[rowNumber - 1][seatNumber - 1] == 'X') {
            cout << "Sorry, that seat is already booked. Choose another.\n";
            continue;
        }

        // Mark seat as booked
        seatingChart[rowNumber - 1][seatNumber - 1] = 'X';
        bookedSeats.push_back({rowNumber, seatNumber}); // Store booked seat (1-indexed)
        remainingSeats--; // Decrease available seats

        showSeatingArrangement(seatingChart); // Show updated chart

        // Ask to continue booking
        cout << "Would you like to book another seat? (y/n): ";
        cin >> continueBooking;
        if (continueBooking != 'y' && continueBooking != 'Y') break;
    }

    // Final output
    cout << "\nFinal Seating Arrangement:";
    showSeatingArrangement(seatingChart); // Show final chart
    cout << "\nRemaining available seats: " << remainingSeats << endl;
    cout << "Booked seats in order:\n";
    for (const auto& seat : bookedSeats) {
        cout << "Row " << seat.first << ", Seat " << seat.second << endl;
    }

    return 0;
}


