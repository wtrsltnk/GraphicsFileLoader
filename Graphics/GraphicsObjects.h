// GraphicsObjects.h: interface for the GraphicsObjects class.
//
//////////////////////////////////////////////////////////////////////

#ifndef GRAPHICSOBJECTS_H
#define GRAPHICSOBJECTS_H

class GraphicsObjects  
{
private:
	GraphicsObjects();
	virtual ~GraphicsObjects();

public:
	static void StartRotate(float x, float y, float z);
	static void StartTranslate(float x, float y, float z);
	static void EndRotate();
	static void EndTranslate();

	static void RenderCube(float size);
	static void RenderBox(float sizex, float sizey, float sizez);
	static void RenderCone(float size, float radius);
	static void RenderCylinder(float size, float radius);

};

#endif
