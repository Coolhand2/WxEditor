/*
 * File:   MainFrame.cpp
 * Author: Mike
 *
 * Created on March 16, 2013, 1:48 AM
 */

#include "MainFrame.h"

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
    _text = new wxTextCtrl(this, 0, _("Hello, World!"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH, wxDefaultValidator, wxTextCtrlNameStr);
    _menu = new wxMenuBar();
    SetMenuBar(_menu);
    CreateStatusBar(2);

    _populateMenu();

}

void MainFrame::_populateMenu(){

    wxMenu *fileMenu = new wxMenu();

    fileMenu->Append(M_New, _("&New"), _("Create New File"));
    fileMenu->Append(M_Open, _("&Open"), _("Open Another File"));
    fileMenu->Append(M_Close, _("&Close"), _("Close Current File"));
    fileMenu->AppendSeparator();
    fileMenu->Append(M_Save, _("&Save"), _("Save Current File"));
    fileMenu->Append(M_SaveAs, _("Save &As"), _("Save Current File Under New Name"));
    fileMenu->AppendSeparator();
    fileMenu->Append(M_Quit, _("&Quit"), _("Close The Application"));

    _menu->Append(fileMenu, _("&File"));
}

void MainFrame::newFile(wxCommandEvent& event){

}

void MainFrame::openFile(wxCommandEvent& event){

}

void MainFrame::saveFile(wxCommandEvent& event){

}

void MainFrame::saveAs(wxCommandEvent& event){

}

void MainFrame::closeFile(wxCommandEvent& event){

}

void MainFrame::quit(wxCommandEvent &event){
    Close(TRUE);
}