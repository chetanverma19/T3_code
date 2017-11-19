#ifndef WMAIN_H
#define WMAIN_H

#include "wx/wx.h"
#include "wx/image.h"

#include "WSortView.h"
#include "wxg/WMain_wxg.h"

// ----------------------------------------------------------------------------
// --- Global Constants and Variables

static const size_t g_framerate = 30;

// ----------------------------------------------------------------------------

class WMain : public WMain_wxg
{
public:
    enum {
        ID_RUN_FINISHED = wxID_HIGHEST + 2000
    };

    WMain(wxWindow* parent);
    ~WMain();

    /// launch selected algorithm
    bool        RunAlgorithm();

    /// abort running algorithm
    void        AbortAlgorithm();

    /// change array size via slider
    void        SetArraySize(size_t pos);

    /// change delay
    void        SetDelay(size_t pos);

    /// change sound sustain
    void        SetSoundSustain(size_t pos);

public:
    class RefreshTimer : public wxTimer
    {
        WMain&  wm;

    public:
        RefreshTimer(WMain* wmain);
        virtual void Notify();
    };

public:
    virtual void OnRunButton(wxCommandEvent &event);
    virtual void OnResetButton(wxCommandEvent &event);
    virtual void OnStepButton(wxCommandEvent &event);
    virtual void OnSoundButton(wxCommandEvent &event);
    virtual void OnRandomButton(wxCommandEvent &event);
    virtual void OnAboutButton(wxCommandEvent &event);
    virtual void OnSpeedSliderChange(wxScrollEvent &event);
    virtual void OnSoundSustainSliderChange(wxScrollEvent &event);
    virtual void OnInversionLabelClick(wxCommandEvent &event);
    virtual void OnArraySizeSliderChange(wxScrollEvent &event);
    virtual void OnAlgoList(wxCommandEvent &event);
    virtual void OnAlgoListDClick(wxCommandEvent &event);

    virtual void OnRunFinished(wxCommandEvent&);

    DECLARE_EVENT_TABLE();

public:

    /// g_framerate timer used to refresh the sortview.
    RefreshTimer* m_reftimer;

    /// the algorithm working thread
    class SortAlgoThread* m_thread;

    /// true if the algorithm terminates
    bool        m_thread_terminate;

    /// array size selected for new run
    size_t      m_array_size;
};

#endif // WMAIN_H

// ----------------------------------------------------------------------------
