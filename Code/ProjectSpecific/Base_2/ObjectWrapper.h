/******************************************************************************/
/*!
\file ObjectWrapper.h
\author Anshuman Wadhera
\par email: a.anshumanwadhera\@digipen.edu
\par a.anshumanwadhera 900995
\par Course: CS1150
\par Project #01
\date 21/02/2012
\brief
Interface for Wrapper of geometric objects and their transforms for this project
Copyright (C) 2012 DigiPen Institute of Technology Singapore
*/
/******************************************************************************/

#ifndef OBJECTWRAPPER_H
#define OBJECTWRAPPER_H

#include "../../Geometry/ObjectGrid.h"
#include "../../Geometry/ObjectCube.h"
#include "../../Camera/Camera.h"
#include "../../GameObject/GameObject.h"
#include "../../AI/AIUtilities.h"
#include <sstream>

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
public:
	Grid geoGrid;	
	GameObject goGrid;
	Cube geoCube;
	GameObject goCube;
	ModelSpace mSpace;	/*!< ModelSpace used */
	Camera camera;	/*!< Camera object of the project */
	static void create();
	static void destroy();
	static Wrapper &Instance();
	void createGeometries();
	void uploadGeometries();
	void destroyGeometries();
	void createAndInitObjects();
};

#endif