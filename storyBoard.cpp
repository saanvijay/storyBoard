#include "storyBoard.h"
#include <algorithm>
#include <set>
#include <iostream>
#include <string>
#include <memory>
using namespace std;
using namespace vijay;

void storyBoard::addNote(string title) {

    string text;
    set<string> tags;

    // create a shared_ptr ( smart pointer)
    m_note = make_shared<Note>();
    
    cout << "Enter user text" << endl;
    getline(cin,text);
    
    while(1) {

        static int i = 0;
        string tag="";

        if (i) cin.get();// to make getline should work in the loop

        cout << "Enter user Tags" << endl;
        getline(cin,tag);
        tags.insert(tag); 

        cout << "More tags? (Y/N)?" << endl;
        char yn;
        cin>>yn;

        i++;

        if (yn == 'y' || yn =='Y') continue;
        else break;
    }

    m_note->setTitle(title);
    m_note->setText(text);
    m_note->setTags(tags);

    // push this note to vector of notes
    m_noteList.push_back(m_note);
}


void storyBoard::deleteNote(string title) {
    for (auto &eachNote : m_noteList) {
        if (title == eachNote->getTitle()) {
                m_noteList.erase(std::remove(m_noteList.begin(), m_noteList.end(), eachNote), m_noteList.end());
                cout << "*** Deleting a Note : " << title <<endl;
        }
    }
}

set<shared_ptr<Note>> storyBoard::searchByTitle(string title) {
    set<shared_ptr<Note>> tNotes;
    for (auto &eachNote : m_noteList) {
        if (eachNote->getTitle() == title) {
            tNotes.insert(eachNote);
            cout << "*** Title found in Notes : " << title <<endl;
        }
    }
    return tNotes;
}

set<shared_ptr<Note>> storyBoard::searchByText(string text) {
    set<shared_ptr<Note>> tNotes;
    for (auto &eachNote : m_noteList) {
        if (eachNote->getText() == text) {
            tNotes.insert(eachNote);
            cout << "*** Text found in Notes: " << text <<endl;
        }
    }
    return tNotes;
}

set<shared_ptr<Note>> storyBoard::searchByTag(set<string> tags) {
    set<shared_ptr<Note>> tNotes;
    for (auto &eachNote : m_noteList) {
            for ( auto &eachNoteTag: eachNote->getTags()) {
                    for (auto &tag : tags) {
                        if (tag == eachNoteTag) {
                            tNotes.insert(eachNote);
                            cout <<"*** Tags found in Notes : "<< tag <<endl;
                        }
                    }
            }
                
    }
return tNotes;
}

void storyBoard::printAllNotes() {

    for (auto &eachNote : m_noteList) {
        cout << "StoryBoard Details" << endl;
        cout << "-------------------" << endl;
        cout << "Title      : " << eachNote->getTitle() << endl;
        cout << "Text       : " << eachNote->getText() << endl;
        cout << "Tags       : { ";
        for (auto tag : eachNote->getTags())
            cout << "{ " << tag << " }, ";
        cout << " }" << endl<<endl;
    }
}