//
// Created by DrMark on 10/2/2017.
//

#ifndef TEXTADV_STATE_H
#define TEXTADV_STATE_H

#include <list>
#include "Room.h"
#include "GameObject.h"
using std::list;
class State {
    Room *currentRoom;
    list<GameObject*> inventory;
public:
    explicit State(Room *startRoom);
    void goTo(Room *target);
    void announceLoc() const;
    Room* getCurrentRoom() const;
    GameObject* getGameObject(const string* keyword);
    void insertGameObject(GameObject* gameObject);
    GameObject* deleteGameObject(const string* keyword);
    list<GameObject*> getInventory();
};


#endif //TEXTADV_STATE_H
