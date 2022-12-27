//
// Created by DrMark on 10/2/2017.
//

#include "State.h"

/**
 * Current state of the game.
 */

/**
 * Display the description of the room the player is in. */

void State::announceLoc() const {
    this->currentRoom->describe();
}

/**
 * Constructor.
 * @param startRoom Pointer to the room to start in.
 */
State::State(Room *startRoom) : currentRoom(startRoom) {};

/**
 * Move to a specified room and print its description.
 * @param target Pointer to the room to move to.
 */
void State::goTo(Room *target) {
    this->currentRoom = target;
    this->announceLoc();
}

/**
 * Return a pointer to the current room.
 * @return Pointer to the current room.
 */
Room* State::getCurrentRoom() const {
    return this->currentRoom;
}

GameObject* State::getGameObject(const string *keyword) {
    for(auto& gameObject:inventory){
        if(*gameObject->showKeyword() == *keyword){
            return gameObject;
        }
    }
    return nullptr;
}

void State::insertGameObject(GameObject *gameObject) {
    this->inventory.push_back(gameObject);
}

GameObject *State::deleteGameObject(const string *keyword) {
    for(auto& gameObject:inventory){
        if(*gameObject->showKeyword() == *keyword){
            this->inventory.remove(gameObject);
            return gameObject;
        }
    }
    return nullptr;
}

list<GameObject *> State::getInventory() {
    return this->inventory;
}


