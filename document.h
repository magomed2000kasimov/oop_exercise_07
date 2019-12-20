//
// Created by magom on 08.12.2019.
//

#ifndef OOP7_DOCUMENT_H
#define OOP7_DOCUMENT_H

#include <fstream>
#include <cstdint>
#include <memory>
#include <string>
#include <algorithm>
#include "figure.h"
#include <vector>
#include "factory.h"

struct document {
public:
    void Print() const {
        if (buffer_.empty()) {
            std::cout << "Buffer is empty\n";
        }
        for (auto elem : buffer_) {
            elem->print(std::cout);
        }
    };

    document(std::string& newName): name_(newName), factory_(), buffer_(0) {};

    void Insert(std::shared_ptr<figure>& ptr) {
        buffer_.push_back(ptr);
    };

    void Rename(const std::string& newName) {
        name_ = newName;
    };

    void Save (const std::string& filename) const {
        std::ofstream fout;
        fout.open(filename);
        if (!fout.is_open()) {
            throw std::runtime_error("File is not opened\n");
        }
        fout << buffer_.size() << '\n';
        for (auto elem : buffer_) {
            elem->printFile(fout);
        }
    }

    void Load(const std::string& filename) {
        std::ifstream fin;
        fin.open(filename);
        if (!fin.is_open()) {
            throw std::runtime_error("File is not opened\n");
        }
        size_t size;
        fin >> size;
        buffer_.clear();
        for (int i = 0; i < size; ++i) {
            buffer_.push_back(factory_.FigureCreateFile(fin));
        }
        name_ = filename;
    }

    std::shared_ptr<figure> GetFigure(uint32_t index) {
        return buffer_[index];
    }

    void Erase(uint32_t index) {
        if ( index >= buffer_.size()) {
            throw std::logic_error("Out of bounds\n");
        }
        buffer_[index] = nullptr;
        for (; index < buffer_.size() - 1; ++index) {
            buffer_[index] = buffer_[index + 1];
        }
        buffer_.pop_back();
    }

    std::string GetName() {
        return this->name_;
    }



private:
    friend class InsertCommand;
    friend class DeleteCommand;
    factory factory_;
    std::string name_;
    std::vector<std::shared_ptr<figure>> buffer_;

    void RemoveLast() {
        if (buffer_.empty()) {
            throw std::logic_error("Document is empty");
        }
        buffer_.pop_back();
    }

    void InsertIndex(std::shared_ptr<figure>& newFigure, uint32_t index) {
        /*buffer_.push_back(newFigure);
        for (int i = buffer_.size() - 1; i != index ; --i){
            std::shared_ptr<figure> tmp = buffer_[i];
            buffer_[i] = buffer_[i - 1];
            buffer_ [i - 1] = tmp;
        }*/
        buffer_.insert(buffer_.begin() + index, newFigure);
    }
};


#endif //OOP7_DOCUMENT_H
