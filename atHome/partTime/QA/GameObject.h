#ifndef TEXTADV_GAMEOBJECT_H
#define TEXTADV_GAMEOBJECT_H
#include <string>
#include <list>
#include <vector>
using std::string;
using std::list;
using std::vector;
class GameObject {
    const string* shortName;

    const string* longDescription;

    const string* keyword;

    static list<GameObject*> gameObjects;

    static vector<int> gameObjectIds;
public:
    GameObject(const string* _shortName, const string* _longDescription, const string* _keyword);
    static void insertGameObject(GameObject* object, int id);
    static GameObject* getGameObject(const string* _keyword);
    static void resetId(GameObject* object, int newId);
    static void getGameObjectsById(int gameObjectId, list<GameObject*>& objects);
    static void getGameObjectIds(list<int>& objectIds);
    static void resetGameObjectIds(list<int>& objectIds);
    const string* showKeyword();
    const string* showShortName();
    const string* describe();

};


#endif //TEXTADV_GAMEOBJECT_H
