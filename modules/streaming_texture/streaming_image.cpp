/**************************************************************************/
/*  streaming_image.cpp                                                   */
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

#include "streaming_image.h"

void StreamingImage::_bind_methods() {

}

int StreamingImage::get_mipmap_size(int p_mipmap) const {
    return Image::get_image_mipmap_offset(width, height, format, p_mipmap);
}

Error StreamingImage::load_mipmap(int p_mipmap, void *p_buffer, size_t p_buffer_size) {

}

int StreamingImage::get_width() const {
    return width;
}

int StreamingImage::get_height() const {
    return height;
}

Size2i StreamingImage::get_size() const {
    return Size2i(width, height);
}

int StreamingImage::get_mipmap_count() const {
    return Image::get_image_required_mipmaps(width, height, format);
}

int StreamingImage::get_current_mipmap() const {
    return current_mipmap;
}

Image::Format StreamingImage::get_format() const {
    return format;
}