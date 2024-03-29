//
//  Obstacle.cpp
//  CS120
//
//  Created by Shaw on 4/13/17.
//  Copyright © 2017 Shaw. All rights reserved.
//

#include "Obstacle.hpp"
#include "Constants.hpp"

#include <iostream>

Obstacle::Obstacle(string name, int x, int y, int width, int height, Color color) : MapObject(name, x, y, width, height, color, false), underlyingTerrain(Terrain("nothing", x, y, width, height, color, true)) {}

Obstacle::Obstacle(string name, int x, int y, int width, int height, Color color, Terrain a) : MapObject(name, x, y, width, height, color, false), underlyingTerrain(a) {}

Terrain Obstacle::getunderlyingTerrain(){
    return underlyingTerrain;
}

void Obstacle::setUnderlyingTerrain(Terrain a){
    underlyingTerrain = a;
}

void Obstacle::draw() {
    MapObject::draw();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(topLeft.getX(), topLeft.getY());
    glVertex2d(topLeft.getX() + width, topLeft.getY());
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2d(topLeft.getX() + width, topLeft.getY());
    glVertex2d(topLeft.getX() + width, topLeft.getY() + height);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2d(topLeft.getX(), topLeft.getY());
    glVertex2d(topLeft.getX(), topLeft.getY() + height);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2d(topLeft.getX(), topLeft.getY() + height);
    glVertex2d(topLeft.getX() + width, topLeft.getY() + height);
    glEnd();
}

DestructibleObstacle::DestructibleObstacle(string name, int x, int y, int width, int height, Color color, Terrain a, double h) : Obstacle(name, x, y, width, height, color, a), health(h) {}

void DestructibleObstacle::setRemainingHealth(double health) {
    this->health = health;
}

double DestructibleObstacle::getRemainingHealth() const{
    return health;
}
