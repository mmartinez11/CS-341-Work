//
// Project 1
// CS 341 Spring 2021
// <<Manuel M Martinez>>
//
// The source file implementing the characterParser class, a collection of characters
// You are to implement the acronymIterator, then change this class to use
//  acronymIterator as the default iterator for the class

#include "characterParser.h"
#include "charIterator.h"
#include "acronymIterator.h"

// Default constructor
// Constructs an empty string
characterParser::characterParser()
    : array(nullptr), length(0)
{    }

// Parametrized constructor
//  Builds a characterParser deep copied from a char *
characterParser::characterParser(char* str)
{
    int len = std::strlen(str);
    array = new char[len + 1];

    std::strncpy(array, str, len);

    // If on windows:     strncpy_s(array, len + 1, str, len);
    array[len] = '\0';
    length = len;
}

// Parametrized constructor
//  Builds a characterParser deep copied from a std::string
characterParser::characterParser(std::string str)
{
    int len = str.length();
    array = new char[len + 1];
    std::strncpy(array, str.c_str(), len);
    // If on windows:    strncpy_s(array, len + 1, str.c_str(), len);
    array[len] = '\0';
    length = len;
}

//-------------------------------------------------------------------------------------------------------------

//---FIX---//
// begin()
//  Returns an charIterator pointing to the first element of the string.
characterParser::acronymIterator characterParser::begin()
{
    return acronymIterator(array);
}

//---FIX---//
// end()
//  Returns an charIterator pointing "after" the last element of the string.
characterParser::acronymIterator characterParser::end()
{
    return acronymIterator(array + length);
}

characterParser::charIterator characterParser::begin2()
{
    return charIterator(array);
}

characterParser::charIterator characterParser::end2()
{
    return charIterator(array + length);
}

//---FIX---//
// printAllCharacters
// Prints every character in the characterParser
// Requires modification after the default iterator has been changed
void characterParser::printAllCharacters()
{
    //this->begin2();

    //auto mycount = std::count(this->begin2(), this->end2(), 'w');
    
    //std::cout << mycount;

    /*
    for (char c : *this)
    {
        std::cout << c;
    }
    std::cout << std::endl;
    */

    
    for (auto it = this->begin2(), e = this->end2(); it != e; ++it) 
    { 
        const char c = *it; 
        std::cout << c; 
    }

}


