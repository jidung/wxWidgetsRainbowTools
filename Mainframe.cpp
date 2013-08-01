#include "Mainframe.h"

BEGIN_EVENT_TABLE(BasicGLPane, wxGLCanvas)
EVT_MOTION(BasicGLPane::mouseMoved)
EVT_LEFT_DOWN(BasicGLPane::mouseDown)
EVT_LEFT_UP(BasicGLPane::mouseReleased)
EVT_RIGHT_DOWN(BasicGLPane::rightClick)
EVT_LEAVE_WINDOW(BasicGLPane::mouseLeftWindow)
EVT_SIZE(BasicGLPane::resized)
EVT_KEY_DOWN(BasicGLPane::keyPressed)
EVT_KEY_UP(BasicGLPane::keyReleased)
EVT_MOUSEWHEEL(BasicGLPane::mouseWheelMoved)
EVT_PAINT(BasicGLPane::render)
END_EVENT_TABLE()

Mainframe::Mainframe(const wxString& title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
{
    
    wxImage::AddHandler( new wxPNGHandler );
    

    wxBitmap sun(wxT("images/icon_sun.png"), wxBITMAP_TYPE_PNG);
    wxBitmap water(wxT("images/icon_water.png"), wxBITMAP_TYPE_PNG);
    wxBitmap exit(wxT("images/icon_exit.png"), wxBITMAP_TYPE_PNG);
    
    wxToolBar *toolbar = CreateToolBar();


    toolbar->AddTool(wxID_ANY, sun, wxT("Place Lightsource"));
    toolbar->AddTool(wxID_ANY, water, wxT("Place Water Droplets"));
    toolbar->AddTool(wxID_EXIT, exit, wxT("Exit application"));
    toolbar->Realize();

    Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED,
            wxCommandEventHandler(Mainframe::OnQuit));
    
    Connect(wxID_ANY, wxEVT_MOTION, wxMouseEventHandler(BasicGLPane::mouseMoved));

        Connect(wxID_ANY, wxEVT_LEFT_DOWN, wxMouseEventHandler(BasicGLPane::mouseDown));

    Centre();
    
    
}

void Mainframe::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}




