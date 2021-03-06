/*

Copyright (c) 2013, Project OSRM, Dennis Luxen, others
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list
of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef COMPUTE_ANGLE_H
#define COMPUTE_ANGLE_H

#include "../Util/MercatorUtil.h"
#include <osrm/Coordinate.h>

#include <boost/assert.hpp>
#include <cmath>

/* Get angle of line segment (A,C)->(C,B), atan2 magic, formerly cosine theorem*/
template <class CoordinateT>
inline static double GetAngleBetweenThreeFixedPointCoordinates(const CoordinateT &A,
                                                               const CoordinateT &C,
                                                               const CoordinateT &B)
{
    const double v1x = (A.lon - C.lon) / COORDINATE_PRECISION;
    const double v1y = lat2y(A.lat / COORDINATE_PRECISION) - lat2y(C.lat / COORDINATE_PRECISION);
    const double v2x = (B.lon - C.lon) / COORDINATE_PRECISION;
    const double v2y = lat2y(B.lat / COORDINATE_PRECISION) - lat2y(C.lat / COORDINATE_PRECISION);

    double angle = (atan2(v2y, v2x) - atan2(v1y, v1x)) * 180 / M_PI;
    while (angle < 0)
        angle += 360;
    return angle;
}

#endif // COMPUTE_ANGLE_H
