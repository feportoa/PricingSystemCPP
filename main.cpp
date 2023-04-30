#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

const int chargePerRoom {30};
const float salesTax {1.06}; // 6% fee (6 /100 = 0.06 + 100% = 1.06)

float Rooms(unsigned int rooms);
std::string toUpperCase(std::string str);

int main()
{
    int userChosenOption {1};

    system("clear");
    std::cout << "Welcome to FRANK'S CARPET CLEANING SERVICE!\n\tWhat do you need for today?" << std::endl;

    std::cout << "Type 1 for a request or 2 for Costumer Support: " << std::flush;
    std::cin >> userChosenOption;

    system("clear");
    // Process the option chosen by the user
    if(userChosenOption == 1){ // Problems handling float/double injection
        unsigned int clientNumberOfRooms {0}; 
        float serviceTotalValue {0.0F};
        std::string userPaymentConfirmation {"Y"};

        std::cout << "Type the number of rooms you need a Ultra Carpet Clean: ";

        // Checks if clientNumberOfRooms is an int and then proceeds
        if(std::cin >> clientNumberOfRooms){ // Problems handling float/double injection
            serviceTotalValue = Rooms(clientNumberOfRooms);
            std::cout << "Cost: $" << clientNumberOfRooms * chargePerRoom << "\n";
            std::cout << "Sales tax: $" << (clientNumberOfRooms * chargePerRoom) * 0.06 << "\n";
            std::cout << "The total value is: " << serviceTotalValue << ". Would you like to confirm?\n";
            std::cout << "Yes[Y] or No[N]" << std::endl;
            
            // Checks if user payment confirmation is Y or YES to proceed to payment session
            if(std::cin >> userPaymentConfirmation){
                if(toUpperCase(userPaymentConfirmation) == "Y" || toUpperCase(userPaymentConfirmation) == "YES"){
                    std::cout << "Redirecting user..." << std::endl;
                    system("xdg-open https://github.com/feportoa/PricingSystemCPP");
                } else if(toUpperCase(userPaymentConfirmation) == "N" || toUpperCase(userPaymentConfirmation) == "NO") {
                    // Ends the program in case of N or NO
                    std::cout << "Closing process" << std::endl;
                    return 0;
                    
                } else {
                    // Return an error and closes the program if option is invalid
                    std::cout << "[ERROR] Invalid Option. Closing Application" << std::endl;
                    return 1;
                }

            } else {
                // Returns an error if the user does not use a string or char
                std::cout << "[ERROR] Invalid Input!\nClosing Application" << std::endl;
                return 1;
            }

        } else {
            // Returns an error if the user does not use an int
            std::cout << "[ERROR] Invalid Input!\nClosing Application." << std::endl;
            return 1;
        }
        
    } else if(userChosenOption == 2){
        std::cout << "Well, we don't really have a costumer support, so we'll just end the chat :)\nHave a great day!" << std::endl;
    } else { // if user chooses an unexisting option, or use anything but an int, ends the program with an error
        std::cout << "Invalid input, try again another time." << std::endl;
        return 1;
    }

    return 0;
}

// Calculate the total value of the service for an specific number of rooms
float Rooms(unsigned int rooms)
{
    float value {0};

    // Multiplies the number of rooms with charge per room them applies a fee of 6%
    value = (rooms * chargePerRoom) * salesTax;
    return value;
}

// Sets strings to upper case (as said in the name)
std::string toUpperCase(std::string str)
{
    for(char& c : str){
        c = std::toupper(c);
    }
    return str;
}

