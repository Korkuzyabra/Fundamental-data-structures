#ifndef COURSE_RBTREE_H
#define COURSE_RBTREE_H
#include "List.h"
#include <iostream>
#include <string>

namespace Denis{

template<class T>
class TNode{

private:
    TNode<T>* _parent;
    TNode<T>* _left;
    TNode<T>* _right;
    List<T>* _list;
    bool _color;//0 - red, 1 - black

public:
    TNode(T val, int index) {

        _color = false;
        _parent = nullptr;
        _left = nullptr;
        _right = nullptr;
        _list = new List<T>(val, index);
    };

    TNode(T val, int index, TNode<T>* parent, TNode<T>* left, TNode<T>* right){

        _color = false;
        _parent = parent;
        _left = left;
        _right = right;
        _list = new List<T>(val, index);
    };

    ~TNode(){

        if (_left)
            delete(&_left);
        if (_right)
            delete(&_right);
        delete(&_list);
        _list = nullptr;
        _right = nullptr;
        _left = nullptr;
    };

    std::string PrintOnSide(int height, TNode<Denis::Date>* Nil){

        std::string str = "";
        if (this != Nil){
            str += this->_right->PrintOnSide(height + 4, Nil);
            for (int i = 0; i < height; ++i) str += " ";
            str += this->Print();
            str += "\n";
            str += this->_left->PrintOnSide(height + 4, Nil);
        }

        return str;
    };

    std::string PrintOnSideS(int height, TNode<std::string>* Nil){

        std::string str = "";
        if (this != Nil){
            str += this->_right->PrintOnSideS(height + 4, Nil);
            for (int i = 0; i < height; ++i) str += " ";
            str += this->PrintS();
            str += "\n";
            str += this->_left->PrintOnSideS(height + 4, Nil);
        }

        return str;
    };

    std::string PrintOnSideInt(int height, TNode<int>* Nil){

        std::string str = "";
        if (this != Nil){
            str += this->_right->PrintOnSideInt(height + 4, Nil);
            for (int i = 0; i < height; ++i) str += " ";
            str += this->PrintInt();
            str += "\n";
            str += this->_left->PrintOnSideInt(height + 4, Nil);
        }

        return str;
    };

    void InvertColor(){

        _color = !_color;
    };

    bool IsNil(){

        return (_list->GetHead()->GetIndex() == -1);
    };

    TNode<T>* GetBrother(){

        if (_parent) {
            if (this == _parent->_left)
                return _parent->_right;
            else
                return _parent->_left;
        }
        else
            return nullptr;
    };

    TNode<T>* GetLeft(){

        return _left;
    };

    TNode<T>* GetRight(){

        return _right;
    };

    TNode<T>* GetParent(){

        return _parent;
    };

    bool GetColor(){

        return _color;
    };

    void SetColor(bool color){

        _color = color;
    };

    void SetLeft(TNode<T>* left){

        _left = left;
    };

    void SetRight(TNode<T>* right){

        _right = right;
    };

    void SetParent(TNode<T>* parent){

        _parent = parent;
    };

    std::string Print(){

        std::string s;
        if (_color)
            s = "(B)";
        else
            s = "(R)";
        return (s + _list->Print());
    };

    std::string PrintInt(){

        std::string s;
        if (_color)
            s = "(B)";
        else
            s = "(R)";
        return (s + _list->PrintInt());
    };

    std::string PrintS(){

        std::string s;
        if (_color)
            s = "(B)";
        else
            s = "(R)";
        return (s + _list->PrintS());
    };

    List<T>* GetList(){

        return _list;
    };

    TNode<T>* TreeMin(TNode<T>* nil){

        auto current = this;
        while(current->GetLeft() != nil)
            current = current->GetLeft();
        return current;
    };

    TNode<T>* TreeMax(TNode<T>* nil){

        auto current = this;
        while(current->GetRight() != nil)
            current = current->GetRight();
        return current;
    };

};

template<class T>
class RBTree{

private:
    TNode<T>* _nil;
    TNode<T>* _root;

    void RightRotate(TNode<T>* node) {

        if (node->GetLeft() != _nil) {
            TNode<T>*y = node->GetLeft();
            node->SetLeft(y->GetRight());
            if (y->GetRight() != _nil)
                y->GetRight()->SetParent(node);
            y->SetParent(node->GetParent());
            if (node->GetParent() == _nil)
                _root = y;
            else if (node == node->GetParent()->GetRight())
                node->GetParent()->SetRight(y);
            else
                node->GetParent()->SetLeft(y);
            y->SetRight(node);
            node->SetParent(y);
        }
    };

    void LeftRotate(TNode<T>* node) {

        if (node->GetRight() != _nil) {
            TNode<T>*y = node->GetRight();
            node->SetRight(y->GetLeft());
            if (y->GetLeft() != _nil)
                y->GetLeft()->SetParent(node);
            y->SetParent(node->GetParent());
            if (node->GetParent() == _nil)
                _root = y;
            else if (node == node->GetParent()->GetLeft())
                node->GetParent()->SetLeft(y);
            else
                node->GetParent()->SetRight(y);
            y->SetLeft(node);
            node->SetParent(y);
        }
    };

    void InsertFixUp(TNode<T>*& node){
        while (!node->GetParent()->GetColor()) {
            if (node->GetParent() == node->GetParent()->GetParent()->GetLeft()) {
                TNode<T>*y = node->GetParent()->GetParent()->GetRight();
                if (!y->GetColor()){
                    node->GetParent()->SetColor(true);
                    y->SetColor(true);
                    node->GetParent()->GetParent()->SetColor(false);
                    node = node->GetParent()->GetParent();
                }
                else {
                    if (node == node->GetParent()->GetRight()) {
                        node = node->GetParent();
                        LeftRotate(node);
                    }
                    node->GetParent()->SetColor(true);
                    node->GetParent()->GetParent()->SetColor(false);
                    RightRotate(node->GetParent()->GetParent());
                }
            }
            else {
                TNode<T>*y = node->GetParent()->GetParent()->GetLeft();
                if (!y->GetColor()){
                    node->GetParent()->SetColor(true);
                    y->SetColor(true);
                    node->GetParent()->GetParent()->SetColor(false);
                    node = node->GetParent()->GetParent();
                }
                else {
                    if (node == node->GetParent()->GetLeft()) {
                        node = node->GetParent();
                        RightRotate(node);
                    }
                    node->GetParent()->SetColor(true);
                    node->GetParent()->GetParent()->SetColor(false);
                    LeftRotate(node->GetParent()->GetParent());
                }
            }
        }
        _root->SetColor(true);
    };

    void DeleteFixUp(TNode<T>* node){

        while (node != _root && node->GetColor()) {
            if (node == node->GetParent()->GetLeft()) {
                if (!node->GetBrother()->GetColor()) {
                    node->GetBrother()->InvertColor();
                    node->GetParent()->InvertColor();
                    LeftRotate(node->GetParent());
                }
                if (node->GetBrother()->GetLeft()->GetColor() &&
                    node->GetBrother()->GetRight()->GetColor()) {
                    node->GetBrother()->InvertColor();
                    node = node->GetParent();
                } else if (node->GetBrother()->GetRight()->GetColor()) {
                    node->GetBrother()->GetLeft()->InvertColor();
                    node->GetBrother()->InvertColor();
                    RightRotate(node->GetBrother());
                }
                else {
                    node->GetBrother()->SetColor(node->GetParent()->GetColor());
                    if (node->GetBrother()->GetLeft()->GetColor() &&
                        !node->GetParent()->GetParent()->GetColor())
                        node->GetParent()->InvertColor();
                    node->GetBrother()->GetRight()->InvertColor();
                    LeftRotate(node->GetParent());
                    node = _root;
                }
            }
            else {
                if (!node->GetBrother()->GetColor()) {
                    node->GetBrother()->InvertColor();
                    node->GetParent()->InvertColor();
                    RightRotate(node->GetParent());
                }
                if (node->GetBrother()->GetRight()->GetColor() &&
                    node->GetBrother()->GetLeft()->GetColor()) {
                    node->GetBrother()->InvertColor();
                    node = node->GetParent();
                } else if (node->GetBrother()->GetLeft()->GetColor()) {
                    node->GetBrother()->GetRight()->InvertColor();
                    node->GetBrother()->InvertColor();
                    LeftRotate(node->GetBrother());
                }
                else {
                    node->GetBrother()->SetColor(node->GetParent()->GetColor());
                    if (node->GetBrother()->GetRight()->GetColor() &&
                        !node->GetParent()->GetParent()->GetColor())
                        node->GetParent()->InvertColor();
                    node->GetBrother()->GetLeft()->InvertColor();
                    RightRotate(node->GetParent());
                    node = _root;
                }
            }
        }
        node->SetColor(true);
    };

    void Transplant(TNode<T>* u, TNode<T>* v){

        if (u->GetParent() == _nil)
            _root = v;
        else {
            if (u == u->GetParent()->GetLeft())
                u->GetParent()->SetLeft(v);
            else
                u->GetParent()->SetRight(v);
        }
        v->SetParent(u->GetParent());
    };

public:
    RBTree(){
        T val = T();
        _nil = new TNode<T>(val, -1);
        _nil->SetColor(true);
        _root = _nil;
    };

    TNode<T>* Find(T val){

        auto current = _root;
        if (current == _nil){
            std::cout << "Tree is empty.\n";
            return nullptr;
        }
        while ((current->GetList()->GetHead()->GetData() != val)&&(current != _nil)){
            if (val > current->GetList()->GetHead()->GetData())
                current = current->GetRight();
            if (val < current->GetList()->GetHead()->GetData())
                current = current->GetLeft();
        }
        if (current)
            return current;
        else
            return nullptr;
    };

    void FindIndex(T val, std::vector<int>* result) {

        TNode<T>* current = _root;
        if (current == _nil) {
            std::cout << "Tree is empty.\n";
            return;
        }
        while ((current->GetList()->GetHead()->GetData() != val) && (current != _nil)) {
            if (val > current->GetList()->GetHead()->GetData())
                current = current->GetRight();
            if (val < current->GetList()->GetHead()->GetData())
                current = current->GetLeft();
        }
        if (current)
            current->GetList()->Search(result);
        else
            return;

        return;
    };

    void Insert(TNode<T>* node){

        auto x = _root;
        auto y = _nil;
        while ((x != _nil) && ((x->GetList()->GetHead()->GetData()) != (node->GetList()->GetHead()->GetData()))){
            y = x;
            if (node->GetList()->GetHead()->GetData() < x->GetList()->GetHead()->GetData())
                x = x->GetLeft();
            else
                x = x->GetRight();
        }
        if (node->GetList()->GetHead()->GetData() == x->GetList()->GetHead()->GetData())
            x->GetList()->Add(node->GetList()->GetHead()->GetIndex());
        else {
            node->SetParent(y);
            if (y == _nil)
                _root = node;
            else {
                if (node->GetList()->GetHead()->GetData() < y->GetList()->GetHead()->GetData())
                    y->SetLeft(node);
                else
                    y->SetRight(node);
            }
            node->SetLeft(_nil);
            node->SetRight(_nil);
            InsertFixUp(node);
        }
    };

    void Insert(T val, int index){

        auto node = new TNode<T>(val, index);
        Insert(node);
    };

    void Delete(TNode<T>* node, int index){

        if (node == nullptr) return;
        if (node->GetList()->GetHead()->GetNext())
            node->GetList()->Delete(index);
        else {
            TNode<T>*y = node;
            TNode<T>*x;
            bool yOriginColor = y->GetColor();
            if (node->GetLeft() == _nil) {
                x = node->GetRight();
                Transplant(node, node->GetRight());
            }
            else
            if (node->GetRight() == _nil) {
                x = node->GetLeft();
                Transplant(node, node->GetLeft());
            }
            else {
                y = node->GetRight()->TreeMin(node->GetRight());
                yOriginColor = y->GetColor();
                x = y->GetRight();
                if (y->GetParent() == node)
                    x->SetParent(node);
                else {
                    Transplant(y, y->GetRight());
                    y->SetRight(node->GetRight());
                    y->GetRight()->SetParent(y);
                }
                Transplant(node, y);
                y->SetLeft(node->GetLeft());
                y->GetLeft()->SetParent(y);
                y->SetColor(node->GetColor());
            }
            if (yOriginColor)
                DeleteFixUp(x);
        }
    };

    void Delete(T val, int index){

        auto node = Find(val);
        Delete(node, index);
    };

    std::string PrintOnSide(int height){

        return _root->PrintOnSide(height, _nil);
    };

    std::string PrintOnSideS(int height){

        return _root->PrintOnSideS(height, _nil);
    }

    std::string PrintOnSideInt(int height){

        return _root->PrintOnSideInt(height, _nil);
    }

    void ChangeIndex(T val, int from, int to) {

        TNode<T>* current = _root;
        if (current == _nil) {
            std::cout << "Tree is empty.\n";
            return;
        }
        while ((current->GetList()->GetHead()->GetData() != val) && (current != _nil)) {
            if (val > current->GetList()->GetHead()->GetData())
                current = current->GetRight();
            if (val < current->GetList()->GetHead()->GetData())
                current = current->GetLeft();
        }
        if (current) {
            current->GetList()->ChangeIndex(from, to);
        }
        else
            return;
    }

};

}

#endif //COURSE_RBTREE_H
