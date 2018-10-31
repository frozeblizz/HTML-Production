#include "pch.h"
#include "Choices.h"
#include "Game.h"
#include "SquareMeshVbo.h"
#include "TextMeshVbo.h"
#include "DiaTextMeshVbo.h"


Choices::Choices()
{
	
}


Choices::~Choices()
{
}

void Choices::render(glm::mat4 globalModelTransform)
{
	GLuint modelMatixId = Game::getInstance()->getRenderer()->getModelMatrixAttrId();
	GLuint modeId = Game::getInstance()->getRenderer()->getModeUniformId();

	

	if (modelMatixId == -1) {
		cout << "Error: Can't perform transformation " << endl;
		return;
	}

	glm::mat4 currentMatrix = this->getTransform();

	SquareMeshVbo *squareMesh = dynamic_cast<SquareMeshVbo *> (Game::getInstance()->getRenderer()->getMesh(SquareMeshVbo::MESH_NAME));
	if (squareMesh != nullptr) {

		currentMatrix = globalModelTransform * currentMatrix;
		//currentMatrix = glm::scale(currentMatrix, glm::vec3(0.25f, 0.3f, 1.0f));
		glUniformMatrix4fv(modelMatixId, 1, GL_FALSE, glm::value_ptr(currentMatrix));

		glBindTexture(GL_TEXTURE_2D, BGtexture);
		glUniform1i(modeId, 1);
		squareMesh->render();

		/*currentMatrix = glm::translate(currentMatrix, glm::vec3(1.0f,0.0f,0.0f));
		glUniformMatrix4fv(modelMatixId, 1, GL_FALSE, glm::value_ptr(currentMatrix));
		glUniform3f(colorId, color.x-0.5f, color.y-0.5f, color.z-0.5f);
		starMesh->render();*/

	}

	
	
	TextMeshVbo *textMesh = dynamic_cast<TextMeshVbo *> (Game::getInstance()->getRenderer()->getMesh(TextMeshVbo::MESH_NAME));
	if (textMesh != nullptr) {

		currentMatrix = globalModelTransform * currentMatrix;
		glUniformMatrix4fv(modelMatixId, 1, GL_FALSE, glm::value_ptr(currentMatrix));
		glUniform1i(modeId, 1);
		glBindTexture(GL_TEXTURE_2D, texture);
		textMesh->render();
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	
}

void Choices::loadTexture(string fileName)
{
	glActiveTexture(GL_TEXTURE0);
	SDL_Surface *image = IMG_Load(fileName.c_str());
	if (image == NULL)
	{
		cerr << "IMG_Load: " << SDL_GetError() << endl;
		return;
	}
	glGenTextures(1, &BGtexture);
	glBindTexture(GL_TEXTURE_2D, BGtexture);

	int Mode = GL_RGB;
	if (image->format->BytesPerPixel == 4)
	{
		Mode = GL_RGBA;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, Mode, image->w, image->h, 0, Mode, GL_UNSIGNED_BYTE, image->pixels);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	SDL_FreeSurface(image);


}

void Choices::update(float deltaTime)
{

}

int Choices::GetID()
{
	return choiceID;
}

void Choices::SetID(int id)
{
	choiceID = id;
}
