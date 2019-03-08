#include "storyBoard.h"
#include <iostream>
#include <memory>
using namespace std;
using namespace vijay;

int main() {

    auto board = make_unique<storyBoard>();
    if (board == nullptr) {
        cout <<"Unable to create storyBoard"<<endl;
        return 0;
    }
    
    board->addNote("Test Traceplayer");
    board->printAllNotes();

    board->searchByTitle("Test Traceplayer");
    board->searchByTag({"testing", "unit test"});
    board->searchByText("Implement a unit test for the class Traceplayer of the spark core framework.");
    board->deleteNote("Test Traceplayer");

    return 0;
}