
---

# HTML page embedding #

```
<object type="application/x-fb-vlc" width="320" height="240">
<param name="windowless" value="true" />
</object>
```

### HTML `<object>` tag attributes: ###
  * **`width`**: Specifies the width of the plugin.
  * **`height`**: Specifies the height of the plugin.
  * **`id`**: DOM id.
  * **`name`**: DOM name.

### FBVLC specific paremeters: ###
  * **`autoplay`**, **`autostart`**: Specifies whether the plugin starts playing on load. Default: "true".
  * **`allowfullscreen`**, **`allowfullscreen`**, **`allow-fullscreen`**, **`fullscreenenabled`**, **`fullscreen-enabled`**: Specifies whether the user can switch into fullscreen mode. **Only for windowed mode.** Default: ''true''.
  * **`toolbar`**: Specifies whether the toolbar is shown by default. **Only for windowed mode.** Default: "true".
  * **`bgcolor`**: Specifies the background color of the video player. Default: "#000000".
  * **`network-caching`**: Specifies сaching value for network resources, in milliseconds.
  * **`mute`**: Specifies whether the audio volume is initially muted. Default: "false".
  * **`loop`**, **`autoloop`**: Specifies whether the video loops on end. Default: "false".
  * **`target`**, **`mrl`**, **`filename`**, **`src`**: Specifies the source location ([MRL](http://wiki.videolan.org/Media_resource_locator)) of the video to load.
  * **`windowless`**: Specifies whether windowed or windowless mode is used. Default: "false".
  * **`adjust-filter`**: Specifies whether "adjust" video filter is enabled (same as libvlc "--video-filter=adjust" option). Default: "false".
  * **`marquee-filter`**: Specifies whether "marquee" filter is enabled (same as libvlc "--sub-filter=marq" option). Default: "false".
  * **`logo-filter`**: Specifies whether "logo" filter is enabled (same as libvlc "--sub-filter=logo" option). Default: "false".
  * **`debug`**: Specifies whether debug mode is enabled (same as libvlc "--vvv" option). Default: "false".
  * **`fullscreen-toolbar`**: Specifies whether toolbar in fullscreen mode is enabled. **Only for windowed mode.** Default: "true". **Available from FBVLC v.0.0.2.0**
  * **`native-scaling`**: Specifies whether native scaling for windowless mode is enabled. Default: "false". **Available from FBVLC v.0.0.2.0**
  * **`use-proxy`**: Specifies whether http proxy setting from browser will be used. Default: "true". **Available from FBVLC v.0.0.2.0**

---


# Javascript API description #

## Root object ##

### read-only properties: ###
  * **`.version`**: returns FBVLC version.
  * **`.vlcVersion`**: returns libvlc version using by FBVLC.
  * **`.playing`**:
  * **`.length`**:
  * **`.state`**: returns current state.

### read-only attributes: ###
  * **`.NothingSpecial`**: **Available from FBVLC v.0.4.0**.
  * **`.Opening`**: **Available from FBVLC v.0.4.0**.
  * **`.Buffering`**: **Available from FBVLC v.0.4.0**.
  * **`.Playing`**: **Available from FBVLC v.0.4.0**.
  * **`.Paused`**: **Available from FBVLC v.0.4.0**.
  * **`.Stopped`**: **Available from FBVLC v.0.4.0**.
  * **`.Ended`**: **Available from FBVLC v.0.4.0**.
  * **`.Error`**: **Available from FBVLC v.0.4.0**.

### read/write properties: ###
  * **`.position`**:
  * **`.time`**:
  * **`.volume`**:
  * **`.bgcolor`**:
  * **`.fullscreen`**:

### methods: ###
  * **`.play(mrl)`**:
  * **`.pause()`**: **Available from FBVLC v.0.0.5**.
  * **`.togglePause()`**:
  * **`.stop()`**:
  * **`.toggleMute()`**:
  * **`.toggleFullscreen()`**: **Only for windowed mode.**

### events: ###
  * **`.MediaPlayerMediaChanged`**: **Available from FBVLC v.0.1.0**.
  * **`.MediaPlayerNothingSpecial`**: vlc is in idle state doing nothing but waiting for a command to be issued.
  * **`.MediaPlayerOpening`**: vlc is opening an media resource locator (MRL).
  * **`.MediaPlayerBuffering( percents )`**: vlc is buffering. **_percents_ available from FBVLC v.0.1.4**
  * **`.MediaPlayerPlaying`**: vlc is playing a media.
  * **`.MediaPlayerPaused`**: vlc is in paused state.
  * **`.MediaPlayerForward`**: vlc is fastforwarding through the media (works only when an input supports forward playback).
  * **`.MediaPlayerBackward`**: vlc is going backwards through the media (works only when an input supports backwards playback).
  * **`.MediaPlayerEncounteredError`**: vlc has encountered an error and is unable to continue.
  * **`.MediaPlayerEndReached`**: vlc has reached the end of current playlist.
  * **`.MediaPlayerStopped`**:
  * **`.MediaPlayerTimeChanged( seconds )`**: time has changed. **_seconds_ available from FBVLC v.0.1.4**
  * **`.MediaPlayerPositionChanged( position )`**: media position has changed. **_position_ available from FBVLC v.0.1.4**
  * **`.MediaPlayerSeekableChanged( seekable )`**: media seekable flag has changed. **_seekable_ available from FBVLC v.0.1.4**
  * **`.MediaPlayerPausableChanged( pausable )`**: media pausable flag has changed. **_pausable_ available from FBVLC v.0.1.4**

### subobject properties: ###
  * **`.input`**: Access input properties.
  * **`.audio`**: Access audio properties.
  * **`.video`**: Access video properties.
  * **`.subtitle`**: Access subtitle properties.
  * **`.playlist`**: Access playlist properties.
  * **`.mediaDescription`**: Access media info properties.


---

## Input object ##

### read-only properties: ###
  * **`.input.length`**: length of the input file in number of milliseconds. 0 is returned for 'live' streams or clips whose length cannot be determined by VLC. It returns -1 if no input is playing.
  * **`.input.fps`**: frames per second returned as a float (typically 60.0, 50.0, 23.976, etc...).
  * **`.input.hasVout`**: a boolean that returns true when the video is being displayed, it returns false when video is not displayed.
  * **`.input.state`**: returns current state.

### read/write properties: ###
  * **`.input.position`**: normalized position in multimedia stream item given as a float value between [0.0 - 1.0].
  * **`.input.time`**: the absolute position in time given in milliseconds, this property can be used to seek through the stream.
  * **`.input.rate`**: input speed given as float (1.0 for normal speed, 0.5 for half speed, 2.0 for twice as fast, etc.).


---

## Video object ##

### read-only properties: ###
  * **`.video.width`**: returns the horizontal size of the video.
  * **`.video.height`**: returns the vertical size of the video.
  * **`.video.trackCount`**: **Available from FBVLC v.0.0.7**.

### read/write properties: ###
  * **`.video.track`**: **Available from FBVLC v.0.0.7**.
  * **`.video.fullscreen`**: when set to true the video will be displayed in fullscreen mode, when set to false the video will be shown inside the video output size. **Only for windowed mode.**
  * **`.video.aspectRatio`**: get and set the aspect ratio to use in the video screen. The property takes a string as input value. Typical values are: "1:1", "4:3", "16:9", "16:10", "221:100" and "5:4"
  * **`.video.crop`**:
  * **`.video.subtitle`**: get and set the subtitle track to show on the video screen. The property takes an integer as input value [1..65535]. If subtitle track is set to 0, the subtitles will be disabled. If set to a value outside the current subtitle tracks range, then it will return -1.
  * **`.video.teletext`**: get and set teletext page to show on the video stream. This will only work if a teletext elementary stream is available in the video stream. The property takes an integer as input value [0..999] for indicating the teletext page to view, setting the value to 0 means hide teletext. On error it will return -1.
  * **`.video.contrast`**:
  * **`.video.brightness`**:
  * **`.video.hue`**:
  * **`.video.saturation`**:
  * **`.video.gamma`**:

> note: contrast/brightness/hue/saturation/gamma is valid only with adjust-filter=true startup option.

### methods: ###
  * **`.video.toggleFullscreen()`**: toggle the fullscreen mode based on the previous setting. **Only for windowed mode.**
  * **`.video.toggleTeletext()`**: toggle the teletext page to overlay transparent or not, based on the previous setting.

### subobject properties: ###
  * **`.video.marquee`**: Access marquee video filter properties.
  * **`.video.logo`**: Access logo video filter properties.
  * **`.video.deinterlace`**:


---

## Audio object ##

### readonly properties: ###
  * **`.audio.count`**: returns the number of audio track available.

### read-only attributes: ###
  * **`.audio.Error`**: **Available from FBVLC v.0.1.4**
  * **`.audio.Stereo`**: **Available from FBVLC v.0.1.4**
  * **`.audio.ReverseStereo`**: **Available from FBVLC v.0.1.4**
  * **`.audio.Left`**: **Available from FBVLC v.0.1.4**
  * **`.audio.Right`**: **Available from FBVLC v.0.1.4**
  * **`.audio.Dolby`**: **Available from FBVLC v.0.1.4**

### read/write properties: ###
  * **`.audio.mute`**: boolean value to mute and unmute the audio.
  * **`.audio.volume`**: a value between [0-200] which indicates a percentage of the volume.
  * **`.audio.track`**: a value between [1-65535] which indicates the audio track to play or that is playing. a value of 0 means the audio is/will be disabled.
  * **`.audio.channel`**: integer value between [1-5] that indicates which audio channel mode is used.

### methods: ###
  * **`.audio.toggleMute()`**: boolean toggle that mutes and unmutes the audio based upon the previous state.
  * **`.audio.description(i)`**: give the i-th audio track name. 0 corresponds to disable and 1 to the first audio track.


---

## Playlist object ##

### read-only attributes: ###
  * **`.playlist.Normal`**: play till last item. **Available from FBVLC v.0.1.4**
  * **`.playlist.Loop`**: infinite repeat all items. **Available from FBVLC v.0.1.4**
  * **`.playlist.Single`**: play current playlist item and stop. **Available from FBVLC v.0.1.4**

### read-only properties: ###
  * **`.playlist.itemCount`**: number that returns the amount of items currently in the playlist.
  * **`.playlist.isPlaying`**: a boolean that returns true if the current playlist item is playing and false when it is not playing.
  * **`.playlist.currentItem`**: returns current item index **Available from FBVLC v.0.0.5**.

### read/write properties: ###
  * **`.playlist.mode`**: playlist mode. **Available from FBVLC v.0.1.4**

### methods: ###
  * **`.playlist.add(mrl)`**: add a playlist item.
  * **`.playlist.addWithOptions(mrl, options)`**: add a playlist item with options.
  * **`.playlist.play()`**: start playing the current playlist item.
  * **`.playlist.playItem(i)`**: start playing the item whose identifier is i.
  * **`.playlist.setCurrentItem(i)`**: **Available from FBVLC v.0.0.6**.
  * **`.playlist.pause()`**: **Available from FBVLC v.0.0.5**.
  * **`.playlist.togglePause()`**: toggle the pause state for the current playlist item.
  * **`.playlist.stop()`**: stop playing the current playlist item.
  * **`.playlist.next()`**: iterate to the next playlist item.
  * **`.playlist.prev()`**: iterate to the previous playlist item.
  * **`.playlist.clear()`**: empty the current playlist, all items will be deleted from the playlist.
  * **`.playlist.removeItem(i)`**: remove the item from playlist whose identifier is i.

### subobject properties: ###
  * **`.playlist.items`**: return the playlist items collection.


---

## Playlist items object ##

### read-only properties: ###
  * **`.playlist.items.count`**: number of items currently in the playlist

### methods: ###
  * **`.playlist.items.clear()`**: empty the current playlist, all items will be deleted from the playlist.
  * **`.playlist.items.remove(i)`**: remove the item whose identifier is i from playlist.
  * **`.playlist.items[i]`**: return [MediaDescription](#MediaDescription_Object.md) object for i-th item. **Available from FBVLC v.0.1.2.1**


---

## Subtitle object ##

### read-only properties: ###
  * **`.subtitle.count`**: returns the number of subtitle available.

### read/write properties: ###
  * **`.subtitle.track`**: get and set the subtitle track to show on the video screen. The property takes an integer as input value [1..65535]. If subtitle track is set to 0, the subtitles will be disabled. If set to a value outside the current subtitle tracks range, then it will return -1.

### methods: ###
  * **`.subtitle.description(i)`**: give the i-th subtitle name. 0 correspond to disable and 1 to the first subtitle.


---

## Deinterlace Object ##

### methods: ###
  * **`.video.deinterlace.enable("my_mode")`**: enable deinterlacing with my\_mode. You can enable it with "blend", "bob", "discard", "linear", "mean", "x", "yadif" or "yadif2x" mode. Enabling too soon deinterlacing may cause some problems. You have to wait that all variable are available before enabling it.
  * **`.video.deinterlace.disable()`**: disable deinterlacing.


---

## Marquee Object ##

### read/write properties: ###
  * **`.video.marquee.text`**: display my text on the screen.
  * **`.video.marquee.color`**: change the text color. val is the new color to use (WHITE=0x000000, BLACK=0xFFFFFF, RED=0xFF0000, GREEN=0x00FF00, BLUE=0x0000FF...).
  * **`.video.marquee.opacity`**: change the text opacity, val is defined from 0 (completely transparent) to 255 (completely opaque).
  * **`.video.marquee.position`**: change the text position ("center", "left", "right", "top", "top-left", "top-right", "bottom", "bottom-left", "bottom-right").
  * **`.video.marquee.refresh`**: change the marquee refresh period.
  * **`.video.marquee.size`**: val define the new size for the text displayed on the screen. If the text is bigger than the screen then the text is not displayed.
  * **`.video.marquee.timeout`**: change the timeout value. val is defined in ms, but 0 value correspond to unlimited.
  * **`.video.marquee.x`**: change text abscissa.
  * **`.video.marquee.y`**: change text ordinate.

### methods: ###
  * **`.video.marquee.enable()`**: enable marquee filter.
  * **`.video.marquee.disable()`**: disable marquee filter.


---

## Logo Object ##

### read/write properties: ###
  * **`.video.logo.opacity`**: change the picture opacity, val is defined from 0 (completely transparent) to 255 (completely opaque).
  * **`.video.logo.position`**: change the text position ("center", "left", "right", "top", "top-left", "top-right", "bottom", "bottom-left", "bottom-right").
  * **`.video.logo.delay`**: display each picture for a duration of 1000 ms (default) before displaying the next picture.
  * **`.video.logo.repeat`**: number of loops for picture animation (-1=continuous, 0=disabled, n=n-times). The default is -1 (continuous).
  * **`.video.logo.x`**: change the x-offset for displaying the picture counting from top-left on the screen.
  * **`.video.logo.y`**: change the y-offset for displaying the picture counting from top-left on the screen.

### methods: ###
  * **`.video.logo.enable()`**: enable logo video filter.
  * **`.video.logo.disable()`**: disable logo video filter.
  * **`.video.logo.file("file.png")`**: display my file.png as logo on the screen.


---

## MediaDescription Object ##

### read-only properties: ###
  * **`.mediaDescription.title`**: returns title meta information field.
  * **`.mediaDescription.artist`**: returns artist meta information field.
  * **`.mediaDescription.genre`**: returns genre meta information field.
  * **`.mediaDescription.copyright`**: returns copyright meta information field.
  * **`.mediaDescription.album`**: returns album meta information field.
  * **`.mediaDescription.trackNumber`**: returns trackNumber meta information field.
  * **`.mediaDescription.description`**: returns description meta information field.
  * **`.mediaDescription.rating`**: returns rating meta information field.
  * **`.mediaDescription.date`**: returns date meta information field.
  * **`.mediaDescription.setting`**: returns setting meta information field.
  * **`.mediaDescription.URL`**: returns URL meta information field.
  * **`.mediaDescription.language`**: returns language meta information field.
  * **`.mediaDescription.nowPlaying`**: returns nowPlaying meta information field.
  * **`.mediaDescription.publisher`**: returns publisher meta information field.
  * **`.mediaDescription.encodedBy`**: returns encodedBy meta information field.
  * **`.mediaDescription.artworkURL`**: returns artworkURL meta information field.
  * **`.mediaDescription.trackID`**: returns trackID meta information field.
  * **`.mediaDescription.mrl`**: **Available from FBVLC v.0.1.2.1**.


---

## Deprecated/Removed ##

### Removed from FBVLC v.0.1.2.1 ###
  * **`.PlayEvent`**
  * **`.PauseEvent`**
  * **`.StopEvent`**
  * **`.CurrentChangedEvent`**: **Was available from FBVLC v.0.0.6**.

### Deprecated from FBVLC v.0.1.4 ###
  * **`.libvlc_NothingSpecial`**
  * **`.libvlc_Opening`**
  * **`.libvlc_Buffering`**
  * **`.libvlc_Playing`**
  * **`.libvlc_Paused`**
  * **`.libvlc_Stopped`**
  * **`.libvlc_Ended`**
  * **`.libvlc_Error`**

  * **`.audio.libvlc_AudioChannel_Error`**
  * **`.audio.libvlc_AudioChannel_Stereo`**
  * **`.audio.libvlc_AudioChannel_RStereo`**
  * **`.audio.libvlc_AudioChannel_Left`**
  * **`.audio.libvlc_AudioChannel_Right`**
  * **`.audio.libvlc_AudioChannel_Dolbys`**


---

This documentation is heavily based on http://wiki.videolan.org./Documentation:WebPlugin.