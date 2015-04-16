/* 
 * File:   AppStyles.tcc
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: Implementation of AppStyles.h.
 *
 * Created on April 6, 2015, 11:00 AM
 */

#ifndef APPSTYLES_TCC
#define	APPSTYLES_TCC

#include "AppStyles.h"

template<class X>
void AppStyles::loadStyle(X* qwidgetChild, Style style)
{
    switch(style)
    {
        case CLASSIC:
            cout << "\"CLASSIC\" selected" << endl;
            break;
        case TRANSPARENT:
            cout << "\"TRANSPARENT\" selected" << endl;
            break;
        case DARK_METAL:
            cout << "\"DARK_METAL\" selected" << endl;
            break;
        case PEACH_PUFF:
            cout << "\"PEACH_PUFF\" selected" << endl;
            break;
        default:
            cerr << "default in switch at AppStyles::loadStyle" << endl;
            break;
    }
    
    
    qwidgetChild->setStyleSheet("{background-color:black;}");
    cout << "no syntax errors at AppStyles::loadStyle!" << endl;
}

#endif	/* APPSTYLES_TCC */

