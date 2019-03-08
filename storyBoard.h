#pragma once

#include "Note.h"
#include <vector>
#include <memory>

namespace vijay {
    class storyBoard {
        shared_ptr<Note> m_note;
        vector<shared_ptr<Note>> m_noteList;

        public:
            storyBoard() {}
            ~storyBoard() {}

            // Copy constructor
            storyBoard(const storyBoard &rhs) {
                m_note = rhs.m_note;
                m_noteList = rhs.m_noteList;
            }

            // Assignment operator
            storyBoard & operator =(const storyBoard& rhs) {
                // avoid self-copy
                if (this != &rhs) {
                    m_note = rhs.m_note;
                    m_noteList = rhs.m_noteList;
                }
                return *this;
            }

            // move copy constructor
            storyBoard(storyBoard&& rhs) {
                m_note = std::move(rhs.m_note);
                m_noteList = std::move(rhs.m_noteList);
            }

            // move assignment operator
            storyBoard& operator=(storyBoard &&rhs) {
                if (this != &rhs) { // avoid self-move
                    m_note = std::move(rhs.m_note);
                    m_noteList = std::move(rhs.m_noteList);
                }
                return *this;
            }

            void addNote(string);
            void deleteNote(string);
            set<shared_ptr<Note>> searchByTitle(string title);
            set<shared_ptr<Note>> searchByText(string text);
            set<shared_ptr<Note>> searchByTag(set<string> tag);
            void printAllNotes();

            shared_ptr<Note> getNote() { return m_note; }
            vector<shared_ptr<Note>> getNoteList() {return m_noteList; }

    };
}