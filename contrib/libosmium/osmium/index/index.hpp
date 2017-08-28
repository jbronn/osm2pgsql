#ifndef OSMIUM_INDEX_INDEX_HPP
#define OSMIUM_INDEX_INDEX_HPP

/*

This file is part of Osmium (http://osmcode.org/libosmium).

Copyright 2013-2017 Jochen Topf <jochen@topf.org> and others (see README).

Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

*/

#include <cstddef>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <string>

namespace osmium {

    /**
     * Exception signaling that an element could not be
     * found in an index.
     */
    struct not_found : public std::runtime_error {

        explicit not_found(const std::string& what) :
            std::runtime_error(what) {
        }

        explicit not_found(const char* what) :
            std::runtime_error(what) {
        }

        explicit not_found(uint64_t id) :
            std::runtime_error(std::string{"id "} + std::to_string(id) + " not found") {
        }

    }; // struct not_found

    /**
     * @brief Indexing of OSM data, Locations, etc.
     */
    namespace index {

        /**
         * Some of the index classes need an "empty" value that can
         * never appear in real data. This function must return this
         * empty value for any class used as a value in an index.
         * The default implementation returns a default constructed
         * object, but it can be specialized.
         */
        template <typename T>
        inline constexpr T empty_value() {
            return T{};
        }

        /**
         * The size_t value in indexes is usually used for offsets
         * into a buffer or file. It is unlikely that we ever need
         * the full range, so the max value is a good "empty" value.
         */
        template <>
        inline constexpr size_t empty_value<size_t>() {
            return std::numeric_limits<size_t>::max();
        }

    } // namespace index

} // namespace osmium

#endif // OSMIUM_INDEX_INDEX_HPP
