// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/web/public/test/web_test_with_web_state.h"

#include "ios/web/public/web_state/web_frame.h"
#include "ios/web/web_state/web_frames_manager_impl.h"

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

namespace web {

typedef WebTestWithWebState WebFramesManagerTest;

// Tests that the WebFramesManager correctly adds a WebFrame for a webpage with
// a single frame.
TEST_F(WebFramesManagerTest, SingleWebFrameAdded) {
  LoadHtml(@"<p></p>");

  WebFramesManagerImpl* frames_manager =
      WebFramesManagerImpl::FromWebState(web_state());
  EXPECT_EQ(1ul, frames_manager->GetAllWebFrames().size());

  WebFrame* main_web_frame = frames_manager->GetMainWebFrame();
  ASSERT_TRUE(main_web_frame);
  EXPECT_TRUE(main_web_frame->IsMainFrame());
  EXPECT_FALSE(main_web_frame->GetFrameId().empty());

  EXPECT_EQ(GURL(BaseUrl()).GetOrigin(), main_web_frame->GetSecurityOrigin());
};

}  // namespace web
