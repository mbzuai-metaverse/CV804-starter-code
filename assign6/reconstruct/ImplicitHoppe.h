//=============================================================================
//                                                
//   Code framework for the lecture
//
//   "CV804: 3D Geometry Processing"
//
//   Lecturer: Hao Li
//   TAs: Phong Tran, Long Nhat Ho
//
//   Modified from
//   "Surface Representation and Geometric Modeling"
//   by Mark Pauly, Mario Botsch, Balint Miklos, and Hao Li
//
//   Copyright (C) 2007 by  Applied Geometry Group and 
//                          Computer Graphics Laboratory, ETH Zurich
//                                                                         
//-----------------------------------------------------------------------------
//                                                                            
//                                License                                     
//                                                                            
//   This program is free software; you can redistribute it and/or
//   modify it under the terms of the GNU General Public License
//   as published by the Free Software Foundation; either version 2
//   of the License, or (at your option) any later version.
//   
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//   
//   You should have received a copy of the GNU General Public License
//   along with this program; if not, write to the Free Software
//   Foundation, Inc., 51 Franklin Street, Fifth Floor, 
//   Boston, MA  02110-1301, USA.
//                                                                            
//=============================================================================
//=============================================================================
//
//  CLASS ImplicitHoppe
//
//=============================================================================

#ifndef HOPPE_HH
#define HOPPE_HH

//=============================================================================

#include <OpenMesh/Core/Geometry/VectorT.hh>
#include <vector>
#include <float.h>

//=============================================================================

class ImplicitHoppe
{
public:

    typedef OpenMesh::Vec3f Vec3f;

    // fit RBF to given constraints
    ImplicitHoppe( 
        const std::vector<Vec3f>& _points, 
        const std::vector<Vec3f>& _normals )
        : points_(_points), normals_(_normals)
    {}

    // evaluate implicit at position _p
    float operator()(const Vec3f& _p) const
    {
        float dist(0);

        //////////////////////////////////////////////////////////////////////
        // INSERT CODE:
        // 1) find closest sample point

        // 2) compute distance to its plane

        //////////////////////////////////////////////////////////////////////
        return dist;
    }

private:

    const std::vector<Vec3f>&  points_;
    const std::vector<Vec3f>&  normals_;
};

//=============================================================================
#endif // RBF_HH defined
//=============================================================================
