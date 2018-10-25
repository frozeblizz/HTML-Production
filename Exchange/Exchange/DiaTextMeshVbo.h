#pragma once

#include "MeshVbo.h"

class DiaTextMeshVbo : public MeshVbo {
protected:

public:
	static string const MESH_NAME;
	DiaTextMeshVbo();
	virtual string getMeshName();
	virtual void render();
	virtual void loadData();
};