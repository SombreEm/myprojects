#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
class Product {
public:
    Product(const string& name, int id, double price, int quantity) :
        name_(name), id_(id), price_(price), quantity_(quantity) {}

    const string& name() const { return name_; }
    int id() const { return id_; }
    double price() const { return price_; }
    int quantity() const { return quantity_; }

    void set_price(double price) { price_ = price; }
    void set_quantity(int quantity) { quantity_ = quantity; }

    bool operator<(const Product& other) const { return name_ < other.name_; }
    bool operator==(const Product& other) const { return name_ == other.name_; }

private:
    string name_;
    int id_;
    double price_;
    int quantity_;
};

class Warehouse {
public:
    Warehouse() {}
    void add_product(const Product& product) { products_.push_back(product); }

    void remove_product(int id) {
        for (auto it = products_.begin(); it != products_.end(); ++it) {
            if (it->id() == id) {
                products_.erase(it);
                break;
            }
        }
    }
    int get_quantity(int id) const {
        for (const auto& product : products_) {
            if (product.id() == id) {
                return product.quantity();
            }
        }
        return 0;
    }
    void filter_products(function<bool(const Product&)> condition) {
        for (const auto& product : products_) {
            if (condition(product)) {
                cout << product << endl;
            }
        }
    }
    void display_all_products() const {
        for (const auto& product : products_) {
            cout << product << endl;
        }
    }

private:
    vector<Product> products_;
};



int main() {
    Warehouse warehouse;

    warehouse.add_product(Product("Книга", 1, 200.0, 10));
    warehouse.add_product(Product("Ручка", 2, 50.0, 20));
    warehouse.add_product(Product("Олівець", 3, 20.0, 30));
    warehouse.filter_products([](const Product& product) { return product.price() > 100; });
    warehouse.display_all_products();

}