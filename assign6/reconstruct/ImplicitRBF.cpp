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
//  CLASS ImplicitRBF - IMPLEMENTATION
//
//=============================================================================

#include "ImplicitRBF.h"

//== IMPLEMENTATION ==========================================================

ImplicitRBF::ImplicitRBF( 
    const std::vector<Vec3f>& _points, 
    const std::vector<Vec3f>& _normals )
{
    //////////////////////////////////////////////////////////////////////
    // INSERT CODE:
    // 1) collect constraints (on-surface and off-surface)
    // get bounding box, recalculate because do not want to change reconstruct.cc

    // 2) setup matrix
    // Check the slides for the formula

    // 3) solve linear system for weights_
    // Call the ImplicitRBF::solve_linear_system function
    
    //////////////////////////////////////////////////////////////////////
}

//-----------------------------------------------------------------------------

void ImplicitRBF::solve_linear_system( 
    gmmMatrix& _M, 
    gmmVector& _b, 
    gmmVector& _x )
{
    // solve linear system by gmm's LU factorization
    unsigned int N = _b.size();
    _x.resize(N);
    std::vector< size_t >  ipvt(N);
    gmm::lu_factor( _M, ipvt );
    gmm::lu_solve( _M, ipvt, _x, _b );
}

//-----------------------------------------------------------------------------

double ImplicitRBF::operator()(const Vec3f& _p) const
{
    std::vector<Vec3d>::const_iterator  
        c_it(centers_.begin()),
        c_end(centers_.end());

    std::vector<double>::const_iterator   
        w_it(weights_.begin());

    const Vec3d p(_p);
    double f(0);

    for (; c_it!=c_end; ++c_it, ++w_it)
        f += *w_it * kernel(*c_it, p);

    return f;
}

//=============================================================================
