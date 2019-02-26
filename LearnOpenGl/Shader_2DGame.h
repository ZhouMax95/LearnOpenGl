#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader {
public:
		GLuint ID;
		Shader(){}
		Shader &Use();

		void Compile(const GLchar *vertexSource, const GLchar *frametSource, const GLchar *geometrySource = nullptr);

		void SetFloat(const GLchar *name, GLfloat value, GLboolean useShader = false);
		void SetInteger(const GLchar *name, GLint value, GLboolean useShader = false);
		void SetVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader = false);
		void SetVector2f(const GLchar *name, const glm::vec2 &value, GLboolean useShader = false);
		void SetVector3f(const GLchar *name, const GLfloat x, GLfloat y, GLfloat z, GLboolean useShader = false);
		void SetVector3f(const GLchar *name, const glm::vec3 &value, GLboolean useShader = false);
		void SetVector4f(const GLchar *name, const GLfloat x, const GLfloat y, const GLfloat z, const GLfloat w, GLboolean = false);
		void SetVector4f(const GLchar *name, const glm::vec4 &value, GLboolean useShader = false);
        void SetMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader = false);

private:
	void checkCompileErrors(GLuint object,std::string type);
};

#endif