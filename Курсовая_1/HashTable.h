#ifndef INC_1_2_HASHTABLE_H
#define INC_1_2_HASHTABLE_H

#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "Clients_comparasion.h"

class HashTable {
public:
    int tableSize;
    struct Entry{
        int key;
        int number;
        std::string value;
        int status;
        int CurrentIndex;

        Entry(): status(0){};
    };
    std::list<Entry>* table;  //key,value,status

public:
    HashTable(int size) : tableSize(size) {
        table = new std::list<Entry>[tableSize];
    }
    bool isEmpty() const;
    int hf1(const Person& person);
    int hf2(int hash1,int trial,const int tableSize);
    void add(const Person& person, int index);
    void remove(const Person& person);
    int search(const Person& person);
    std::string print();
    void helpDel(int hash);
    int MODINC(int bits, int index) {
        return ((index + 1)%tableSize) & ((1 << bits) - 1);
    }
    void solution(int hash, Entry newEntry,const Person& person, int n);
    ~HashTable() {
        delete[] table;
    }
};

bool HashTable::isEmpty() const{
    int sum{};
    for (int i{}; i < tableSize; i++){
        sum += table[i].size();
    }

    if (!sum) {
        return true;
    }
    return false;
}


int HashTable::hf1(const Person& person){
//    std::string line = fio.F + fio.I + fio.O;
    int hash = 0;
    int key = person.getNUM().number;
    while (key > 0){
        hash += key % 1000;
        key = (key-key % 1000) / 1000;
    }

    return hash % tableSize;

};
int HashTable::hf2(int hash1,int trial,const int tableSize){
    return ((hash1 + trial * 1) % tableSize);
};

void HashTable::solution(int hash, Entry newEntry,const Person& person, int n){
    int trial = 1;


        if (n == 1){
            while (trial < tableSize) {
                int index = hf2(hash, trial, tableSize);
                if (table[index].empty() || table[index].front().status == 0) {
                    //newEntry.key = index;
                    table[index].clear();
                    table[index].push_front(newEntry);
                    return;
                }
                trial++;
            }
        }
        if (n == 2){
            int trial = 1;
//            std::string line = room.letter + to_string(room.digit) + " " + fio.F + " " + fio.I + " " + fio.O + " " + to_string(time.hour) + " " + to_string(time.minute);
            std::string line = std::to_string(person.getNUM().number) + " " + person.getFIO().surname + " " + person.getFIO().name + " " + person.getFIO().f_name + " "
                    + std::to_string(person.getDB().day) + "." + std::to_string(person.getDB().month)
                    + "." + std::to_string(person.getDB().year) + " " + person.getADRESS().address;
            while (trial < tableSize) {
                int index = hf2(hash, trial, tableSize);
                if (!table[index].empty()) {
                    if (table[index].front().status == 1) {
                        Entry &entry = table[index].front();
                        if (table[index].front().value == line) {
                            // Mark the entry as deleted
                            entry.status = 0;
                            std::cout << "Удалено: " << entry.value << std::endl;
                            helpDel(index);
                            return;
                        }
                    }
                }

                trial++;
            }

        }
        if (n == 3){
            std::string line = std::to_string(person.getNUM().number) + " " + person.getFIO().surname + " " + person.getFIO().name + " " + person.getFIO().f_name + " "
                               + std::to_string(person.getDB().day) + "." + std::to_string(person.getDB().month)
                               + "." + std::to_string(person.getDB().year) + " " + person.getADRESS().address;
            while (trial < tableSize) {
                int index = hf2(hash, trial, tableSize);
                // Check if the entry at the index matches the given FIOs and time
                if (!table[index].empty() && table[index].front().status != 0) {
                    Entry& entry = table[index].front();
                    if (entry.value == line)  {
                        std::cout << "Найдено: " << entry.value << std::endl;
                        return;
                    }
                }
                trial++;
            }
        }


    if (trial >= tableSize) {
        std::cout << "ERROR" << std::endl;
    }
}

void HashTable::add(const Person&person, int index) {
    int hash = hf1(person);
    Entry newEntry;
    std::string line = std::to_string(person.getNUM().number) + " " + person.getFIO().surname + " " + person.getFIO().name + " " + person.getFIO().f_name + " "
                       + std::to_string(person.getDB().day) + "." + std::to_string(person.getDB().month)
                       + "." + std::to_string(person.getDB().year) + " " + person.getADRESS().address;
    newEntry.value = line;
    newEntry.status = 1;
    newEntry.number = person.getNUM().number;
    newEntry.key = hash;
    newEntry.CurrentIndex = index;
    for (int i = 0; i < tableSize;i++) {
        // Check if an entry with the same key exists
        for (auto &entry: table[i]) {
            if (entry.value == newEntry.value && entry.status == 1) {
                std::cout << "Невозможно добавить! Такая запись уже есть!" << std::endl;
                return;
            }
        }
    }
    //std::cout << hash << std::endl;
    if (table[hash].empty() || table[hash].front().status == 0){
        //newEntry.key = hash;
        table[hash].clear();
        table[hash].push_front(newEntry);
        return;
    }
    else{
        solution(hash, newEntry, person, 1);
    }
}

void HashTable::helpDel(int index) {
    int start = index;
    table[start].clear();
    int nextIndex = MODINC(tableSize, start);
    int replace;
    while (nextIndex != start) {
        bool flag2 = true;
        if (!table[nextIndex].empty() && table[nextIndex].front().key != nextIndex) {
            int trial = 0;
            int h = table[nextIndex].front().key;
            while (true) {
                replace = hf2(h, trial, tableSize);
                if (replace == nextIndex) { // Добавленное условие: если replace равен nextIndex
                    flag2 = false;
                    break;
                }
                if (flag2) {
                    if (table[replace].empty()) {
                        auto temp = table[replace];
                        table[replace] = table[nextIndex];
                        table[nextIndex] = temp;
                        break;
                    } else {
                        trial++;
                    }
                }
            }
        }
        nextIndex = MODINC(tableSize, nextIndex);
    }
    return;
}
//
void HashTable::remove(const Person&person) {
    int hash = hf1(person);
    Entry& entry = table[hash].front();
    //std::string inputline = std::to_string(person.getNUM().number) + " " + person.getFIO().surname + " " + person.getFIO().name + " " + person.getFIO().f_name + " "
  //                     + std::to_string(person.getDB().day) + "." + std::to_string(person.getDB().month)
    //                   + "." + std::to_string(person.getDB().year) + " " + person.getADRESS().address;
    int inputline = person.getNUM().number;
    if (isEmpty() == false) {
        if (entry.status == 1 && entry.number == inputline) {
            //entry.status = 0;
            std::cout << "Удалено: " << entry.value << std::endl;
            helpDel(hash);
            //return;
        } else if (entry.status == 0 || entry.number != inputline || table[hash].empty()) {
            bool found = false;
            solution(hash, entry, person, 2);
//            if (found == false) {
//                std::cout << "Запись не найдена" << std::endl;
//            }
        }
    }
    if (isEmpty()== true){
        std::cout << "Таблица пустая" << std::endl;
    }
}

int HashTable::search(const Person&person) {
    int hash = hf1(person);
    int trial = 0;
    int rehash = hash;
   // std::string line = std::to_string(person.getNUM().number) + " " + person.getFIO().surname + " " + person.getFIO().name + " " + person.getFIO().f_name + " "
                       //+ std::to_string(person.getDB().day) + "." + std::to_string(person.getDB().month)
                       //+ "." + std::to_string(person.getDB().year) + " " + person.getADRESS().address;
    int line = person.getNUM().number;
    while (!table[rehash].empty() && trial < tableSize) {
        Entry& entry = table[rehash].front();
//        if (!table[hash].empty() && table[hash].front().status == 1) {
        if (entry.key == hash && entry.number == line) {
            std::cout << "Найдено: " << entry.value << std::endl;
            return entry.CurrentIndex;
        }
        trial++;
        rehash = hf2(hash,trial,tableSize);

        //hash = hf2(hash,trial,tableSize);

        //}
    }
    if (table[rehash].empty() || trial >= tableSize){
        //std::cout << "Такого элемента нет" << std::endl;
        return -1;
    }
}

std::string HashTable::print() {


    std::string space = " ";
    std::string left = "[";
    std::string right = "]";
    std::string lr = "(";
    std::string rr = ")";
    std::string s = "";
    for (int i = 0; i < tableSize; i++) {
        s +=  left + msclr::interop::marshal_as<std::string>(i.ToString())+ right + space;
        for (auto& entry : table[i]) {
            s += lr + msclr::interop::marshal_as<std::string>(entry.key.ToString()) + rr + space + /*space + msclr::interop::marshal_as<std::string>(entry.key.ToString()) + space + msclr::interop::marshal_as<std::string>(entry.number.ToString()) + left + msclr::interop::marshal_as<std::string>(entry.CurrentIndex.ToString()) + right +*/ entry.value;
            
        }
        s += "\n";
    }
    return s;
}

#endif //INC_1_2_HASHTABLE_H
