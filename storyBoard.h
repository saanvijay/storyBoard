#pragma once

#include "note.h"
#include <vector>
#include <memory>

class storyBoard {
    shared_ptr<Note> _note;
    vector<shared_ptr<Note>> _noteList;

    public:
        storyBoard() {}
        ~storyBoard() {}

        storyBoard(const storyBoard &rhs) {
            _note = rhs._note;
            _noteList = rhs._noteList;
        }
       storyBoard & operator =(const storyBoard& rhs) {
           if (this != &rhs) {
            _note = rhs._note;
            _noteList = rhs._noteList;
           }
           return *this;
       }

        // move semantics
        storyBoard(storyBoard&& rhs) {
            _note = std::move(rhs._note);
            _noteList = std::move(rhs._noteList);
           // rhs = nullptr;

        }
       storyBoard& operator=(storyBoard &&rhs) {
           if (this != &rhs){
            _note = std::move(rhs._note);
            _noteList = std::move(rhs._noteList);
           }
           return *this;

       }

        void addNote();
        void deleteNote(string);
        set<shared_ptr<Note>> searchByTitle(string title);
        set<shared_ptr<Note>> searchByText(string text);
        set<shared_ptr<Note>> searchByTag(string tag);
        void printAllNotes();

        shared_ptr<Note> getNote() { return _note; }
        vector<shared_ptr<Note>> getNoteList() {return _noteList; }

};