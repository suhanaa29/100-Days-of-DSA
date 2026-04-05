/*Given an array rooms where rooms[i] is the set of keys that you can obtain 
if you visited room i, return true if you can visit all the rooms, or false otherwise.*/

#include <stdbool.h>

void dfs(int** rooms, int* roomsColSize, bool* visited, int currentRoom, int* visitedCount) {
    visited[currentRoom] = true;
    (*visitedCount)++;

    for (int i = 0; i < roomsColSize[currentRoom]; i++) {
        int key = rooms[currentRoom][i];
        if (!visited[key]) {
            dfs(rooms, roomsColSize, visited, key, visitedCount);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];
    for (int i = 0; i < roomsSize; i++) visited[i] = false;

    int visitedCount = 0;
    dfs(rooms, roomsColSize, visited, 0, &visitedCount);

    return visitedCount == roomsSize;
}
