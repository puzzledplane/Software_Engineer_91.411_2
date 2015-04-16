#include "Coder.h"


Coder::Coder()
{
    ;
}


void Coder::encode(string userInput)
{
    for(size_t i = 0; i < userInput.length(); i++)
    {
        dataAsciiVec.push_back(userInput.at(i) );
        if(dataAsciiVec.at(i) < 33)
        {
            cerr << "invalid password" << endl;
        }
        else if(dataAsciiVec.at(i) >= 33 && dataAsciiVec.at(i) < 126)
        {
            dataAsciiVec.at(i) += 1;
        }
        else
        {
            cerr << "invalid password" << endl;
        }
    }
    
}


string Coder::decode()
{
    string answerTmp;
    string castTmp;
    
    //testing encoded output
    /*cout << "encoded password: ";
    for(size_t i = 0; i < dataAsciiVec.size(); i++) { cout << dataAsciiVec.at(i); }
    cout << endl;*/
    
    for(size_t i = 0; i < dataAsciiVec.size(); i++)
    {
        castTmp = (int) (dataAsciiVec.at(i) - 1);
        answerTmp.append(castTmp);
    }
    
    return answerTmp;
}


Coder::~Coder()
{
    ;
}
