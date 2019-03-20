/**
 * \class BeefRolade
 * \brief BeefRolade adalah salah satu SideProduct dalam game
 *
 * BeefRolade adalah SideProduct yang dihasilkan dari CowMeat dan ChickenEgg
 *  
 * \note Ingredients : CowMeat & ChickenEgg
 * 
 * \author Naufal Aditya D.
 * 
 */
#include <iostream>
#include "SideProduct.h"
using namespace std;

#ifndef BEEFROLADE_H
#define BEEFROLADE_H

class BeefRolade: public SideProduct{
    public:
        /**
         * \brief Constructor BeefRolade dengan parameter harga BeefRolade
         * \param _price Harga BeefRolade
         */
        BeefRolade(int _price);
        /**
         * \brief Copy Constructor SideProduct dengan parameter BeefRolade lain
         * \param BeefRolade& BeefRolade tujuan copy
         */
        BeefRolade(const BeefRolade&);
        /**
         * \brief Operator = untuk meng-assign BeefRolade dengan BeefRolade yang lain
         * \param _price Harga BeefRolade
         */
        BeefRolade& operator= (const BeefRolade&);
};
#endif