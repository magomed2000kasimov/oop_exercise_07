//
// Created by magom on 09.12.2019.
//

#ifndef OOP7_EDITOR_H
#define OOP7_EDITOR_H

#include "figure.h"
#include "document.h"
#include <stack>
#include "command.h"

struct editor {
private:
    std::shared_ptr<document> doc_;
    std::stack<std::shared_ptr<Acommand>> history_;
public:
    ~editor() = default;

    void PrintDocument();

    void CreateDocument(std::string& newName);

    bool DocumentExist();

    editor() : doc_(nullptr), history_()
    {
    }

    void InsertInDocument(std::shared_ptr<figure>& newFigure);

    void DeleteInDocument(uint32_t index);

    void SaveDocument();

    void LoadDocument(std::string& name);

    void Undo();

};

#endif //OOP7_EDITOR_H
