#include "D:\code\vsCode\NOTE\C++\atHome\partTime\QA\GameObject.h"

std::list<GameObject *> GameObject::gameObjects;
std::vector<int> GameObject::gameObjectIds;//GameObject的成员，用来记录Object的ID

GameObject::GameObject(const string *_shortName, const string *_longDescription, const string *_keyword) {
    this->shortName = _shortName;
    this->longDescription = _longDescription;
    this->keyword = _keyword;
}

const string *GameObject::showKeyword() {
    return this->keyword;
}

const string *GameObject::showShortName() {
    return this->shortName;
}

const string *GameObject::describe() {
    return this->longDescription;
}

void GameObject::insertGameObject(GameObject *object, int id) {
    gameObjects.push_back(object);
    gameObjectIds.push_back(id);
}

GameObject *GameObject::getGameObject(const string *_keyword) {
    for (auto &gameObject: gameObjects) {
        if (gameObject->keyword->compare(*_keyword) == 0) {
            return gameObject;
        }
    }
    return nullptr;
}

void GameObject::resetId(GameObject *object, int newId) {
    int id = 0;
    for (auto &gameObject: gameObjects) {
        if (gameObject == object) {
            gameObjectIds[id] = newId;
        }
        id++;
    }
}

void GameObject::getGameObjectsById(int gameObjectId, list<GameObject *> &objects) {
    int id = 0;
    for (auto &gameObject: gameObjects) {
        if (gameObjectIds[id] == gameObjectId) {
            objects.push_back(gameObject);
        }
        id++;
    }
}

void GameObject::getGameObjectIds(list<int> &objectIds) {
    for (auto &id: gameObjectIds) {
        objectIds.push_back(id);
    }
}

void GameObject::resetGameObjectIds(list<int> &objectIds) {
    int id = 0;
    for (auto &objectId: objectIds) {
        gameObjectIds[id++] = objectId;
    }
}
