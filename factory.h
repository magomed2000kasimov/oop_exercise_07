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
    std::shared_ptr<figure> FigureCreate(std::istream& is)  {
        std::string name;
        is >> name;
        if ( name == "pentagon" ) {
            return std::shared_ptr<figure> ( new pentagon(is));
        } else if ( name == "hexagon") {
            return std::shared_ptr<figure> ( new hexagon(is));
        } else if ( name == "octagon") {
            return std::shared_ptr<figure> ( new octagon(is));
        } else {
            throw std::logic_error("There is no such figure\n");
        }
    };

    std::shared_ptr<figure> FigureCreateFile(std::ifstream& is)  {
        std::string name;
        is >> name;
        if ( name == "pentagon" ) {
            return std::shared_ptr<figure> ( new pentagon(is));
        } else if ( name == "hexagon") {
            return std::shared_ptr<figure> ( new hexagon(is));
        } else if ( name == "octagon") {
            return std::shared_ptr<figure> ( new octagon(is));
        } else {
            throw std::logic_error("There is no such figure\n");
        }
    };

};


#endif //OOP7_FACTORY_H
