//
// File: ComposeTransformNode.cpp
//
// Dependency Graph Node: composeTransform
//
// Author: Jisoo Kim
//

#include "ComposeTransformNode.h"

MObject		ComposeTransform::inputTranslate;
MObject		ComposeTransform::inputTranslateX;
MObject		ComposeTransform::inputTranslateY;
MObject		ComposeTransform::inputTranslateZ;
MObject		ComposeTransform::inputRotateOrder;
MObject		ComposeTransform::inputRotate;
MObject		ComposeTransform::inputRotateX;
MObject		ComposeTransform::inputRotateY;
MObject		ComposeTransform::inputRotateZ;
MObject		ComposeTransform::inputRotateAxis;
MObject		ComposeTransform::inputRotateAxisX;
MObject		ComposeTransform::inputRotateAxisY;
MObject		ComposeTransform::inputRotateAxisZ;
MObject		ComposeTransform::inputRotatePivot;
MObject		ComposeTransform::inputRotatePivotX;
MObject		ComposeTransform::inputRotatePivotY;
MObject		ComposeTransform::inputRotatePivotZ;
MObject		ComposeTransform::inputRotatePivotTranslate;
MObject		ComposeTransform::inputRotatePivotTranslateX;
MObject		ComposeTransform::inputRotatePivotTranslateY;
MObject		ComposeTransform::inputRotatePivotTranslateZ;
MObject		ComposeTransform::inputScale;
MObject		ComposeTransform::inputScaleX;
MObject		ComposeTransform::inputScaleY;
MObject		ComposeTransform::inputScaleZ;
MObject		ComposeTransform::inputScalePivot;
MObject		ComposeTransform::inputScalePivotX;
MObject		ComposeTransform::inputScalePivotY;
MObject		ComposeTransform::inputScalePivotZ;
MObject		ComposeTransform::inputScalePivotTranslate;
MObject		ComposeTransform::inputScalePivotTranslateX;
MObject		ComposeTransform::inputScalePivotTranslateY;
MObject		ComposeTransform::inputScalePivotTranslateZ;
MObject     ComposeTransform::inputShear;
MObject		ComposeTransform::inputShearXY;
MObject		ComposeTransform::inputShearXZ;
MObject		ComposeTransform::inputShearYZ;
MObject		ComposeTransform::inputOffsetParentMatrix;

MObject		ComposeTransform::outputMatrix;

MString		ComposeTransform::inputCategory("Input");
MString		ComposeTransform::outputCategory("Output");
MString		ComposeTransform::classification("animation");

MTypeId		ComposeTransform::id(0x0013b1ea);


ComposeTransform::ComposeTransform() {}
ComposeTransform::~ComposeTransform() {}


MStatus ComposeTransform::compute(const MPlug& plug, MDataBlock& data)
/**
This method should be overridden in user defined nodes.
Recompute the given output based on the nodes inputs.
The plug represents the data value that needs to be recomputed, and the data block holds the storage for all of the node's attributes.
The MDataBlock will provide smart handles for reading and writing this node's attribute values.
Only these values should be used when performing computations!

@param plug: Plug representing the attribute that needs to be recomputed.
@param data: Data block containing storage for the node's attributes.
@return: Return status.
*/
{

	MStatus status;

	// Check requested attribute
	//
	MObject attribute = plug.attribute(&status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MFnAttribute fnAttribute(attribute, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	bool isOutput = fnAttribute.hasCategory(ComposeTransform::outputCategory);

	if (isOutput)
	{

		// Get input data handles
		//
		MDataHandle inputTranslateHandle = data.inputValue(ComposeTransform::inputTranslate, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		MDataHandle inputTranslateXHandle = inputTranslateHandle.child(ComposeTransform::inputTranslateX);
		MDataHandle inputTranslateYHandle = inputTranslateHandle.child(ComposeTransform::inputTranslateY);
		MDataHandle inputTranslateZHandle = inputTranslateHandle.child(ComposeTransform::inputTranslateZ);

		MDataHandle inputRotateOrderHandle = data.inputValue(ComposeTransform::inputRotateOrder, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		MDataHandle inputRotateHandle = data.inputValue(ComposeTransform::inputRotate, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		MDataHandle inputRotateXHandle = inputRotateHandle.child(ComposeTransform::inputRotateX);
		MDataHandle inputRotateYHandle = inputRotateHandle.child(ComposeTransform::inputRotateY);
		MDataHandle inputRotateZHandle = inputRotateHandle.child(ComposeTransform::inputRotateZ);

		MDataHandle inputRotatePivotHandle = data.inputValue(ComposeTransform::inputRotatePivot, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		MDataHandle inputRotatePivotXHandle = inputRotatePivotHandle.child(ComposeTransform::inputRotatePivotX);
		MDataHandle inputRotatePivotYHandle = inputRotatePivotHandle.child(ComposeTransform::inputRotatePivotY);
		MDataHandle inputRotatePivotZHandle = inputRotatePivotHandle.child(ComposeTransform::inputRotatePivotZ);

		MDataHandle inputRotatePivotTranslateHandle = data.inputValue(ComposeTransform::inputRotatePivotTranslate, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		MDataHandle inputRotatePivotTranslateXHandle = inputRotatePivotTranslateHandle.child(ComposeTransform::inputRotatePivotTranslateX);
		MDataHandle inputRotatePivotTranslateYHandle = inputRotatePivotTranslateHandle.child(ComposeTransform::inputRotatePivotTranslateY);
		MDataHandle inputRotatePivotTranslateZHandle = inputRotatePivotTranslateHandle.child(ComposeTransform::inputRotatePivotTranslateZ);

		MDataHandle inputRotateAxisHandle = data.inputValue(ComposeTransform::inputRotateAxis, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		MDataHandle inputRotateAxisXHandle = inputRotateAxisHandle.child(ComposeTransform::inputRotateAxisX);
		MDataHandle inputRotateAxisYHandle = inputRotateAxisHandle.child(ComposeTransform::inputRotateAxisY);
		MDataHandle inputRotateAxisZHandle = inputRotateAxisHandle.child(ComposeTransform::inputRotateAxisZ);

		MDataHandle inputScaleHandle = data.inputValue(ComposeTransform::inputScale, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		MDataHandle inputScaleXHandle = inputScaleHandle.child(ComposeTransform::inputScaleX);
		MDataHandle inputScaleYHandle = inputScaleHandle.child(ComposeTransform::inputScaleY);
		MDataHandle inputScaleZHandle = inputScaleHandle.child(ComposeTransform::inputScaleZ);

		MDataHandle inputScalePivotHandle = data.inputValue(ComposeTransform::inputScalePivot, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		MDataHandle inputScalePivotXHandle = inputScalePivotHandle.child(ComposeTransform::inputScalePivotX);
		MDataHandle inputScalePivotYHandle = inputScalePivotHandle.child(ComposeTransform::inputScalePivotY);
		MDataHandle inputScalePivotZHandle = inputScalePivotHandle.child(ComposeTransform::inputScalePivotZ);

		MDataHandle inputScalePivotTranslateHandle = data.inputValue(ComposeTransform::inputScalePivotTranslate, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		MDataHandle inputScalePivotTranslateXHandle = inputScalePivotTranslateHandle.child(ComposeTransform::inputScalePivotTranslateX);
		MDataHandle inputScalePivotTranslateYHandle = inputScalePivotTranslateHandle.child(ComposeTransform::inputScalePivotTranslateY);
		MDataHandle inputScalePivotTranslateZHandle = inputScalePivotTranslateHandle.child(ComposeTransform::inputScalePivotTranslateZ);

		MDataHandle inputShearHandle = data.inputValue(ComposeTransform::inputShear, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		MDataHandle inputShearXYHandle = inputShearHandle.child(ComposeTransform::inputShearXY);
		MDataHandle inputShearXZHandle = inputShearHandle.child(ComposeTransform::inputShearXZ);
		MDataHandle inputShearYZHandle = inputShearHandle.child(ComposeTransform::inputShearYZ);

		MDataHandle inputOffsetParentMatrixHandle = data.inputValue(ComposeTransform::inputOffsetParentMatrix);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		// Get values from handles
		//
		double inputTranslateX = inputTranslateXHandle.asDistance().asCentimeters();
		double inputTranslateY = inputTranslateYHandle.asDistance().asCentimeters();
		double inputTranslateZ = inputTranslateZHandle.asDistance().asCentimeters();
		MVector inputTranslation = MVector(inputTranslateX, inputTranslateY, inputTranslateZ);

		MEulerRotation::RotationOrder inputRotateOrder = MEulerRotation::RotationOrder(inputRotateOrderHandle.asShort());
		MTransformationMatrix::RotationOrder inputTransformOrder = MTransformationMatrix::RotationOrder(inputRotateOrder + 1);

		double inputRotateX = inputRotateXHandle.asAngle().asRadians();
		double inputRotateY = inputRotateYHandle.asAngle().asRadians();
		double inputRotateZ = inputRotateZHandle.asAngle().asRadians();
		double3 inputRotate = { inputRotateX, inputRotateY, inputRotateZ };

		double inputRotateAxisX = inputRotateAxisXHandle.asAngle().asRadians();
		double inputRotateAxisY = inputRotateAxisYHandle.asAngle().asRadians();
		double inputRotateAxisZ = inputRotateAxisZHandle.asAngle().asRadians();
		MQuaternion inputOrientation = MEulerRotation(inputRotateAxisX, inputRotateAxisY, inputRotateAxisZ, inputRotateOrder).asQuaternion();

		double inputRotatePivotX = inputRotatePivotXHandle.asDistance().asCentimeters();
		double inputRotatePivotY = inputRotatePivotYHandle.asDistance().asCentimeters();
		double inputRotatePivotZ = inputRotatePivotZHandle.asDistance().asCentimeters();
		MPoint inputRotatePivot = MPoint(inputRotatePivotX, inputRotatePivotY, inputRotatePivotZ);

		double inputRotatePivotTranslateX = inputRotatePivotTranslateXHandle.asDistance().asCentimeters();
		double inputRotatePivotTranslateY = inputRotatePivotTranslateYHandle.asDistance().asCentimeters();
		double inputRotatePivotTranslateZ = inputRotatePivotTranslateZHandle.asDistance().asCentimeters();
		MVector inputRotatePivotTranslation = MVector(inputRotatePivotTranslateX, inputRotatePivotTranslateY, inputRotatePivotTranslateZ);

		double inputScaleX = inputScaleXHandle.asDouble();
		double inputScaleY = inputScaleYHandle.asDouble();
		double inputScaleZ = inputScaleZHandle.asDouble();
		double3 inputScale = { inputScaleX, inputScaleY, inputScaleZ };

		double inputScalePivotX = inputScalePivotXHandle.asDistance().asCentimeters();
		double inputScalePivotY = inputScalePivotYHandle.asDistance().asCentimeters();
		double inputScalePivotZ = inputScalePivotZHandle.asDistance().asCentimeters();
		MPoint inputScalePivot = MPoint(inputScalePivotX, inputScalePivotY, inputScalePivotZ);

		double inputScalePivotTranslateX = inputScalePivotTranslateXHandle.asDistance().asCentimeters();
		double inputScalePivotTranslateY = inputScalePivotTranslateYHandle.asDistance().asCentimeters();
		double inputScalePivotTranslateZ = inputScalePivotTranslateZHandle.asDistance().asCentimeters();
		MVector inputScalePivotTranslation = MVector(inputScalePivotTranslateX, inputScalePivotTranslateY, inputScalePivotTranslateZ);

		double inputShearXY = inputShearXYHandle.asDouble();
		double inputShearXZ = inputShearXZHandle.asDouble();
		double inputShearYZ = inputShearYZHandle.asDouble();
		double3 inputShear = { inputShearXY, inputShearXZ, inputShearYZ };

		MObject inputOffsetParentMatrixData = inputOffsetParentMatrixHandle.data();
		MMatrix inputOffsetParentMatrix = MMatrix::identity;

		bool hasOffsetParentMatrixData = !inputOffsetParentMatrixData.isNull();

		if (hasOffsetParentMatrixData)
		{

			MFnMatrixData fnInputOffsetParentMatrixData(inputOffsetParentMatrixData, &status);
			CHECK_MSTATUS_AND_RETURN_IT(status);

			if (fnInputOffsetParentMatrixData.isTransformation())
			{

				inputOffsetParentMatrix = fnInputOffsetParentMatrixData.transformation(&status).asMatrix();
				CHECK_MSTATUS_AND_RETURN_IT(status);

			}
			else
			{

				inputOffsetParentMatrix = fnInputOffsetParentMatrixData.matrix(&status);
				CHECK_MSTATUS_AND_RETURN_IT(status);

			}

		}

		// Compose transformation matrix
		//
		MTransformationMatrix outputMatrix = MTransformationMatrix::identity;

		status = outputMatrix.setScalePivot(inputScalePivot, MSpace::kTransform, false);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		status = outputMatrix.setScale(inputScale, MSpace::kTransform);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		status = outputMatrix.setShear(inputShear, MSpace::kTransform);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		status = outputMatrix.setScalePivotTranslation(inputScalePivotTranslation, MSpace::kTransform);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		status = outputMatrix.setRotatePivot(inputRotatePivot, MSpace::kTransform, false);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		outputMatrix.setRotationOrientation(inputOrientation);

		status = outputMatrix.setRotation(inputRotate, inputTransformOrder, MSpace::kTransform);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		status = outputMatrix.setRotatePivotTranslation(inputRotatePivotTranslation, MSpace::kTransform);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		status = outputMatrix.setTranslation(inputTranslation, MSpace::kTransform);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		// Get output data handle
		//
		MDataHandle outputMatrixHandle = data.outputValue(ComposeTransform::outputMatrix, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		// Set output handle value
		//
		MFnMatrixData fnMatrixData;

		MObject matrixData = fnMatrixData.create(&status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		bool requiresOffsetParentMatrix = !inputOffsetParentMatrix.isEquivalent(MMatrix::identity);

		if (requiresOffsetParentMatrix)
		{

			MMatrix offsetOutputMatrix = outputMatrix.asMatrix() * inputOffsetParentMatrix;

			status = fnMatrixData.set(offsetOutputMatrix);
			CHECK_MSTATUS_AND_RETURN_IT(status);

		}
		else
		{

			status = fnMatrixData.set(outputMatrix);
			CHECK_MSTATUS_AND_RETURN_IT(status);

		}

		outputMatrixHandle.setMObject(matrixData);
		outputMatrixHandle.setClean();

		// Mark plug as clean
		//
		status = data.setClean(plug);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		return MS::kSuccess;

	}
	else
	{

		return MS::kUnknownParameter;

	}

};


void* ComposeTransform::creator()
/**
This function is called by Maya when a new instance is requested.
See pluginMain.cpp for details.

@return: SoftIK
*/
{

	return new ComposeTransform();

};


MStatus ComposeTransform::initialize()
/**
This function is called by Maya after a plugin has been loaded.
Use this function to define any static attributes.

@return: MStatus
*/
{

	MStatus status;

	// Initialize function sets
	//
	MFnNumericAttribute fnNumericAttr;
	MFnUnitAttribute fnUnitAttr;
	MFnTypedAttribute fnTypedAttr;
	MFnEnumAttribute fnEnumAttr;

	// Input attributes:
	// Initialize `inputTranslateX` attribute
	//
	ComposeTransform::inputTranslateX = fnUnitAttr.create("inputTranslateX", "itx", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputTranslateY` attribute
	//
	ComposeTransform::inputTranslateY = fnUnitAttr.create("inputTranslateY", "ity", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputTranslateZ` attribute
	//
	ComposeTransform::inputTranslateZ = fnUnitAttr.create("inputTranslateZ", "itz", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputTranslate` attribute
	//
	ComposeTransform::inputTranslate = fnNumericAttr.create("inputTranslate", "it", ComposeTransform::inputTranslateX, ComposeTransform::inputTranslateY, ComposeTransform::inputTranslateZ, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `constraintRotateOrder` attribute
	//
	ComposeTransform::inputRotateOrder = fnEnumAttr.create("inputRotateOrder", "iro", short(0), &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnEnumAttr.addField("xyz", 0));
	CHECK_MSTATUS(fnEnumAttr.addField("yzx", 1));
	CHECK_MSTATUS(fnEnumAttr.addField("zxy", 2));
	CHECK_MSTATUS(fnEnumAttr.addField("xzy", 3));
	CHECK_MSTATUS(fnEnumAttr.addField("yxz", 4));
	CHECK_MSTATUS(fnEnumAttr.addField("zyx", 5));

	// Initialize `inputRotateX` attribute
	//
	ComposeTransform::inputRotateX = fnUnitAttr.create("inputRotateX", "irx", MFnUnitAttribute::kAngle, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotateY` attribute
	//
	ComposeTransform::inputRotateY = fnUnitAttr.create("inputRotateY", "iry", MFnUnitAttribute::kAngle, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotateZ` attribute
	//
	ComposeTransform::inputRotateZ = fnUnitAttr.create("inputRotateZ", "irz", MFnUnitAttribute::kAngle, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotate` attribute
	//
	ComposeTransform::inputRotate = fnNumericAttr.create("inputRotate", "ir", ComposeTransform::inputRotateX, ComposeTransform::inputRotateY, ComposeTransform::inputRotateZ, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotatePivotX` attribute
	//
	ComposeTransform::inputRotatePivotX = fnUnitAttr.create("inputRotatePivotX", "irpx", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotatePivotY` attribute
	//
	ComposeTransform::inputRotatePivotY = fnUnitAttr.create("inputRotatePivotY", "irpy", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotatePivotZ` attribute
	//
	ComposeTransform::inputRotatePivotZ = fnUnitAttr.create("inputRotatePivotZ", "irpz", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotatePivot` attribute
	//
	ComposeTransform::inputRotatePivot = fnNumericAttr.create("inputRotatePivot", "irp", ComposeTransform::inputRotatePivotX, ComposeTransform::inputRotatePivotY, ComposeTransform::inputRotatePivotZ, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotatePivotTranslateX` attribute
	//
	ComposeTransform::inputRotatePivotTranslateX = fnUnitAttr.create("inputRotatePivotTranslateX", "irptx", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotatePivotTranslateY` attribute
	//
	ComposeTransform::inputRotatePivotTranslateY = fnUnitAttr.create("inputRotatePivotTranslateY", "irpty", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotatePivotTranslateZ` attribute
	//
	ComposeTransform::inputRotatePivotTranslateZ = fnUnitAttr.create("inputRotatePivotTranslateZ", "irptz", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotatePivotTranslate` attribute
	//
	ComposeTransform::inputRotatePivotTranslate = fnNumericAttr.create("inputRotatePivotTranslate", "irpt", ComposeTransform::inputRotatePivotTranslateX, ComposeTransform::inputRotatePivotTranslateY, ComposeTransform::inputRotatePivotTranslateZ, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotateAxisX` attribute
	//
	ComposeTransform::inputRotateAxisX = fnUnitAttr.create("inputRotateAxisX", "irax", MFnUnitAttribute::kAngle, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotateAxisY` attribute
	//
	ComposeTransform::inputRotateAxisY = fnUnitAttr.create("inputRotateAxisY", "iray", MFnUnitAttribute::kAngle, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotateAxisZ` attribute
	//
	ComposeTransform::inputRotateAxisZ = fnUnitAttr.create("inputRotateAxisZ", "iraz", MFnUnitAttribute::kAngle, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputRotateAxis` attribute
	//
	ComposeTransform::inputRotateAxis = fnNumericAttr.create("inputRotateAxis", "ira", ComposeTransform::inputRotateAxisX, ComposeTransform::inputRotateAxisY, ComposeTransform::inputRotateAxisZ, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScaleX` attribute
	//
	ComposeTransform::inputScaleX = fnNumericAttr.create("inputScaleX", "isx", MFnNumericData::kDouble, 1.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.setKeyable(true));
	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScaleY` attribute
	//
	ComposeTransform::inputScaleY = fnNumericAttr.create("inputScaleY", "isy", MFnNumericData::kDouble, 1.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.setKeyable(true));
	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScaleZ` attribute
	//
	ComposeTransform::inputScaleZ = fnNumericAttr.create("inputScaleZ", "isz", MFnNumericData::kDouble, 1.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.setKeyable(true));
	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScale` attribute
	//
	ComposeTransform::inputScale = fnNumericAttr.create("inputScale", "is", ComposeTransform::inputScaleX, ComposeTransform::inputScaleY, ComposeTransform::inputScaleZ, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScalePivotX` attribute
	//
	ComposeTransform::inputScalePivotX = fnUnitAttr.create("inputScalePivotX", "ispx", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScalePivotY` attribute
	//
	ComposeTransform::inputScalePivotY = fnUnitAttr.create("inputScalePivotY", "ispy", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScalePivotZ` attribute
	//
	ComposeTransform::inputScalePivotZ = fnUnitAttr.create("inputScalePivotZ", "ispz", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScalePivot` attribute
	//
	ComposeTransform::inputScalePivot = fnNumericAttr.create("inputScalePivot", "isp", ComposeTransform::inputScalePivotX, ComposeTransform::inputScalePivotY, ComposeTransform::inputScalePivotZ, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScalePivotTranslateX` attribute
	//
	ComposeTransform::inputScalePivotTranslateX = fnUnitAttr.create("inputScalePivotTranslateX", "isptx", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScalePivotTranslateY` attribute
	//
	ComposeTransform::inputScalePivotTranslateY = fnUnitAttr.create("inputScalePivotTranslateY", "ispty", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScalePivotTranslateZ` attribute
	//
	ComposeTransform::inputScalePivotTranslateZ = fnUnitAttr.create("inputScalePivotTranslateZ", "isptz", MFnUnitAttribute::kDistance, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnUnitAttr.setKeyable(true));
	CHECK_MSTATUS(fnUnitAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputScalePivotTranslate` attribute
	//
	ComposeTransform::inputScalePivotTranslate = fnNumericAttr.create("inputScalePivotTranslate", "ispt", ComposeTransform::inputScalePivotTranslateX, ComposeTransform::inputScalePivotTranslateY, ComposeTransform::inputScalePivotTranslateZ, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputShearXY` attribute
	//
	ComposeTransform::inputShearXY = fnNumericAttr.create("inputShearXY", "ishxy", MFnNumericData::kDouble, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.setKeyable(true));
	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputShearXZ` attribute
	//
	ComposeTransform::inputShearXZ = fnNumericAttr.create("inputShearXZ", "ishxz", MFnNumericData::kDouble, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.setKeyable(true));
	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputShearYZ` attribute
	//
	ComposeTransform::inputShearYZ = fnNumericAttr.create("inputShearYZ", "ishyz", MFnNumericData::kDouble, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.setKeyable(true));
	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputShear` attribute
	//
	ComposeTransform::inputShear = fnNumericAttr.create("inputShear", "ish", ComposeTransform::inputShearXY, ComposeTransform::inputShearXZ, ComposeTransform::inputShearYZ, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnNumericAttr.addToCategory(ComposeTransform::inputCategory));

	// Initialize `inputOffsetParentMatrix` attribute
	//
	ComposeTransform::inputOffsetParentMatrix = fnTypedAttr.create("inputOffsetParentMatrix", "iopm", MFnData::kMatrix, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnTypedAttr.addToCategory(ComposeTransform::inputCategory));

	// Output attributes:
	// Initialize `outputMatrix` attribute
	//
	ComposeTransform::outputMatrix = fnTypedAttr.create("outputMatrix", "om", MFnData::kMatrix, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	CHECK_MSTATUS(fnTypedAttr.setWritable(false));
	CHECK_MSTATUS(fnTypedAttr.setStorable(false));
	CHECK_MSTATUS(fnTypedAttr.addToCategory(ComposeTransform::outputCategory));

	// Add attributes to node
	//
	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::inputTranslate));
	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::inputRotateOrder));
	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::inputRotate));
	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::inputRotatePivot));
	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::inputRotatePivotTranslate));
	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::inputRotateAxis));
	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::inputScale));
	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::inputScalePivot));
	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::inputScalePivotTranslate));
	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::inputShear));
	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::inputOffsetParentMatrix));

	CHECK_MSTATUS(ComposeTransform::addAttribute(ComposeTransform::outputMatrix));

	// Define attribute relationships
	//
	CHECK_MSTATUS(ComposeTransform::attributeAffects(ComposeTransform::inputTranslate, ComposeTransform::outputMatrix));
	CHECK_MSTATUS(ComposeTransform::attributeAffects(ComposeTransform::inputRotateOrder, ComposeTransform::outputMatrix));
	CHECK_MSTATUS(ComposeTransform::attributeAffects(ComposeTransform::inputRotate, ComposeTransform::outputMatrix));
	CHECK_MSTATUS(ComposeTransform::attributeAffects(ComposeTransform::inputRotatePivot, ComposeTransform::outputMatrix));
	CHECK_MSTATUS(ComposeTransform::attributeAffects(ComposeTransform::inputRotatePivotTranslate, ComposeTransform::outputMatrix));
	CHECK_MSTATUS(ComposeTransform::attributeAffects(ComposeTransform::inputRotateAxis, ComposeTransform::outputMatrix));
	CHECK_MSTATUS(ComposeTransform::attributeAffects(ComposeTransform::inputScale, ComposeTransform::outputMatrix));
	CHECK_MSTATUS(ComposeTransform::attributeAffects(ComposeTransform::inputScalePivot, ComposeTransform::outputMatrix));
	CHECK_MSTATUS(ComposeTransform::attributeAffects(ComposeTransform::inputScalePivotTranslate, ComposeTransform::outputMatrix));
	CHECK_MSTATUS(ComposeTransform::attributeAffects(ComposeTransform::inputShear, ComposeTransform::outputMatrix));
	CHECK_MSTATUS(ComposeTransform::attributeAffects(ComposeTransform::inputOffsetParentMatrix, ComposeTransform::outputMatrix));

	return status;

};