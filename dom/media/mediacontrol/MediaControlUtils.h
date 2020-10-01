/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef DOM_MEDIA_MEDIACONTROL_MEDIACONTROLUTILS_H_
#define DOM_MEDIA_MEDIACONTROL_MEDIACONTROLUTILS_H_

#include "MediaController.h"
#include "MediaControlKeysEvent.h"
#include "mozilla/dom/ChromeUtilsBinding.h"
#include "mozilla/Logging.h"

extern mozilla::LazyLogModule gMediaControlLog;

namespace mozilla {
namespace dom {

inline const char* ToMediaControlKeysEventStr(MediaControlKeysEvent aKeyEvent) {
  switch (aKeyEvent) {
    case MediaControlKeysEvent::ePause:
      return "Pause";
    case MediaControlKeysEvent::ePlay:
      return "Play";
    case MediaControlKeysEvent::ePlayPause:
      return "Play & pause";
    case MediaControlKeysEvent::ePrevTrack:
      return "Previous track";
    case MediaControlKeysEvent::eNextTrack:
      return "Next track";
    case MediaControlKeysEvent::eSeekBackward:
      return "Seek backward";
    case MediaControlKeysEvent::eSeekForward:
      return "Seek forward";
    case MediaControlKeysEvent::eStop:
      return "Stop";
    default:
      MOZ_ASSERT_UNREACHABLE("Invalid action.");
      return "Unknown";
  }
}

inline MediaControlKeysEvent
ConvertMediaControlKeysTestEventToMediaControlKeysEvent(
    MediaControlKeysTestEvent aEvent) {
  switch (aEvent) {
    case MediaControlKeysTestEvent::Play:
      return MediaControlKeysEvent::ePlay;
    case MediaControlKeysTestEvent::Pause:
      return MediaControlKeysEvent::ePause;
    case MediaControlKeysTestEvent::PlayPause:
      return MediaControlKeysEvent::ePlayPause;
    case MediaControlKeysTestEvent::Previoustrack:
      return MediaControlKeysEvent::ePrevTrack;
    case MediaControlKeysTestEvent::Nexttrack:
      return MediaControlKeysEvent::eNextTrack;
    case MediaControlKeysTestEvent::Seekbackward:
      return MediaControlKeysEvent::eSeekBackward;
    case MediaControlKeysTestEvent::Seekforward:
      return MediaControlKeysEvent::eSeekForward;
    default:
      MOZ_ASSERT(aEvent == MediaControlKeysTestEvent::Stop);
      return MediaControlKeysEvent::eStop;
  }
}

inline const char* ToPlaybackStateEventStr(PlaybackState aState) {
  switch (aState) {
    case PlaybackState::ePlaying:
      return "Playing";
    case PlaybackState::ePaused:
      return "Paused";
    case PlaybackState::eStopped:
      return "Stopped";
    default:
      MOZ_ASSERT_UNREACHABLE("Invalid playback state.");
      return "Unknown";
  }
}

inline const char* ToControlledMediaStateStr(ControlledMediaState aState) {
  switch (aState) {
    case ControlledMediaState::eStarted:
      return "started";
    case ControlledMediaState::ePlayed:
      return "played";
    case ControlledMediaState::ePaused:
      return "paused";
    case ControlledMediaState::eStopped:
      return "stopped";
    default:
      MOZ_ASSERT_UNREACHABLE("Invalid media state.");
      return "Unknown";
  }
}

BrowsingContext* GetAliveTopBrowsingContext(BrowsingContext* aBC);

}  // namespace dom
}  // namespace mozilla

#endif  // DOM_MEDIA_MEDIACONTROL_MEDIACONTROLUTILS_H_
