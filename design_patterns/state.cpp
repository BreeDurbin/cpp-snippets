#include<iostream>
#include<memory>
#include <string>

using namespace std;


class Context;

class State{
    protected:
    Context* _context;
    public: 
    virtual void handle(string message) = 0;
    virtual string name() const {return "Default State"; };
    void set_context(Context* context){
        _context = context;
    }
};

class StateA : public State {
    public: 

    void handle(string message) override {
        cout << "Handling message: " << message << " with stateA.Handler().\n";
        cout << "Changing state to StateB.\n";
        //_context->set_state(make_unique<StateB>());
    };

    string name() const override { return "StateA"; };
};

class StateB : public State {
    public: 

    void handle(string message) override {
        cout << "Handling message: " << message << " with stateB.Handler().\n";
        cout << "Changing state to StateA.\n";
        //_context->set_state(make_unique<StateA>());
    };

    string name() const override { return "StateB"; };
};

class Context {
    private:
    unique_ptr<State> _state;

    public:
    Context(unique_ptr<State>&& state) : _state{move(state)} {
        cout << "Initialized context with strategy: " << _state->name() << endl;
    };

    void set_state(unique_ptr<State>&& state) {
        _state = move(state);
    };

    void request(string message){ _state->handle(message); };

};



int main() {

    cout << "Hiya!\n";

    Context context = Context(std::make_unique<StateA>());
    context.request("Message 1");
    context.request("Message 2");

    return 0;
}
