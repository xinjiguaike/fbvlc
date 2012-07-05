/**********************************************************\

  Auto-generated FBVLC.h

  This file contains the auto-generated main plugin object
  implementation for the FireBreathed VLC project

\**********************************************************/
#ifndef H_FBVLCPLUGIN
#define H_FBVLCPLUGIN

#include "PluginWindow.h"
#include "PluginEvents/MouseEvents.h"
#include "PluginEvents/AttachedEvent.h"

#include "PluginCore.h"

#include <vlc/vlc.h>

#include "vlc_player.h"

FB_FORWARD_PTR(FBVLC)
class FBVLC
    : public FB::PluginCore,
      protected vlc_player,
{
public:
    static void StaticInitialize();
    static void StaticDeinitialize();

public:
    FBVLC();
    virtual ~FBVLC();

public:
    void onPluginReady();
    void shutdown();
    virtual FB::JSAPIPtr createJSAPI();
    // If you want your plugin to always be windowless, set this to true
    // If you want your plugin to be optionally windowless based on the
    // value of the "windowless" param tag, remove this method or return
    // FB::PluginCore::isWindowless()
    virtual bool isWindowless() { return true; }

    BEGIN_PLUGIN_EVENT_MAP()
        //EVENTTYPE_CASE(FB::MouseDownEvent, onMouseDown, FB::PluginWindow)
        //EVENTTYPE_CASE(FB::MouseUpEvent, onMouseUp, FB::PluginWindow)
        //EVENTTYPE_CASE(FB::MouseMoveEvent, onMouseMove, FB::PluginWindow)
        //EVENTTYPE_CASE(FB::MouseMoveEvent, onMouseMove, FB::PluginWindow)
        EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindow)
        EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindow)
        EVENTTYPE_CASE(FB::RefreshEvent, onRefreshEvent, FB::PluginWindowlessWin)
    END_PLUGIN_EVENT_MAP()

    /** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
    //virtual bool onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *);
    //virtual bool onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *);
    //virtual bool onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *);
    virtual bool onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *);
    virtual bool onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *);
    virtual bool onRefreshEvent(FB::RefreshEvent *evt, FB::PluginWindowlessWin *);
    /** END EVENTDEF -- DON'T CHANGE THIS LINE **/

public:
    libvlc_instance_t* getLibVlc()
        { return m_libvlc; };
    vlc_player& get_player()
        { return *static_cast<vlc_player*>(this); };

protected:
    virtual void on_player_action( vlc_player_action_e );

private:
    //for libvlc_video_set_format_callbacks
    static unsigned video_format_proxy(void **opaque, char *chroma,
                                       unsigned *width, unsigned *height,
                                       unsigned *pitches, unsigned *lines)
        { return reinterpret_cast<FBVLC*>(*opaque)->video_format_cb(chroma,
                                                                  width, height,
                                                                  pitches, lines); }
    static void video_cleanup_proxy(void *opaque)
        { reinterpret_cast<FBVLC*>(opaque)->video_cleanup_cb(); };

    unsigned video_format_cb(char *chroma,
                             unsigned *width, unsigned *height,
                             unsigned *pitches, unsigned *lines);
    void video_cleanup_cb();
    //end (for libvlc_video_set_format_callbacks)

    //for libvlc_video_set_callbacks
    static void* video_fb_lock_proxy(void *opaque, void **planes)
        { return reinterpret_cast<FBVLC*>(opaque)->video_lock_cb(planes); }
    static void  video_fb_unlock_proxy(void *opaque, void *picture, void *const *planes)
        { reinterpret_cast<FBVLC*>(opaque)->video_unlock_cb(picture, planes); }
    static void  video_fb_display_proxy(void *opaque, void *picture)
        { reinterpret_cast<FBVLC*>(opaque)->video_display_cb(picture); }

    void* video_lock_cb(void **planes);
    void  video_unlock_cb(void *picture, void *const *planes);
    void  video_display_cb(void *picture);
    //end (for libvlc_video_set_callbacks)

private:
    libvlc_instance_t* m_libvlc;
    std::vector<char>  m_frame_buf;
    unsigned int      m_media_width;
    unsigned int      m_media_height;
};

#endif

