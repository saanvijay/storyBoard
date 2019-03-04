#pragma once

#include "note.h"
#include <vector>

class storyBoard {
    Note* _note;
    vector<Note*> _noteList;

    public:
        storyBoard() {}
        ~storyBoard() {}

        // we don't want storyBoard to be copied
        storyBoard(const storyBoard&) = delete;
        storyBoard & operator =(const storyBoard&) = delete;

        // move semantics
        storyBoard(storyBoard&&) = delete;
        storyBoard& operator=(storyBoard &&) = delete;

        void addNote();
        void deleteNote(string);
        set<Note*> searchByTitle(string title);
        set<Note*> searchByText(string text);
        set<Note*> searchByTag(string tag);
        void printAllNotes();
};