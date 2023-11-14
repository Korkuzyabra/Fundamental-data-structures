#ifndef INC_1_2_LIST_H
#define INC_1_2_LIST_H
#include "Clients.h"

template<typename T2>
struct Info {
    T2 data;
    int currentIndex;

    Info() : data(T2()), currentIndex(-1) {}
    Info(T2 val, int index) : data(val), currentIndex(index) {}
};

template<typename T2>
class List {
public:
    Info<T2> data;
    List<T2>* next;
    List<T2>* prev;

    List() {
        next = nullptr;
        prev = nullptr;
    }

    List(T2 val, int index) : data(val, index) {
        next = nullptr;
        prev = nullptr;
    }
};

template<typename T2>
void ToList(List<T2>*& head, T2 val, int index) {
    List<T2>* newNode = new List<T2>(val, index);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template<typename T2>
void removeAfter(List<T2>* head, T2 val) {
    if (head == nullptr) {
        return;
    }
    List<T2>* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->data.data == val) {
            List<T2>* temp = current->next;
            current->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = current;
            }
            delete temp;
        }
        current = current->next;
    }
}

template<typename T2>
void deleteFromList(List<T2>*& head, T2 val,int index) {
    List<T2>* current = head;
    while (current != nullptr) {
        if (current->data.data == val && current->data.data == index) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

template<typename T2>
void search(List<T2>* head, T2 val, std::vector<int>* result) {

    List<T2>* current = head;
    while (current != nullptr) {
        if (current->data.data == val) 
            result->push_back(current->data.currentIndex);
        current = current->next;
    }
}

template<typename T>
List<T>* mergeLists(List<T>* head1, List<T>* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }
    List<T>* current = head1;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = head2;
    head2->prev = current;
    return head1;
}

template<typename T>
void freeMemory(List<T>*& head) {
    List<T>* current = head;
    while (current != nullptr) {
        List<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

std::string printListAdress(List<Adress>* head) {
    std::string s = "";
    List<Adress>* current = head;
    msclr::interop::marshal_context context;
    while (current != nullptr) {
        s += (std::string)current->data.data + " [" + context.marshal_as<std::string>(current->data.currentIndex.ToString()) + "]";
        current = current->next;
        if (current != nullptr) {
            s+= " <-> ";
        }
    }
    return s;
}
std::string printListFIO(List<FIO>* head) {
    std::string s = "";
    List<FIO>* current = head;
    msclr::interop::marshal_context context;
    while (current != nullptr) {
        s += (std::string)current->data.data + " [" + context.marshal_as<std::string>(current->data.currentIndex.ToString()) + "]";
        current = current->next;
        if (current != nullptr) {
            s += " <-> ";
        }
    }
    return s;
}
std::string printListDB(List<DB>* head) {
    std::string s = "";
    List<DB>* current = head;
    msclr::interop::marshal_context context;
    while (current != nullptr) {
        s += (std::string)current->data.data + " [" + context.marshal_as<std::string>(current->data.currentIndex.ToString()) + "]";
        current = current->next;
        if (current != nullptr) {
            s += " <-> ";
        }
    }
    return s;
}

#endif
