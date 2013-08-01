#include <wx/wx.h>
#include "Mainframe.h"
#include "Panels.h"
class MyApp : public wxApp
{
public:

    LeftPanel *m_lp;
    RightPanel *m_rp;

    virtual bool OnInit();
    wxPanel *mainPanel;
    BasicGLPane *glPane;
};




