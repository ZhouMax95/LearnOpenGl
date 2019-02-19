#include "Shader_2DGame.h"
#include <iostream>

Shader &Shader::Use() {
	glUseProgram(this->ID);
	return *this;
}

void Shader::Compile(const GLchar *vertexSource, const GLchar *frameSource, const GLchar *geometrySource) {
	GLuint sVertex, sFrament, gShader;
	sVertex = glCreateShader(GL_VERTEX_SHADER);

}

void Shader::checkCompileErrors(GLuint object, std::string type) {
	GLint success;
	GLchar infoLog[1024];
	if (type!="PROGRAM")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(object,1024,NULL,infoLog);
			std::cout << "|ERROR::SHADER:Compile-time error:Type:" << type << "\n" << infoLog <<
				"\n -- --------------------------------------- --" << std::endl;
		}
	}
	else
	{
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!&success)
		{
			glGetProgramInfoLog(object, 1024, NULL,infoLog);
			std::cout << "|ERROR::Shader:Link-time error:Type:" << type << "\n" << infoLog << "\n -- ----------------------------------- --"
				<< std::endl;
		}

	}
}