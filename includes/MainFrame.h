/*
 * File:   MainFrame.h
 * Author: Mike
 *
 * Created on March 16, 2013, 1:48 AM
 */

#ifndef MAINFRAME_H
#define	MAINFRAME_H

#include <wx/frame.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/menu.h>

class MainFrame : public wxFrame {
private:
    wxTextCtrl *_text;
    wxString _documentPath;
    void _loadMenus();
    void _loadFrame();
    void _setupFrame();
    wxString _getFileTypes();
public:
    MainFrame(const wxString &title, const wxPoint &position, const wxSize &size);
    void newFile(wxCommandEvent &event);
    void openFile(wxCommandEvent &event);
    void saveFile(wxCommandEvent &event);
    void saveAs(wxCommandEvent &event);
    void closeFile(wxCommandEvent &event);
    void quit(wxCommandEvent &event);

    DECLARE_EVENT_TABLE()
};

enum {
    M_New = wxID_HIGHEST + 1,
    M_Open,
    M_Save,
    M_SaveAs,
    M_Close,
    M_Quit,
    E_Input
};

#endif	/* MAINFRAME_H */

