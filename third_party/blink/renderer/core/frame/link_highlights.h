// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_LINK_HIGHLIGHTS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_LINK_HIGHLIGHTS_H_

#include <memory>

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class Page;
class LinkHighlightImpl;
class CompositorAnimationHost;
class CompositorAnimationTimeline;
class WebLayerTreeView;
class LocalFrame;

class CORE_EXPORT LinkHighlights final
    : public GarbageCollectedFinalized<LinkHighlights> {
 public:
  static LinkHighlights* Create(Page& page) { return new LinkHighlights(page); }
  virtual ~LinkHighlights();

  virtual void Trace(blink::Visitor*);

  void ResetForPageNavigation();

  void SetTapHighlights(HeapVector<Member<Node>>&);

  void UpdateGeometry();

  void StartHighlightAnimationIfNeeded();

  void LayerTreeViewInitialized(WebLayerTreeView&);
  void WillCloseLayerTreeView(WebLayerTreeView&);

 private:
  FRIEND_TEST_ALL_PREFIXES(LinkHighlightImplTest, verifyWebViewImplIntegration);
  FRIEND_TEST_ALL_PREFIXES(LinkHighlightImplTest, resetDuringNodeRemoval);
  FRIEND_TEST_ALL_PREFIXES(LinkHighlightImplTest, resetLayerTreeView);
  FRIEND_TEST_ALL_PREFIXES(LinkHighlightImplTest, multipleHighlights);

  explicit LinkHighlights(Page&);

  void RemoveAllHighlights();

  LocalFrame* MainFrame() const;

  Page& GetPage() const {
    DCHECK(page_);
    return *page_;
  }

  Member<Page> page_;
  Vector<std::unique_ptr<LinkHighlightImpl>> link_highlights_;
  std::unique_ptr<CompositorAnimationHost> animation_host_;
  std::unique_ptr<CompositorAnimationTimeline> timeline_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_LINK_HIGHLIGHTS_H_
