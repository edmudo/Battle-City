//
//  LevelEditor.cpp
//  Battle City
//
//  Created by Edmund Do on 4/3/17.
//  Copyright © 2017 Edmund Do. All rights reserved.
//

#include "Obstacle.hpp"
#include "LevelEditor.hpp"

LevelEditor::LevelEditor(Map &m) : currentMap(m) {}

void LevelEditor::addObstacle(string name,int x, int y, int height, int width, Color color) {
    currentMap.addMapObj(new Obstacle(name, x, y, height, width, color));
}

void LevelEditor::addObstacle(string name,int x, int y, int height, int width, Color color, Terrain terrain){
    currentMap.addMapObj(new Obstacle(name,x, y, height, width,color, terrain));
}

void LevelEditor::addTerrain(string name,int x, int y, int height, int width, Color color, bool isPassible){
    currentMap.addMapObj(new Terrain(name,x, y,height, width,color,isPassible));
}

void LevelEditor::removeMapObjAt(int x, int y){
    currentMap.removeMapObjAt(x,y);
}

void LevelEditor::addPreferredStart(int x, int y){
    currentMap.addPreferredStartCoord(x,y);
}

void LevelEditor::removePreferredStart(int x, int y){
    currentMap.removePreferredStartCoord(x,y);
}

void LevelEditor::save() {
    MapIO::write(currentMap, "map.txt");
}

void LevelEditor::load(string filepath) {
    Map map(filepath);
    currentMap = map;
    
    cout << currentMap.getHeight() << endl;
    cout << currentMap.getWidth() << endl;
    cout << currentMap.getMapObjectAt(1, 1)->getName() << endl;
}

void LevelEditor::fillTerrain(Terrain *t){
    for(int x=0;x<currentMap.getWidth();x++){
        for(int y=0;y<currentMap.getHeight();y++){
            if(currentMap.getMapObjectAt(x,y)==nullptr){
                t->setXcoord(x);
                t->setYcoord(y);
                currentMap.addMapObj(t);
            }
        }
    }
}







