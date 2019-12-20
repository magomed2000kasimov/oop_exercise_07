//
// Created by magom on 09.12.2019.
//

#ifndef OOP7_COMMAND_H
#define OOP7_COMMAND_H
#include "document.h"

struct Acommand {
    virtual ~Acommand() = default;
    virtual void UnExecute() = 0;
    void SetDocument(std::shared_ptr<document>& doc) {
        doc_ = doc;
    }

protected:
    std::shared_ptr<document> doc_;
};

struct InsertCommand : public Acommand {
public:
    void UnExecute() override {
        doc_->RemoveLast();
    }
};

struct DeleteCommand : public Acommand {
public:
    DeleteCommand(std::shared_ptr<figure>& newFigure, uint32_t newIndex) {
        figure_ = newFigure;
        index_ = newIndex;
    }
    void UnExecute() override {
        doc_->InsertIndex(figure_,index_);
    }

private:
    std::shared_ptr<figure> figure_;
    uint32_t index_;
};
#endif //OOP7_COMMAND_H
