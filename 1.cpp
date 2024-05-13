#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Struct representing information about attractions
struct Attraction {
    string name;
    string description;
};

// Struct representing information about accommodations
struct Accommodation {
    string name;
    string address;
    int rating;
};

// Struct representing information about activities
struct Activity {
    string name;
    string description;
};

// Struct representing information about tourist destinations
struct TouristDestination {
    string name;
    string description;
    vector<Attraction> attractions;
    vector<Accommodation> accommodations;
    vector<Activity> activities;
};

// Function to print information about a tourist destination
void printTouristDestination(const TouristDestination& destination) {
    cout << "Destination: " << destination.name << endl;
    cout << "Description: " << destination.description << endl;

    cout << "Attractions:" << endl;
    for (const auto& attraction : destination.attractions) {
        cout << "- " << attraction.name << ": " << attraction.description << endl;
    }

    cout << "Accommodations:" << endl;
    for (const auto& accommodation : destination.accommodations) {
        cout << "- " << accommodation.name << " (" << accommodation.rating << " stars): " << accommodation.address << endl;
    }

    cout << "Activities:" << endl;
    for (const auto& activity : destination.activities) {
        cout << "- " << activity.name << ": " << activity.description << endl;
    }

    cout << endl;
}

// Function to create a new tourist destination
TouristDestination createTouristDestination() {
    TouristDestination destination;
    cout << "Enter destination name: ";
    cin >> destination.name;
    cout << "Enter destination description: ";
    cin.ignore();
    getline(cin, destination.description);
    return destination;
}

// Function to create a new attraction
Attraction createAttraction() {
    Attraction attraction;
    cout << "Enter attraction name: ";
    cin >> attraction.name;
    cout << "Enter attraction description: ";
    cin.ignore();
    getline(cin, attraction.description);
    return attraction;
}

// Function to create a new accommodation
Accommodation createAccommodation() {
    Accommodation accommodation;
    cout << "Enter accommodation name: ";
    cin >> accommodation.name;
    cout << "Enter accommodation address: ";
    cin.ignore();
    getline(cin, accommodation.address);
    cout << "Enter accommodation rating (1-5 stars): ";
    cin >> accommodation.rating;
    return accommodation;
}

// Function to create a new activity
Activity createActivity() {
    Activity activity;
    cout << "Enter activity name: ";
    cin >> activity.name;
    cout << "Enter activity description: ";
    cin.ignore();
    getline(cin, activity.description);
    return activity;
}

// Function to update a tourist destination
void updateTouristDestination(TouristDestination& destination) {
    cout << "Enter new destination name: ";
    cin >> destination.name;
    cout << "Enter new destination description: ";
    cin.ignore();
    getline(cin, destination.description);
}

// Function to delete a tourist destination
void deleteTouristDestination(vector<TouristDestination>& destinations, int index) {
    destinations.erase(destinations.begin() + index);
}

// Function to delete an attraction
void deleteAttraction(vector<Attraction>& attractions, int index) {
    attractions.erase(attractions.begin() + index);
}

// Function to delete an accommodation
void deleteAccommodation(vector<Accommodation>& accommodations, int index) {
    accommodations.erase(accommodations.begin() + index);
}

// Function to delete an activity
void deleteActivity(vector<Activity>& activities, int index) {
    activities.erase(activities.begin() + index);
}

int main() {
    vector<TouristDestination> destinations;

    int choice;
    do {
        // Menu
        cout << "CRUD Operations on Tourist Destinations" << endl;
        cout << "1. Create Destination" << endl;
        cout << "2. Read Destination" << endl;
        cout << "3. Update Destination" << endl;
        cout << "4. Delete Destination" << endl;
        cout << "5. Create Attraction" << endl;
        cout << "6. Delete Attraction" << endl;
        cout << "7. Create Accommodation" << endl;
        cout << "8. Delete Accommodation" << endl;
        cout << "9. Create Activity" << endl;
        cout << "10. Delete Activity" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Create Destination
                TouristDestination newDestination = createTouristDestination();
                destinations.push_back(newDestination);
                break;
            }
            case 2: { // Read Destination
                cout << "Tourist Destinations:" << endl;
                for (size_t i = 0; i < destinations.size(); ++i) {
                    cout << i + 1 << ". " << destinations[i].name << endl;
                }
                cout << "Enter the index of the destination you want to view: ";
                int index;
                cin >> index;
                if (index > 0 && index <= static_cast<int>(destinations.size())) {
                    printTouristDestination(destinations[index - 1]);
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;
            }
            case 3: { // Update Destination
                cout << "Enter the index of the destination you want to update: ";
                int index;
                cin >> index;
                if (index > 0 && index <= static_cast<int>(destinations.size())) {
                    updateTouristDestination(destinations[index - 1]);
                    cout << "Destination updated successfully!" << endl;
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;
            }
            case 4: { // Delete Destination
                cout << "Enter the index of the destination you want to delete: ";
                int index;
                cin >> index;
                if (index > 0 && index <= static_cast<int>(destinations.size())) {
                    deleteTouristDestination(destinations, index - 1);
                    cout << "Destination deleted successfully!" << endl;
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;
            }
            case 5: { // Create Attraction
                cout << "Enter the index of the destination to add the attraction: ";
                int index;
                cin >> index;
                if (index > 0 && index <= static_cast<int>(destinations.size())) {
                    Attraction newAttraction = createAttraction();
                    destinations[index - 1].attractions.push_back(newAttraction);
                    cout << "Attraction added successfully!" << endl;
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;
            }
            case 6: { // Delete Attraction
                cout << "Enter the index of the destination from which you want to delete the attraction: ";
                int destIndex;
                cin >> destIndex;
                if (destIndex > 0 && destIndex <= static_cast<int>(destinations.size())) {
                    cout << "Enter the index of the attraction you want to delete: ";
                    int attIndex;
                    cin >> attIndex;
                    if (attIndex > 0 && attIndex <= static_cast<int>(destinations[destIndex - 1].attractions.size())) {
                        deleteAttraction(destinations[destIndex - 1].attractions, attIndex - 1);
                        cout << "Attraction deleted successfully!" << endl;
                    } else {
                        cout << "Invalid attraction index!" << endl;
                    }
                } else {
                    cout << "Invalid destination index!" << endl;
                }
                break;
            }
            case 7: { // Create Accommodation
                int destIndex;
                cout << "Enter the index of the destination to add the accommodation: ";
                cin >> destIndex;
                if (destIndex > 0 && destIndex <= static_cast<int>(destinations.size())) {
                    Accommodation newAccommodation = createAccommodation();
                    destinations[destIndex - 1].accommodations.push_back(newAccommodation);
                    cout << "Accommodation added successfully!" << endl;
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;
            }
            case 8: { // Delete Accommodation
                cout << "Enter the index of the destination from which you want to delete the accommodation: ";
                int destIndex;
                cin >> destIndex;
                if (destIndex > 0 && destIndex <= static_cast<int>(destinations.size())) {
                    cout << "Enter the index of the accommodation you want to delete: ";
                    int accIndex;
                    cin >> accIndex;
                    if (accIndex > 0 && accIndex <= static_cast<int>(destinations[destIndex - 1].accommodations.size())) {
                        deleteAccommodation(destinations[destIndex - 1].accommodations, accIndex - 1);
                        cout << "Accommodation deleted successfully!" << endl;
                    } else {
                        cout << "Invalid accommodation index!" << endl;
                    }
                } else {
                    cout << "Invalid destination index!" << endl;
                }
                break;
            }
            case 9: { // Create Activity
                int destIndex;
                cout << "Enter the index of the destination to add the activity: ";
                cin >> destIndex;
                if (destIndex > 0 && destIndex <= static_cast<int>(destinations.size())) {
                    Activity newActivity = createActivity();
                    destinations[destIndex - 1].activities.push_back(newActivity);
                    cout << "Activity added successfully!" << endl;
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;
            }
            case 10: { // Delete Activity
                cout << "Enter the index of the destination from which you want to delete the activity: ";
                int destIndex;
                cin >> destIndex;
                if (destIndex > 0 && destIndex <= static_cast<int>(destinations.size())) {
                    cout << "Enter the index of the activity you want to delete: ";
                    int actIndex;
                    cin >> actIndex;
                    if (actIndex > 0 && actIndex <= static_cast<int>(destinations[destIndex - 1].activities.size())) {
                        deleteActivity(destinations[destIndex - 1].activities, actIndex - 1);
                        cout << "Activity deleted successfully!" << endl;
                    } else {
                        cout << "Invalid activity index!" << endl;
                    }
                } else {
                    cout << "Invalid destination index!" << endl;
                }
                break;
            }
            case 11: // Exit
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 11);

    return 0;
}
