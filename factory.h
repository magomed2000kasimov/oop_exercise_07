//
// Created by magom on 08.12.2019.
//

#ifndef OOP7_FACTORY_H
#define OOP7_FACTORY_H

#include <memory>
#include <iostream>
#include <fstream>
#include "hexagon.h"
#include "octagon.h"
#include "pentagon.h"
#include <string>

struct factory {
    std::shared_ptr<figure> FigureCreate(std::istream& is);

    std::shared_ptr<figure> FigureCreateFile(std::ifstream& is);

};


#endif //OOP7_FACTORY_H
