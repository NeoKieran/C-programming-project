//This ver works until pg 8 of 22

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <iomanip>

// Function prototypes
void configureAutopilotSettings(std::string& inputFilename, bool& isEncrypted, std::string& outputFilename);
void configureSimulatorSettings(std::string& inputMapFilename, std::string& outputRouteFilename, std::string& routeCriteria, std::string& vehicleType);
void startAutopilotMapping(const std::string& inputFilename, bool isEncrypted, const std::string& outputFilename);

// Function to display the main menu
void displayMainMenu(int teamNumber, const std::string& teamLeaderName) {
    std::cout << "\n\033[1mTeam Number\033[0m        : " << teamNumber << "\n";
    std::cout << "\033[1mTeam Leader Name\033[0m   : " << teamLeaderName << "\n";
    std::cout << "------------------------------------------\n\n";
    std::cout << "Welcome to Team " << teamNumber << " Group Project\n\n";
    std::cout << "1) Configure Autopilot Mapping Exploration settings\n";
    std::cout << "2) Configure Terrain Exploration Simulator settings\n";
    std::cout << "3) Start Autopilot Mapping!\n";
    std::cout << "4) Start Simulation!\n";
    std::cout << "5) End\n\n";
    std::cout << "Please enter your choice: ";
}

// Function to configure simulator settings
void configureSimulatorSettings(std::string& inputMapFilename, std::string& outputRouteFilename, std::string& routeCriteria, std::string& vehicleType) {
    char choice;
    do {
        std::cout << "\n[ Configure Terrain Exploration Simulator settings ]\n";
        std::cout << "    a) Specify INPUT map details filename (current: \033[32m" << inputMapFilename << "\033[0m)\n";
        std::cout << "    b) Specify OUTPUT route report filename (current: \033[32m" << outputRouteFilename << "\033[0m)\n";
        std::cout << "    c) Specify ideal route criteria (current: \033[32m" << routeCriteria << "\033[0m)\n";
        std::cout << "    d) Specify vehicle type (current: \033[32m" << vehicleType << "\033[0m)\n";
        std::cout << "    e) Back to main menu\n\n";

        std::cout << "Please enter your choice (a - e): ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 'a': {
                std::cout << "\nPlease enter INPUT map details filename: ";
                std::getline(std::cin, inputMapFilename);
                std::cout << "INPUT map details filename successfully set to '\033[31m" << inputMapFilename << "\033[0m'!\n";
                break;
            }
            case 'b': {
                std::cout << "\nPlease enter OUTPUT route report filename: ";
                std::getline(std::cin, outputRouteFilename);
                std::cout << "OUTPUT route report filename successfully set to '\033[31m" << outputRouteFilename << "\033[0m'!\n";
                break;
            }
          case 'c': { 
                char criteriaChoice;
                do {
                    std::cout << "\n[ Specify Ideal Route Criteria (current: \033[32m" << routeCriteria << "\033[0m) ]\n";
                    std::cout << "    a) Minimized total energy expenditure\n";
                    std::cout << "    b) Shortest distance from Start to End locations\n";
                    std::cout << "    c) Go back to sub menu\n\n";
                    std::cout << "Enter your choice (a - c): ";
                    std::cin >> criteriaChoice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    switch (criteriaChoice) {
                        case 'a':
                            routeCriteria = "minimized total energy expenditure";
                            std::cout << "Ideal Route Criteria successfully set to '\033[32m" << routeCriteria << "\033[0m'!\n";
                            break;
                        case 'b':
                            routeCriteria = "shortest distance from Start to End locations";
                            std::cout << "Ideal Route Criteria successfully set to '\033[32m" << routeCriteria << "\033[0m'!\n";
                            break;
                        case 'c':
                            std::cout << "Going back to sub menu...\n";
                            break;
                        default:
                            std::cout << "Invalid choice! Please try again.\n";
                            break;
                    }
                } while (criteriaChoice != 'c'); 
                break;
            }
            case 'd': {
                char vehicleChoice;
                do {
                    std::cout << "\n[ Specify Vehicle Type (current: \033[32m" << vehicleType << "\033[0m) ]\n";
                    std::cout << "    a) HighLander (Hill h, Mountain M)\n";
                    std::cout << "    b) DragonFly (Swamp w, Watery ~)\n";
                    std::cout << "    c) ShieldHero (Danger area X)\n";
                    std::cout << "    d) Go back to sub menu\n\n";
                    std::cout << "Enter your choice (a - d): ";
                    std::cin >> vehicleChoice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    switch (vehicleChoice) {
                        case 'a':
                            vehicleType = "HighLander";
                            std::cout << "Vehicle Type successfully set to '\033[32m" << vehicleType << "\033[0m'!\n";
                            break;
                        case 'b':
                            vehicleType = "DragonFly";
                            std::cout << "Vehicle Type successfully set to '\033[32m" << vehicleType << "\033[0m'!\n";
                            break;
                        case 'c':
                            vehicleType = "ShieldHero";
                            std::cout << "Vehicle Type successfully set to '\033[32m" << vehicleType << "\033[0m'!\n";
                            break;
                        case 'd':
                            std::cout << "Going back to sub menu...\n";
                            break;
                        default:
                            std::cout << "Invalid choice! Please try again.\n";
                            break;
                    }
                } while (vehicleChoice != 'd');
                break;
            }
            case 'e':
                std::cout << "Returning to main menu...\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter a valid option.\n";
                break;
        }
    } while (choice != 'e');
}
// Function to get current time in DD/MM/YY HH:MM:SS format
std::string getCurrentTime() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << localTime->tm_mday << "/"
        << std::setw(2) << (localTime->tm_mon + 1) << "/"
        << (localTime->tm_year % 100) << " "
        << std::setw(2) << localTime->tm_hour << ":"
        << std::setw(2) << localTime->tm_min << ":"
        << std::setw(2) << localTime->tm_sec;
    return oss.str();
}

// Function to start autopilot mapping
void startAutopilotMapping(const std::string& inputFilename, bool isEncrypted, const std::string& outputFilename) {
    std::cout << "\n[ Start Autopilot Mapping ]\n";
    std::cout << "INPUT scenario file name    = \033[32m" << inputFilename << "\033[0m\n";
    std::cout << "INPUT scenario file encrypted = \033[32m" << (isEncrypted ? "Y" : "N") << "\033[0m\n";
    std::cout << "OUTPUT map report filename  = \033[32m" << outputFilename << "\033[0m\n\n";

    // Ask if the user wants to display the report
    char displayChoice;
    std::cout << "When mapping ends, do you wish to display map report on Ubuntu terminal? (Y/N): ";
    std::cin >> displayChoice;
    std::cin.ignore();
    bool displayReport = (displayChoice == 'Y' || displayChoice == 'y');

    std::cout << "\nBEGIN NOW? ( Y ) : ";
    char beginChoice;
    std::cin >> beginChoice;
    std::cin.ignore();

    if (beginChoice != 'Y' && beginChoice != 'y') {
        std::cout << "Mapping process aborted.\n";
        return;
    }

    std::string startTime = getCurrentTime();
    std::time_t start = std::time(nullptr);
    std::cout << "\nAutopilot Mapping STARTED! Start datetime stamp = " << startTime << "\n";
    std::cout << "\nMAPPING IN PROGRESS … PLEASE DO NOT END PROGRAM !\n";
    
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Simulated delay

    std::string endTime = getCurrentTime();
    std::time_t end = std::time(nullptr);
    std::cout << "\nAutopilot Mapping ENDED! End datetime stamp = " << endTime << "\n";
    
    int duration = static_cast<int>(difftime(end, start));
    int hours = duration / 3600;
    int minutes = (duration % 3600) / 60;
    int seconds = duration % 60;
    
    std::cout << "Total Mapping Duration : " << std::setw(2) << std::setfill('0') << hours << " hr "
              << std::setw(2) << minutes << " min "
              << std::setw(2) << seconds << " sec\n";

    std::ofstream reportFile(outputFilename);
    if (reportFile) {
        reportFile << "Autopilot Mapping Report\n";
        reportFile << "Start Time: " << startTime << "\n";
        reportFile << "End Time: " << endTime << "\n";
        reportFile << "Total Mapping Duration: " << hours << " hr " << minutes << " min " << seconds << " sec\n";
        reportFile << "Scenario File Used: " << inputFilename << "\n";
        reportFile.close();
        std::cout << "Map report saved to: \033[32m" << outputFilename << "\033[0m\n";
    } else {
        std::cerr << "Error: Unable to save map report!\n";
        return;
    }

    // Display the report if the user requested it
    if (displayReport) {
        std::cout << "\nDisplaying contents of " << outputFilename << " on Ubuntu terminal:\n\n";
        std::ifstream inFile(outputFilename);
        if (inFile) {
            std::string line;
            while (std::getline(inFile, line)) {
                std::cout << line << "\n";
            }
            inFile.close();
        } else {
            std::cerr << "Error: Unable to read map report!\n";
        }
    }
}

// Function to configure autopilot settings
void configureAutopilotSettings(std::string& inputFilename, bool& isEncrypted, std::string& outputFilename) {
    char choice;
    do {
        std::cout << "\n[ Configure Autopilot Mapping Exploration settings ]\n";
        std::cout << "    a) Specify INPUT scenario filename (current: \033[32m" << inputFilename << "\033[0m)\n";
        std::cout << "    b) Specify INPUT scenario file encrypted (current: \033[32m" << (isEncrypted ? "Y" : "N") << "\033[0m)\n";
        std::cout << "    c) Specify OUTPUT map report filename (current: \033[32m" << outputFilename << "\033[0m)\n";
        std::cout << "    d) Back to main menu\n\n";

        std::cout << "Please enter your choice (a - d): ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 'a': {
                std::cout << "\nPlease enter INPUT scenario filename: ";
                std::getline(std::cin, inputFilename);
                std::cout << "\nINPUT scenario filename successfully set to '\033[31m" << inputFilename << "\033[0m'!\n";
                break;
            }
            case 'b': {
                char encryptChoice;
                std::cout << "Is the INPUT scenario file encrypted? (Y/N): ";
                std::cin >> encryptChoice;
                std::cin.ignore();
                isEncrypted = (encryptChoice == 'Y' || encryptChoice == 'y');
                std::cout << "INPUT scenario file encryption set to '\033[31m" << (isEncrypted ? "Y" : "N") << "\033[0m'!\n";
                break;
            }
            case 'c': {
                std::cout << "Please enter OUTPUT map report filename: ";
                std::getline(std::cin, outputFilename);
                std::cout << "\nOUTPUT map report filename successfully set to '\033[31m" << outputFilename << "\033[0m'!\n";
                break;
            }
            case 'd':
                std::cout << "Returning to main menu...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 'd');
}

int main() {
    std::string inputFilename = "default.dat";
    bool isEncrypted = true;
    std::string outputFilename = "map-rpt.txt";

    std::string inputMapFilename = "map-rpt.txt";
    std::string outputRouteFilename = "route-rpt.txt";
    std::string routeCriteria = "Minimized total energy expenditure";
    std::string vehicleType = "HighLander";

    int choice;
    do {
        displayMainMenu(1, "Alexandre Cotton");
        
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                configureAutopilotSettings(inputFilename, isEncrypted, outputFilename);
                break;
            case 2:  
                configureSimulatorSettings(inputMapFilename, outputRouteFilename, routeCriteria, vehicleType);
                break;
            case 3:
                startAutopilotMapping(inputFilename, isEncrypted, outputFilename);
                break;
            case 5:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter a number between 1-5.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
