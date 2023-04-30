#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

const float chargePerSmallRoom {25.0F};
const float chargePerLargeRoom {35.0F};
const float salesTax {0.06F};
const int estimateValidity {30};

float Total(unsigned int smallRooms, unsigned int largeRooms);
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
        unsigned int clientNumberOfSmallRooms {0}; 
        unsigned int clientNumberOfLargeRooms {0};
        float cost {0.0F};
        std::string userPaymentConfirmation {"Y"};

        std::cout << "Type the number of small rooms you need an Ultra Carpet Clean: ";

        // Checks if clientNumberOfSmallRooms is an int and then proceeds
        if(std::cin >> clientNumberOfSmallRooms){ // Problems handling float/double injection
            std::cout << "Type the number of large rooms you need an Ultra Carpet Clean: ";
            if(std::cin >> clientNumberOfLargeRooms){
                cost = (chargePerSmallRoom * clientNumberOfSmallRooms) + (chargePerLargeRoom * clientNumberOfLargeRooms);
                std::cout << "Price per small room: $" << chargePerSmallRoom << "\nPrice per large room: $" << chargePerLargeRoom << std::endl;
                std::cout << "Cost: $" << cost << "\nSales Tax: $" << salesTax * cost << std::endl;
                std::cout << "=========================================" << std::endl;
                std::cout << "Total estimate: $" << Total(clientNumberOfSmallRooms, clientNumberOfLargeRooms) << "\nThis estimate is valid for " << estimateValidity << " days." << std::endl;
            } else {
                std::cout << "[ERROR] Invalid input! Closing application..." << std::endl;
                return 1;
            }

            std::cout << "Would you like to confirm your purchase?\n Yes[Y] or No[N]" << std::endl;

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
float Total(unsigned int smallRooms, unsigned int largeRooms)
{
    float value {0.0F};

    // Multiplies the number of rooms with charge per room them applies a fee of 6%
    value = ((smallRooms * chargePerSmallRoom) + (largeRooms * chargePerLargeRoom)) * (1 + salesTax);
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

