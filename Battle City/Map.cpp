//
//  Map.cpp
//  Battle City
//
//  Created by Edmund Do on 4/3/17.
//  Copyright © 2017 Edmund Do. All rights reserved.
//

#include "Map.hpp"
#include "MapIO.hpp"

#include <random>
#include <vector>

Map::Map(string filepath) {
    loadMapFromFile(filepath);
}

Map::Map(int width, int height) : width(width), height(height) {
    preferredStartCoords.push_back(Point2D(0, 0));
}

Map::~Map() {}

void Map::addPreferredStartCoord(int x, int y) {
    Point2D point(x, y);
    preferredStartCoords.push_back(point);
}

void Map::removePreferredStartCoord(int x, int y) {
    for(int i = 0; i < preferredStartCoords.size(); i++) {
        if(preferredStartCoords[i].getX() == x && preferredStartCoords[i].getY() == y) {
            preferredStartCoords.erase(preferredStartCoords.begin() + i);
        }
    }
}

void Map::addMapObj(MapObject &mobj) {
    mapObjs.push_back(&mobj);
}

void Map::removeMapObjAt(int x, int y) {
    for(int i = 0; i < mapObjs.size(); i++) {
        if(mapObjs[i]->getCoordX() == x && mapObjs[i]->getCoordY() == y) {
            mapObjs.erase(mapObjs.begin() + i);
        }
    }
}

Point2D Map::getRandomStartCoords() const {
    random_device rnd;
    int rand_index = rnd() % preferredStartCoords.size();
    return preferredStartCoords[rand_index];
}

MapObject* Map::getMapObjectAt(int x, int y) const {
    for(int i = 0; i < mapObjs.size(); i++) {
        if(x == mapObjs[i]->getCoordX() && y == mapObjs[i]->getCoordY()) {
            return mapObjs[i];
        }
    }
    
    return nullptr;
}

Obstacle* Map::getObstacleAt(int x, int y) const {
    for(int i = 0; i < mapObjs.size(); i++) {
        if(x == mapObjs[i]->getCoordX() && y == mapObjs[i]->getCoordY()) {
            if(Obstacle* o = dynamic_cast<Obstacle*>(mapObjs[i])) {
                return o;
            }
        }
    }
    
    return nullptr;
}

Terrain* Map::getTerrainAt(int x, int y) const {
    for(int i = 0; i < mapObjs.size(); i++) {
        if(x == mapObjs[i]->getCoordX() && y == mapObjs[i]->getCoordY()) {
            if(Terrain* t = dynamic_cast<Terrain*>(mapObjs[i])) {
                return t;
            }
        }
    }
    
    return nullptr;
}

vector<Point2D> Map::getPreferredStartCoords() const {
    return preferredStartCoords;
}

int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}

void Map::loadMapFromFile(string filepath) {
    MapData mapData = MapIO::read(filepath);
    
    this->width = mapData.width;
    this->height = mapData.height;
    
    this->preferredStartCoords = mapData.preferredStartCoords;
    this->mapObjs = mapData.mapObjs;
}
