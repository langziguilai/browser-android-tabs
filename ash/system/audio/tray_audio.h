// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ASH_SYSTEM_AUDIO_TRAY_AUDIO_H_
#define ASH_SYSTEM_AUDIO_TRAY_AUDIO_H_

#include <stdint.h>

#include "ash/ash_export.h"
#include "ash/session/session_observer.h"
#include "ash/system/tray/tray_image_item.h"
#include "base/macros.h"
#include "chromeos/audio/cras_audio_handler.h"

namespace ash {

namespace tray {
class AudioDetailedView;
class VolumeView;
}

class DetailedViewDelegate;

// The system tray item for audio input and output.
class ASH_EXPORT TrayAudio : public TrayImageItem,
                             public chromeos::CrasAudioHandler::AudioObserver,
                             public SessionObserver {
 public:
  explicit TrayAudio(SystemTray* system_tray);
  ~TrayAudio() override;

  // Shows the pop-up volume slider on all displays. Used by ARC when an Android
  // app changes the system volume.
  void ShowPopUpVolumeView();

  tray::VolumeView* volume_view_for_testing() { return volume_view_; }
  bool pop_up_volume_view_for_testing() { return pop_up_volume_view_; }

 private:
  // Overridden from TrayImageItem.
  bool GetInitialVisibility() override;

  // Overridden from SystemTrayItem.
  views::View* CreateDefaultView(LoginStatus status) override;
  views::View* CreateDetailedView(LoginStatus status) override;
  void OnDefaultViewDestroyed() override;
  void OnDetailedViewDestroyed() override;
  bool ShouldShowShelf() const override;
  views::View* GetItemToRestoreFocusTo() override;

  // Overridden from CrasAudioHandler::AudioObserver.
  void OnOutputNodeVolumeChanged(uint64_t node_id, int volume) override;
  void OnOutputMuteChanged(bool mute_on, bool system_adjust) override;
  void OnAudioNodesChanged() override;
  void OnActiveOutputNodeChanged() override;
  void OnActiveInputNodeChanged() override;

  // Overridden from SessionObserver:
  void OnSessionStateChanged(session_manager::SessionState state) override;

  // Updates the UI views.
  void Update();

  tray::VolumeView* volume_view_;

  // True if VolumeView should be created for accelerator pop up;
  // Otherwise, it should be created for detailed view in ash tray bubble.
  bool pop_up_volume_view_;

  tray::AudioDetailedView* audio_detail_view_;

  ScopedSessionObserver session_observer_{this};

  const std::unique_ptr<DetailedViewDelegate> detailed_view_delegate_;

  DISALLOW_COPY_AND_ASSIGN(TrayAudio);
};

}  // namespace ash

#endif  // ASH_SYSTEM_AUDIO_TRAY_AUDIO_H_
