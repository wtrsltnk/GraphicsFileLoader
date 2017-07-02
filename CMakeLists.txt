cmake_minimum_required(VERSION 3.1)

project(GraphicsFileLoader)

find_package(OpenGL REQUIRED)

add_executable(GraphicsFileLoader
    DummyModifier.cpp
    DummyModifier.h
    DummySceneLoader.cpp
    DummySceneLoader.h
    GraphicsFileLoader.dsp
    GraphicsFileLoader.dsw
    HoofdScherm.cpp
    HoofdScherm.h
    Scherm.cpp
    Scherm.h
    SelectionGroups.cpp
    SelectionGroups.h
    Selector.cpp
    Selector.h
    TextureManager.cpp
    TextureManager.h
    Control/ControlCameraTool.cpp
    Control/ControlCameraTool.h
    Control/ControlSelectionTool.cpp
    Control/ControlSelectionTool.h
    Control/ControlToolArguments.cpp
    Control/ControlToolArguments.h
    Graphics/GraphicsCamera.cpp
    Graphics/GraphicsCamera.h
    Graphics/GraphicsCube.cpp
    Graphics/GraphicsCube.h
    Graphics/GraphicsEngine.cpp
    Graphics/GraphicsEngine.h
    Graphics/GraphicsObjects.cpp
    Graphics/GraphicsObjects.h
    Graphics/GraphicsRectangle.cpp
    Graphics/GraphicsRectangle.h
    Graphics/GraphicsView.cpp
    Graphics/GraphicsView.h
    Interface/flag.h
    Interface/ICamera.h
    Interface/IGroup.h
    Interface/IMaterial.h
    Interface/IModifier.h
    Interface/IPoint.h
    Interface/IScene.h
    Interface/ISceneLoader.h
    Interface/ISelection.h
    Interface/ITexCoord.h
    Interface/ITool.h
    Interface/IToolArguments.h
    Interface/ITriangle.h
    Interface/IVertex.h
    structure/StructureGroup.cpp
    structure/StructureGroup.h
    structure/StructureMaterial.cpp
    structure/StructureMaterial.h
    structure/StructureScene.cpp
    structure/StructureScene.h
    structure/StructureSceneManager.cpp
    structure/StructureSceneManager.h
    structure/StructureTexCoord.cpp
    structure/StructureTexCoord.h
    structure/StructureTriangle.cpp
    structure/StructureTriangle.h
    structure/StructureVertex.cpp
    structure/StructureVertex.h
    )

target_include_directories(GraphicsFileLoader
    PRIVATE Interface
    PRIVATE Control
    PRIVATE Graphics
    )

target_link_libraries(GraphicsFileLoader
    ${OPENGL_LIBRARIES}
    comctl32
    winmm
    )

target_compile_features(GraphicsFileLoader
	PRIVATE cxx_auto_type
	PRIVATE cxx_nullptr
	PRIVATE cxx_range_for
	)
