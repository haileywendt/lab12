// lab12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

//Function Prototypes
vector<int> getAdjacentRooms(vector<vector<int>> map, int currentRoom);
bool isValidMove(int to, vector<int> connections);
void printCurrentRoom(int room);
void printAdjacentRooms(vector<int> rooms);
void pressEnterToContinue(void);

int main()
{
    // Part A: MP4 Development - code provided by Dr. Estell
    /*vector<vector<int>> dodecahedron{
        {-1, -1, -1},  // no node 0...
        { 2,  5,  8},  // node 1
        { 1,  3, 10},  // node 2
        { 2,  4, 12},  // node 3
        { 3,  5, 14},  // node 4
        { 1,  4,  6},  // node 5
        { 5,  7, 15},  // node 6
        { 6,  8, 17},  // node 7
        { 1,  7,  9},  // node 8
        { 8, 10, 18},  // node 9
        { 2,  9, 11},  // node 10
        {10, 12, 19},  // node 11
        { 3, 11, 13},  // node 12
        {12, 14, 20},  // node 13
        { 4, 13, 15},  // node 14
        { 6, 14, 16},  // node 15
        {15, 17, 20},  // node 16
        { 7, 16, 18},  // node 17
        { 9, 17, 19},  // node 18
        {11, 18, 20},  // node 19
        {13, 16, 19}   // node 20
    };

    int currentRoom = 0;
    int enteredRoom;
    vector<int> adjacentRooms;

    srand(time(NULL));
    cout << "Dodecahedron Run - enter value 1-20 to start at that room: ";
    cin >> enteredRoom;
    if (enteredRoom < 1 || enteredRoom > 20) { // Easter Egg - randomly select room
        currentRoom = rand() % 20 + 1;
    }
    else {
        currentRoom = enteredRoom;
    }

    // run 'til you're done...
    while (true) {
        adjacentRooms = getAdjacentRooms(dodecahedron, currentRoom);
        printCurrentRoom(currentRoom);
        printAdjacentRooms(adjacentRooms);

        cout << "Where to? ";
        cin >> enteredRoom;
        if (cin.fail()) break;

        if (isValidMove(enteredRoom, getAdjacentRooms(dodecahedron, currentRoom))) {
            currentRoom = enteredRoom;
        }
        else {
            cout << "You can't get there from here." << endl;
        }
    }
    cout << "Thanks for playing!" << endl;
    return 0;*/

    // Part B: Text Files
    // Problem 1
    /*cout << "Input file: ";
    string filename = " ";
    cin >> filename;
    ifstream in_file;
    in_file.open(filename.c_str());

    string word;
    int words = 0;
    while (in_file >> word) {
        words++;
    }
    cout << "Words: " << words << endl;
    in_file.close();

    char c;
    int characters = 0;
    in_file.open(filename.c_str());
    while (in_file.get(c)) {
        if (c != ' ' && c != '\n') {
            characters++;
        }
    }
    in_file.close();
    cout << "Characters: " << characters << endl;

    pressEnterToContinue();*/

    // Problem 2
   /* cout << "Input file: ";
    string filename = " ";
    cin >> filename;
    ifstream in_file;
    in_file.open(filename.c_str());

    string word;
    int words = 0;
    while (in_file >> word) {
        if (word != "-" && word != "\n" && word != " ") {
            words++;
        }
    }
    cout << "Words: " << words << endl;
    in_file.close();

    char c;
    int characters = 0;
    in_file.open(filename.c_str());
    while (in_file.get(c)) {
        if (c != ' ' && c != '\n' && c != '.' && c != ',' && c != '-') {
            characters++;
        }
    }
    in_file.close();
    cout << "Characters: " << characters << endl;

    pressEnterToContinue();*/
}

/**
getAdjacentRooms - lets you know what rooms you can directly move to from the current room.
@param map - 2-D vector of integers containing the game's room map
@param currentRoom - integer value indicating one's current location
@return integer vector containing list of rooms that it's legal to move to
*/
vector<int> getAdjacentRooms(vector<vector<int>> map, int currentRoom) {
    return map[currentRoom];
}

/**
isValidMove - given a room number, can one directly move there from where they currently are?
@param to - proposed room to move to
@param connections - list of rooms adjacent to the current room
@return true if specific room is adjacent, false otherwise
*/
bool isValidMove(int to, vector<int> connections) {
    for (int i = 0; i < connections.size(); i++) {
        if (to == connections[i]) {
            return true;
        }
    }
    return false;
}

/**
printCurrentRoom - display message containing current room number.
@param room - current room number
*/
void printCurrentRoom(int room) {
    cout << "You are in room " << room << endl;
}

/**
printAdjacentRooms - display message listing those rooms adjacent to the current room.
@param rooms - list of rooms adjacent to the current room.
*/
void printAdjacentRooms(vector<int> rooms) {
    cout << "Tunnels lead to rooms ";
    for (int i = 0; i < rooms.size(); i++) {
        cout << rooms[i];
        if (i < rooms.size() - 1) {
            cout << ", ";
        }
        else {
            cout << endl;
        }
    }
}

// pressEnterToContinue: used to keep the console window open long enough to see
// your program's output.
//
// Parameters: none
// Returns: nothing
void pressEnterToContinue(void) {
    char c;
    cout << "Press Enter to continue...";
    cin.ignore(1024, '\n');
    do { cin.get(c); } while (c != '\n' && c != EOF);
    return;
}
