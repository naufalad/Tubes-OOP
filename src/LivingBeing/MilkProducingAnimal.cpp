#include "LivingBeing/MilkProducingAnimal.h"
#include "World.h"
#include <ctime>

MilkProducingAnimal::MilkProducingAnimal(int _x, int _y, string _animalSound, char _repChar, int maxHunger) : Animal(_x, _y, _animalSound, _repChar, maxHunger){
}

bool MilkProducingAnimal::MoveRandom()
{
    bool moveValid = false;
    int i = 0;
    direction randDir;
    while (i < 4 && !moveValid)
    {
        srand(World::GetInstance()->getTick());
        randDir = static_cast<direction>(rand() % 5 + 1);
        if (randDir == up && y > 0 && World::GetInstance()->getLand(x, y - 1)->isGrassland())
        {
            moveValid = true;
        }
        else if (randDir == down && y < World::GetInstance()->getSize().getOrdinat() && World::GetInstance()->getLand(x, y + 1)->isGrassland())
        {
            moveValid = true;
        }
        else if (randDir == left && x>0 && World::GetInstance()->getLand(x - 1, y)->isGrassland())
        {
            moveValid = true;
        }
        else if (randDir == right && x < World::GetInstance()->getSize().getAbsis() && World::GetInstance()->getLand(x + 1, y)->isGrassland())
        {
            moveValid = true;
        }
        i++;
    }
    if(moveValid)
    {
        this->Move(randDir);
    }
    // World::GetInstance()->addMsg("MilkAnimal Bergerak");
    return moveValid;
}