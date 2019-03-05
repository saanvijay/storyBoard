#pragma once

#include <iostream>
#include <set>
#include <string>
using namespace std;

namespace vijay {
class Note {
    string _title;
    string _text;
    string _tags;

    public:
        Note() {}
        ~Note() {}
        Note(const Note &rhs) {
                _title = rhs._title;
                _text = rhs._text;
                _tags = rhs._tags;
        }
        Note& operator=(const Note &rhs) {
            if (this != &rhs) {
                 _title = rhs._title;
                _text = rhs._text;
                _tags = rhs._tags;
            }
            return *this;
        }

        // move semantics
        Note(Note &&) = delete;
        Note& operator=(Note &&) = delete;

        void setTitle(string title) { _title = title;}
        void setText(string text) { _text = text; }
        void setTags(string tags) { _tags = tags;}

        string getTitle() { return _title;}
        string getText() { return _text;}
        string getTags() { return _tags;}
};
}