/*=========================================================================

  Program:   ParaView
  Module:    vtkPVConfig.h.in

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef __vtkPVConfig_h
#define __vtkPVConfig_h

/* #undef PARAVIEW_USE_ICE_T */
/* #undef PARAVIEW_USE_VISITBRIDGE */

// flags controlling various visit-bridge components being built.
/* #undef VISIT_BUILD_READER_CGNS */
/* #undef VISIT_BUILD_READER_GMV */
/* #undef VISIT_BUILD_READER_Silo */
/* #undef VISIT_BUILD_READER_Mili */

/* #undef PARAVIEW_ENABLE_PYTHON */
/* #undef PARAVIEW_FREEZE_PYTHON */
#define PARAVIEW_BUILD_ARCHITECTURE "32"

#define PARAVIEW_ENABLE_MATPLOTLIB

// Added for AutoMPI
/* #undef VTK_MPIRUN_EXE */
/* #undef VTK_MPI_PRENUMPROC_FLAGS */
/* #undef VTK_MPI_NUMPROC_FLAG */
/* #undef VTK_MPI_PREFLAGS */
/* #undef VTK_MPI_POSTFLAGS */
/* #undef VTK_MPI_SERVER_PREFLAGS */
/* #undef VTK_MPI_SERVER_POSTFLAGS */

// Indicates the Qt support is enabled in VTK.
/* #undef VTK_USE_QVTK */

// Build ParaView with Floating Point Exceptions turned on
/* #undef PARAVIEW_ENABLE_FPE */
//Build ParaView with enforced secure connection (--connect-id)
/* #undef PARAVIEW_ALWAYS_SECURE_CONNECTION */

#define PARAVIEW_VERSION_MAJOR 4
#define PARAVIEW_VERSION_MINOR 1
#define PARAVIEW_VERSION_PATCH 0
#define PARAVIEW_VERSION "4.1"
#define PARAVIEW_VERSION_FULL "4.1.0"

// Some runtime informations to be displayed in About box:
#define OPENGL_gl_LIBRARY   "opengl32"
#define OPENGL_INCLUDE_DIR  ""
#define CMAKE_BUILD_TYPE    ""

#define CMAKE_CXX_COMPILER_ID "MSVC"


// defined when SSEND must be used for communication by default.
/* #undef PARAVIEW_USE_MPI */

// defined when SSEND must be used for communication by default.
/* #undef PARAVIEW_USE_MPI_SSEND */

// defined when client processes must init MPI by default.
/* #undef PARAVIEW_INITIALIZE_MPI_ON_CLIENT */

// defined when qt support is enabled
#define PARAVIEW_ENABLE_QT_SUPPORT

// ParaView data root (useful for testing).
#define PARAVIEW_DATA_ROOT "PARAVIEW_DATA_ROOT-NOTFOUND"

// Should chroma-subsampling be used by default?
/* #undef PARAVIEW_OGGTHEORA_USE_SUBSAMPLING */

/* #undef BUILD_SHARED_LIBS */
#ifdef BUILD_SHARED_LIBS
// for sake of old code, we define the PARAVIEW_BUILD_SHARED_LIBS variable. This
// can be deprecated once the cleanup is complete.
# define PARAVIEW_BUILD_SHARED_LIBS
#endif

// The ParaView version of VTK_USE_X
/* #undef PARAVIEW_USE_X */

// The default prevision value for conversion for string to double
// and double to string
#define DEFAULT_DOUBLE_PRECISION_VALUE 16

/* #undef PARAVIEW_ENABLE_FFMPEG */

/* #undef PARAVIEW_USE_PISTON */

#endif
