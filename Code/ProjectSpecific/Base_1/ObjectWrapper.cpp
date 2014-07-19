/******************************************************************************/
/*!
\file ObjectWrapper.cpp
\author Anshuman Wadhera
\par email: a.anshumanwadhera\@digipen.edu
\par a.anshumanwadhera 900995
\par Course: CS1050
\par Project #01
\date 21/12/2011
\brief
Implementation of Wrapper of geometric objects for this project
Copyright (C) 2011 DigiPen Institute of Technology Singapore
*/
/******************************************************************************/

#include "ObjectWrapper.h"

///Initialize static instance of Wrapper
Wrapper * Wrapper::s_pInstance = 0;

/******************************************************************************/
/*!
Set the transformation matrices for the composite objects
\return
void
*/
/******************************************************************************/
void Wrapper::setTransforms()
{
	///Transformations for first composite object - Empire star fighter
	s[0].upload(1.0f,0.3f,0.8f);
	s[1].upload(0.3f,1.5f,1.0f);
	s[2].upload(0.3f,3.0f,1.5f);
	s[3].upload(0.07f,0.5f,0.07f);
	s[4].upload(1.2f,1.4f,1.2f);
	s[5].upload(0.5f,0.5f,0.5f);
	t[0].upload(1.0f,0.0f,0.0f);
	t[1].upload(-1.0f,0.0f,0.0f);
	t[2].upload(0.5f,0.0f,0.0f);
	t[3].upload(-0.5f,0.0f,0.0f);
	t[4].upload(0.2f,1.3f,0.0f);
	t[5].upload(0.2f,-1.3f,0.0f);
	t[6].upload(-0.2f,1.3f,0.0f);
	t[7].upload(-0.2f,-1.3f,0.0f);
	t[8].upload(0.0f,0.0f,2.0f);
	t[9].upload(0.0f,1.3f,0.0f);
	t[10].upload(0.0f,0.0f,0.5f);
	r[0].upload(30.0f,0.0f,0.0f,1.0f);
	r[1].upload(30.0f,0.0f,0.0f,-1.0f);
	r[2].upload(90.0f,1.0f,0.0f,0.0f);
	r[3].upload(1.0f,0.0f,0.0f,1.0f);
	r[3].setUpdate(0.1f,-20.0f,20.0f,false);
	r[5].upload(20.0f,0.0f,-1.0f,0.0f);
	r[6].upload(30.0f,1.0f,0.0f,0.0f);

	/// Transformations for second composite object - Rebellion x-wing fighter
	x_s[0].upload(1.1f,1.3f,2.0f);
	x_s[1].upload(1.0f,1.2f,1.0f);
	x_s[2].upload(1.0f,5.0f,0.9f);
	x_s[3].upload(1.0f,1.5f,0.9f);
	x_s[4].upload(0.8f,2.5f,0.8f);
	x_s[5].upload(4.0f,0.25f,1.3f);
	x_s[6].upload(0.4f,1.3f,0.4f);
	x_s[7].upload(0.15f,3.5f,0.15f);
	x_s[8].upload(0.5f,0.5f,0.5f);
	x_t[0].upload(0.0f,0.4f,1.4f);
	x_t[1].upload(0.0f,-0.2f,2.0f);
	x_t[2].upload(0.0f,0.0f,3.2f);
	x_t[3].upload(0.8f,0.8f,-1.0f);
	x_t[4].upload(0.8f,-0.8f,-1.0f);
	x_t[5].upload(-0.8f,0.8f,-1.0f);
	x_t[6].upload(-0.8f,-0.8f,-1.0f);
	x_t[7].upload(2.0f,0.0f,0.0f);
	x_t[8].upload(-2.0f,0.0f,0.0f);
	x_t[9].upload(2.0f,0.3f,0.0f);
	x_t[10].upload(-2.0f,0.3f,0.0f);
	x_t[11].upload(0.0f,0.0f,2.0f);
	x_t[12].upload(0.0f,0.0f,1.0f);
	x_t[13].upload(2.0f,-0.3f,0.0f);
	x_t[14].upload(-2.0f,-0.3f,0.0f);
	x_r[0].upload(65.0f,-1.0f,0.0f,0.0f);
	x_r[1].upload(90.0f,1.0f,0.0f,0.0f);
	x_r[2].upload(90.0f,-1.0f,0.0f,0.0f);
	x_r[3].upload(18.0f,0.0f,0.0f,1.0f); 
	x_r[3].setUpdate(0.05f,10.0f,22.0f,false);
	x_r[4].upload(18.0f,0.0f,0.0f,-1.0f);
	x_r[4].setUpdate(0.05f,10.0f,22.0f,false);
	x_r[5].upload(20.0f,0.0f,-1.0f,0.0f);
	x_r[6].upload(30.0f,1.0f,0.0f,0.0f);
}

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
Destroy the Grid whose specifics are read from file
\return
void
*/
/******************************************************************************/
void Wrapper::destroyGrid()
{
	delete grid;
}

/******************************************************************************/
/*!
Destroy the Cube whose specifics are read from file
\return
void
*/
/******************************************************************************/
void Wrapper::destroyCube()
{
	delete cube;
}

/******************************************************************************/
/*!
Destroy the Cylinder whose specifics are read from file
\return
void
*/
/******************************************************************************/
void Wrapper::destroyCylinder()
{
	delete cylinder;
}

/******************************************************************************/
/*!
Destroy the Cone whose specifics are read from file
\return
void
*/
/******************************************************************************/
void Wrapper::destroyCone()
{
	delete cone;
}

/******************************************************************************/
/*!
Destroy the Sphere whose specifics are read from file
\return
void
*/
/******************************************************************************/
void Wrapper::destroySphere()
{
	delete sphere;
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
Create GRID specific to input read from file
\param x
subdivisions along x
\param y
subdivisions along y
\param c
Instance of Color4 structure specifying color of grid
\return
void
*/
/******************************************************************************/
void Wrapper::createGrid(const unsigned short &x,const unsigned short &y,const Color4 &c)
{
	grid = new Grid(x,y);
	bp[count] = grid;
	bpDraw[0] = grid;
	col[count] = c;
	++count;
}

/******************************************************************************/
/*!
Create CUBE specific to input read from file
\param subd
subdivisions in the cube
\param c
Instance of Color4 structure specifying color of Cube
\return
void
*/
/******************************************************************************/
void Wrapper::createCube(const unsigned short &subd,const Color4 &c)
{
	cube = new Cube(subd);
	bp[count] = cube;
	bpDraw[1] = cube;
	col[count] = c;
	++count;
}

/******************************************************************************/
/*!
Create Cylinder specific to input read from file
\param stacks
Number of stacks 
\param slices
Number of slices
\param c
Instance of Color4 structure specifying color of cylinder
\return
void
*/
/******************************************************************************/
void Wrapper::createCylinder(const unsigned short &stacks,const unsigned short &slices,const Color4 &c)
{
	cylinder = new Cylinder(stacks,slices);
	bp[count] = cylinder;
	bpDraw[2] = cylinder;
	col[count] = c;
	++count;
}

/******************************************************************************/
/*!
Create Cone specific to input read from file
\param stacks
Number of stacks
\param slices
Number of slices
\param c
Instance of Color4 structure specifying color of Cone
\return
void
*/
/******************************************************************************/
void Wrapper::createCone(const unsigned short &stacks,const unsigned short &slices,const Color4 &c)
{
	cone = new Cone(stacks,slices);
	bp[count] = cone;
	bpDraw[3] = cone;
	col[count] = c;
	++count;
}

/******************************************************************************/
/*!
Create Sphere specific to input read from file
\param stacks
Number of stacks
\param slices
Number of slices
\param c
Instance of Color4 structure specifying color of Sphere
\return
void
*/
/******************************************************************************/
void Wrapper::createSphere(const unsigned short &stacks,const unsigned short &slices,const Color4 &c)
{
	sphere = new Sphere(stacks,slices);
	bp[count] = sphere;
	bpDraw[4] = sphere;
	col[count] = c;
	++count;
}

/******************************************************************************/
/*!
Create composite object 1 - Empire star fighter
\return
void
*/
/******************************************************************************/
void Wrapper::createComposite_1()
{	
	/// Set the colors for geometric entities in the composite object	
	Color4 c;
	c.r = 255;c.g = 0;c.b = 0;bp[count] = &comp_sphere[0];col[count] = c;++count;
	c.r = 0;c.g = 0;c.b = 0;bp[count] = &comp_sphere[1];col[count] = c;++count;
	c.r = 160;c.g = 160;c.b = 160;bp[count] = &comp_cube[0];col[count] = c;++count;
	c.r = 160;c.g = 160;c.b = 160;bp[count] = &comp_cube[1];col[count] = c;++count;
	c.r = 160;c.g = 160;c.b = 160;bp[count] = &comp_cube[2];col[count] = c;++count;
	c.r = 160;c.g = 160;c.b = 160;bp[count] = &comp_cube[3];col[count] = c;++count;
	c.r = 160;c.g = 160;c.b = 160;bp[count] = &comp_cube[4];col[count] = c;++count;
	c.r = 160;c.g = 160;c.b = 160;bp[count] = &comp_cube[5];col[count] = c;++count;
	c.r = 160;c.g = 160;c.b = 160;bp[count] = &comp_cube[6];col[count] = c;++count;
	c.r = 160;c.g = 160;c.b = 160;bp[count] = &comp_cube[7];col[count] = c;++count;
	c.r = 255;c.g = 0;c.b = 0;bp[count] = &comp_cone[0];col[count] = c;++count;
	c.r = 255;c.g = 0;c.b = 0;bp[count] = &comp_cone[1];col[count] = c;++count;
	c.r = 255;c.g = 0;c.b = 0;bp[count] = &comp_cone[2];col[count] = c;++count;
	c.r = 255;c.g = 0;c.b = 0;bp[count] = &comp_cone[3];col[count] = c;++count;
	c.r = 255;c.g = 255;c.b = 255;bp[count] = &comp_cylinder[0];col[count] = c;++count;
	c.r = 255;c.g = 255;c.b = 255;bp[count] = &comp_cylinder[1];col[count] = c;++count;
	c.r = 255;c.g = 255;c.b = 255;bp[count] = &comp_cylinder[2];col[count] = c;++count;
	c.r = 255;c.g = 255;c.b = 255;bp[count] = &comp_cylinder[3];col[count] = c;++count;

	/// Add the transforms for entities in the hierarchy
	comp[0].local.add(&r[5]);
	comp[0].local.add(&r[6]);
	comp_sphere[0].local.add(&s[4]);
	comp[1].parentChild.add(&r[3]);
	comp[1].parentChild.add(&t[0]);
	comp_cube[0].local.add(&s[0]);
	comp_cube[1].parentChild.add(&t[2]);
	comp_cube[1].local.add(&s[1]);
	comp[3].parentChild.add(&t[4]);
	comp[3].parentChild.add(&r[0]);
	comp_cube[2].local.add(&s[1]);
	comp[7].parentChild.add(&t[8]);
	comp[7].parentChild.add(&r[2]);
	comp_cone[0].local.add(&s[2]);
	comp_cylinder[0].parentChild.add(&t[9]);
	comp_cylinder[0].local.add(&s[3]);
	comp[4].parentChild.add(&t[5]);
	comp[4].parentChild.add(&r[1]);
	comp_cube[3].local.add(&s[1]);
	comp[8].parentChild.add(&t[8]);
	comp[8].parentChild.add(&r[2]);
	comp_cone[1].local.add(&s[2]);
	comp_cylinder[1].parentChild.add(&t[9]);
	comp_cylinder[1].local.add(&s[3]);
	comp[2].parentChild.add(&r[3]);
	comp[2].parentChild.add(&t[1]);
	comp_cube[4].local.add(&s[0]);
	comp_cube[5].parentChild.add(&t[3]);
	comp_cube[5].local.add(&s[1]);
	comp[5].parentChild.add(&t[6]);
	comp[5].parentChild.add(&r[1]);
	comp_cube[6].local.add(&s[1]);
	comp[9].parentChild.add(&t[8]);
	comp[9].parentChild.add(&r[2]);
	comp_cone[2].local.add(&s[2]);
	comp_cylinder[2].parentChild.add(&t[9]);
	comp_cylinder[2].local.add(&s[3]);
	comp[6].parentChild.add(&t[7]);
	comp[6].parentChild.add(&r[0]);
	comp_cube[7].local.add(&s[1]);
	comp[10].parentChild.add(&t[8]);
	comp[10].parentChild.add(&r[2]);
	comp_cone[3].local.add(&s[2]);
	comp_cylinder[3].parentChild.add(&t[9]);
	comp_cylinder[3].local.add(&s[3]);
	comp_sphere[1].parentChild.add(&t[10]);
	comp_sphere[1].local.add(&s[5]);

	/// Form the hierarchy of entities
	comp[7].add(&comp_cone[0]);
	comp[7].add(&comp_cylinder[0]);
	comp[8].add(&comp_cone[1]);
	comp[8].add(&comp_cylinder[1]);
	comp[9].add(&comp_cone[2]);
	comp[9].add(&comp_cylinder[2]);
	comp[10].add(&comp_cone[3]);
	comp[10].add(&comp_cylinder[3]);
	comp[5].add(&comp_cube[6]);
	comp[5].add(&comp[9]);
	comp[6].add(&comp_cube[7]);
	comp[6].add(&comp[10]);
	comp[3].add(&comp_cube[2]);
	comp[3].add(&comp[7]);
	comp[4].add(&comp_cube[3]);
	comp[4].add(&comp[8]);
	comp[2].add(&comp_cube[4]);
	comp[2].add(&comp_cube[5]);
	comp[2].add(&comp[5]);
	comp[2].add(&comp[6]);
	comp[1].add(&comp_cube[0]);
	comp[1].add(&comp_cube[1]);
	comp[1].add(&comp[3]);
	comp[1].add(&comp[4]);
	comp[0].add(&comp_sphere[0]);
	comp[0].add(&comp[1]);
	comp[0].add(&comp[2]);
	comp[0].add(&comp_sphere[1]);

	/// Base object pointing to this composite object
	bpDraw[5] = &comp[0];
}

/******************************************************************************/
/*!
Create composite object 2 - Rebellion x-wing fighter
\return
void
*/
/******************************************************************************/
void Wrapper::createComposite_2()
{
	/// set the color of entities in the hierarchy
	Color4 c;
	c.r = 170;c.g = 170;c.b = 170;bp[count] = &xwing_cube[0];col[count] = c;++count;
	c.r = 170;c.g = 170;c.b = 170;bp[count] = &xwing_cube[1];col[count] = c;++count;
	c.r = 170;c.g = 170;c.b = 170;bp[count] = &xwing_cube[2];col[count] = c;++count;
	c.r = 170;c.g = 170;c.b = 170;bp[count] = &xwing_cube[3];col[count] = c;++count;
	c.r = 170;c.g = 170;c.b = 170;bp[count] = &xwing_cube[4];col[count] = c;++count;
	c.r = 170;c.g = 170;c.b = 170;bp[count] = &xwing_cube[5];col[count] = c;++count;
	c.r = 128;c.g = 64;c.b = 0;bp[count] = &xwing_cylinder[0];col[count] = c;++count;
	c.r = 128;c.g = 64;c.b = 0;bp[count] = &xwing_cylinder[1];col[count] = c;++count;
	c.r = 128;c.g = 64;c.b = 0;bp[count] = &xwing_cylinder[2];col[count] = c;++count;
	c.r = 128;c.g = 64;c.b = 0;bp[count] = &xwing_cylinder[3];col[count] = c;++count;
	c.r = 0;c.g = 255;c.b = 0;bp[count] = &xwing_cylinder[4];col[count] = c;++count;
	c.r = 0;c.g = 255;c.b = 0;bp[count] = &xwing_cylinder[5];col[count] = c;++count;
	c.r = 0;c.g = 255;c.b = 0;bp[count] = &xwing_cylinder[6];col[count] = c;++count;
	c.r = 0;c.g = 255;c.b = 0;bp[count] = &xwing_cylinder[7];col[count] = c;++count;
	c.r = 170;c.g = 170;c.b = 170;bp[count] = &xwing_cylinder[8];col[count] = c;++count;
	c.r = 170;c.g = 170;c.b = 170;bp[count] = &xwing_cylinder[9];col[count] = c;++count;
	c.r = 170;c.g = 170;c.b = 170;bp[count] = &xwing_cylinder[10];col[count] = c;++count;
	c.r = 170;c.g = 170;c.b = 170;bp[count] = &xwing_cylinder[11];col[count] = c;++count;
	c.r = 170;c.g = 170;c.b = 170;bp[count] = &xwing_cylinder[12];col[count] = c;++count;
	c.r = 0;c.g = 0;c.b = 255;bp[count] = &xwing_sphere[0];col[count] = c;++count;
	c.r = 0;c.g = 0;c.b = 255;bp[count] = &xwing_sphere[1];col[count] = c;++count;
	c.r = 0;c.g = 0;c.b = 255;bp[count] = &xwing_sphere[2];col[count] = c;++count;
	c.r = 0;c.g = 0;c.b = 255;bp[count] = &xwing_sphere[3];col[count] = c;++count;
	c.r = 255;c.g = 0;c.b = 0;bp[count] = &xwing_grid[0];col[count] = c;++count;
	c.r = 255;c.g = 255;c.b = 255;bp[count] = &xwing_cone[0];col[count] = c;++count;

	//	Add the transformations for entities in the hierarchy
	xwing[0].local.add(&x_r[5]);
	xwing[0].local.add(&x_r[6]);
	xwing_cube[0].local.add(&x_s[0]);
	xwing_grid[0].local.add(&x_s[1]);
	xwing_cylinder[12].local.add(&x_r[1]);
	xwing_cylinder[12].local.add(&x_s[2]);
	xwing_cone[0].local.add(&x_r[1]);
	xwing_cone[0].local.add(&x_s[3]);
	xwing_cylinder[0].local.add(&x_r[2]);
	xwing_cylinder[0].local.add(&x_s[4]);
	xwing_cylinder[1].local.add(&x_r[2]);
	xwing_cylinder[1].local.add(&x_s[4]);
	xwing_cylinder[2].local.add(&x_r[2]);
	xwing_cylinder[2].local.add(&x_s[4]);
	xwing_cylinder[3].local.add(&x_r[2]);
	xwing_cylinder[3].local.add(&x_s[4]);
	xwing_cube[2].local.add(&x_s[5]);
	xwing_cube[3].local.add(&x_s[5]);
	xwing_cube[4].local.add(&x_s[5]);
	xwing_cube[5].local.add(&x_s[5]);
	xwing_cylinder[4].local.add(&x_r[2]);
	xwing_cylinder[4].local.add(&x_s[6]);
	xwing_cylinder[5].local.add(&x_r[2]);
	xwing_cylinder[5].local.add(&x_s[6]);
	xwing_cylinder[6].local.add(&x_r[2]);
	xwing_cylinder[6].local.add(&x_s[6]);
	xwing_cylinder[7].local.add(&x_r[2]);
	xwing_cylinder[7].local.add(&x_s[6]);
	xwing_cylinder[8].local.add(&x_r[2]);
	xwing_cylinder[8].local.add(&x_s[7]);
	xwing_cylinder[9].local.add(&x_r[2]);
	xwing_cylinder[9].local.add(&x_s[7]);
	xwing_cylinder[10].local.add(&x_r[2]);
	xwing_cylinder[10].local.add(&x_s[7]);
	xwing_cylinder[11].local.add(&x_r[2]);
	xwing_cylinder[11].local.add(&x_s[7]);
	xwing_sphere[0].local.add(&x_s[8]);
	xwing_sphere[1].local.add(&x_s[8]);
	xwing_sphere[2].local.add(&x_s[8]);
	xwing_sphere[3].local.add(&x_s[8]);
	xwing_grid[0].parentChild.add(&x_t[0]);
	xwing_grid[0].parentChild.add(&x_r[0]);
	xwing[1].parentChild.add(&x_t[1]);
	xwing_cone[0].parentChild.add(&x_t[2]);
	xwing[2].parentChild.add(&x_t[3]);
	xwing[2].parentChild.add(&x_r[3]);
	xwing[3].parentChild.add(&x_t[4]);
	xwing[3].parentChild.add(&x_r[4]);
	xwing[4].parentChild.add(&x_t[5]);
	xwing[4].parentChild.add(&x_r[4]);
	xwing[5].parentChild.add(&x_t[6]);
	xwing[5].parentChild.add(&x_r[3]);
	xwing[6].parentChild.add(&x_t[7]);
	xwing[7].parentChild.add(&x_t[7]);
	xwing[8].parentChild.add(&x_t[8]);
	xwing[9].parentChild.add(&x_t[8]);
	xwing[10].parentChild.add(&x_t[9]);
	xwing[11].parentChild.add(&x_t[13]);
	xwing[12].parentChild.add(&x_t[10]);
	xwing[13].parentChild.add(&x_t[14]);
	xwing[14].parentChild.add(&x_t[11]);
	xwing[15].parentChild.add(&x_t[11]);
	xwing[16].parentChild.add(&x_t[11]);
	xwing[17].parentChild.add(&x_t[11]);
	xwing_sphere[0].parentChild.add(&x_t[12]);
	xwing_sphere[1].parentChild.add(&x_t[12]);
	xwing_sphere[2].parentChild.add(&x_t[12]);
	xwing_sphere[3].parentChild.add(&x_t[12]);

	//	Form the hierarchy of entities in the object
	xwing[17].add(&xwing_sphere[3]);
	xwing[17].add(&xwing_cylinder[11]);
	xwing[16].add(&xwing_sphere[2]);
	xwing[16].add(&xwing_cylinder[10]);
	xwing[15].add(&xwing_sphere[1]);
	xwing[15].add(&xwing_cylinder[9]);
	xwing[14].add(&xwing_sphere[0]);
	xwing[14].add(&xwing_cylinder[8]);
	xwing[13].add(&xwing[17]);
	xwing[13].add(&xwing_cylinder[7]);
	xwing[12].add(&xwing[16]);
	xwing[12].add(&xwing_cylinder[6]);
	xwing[11].add(&xwing[15]);
	xwing[11].add(&xwing_cylinder[5]);
	xwing[10].add(&xwing[14]);
	xwing[10].add(&xwing_cylinder[4]);
	xwing[9].add(&xwing[13]);
	xwing[9].add(&xwing_cube[5]);
	xwing[8].add(&xwing[12]);
	xwing[8].add(&xwing_cube[4]);
	xwing[7].add(&xwing[11]);
	xwing[7].add(&xwing_cube[3]);
	xwing[6].add(&xwing[10]);
	xwing[6].add(&xwing_cube[2]);
	xwing[5].add(&xwing[9]);
	xwing[5].add(&xwing_cylinder[3]);
	xwing[4].add(&xwing[8]);
	xwing[4].add(&xwing_cylinder[2]);
	xwing[3].add(&xwing[7]);
	xwing[3].add(&xwing_cylinder[1]);
	xwing[2].add(&xwing[6]);
	xwing[2].add(&xwing_cylinder[0]);
	xwing[1].add(&xwing_cone[0]);
	xwing[1].add(&xwing_cylinder[12]);
	xwing[0].add(&xwing[5]);
	xwing[0].add(&xwing[4]);
	xwing[0].add(&xwing[3]);
	xwing[0].add(&xwing[2]);
	xwing[0].add(&xwing[1]);
	xwing[0].add(&xwing_grid[0]);
	xwing[0].add(&xwing_cube[0]);

	/// Base geometry pointer pointing to the composite object
	bpDraw[6] = &xwing[0];
}

/******************************************************************************/
/*!
Create the Vertices and Indices for all the geometric objects
\return
void
*/
/******************************************************************************/
void Wrapper::createGeometries()
{
	for(int i = 0;i < count;++i)
		bp[i]->createGeometry(col[i].r,col[i].g,col[i].b);
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
	for(int i = 0;i < count;++i)
		bp[i]->uploadGeometry();
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
	for(int i = 0;i < count;++i)
		bp[i]->destroyGeometry();
}