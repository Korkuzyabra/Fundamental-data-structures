#ifndef COURSE_HASHTABLE_H
#define COURSE_HASHTABLE_H
#include <iostream>
#include <utility>
#include "Order.h"

namespace Denis {

int GetMaxPrime(const int limit);

struct Hs_item{

    int _index;
    Date _date;
    int _num;
    std::string _car;
    bool _status;

    Hs_item(Date date, int num, std::string car, int index){

        _index = index;
        _date = date;
        _num = num;
        _car = std::move(car);
        _status = true;
    }

    ~Hs_item() = default;
};

class HashTable{

public:
    int _count;
    int _max_count;
    int _capacity;
    int _realcount;
    std::vector<Hs_item*> _items;

    int HashFunction(Hs_item* item) const{

        unsigned long long result = 0;
        result += item->_date._day + item->_date._month + item->_date._year;
        for (auto i : item->_car){
            result += (int)i;
        }
        int first = item->_num / 10000;
        int second = item->_num % 10000;
        result += first + second;
        result *= result;
        result /= 1000;
        result %= 10000;
        result %= _capacity;
        return (int)result;
    };
    
    int HashFunction2(Hs_item* item) const{

        unsigned long long a = 0;
        a += item->_date._day + item->_date._month + item->_date._year;
        for (auto i : item->_car){
            a += (int)i;
        }
        int first = item->_num / 10000;
        int second = item->_num % 10000;
        a += first + second;
        int result = 1 + ((a) % (GetMaxPrime(_capacity)));
        return result;
    };
    
    void UpSize(){

        auto* newtable = new HashTable(_capacity*2);
        int count = 0;
        for (auto i = 0; i < _capacity; ++i)
            if ((_items[i] != nullptr)&&(_items[i]->_status)) {
                newtable->InsertItem(_items[i]);
                count++;
            }

        _items = std::move(newtable->_items);
        newtable->_capacity = 0;
        FreeTable(newtable);
        _capacity *= 2;
        _max_count *= 2;
        _realcount = count;
        _count = count;
    };

    void DownSize() {

        auto* newtable = new HashTable(_capacity / 2);
        int count = 0;
        for (auto i = 0; i < _capacity; ++i)
            if ((_items[i] != nullptr) && (_items[i]->_status)) {
                newtable->InsertItem(_items[i]);
                count++;
            }

        _items = std::move(newtable->_items);
        newtable->_capacity = 0;
        FreeTable(newtable);
        _capacity /= 2;
        _max_count /= 2;
        _realcount = count;
        _count = count;
    };
    
    void FreeItems(){
        
        for (auto i = 0; i < _capacity; ++i){
            delete(_items[i]);
            _items[i] = nullptr;
        }
    };

    friend void FreeTable(HashTable* table){
        
        table->FreeItems();
        table->_items.resize(0);
        free(table);
    };

public:

        explicit HashTable(int size = 10){
        
        _capacity = size;
        _count = 0;
        _max_count = size;
        _items = std::vector<Hs_item*>(size);
        _realcount = 0;
        
        for (auto i = 0; i < size; ++i){
            _items[i] = nullptr;
        }
    };

    void InsertItem(Hs_item* item){

        InsertItem(item->_num, item->_car, item->_date, item->_index);
    }
    
    void InsertItem(int num, std::string car, Date date, int index){

        if (_capacity == _realcount){
            std::cout << "Table is full.\n";
            return;
        }
        auto item = new Hs_item(date, num, car, index);
        int hash1 = HashFunction(item);
        int hash2 = HashFunction2(item);
        bool success = false;
        auto current = _items[hash1];
        do{
            int i = 0;
            int _free = -1;
            while ((i <= _max_count)&&(current)&&
                    ((current->_date != date)||(current->_car != car)||(current->_num != num))
            ){
                if ((!current->_status)&&(_free == -1))
                    _free = i;
                ++i;
                current = _items[(hash1 + i * hash2) % _capacity];
            }
            if ((current)&&(current->_date == date)&&(current->_car == car)&&(current->_num == num)){
                if (current->_status) {
                    std::cout << "Such element exists.\n";
                    success = true;
                }
                else{
                    current->_status = true;
                }
            }
            else{
                if ((i <= _max_count)||(_free != -1)){
                    if (_free != -1){
                        current = _items[(hash1 + i * hash2) % _capacity];
                        current->_date = date;
                        current->_num = num;
                        current->_car = car;
                        current->_index = index;
                        _realcount++;
                        success = true;
                    }
                    else{
                        _items[(hash1 + i * hash2) % _capacity] = new Hs_item(date, num, car, index);
                        _count++;
                        _realcount++;
                        success = true;
                    }
                }
                else {
                    UpSize();
                }
            }

            if ((_realcount * 4 / 3) >= _capacity)
                UpSize();
        } while (!success);
    };
    
    std::string PrintHashTable(){

        std::string s;
        for (auto i = 0; i < _capacity; ++i){
            if (_items[i])
                s += std::to_string(i) + " : " +
                std::to_string(_items[i]->_num) + " " +
                _items[i]->_date.Print() + " " +
                _items[i]->_car + " -> " +
                std::to_string(_items[i]->_index) + " (" +
                std::to_string(HashFunction(_items[i])) + ") " +
                std::to_string(_items[i]->_status) + "\n";
            else
                s += std::to_string(i) + " : nullptr\n";
        }

        return s;
    };
    
    ~HashTable(){
        
        for (auto i = 0; i < _capacity; ++i){
            delete(_items[i]);
            _items[i] = nullptr;
        }
    }

    int Search(Date date, int num, std::string car){

        int i = 0;
        auto item = new Hs_item(date, num, car, -1);
        int hash1 = HashFunction(item);
        int hash2 = HashFunction2(item);
        Hs_item* current = _items[hash1];
        while ((i <= _max_count)&&(current)&&
                ((current->_num != num)||(current->_car != car)||(current->_date != date))){
            i++;
            current = _items[(hash1 + i * hash2) % _capacity];
        }
        if (!current) {
            std::cout << "Such item hasn't been found.\n";
            return -1;
        }
        else {
            if ((i <= _max_count) &&
                (current->_num == num) && (current->_car == car) && (current->_date == date)) {
                if (current->_status)
                    return current->_index;
                else {
                    std::cout << "This item has been deleted.\n";
                    return -1;
                }
            } else {
                std::cout << "This item has been deleted.\n";
                return -1;
            }
        }
    }

    void DeleteItem(Hs_item* item){
        DeleteItem(item->_date, item->_num, item->_car);
    }

    void DeleteItem(Date date, int num, std::string car){

        auto item = new Hs_item(date, num, car, -1);
        int i = 0;
        int hash1 = HashFunction(item);
        int hash2 = HashFunction2(item);
        Hs_item* current = _items[hash1];
        while ((i <= _max_count)&&(current)&&
                ((current->_num != num)||(current->_car != car)||(current->_date != date))){
            i++;
            current = _items[(hash1 + i * hash2) % _capacity];
        }
        if ((i <= _max_count)&&(current)&&
        (current->_num == num)&&(current->_car == car)&&(current->_date == date)&&
        (current->_status)) {
            current->_status = false;
            _realcount--;
        }
        else{
            std::cout << "Such item hasn't been found.\n";
        }

        if ((_realcount * 4) <= _capacity)
            DownSize();

    }

};

}

#endif //COURSE_HASHTABLE_H
