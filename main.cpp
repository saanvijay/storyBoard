#include "storyBoard.h"
#include <iostream>
#include <memory>
using namespace std;
using namespace vijay;

int main() {

    auto sB = make_unique<storyBoard>();
    if (sB == nullptr) {
        cout <<"Unable to create storyBoard"<<endl;
        return 0;
    }
    
    sB->addNote();
    sB->printAllNotes();

    sB->searchByTitle("This is for test");
    sB->searchByTag("tag");
    sB->searchByText("text");
    sB->deleteNote("This is for test");

    return 0;
}