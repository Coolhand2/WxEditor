/*
 * File:   App.cpp
 * Author: Mike
 *
 * Created on March 16, 2013, 1:37 AM
 */

#include <wx/frame.h>
#include "wxEditor.h"

bool wxEditor::OnInit(){
    wxFrame *frame = new wxFrame((wxFrame*)NULL, -1, _T("wxEditor"));
    frame->Show(true);
    SetTopWindow(frame);
    return true;
}