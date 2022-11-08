#pragma once
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <sstream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "../interface/author.h"

std::string genRandomString(const int len);


class Element
{
public:
    virtual void print() = 0;
    virtual void add(Element*) = 0;
    virtual void remove(Element*) = 0;
    virtual Element* get(int index) = 0;
};


class Picture
{
public:
    virtual std::string getUrl() = 0;
    virtual int getDimension() = 0;
    virtual std::string getPictureContent() = 0;
};


class Image: public Element, public Picture
{
private:
    std::string url;
    std::string imageContent;
public:
    Image(std::string url);

    std::string getUrl();
    int getDimension();
    std::string getPictureContent();

    void print();
    void add(Element* element);
    void remove(Element* element);
    Element* get(int index);
};


class ImageProxy: public Element, public Picture
{
private:
    Image *realImage;
    std::string url;
    int dimension;
public:
    ImageProxy(std::string url);
    ~ImageProxy();
    Image loadImage();

    std::string getUrl();
    int getDimension();
    std::string getPictureContent();

    void print();
    void add(Element* element);
    void remove(Element* element);
    Element* get(int index);
};


class AlignStrategy
{
public:
    virtual void render(std::string text) = 0;
};


class AlignLeft: public AlignStrategy
{
private:
    int left;
public:
    AlignLeft(int left);
    void render(std::string text);
};


class AlignRight: public AlignStrategy
{
private:
    int right;
public:
    AlignRight(int right);
    void render(std::string text);
};


class AlignCenter: public AlignStrategy
{
public:
    AlignCenter();
    void render(std::string text);
};


class Paragraph: public Element
{
private:
    std::string text;
    AlignStrategy *alignStrategy;
public:
    Paragraph(std::string text);
    void setAlignStrategy(AlignStrategy *alignStrategy);

    void print();
    void add(Element* element);
    void remove(Element* element);
    Element* get(int index);

    friend class AlignStrategy;
};


class Table: public Element
{
private:
    std::string title;
public:
    Table(std::string title);

    void print();
    void add(Element* element);
    void remove(Element* element);
    Element* get(int index);
};


class TableOfContents: public Element
{
private:
    std::string title;
public:
    TableOfContents(std::string title);

    void print();
    void add(Element* element);
    void remove(Element* element);
    Element* get(int index);
};


class Section: public Element
{
private:
    std::vector<Element*> elementList;
protected:
    std::string title;
public:
    Section(std::string title);

    void print();
    void add(Element* element);
    void remove(Element* element);
    Element* get(int index);
};


class Book: public Section
{
private:
    std::vector<Author*> authorList;
public:
    explicit Book(std::string title);

    void addAuthor(Author* author);
    void print();
};