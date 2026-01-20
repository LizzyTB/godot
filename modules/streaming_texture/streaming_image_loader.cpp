/**************************************************************************/
/*  streaming_image_loader.cpp                                            */
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

#include "streaming_image_loader.h"
#include "core/io/file_access.h"

Ref<Resource> StreamingImageLoader::load(const String &p_path, const String &p_original_path, Error *r_error, bool p_use_sub_threads, float *r_progress, CacheMode p_cache_mode) {
    Ref<FileAccess> f = FileAccess::open(p_path, FileAccess::READ);
    if (f.is_null()) {
        if (r_error) {
            *r_error = ERR_CANT_OPEN;
        }
        return Ref<Resource>();
    }

    uint8_t header[4] = { 0, 0, 0, 0 };
    f->get_buffer(header, 4);

    bool unrecognized = header[0] != 'G' || header[1] != 'D' || header[2] != 'S' || header[3] != 'I';
    if (unrecognized) {
        if (r_error) {
            *r_error = ERR_FILE_UNRECOGNIZED;
        }
        ERR_FAIL_V(Ref<Resource>());
    }

    Ref<Image> image;
    image.instantiate();

    image->create_empty(2, 2, false, Image::FORMAT_RGB8);
    image->set_pixel(0, 0, Color(1.0, 0.0, 0.0));
    image->set_pixel(1, 0, Color(0.0, 1.0, 0.0));
    image->set_pixel(0, 1, Color(0.0, 0.0, 1.0));
    image->set_pixel(1, 1, Color(1.0, 1.0, 1.0));

    if (r_error) {
        *r_error = OK;
    }

    return image;
}

void StreamingImageLoader::get_recognized_extensions(List<String> *p_extensions) const {
    p_extensions->push_back("streaming_image");
}

bool StreamingImageLoader::handles_type(const String &p_type) const {
    return p_type == "Image";
}

String StreamingImageLoader::get_resource_type(const String &p_path) const {
    return p_path.get_extension().to_lower() == "streaming_image" ? "Image" : String();
}