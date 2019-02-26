#include "game.h";
#include "ResourceManager.h";
#include "sprite_renderer.h";
#include <iostream>

Game::Game(GLuint width, GLuint height) 
	:State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

SpriteRenderer *Renderer;

Game::~Game(){
	delete Renderer;
}

void Game::Init() {

	std::cout << "Init Game" << std::endl;
	ResourceManager::LoadShader("Shader/sprite.vs", "Shader/sprite.fs", nullptr, "sprite");

	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection); 

	Shader myShader;
	myShader = ResourceManager::GetShader("sprite");
	Renderer = new SpriteRenderer(myShader);

	ResourceManager::LoadTexture("Texture/container.jpg", GL_TRUE, "face");

	
}

void Game::Update(GLfloat dt) {

}

void Game::ProcessInput(GLfloat dt) {

}

void Game::Render()
{
	//std::cout << "Renderer" << std::endl;
	Texture2D myTexture;
	myTexture = ResourceManager::GetTexture("face");
	Renderer->DrawSprite(myTexture, glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}