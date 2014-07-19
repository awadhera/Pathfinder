/******************************************************************************/
/*!
\file ObjectWrapper.h
\author Anshuman Wadhera
\par email: a.anshumanwadhera\@digipen.edu
\par a.anshumanwadhera 900995
\par Course: CS1050
\par Project #01
\date 21/12/2011
\brief
Interface for Wrapper of geometric objects and their transforms for this project
Copyright (C) 2011 DigiPen Institute of Technology Singapore
*/
/******************************************************************************/

#ifndef OBJECTWRAPPER_H
#define OBJECTWRAPPER_H

#include "Geometry/ObjectGrid.h"
#include "Geometry/ObjectCube.h"
#include "Geometry/ObjectCylinder.h"
#include "Geometry/ObjectCone.h"
#include "Geometry/ObjectSphere.h"
#include "Geometry/ObjectComposite.h"
#include "Camera/Camera.h"

//!  Wrapper class
/*!
Class for implmenting wrapper of geomtric objects and transforms
*/
class Wrapper
{
	static Wrapper *s_pInstance;	/*! Pointer to a Wrapper object which is static*/
	int count;	/*! Variable to keep track of total number of geometric objects*/
	Wrapper();
	~Wrapper();
	Wrapper(Wrapper &);
	Wrapper & operator = (Wrapper &);

	Cube *cube;		/*!< Pointer to Cube object(Specifics read from file) */
	Grid *grid;		/*!< Pointer to Grid object(Specifics read from file) */
	Cone *cone;		/*!< Pointer to Cone object(Specifics read from file) */
	Cylinder *cylinder;	/*!< Pointer to Cylinder object(Specifics read from file) */
	Sphere *sphere;	/*!< Pointer to Sphere object(Specifics read from file) */

	Cube comp_cube[8];	/*!< Array of 8 cube objects for composite object_1 */
	Sphere comp_sphere[2];	/*!< Array of 2 sphere objects for composite object_1 */
	Cone comp_cone[4];	/*!< Array of 4 cone objects for composite object_1 */
	Cylinder comp_cylinder[4];	/*!< Array of 4 cylinder objects for composite object_1 */

	Cube xwing_cube[6]; /*!< Array of 6 cube objects for composite object_2 */
	Cylinder xwing_cylinder[13]; /*!< Array of 13 cylinder objects for composite object_2 */
	Sphere xwing_sphere[4]; /*!< Array of 4 sphere objects for composite object_2 */
	Grid xwing_grid[1]; /*!< Array of 1 grid object for composite object_2 */
	Cone xwing_cone[1]; /*!< Array of 1 cone object for composite object_2 */

	Composite comp[11];	/*!< Array of 11 composite objects for composite object_1 */
	Composite xwing[18]; /*!< Array of 18 composite objects for composite object_2 */

	Scale s[6];	/*!< Array of 20 Scale Transforms for composite object_1 */
	Translate t[11];	/*!< Array of 20 Translate Transforms for composite object_1 */
	Rotate r[7];	/*!< Array of 20 Rotate Transforms for composite object_1 */

	Scale x_s[9];	/*!< Array of 20 Scale Transforms for composite object_2 */
	Translate x_t[15]; /*!< Array of 20 Translate Transforms for composite object_2 */
	Rotate x_r[7];	/*!< Array of 20 Rotate Transforms for composite object_2 */

	BaseGeometry *bp[48];	/*!< Array of BaseGeometry pointers */
	Color4 col[48];	/*!< Array of Color4 objects */
public:
	Camera camera;	/*!< Camera object of the project */
	BaseGeometry *bpDraw[7]; /*!< Array of BaseGeometry pointers */	
	static void create();
	static void destroy();
	static Wrapper &Instance();
	void createGrid(const unsigned short &x,const unsigned short &y, const Color4 &c);
	void createCube(const unsigned short &subd, const Color4 &c);
	void createCylinder(const unsigned short &stacks,const unsigned short &slices, const Color4 &c);
	void createCone(const unsigned short &stacks,const unsigned short &slices, const Color4 &c);
	void createSphere(const unsigned short &stacks,const unsigned short &slices, const Color4 &c);
	void destroyGrid();
	void destroyCube();
	void destroyCylinder();
	void destroyCone();
	void destroySphere();
	void createComposite_1();
	void createComposite_2();
	void setTransforms();
	void createGeometries();
	void uploadGeometries();
	void destroyGeometries();
};



#endif