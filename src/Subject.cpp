#include "../interface/Subject.h"

void Subject::Attach(Observer* observer)
{
    observers.push_back(observer);
}

void Subject::Detach(Observer* observer)
{
    for (auto iter = observers.begin(); iter != observers.end(); ++iter)
    {
        if (*iter == observer) 
        {
            observers.erase(iter);
            break;
        }
    }
}

void Subject::Notify(const std::string& availability) 
{
    for (auto observer : observers)
    {
        observer->Update(availability);
    }
}