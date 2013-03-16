/*
 * File:   App.h
 * Author: Mike
 *
 * Created on March 16, 2013, 1:37 AM
 */

#ifndef WXEDITOR_H
#define	WXEDITOR_H

#include <wx/app.h>

class wxEditor : public wxApp
{
public:
    virtual bool OnInit();
};

DECLARE_APP(wxEditor);

#endif	/* WXEDITOR_H */

