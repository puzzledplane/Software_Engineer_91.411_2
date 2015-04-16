/* 
 * File:   AppStyles.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class loads enums from a json file to signify the
 *                   available styles.  It can dynamically load Qt style sheets
 *                   during runtime.  The user can create custom styles by
 *                   adding their new style name to the Styles.json file, and
 *                   adding their style_name.qss file in the qss directory.
 *
 * Reference: http://stackoverflow.com/questions/10632251/undefined-reference-to-template-function
 * 
 * Created on April 7, 2015, 6:29 PM
 */


#ifndef APPSTYLES_H
#define	APPSTYLES_H

#include <QWidget>

#include <iostream>

using namespace std;

namespace AppStyles
{
    enum Style
    {
        CLASSIC,
        TRANSPARENT,
        DARK_METAL,
        PEACH_PUFF
    };
    
    /**
     * This method sets the style of the GUI.
     * 
     * @param qwidgetChild templated class parameter; expects pointer to child
     *                     of class QWidget. 
     * @param style enum style type.
     */
    template<class X>
    void loadStyle(X* qwidgetChild, Style style);
}

#include "AppStyles.tcc"

#endif	/* APPSTYLES_H */

