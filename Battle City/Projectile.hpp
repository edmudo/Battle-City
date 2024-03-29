//
//  Projectile.hpp
//  Battle City
//
//  Created by Yixiong Zhang on 4/3/17.
//  Copyright © 2017 Yixiong Zhang. All rights reserved.
//

#ifndef Projectile_hpp
#define Projectile_hpp
#include "Entity.hpp"
#include "Tank.hpp"



class Projectile : public Entity{
  
public:
    Projectile(double damage, double x, double y, double direction, Color color, bool canPassAllTerrain = true);
    ~Projectile();
    
    /**
     * @See Entity#move(Sign)
     */
    
    virtual void move(ESign sign) override;
    
    /**
     * Requires: nothing
     * Modifies: damage
     * Effects: getters and setters
     */

    void setDamage(double d);
    double getDamage() const;
    
    virtual void draw() override;
    
    static const int WIDTH = 10;
    static const int HEIGHT = 10;
    
private:
    double damage;
    
  
};

    
    























#endif /* Projectile_hpp */
