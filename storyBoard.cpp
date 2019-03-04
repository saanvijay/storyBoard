#include "storyBoard.h"
#include <algorithm>
#include <set>
#include <iostream>
#include <string>
using namespace std;


void storyBoard::addNote() {

    _note = new Note;
    string title, text;
    string tags;

    cout << "Enter Title" << endl;
    getline(cin,title);
    
    _note->setTitle(title);

    cout << "Enter text" << endl;
    getline(cin,text);
   _note->setText(text);
   
    cout << "Enter Tag" << endl;
    getline(cin,tags);
    _note->setTags(tags);

    _noteList.push_back(_note);
}


void storyBoard::deleteNote(string title) {
    for (auto &tList : _noteList) {
        if (title == tList->getTitle()) {
                _noteList.erase(std::remove(_noteList.begin(), _noteList.end(), tList), _noteList.end());
                cout << "Deleting Note...." <<endl;
        }
    }
}

set<Note*> storyBoard::searchByTitle(string title) {
    set<Note*> titleNotes;
    for (auto &l : _noteList) {
        if (l->getTitle() == title) {
            titleNotes.insert(l);
            cout << "---- Title Found ----" << endl;
        }
    }
return titleNotes;

}

set<Note*> storyBoard::searchByText(string text) {
    set<Note*> textNotes;
    for (auto &l : _noteList) {
        if (l->getText().find(text)) {
            textNotes.insert(l);
            cout << "---- Text Found ----" << endl;
        }
    }
return textNotes;
}

set<Note*> storyBoard::searchByTag(string tags) {
    set<Note*> tagNotes;
    for (auto &l : _noteList) {
            if (l->getTags().find(tags)) 
                tagNotes.insert(l);
                cout << "---- Tag Found ----" << endl;
    }
return tagNotes;
}

void storyBoard::printAllNotes() {

    for (auto &nL : _noteList) {
        cout << "StoryBoard Details" << endl;
        cout << "-------------------" << endl;
        cout << "Title      : " << nL->getTitle() << endl;
        cout << "Text       : " << nL->getText() << endl;
        cout << "Tags       : " << nL->getTags() << endl;
    }
}