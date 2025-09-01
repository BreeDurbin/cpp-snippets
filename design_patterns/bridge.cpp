#include<iostream>
#include<memory>
#include <string>

using namespace std;

class Platform {
    public:
    virtual void setup() const = 0;
};

class ConcretePlatform : public Platform {
    public:
    void setup() const { cout << "ConcretePlatform::setup()\n"; }
};

class Bridge{
    protected:
    unique_ptr<Platform> _platform;
    public:
    Bridge(unique_ptr<Platform>&& platform) : _platform{ move(platform) } {}
    void feature() const { cout << "Using bridge::feature()\n"; }
};

class SpecificBridge : public Bridge {
    public:
    SpecificBridge(unique_ptr<Platform>&& platform) : Bridge(move(platform)) {}
    void fancy_feature() const { 
        _platform->setup();
        cout << "SpecificBridge::fancy_feature()\n";
    }
};

int main() {
    SpecificBridge bridge(make_unique<ConcretePlatform>());
    bridge.feature();
    bridge.fancy_feature();
    return 0;
}
