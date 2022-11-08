#include <iostream>
#include "../interface/Book.h"
int main()
{
    Section *cap1 = new Section("Capitolul 1");
    Paragraph *p1 = new Paragraph("Centered");
    cap1->add(p1);
    Paragraph *p2 = new Paragraph("Right Positioned");
    cap1->add(p2);
    Paragraph *p3 = new Paragraph("Left Positioned");
    cap1->add(p3);
    Paragraph *p4 = new Paragraph("Paragraph 4");
    cap1->add(p4);
    std::cout << "Printing without Alignment" << std::endl;
    cap1->print();
    p1->setAlignStrategy(new AlignCenter());
    p2->setAlignStrategy(new AlignRight(4));
    p3->setAlignStrategy(new AlignLeft(4));

    std::cout << "Printing without Alignment" << std::endl;
    cap1->print();
}