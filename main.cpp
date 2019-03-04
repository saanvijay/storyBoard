#include "storyBoard.h"
#include <iostream>
#include <memory>
using namespace std;

int main() {

    auto sB = make_unique<storyBoard>();// C++14 
    sB->addNote();
    sB->printAllNotes();

    sB->searchByTitle("This is for test");
    sB->searchByTag("tag");
    sB->searchByText("text");
    sB->deleteNote("This is for test");

    return 0;
}