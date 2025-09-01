#include<iostream>
#include<memory>
#include <string>

using namespace std;

class Target {
    public:
    virtual string request() const = 0;
};

class Adaptee {
    public:
    string specific_request() const {
        return "Adaptee specific request."; 
    }
};

class Adapter : public Target {
    private:
    unique_ptr<Adaptee> _adaptee = make_unique<Adaptee>();
    public:
    string request() const {
        return "Adapter modified adaptee request: " + _adaptee->specific_request();
    }
};

class Client {
    unique_ptr<Target> _target;
    public:
    Client(unique_ptr<Target>&& target) : _target{move(target)} {}
    string do_work(){
        return _target->request();
    }
};

int main() {
    Client client(make_unique<Adapter>());
    cout << client.do_work() << "\n";
    return 0;
}
