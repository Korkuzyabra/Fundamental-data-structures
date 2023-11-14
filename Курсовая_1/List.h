#ifndef MAIN_CPP_LIST_H
#define MAIN_CPP_LIST_H
#include "Order.h"
#include <string>

namespace Denis {

template<class T>
class Node{

private:
    Node<T>* _next;
    int _index;
    T _val;

public:
    Node(T val, int index){

        _val = val;
        _index = index;
        _next = nullptr;
    };

    Node(T val, int index, Node* next){

        _val = val;
        _index = index;
        _next = next;
    };

    ~Node() = default;

    Node<T>* GetNext(){

        return _next;
    };

    int GetIndex(){

        return _index;
    };

    T GetData(){

        return _val;
    };

    void SetNext(Node<T>* next){

        _next = next;
    };

    void SetIndex(int index){

        _index = index;
    };

    void SetData(T data){

      _val = data;
    };

    std::string Print(){

      std::string s = "";
        auto* current = this;
        while (current){
            s += current->GetData().Print() + " (" + std::to_string(current->_index) + ") -> ";
            current = current->GetNext();
        }
        s += "nullptr";

        return s;
    };

    std::string PrintInt(){

        std::string s = "";
        auto* current = this;
        while (current){
            s += std::to_string(current->GetData()) + " (" + std::to_string(current->_index) + ") -> ";
            current = current->GetNext();
        }
        s += "nullptr";

        return s;
    };

    std::string PrintS(){

        std::string s = "";
        auto* current = this;
        while (current){
            s += current->GetData() + " (" + std::to_string(current->_index) + ") -> ";
            current = current->GetNext();
        }
        s += "nullptr";

        return s;
    };

};

template<class T>
class List{

private:
    Node<T>* _head;

public:
    explicit List(Node<T>* head){

        _head = head;
        _head->SetNext(nullptr);
    };

    List(T val, int index){

        _head = new Node<T>(val, index);
    }

    ~List(){

        delete(*_head);
        _head = nullptr;
    };

    void Add(int index){

        auto node = new Node<T>(_head->GetData(), index);
        bool done = false;
        auto current = _head;
        Node<T>* prev = nullptr;
        while ((current->GetNext() != nullptr)&&(!done)){
            if (current->GetIndex() <= index){
                if (prev)
                    prev->SetNext(node);
                node->SetNext(current);
                done = true;
            }
            else {
                prev = current;
                current = current->GetNext();
            }
        }
        if  ((current == _head)&&(!done)){
            if (_head->GetIndex() <= index) {
                node->SetNext(_head);
                _head = node;
            }
            else
                _head->SetNext(node);
            done = true;
        }
        if (!done) {
            if (current->GetIndex() <= index) {
                if (prev)
                    prev->SetNext(node);
                node->SetNext(current);
            }
            else {
                current->SetNext(node);
            }
        }
        if ((current == _head)&&(done)){
            _head = node;
        }

    };

    void Delete(int index){

        auto current = _head;
        Node<T>* prev = nullptr;
        bool done = false;
        while ((current != nullptr)&&(!done)){
            if (current->GetIndex() == index){
                done = true;
                if (prev)
                    prev->SetNext(current->GetNext());
                if (current == _head)
                    _head = current->GetNext();
                delete(current);
            }
            else{
                prev = current;
                current = current->GetNext();
            }
        }
    };

    Node<T>* Search(int index){

        auto current = _head;
        while (current){
            if (current->GetIndex() == index)
                return current;
            current = current->GetNext();
        }
    };

    void Search(std::vector<int>* result) {

        auto current = _head;
        while (current) {
            if (current->GetIndex() != -1)
                result->push_back(current->GetIndex());
            current = current->GetNext();
        }
    };

    void ChangeIndex(int from, int to) {

        Node<T>* current = _head;
        while ((current) && (current->GetIndex() != from)) {
            current = current->GetNext();
        }
        if (current)
            current->SetIndex(to);
    };

    Node<T>* GetHead(){

        return _head;
    };

    std::string Print(){

        return _head->Print();
    };

    std::string PrintS(){

        return _head->PrintS();
    };

    std::string PrintInt(){

        return _head->PrintInt();
    };

};

}

#endif //MAIN_CPP_LIST_H
