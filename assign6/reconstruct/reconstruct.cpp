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

#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Geometry/VectorT.hh>
#include <OpenMesh/Tools/Utils/Timer.hh>

#include <IsoEx/Grids/ScalarGridT.hh>
#include <IsoEx/Extractors/MarchingCubesT.hh>

#include <iostream>
#include <fstream>
#include <vector>

#include "ImplicitRBF.h"
#include "ImplicitHoppe.h"

//=============================================================================
// resolution of Marching Cubes grid
#define MC_RESOLUTION  50

//=============================================================================

typedef OpenMesh::TriMesh_ArrayKernelT<>  Mesh;
typedef Mesh::Point                       Point;
typedef Mesh::Scalar                      Scalar;
typedef OpenMesh::Vec3d                   Vec3d;


//=============================================================================

int main(int argc, char **argv)
{
    // parse command line
    if (argc<3)
    {
        std::cerr << "Usage:\n"
            << argv[0] 
            << "  <input-points>  <output-mesh>  <mode: HOPPE or RBF>\n";
        exit(1);
    }

    // load sample points with normals
    std::cout << "Load points\n" << std::flush;

    std::ifstream ifs(argv[1]);
    if (!ifs) 
    {
        std::cerr << "Cannot open file\n";
        exit(1);
    }

    std::vector<Point>   points, normals;
    Point                p, n;

    while (ifs && !ifs.eof())
    {
        ifs >> p[0] >> p[1] >> p[2];
        ifs >> n[0] >> n[1] >> n[2];
        points.push_back(p);
        normals.push_back(n);
    }
    std::cout << points.size() << " sample points\n";
    ifs.close();

    std::string MODE(argv[3]);
    std::cout << "MODE: " << MODE << "\n" << std::flush;
    if (MODE == "RBF"){
        std::cout << "Fit RBF\n" << std::flush;
    }
    else if (MODE == "HOPPE"){
        std::cout << "Use Hoppe's method\n" << std::flush;
    }
    else{
        std::cerr << "You have to set MODE to HOPPE or RBF";
        exit(1);
    }

    ImplicitRBF implicitRBF( points, normals );
    ImplicitHoppe implicitHOPPE( points, normals );

    // compute bounding cube for Marching Cubes grid
    std::cout << "Bounding Box\n" << std::flush;
    Point bb_min( points[0]), bb_max( points[0]);

    for (unsigned int i=1; i<points.size(); ++i)
    {
        bb_min.minimize( points[i] );
        bb_max.maximize( points[i] );
    }

    Point  bb_center = (bb_max+bb_min)*0.5f;
    Scalar bb_size   = (bb_max-bb_min).max();
    bb_min = bb_center - 0.6f * Point(bb_size, bb_size, bb_size);
    bb_max = bb_center + 0.6f * Point(bb_size, bb_size, bb_size);

    // setup Marching Cubes grid by sampling RBF
    std::cout << "Setup grid\n" << std::flush;
    int res = MC_RESOLUTION;
    IsoEx::ScalarGridT<Scalar>  grid(bb_min,
        Point(bb_max[0]-bb_min[0], 0, 0),
        Point(0, bb_max[1]-bb_min[1], 0),
        Point(0, 0, bb_max[2]-bb_min[2]),
        res, res, res);

    for (unsigned int x=0; x<res; ++x)
        for (unsigned int y=0; y<res; ++y)
            for (unsigned int z=0; z<res; ++z){
                if (MODE == "HOPPE"){
                    grid.value(x,y,z) = implicitHOPPE( grid.point(x,y,z) );
                }
                if (MODE == "RBF"){
                    grid.value(x,y,z) = implicitRBF( grid.point(x,y,z) );
                }
            }

    // isosurface extraction by Marching Cubes
    std::cout << "Marching Cubes\n" << std::flush;
    Mesh mesh;
    marching_cubes(grid, mesh); 

    // write mesh
    std::cout << "Write mesh\n" << std::flush;
    if (!OpenMesh::IO::write_mesh(mesh, argv[2]))
    {
        std::cerr << "Cannot write mesh\n";
        exit(1);
    }

    std::cout << "Done\n" << std::flush;
    return 0;
}


//=============================================================================
