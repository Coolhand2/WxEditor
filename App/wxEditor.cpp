/*
 * File:   App.cpp
 * Author: Mike
 *
 * Created on March 16, 2013, 1:37 AM
 */

#include <wx/frame.h>
#include "wxEditor.h"
#include "MainFrame.h"

bool wxEditor::OnInit(){
    wxFrame *frame = new MainFrame(_("wxEditor"), wxDefaultPosition, wxSize(800, 600));
    frame->Show(true);
    SetTopWindow(frame);
    return true;
}