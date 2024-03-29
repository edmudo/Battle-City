//
//  MapObject.hpp
//  CS120
//
//  Created by Shaw on 4/13/17.
//  Copyright © 2017 Shaw. All rights reserved.
//

#ifndef MapObject_hpp
#define MapObject_hpp

#include "Color.hpp"
#include "Point2D.hpp"
#include "graphics.hpp"

#include <string>
using namespace std;

class MapObject{
    
public:
    MapObject(string name, int x, int y, int width, int height, Color color, bool isPassable);
    
    /**
     * Requires: r, g, b must be between 0 and 255
     * Modifies: color
     * Effects: getters and setters
     */
    
    virtual string getName() const;
    virtual int getX() const;
    virtual int getGridX() const;
    virtual void setX(int x);
    virtual int getY() const;
    virtual int getGridY() const;
    virtual void setY(int y);
    virtual int getWidth() const;
    virtual int getHeight() const;
    bool getIsPassable() const;
    void setIsPassable(bool a);
    virtual Color getColor() const;
    virtual void setColor(Color &color);
    virtual void setColor(int r, int g, int b);
    
    virtual void draw();
    
    static const int DEFAULT_OBJ_WIDTH = 10, DEFAULT_OBJ_HEIGHT = 10;
    
protected:
    
    string name;
    Point2D topLeft;
    int width, height;
    bool isPassable;
    Color color;
    
};

#endif /* MapObject_hpp */
