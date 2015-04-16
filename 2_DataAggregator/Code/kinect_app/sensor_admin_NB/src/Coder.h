/* 
 * File:   Encoder.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: Basic coder for encoding and decoding sensitive data.
 *                   Encoder is converting each character to ASCII, then adding
 *                   1 to it.  Decoder is performing the inverse operation.
 *
 * Created on April 7, 2015, 11:44 PM
 */

#ifndef CODER_H
#define	CODER_H

//#include <boost/filesystem.hpp>
//#include <boost/filesystem/fstream.hpp>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//using namespace boost::filesystem;

class Coder
{
private:
    vector<int> dataAsciiVec;
    
public:
    Coder();
    void encode(string userInput);
    string decode();
    ~Coder();
};

#endif	/* CODER_H */
