#pragma once
#include <string.h>
#include <iostream>
#include <vector>
#include <author.h>

class Element
{
public:
    virtual void print() = 0;
};


class Image : public Element
{
private:
    std::string imageName;
public:
    Image(std::string imageName);
    void print();
};


class Paragraph : public Element
{
private:
    std::string text;
public:
    Paragraph(std::string text);
    void print();
};


class Table : public Element
{
private:
    std::string title;
public:
    Table(std::string title);
    void print();
};


class SubChapter
{
private:
    std::string name;
    std::vector<Element*> elementList;
public:
    SubChapter(std::string name);
    ~SubChapter();
    int createNewImage(std::string imageName);
    int createNewParagraph(std::string paragraphText);
    int createNewTable(std::string tableTitle);
    void print();
};


class Chapter
{
private:
    std::string name;
    std::vector<SubChapter> subChapterList;
public:
    Chapter(std::string name);
    int createSubChapter(std::string subChapterName);
    SubChapter* getSubChapter(int index);
    void print();
};


class Book
{
private:
    std::string title;
    std::vector<Chapter> chapterList;
    std::vector<Author> authorList;
public:
    Book(std::string title);
    int createChapter(std::string chapterName);
    Chapter* getChapter(int index);
    void addAuthor(Author author);
    void print();
};