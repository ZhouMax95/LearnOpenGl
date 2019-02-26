#include "ResourceManager.h"
#include <iostream>
#include <sstream>
#include <fstream>

#include <stb_image.h> 

std::map<std::string, Texture2D> ResourceManager::Textures;
std::map<std::string, Shader> ResourceManager::Shaders;

Shader ResourceManager::LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name) {
	Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
	return Shaders[name];
}

Shader ResourceManager::GetShader(std::string name) {
	return Shaders[name];
}

Texture2D ResourceManager::LoadTexture(const GLchar *file, GLboolean alpha, std::string name) {
	Textures[name] = loadTextureFromFile(file, alpha);
	return Textures[name];
}

Texture2D ResourceManager::GetTexture(std::string name) {
	return Textures[name];
}

void ResourceManager::Clear(){
	for (auto iter : Shaders) {
		glDeleteShader(iter.second.ID);
	}
	for (auto iter : Textures) {
		glDeleteTextures(1,&iter.second.ID);
	}
}

Shader ResourceManager::loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile) {
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	try {
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;
		
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

		if (gShaderFile!=nullptr)
		{
			std::ifstream geometryShaderFile(gShaderFile);
			std::stringstream gShaderStream;
			gShaderStream << geometryShaderFile.rdbuf();
			geometryCode = gShaderStream.str();			
		}
		
	}
	catch(std::exception e)
	{
		std::cout << "ERROR::SHADER:Failed to read shader files" << std::endl;
	}
	const GLchar *vShaderCode = vertexCode.c_str();
	const GLchar *fShaderCode = fragmentCode.c_str();
	const GLchar *gShaderCode = geometryCode.c_str();
	Shader shader;
	shader.Compile(vShaderCode, fShaderCode, gShaderCode != nullptr ? gShaderCode : nullptr);
	return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const GLchar *file, GLboolean alpha) {
	Texture2D texture;
	int width, height, nrComponent;
	unsigned char* image = stbi_load(file, &width, &height, &nrComponent, 0);
	if (nrComponent==3)
	{
		
		texture.internal_Format = GL_RGB;
		texture.Image_Format = GL_RGB;
	}
	else if (nrComponent == 4)
	{		
		texture.internal_Format = GL_RGBA;
		texture.Image_Format = GL_RGBA;
	}
	/*
	if (alpha)
	{
		texture.internal_Format = GL_RGBA;
		texture.Image_Format = GL_RGBA;
	}
	else
	{
		texture.internal_Format = GL_RGB;
		texture.Image_Format = GL_RGB;
	}*/
	texture.Generate(width, height, image);
	stbi_image_free(image);
	return texture;

}
