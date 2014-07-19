/******************************************************************************/
/*!
\file ObjectWrapper.cpp
\author Anshuman Wadhera
\par email: a.anshumanwadhera\@digipen.edu
\par a.anshumanwadhera 900995
\par Course: CS1150
\par Project #01
\date 21/02/2012
\brief
Implementation of Wrapper of game objects for this project
Copyright (C) 2012 DigiPen Institute of Technology Singapore
*/
/******************************************************************************/

#include "ObjectWrapper.h"
#include <string>

///Initialize static instance of Wrapper
Wrapper * Wrapper::s_pInstance = 0;
/******************************************************************************/
/*!
Constructor for Wrapper class
*/
/******************************************************************************/
Wrapper::Wrapper()
{
	count = 0;
}

/******************************************************************************/
/*!
Destructor for Wrapper class
*/
/******************************************************************************/
Wrapper::~Wrapper()
{
}


/******************************************************************************/
/*!
Create instance of Wrapper class
\return
void
*/
/******************************************************************************/
void Wrapper::create()
{
	s_pInstance = new Wrapper;
}

/******************************************************************************/
/*!
Destroy(deallocate) instance of Wrapper class
\return
void
*/
/******************************************************************************/
void Wrapper::destroy()
{
	delete s_pInstance;
}

/******************************************************************************/
/*!
Provide static instance of Wrapper class
\return
Reference to Wrapper instance
*/
/******************************************************************************/
Wrapper & Wrapper::Instance()
{
	return *s_pInstance;
}

/******************************************************************************/
/*!
Create the Vertices and Indices for all the geometric objects
Also create the transform objects
\return
void
*/
/******************************************************************************/
void Wrapper::createGeometries()
{
	geoGrid.createGeometry(255,255,0);
	geoCube.createGeometry(255,255,0);
}

/******************************************************************************/
/*!
Upload the geometries to the GPU
\return
void
*/
/******************************************************************************/
void Wrapper::uploadGeometries()
{
	geoGrid.uploadGeometry();
	geoCube.uploadGeometry();
}

/******************************************************************************/
/*!
Destroy the geometries - Unbind the buffers, delete the vertices and indices info
\return
void
*/
/******************************************************************************/
void Wrapper::destroyGeometries()
{
	geoGrid.destroyGeometry();
	geoCube.destroyGeometry();
}

/******************************************************************************/
/*!
createTiles:Create and initialize game objects for Tiles
\return
void
*/
/******************************************************************************/
void Wrapper::createAndInitObjects()
{
	goGrid.setGeometryAndPhysicalType(&geoGrid,square);
	goGrid.translate.upload(0.0f,0.0f,0.0f);
	goGrid.geoType->local.add(&goGrid.translate);
	goGrid.p.x = 0.0f;
	goGrid.p.y = 0.0f;
	goGrid.p.z = 0.0f;
	goGrid.setTexture("Code/Files/TGA/Misc1.tga");

	goCube.setGeometryAndPhysicalType(&geoCube,box);
	goCube.translate.upload(0.0f,0.0f,0.0f);
	goCube.geoType->local.add(&goCube.translate);
	goCube.p.x = 0.0f;
	goCube.p.y = 0.0f;
	goCube.p.z = 0.0f;
	goCube.setTexture("Code/Files/TGA/Misc1.tga");

}

