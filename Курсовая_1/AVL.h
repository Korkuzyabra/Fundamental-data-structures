#ifndef INC_1_2_AVL_H
#define INC_1_2_AVL_H

#include <iostream>
#include <stack>
#include "LisMt.h"
#include "Clients_comparasion.h"
#include "list"
template<typename T>
class TNode {
public:
    int height;
    List<T>* list;
    TNode<T>* left;
    TNode<T>* right;
    std::list<int> index;
    int balance;


    TNode() : list(nullptr), left(nullptr), right(nullptr), height(1), balance(0),index() {}

    TNode(T num,int index) : left(nullptr), right(nullptr), height(1), balance(0),index() {
        list = new List<T>(num,index);
    }

    ~TNode() {
        delete list;
    }
};
template<typename T>
class BST {
private:
    TNode<T>* root;
    bool h;

public:
    BST() : root(nullptr), h(true) {}

    ~BST() {
        deleteTree(root);
    }

    void insert(T num,int index) {
        insertInTree(root, num, h,index);
    }

    void remove(T num,int index) {
        deleteFromTree(root, num, h,index);
    }

    std::string printSidewaysFIO() {
        std::string s = "";
        s += printOnSideFIO(0, root) + "\n";
        return s;
    }
    std::string printSidewaysAdress() {
        std::string s = "";
        s += printOnSideAdress(0, root) + "\n";
        return s;
    }
    std::string printSidewaysDB() {
        std::string s = "";
        s += printOnSideDB(0, root) + "\n";
        return s;
    }

    bool isEqual(BST& other) {
        return areEqual(root, other.root);
    }

    public:

    int nodeNumber(List<T>* node) {
        int number = 1;
        if (node->next == nullptr)
            return number;
        List<T>* current = node->next;
        while (current != nullptr) {
            number++;
            current = current->next;
        }
        return number;
    }
//
//    void deleteFromList(TNode<T>* node,int index) {
//        List<T>* listnode = node->list;
//        List<T>* temp = listnode->next;
//        listnode->next = temp->next;
//        if (temp->next != nullptr || temp->next->data.currentIndex != index) {
//            temp->next->prev = listnode;
//        }
//        delete temp;
//    }
    void deleteFromList(TNode<T>* node, int index) {
        List<T>* listnode = node->list;
        List<T>* temp = listnode->next;
        while (temp != nullptr && temp->data.currentIndex != index)
            temp = temp->next;
        if (temp != nullptr) {
            if (temp->prev != nullptr)
                temp->prev->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = temp->prev;
        }
        //delete temp->data; // Освобождаем память, если данные хранятся динамически
        delete temp;
    }


    void addToList(List<T>*& node, T num,int index) {
        ToList(node,num,index);
//
//        List<T>* newone = new List<T>(num);
//        if (node != nullptr) {
//            node->prev = newone;
//            newone->next = node;
//        }
//        node = newone;
    }

    T getNodeValue(TNode<T>* p) {
        return p->list->data.data;
    }
    TNode<T>* GetRoot() {

        return this->root;
    }



    int findNode(TNode<T>* root, T num, std::vector<int>* result) {

        if (root == nullptr) {
            std::cout << "The tree is empty.\n";
            return -1;
        }
        TNode<T>* current = root;
        while ((current != nullptr) && (getNodeValue(current) != num)) {
            if (getNodeValue(current) > num)
                current = current->left;
            else if (getNodeValue(current) < num)
                current = current->right;
        }
        if (current == nullptr) {
            return -1;
        }
        else {
            auto cur = current->list;
            while (cur) {
                result->push_back(cur->data.currentIndex);
                cur = cur->next;
            }
            
            return 1;
        }
    }

    void changeIndex(T num, int from, int to) {

        if (root == nullptr) {
            std::cout << "The tree is empty.\n";
            return;
        }
        TNode<T>* current = root;
        while ((current != nullptr) && (getNodeValue(current) != num)) {
            if (getNodeValue(current) > num)
                current = current->left;
            else if (getNodeValue(current) < num)
                current = current->right;
        }
        if (current == nullptr) {
            return;
        }
        else {
            auto cur = current->list;
            while (cur->data.currentIndex != from) {
                cur = cur->next;
            }
            if (cur->data.currentIndex == from)
                cur->data.currentIndex = to;

            return;
        }
    }

    void insertInTree(TNode<T>*& root, T num, bool& h,int index) {
        if ((root == nullptr) || (root->list == nullptr)) {
            root = new TNode<T>(num,index);
            root->height = 1;
            root->left = nullptr;
            root->right = nullptr;
            h = true;
            //root->index.push_back(currentIndex);
        }
        else if (getNodeValue(root) > num) {
            insertInTree(root->left, num, h,index);
            if (h == true) {
                if (root->balance == 1) {
                    root->balance = 0;
                    h = false;
                }
                else if (root->balance == 0) {
                    root->balance = -1;
                }
                else if (root->balance == -1) {
                    TNode<T>* node = root->left;
                    if (node->balance == -1) {
                        root->left = node->right;
                        node->right = root;
                        root->balance = 0;
                        root = node;
                    }
                    else {
                        TNode<T>* node1 = node->right;
                        node->right = node1->left;
                        node1->left = node;
                        root->left = node1->right;
                        node1->right = root;
                        if (node1->balance == -1)
                            root->balance = 1;
                        else
                            root->balance = 0;
                        if (node1->balance == 1)
                            node1->balance = -1;
                        else
                            node->balance = 0;
                        root = node1;
                    }
                    root->balance = 0;
                    h = false;
                }
            }
        }
        else if (getNodeValue(root) < num) {
            insertInTree(root->right, num, h,index);
            if (h == true) {
                if (root->balance == -1) {
                    root->balance = 0;
                    h = false;
                }
                else if (root->balance == 0) {
                    root->balance = 1;
                }
                else if (root->balance == 1) {
                    TNode<T>* node = root->right;
                    if (node->balance == 1) {
                        root->right = node->left;
                        node->left = root;
                        root->balance = 0;
                        root = node;
                    }
                    else {
                        TNode<T>* node1 = node->left;
                        node->left = node1->right;
                        node1->right = node;
                        root->right = node1->left;
                        node1->left = root;
                        if (node1->balance == 1)
                            root->balance = -1;
                        else
                            root->balance = 0;
                        if (node1->balance == -1)
                            node->balance = 1;
                        else
                            node->balance = 0;
                        root = node1;
                    }
                    root->balance = 0;
                    h = false;
                }
            }
        }
        else {
            //root->index.push_back(currentIndex);
            addToList(root->list, num,index);
        }
    }

    void balanceL(TNode<T>*& root, bool& h) {
        if (root->balance == -1)
            root->balance = 0;
        else if (root->balance == 0) {
            root->balance = 1;
            h = false;
        }
        else {
            TNode<T>* node = root->right;
            if (node->balance >= 0) {
                root->right = node->left;
                node->left = root;
                if (node->balance == 0) {
                    root->balance = 1;
                    node->balance = -1;
                    h = false;
                }
                else {
                    root->balance = 0;
                    node->balance = 0;
                }
                root = node;
            }
            else {
                TNode<T>* node1 = node->left;
                node->left = node1->right;
                node1->right = node;
                root->right = node1->left;
                node1->left = root;
                if (node1->balance == -1)
                    root->balance = 1;
                else
                    root->balance = 0;
                if (node1->balance == 1)
                    node->balance = -1;
                else
                    node->balance = 0;
                root = node1;
                node1->balance = 0;
            }
        }
    }

    void balanceR(TNode<T>*& root, bool& h) {
        if (root->balance == 1)
            root->balance = 0;
        else if (root->balance == 0) {
            root->balance = -1;
            h = false;
        }
        else {
            TNode<T>* node = root->left;
            if (node->balance <= 0) {
                root->left = node->right;
                node->right = root;
                if (node->balance == 0) {
                    root->balance = -1;
                    node->balance = 1;
                    h = false;
                }
                else {
                    root->balance = 0;
                    node->balance = 0;
                }
                root = node;
            }
            else {
                TNode<T>* node1 = node->right;
                node->right = node1->left;
                node1->left = node;
                root->left = node1->right;
                node1->right = root;
                if (node1->balance == -1)
                    root->balance = 1;
                else
                    root->balance = 0;
                if (node1->balance == 1)
                    node->balance = -1;
                else
                    node->balance = 0;
                root = node1;
                node1->balance = 0;
            }
        }
    }

    TNode<T>* deleteFromTr(TNode<T>*& root, TNode<T>*& node, bool& h) {
        if (root->right != nullptr) {
            deleteFromTr(root->right, node, h);
            if (h)
                balanceR(root, h);
        }
        else {
            node->list = root->list;
            root = root->left;
            h = true;
        }
        return root;
    }

    TNode<T>* deleteFromTree(TNode<T>*& root, T num, bool& h,int index) {
        if (root == nullptr)
            std::cout << "Tree is empty.";
        else if (getNodeValue(root) > num) {
            root->left = deleteFromTree(root->left, num, h,index);
            if (h)
                balanceL(root, h);
        }
        else if (getNodeValue(root) < num) {
            root->right = deleteFromTree(root->right, num, h,index);
            if (h)
                balanceR(root, h);
        }
        else if (nodeNumber(root->list) > 1) {
            deleteFromList(root,index);
            return root;
        }
        else {
            TNode<T>* node = root;
            if (node->right == nullptr) {
                root = node->left;
                h = true;
            }
            else if (node->left == nullptr) {
                root = node->right;
                h = true;
            }
            else {
                node->left = deleteFromTr(node->left, node, h);
                if (h)
                    balanceL(root, h);
            }
        }
        return root;
    }

    void deleteTree(TNode<T>*& node) {
        if (node != nullptr) {
            if (node->left)
                deleteTree(node->left);
            if (node->right)
                deleteTree(node->right);
            delete node;
        }
    }

    std::string printOnSideFIO(int h, TNode<FIO>* node) {
        std::string all;
        if (node != nullptr) {
            all += printOnSideFIO(h + 8, node->right);
            for (int i = 0; i < h; ++i) {
                all += " ";
            }
            all += printListFIO(node->list) + "\n";
            all += printOnSideFIO(h + 8, node->left);
        }
        return all;
    }
    std::string printOnSideDB(int h, TNode<DB>* node) {
        std::string all;
        if (node != nullptr) {
            all += printOnSideDB(h + 8, node->right);
            for (int i = 0; i < h; ++i) {
                all += " ";
            }
            all += printListDB(node->list) + "\n";
            all += printOnSideDB(h + 8, node->left);
        }
        return all;
    }
    std::string printOnSideAdress(int h, TNode<Adress>* node) {
        std::string all;
        if (node != nullptr) {
            all += printOnSideAdress(h + 8, node->right);
            for (int i = 0; i < h; ++i) {
                all += " ";
            }
            all += printListAdress(node->list) + "\n";
            all += printOnSideAdress(h + 8, node->left);
        }
        return all;
    }


    void toStack(TNode<T>* a, std::stack<int>*& astack) {
        if (a != nullptr) {
            toStack(a->left, astack);
            astack->push(getNodeValue(a));
            toStack(a->right, astack);
        }
    }

    bool areEqual(TNode<T>* a, TNode<T>* b) {
        if (a == nullptr && b == nullptr)
            return true;
        if (a == nullptr ^ b == nullptr)
            return false;
        auto* astack = new std::stack<int>;
        auto* bstack = new std::stack<int>;
        toStack(a, astack);
        toStack(b, bstack);
        while (!astack->empty() && !bstack->empty()) {
            if (astack->top() != bstack->top())
                return false;
            astack->pop();
            bstack->pop();
        }
        return areEqual(a->left, b->left) && areEqual(a->right, b->right);
    }
};

#endif //INC_1_2_AVL_H