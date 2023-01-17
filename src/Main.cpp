#include <iostream>
#include "../interface/VisitContentVisitor.h"
#include "../interface/Customer.h"

int main()
{
    Section *cap1 = new Section("Chapter 1");
    Paragraph *p1 = new Paragraph("Paragraph 1");
    cap1->add(p1);
    Paragraph *p2 = new Paragraph("Paragraph 2");
    cap1->add(p2);
    Paragraph *p3 = new Paragraph("Paragraph 3");
    cap1->add(p3);
    Paragraph *p4 = new Paragraph("Paragraph 4");
    cap1->add(p4);
    cap1->add(new ImageProxy("ImageOne"));
    cap1->add(new Image("ImageTwo"));
    cap1->add(new Paragraph("Some text"));
    cap1->add(new Table("Table 1"));
    VisitContentVisitor *stats = new VisitContentVisitor();
    cap1->accept(stats);
    stats->print();

    Book book1("The Hobbit");

    Customer customer1("Paul");
    Customer customer2("Daniel");
    book1.Attach(&customer1);
    book1.Attach(&customer2);

    book1.SetAvailability("limited");
    book1.SetAvailability("out of stock");

    book1.Detach(&customer1);

    book1.SetAvailability("available");
}