#include "Event/EventManager.h"
#include "Test/Game.h"
#include "Test/TestListener.h"
using namespace std;

int main()
{
    auto game = Game();
    auto test = TestListener();
    auto e = ChatEvent("Hello world!");

    EventManager::register_listener(&test, MONITOR);
    EventManager::register_listener(&game);
    EventManager::call(&e);
}
