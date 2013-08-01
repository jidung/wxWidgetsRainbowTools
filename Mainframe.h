#include <wx/wx.h>
#include "BasicGLPane.h"

class Mainframe : public wxFrame
{
public:
    
    Mainframe(const wxString& title);
    
    void OnQuit(wxCommandEvent& event);
    
    
};

