#ifndef _GRASSLAND_H
#define _GRASSLAND_H

#include "Land.h"
#include "Animal.h"

class Grassland : public Land{
    private:

    public:
        //ctor berparameter grass = false
        Grassland(Point);

        bool isGrassland() const{return true;}

};



#endif