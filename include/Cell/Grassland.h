/**
 * \class Grassland
 * \brief Grassland adalah kelas untuk mengembangbiakan hewan ternak
 *
 * \author M. Khairul Makirin
 * 
 */

#ifndef _GRASSLAND_H
#define _GRASSLAND_H

#include "Land.h"

class Grassland : public Land{
    public:
        //CTOR
        Grassland(bool hasGrass);
        //METHOD
        /** 
         * \brief Meng-overwrite fungsi generik isGrassLand
         * sehingga jika kelas GrassLand memanggil isGrassLand
         * akan mereturn true, tapi kalau kelas lain yang manggil
         * akan mereturn false
         */
        bool isGrassland() const;

};



#endif