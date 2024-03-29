//
// Created by magom on 09.12.2019.
//

#ifndef OOP7_COMMAND_H
#define OOP7_COMMAND_H
#include "document.h"

struct Acommand {
    virtual ~Acommand() = default;
    virtual void UnExecute() = 0;


protected:
    std::shared_ptr<document> doc_;
};

struct InsertCommand : public Acommand {
public:
    void UnExecute() override;

    InsertCommand(std::shared_ptr<document>& doc);


};

struct DeleteCommand : public Acommand {
public:
    DeleteCommand(std::shared_ptr<figure>& newFigure, uint32_t newIndex,std::shared_ptr<document>& doc);
    void UnExecute() override;

private:
    std::shared_ptr<figure> figure_;
    uint32_t index_;
};
#endif //OOP7_COMMAND_H
