#ifndef _COMPOSE_TRANSFORM_NODE
#define _COMPOSE_TRANSFORM_NODE
//
// File: ComposeTransformNode.h
//
// Dependency Graph Node: composeTransform
//
// Author: Jisoo Kim
//

#include <maya/MPxNode.h>
#include <maya/MObject.h>
#include <maya/MPlug.h>
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MDistance.h>
#include <maya/MVector.h>
#include <maya/MAngle.h>
#include <maya/MEulerRotation.h>
#include <maya/MPoint.h>
#include <maya/MQuaternion.h>
#include <maya/MMatrix.h>
#include <maya/MTransformationMatrix.h>
#include <maya/MFnEnumAttribute.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnNumericData.h>
#include <maya/MFnTypedAttribute.h> 
#include <maya/MFnUnitAttribute.h>
#include <maya/MFnMatrixData.h> 
#include <maya/MFnData.h> 
#include <maya/MTypeId.h>
#include <maya/MGlobal.h>



class ComposeTransform : public MPxNode
{

public:

						ComposeTransform();
	virtual				~ComposeTransform();

	virtual MStatus		compute(const MPlug& plug, MDataBlock& data);

	static  void*		creator();
	static  MStatus		initialize();

public:

	static	MObject		inputTranslate;
	static	MObject		inputTranslateX;
	static	MObject		inputTranslateY;
	static	MObject		inputTranslateZ;
	static	MObject		inputRotateOrder;
	static	MObject		inputRotate;
	static	MObject		inputRotateX;
	static	MObject		inputRotateY;
	static	MObject		inputRotateZ;
	static	MObject		inputRotatePivot;
	static	MObject		inputRotatePivotX;
	static	MObject		inputRotatePivotY;
	static	MObject		inputRotatePivotZ;
	static	MObject		inputRotatePivotTranslate;
	static	MObject		inputRotatePivotTranslateX;
	static	MObject		inputRotatePivotTranslateY;
	static	MObject		inputRotatePivotTranslateZ;
	static	MObject		inputRotateAxis;
	static	MObject		inputRotateAxisX;
	static	MObject		inputRotateAxisY;
	static	MObject		inputRotateAxisZ;
	static	MObject		inputScale;
	static	MObject		inputScaleX;
	static	MObject		inputScaleY;
	static	MObject		inputScaleZ;
	static	MObject		inputScalePivot;
	static	MObject		inputScalePivotX;
	static	MObject		inputScalePivotY;
	static	MObject		inputScalePivotZ;
	static	MObject		inputScalePivotTranslate;
	static	MObject		inputScalePivotTranslateX;
	static	MObject		inputScalePivotTranslateY;
	static	MObject		inputScalePivotTranslateZ;
	static  MObject     inputShear;
	static	MObject		inputShearXY;
	static	MObject		inputShearXZ;
	static	MObject		inputShearYZ;
	static	MObject		inputOffsetParentMatrix;

	static	MObject		outputMatrix;

	static	MString		inputCategory;
	static	MString		outputCategory;
	static	MString		classification;

	static	MTypeId		id;

};

#endif