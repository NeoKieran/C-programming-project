#include <iostream>
#include <string>

// Function to display the main menu
void displayMainMenu(int teamNumber, const std::string& teamLeaderName) {
    std::cout << "Team Number		: " << teamNumber << "\n";
    std::cout << "Team Leader Name	: " << teamLeaderName << "\n";
    std::cout << "------------------------------------------\n\n";
    std::cout << "Welcome to Team " << teamNumber <<" Group Project\n\n";
    std::cout << "1) 	Configure Autopilot Mapping Exploration settings\n";
    std::cout << "2) 	Configure Terrain Exploration Simulator settings\n";
    std::cout << "3) 	Start Autopilot Mapping!\n";
    std::cout << "4) 	Start Simulation!\n";
    std::cout << "5) 	End\n\n";
    std::cout << "Please enter your choice: ";
}

// Function to configure auto-pilot settings
void configureAutopilotSettings(std::string& inputFilename, bool& isEncrypted, std::string& outputFilename) {
    char choice;
    do {
        std::cout << "\n		[ Configure Autopilot Mapping Exploration settings ]\n\n";
        std::cout << "		a)	Specify INPUT scenario filename (current: " << inputFilename << ")\n";
        std::cout << "		b)	Specify INPUT scenario file encrypted (current: " << (isEncrypted ? "Y" : "N") << ")\n";
        std::cout << "		c)	Specify OUTPUT map report filename (current: " << outputFilename << ")\n";
        std::cout << "		d)	Back to main menu\n\n";
        std::cout << "		Please enter your choice (a - d): ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
                std::cout << "\n		Please enter INPUT scenario filename (current: " << inputFilename << ") : ";
                std::cin >> inputFilename;
                std::cout << "\n		INPUT scenario filename successfully set to '" << inputFilename << "'!\n";
                break;
            case 'b':
                char encryptedChoice;
                std::cout << "\n		Is the INPUT scenario file encrypted? (Y/N): ";
                std::cin >> encryptedChoice;
                isEncrypted = (encryptedChoice == 'Y' || encryptedChoice == 'y');
                std::cout << "\n		INPUT scenario file encryption set to " << (isEncrypted ? "Y" : "N") << "!\n";
                break;
            case 'c':
                std::cout << "\n		Please enter OUTPUT map report filename (current: " << outputFilename << "): ";
                std::cin >> outputFilename;
                std::cout << "\n		OUTPUT map report filename successfully set to '" << outputFilename << "'!\n";
                break;
            case 'd':
                std::cout << "\n		Going back to main menu...\n\n\n";
                break;	
            default:
                std::cout << "\n		Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 'd');
}

// Function to configure simulator settings
void configureSimulatorSettings(std::string& inputMapFilename, std::string& outputRouteFilename, std::string& routeCriteria, std::string& vehicleType) {
    char choice;
    do {
        std::cout << "\n		[ Configure Terrain Exploration Simulator settings ]\n\n";
        std::cout << "		a)	Specify INPUT map details filename (current: " << inputMapFilename << ")\n";
        std::cout << "		b)	Specify OUTPUT route report filename (current: " << outputRouteFilename << ")\n";
        std::cout << "		c)	Specify ideal route criteria (current: " << routeCriteria << ")\n";
        std::cout << "		d)	Specify vehicle type (current: " << vehicleType << ")\n";
        std::cout << "		e)	Back to main menu\n";
        std::cout << "\n		Please enter your choice (a - e): ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
                std::cout << "\n		Please enter INPUT map details filename (current: " << inputMapFilename << "): ";
                std::cin >> inputMapFilename;
                std::cout << "\n		INPUT map details filename successfully set to '" << inputMapFilename << "'!\n";
                break;
            case 'b':
                std::cout << "\n		Please enter OUTPUT route report filename (current: " << outputRouteFilename << "): ";
                std::cin >> outputRouteFilename;
                std::cout << "\n		OUTPUT route report filename successfully set to '" << outputRouteFilename << "'!\n";
                break;
            case 'c':{
		char criteriaChoice;
		do {
    		    std::cout << "\n			[ Specify Ideal Route Criteria (current: " << routeCriteria << ") ]\n\n";
    		    std::cout << "			a)	minimized total energy expenditure\n";
    		    std::cout << "			b)	shortest distance from Start to End locations\n";
		    std::cout << "			c)	go back to sub menu\n\n";
    		    std::cout << "			Please enter your choice (a - c): ";
    		    std::cin >> criteriaChoice;

    		    switch (criteriaChoice) {
        		case 'a':
            		routeCriteria = "minimized total energy expenditure";
            		std::cout << "\n			Ideal route criteria successfully set to '" << routeCriteria << "'!\n";
            		break;
        		case 'b':
            		routeCriteria = "shortest distance from Start to End locations";
            		std::cout << "\n			Ideal route criteria successfully set to '" << routeCriteria << "'!\n";
            		break;
			case 'c':
			std::cout << "\n			Going back to sub menu...\n";
			break;
        		default:
            		std::cout << "\n			Invalid choice! Criteria not changed.\n";
            		break;
    			}
		}
		while (criteriaChoice != 'c'); // Loop until the user chooses 'c' to go back
		break;
	    }
	    case 'd': {
                char vehicleChoice;
                do {
                    std::cout << "\n			[ Specify Vehicle Type (current: " << vehicleType << ") ]\n\n";
                    std::cout << "			a)	HighLander (Hill h, Mountain M)\n";
                    std::cout << "			b)	DragonFly (Swamp w, Watery ~)\n";
                    std::cout << "			c)	ShieldHero (Danger area X)\n";
                    std::cout << "			d)	Go back to sub menu\n";
                    std::cout << "\n			Please enter your choice (a - d): ";
                    std::cin >> vehicleChoice;

                    switch (vehicleChoice) {
                        case 'a':
                            vehicleType = "HighLander";
                            std::cout << "\n			Vehicle type successfully set to '" << vehicleType << "'!\n";
                            break;
                        case 'b':
                            vehicleType = "DragonFly";
                            std::cout << "\n			Vehicle type successfully set to '" << vehicleType << "'!\n";
                            break;
                        case 'c':
                            vehicleType = "ShieldHero";
                            std::cout << "\n			Vehicle type successfully set to '" << vehicleType << "'!\n";
                            break;
                        case 'd':
                            std::cout << "\n			Going back to sub menu...\n";
                            break;
                        default:
                            std::cout << "\n			Invalid choice! Vehicle type not changed.\n";
                            break;
                    }
                } while (vehicleChoice != 'd'); // Loop until the user chooses 'd' to go back
                break;
            }
            case 'e':
                std::cout << "\n		Going back to main menu...\n\n\n";
                break;
            default:
                std::cout << "\n		Invalid choice! Please try again.\n\n";
                break;
        }
    } while (choice != 'e');
}

// Function to handle the main menu
void handleMainMenu(int teamNumber, const std::string& teamLeaderName) {
    // Default settings for auto-pilot mapping
    std::string inputFilename = "default.dat";
    bool isEncrypted = true;
    std::string outputFilename = "map-rpt.txt";

    // Default settings for terrain exploration simulator
    std::string inputMapFilename = "map-rpt.txt";
    std::string outputRouteFilename = "route-rpt.txt";
    std::string routeCriteria = "minimized total energy expenditure";
    std::string vehicleType = "HighLander";

    int choice;
    do {
        displayMainMenu(teamNumber, teamLeaderName);
        std::cin >> choice;

        switch (choice) {
            case 1:
                configureAutopilotSettings(inputFilename, isEncrypted, outputFilename);
                break;
            case 2:
                configureSimulatorSettings(inputMapFilename, outputRouteFilename, routeCriteria, vehicleType);
                break;
            case 3:
                std::cout << "\nStarting Autopilot Mapping...\n";
                // Call function to start auto-pilot mapping
                break;
            case 4:
                std::cout << "\nStarting Simulation...\n";
                // Call function to start simulation
                break;
            case 5:
                std::cout << "\nExiting program...\n";
                break;
            default:
                std::cout << "\nInvalid choice! Please try again.\n\n";
                break;
        }
    } while (choice != 5);
}

int main() {
    int teamNumber = 1; // Replace with your team number
    std::string teamLeaderName = "Alexandre Cotton"; // Replace with your team leader's name

    handleMainMenu(teamNumber, teamLeaderName);

    return 0;
}
