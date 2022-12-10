#pragma once
#include <iostream>
#include "Visitor.h"

class VisitContentVisitor: public Visitor
{
private:
    static int nrOfImages;
    static int nrOfTables;
    static int nrOfParagraphs;
public:
    void visitBook(Book* book);
    void visitSection(Section* section);
    void visitTableOfContents(TableOfContents* tableOfContents);
    void visitParagraph(Paragraph* paragraph);
    void visitImageProxy(ImageProxy* imageProxy);
    void visitImage(Image* image);
    void visitTable(Table* table);
    void print();
};