#include<iostream>
#include "Header.h"
#include <string>
#include <cstdlib> 
#include <ctime> 

using namespace std;

int main() 
{
    char seatLetter;
    int seatNumber;
    Passenger newPassenger;
    cout << "Welcome to the Flight Reservation System!" << endl;
    cout << "Are you a new passenger or have you already booked a flight?" << endl;
    cout << "1. New Passenger" << endl;
    cout << "2. Existing Passenger" << endl;

    int choice;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) 
    {
        // New passenger logic
        cout << "You have chosen to register as a new passenger." << endl;

        // Prompt the user for name and phone number
        string name;
        int phoneNumber;
        cout << "Enter your name: ";
        cin >> name;
        
        cout << "Enter your phone number: ";
        cin >> phoneNumber;

        // Create a Passenger object and store the information
        newPassenger = Passenger(name, phoneNumber);

        // Display registration success message
        cout << "Registration successful!" << endl;
    }
   // else if (choice == 2) {
        // Existing passenger logic
     //   cout << "You have chosen to continue as an existing passenger." << endl;

        // Prompt the user for their name
       // string name;
        //cout << "Enter your name: ";
        //cin >> name;

        // Check if the passenger exists
        //if (Passenger::nameMatches(name, passengers, numPassengers) {
            // Passenger exists
          //  cout << "Welcome back, " << name << "!" << endl;
            // Implement login process
        //}
        //else {
            // Passenger does not exist
          //  cout << "Sorry, no matching record found for " << name << "." << endl;
            // Optionally provide an option to register as a new passenger
        //}
    //}
    else {
        cout << "Invalid choice. Please enter 1 or 2." << endl;
    }

    

    // Clear the screen
#ifdef _WIN32
    system("cls"); 
#else
    system("clear"); 
#endif

    // Display the flight details screen
    cout << "Flight Details Screen:" << endl;

    const int numFlights = 5;
    Flight flights[numFlights] = {
        generateRandomFlight(),
        generateRandomFlight(),
        generateRandomFlight(),
        generateRandomFlight(),
        generateRandomFlight()
    };

    // Generate random flight details
    for (int i = 0; i < numFlights; ++i) 
    {
        flights[i] = generateRandomFlight();
    }

    // Display random flight details
    for (int i = 0; i < numFlights; ++i) 
    {
        cout << "Flight Number: " << flights[i].getFlightNumber() << " | Airline: " << flights[i].getAirline() << " | Destination: " << flights[i].getDestination() << endl;
    }


    // Prompt the user to select a flight via its flight number
    cout << "Select a flight via its flight number:" << endl;
    cout << "Enter the flight number: ";
    int flightNumber;
    cin >> flightNumber;

    // Find the selected flight from the flights array
    Flight selectedFlight;
    bool found = false;
    for (int i = 0; i < numFlights; ++i) 
    {
        if (flights[i].getFlightNumber() == flightNumber) 
        {
            selectedFlight = flights[i];
            selectedFlight.setSelected(true); // Mark the flight as selected
            found = true;

            break;
        }
    }

    if (!found) 
    {
        cout << "Flight not found. Please enter a valid flight number." << endl;
        return 1; // Exit program
    }


    while (true) 
    {
        cout << "Seats with 0 are available" << endl;
        cout << endl;
        int seats[6][3];
        generateSeats(seats);
        layout(seats);

        // Prompt the user to select a seat

        cout << endl;
        cout << "Enter your desired seat letter (A, B, C): ";
        cin >> seatLetter;
        cout << "Enter your desired seat number (1-6): ";
        cin >> seatNumber;

        // Convert seat letter to column index
        int seatIndex;
        if (seatLetter == 'A')
            seatIndex = 0;
        else if (seatLetter == 'B')
            seatIndex = 1;
        else if (seatLetter == 'C')
            seatIndex = 2;
        else 
        {
            cout << "Invalid seat letter. Please enter A, B, or C." << endl;
#ifdef _WIN32
            system("cls"); // For Windows
#else
            system("clear"); 
#endif
            continue; // Restart the loop to select a seat again
        }

        // Check if the seat is available
        if (seats[seatNumber - 1][seatIndex] == 1) 
        {
            cout << "Seat already occupied. Please choose another seat." << endl;

#ifdef _WIN32
            system("cls"); // For Windows
#else
            system("clear"); 
#endif
            continue; // Restart the loop to select a seat again
        }


        break; // Exit the loop
    }
  


    // Clear the screen
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix/Linux
#endif

    //display information
    Pax newPax(newPassenger, seatLetter,seatNumber, selectedFlight);
    cout << "Registration successful!" << endl;
    cout << "Your ticket info:" << endl;
    newPax.displayInfo(); // Display Pax information

    cout << endl;

    cout << "Happy Landings !!!" << endl;

    return 0;
}

