#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <cmath>

#include "ELf.h"
#include "Orc.h"
#include "Farmer.h"
#include "Soldier.h"
#include "Shaman.h"

int main()
{
    NPC *elf = new Elf("Legolas");
    NPC *orc = new Orc("Azog");

    NPC *farmerElf = new Farmer(elf);
    NPC *soldierShamanOrc = new Soldier(new Shaman(orc));

    // elf->render();              // Print alleen de Elf
    // farmerElf->render();        // Print de Elf met Farmer rol
    soldierShamanOrc->render(); // Print de Orc met Soldier en Shaman rollen

    //deze while loop staat er in omdat anders de console direct afsluit.
    bool isRunning = true;
    while (isRunning)
    {

    }
    
    // Vergeet niet om gealloceerd geheugen vrij te geven
    delete elf;
    delete orc;
    delete farmerElf;
    delete soldierShamanOrc;

    return 0;
}