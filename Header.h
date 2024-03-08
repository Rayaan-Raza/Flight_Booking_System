#pragma once
#include<iostream>
using namespace std;

class Passenger 
{
private:
    string name;
    int phoneNumber; 

    static int count;

public:
    // Constructors
    Passenger() { count++; }

    Passenger(const string& name, int phoneNumber)
        : name(name), phoneNumber(phoneNumber)
    {
        count++;
    }

    // Getters
    string getName() const { return name; }
    int getPhoneNumber() const { return phoneNumber; }

    // Setters
    void setName(const string& name) { this->name = name; }
    void setPhoneNumber(int phoneNumber) { this->phoneNumber = phoneNumber; }

    // Display passenger information
    void displayInfo() const {
        cout << "Passenger Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }

    // Static member function to check if a name matches in the passenger array
    static bool nameMatches(const string& searchName, const Passenger* passengers, int numPassengers) {
        for (int i = 0; i < numPassengers; ++i) {
            if (passengers[i].getName() == searchName) {
                return true; // Name found
            }
        }
        return false; // Name not found
    }

    // Static member function to get the count of registered passengers
    static int getCount() { return count; }
};

// Define and initialize the static count member variable
int Passenger::count = 0;

class Flight 
{
private:
    int flightNumber;
    bool selectedFlight;
    string airline;
    string destination;

public:
    // Constructor
    Flight(int flightNumber = 0, const string& airline = "", const string& destination = "", bool selectedFlight = false)
        : flightNumber(flightNumber), airline(airline), destination(destination), selectedFlight(selectedFlight) {}


    // Getters
    int getFlightNumber() const { return flightNumber; }
    string getAirline() const { return airline; }
    string getDestination() const { return destination; }
    bool isSelected() const { return selectedFlight; }

    // Setter
    void setSelected(bool selected) { selectedFlight = selected; }
};

// Function to generate random flight details
Flight generateRandomFlight() 
{
    int flightNumber = rand() % 900 + 100; // Generate random flight number (between 100 and 999)

    string airlines[] = { "PIA", "SereneAir", "AirBlue", "Shaheen Air", "Emirates" };
    string airline = airlines[rand() % 5]; // Generate random airline name

    string destinations[] = { "Karachi", "Lahore", "Islamabad", "Quetta", "Peshawar", "Multan", "Faisalabad" };
    string destination = destinations[rand() % 7]; // Generate random destination city in Pakistan

    return Flight(flightNumber, airline, destination);
}

class Pax 
{
private:
    Passenger passinfo;
    char seatL;
    int seatNumber;
    Flight flightInfo;

public:
    // Constructor
    Pax(const Passenger& passinfo, char seatL, int seatNumber, const Flight& flightInfo)
        : passinfo(passinfo), seatL(seatL), seatNumber(seatNumber), flightInfo(flightInfo) {}

    // Getters
    Passenger getPassinfo() const { return passinfo; }
    char getSeatL() const { return seatL; }

    int getSeatNumber() const { return seatNumber; }
    Flight getFlightInfo() const { return flightInfo; }

    // Setters
    void setPassinfo(const Passenger& passinfo) { this->passinfo = passinfo; }
    void setSeatL(int seatL) { this->seatL = seatL; }

    void setSeatNumber(int seatNumber) { this->seatNumber = seatNumber; }
    void setFlightInfo(const Flight& flightInfo) { this->flightInfo = flightInfo; }

    // Display passenger information
    void displayInfo() const {
        cout << "Passenger Name: " << passinfo.getName() << endl;
        cout << "Phone Number: " << passinfo.getPhoneNumber() << endl;
        cout << "Seat INformation: " << seatL <<" "<< seatNumber << endl;
        cout << "Flight Information:" << endl;
        cout << endl;
        cout << "Flight Number: " << flightInfo.getFlightNumber() << " | Airline: " << flightInfo.getAirline() << " | Destination: " << flightInfo.getDestination() << endl;
    }
};

void generateSeats(int seats[6][3]) 
{
    srand(time(0)); // Seed the random number generator with current time

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            seats[i][j] = rand() % 2; // Generate random 0 or 1
        }
    }
}

void layout(int seats[6][3]) {
    cout << "Seat Layout:" << endl;
    cout << "\tA B C" << endl;
    for (int i = 0; i < 6; ++i) {
        cout << i + 1 << "\t";
        for (int j = 0; j < 3; ++j) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}


