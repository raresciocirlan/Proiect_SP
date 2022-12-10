#include "../interface/VisitContentVisitor.h"

int VisitContentVisitor::nrOfImages = 0;
int VisitContentVisitor::nrOfTables = 0;
int VisitContentVisitor::nrOfParagraphs = 0;

void VisitContentVisitor::visitBook(Book* book){

}
void VisitContentVisitor::visitSection(Section* section){
    for(Element* element: section->elementList)
        if(dynamic_cast<Image*>(element))
            this->visitImage(dynamic_cast<Image*>(element));
        else if(dynamic_cast<ImageProxy*>(element))
            this->visitImageProxy(dynamic_cast<ImageProxy*>(element));
        else if(dynamic_cast<Table*>(element))
            this->visitTable(dynamic_cast<Table*>(element));
        else if(dynamic_cast<TableOfContents*>(element))
            this->visitTableOfContents(dynamic_cast<TableOfContents*>(element));
        else if(dynamic_cast<Paragraph*>(element))
            this->visitParagraph(dynamic_cast<Paragraph*>(element));
        
}
void VisitContentVisitor::visitTableOfContents(TableOfContents* tableOfContents){
    VisitContentVisitor::nrOfTables++;
}
void VisitContentVisitor::visitParagraph(Paragraph* paragraph){
    VisitContentVisitor::nrOfParagraphs++;

}
void VisitContentVisitor::visitImageProxy(ImageProxy* imageProxy){
    VisitContentVisitor::nrOfImages++;
}
void VisitContentVisitor::visitImage(Image* image){
    VisitContentVisitor::nrOfImages++;
}
void VisitContentVisitor::visitTable(Table* table){
    VisitContentVisitor::nrOfTables++;
}
void VisitContentVisitor::print(){
    std::cout << "Book Statistics: " << std::endl;;
    std::cout << "*** Number of images: " << this-> nrOfImages << std::endl;
    std::cout << "*** Number of tables: " << this -> nrOfTables << std::endl;
    std::cout << "*** Number of paragraphs: " << this -> nrOfParagraphs << std::endl;
}