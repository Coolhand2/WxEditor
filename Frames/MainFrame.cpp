/*
 * File:   MainFrame.cpp
 * Author: Mike
 *
 * Created on March 16, 2013, 1:48 AM
 */

#include "MainFrame.h"
#include <sstream>
#include <iostream>
#include <wx/filedlg.h>

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(M_New, MainFrame::newFile)
    EVT_MENU(M_Open, MainFrame::openFile)
    EVT_MENU(M_Save, MainFrame::saveFile)
    EVT_MENU(M_SaveAs, MainFrame::saveAs)
    EVT_MENU(M_Close, MainFrame::closeFile)
    EVT_MENU(M_Quit, MainFrame::quit)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString &title, const wxPoint &position, const wxSize &size)
: wxFrame((wxFrame *) NULL, -1, title, position, size){
    _setupFrame();
    _loadFrame();
}

void MainFrame::_setupFrame(){
    CreateStatusBar(2);
}

void MainFrame::_loadFrame(){
    _loadMenus();
    _text = new wxTextCtrl(this, 0, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH, wxDefaultValidator, wxTextCtrlNameStr);
}

void MainFrame::_loadMenus(){
    wxMenuBar *menu = new wxMenuBar();
    wxMenu *fileMenu = new wxMenu();

    fileMenu->Append(M_New, _("&New"), _("Create New File"));
    fileMenu->Append(M_Open, _("&Open"), _("Open Another File"));
    fileMenu->Append(M_Close, _("&Close"), _("Close Current File"));
    fileMenu->AppendSeparator();
    fileMenu->Append(M_Save, _("&Save"), _("Save Current File"));
    fileMenu->Append(M_SaveAs, _("Save &As"), _("Save Current File Under New Name"));
    fileMenu->AppendSeparator();
    fileMenu->Append(M_Quit, _("&Quit"), _("Close The Application"));

    menu->Append(fileMenu, _("&File"));
    SetMenuBar(menu);
}

wxString MainFrame::_getFileTypes(){
    std::stringstream ss;
    ss << "Text Files (*.txt)|*.txt|"
       << "C++ Source Files (*.cpp, *.cxx, *.cc, *.c)|*.cpp;*.cxx;*.cc;*.c|"
       << "C++ Header Files (*.hpp, *.hxx, *.hh, *.h)|*.hpp;*.hxx;*.hh;*.h|"
       << "C Source Files (*.c)|*.c|"
       << "C Header Files (*.h)|*.h|"
       << "PHP Source Files (*.php)|*.php|"
       << "Java Source Files (*.java)|*.java|"
       << "XML Files (*.xml)|*.xml";
    std::string str = ss.str();
    wxString wxs(str.c_str(), wxConvUTF8);
    return wxs;
}

void MainFrame::newFile(wxCommandEvent& event){
    _text->Clear();
    _documentPath = _("");
    SetTitle(_("Edit - New *"));
}

void MainFrame::openFile(wxCommandEvent& event){
    wxFileDialog dialog(this, _("Choose A File To Open"), wxEmptyString, wxEmptyString, _getFileTypes(), wxFD_OPEN, wxDefaultPosition);
    if(dialog.ShowModal() == wxID_OK){
        _documentPath = dialog.GetPath();
        _text->LoadFile(_documentPath);
        SetTitle(wxString(_("Edit - ")) << dialog.GetFilename());
    }
}

void MainFrame::saveFile(wxCommandEvent& event){
    if( !_documentPath.IsEmpty() ) {
        _text->SaveFile(_documentPath);
    } else {
        saveAs(event);
    }
}

void MainFrame::saveAs(wxCommandEvent& event){
    wxFileDialog dialog(this, _("Save File As"), wxEmptyString, wxEmptyString, _getFileTypes(), wxFD_SAVE| wxFD_OVERWRITE_PROMPT, wxDefaultPosition);
    if(dialog.ShowModal() == wxID_OK){
        _documentPath = dialog.GetPath();
        _text->SaveFile(_documentPath);
        SetTitle(wxString(_("Edit - ")) << dialog.GetFilename());
    }
}

void MainFrame::closeFile(wxCommandEvent& event){
    if( _text->IsModified() ){
        saveFile(event);
    }
    newFile(event);
}

void MainFrame::quit(wxCommandEvent &event){
    closeFile(event);
    Close(TRUE);
}