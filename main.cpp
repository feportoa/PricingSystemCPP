#include <iostream>
#include <string>
#include <cstdlib>

const int chargePerRoom {30};
const float salesTax {1.06};

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
    if(userChosenOption == 1){
        unsigned int clientNumberOfRooms {0}; 
        float serviceValue {0.0F};
        std::string userPaymentConfirmation {"Y"};

        std::cout << "Type the number of rooms you need a Ultra Carpet Clean: ";
        if(std::cin >> clientNumberOfRooms){
            serviceValue = Rooms(clientNumberOfRooms);
            std::cout << "The total value is: " << serviceValue << ". Would you like to confirm?" << std::endl;
            std::cout << "Yes[Y] or No[N]" << std::endl;
            
            if(std::cin >> userPaymentConfirmation){
                if(toUpperCase(userPaymentConfirmation) == "Y" || toUpperCase(userPaymentConfirmation) == "YES"){
                    std::cout << "Redirecting user..." << std::endl;
                    system("xdg-open https://github.com/feportoa");
                } else if(toUpperCase(userPaymentConfirmation) == "N" || toUpperCase(userPaymentConfirmation) == "NO") {
                    std::cout << "Closing process" << std::endl;
                    return 0;
                } else {
                    std::cout << "[ERROR] Invalid Option. Closing Application" << std::endl;
                    return 1;
                }

            } else {
                std::cout << "[ERROR] Invalid Input!\nClosing Application" << std::endl;
                return 1;
            }

        } else {
            std::cout << "[ERROR] Invalid Input!\nClosing Application." << std::endl;
            return 1;
        }
        
    } else if(userChosenOption == 2){
        std::cout << "Well, we don't really have a costumer support, so we'll just end the chat :)\nHave a great day!" << std::endl;
    } else {
        std::cout << "Invalid input, try again another time." << std::endl;
        return 1;
    }

    return 0;
}

float Rooms(unsigned int rooms)
{
    float value {0};

    value = (rooms * chargePerRoom) * salesTax;
    return value;
}

std::string toUpperCase(std::string str)
{
    for(char& c : str){
        c = std::toupper(c);
    }
    return str;
}

