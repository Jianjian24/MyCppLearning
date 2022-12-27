#include <iostream>
#include <iomanip>
#include <memory>
#include <iterator>
#include <vector>
#include <forward_list>
#include <fstream>
#include "Room.h"
#include "wordwrap.h"
#include "State.h"
#include "strings.h"
#include "GameObject.h"

using std::string;
using std::unique_ptr;

string commandBuffer;
State *currentState;

/**
 * Print out the command prompt then read a command into the provided string buffer.
 * @param buffer Pointer to the string buffer to use.
 */
void inputCommand(string *buffer) {
    buffer->clear();
    std::cout << "> ";
    std::getline(std::cin, *buffer);
}

/**
 * Sets up the map.
 */
void initRooms() {
    auto *r2 = new Room(&r2name, &r2desc);
    auto *r1 = new Room(&r1name, &r1desc);
    auto *r3 = new Room(&r3name, &r3desc);
    auto *r4 = new Room(&r4name, &r4desc);
    auto *r5 = new Room(&r5name, &r5desc);

//    auto* g1 = new GameObject(&g1name, &g1desc, & g1keyword);
//    auto* g2 = new GameObject(&g2name, &g2desc, & g2keyword);
    auto *g3 = new GameObject(&g3name, &g3desc, &g3keyword);
    auto *g4 = new GameObject(&g4name, &g4desc, &g4keyword);
//    auto* g5 = new GameObject(&g5name, &g5desc, & g5keyword);

//    GameObject::insertGameObject(g1);
//    GameObject::insertGameObject(g2);
    GameObject::insertGameObject(g3, 3);
    GameObject::insertGameObject(g4, 4);
//    GameObject::insertGameObject(g5);
//    r1->insertGameObject(g1);
//    r2->insertGameObject(g2);
    r3->insertGameObject(g3);
    r4->insertGameObject(g4);
//    r5->insertGameObject(g5);
    Room::addRoom(r1);
    Room::addRoom(r2);
    Room::addRoom(r3);
    Room::addRoom(r4);
    Room::addRoom(r5);
    r1->setNorth(r2);
    r1->setSouth(r5);
    r1->setEast(r3);
    r1->setWest(r4);
    r5->setNorth(r1);
    r2->setSouth(r1);
    r3->setWest(r1);
    r4->setEast(r1);
}

/**
 * Sets up the game state.
 */
void initState() {
    currentState = new State(Room::rooms.front());
}


/**
 * The main game loop.
 */
void gameLoop() {
    bool gameOver = false;
    int nSteps = 0, eSteps = 0;
    while (!gameOver) {
        /* Ask for a command. */
        bool commandOk = false;
        inputCommand(&commandBuffer);

        /* The first word of a command would normally be the verb. The first word is the text before the first
         * space, or if there is no space, the whole string. */
        auto endOfVerb = static_cast<uint8_t>(commandBuffer.find(' '));

        /* We could copy the verb to another string but there's no reason to, we'll just compare it in place. */
        /* Command to go north. */
        if ((commandBuffer.compare(0, endOfVerb, "north") == 0) || (commandBuffer.compare(0, endOfVerb, "n") == 0)) {
            commandOk = true; /* Confirm command has been handled */
            /* See if there's a north exit */
            Room *northRoom = currentState->getCurrentRoom()->getNorth();
            if (northRoom == nullptr) { /* there isn't */
                wrapOut(&badExit);      /* Output the "can't go there" message */
                wrapEndPara();
            } else {                    /* There is */
                currentState->goTo(northRoom); /* Update state to that room - this will also describe it */
                nSteps++;
            }
        }
        if ((commandBuffer.compare(0, endOfVerb, "south") == 0) || (commandBuffer.compare(0, endOfVerb, "s") == 0)) {
            commandOk = true; /* Confirm command has been handled */
            /* See if there's a north exit */
            Room *southRoom = currentState->getCurrentRoom()->getSouth();
            if (southRoom == nullptr) { /* there isn't */
                wrapOut(&badExit);      /* Output the "can't go there" message */
                wrapEndPara();
            } else {                    /* There is */
                currentState->goTo(southRoom); /* Update state to that room - this will also describe it */
                nSteps--;
            }
        }
        if ((commandBuffer.compare(0, endOfVerb, "east") == 0) || (commandBuffer.compare(0, endOfVerb, "e") == 0)) {
            commandOk = true; /* Confirm command has been handled */
            /* See if there's a north exit */
            Room *eastRoom = currentState->getCurrentRoom()->getEast();
            if (eastRoom == nullptr) { /* there isn't */
                wrapOut(&badExit);      /* Output the "can't go there" message */
                wrapEndPara();
            } else {                    /* There is */
                currentState->goTo(eastRoom); /* Update state to that room - this will also describe it */
                eSteps++;
            }
        }
        if ((commandBuffer.compare(0, endOfVerb, "west") == 0) || (commandBuffer.compare(0, endOfVerb, "w") == 0)) {
            commandOk = true; /* Confirm command has been handled */
            /* See if there's a north exit */
            Room *westRoom = currentState->getCurrentRoom()->getWest();
            if (westRoom == nullptr) { /* there isn't */
                wrapOut(&badExit);      /* Output the "can't go there" message */
                wrapEndPara();
            } else {                    /* There is */
                currentState->goTo(westRoom); /* Update state to that room - this will also describe it */
                eSteps--;
            }
        }
        auto n = commandBuffer.length() - 1;

        /* get */
        if (commandBuffer.compare(0, endOfVerb, "get") == 0) {
            //check the second input word
            if (endOfVerb >= 0 && endOfVerb < n) {
                commandOk = true;
                string keyword = commandBuffer.substr(endOfVerb + 1, n - endOfVerb);
                if (GameObject::getGameObject(&keyword) == nullptr) {
                    wrapOut(&notExistGameObject);      //not exist
                    wrapEndPara();
                } else {
                    //check the inventory
                    if (currentState->getGameObject(&keyword) != nullptr) {
                        wrapOut(&existGameObjectInventory);      //already in the inventory
                        wrapEndPara();
                    } else {
                        //check the room
                        auto gameObject = currentState->getCurrentRoom()->deleteGameObject(&keyword);
                        if (gameObject != nullptr) {
                            currentState->insertGameObject(gameObject);
                            GameObject::resetId(gameObject, 0);
                            string getInfo = "You get the " + keyword + ".";
                            wrapOut(&getInfo);      //get successfully
                            wrapEndPara();
                        } else {
                            wrapOut(&notExistGameObjectRoom);      //not in the room
                            wrapEndPara();
                        }
                    }
                }

            }
        }


        /* drop */
        if (commandBuffer.compare(0, endOfVerb, "drop") == 0) {
            if (endOfVerb < n) {
                commandOk = true;
                //check the second input word
                string keyword = commandBuffer.substr(endOfVerb + 1, n - endOfVerb);
                if (GameObject::getGameObject(&keyword) == nullptr) {
                    wrapOut(&notExistGameObject);      //not exist
                    wrapEndPara();
                } else {
                    auto gameObject = currentState->deleteGameObject(&keyword);
                    if (gameObject == nullptr) {
                        wrapOut(&notExistGameObjectInventory);      //not exist in the inventory
                        wrapEndPara();
                    } else {
                        gameObject = currentState->getCurrentRoom()->getGameObject(&keyword);
                        if (gameObject == nullptr) {
                            // drop object
                            currentState->getCurrentRoom()->insertGameObject(gameObject);
                            int roomId = Room::getRoomId(currentState->getCurrentRoom());
                            GameObject::resetId(gameObject, roomId);
                            string dropInfo = "You drop the " + keyword + ".";
                            wrapOut(&dropInfo); // drop successfully
                            wrapEndPara();
                        } else {
                            wrapOut(&existGameObjectRoom);      //already in the room
                            wrapEndPara();
                        }
                    }
                }
            }
        }

        /* examine */
        if (commandBuffer.compare(0, endOfVerb, "examine") == 0) {
            if (endOfVerb < commandBuffer.length() - 1) {
                commandOk = true;
                //check the second input word
                string keyword = commandBuffer.substr(endOfVerb + 1, n - endOfVerb);
                GameObject *gameObject = GameObject::getGameObject(&keyword); //not exist
                if (gameObject != nullptr) {
                    wrapOut(gameObject->describe());      //describe the GameObject
                    wrapEndPara();
                } else {
                    wrapOut(&notExistGameObject);
                    wrapEndPara();
                }
            }
        }

        /* inventory */
        if (commandBuffer.compare(0, endOfVerb, "inventory") == 0) {
            commandOk = true;
            if (currentState->getInventory().empty()) {
                string emptyInfo = "The inventory has no GameObject.";
                wrapOut(&emptyInfo);
                wrapEndPara();
            } else {
                string inventoryInfo = "The GameObject list in the inventory: ";
                wrapOut(&inventoryInfo);
                wrapEndPara();
                for (auto &gameObject: currentState->getInventory()) {
                    wrapOut(gameObject->showShortName());
                    wrapEndPara();
                }
                wrapEndPara();
            }

        }

        /* Save command */
        if ((commandBuffer.compare(0, endOfVerb, "save") == 0)) {
            commandOk = true;
            string file;
            string fileInfo = "Please enter the file name: ";
            wrapOut(&fileInfo);
            wrapEndPara();
            inputCommand(&file);
            std::ofstream fout(file);
            fout << nSteps << " " << eSteps << std::endl;
            list<int> gameObjectIds;
            GameObject::getGameObjectIds(gameObjectIds);
            for (int objectId: gameObjectIds) {
                fout << objectId << " ";
            }
            fout << std::endl;
            fout.close();
            string saveInfo = "You save the game to the file: " + file + ".";
            wrapOut(&saveInfo); // save successfully
            wrapEndPara();
        }

        /* Load command */
        if ((commandBuffer.compare(0, endOfVerb, "load") == 0)) {
            commandOk = true;
            string file;
            string fileInfo = "Please enter the file name: ";
            wrapOut(&fileInfo);
            wrapEndPara();
            inputCommand(&file);
            std::ifstream fin(file);
            fin >> nSteps >> eSteps;
            list<int> loadGameObjectIds;
            int loadGameObjectId;
            while (fin >> loadGameObjectId) {
                loadGameObjectIds.push_back(loadGameObjectId);
            }
            GameObject::resetGameObjectIds(loadGameObjectIds);
            int roomId = 1;
            for (auto &room: Room::rooms) {
                room->clearGameObjects();
                list<GameObject *> gameObjects;
                GameObject::getGameObjectsById(roomId, gameObjects);
                for (auto &gameObject: gameObjects) {
                    room->insertGameObject(gameObject);
                }
                roomId++;
            }
            Room* currentRoom = Room::rooms.front();

            if(nSteps > 0){
                for (int i = 0; i < nSteps; i++) {
                    currentRoom = currentRoom->getNorth();
                }
            }else{
                for (int i = 0; i < -nSteps; i++) {
                    currentRoom = currentRoom->getSouth();
                }
            }
            if(eSteps > 0){
                for (int i = 0; i < eSteps; i++) {
                    currentRoom = currentRoom->getEast();
                }
            }else{
                for (int i = 0; i < -eSteps; i++) {
                    currentRoom = currentRoom->getWest();
                }
            }
            currentState = new State(currentRoom);
            list<GameObject *> gameObjects;
            GameObject::getGameObjectsById(0, gameObjects);
            for (auto &gameObject: gameObjects) {
                currentState->insertGameObject(gameObject);
            }
            fin.close();
            string loadInfo = "You load the game from the file: " + file + ".";
            wrapOut(&loadInfo); // load successfully
            wrapEndPara();
        }


        /* Quit command */
        if ((commandBuffer.compare(0, endOfVerb, "quit") == 0)) {
            commandOk = true;
            gameOver = true;
        }

        /* If commandOk hasn't been set, command wasn't understood, display error message */
        if (!commandOk) {
            wrapOut(&badCommand);
            wrapEndPara();
        }
    }
}


int main() {
    initWordWrap();
    initRooms();
    initState();
    currentState->announceLoc();
    gameLoop();
    return 0;
}