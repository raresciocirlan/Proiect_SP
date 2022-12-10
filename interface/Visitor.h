#pragma once
#include <iostream>
#include "Book.h"

class Book;
class Section;
class TableOfContents;
class Paragraph;
class ImageProxy;
class Image;
class Table;

class Visitor
{
public:
    virtual void visitBook(Book* book) = 0;
    virtual void visitSection(Section* section) = 0;
    virtual void visitTableOfContents(TableOfContents* tableOfContents) = 0;
    virtual void visitParagraph(Paragraph* paragraph) = 0;
    virtual void visitImageProxy(ImageProxy* imageProxy) = 0;
    virtual void visitImage(Image* image) = 0;
    virtual void visitTable(Table* table) = 0;
    virtual void print() = 0;
};