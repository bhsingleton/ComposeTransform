//
// File: pluginMain.cpp
//
// Author: Jisoo Kim
//

#include "ComposeTransformNode.h"

#include <maya/MFnPlugin.h>


MStatus initializePlugin(MObject obj)
{

	MStatus status;

	MFnPlugin plugin(obj, "Jisoo Kim", "2017", "Any");
	status = plugin.registerNode("composeTransform", ComposeTransform::id, ComposeTransform::creator, ComposeTransform::initialize, MPxNode::kDependNode, &ComposeTransform::classification);

	if (!status)
	{

		status.perror("registerNode");
		return status;

	}

	return status;

}

MStatus uninitializePlugin(MObject obj)
{

	MStatus status;

	MFnPlugin plugin(obj);
	status = plugin.deregisterNode(ComposeTransform::id);

	if (!status)
	{

		status.perror("deregisterNode");
		return status;

	}

	return status;

}
