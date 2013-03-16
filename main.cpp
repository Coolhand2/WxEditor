/*
 * File:   main.cpp
 * Author: Mike
 *
 * Created on March 16, 2013, 12:25 AM
 */

#include <iostream>

#include <wx/wx.h>

using namespace std;

/*
 *
 */

class wxEditor : public wxApp
{
public:
    virtual bool OnInit();
};

DECLARE_APP(wxEditor);
IMPLEMENT_APP(wxEditor);

bool wxEditor::OnInit(){
    wxFrame *frame = new wxFrame((wxFrame*)NULL, -1, _T("wxEditor"));
    frame->CreateStatusBar();
    frame->SetStatusText(_T("Hello, World!"));
    frame->Show(true);
    SetTopWindow(frame);
    return true;
}