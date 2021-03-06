/* Generated by wayland-scanner 1.13.0 */

#ifndef CURSOR_SHAPES_V1_CLIENT_PROTOCOL_H
#define CURSOR_SHAPES_V1_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_cursor_shapes_v1 The cursor_shapes_v1 protocol
 * @section page_ifaces_cursor_shapes_v1 Interfaces
 * - @subpage page_iface_zcr_cursor_shapes_v1 - Allows to set the cursor shape
 * @section page_copyright_cursor_shapes_v1 Copyright
 * <pre>
 *
 * Copyright 2018 The Chromium Authors.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * </pre>
 */
struct wl_pointer;
struct zcr_cursor_shapes_v1;

/**
 * @page page_iface_zcr_cursor_shapes_v1 zcr_cursor_shapes_v1
 * @section page_iface_zcr_cursor_shapes_v1_desc Description
 *
 * Allows to set the semantic cursor shape rather than a surface for a
 * pointer cursor.
 *
 * Warning! The protocol described in this file is experimental and
 * backward incompatible changes may be made. Backward compatible changes
 * may be added together with the corresponding uinterface version bump.
 * Backward incompatible changes are done by bumping the version number in
 * the protocol and uinterface names and resetting the interface version.
 * Once the protocol is to be declared stable, the 'z' prefix and the
 * version number in the protocol and interface names are removed and the
 * interface version number is reset.
 * @section page_iface_zcr_cursor_shapes_v1_api API
 * See @ref iface_zcr_cursor_shapes_v1.
 */
/**
 * @defgroup iface_zcr_cursor_shapes_v1 The zcr_cursor_shapes_v1 interface
 *
 * Allows to set the semantic cursor shape rather than a surface for a
 * pointer cursor.
 *
 * Warning! The protocol described in this file is experimental and
 * backward incompatible changes may be made. Backward compatible changes
 * may be added together with the corresponding uinterface version bump.
 * Backward incompatible changes are done by bumping the version number in
 * the protocol and uinterface names and resetting the interface version.
 * Once the protocol is to be declared stable, the 'z' prefix and the
 * version number in the protocol and interface names are removed and the
 * interface version number is reset.
 */
extern const struct wl_interface zcr_cursor_shapes_v1_interface;

#ifndef ZCR_CURSOR_SHAPES_V1_ERROR_ENUM
#define ZCR_CURSOR_SHAPES_V1_ERROR_ENUM
enum zcr_cursor_shapes_v1_error {
	/**
	 * the specified shape value is invalid
	 */
	ZCR_CURSOR_SHAPES_V1_ERROR_INVALID_SHAPE = 0,
};
#endif /* ZCR_CURSOR_SHAPES_V1_ERROR_ENUM */

#ifndef ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_ENUM
#define ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_ENUM
/**
 * @ingroup iface_zcr_cursor_shapes_v1
 * the type of cursor shape
 */
enum zcr_cursor_shapes_v1_cursor_shape_type {
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_POINTER = 0,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_CROSS = 1,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_HAND = 2,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_IBEAM = 3,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_WAIT = 4,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_HELP = 5,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_EAST_RESIZE = 6,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NORTH_RESIZE = 7,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NORTH_EAST_RESIZE = 8,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NORTH_WEST_RESIZE = 9,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_SOUTH_RESIZE = 10,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_SOUTH_EAST_RESIZE = 11,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_SOUTH_WEST_RESIZE = 12,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_WEST_RESIZE = 13,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NORTH_SOUTH_RESIZE = 14,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_EAST_WEST_RESIZE = 15,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NORTH_EAST_SOUTH_WEST_RESIZE = 16,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NORTH_WEST_SOUTH_EAST_RESIZE = 17,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_COLUMN_RESIZE = 18,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_ROW_RESIZE = 19,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_MIDDLE_PANNING = 20,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_EAST_PANNING = 21,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NORTH_PANNING = 22,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NORTH_EAST_PANNING = 23,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NORTH_WEST_PANNING = 24,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_SOUTH_PANNING = 25,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_SOUTH_EAST_PANNING = 26,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_SOUTH_WEST_PANNING = 27,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_WEST_PANNING = 28,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_MOVE = 29,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_VERTICAL_TEXT = 30,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_CELL = 31,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_CONTEXT_MENU = 32,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_ALIAS = 33,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_PROGRESS = 34,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NO_DROP = 35,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_COPY = 36,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NONE = 37,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_NOT_ALLOWED = 38,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_ZOOM_IN = 39,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_ZOOM_OUT = 40,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_GRAB = 41,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_GRABBING = 42,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_DND_NONE = 43,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_DND_MOVE = 44,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_DND_COPY = 45,
	ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_DND_LINK = 46,
};
#endif /* ZCR_CURSOR_SHAPES_V1_CURSOR_SHAPE_TYPE_ENUM */

#define ZCR_CURSOR_SHAPES_V1_SET_CURSOR_SHAPE 0


/**
 * @ingroup iface_zcr_cursor_shapes_v1
 */
#define ZCR_CURSOR_SHAPES_V1_SET_CURSOR_SHAPE_SINCE_VERSION 1

/** @ingroup iface_zcr_cursor_shapes_v1 */
static inline void
zcr_cursor_shapes_v1_set_user_data(struct zcr_cursor_shapes_v1 *zcr_cursor_shapes_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zcr_cursor_shapes_v1, user_data);
}

/** @ingroup iface_zcr_cursor_shapes_v1 */
static inline void *
zcr_cursor_shapes_v1_get_user_data(struct zcr_cursor_shapes_v1 *zcr_cursor_shapes_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zcr_cursor_shapes_v1);
}

static inline uint32_t
zcr_cursor_shapes_v1_get_version(struct zcr_cursor_shapes_v1 *zcr_cursor_shapes_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zcr_cursor_shapes_v1);
}

/** @ingroup iface_zcr_cursor_shapes_v1 */
static inline void
zcr_cursor_shapes_v1_destroy(struct zcr_cursor_shapes_v1 *zcr_cursor_shapes_v1)
{
	wl_proxy_destroy((struct wl_proxy *) zcr_cursor_shapes_v1);
}

/**
 * @ingroup iface_zcr_cursor_shapes_v1
 *
 * Sets the pointer cursor to the specified shape. The server will change
 * the cursor graphics based on the specified shape and its graphic assets
 * and system condition.
 *
 * The "shape" argument needs to be one of the values in cursor_shape_type
 * enum. Otherwise invalid_shape error is raised.
 *
 * This is similar to wl_pointer::set_cursor request, but this accepts a
 * shape instead of contents in the form of a surface.
 *
 * The client which do not know this protocol should work as-is, so
 * wl_pointer::set_cursor will change the cursor graphics even when it's
 * combined with this request; and another invocation of set_cursor_shape
 * will change the cursor shape again. This means the last invoked one will
 * be used for the actual cursor.
 */
static inline void
zcr_cursor_shapes_v1_set_cursor_shape(struct zcr_cursor_shapes_v1 *zcr_cursor_shapes_v1, struct wl_pointer *pointer, int32_t shape)
{
	wl_proxy_marshal((struct wl_proxy *) zcr_cursor_shapes_v1,
			 ZCR_CURSOR_SHAPES_V1_SET_CURSOR_SHAPE, pointer, shape);
}

#ifdef  __cplusplus
}
#endif

#endif
