//
// Created by magom on 08.12.2019.
//

#ifndef OOP7_FIGURE_H
#define OOP7_FIGURE_H
#include <iostream>
#include "point.h"
#include <fstream>

struct figure {
    virtual point center() const = 0;
    virtual void print(std::ostream&) const = 0 ;
    virtual void printFile(std::ofstream&) const = 0 ;
    virtual double square() const = 0;
    virtual ~figure() = default;
};


#endif //OOP7_FIGURE_H
