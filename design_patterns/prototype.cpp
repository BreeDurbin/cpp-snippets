#include<iostream>
#include<memory>
#include <string>

using namespace std;

class Prototype {
    public:
    virtual Prototype* clone() = 0;
};

class Product : public Prototype {
    int _data{};
    public:
    Product(int data) : _data{data} {}
    Product(const Product& rhs) : _data{rhs.data()} {}

    Product* clone() override {
        return new Product(*this);
    }

    int data() const { return _data; }
    void set_data( int data ) {_data = data; }
};

class Client {
    public:
    void do_operation(){
        cout << "Hiya!\n";

        Product* first_product = new Product{1};
        Product* cloned_product = first_product->clone();

        cout << "first product data: " << first_product->data() 
            << " cloned product data " << cloned_product->data() << "\n";
        
        first_product->set_data(100);

        cout << "changed first product data: " << first_product->data() 
            << " unchanged cloned product data " << cloned_product->data() << "\n";

        delete first_product;
        delete cloned_product;
    }
};

int main() {

    Client client{};
    client.do_operation();
    
    return 0;
}

