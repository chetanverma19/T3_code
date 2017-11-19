/***************************************************************
 * Name:      T3Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2017-11-19
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef T3MAIN_H
#define T3MAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "T3App.h"


#include <wx/button.h>
#include <wx/statline.h>
class T3Dialog: public wxDialog
{
    public:
        T3Dialog(wxDialog *dlg, const wxString& title);
        ~T3Dialog();

    protected:
        enum
        {
            idBtnQuit = 1000,
            idBtnAbout
        };
        wxStaticText* m_staticText1;
        wxButton* BtnAbout;
        wxStaticLine* m_staticline1;
        wxButton* BtnQuit;

    private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};

#endif // T3MAIN_H
