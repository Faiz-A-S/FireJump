#ifndef DEMO_H
#define DEMO_H


#include <SOIL/SOIL.h>

#include <SDL/SDL_mixer.h>
#include <SDL/SDL_thread.h>

#include <ft2build.h>
#include <freetype/freetype.h>
#include <map>

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

#include "Game.h"

#define NUM_FRAMES 8
#define FRAME_DUR 80

using namespace glm;

#define FONTSIZE 40
#define FONTNAME "Noctura Sans.otf"
#define NUM_BUTTON 3

//enum class State { RUNNING, EXIT, MENU };

struct Character {
	GLuint TextureID; // ID handle of the glyph texture
	ivec2 Size; // Size of glyph
	ivec2 Bearing; // Offset from baseline to left/top of glyph
	GLuint Advance; // Offset to advance to next glyph
};

class Demo :
	public Engine::Game
{
public:
	Demo();
	~Demo();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void RenderGame();
	//int intstat = 0;
	void InitAudio();
	float frame_width = 0, frame_height = 0, frame_width2 = 0, frame_height2 = 0, frame_width3 = 0, frame_height3 = 0, frame_width4 = 0, frame_height4 = 0;

private:
	float frame_dur = 0, oldxpos = 0, oldypos = 0, xpos = 0, ypos = 0, xpos2 = 0, ypos2 = 0, xpos3 = 0, ypos3 = 0, xpos4 = 0, ypos4 = 0, xpos5 = 0, ypos5 = 0, xpos6 = 0, ypos6 = 0, gravity = 0, xVelocity = 0, yVelocity = 0, yposGround = 0, oldyposGround = 0;
	GLuint VBO, VAO, EBO, texture, program, VBO2, VAO2, EBO2, texture2, program2, VBO3, VAO3, EBO3, texture3, program3, VBO4, VAO4, EBO4, texture4, program4;
	bool walk_anim = false, onGround = true;
	unsigned int frame_idx = 0, flip = 0, flip2 = 0;
	Mix_Chunk* sound = NULL;
	Mix_Music* music = NULL;
	int sfx_channel = -1;
	//State state;
	void BuildPlayerSprite();
	void BuildCrateSprite();
	void DrawCrateSprite();
	void BuildFireSprite();
	void DrawFireSprite();
	void BuildBackgroundSprite();
	void DrawBackgroundSprite();
	bool IsCollided(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2);
	float RandomNumber();
	void DrawPlayerSprite();
	void UpdatePlayerSpriteAnim(float deltaTime);
	void ControlPlayerSprite(float deltaTime);
	void ControlFireSprite(float deltaTime);
	void FireMoveLeft(float deltaTime);
	void FireMoveRight(float deltaTime);
	void InitText();
	void InitButton();
	void RenderButton();
	void RenderText(string text, GLfloat x, GLfloat y, GLfloat scale, vec3 color);
	map<GLchar, Character> Characters;
	float button_width[NUM_BUTTON], button_height[NUM_BUTTON], hover_button_width[NUM_BUTTON], hover_button_height[NUM_BUTTON];
	int activeButtonIndex = -2;
	GLuint VBO7, VAO7, texture5, program5; 
	GLuint textureb[NUM_BUTTON], hover_texture[NUM_BUTTON], VBO8, VAO8;
};
#endif

