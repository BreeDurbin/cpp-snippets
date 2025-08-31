#include<iostream>
#include<memory>
#include <string>

using namespace std;

class Product {
    string _data{};
    public:
    Product(string data) : _data{data} {}
    string data() const { return _data; }
};

class ProductFactory {
    public: 
    Product* build(){
        return new Product("Factory built.");
    }
};

int main() {

    ProductFactory factory{};
    Product* product = factory.build();
    cout << "Product: " << product->data() << "\n";
    delete product;
    return 0;
}
