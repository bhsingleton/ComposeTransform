cmake_minimum_required(VERSION 3.21)
project(ComposeTransform)
include($ENV{DEVKIT_LOCATION}/cmake/pluginEntry.cmake)

set(
	SOURCE_FILES
	"pluginMain.cpp"
	"ComposeTransformNode.h"
	"ComposeTransformNode.cpp"
)

set(
	LIBRARIES
	OpenMaya
	Foundation
)

build_plugin()