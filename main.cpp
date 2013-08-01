#include "main.h"


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()

{
    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    
    Mainframe *mainframe = new Mainframe(wxT("Mainframe"));
    
    int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};
    glPane = new BasicGLPane( (wxFrame*) mainframe, args);
    
    mainPanel = new wxPanel(mainframe, wxID_ANY);
    
    m_lp = new LeftPanel(mainPanel);

    sizer->Add(m_lp, 1, wxEXPAND | wxALL, 5);
    sizer->Add(glPane, 10, wxEXPAND | wxALL, 5);

    
    mainframe->SetSizer(sizer);
    mainframe->Show(true);
    
    return true;
}




