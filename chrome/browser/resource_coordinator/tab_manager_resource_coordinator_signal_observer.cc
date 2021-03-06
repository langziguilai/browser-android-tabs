// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/resource_coordinator/tab_manager_resource_coordinator_signal_observer.h"

#include "base/time/time.h"
#include "chrome/browser/browser_process.h"
#include "chrome/browser/resource_coordinator/tab_load_tracker.h"
#include "chrome/browser/resource_coordinator/tab_manager_stats_collector.h"
#include "chrome/browser/resource_coordinator/tab_manager_web_contents_data.h"

namespace resource_coordinator {

// A helper class for accessing TabLoadTracker. TabLoadTracker can't directly
// friend TabManager::ResourceCoordinatorSignalObserver as it's a nested class
// and can't be forward declared.
class TabManagerResourceCoordinatorSignalObserverHelper {
 public:
  static void OnPageAlmostIdle(content::WebContents* web_contents) {
    TabLoadTracker::Get()->OnPageAlmostIdle(web_contents);
  }
};

TabManager::ResourceCoordinatorSignalObserver::
    ResourceCoordinatorSignalObserver() {
  if (auto* page_signal_receiver = PageSignalReceiver::GetInstance())
    page_signal_receiver->AddObserver(this);
}

TabManager::ResourceCoordinatorSignalObserver::
    ~ResourceCoordinatorSignalObserver() {
  if (auto* page_signal_receiver = PageSignalReceiver::GetInstance())
    page_signal_receiver->RemoveObserver(this);
}

void TabManager::ResourceCoordinatorSignalObserver::OnPageAlmostIdle(
    content::WebContents* web_contents,
    const PageNavigationIdentity& page_navigation_id) {
  auto* page_signal_receiver = PageSignalReceiver::GetInstance();
  DCHECK_NE(nullptr, page_signal_receiver);

  // Only dispatch the event if it pertains to the current navigation.
  if (page_signal_receiver->GetNavigationIDForWebContents(web_contents) ==
      page_navigation_id.navigation_id) {
    TabManagerResourceCoordinatorSignalObserverHelper::OnPageAlmostIdle(
        web_contents);
  }
}

void TabManager::ResourceCoordinatorSignalObserver::
    OnExpectedTaskQueueingDurationSet(
        content::WebContents* web_contents,
        const PageNavigationIdentity& page_navigation_id,
        base::TimeDelta duration) {
  auto* page_signal_receiver = PageSignalReceiver::GetInstance();
  DCHECK_NE(nullptr, page_signal_receiver);

  if (page_signal_receiver->GetNavigationIDForWebContents(web_contents) !=
      page_navigation_id.navigation_id) {
    // |web_contents| has been re-navigated, drop this notification rather than
    // recording it against the wrong origin.
    return;
  }

  g_browser_process->GetTabManager()
      ->stats_collector()
      ->RecordExpectedTaskQueueingDuration(web_contents, duration);
}

void TabManager::ResourceCoordinatorSignalObserver::
    OnNonPersistentNotificationCreated(
        content::WebContents* web_contents,
        const PageNavigationIdentity& page_navigation_id) {
  // TODO(sebmarchand): Add the wiring to forward this signal where it should be
  // used.
}

void TabManager::ResourceCoordinatorSignalObserver::
    OnLoadTimePerformanceEstimate(
        content::WebContents* web_contents,
        const PageNavigationIdentity& page_navigation_id,
        base::TimeDelta cpu_usage_estimate,
        uint64_t private_footprint_kb_estimate) {
  // TODO(siggi): Persist the measurement associated to |url|'s site.
}

}  // namespace resource_coordinator
