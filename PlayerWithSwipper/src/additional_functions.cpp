#include "additional_functions.hpp"

using namespace std;

vector<string> split(string data, string separateur)
{
    vector<string> tab;
    size_t pos;
    if(separateur.length() > 0)
    {
        while ((pos = data.find(separateur)) != string::npos)
        {
            tab.push_back(data.substr(0, pos));
            data.erase(0, pos + separateur.length());
        }
    }
    tab.push_back(data);
    return tab;
}

vector<string> split(string data, char separateur)
{
    vector<string> tab;
    size_t pos;

    //cout << "test séparateur : " << data << endl;
    while ((pos = data.find(separateur)) != string::npos)
    {
        tab.push_back(data.substr(0, pos));
        data.erase(0, pos + 1);
    }

    tab.push_back(data);
    return tab;
}

void delay(int sec)
{
    QTime dieTime= QTime::currentTime().addSecs(sec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
