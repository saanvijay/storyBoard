#pragma once

#include <iostream>
#include <set>
#include <string>
using namespace std;

// namespace vijay to avoid any other scope
namespace vijay {
    class Note {
        string      m_title;
        string      m_text;
        set<string> m_tags;

        public:
            Note() {}
            ~Note() {}
            // Copy Constructor
            Note(const Note &rhs) {
                    m_title = rhs.m_title;
                    m_text = rhs.m_text;
                    m_tags = rhs.m_tags;
            }
            // Assignment operator
            Note& operator=(const Note &rhs) {
                if (this != &rhs) {
                    m_title = rhs.m_title;
                    m_text  = rhs.m_text;
                    m_tags  = rhs.m_tags;
                }
                return *this;
            }

            // move semantics
            Note(Note &&) = delete;
            Note& operator=(Note &&) = delete;

            // Set member functions
            void setTitle(string title)     { m_title = title;}
            void setText(string text)       { m_text  = text;}
            void setTags(set<string> tags)  { m_tags  = tags;}

            // get member functions
            auto getTitle() { return m_title;}
            auto getText()  { return m_text;}
            auto getTags()  { return m_tags;}
    };
}