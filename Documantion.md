# Tourist Destination Management System Documentation

## Overview
The Tourist Destination Management System is a console-based application designed to facilitate the management of tourist destinations, attractions, accommodations, and activities. The system allows users to perform CRUD (Create, Read, Update, Delete) operations on tourist destinations and their associated data.

## Features

1. **Destination Management**:
   - Create, view, update, and delete tourist destinations.
   - Each destination contains information such as name, description, attractions, accommodations, and activities.

2. **Attraction Management**:
   - Add attractions to existing tourist destinations.
   - Attractions include a name and description.

3. **Accommodation Management**:
   - Add accommodations to existing tourist destinations.
   - Accommodations include a name, address, and rating.

4. **Activity Management**:
   - Add activities to existing tourist destinations.
   - Activities include a name and description.

5. **Menu-Driven Interface**:
   - Users interact with the system through a menu-driven interface.
   - The interface provides options for performing various operations on tourist destinations and their associated data.

## Data Structures

1. **Structures**:
   - `Attraction`: Represents information about attractions within a tourist destination.
   - `Accommodation`: Represents information about accommodations available at a tourist destination.
   - `Activity`: Represents information about activities that can be performed at a tourist destination.
   - `TouristDestination`: Represents information about a tourist destination, including its name, description, attractions, accommodations, and activities.

2. **Vectors**:
   - Vectors are used to store collections of attractions, accommodations, and activities within each tourist destination.

## Functions

1. **CRUD Operations**:
   - `createTouristDestination()`: Creates a new tourist destination.
   - `printTouristDestination()`: Displays information about a tourist destination.
   - `updateTouristDestination()`: Updates the information of an existing tourist destination.
   - `deleteTouristDestination()`: Deletes an existing tourist destination.
   - Similar functions exist for managing attractions, accommodations, and activities.

2. **Input Handling**:
   - Functions such as `createAttraction()`, `createAccommodation()`, and `createActivity()` handle user input to create new entries.
   - User input is validated to ensure data integrity.

3. **Menu Handling**:
   - The `main()` function provides a menu-driven interface for users to select operations.
   - Each menu option corresponds to a specific operation, such as creating, viewing, updating, or deleting data.

## Usage
1. **Compilation**:
   - The code can be compiled using a C++ compiler such as g++ or Visual C++.
   - Example: `g++ -o tourist_destination tourist_destination.cpp`

2. **Execution**:
   - After compilation, execute the generated binary to run the program.
   - Example: `./tourist_destination`

3. **Operation**:
   - Follow the prompts in the console to perform various operations on tourist destinations and associated data.
