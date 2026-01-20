/**************************************************************************/
/*  streaming_texture.h                                                   */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once

#include "core/io/image.h"

class StreamingImage : public Resource {
    GDCLASS(StreamingImage, Resource);

    friend class StreamingTextureServer;

public:
    enum {
		MAX_WIDTH = (1 << 24), // Force a limit somehow.
		MAX_HEIGHT = (1 << 24), // Force a limit somehow.
		MAX_PIXELS = 268435456 // 16384 ^ 2
	};

protected:
    static void _bind_methods();

private:
    Image::Format format = Image::FORMAT_L8;
    int width;
    int height;
    int current_mipmap;

    int get_mipmap_size(int p_mipmap) const;
    Error load_mipmap(int p_mipmap, void *p_buffer, size_t p_buffer_size);

public:
    int get_width() const;
    int get_height() const;
    Size2i get_size() const;
    int get_mipmap_count() const;
    int get_current_mipmap() const;

    Image::Format get_format() const;

    StreamingImage() = default;
};