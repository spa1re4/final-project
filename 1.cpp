#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Структура, представляющая информацию о достопримечательностях
struct Attraction {
    string name;
    string description;
};

// Структура, представляющая информацию об отеле
struct Accommodation {
    string name;
    string address;
    int rating;
};

// Структура, представляющая информацию о доступных активностях
struct Activity {
    string name;
    string description;
};

// Структура, представляющая информацию о туристическом направлении
struct TouristDestination {
    string name;
    string description;
    vector<Attraction> attractions;
    vector<Accommodation> accommodations;
    vector<Activity> activities;
};

// Функция для вывода информации о туристическом направлении
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

int main() {
    // Создаем несколько туристических направлений
    TouristDestination destination1 = {"Bishkek", "The capital city of Kyrgyzstan, known for its art, culture, and history."};
    destination1.attractions.push_back({"Ala-Too Square", "The heart of Bishkek is its central Ala-Too square."});
    destination1.attractions.push_back({"Victory Square", "Victory Square in Bishkek is a tribute to everyone who made their contribution to the approach of the cherished day."});
    destination1.accommodations.push_back({"Hotel Urban", "79 Yakova Logvinenko str, Bishkek", 3});
    destination1.accommodations.push_back({"Hotel Madison", "210 Kievskaya Street, Bishkek", 4});
    destination1.activities.push_back({"Ala-Archa Gorge", "The only mountains that can be better than mountains are those that you haven't been to yet."});

    TouristDestination destination2 = {"Saratov", "The city of Russia, It is known for the Volga river."};
    destination2.attractions.push_back({"Kirov Avenue", "There are many attractions on the former German street: Ancient merchant houses, the church Assuage My Sorrows."});
    destination2.attractions.push_back({"Saratov Bridge", "The automobile bridge across the Volga is the link between Saratov and the city of Engels."});
    destination2.accommodations.push_back({"Hotel Olympia", "N.G. Chernyshevsky Street, 61, Saratov", 4});
    destination2.accommodations.push_back({"Hotel Absolute", "128 Myasnitskaya Street, Saratov", 4});
    destination2.activities.push_back({"the Volga River", "go on a spa cruise along the Volga."});
    destination2.activities.push_back({"Victory Park", "visit the exhibition of military and civilian equipment."});
    
    TouristDestination destination3 = {"London", "The city of Russia, It is known for the Volga river."};
    destination3.attractions.push_back({"Kirov Avenue", "There are many attractions on the former German street: Ancient merchant houses, the church Assuage My Sorrows."});
    destination3.attractions.push_back({"Saratov Bridge", "The automobile bridge across the Volga is the link between Saratov and the city of Engels."});
    destination3.accommodations.push_back({"Hotel Olympia", "N.G. Chernyshevsky Street, 61, Saratov", 4});
    destination3.accommodations.push_back({"Hotel Absolute", "128 Myasnitskaya Street, Saratov", 4});
    destination3.activities.push_back({"the Volga River", "go on a spa cruise along the Volga."});
    destination3.activities.push_back({"Victory Park", "visit the exhibition of military and civilian equipment."});
    
    
    // Панель выбора туристических направлений
    cout << "Select a tourist destination:" << endl;
    cout << "1. Bishkek" << endl;
    cout << "2. Saratov" << endl;
    cout << "3. London" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    // Выводим информацию о выбранном туристическом направлении
    if (choice == 1) {
        printTouristDestination(destination1);
    } else if (choice == 2) { 
        printTouristDestination(destination2);
    } else if(choice ==3){
          printTouristDestination(destination3);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
