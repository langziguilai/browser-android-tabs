// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/css/properties/shorthands/border_block_color.h"

#include "third_party/blink/renderer/core/css/parser/css_property_parser_helpers.h"
#include "third_party/blink/renderer/core/style_property_shorthand.h"

namespace blink {
namespace CSSShorthand {

bool BorderBlockColor::ParseShorthand(
    bool important,
    CSSParserTokenRange& range,
    const CSSParserContext& context,
    const CSSParserLocalContext&,
    HeapVector<CSSPropertyValue, 256>& properties) const {
  return CSSPropertyParserHelpers::ConsumeShorthandVia2Longhands(
      borderBlockColorShorthand(), important, context, range, properties);
}

}  // namespace CSSShorthand
}  // namespace blink
