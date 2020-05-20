#include <iostream>
#include <vector>
#include <string>

using namespace std;

class pizza
{
protected:
    string name;
    string description;
    int price;
    int size;
    int cheese;
    int salt;
public:
    virtual string get_name() const = 0;
    virtual string get_description() const = 0;
    virtual int get_price() const = 0;
    virtual int get_size() const = 0;
    virtual int get_cheese() const = 0;
    virtual int get_salt() const = 0;
};

class pizza_1 : public pizza
{
public:
    pizza_1(unsigned int size, unsigned int cheese, unsigned int salt)
    {
        this->name = "pizza_1";
        this->size = size;
        this->cheese = cheese;
        this->salt = salt;
        this->description = " //моцарелла, помидоры, салями, томатная паста, оливки ";
        this->price = get_size() * 10 + get_salt() * 2 + get_cheese() * 20;
    }

    string get_name() const override { return name; }
    string get_description() const override { return description; }
    int get_size() const override { return size; }
    int get_salt() const override { return salt; }
    int get_cheese() const override { return cheese; }
    int get_price() const override { return price; }
};

class pizza_2 : public pizza
{
public:
    pizza_2(unsigned int size, unsigned int cheese, unsigned int salt)
    {
        this->name = "pizza_2";
        this->size = size;
        this->cheese = cheese;
        this->salt = salt;
        this->description = " //томатная паста, моцарелла, пепперони";
        this->price = get_size() * 12 + get_salt() * 2 + get_cheese() * 15;
    }

    string get_name() const override { return name; }
    string get_description() const override { return description; }
    int get_size() const override { return size; }
    int get_salt() const override { return salt; }
    int get_cheese() const override { return cheese; }
    int get_price() const override { return price; }
};

class pizza_3 : public pizza
{
public:
    pizza_3(unsigned int size, unsigned int cheese, unsigned int salt)
    {
        this->name = "pizza_3";
        this->size = size;
        this->cheese = cheese;
        this->salt = salt;
        this->description = " //таматная паста, базилик, моцарелла, помидоры";
        this->price = get_size() * 8 + get_salt() * 2 + get_cheese() * 25;
    }

    string get_name() const override { return name; }
    string get_description() const override { return description; }
    int get_size() const override { return size; }
    int get_salt() const override { return salt; }
    int get_cheese() const override { return cheese; }
    int get_price() const override { return price; }
};

class order
{
    vector<pizza*> pizzas;

public:
    void add(pizza* _pizza)
    {
        pizzas.push_back(_pizza);
    }
    void print()
    {
        int _price = 0;
        int n = pizzas.size();
        cout << "Order:" << endl;
        for(int i = 0; i < n; i++)
        {
            cout << i + 1 << ". " << pizzas[i]->get_name() <<
            " цена: " << pizzas[i]->get_price() <<
            " размер: " << pizzas[i]->get_size() <<
            " кол-во доп. соли: " << pizzas[i]->get_salt() <<
            " кол-во доп. сыра: " << pizzas[i]->get_cheese() <<
            pizzas[i]->get_description() << endl;
        }
        for(int i = 0; i < n; i++)
        {
            _price += pizzas[i]->get_price();
        }
        cout << "Итого: " << _price << endl;
    }
};

void input(order &order)
{
    while (true)
    {
        unsigned int pizza, size, cheese, salt;
        cin >> pizza;
        if (pizza == 0)
            return;
        cin >> size;
        if ((size != 25) && (size != 30) && (size != 35) && (size != 40))
        {
            if (size == 0)
                return;
            size = 25;
        }
        cin >> cheese;
        cin >> salt;
        if (pizza == 1)
            order.add(new pizza_1(size, cheese, salt));
        else if (pizza == 2)
            order.add(new pizza_2(size, cheese, salt));
        else if (pizza == 3)
            order.add(new pizza_3(size, cheese, salt));
    }
}

int main() {
    system("chcp 65001");
    pizza_1 pizza_1(25, 1, 1);
    pizza_2 pizza_2(25, 1, 1);
    pizza_3 pizza_3(25, 1, 1);

    cout << "Меню:" << endl;
    cout << "1. " << pizza_1.get_name() << " " << pizza_1.get_description() << endl;
    cout << "2. " << pizza_2.get_name() << " " << pizza_2.get_description() << endl;
    cout << "3. " << pizza_3.get_name() << " " << pizza_3.get_description() << endl;
    cout << "Размеры: " << endl;
    cout << 25 << endl;
    cout << 30 << endl;
    cout << 35 << endl;
    cout << 40 << endl;
    cout << "Введите номер пиццы, размер, кол-во доп. сыра и кол-во доп. соли" << endl;
    cout << "Введите 0 если заказ окончен." << endl;

    order order;
    input(order);
    order.print();
    return 0;
}
