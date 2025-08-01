/**
    libLaserdockCore
    Copyright(c) 2018 Wicked Lasers

    This file is part of libLaserdockCore.

    libLaserdockCore is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libLaserdockCore is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libLaserdockCore.  If not, see <https://www.gnu.org/licenses/>.
**/

#ifndef LDVERTEX_H
#define LDVERTEX_H

#include <ldCore/ldCore_global.h>

/** Laser vertex. Used for easier processing */
struct LDCORESHARED_EXPORT ldVertex
{
    static const int POS_COUNT = 3;
    static const int COLOR_COUNT = 4;

    static void registerMetaTypes();

    float &x();
    float x() const;
    float &y();
    float y() const;
    float &z();
    float z() const;

    float &r();
    float r() const;
    float &g();
    float g() const;
    float &b();
    float b() const;
    float &a();
    float a() const;

    bool isValid() const;
    bool isBlank() const;

    void clear();
    void clearColor();

    void normalize(const ldVertex &source, float intensity);

    /** x,y */
    float position[POS_COUNT];
    /** r,g,b,a [0..1] */
    float color[COLOR_COUNT];
};
Q_DECLARE_METATYPE(ldVertex)

QDebug operator << (QDebug debug, const ldVertex& v);


#endif // LDVERTEX_H
