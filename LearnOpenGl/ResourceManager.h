#pragma once
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>

#include <glad/glad.h>
#include "texture.h"
#include "Shader_2DGame.h"

class ResourceManager {
public:
	static std::map<std::string, Shader> Shaders;
	static std::map<std::string, Texture2D> Textures;
	static Shader LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShader, std::string name);
	static Shader GetShader(std::string name);
	static Texture2D LoadTexture(const GLchar *file, GLboolean alpha, std::string name);
	static Texture2D GetTexture(std::string name);
	static void Clear();

private:
	ResourceManager() {}
	static Shader loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *loadShaderFromFile = nullptr);
	static Texture2D loadTextureFromFile(const GLchar *file, GLboolean alpha);
};

#endif 
