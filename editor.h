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

    void PrintDocument() {
        if (doc_ == nullptr) {
            std::cout << "No document!\n";
            return;
        }
        doc_->Print();
    }

    void CreateDocument(std::string& newName) {
        doc_ = std::make_shared<document>(newName);
    }

    bool DocumentExist() {
        return doc_ != nullptr;
    }

    editor() : doc_(nullptr), history_()
    {
    }

    void InsertInDocument(std::shared_ptr<figure>& newFigure) {
        if (doc_ == nullptr) {
            std::cout << "No document!\n";
            return;
        }
        std::shared_ptr<Acommand> command = std::shared_ptr<Acommand>(new InsertCommand());
        doc_->Insert(newFigure);
        command -> SetDocument(doc_);
        history_.push(command);
    }

    void DeleteInDocument(uint32_t index) {
        if (doc_ == nullptr) {
            std::cout << "No document!\n";
            return;
        }
        std::shared_ptr<figure> tmp = doc_->GetFigure(index);
        std::shared_ptr<Acommand> command = std::shared_ptr<Acommand>(new DeleteCommand(tmp,index));
        doc_->Erase(index);
        command -> SetDocument(doc_);
        history_.push(command);
    }

    void SaveDocument() {
        if (doc_ == nullptr) {
            std::cout << "Create document!\nNot ";
            return;
        }
        std::string saveName = doc_->GetName();
        doc_ ->Save(saveName);
    }

    void LoadDocument(std::string& name) {
        doc_ = std::make_shared<document>(name);
        doc_->Load(name);
        while (!history_.empty()){
            history_.pop();
        }
    }

    void Undo(){
        if (history_.empty()) {
            throw std::logic_error("History is empty\n");
        }
        std::shared_ptr<Acommand> lastCommand = history_.top();
        lastCommand->UnExecute();
        history_.pop();
    }

};

#endif //OOP7_EDITOR_H
