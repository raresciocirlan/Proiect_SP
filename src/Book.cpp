#include "../interface/Book.h"

std::string genRandomString(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}


Book::Book(std::string title) : Section(title){}
void Book::print()
{
    std::cout << "Book: " << title << std::endl;
    std::cout << "Author(s): " << std::endl;
    for(Author* author: authorList)
        author->print();
    std::cout << std::endl;
    Section::print();
}
void Book::addAuthor(Author* author)
{
    authorList.push_back(author);
}


Section::Section(std::string title)
{
    this->title = title;
}
void Section::print()
{
    std::cout << title << std::endl;
    for(Element* element: elementList)
        element->print();
}
void Section::add(Element* element)
{
    elementList.push_back(element);
}
void Section::remove(Element* element)
{
    elementList.erase(std::remove(elementList.begin(), elementList.end(), element), elementList.end());
}
Element* Section::get(int index)
{
    return elementList.at(index);
}


Image::Image(std::string url)
{
    this->url = url;
    imageContent = genRandomString(20);
    Sleep(5000);
}
std::string Image::getUrl(){return url;}
int Image::getDimension(){return imageContent.length();}
std::string Image::getPictureContent()
{
    return imageContent;
}
void Image::print(){}
void Image::add(Element* element){}
void Image::remove(Element* element){}
Element* Image::get(int index){return nullptr;}


ImageProxy::ImageProxy(std::string url)
{
    this->url = url;
    realImage = nullptr;
}
ImageProxy::~ImageProxy()
{
    delete[] realImage;
}
Image ImageProxy::loadImage()
{
    if(realImage == nullptr)
    {
        realImage = new Image(url);
        dimension = realImage->getDimension();
    }
    return *realImage;
}
std::string ImageProxy::getUrl()
{
    return url;
}
int ImageProxy::getDimension()
{
    return dimension;
}
std::string ImageProxy::getPictureContent(){return loadImage().getPictureContent();}
void ImageProxy::print()
{
    std::cout << getPictureContent() << std::endl;
}
void ImageProxy::add(Element* element){}
void ImageProxy::remove(Element* element){}
Element* ImageProxy::get(int index){return nullptr;}


AlignLeft::AlignLeft(int left)
{
    this->left = left;
}
void AlignLeft::render(std::string text)
{
    std::istringstream stream(text);
    std::string line;
    while (std::getline(stream, line))
    {
        for(int i = 0; i < left; i++)
            std::cout << " ";
        std::cout << line << std::endl;
    }
}


AlignRight::AlignRight(int right)
{
    this->right = right;
}
void AlignRight::render(std::string text)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    std::istringstream stream(text);
    std::string line;
    while (std::getline(stream, line))
    {
        for(int i = 0; i < columns - right - line.size(); i++)
            std::cout << " ";
        std::cout << line << std::endl;
    }
}

AlignCenter::AlignCenter(){}
void AlignCenter::render(std::string text)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    std::istringstream stream(text);
    std::string line;
    while (std::getline(stream, line))
    {
        for(int i = 0; i < (columns - line.size())/2; i++)
            std::cout << " ";
        std::cout << line << std::endl;
    }
}


Paragraph::Paragraph(std::string text)
{
    this->text = text;
    alignStrategy = nullptr;
}
void Paragraph::setAlignStrategy(AlignStrategy *alignStrategy)
{
    this->alignStrategy = alignStrategy;
}
void Paragraph::print()
{
    std::cout << "Paragraph: " << std::endl;
    if(alignStrategy != nullptr)
        alignStrategy->render(text);
    else
        std::cout << text << std::endl;
}
void Paragraph::add(Element* element){}
void Paragraph::remove(Element* element){}
Element* Paragraph::get(int index){return nullptr;}



Table::Table(std::string title)
{
    this->title = title;
}
void Table::print()
{
    std::cout << "Table with Title: " << title << std::endl;
}
void Table::add(Element* element){}
void Table::remove(Element* element){}
Element* Table::get(int index){return nullptr;}


TableOfContents::TableOfContents(std::string title)
{
    this->title = title;
}
void TableOfContents::print()
{
    std::cout << "TableOfContents with Title: " << title << std::endl;
}
void TableOfContents::add(Element* element){}
void TableOfContents::remove(Element* element){}
Element* TableOfContents::get(int index){return nullptr;}