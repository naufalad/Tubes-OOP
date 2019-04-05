#include <iostream>
#include "Product/SideProduct.h"
#include "World.h"
#include "Cell/AllLand.h"
#include "Cell/AllFacil.h"
#include "Frontend/frontend.h"
#include "LivingBeing/Player.h"
#include "LivingBeing/LivingBeing.h"
#include "LivingBeing/Landsalmon.h"
#include "LivingBeing/Diplodocus.h"
#include "LivingBeing/MeatProducingAnimal.h"
#include "Product/CowMeat.h"

using namespace std;

int main()
{
    Mixer::initCatalog();
    //Peta kaya di spek
    for (int y = 0; y < 11; y++)
    {
        for (int x = 0; x < 11; x++)
        {
            World::GetInstance()->setLand(new Grassland(false), x, y);
        }
    }
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            World::GetInstance()->setLand(new Coop(false), x, y);
        }
    }
    for (int y = 0; y < 6; y++)
    {
        for (int x = 4; x < 8; x++)
        {
            World::GetInstance()->setLand(new Barn(false), x, y);
        }
    }
    World::GetInstance()->addFacil(new Truck(Point(10, 0)), 10, 0);
    World::GetInstance()->addFacil(new Mixer(Point(10, 1)), 10, 1);
    World::GetInstance()->addFacil(new Well(Point(10, 3)), 10, 3);

    World::GetInstance()->addAnimal(new Landsalmon(2, 2), 2, 2);
    World::GetInstance()->addAnimal(new Diplodocus(4, 3), 4, 3);

    Player::GetInstance()->AddInventory(new CowMeat(200));

    bool gamePlay = true;
    string inputUser;
    while (gamePlay)
    {
        Tampilan::GetInstance()->clearLayar();
        World::GetInstance()->renderAll();
        //Get input user
        inputUser = Tampilan::GetInstance()->readStringTable(0, 23, 11, 1, 1, 0);
        for (int i = 0; i < inputUser.size(); i++)
        {
            inputUser[i] = tolower(inputUser[i]);
        }
        if (inputUser == "exit")
        {
            gamePlay = false;
        }
        else if (inputUser == "up")
        {
            if (Player::GetInstance()->Move(LivingBeing::direction::up))
            {
                World::GetInstance()->addMsg("Player go up");
            }
            else
            {
                World::GetInstance()->addMsg("Movement gagal");
            }
        }
        else if (inputUser == "down")
        {
            if (Player::GetInstance()->Move(LivingBeing::direction::down))
            {
                World::GetInstance()->addMsg("Player go down");
            }
            else
            {
                World::GetInstance()->addMsg("Movement gagal");
            }
        }
        else if (inputUser == "left")
        {
            if (Player::GetInstance()->Move(LivingBeing::direction::left))
            {
                World::GetInstance()->addMsg("Player go left");
            }
            else
            {
                World::GetInstance()->addMsg("Movement gagal");
            }
        }
        else if (inputUser == "right")
        {
            if (Player::GetInstance()->Move(LivingBeing::direction::right))
            {
                World::GetInstance()->addMsg("Player go right");
            }
            else
            {
                World::GetInstance()->addMsg("Movement gagal");
            }
        }
        else if (inputUser == "talk")
        {
            vector<Animal*> nearAnimal = World::GetInstance()->getNearestAnimal(
                Player::GetInstance()->GetX(),
                Player::GetInstance()->GetY()
            );
            if(nearAnimal.size() != 0)
            { 
                for(Animal* a : nearAnimal)
                {
                    string berbicara = "Kamu bicara dengan ";
                    berbicara += a->getRenderChar();
                    World::GetInstance()->addMsg(berbicara);
                    World::GetInstance()->addMsg("  Dia berkata : "+a->GetAnimalSound());
                }
            }else{
                World::GetInstance()->addMsg("Jangan ngomong sendiri");
            }
        }
        else if (inputUser == "interact")
        {
            int playerX = Player::GetInstance()->GetX();
            int playerY = Player::GetInstance()->GetY();
            vector<Animal*> nearAnimal = World::GetInstance()->getNearestAnimal(playerX, playerY);
            vector<Facility*> nearFacility = World::GetInstance()->getNearestFacility(playerX, playerY);
            Animal *atasA = nullptr, *bawahA = nullptr, *kiriA = nullptr, *kananA = nullptr;
            Facility *atasF = nullptr, *bawahF = nullptr, *kiriF = nullptr, *kananF = nullptr;
            World::GetInstance()->addMsg("Animal dekat kamu:");
            for(Animal* a : nearAnimal)
            {
                string temp = "  ";
                temp += a->getRenderChar();
                if(a->GetX()==playerX && a->GetY()==playerY-1)
                {
                    temp += " (atas)";
                    atasA = a;
                }else if(a->GetX()==playerX && a->GetY()==playerY+1)
                {
                    temp += " (bawah)";
                    bawahA = a;
                }else if(a->GetX()==playerX-1 && a->GetY()==playerY)
                {
                    temp += " (kiri)";
                    kiriA = a;
                }else if(a->GetX()==playerX+1 && a->GetY()==playerY)
                {
                    temp += " (kanan)";
                    kananA = a;
                }
                World::GetInstance()->addMsg(temp);
            }
            World::GetInstance()->addMsg("Facility dekat kamu:");
            for(Facility* f : nearFacility)
            {
                string temp = "  ";
                temp += f->getRenderChar();
                int f_x = f->getPoint().getAbsis();
                int f_y = f->getPoint().getOrdinat();
                if(f_x==playerX && f_y==playerY-1)
                {
                    temp += " (atas)";
                    atasF = f;
                }else if(f_x==playerX && f_y==playerY+1)
                {
                    temp += " (bawah)";
                    bawahF = f;
                }else if(f_x==playerX-1 && f_y==playerY)
                {
                    temp += " (kiri)";
                    kiriF = f;
                }else if(f_x==playerX+1 && f_y==playerY)
                {
                    temp += " (kanan)";
                    kananF = f;
                }
                World::GetInstance()->addMsg(temp);
            }
            World::GetInstance()->addMsg("Ketik arah untuk berinteraksi");
            World::GetInstance()->renderAll();
            bool valid = false;
            while(!valid){
                inputUser = Tampilan::GetInstance()->readStringTable(0, 23, 11, 1, 1, 0);
                for (int i = 0; i < inputUser.size(); i++)
                {
                    inputUser[i] = tolower(inputUser[i]);
                }
                if(inputUser == "atas" || inputUser == "bawah" || inputUser == "kiri" || inputUser == "kanan")
                {
                    valid = true;
                }else{
                    World::GetInstance()->addMsg("Input salah, masukan arah interaksi");
                }
                World::GetInstance()->renderAll();
            }
            if(inputUser == "atas")
            {
                //Interact dengan atas
                if(atasA != nullptr)
                {
                    atasA->Interact();
                }else if(atasF != nullptr)
                {
                    atasF->interact();
                }else{
                    World::GetInstance()->addMsg("Tidak ada apapun di atasmu");
                }
            }else if(inputUser == "bawah") {
                //Interact dengan bawah
                if(bawahA != nullptr)
                {
                    bawahA->Interact();         
                }else if(bawahF != nullptr)
                {
                    bawahF->interact();
                }else{
                    World::GetInstance()->addMsg("Tidak ada apapun di bawahmu");
                }

            }else if(inputUser == "kiri") {
                //Interact dengan kiri
                if(kiriA != nullptr)
                {
                    kiriA->Interact();    
                }else if(kiriF != nullptr)
                {
                    kiriF->interact();
                }else{
                    World::GetInstance()->addMsg("Tidak ada apapun di kirimu");
                }

            }else{
                //Interact dengan kanan
                if(kananA != nullptr)
                {
                    kananA->Interact();
                }else if(kananF != nullptr)
                {
                    kananF->interact();
                }else{
                    World::GetInstance()->addMsg("Tidak ada apapun di kananmu");
                }
            }
        }
        else if (inputUser == "kill")
        {
        }
        else if (inputUser == "grow")
        {
            int x = Player::GetInstance()->GetX();
            int y = Player::GetInstance()->GetY();
            if(World::GetInstance()->getLand(x, y)->hasGrass())
            {
                World::GetInstance()->addMsg("Sudah ada rumput");
            }else{
                World::GetInstance()->getLand(x, y)->setGrass(true);
                World::GetInstance()->addMsg("Kamu menanam rumput");
            }
        }
        World::GetInstance()->updateAll();
    }
    endwin();
}